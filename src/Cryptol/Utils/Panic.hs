-- |
-- Module      :  Cryptol.Utils.Panic
-- Copyright   :  (c) 2013-2016 Galois, Inc.
-- License     :  BSD3
-- Maintainer  :  cryptol@galois.com
-- Stability   :  provisional
-- Portability :  portable

{-# LANGUAGE Safe #-}
{-# LANGUAGE DeriveDataTypeable, RecordWildCards, ImplicitParams #-}
module Cryptol.Utils.Panic (HasCallStack, panic) where

import Cryptol.Version

import Control.Exception as X
import Data.Typeable(Typeable)
import Data.Maybe(fromMaybe,listToMaybe)
import GHC.Stack

panic :: HasCallStack => String -> [String] -> a
panic panicLoc panicMsg =
  throw CryptolPanic { panicStack = freezeCallStack ?callStack, .. }

data CryptolPanic = CryptolPanic { panicLoc :: String
                                 , panicMsg :: [String]
                                 , panicStack :: CallStack
                                 } deriving Typeable

instance Show CryptolPanic where
  show p = unlines $
    [ "You have encountered a bug in Cryptol's implementation."
    , "*** Please create an issue at https://github.com/galoisinc/cryptol/issues"
    , ""
    , "%< --------------------------------------------------- "
    ] ++ rev ++
    [ locLab ++ panicLoc p
    , msgLab ++ fromMaybe "" (listToMaybe msgLines)
    ]
    ++ map (tabs ++) (drop 1 msgLines)
    ++ [ prettyCallStack (panicStack p) ] ++
    [ "%< --------------------------------------------------- "
    ]
    where msgLab    = "  Message:   "
          revLab    = "  Revision:  "
          branchLab = "  Branch:    "
          dirtyLab  = " (non-committed files present during build)"
          locLab    = "  Location:  "
          tabs      = map (const ' ') msgLab

          msgLines  = panicMsg p

          rev | null commitHash = []
              | otherwise   = [ revLab ++ commitHash
                              , branchLab ++ commitBranch ++ dirtyLab ]

instance Exception CryptolPanic


