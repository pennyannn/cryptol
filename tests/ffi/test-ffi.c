#include <assert.h>
#include <math.h>
#include <stdint.h>
#include <stddef.h>

uint8_t add8(uint8_t x, uint8_t y) {
  return x + y;
}

uint16_t sub16(uint16_t x, uint16_t y) {
  return x - y;
}

uint32_t mul32(uint32_t x, uint32_t y) {
  return x * y;
}

uint64_t div64(uint64_t x, uint64_t y) {
  return x / y;
}

uint8_t extendInput(uint8_t x) {
  return x;
}

uint8_t maskOutput(uint8_t x) {
  return x;
}

uint8_t noBits(uint8_t zero) {
  assert(zero == 0);
  return 1;
}

uint8_t not(uint8_t x) {
  return !x;
}

float addFloat32(float x, float y) {
  return x + y;
}

double subFloat64(double x, double y) {
  return x - y;
}

float specialFloats(uint8_t select) {
  switch (select) {
    case 0:
      return INFINITY;
    case 1:
      return -INFINITY;
    case 2:
      return NAN;
    case 3:
      return -0.0f;
  }
  return 0;
}

uint8_t usesTypeSynonym(uint32_t x, float y) {
  return x == y;
}

uint32_t sum10(uint32_t *xs) {
  uint32_t sum = 0;
  for (unsigned i = 0; i < 10; ++i) {
    sum += xs[i];
  }
  return sum;
}

void reverse5(double *in, double *out) {
  for (unsigned i = 0; i < 5; ++i) {
    out[i] = in[4 - i];
  }
}

void compoundTypes(uint32_t n, uint16_t x, uint32_t *y, uint32_t *z,
    uint16_t *a_0, uint16_t *a_1, uint32_t *c, uint8_t *d, uint8_t *e) {
  *a_0 = n >> 16;
  *a_1 = n;
  for (unsigned i = 0; i < 3; ++i) {
    c[i] = y[i];
  }
  for (unsigned i = 0; i < 5; ++i) {
    c[i + 3] = z[i];
  }
  *d = x >> 5;
  *e = x;
}

uint64_t typeToValue(size_t n) {
  return n;
}

uint32_t sumPoly(size_t n, uint32_t *xs) {
  uint32_t sum = 0;
  for (size_t i = 0; i < n; ++i) {
    sum += xs[i];
  }
  return sum;
}

void inits(size_t n, uint8_t *in, uint8_t *out) {
  for (unsigned i = 1; i <= n; ++i) {
    for (unsigned j = 0; j < i; ++j) {
      *out++ = in[j];
    }
  }
}

void zipMul3(size_t n, size_t m, size_t p, float *xs, float *ys, float *zs,
    float *out) {
  for (size_t i = 0; i < n && i < m && i < p; ++i) {
    out[i] = xs[i] * ys[i] * zs[i];
  }
}
