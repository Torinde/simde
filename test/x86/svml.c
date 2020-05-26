/* Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Copyright:
 *   2020      Evan Nemerson <evan@nemerson.com>
 */

#define SIMDE_TESTS_CURRENT_ISAX svml
#include <test/x86/test-avx512.h>
#include <simde/x86/svml.h>

static MunitResult
test_simde_mm_cos_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -186.21), SIMDE_FLOAT32_C(    39.01), SIMDE_FLOAT32_C(  -754.38), SIMDE_FLOAT32_C(   346.63)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    -0.66), SIMDE_FLOAT32_C(     0.26), SIMDE_FLOAT32_C(     0.92), SIMDE_FLOAT32_C(     0.49)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   497.31), SIMDE_FLOAT32_C(   670.24), SIMDE_FLOAT32_C(  -297.45), SIMDE_FLOAT32_C(    34.06)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.59), SIMDE_FLOAT32_C(    -0.47), SIMDE_FLOAT32_C(    -0.54), SIMDE_FLOAT32_C(    -0.88)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   825.53), SIMDE_FLOAT32_C(   422.21), SIMDE_FLOAT32_C(  -269.45), SIMDE_FLOAT32_C(   467.76)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    -0.76), SIMDE_FLOAT32_C(     0.33), SIMDE_FLOAT32_C(     0.75), SIMDE_FLOAT32_C(    -0.94)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -678.17), SIMDE_FLOAT32_C(  -686.13), SIMDE_FLOAT32_C(    84.77), SIMDE_FLOAT32_C(   571.46)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.92), SIMDE_FLOAT32_C(     0.30), SIMDE_FLOAT32_C(    -1.00), SIMDE_FLOAT32_C(     0.95)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -305.07), SIMDE_FLOAT32_C(  -860.95), SIMDE_FLOAT32_C(  -417.54), SIMDE_FLOAT32_C(   696.87)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    -0.94), SIMDE_FLOAT32_C(     0.99), SIMDE_FLOAT32_C(    -0.96), SIMDE_FLOAT32_C(     0.85)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -444.81), SIMDE_FLOAT32_C(    28.47), SIMDE_FLOAT32_C(  -384.03), SIMDE_FLOAT32_C(  -923.64)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.27), SIMDE_FLOAT32_C(    -0.98), SIMDE_FLOAT32_C(     0.73), SIMDE_FLOAT32_C(     1.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   261.31), SIMDE_FLOAT32_C(  -212.54), SIMDE_FLOAT32_C(  -976.55), SIMDE_FLOAT32_C(  -660.80)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    -0.85), SIMDE_FLOAT32_C(     0.46), SIMDE_FLOAT32_C(    -0.88), SIMDE_FLOAT32_C(     0.48)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   178.20), SIMDE_FLOAT32_C(  -450.67), SIMDE_FLOAT32_C(   233.37), SIMDE_FLOAT32_C(   687.09)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    -0.64), SIMDE_FLOAT32_C(    -0.15), SIMDE_FLOAT32_C(     0.63), SIMDE_FLOAT32_C(    -0.61)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_cos_ps(test_vec[i].a);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cos_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -754.38), SIMDE_FLOAT64_C(  346.63)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.92), SIMDE_FLOAT64_C(    0.49)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -186.21), SIMDE_FLOAT64_C(   39.01)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -0.66), SIMDE_FLOAT64_C(    0.26)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -297.45), SIMDE_FLOAT64_C(   34.06)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -0.54), SIMDE_FLOAT64_C(   -0.88)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  497.31), SIMDE_FLOAT64_C(  670.24)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.59), SIMDE_FLOAT64_C(   -0.47)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -269.45), SIMDE_FLOAT64_C(  467.76)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.75), SIMDE_FLOAT64_C(   -0.94)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  825.53), SIMDE_FLOAT64_C(  422.21)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -0.76), SIMDE_FLOAT64_C(    0.33)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   84.77), SIMDE_FLOAT64_C(  571.46)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -1.00), SIMDE_FLOAT64_C(    0.95)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -678.17), SIMDE_FLOAT64_C( -686.13)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.92), SIMDE_FLOAT64_C(    0.30)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cos_pd(test_vec[i].a);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_cos_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   497.31), SIMDE_FLOAT32_C(   670.24),
                         SIMDE_FLOAT32_C(  -297.45), SIMDE_FLOAT32_C(    34.06),
                         SIMDE_FLOAT32_C(  -186.21), SIMDE_FLOAT32_C(    39.01),
                         SIMDE_FLOAT32_C(  -754.38), SIMDE_FLOAT32_C(   346.63)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     0.59), SIMDE_FLOAT32_C(    -0.47),
                         SIMDE_FLOAT32_C(    -0.54), SIMDE_FLOAT32_C(    -0.88),
                         SIMDE_FLOAT32_C(    -0.66), SIMDE_FLOAT32_C(     0.26),
                         SIMDE_FLOAT32_C(     0.92), SIMDE_FLOAT32_C(     0.49)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -678.17), SIMDE_FLOAT32_C(  -686.13),
                         SIMDE_FLOAT32_C(    84.77), SIMDE_FLOAT32_C(   571.46),
                         SIMDE_FLOAT32_C(   825.53), SIMDE_FLOAT32_C(   422.21),
                         SIMDE_FLOAT32_C(  -269.45), SIMDE_FLOAT32_C(   467.76)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     0.92), SIMDE_FLOAT32_C(     0.30),
                         SIMDE_FLOAT32_C(    -1.00), SIMDE_FLOAT32_C(     0.95),
                         SIMDE_FLOAT32_C(    -0.76), SIMDE_FLOAT32_C(     0.33),
                         SIMDE_FLOAT32_C(     0.75), SIMDE_FLOAT32_C(    -0.94)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -444.81), SIMDE_FLOAT32_C(    28.47),
                         SIMDE_FLOAT32_C(  -384.03), SIMDE_FLOAT32_C(  -923.64),
                         SIMDE_FLOAT32_C(  -305.07), SIMDE_FLOAT32_C(  -860.95),
                         SIMDE_FLOAT32_C(  -417.54), SIMDE_FLOAT32_C(   696.87)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     0.27), SIMDE_FLOAT32_C(    -0.98),
                         SIMDE_FLOAT32_C(     0.73), SIMDE_FLOAT32_C(     1.00),
                         SIMDE_FLOAT32_C(    -0.94), SIMDE_FLOAT32_C(     0.99),
                         SIMDE_FLOAT32_C(    -0.96), SIMDE_FLOAT32_C(     0.85)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   178.20), SIMDE_FLOAT32_C(  -450.67),
                         SIMDE_FLOAT32_C(   233.37), SIMDE_FLOAT32_C(   687.09),
                         SIMDE_FLOAT32_C(   261.31), SIMDE_FLOAT32_C(  -212.54),
                         SIMDE_FLOAT32_C(  -976.55), SIMDE_FLOAT32_C(  -660.80)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    -0.64), SIMDE_FLOAT32_C(    -0.15),
                         SIMDE_FLOAT32_C(     0.63), SIMDE_FLOAT32_C(    -0.61),
                         SIMDE_FLOAT32_C(    -0.85), SIMDE_FLOAT32_C(     0.46),
                         SIMDE_FLOAT32_C(    -0.88), SIMDE_FLOAT32_C(     0.48)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -770.35), SIMDE_FLOAT32_C(   443.48),
                         SIMDE_FLOAT32_C(  -583.60), SIMDE_FLOAT32_C(   380.46),
                         SIMDE_FLOAT32_C(  -770.72), SIMDE_FLOAT32_C(   993.90),
                         SIMDE_FLOAT32_C(    28.08), SIMDE_FLOAT32_C(   841.21)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    -0.79), SIMDE_FLOAT32_C(    -0.87),
                         SIMDE_FLOAT32_C(     0.74), SIMDE_FLOAT32_C(    -0.95),
                         SIMDE_FLOAT32_C(    -0.52), SIMDE_FLOAT32_C(     0.40),
                         SIMDE_FLOAT32_C(    -0.98), SIMDE_FLOAT32_C(     0.74)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -387.90), SIMDE_FLOAT32_C(   395.92),
                         SIMDE_FLOAT32_C(   655.87), SIMDE_FLOAT32_C(   339.21),
                         SIMDE_FLOAT32_C(   532.35), SIMDE_FLOAT32_C(  -263.99),
                         SIMDE_FLOAT32_C(   780.64), SIMDE_FLOAT32_C(   -30.79)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    -0.09), SIMDE_FLOAT32_C(     1.00),
                         SIMDE_FLOAT32_C(    -0.75), SIMDE_FLOAT32_C(     1.00),
                         SIMDE_FLOAT32_C(    -0.15), SIMDE_FLOAT32_C(     1.00),
                         SIMDE_FLOAT32_C(     0.05), SIMDE_FLOAT32_C(     0.81)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -203.65), SIMDE_FLOAT32_C(   -80.73),
                         SIMDE_FLOAT32_C(   336.73), SIMDE_FLOAT32_C(  -944.78),
                         SIMDE_FLOAT32_C(  -747.59), SIMDE_FLOAT32_C(  -767.23),
                         SIMDE_FLOAT32_C(  -554.19), SIMDE_FLOAT32_C(   398.82)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    -0.85), SIMDE_FLOAT32_C(     0.58),
                         SIMDE_FLOAT32_C(    -0.84), SIMDE_FLOAT32_C(    -0.67),
                         SIMDE_FLOAT32_C(     0.99), SIMDE_FLOAT32_C(     0.78),
                         SIMDE_FLOAT32_C(     0.30), SIMDE_FLOAT32_C(    -0.99)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   469.66), SIMDE_FLOAT32_C(   680.02),
                         SIMDE_FLOAT32_C(  -148.69), SIMDE_FLOAT32_C(   818.66),
                         SIMDE_FLOAT32_C(   910.03), SIMDE_FLOAT32_C(   600.47),
                         SIMDE_FLOAT32_C(   791.23), SIMDE_FLOAT32_C(   254.31)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    -0.01), SIMDE_FLOAT32_C(     0.13),
                         SIMDE_FLOAT32_C(    -0.51), SIMDE_FLOAT32_C(    -0.27),
                         SIMDE_FLOAT32_C(     0.51), SIMDE_FLOAT32_C(    -0.91),
                         SIMDE_FLOAT32_C(     0.90), SIMDE_FLOAT32_C(    -0.99)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_cos_ps(test_vec[i].a);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_cos_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -186.21), SIMDE_FLOAT64_C(   39.01),
                         SIMDE_FLOAT64_C( -754.38), SIMDE_FLOAT64_C(  346.63)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -0.66), SIMDE_FLOAT64_C(    0.26),
                         SIMDE_FLOAT64_C(    0.92), SIMDE_FLOAT64_C(    0.49)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  497.31), SIMDE_FLOAT64_C(  670.24),
                         SIMDE_FLOAT64_C( -297.45), SIMDE_FLOAT64_C(   34.06)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.59), SIMDE_FLOAT64_C(   -0.47),
                         SIMDE_FLOAT64_C(   -0.54), SIMDE_FLOAT64_C(   -0.88)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  825.53), SIMDE_FLOAT64_C(  422.21),
                         SIMDE_FLOAT64_C( -269.45), SIMDE_FLOAT64_C(  467.76)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -0.76), SIMDE_FLOAT64_C(    0.33),
                         SIMDE_FLOAT64_C(    0.75), SIMDE_FLOAT64_C(   -0.94)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -678.17), SIMDE_FLOAT64_C( -686.13),
                         SIMDE_FLOAT64_C(   84.77), SIMDE_FLOAT64_C(  571.46)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.92), SIMDE_FLOAT64_C(    0.30),
                         SIMDE_FLOAT64_C(   -1.00), SIMDE_FLOAT64_C(    0.95)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -305.07), SIMDE_FLOAT64_C( -860.95),
                         SIMDE_FLOAT64_C( -417.54), SIMDE_FLOAT64_C(  696.87)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -0.94), SIMDE_FLOAT64_C(    0.99),
                         SIMDE_FLOAT64_C(   -0.96), SIMDE_FLOAT64_C(    0.85)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -444.81), SIMDE_FLOAT64_C(   28.47),
                         SIMDE_FLOAT64_C( -384.03), SIMDE_FLOAT64_C( -923.64)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.27), SIMDE_FLOAT64_C(   -0.98),
                         SIMDE_FLOAT64_C(    0.73), SIMDE_FLOAT64_C(    1.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  261.31), SIMDE_FLOAT64_C( -212.54),
                         SIMDE_FLOAT64_C( -976.55), SIMDE_FLOAT64_C( -660.80)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -0.85), SIMDE_FLOAT64_C(    0.46),
                         SIMDE_FLOAT64_C(   -0.88), SIMDE_FLOAT64_C(    0.48)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  178.20), SIMDE_FLOAT64_C( -450.67),
                         SIMDE_FLOAT64_C(  233.37), SIMDE_FLOAT64_C(  687.09)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -0.64), SIMDE_FLOAT64_C(   -0.15),
                         SIMDE_FLOAT64_C(    0.63), SIMDE_FLOAT64_C(   -0.61)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_cos_pd(test_vec[i].a);
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_cos_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512 a;
    simde__m512 r;
  } test_vec[8] = {
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -678.17), SIMDE_FLOAT32_C(  -686.13), SIMDE_FLOAT32_C(    84.77), SIMDE_FLOAT32_C(   571.46),
                         SIMDE_FLOAT32_C(   825.53), SIMDE_FLOAT32_C(   422.21), SIMDE_FLOAT32_C(  -269.45), SIMDE_FLOAT32_C(   467.76),
                         SIMDE_FLOAT32_C(   497.31), SIMDE_FLOAT32_C(   670.24), SIMDE_FLOAT32_C(  -297.45), SIMDE_FLOAT32_C(    34.06),
                         SIMDE_FLOAT32_C(  -186.21), SIMDE_FLOAT32_C(    39.01), SIMDE_FLOAT32_C(  -754.38), SIMDE_FLOAT32_C(   346.63)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.92), SIMDE_FLOAT32_C(     0.30), SIMDE_FLOAT32_C(    -1.00), SIMDE_FLOAT32_C(     0.95),
                         SIMDE_FLOAT32_C(    -0.76), SIMDE_FLOAT32_C(     0.33), SIMDE_FLOAT32_C(     0.75), SIMDE_FLOAT32_C(    -0.94),
                         SIMDE_FLOAT32_C(     0.59), SIMDE_FLOAT32_C(    -0.47), SIMDE_FLOAT32_C(    -0.54), SIMDE_FLOAT32_C(    -0.88),
                         SIMDE_FLOAT32_C(    -0.66), SIMDE_FLOAT32_C(     0.26), SIMDE_FLOAT32_C(     0.92), SIMDE_FLOAT32_C(     0.49)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   178.20), SIMDE_FLOAT32_C(  -450.67), SIMDE_FLOAT32_C(   233.37), SIMDE_FLOAT32_C(   687.09),
                         SIMDE_FLOAT32_C(   261.31), SIMDE_FLOAT32_C(  -212.54), SIMDE_FLOAT32_C(  -976.55), SIMDE_FLOAT32_C(  -660.80),
                         SIMDE_FLOAT32_C(  -444.81), SIMDE_FLOAT32_C(    28.47), SIMDE_FLOAT32_C(  -384.03), SIMDE_FLOAT32_C(  -923.64),
                         SIMDE_FLOAT32_C(  -305.07), SIMDE_FLOAT32_C(  -860.95), SIMDE_FLOAT32_C(  -417.54), SIMDE_FLOAT32_C(   696.87)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    -0.64), SIMDE_FLOAT32_C(    -0.15), SIMDE_FLOAT32_C(     0.63), SIMDE_FLOAT32_C(    -0.61),
                         SIMDE_FLOAT32_C(    -0.85), SIMDE_FLOAT32_C(     0.46), SIMDE_FLOAT32_C(    -0.88), SIMDE_FLOAT32_C(     0.48),
                         SIMDE_FLOAT32_C(     0.27), SIMDE_FLOAT32_C(    -0.98), SIMDE_FLOAT32_C(     0.73), SIMDE_FLOAT32_C(     1.00),
                         SIMDE_FLOAT32_C(    -0.94), SIMDE_FLOAT32_C(     0.99), SIMDE_FLOAT32_C(    -0.96), SIMDE_FLOAT32_C(     0.85)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -387.90), SIMDE_FLOAT32_C(   395.92), SIMDE_FLOAT32_C(   655.87), SIMDE_FLOAT32_C(   339.21),
                         SIMDE_FLOAT32_C(   532.35), SIMDE_FLOAT32_C(  -263.99), SIMDE_FLOAT32_C(   780.64), SIMDE_FLOAT32_C(   -30.79),
                         SIMDE_FLOAT32_C(  -770.35), SIMDE_FLOAT32_C(   443.48), SIMDE_FLOAT32_C(  -583.60), SIMDE_FLOAT32_C(   380.46),
                         SIMDE_FLOAT32_C(  -770.72), SIMDE_FLOAT32_C(   993.90), SIMDE_FLOAT32_C(    28.08), SIMDE_FLOAT32_C(   841.21)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    -0.09), SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(    -0.75), SIMDE_FLOAT32_C(     1.00),
                         SIMDE_FLOAT32_C(    -0.15), SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(     0.05), SIMDE_FLOAT32_C(     0.81),
                         SIMDE_FLOAT32_C(    -0.79), SIMDE_FLOAT32_C(    -0.87), SIMDE_FLOAT32_C(     0.74), SIMDE_FLOAT32_C(    -0.95),
                         SIMDE_FLOAT32_C(    -0.52), SIMDE_FLOAT32_C(     0.40), SIMDE_FLOAT32_C(    -0.98), SIMDE_FLOAT32_C(     0.74)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   469.66), SIMDE_FLOAT32_C(   680.02), SIMDE_FLOAT32_C(  -148.69), SIMDE_FLOAT32_C(   818.66),
                         SIMDE_FLOAT32_C(   910.03), SIMDE_FLOAT32_C(   600.47), SIMDE_FLOAT32_C(   791.23), SIMDE_FLOAT32_C(   254.31),
                         SIMDE_FLOAT32_C(  -203.65), SIMDE_FLOAT32_C(   -80.73), SIMDE_FLOAT32_C(   336.73), SIMDE_FLOAT32_C(  -944.78),
                         SIMDE_FLOAT32_C(  -747.59), SIMDE_FLOAT32_C(  -767.23), SIMDE_FLOAT32_C(  -554.19), SIMDE_FLOAT32_C(   398.82)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    -0.01), SIMDE_FLOAT32_C(     0.13), SIMDE_FLOAT32_C(    -0.51), SIMDE_FLOAT32_C(    -0.27),
                         SIMDE_FLOAT32_C(     0.51), SIMDE_FLOAT32_C(    -0.91), SIMDE_FLOAT32_C(     0.90), SIMDE_FLOAT32_C(    -0.99),
                         SIMDE_FLOAT32_C(    -0.85), SIMDE_FLOAT32_C(     0.58), SIMDE_FLOAT32_C(    -0.84), SIMDE_FLOAT32_C(    -0.67),
                         SIMDE_FLOAT32_C(     0.99), SIMDE_FLOAT32_C(     0.78), SIMDE_FLOAT32_C(     0.30), SIMDE_FLOAT32_C(    -0.99)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -178.99), SIMDE_FLOAT32_C(   758.79), SIMDE_FLOAT32_C(   324.62), SIMDE_FLOAT32_C(   343.48),
                         SIMDE_FLOAT32_C(  -874.31), SIMDE_FLOAT32_C(  -797.92), SIMDE_FLOAT32_C(  -328.54), SIMDE_FLOAT32_C(  -525.83),
                         SIMDE_FLOAT32_C(  -192.31), SIMDE_FLOAT32_C(  -822.65), SIMDE_FLOAT32_C(   561.36), SIMDE_FLOAT32_C(   655.67),
                         SIMDE_FLOAT32_C(   -70.91), SIMDE_FLOAT32_C(   543.35), SIMDE_FLOAT32_C(   120.65), SIMDE_FLOAT32_C(  -171.51)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    -1.00), SIMDE_FLOAT32_C(     0.10), SIMDE_FLOAT32_C(    -0.51), SIMDE_FLOAT32_C(    -0.50),
                         SIMDE_FLOAT32_C(     0.58), SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(    -0.24), SIMDE_FLOAT32_C(    -0.38),
                         SIMDE_FLOAT32_C(    -0.78), SIMDE_FLOAT32_C(     0.90), SIMDE_FLOAT32_C(    -0.55), SIMDE_FLOAT32_C(    -0.60),
                         SIMDE_FLOAT32_C(    -0.22), SIMDE_FLOAT32_C(    -0.99), SIMDE_FLOAT32_C(     0.30), SIMDE_FLOAT32_C(    -0.29)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   690.12), SIMDE_FLOAT32_C(   840.65), SIMDE_FLOAT32_C(   -21.09), SIMDE_FLOAT32_C(  -591.56),
                         SIMDE_FLOAT32_C(  -448.89), SIMDE_FLOAT32_C(   731.49), SIMDE_FLOAT32_C(   505.79), SIMDE_FLOAT32_C(   623.70),
                         SIMDE_FLOAT32_C(   831.02), SIMDE_FLOAT32_C(   140.67), SIMDE_FLOAT32_C(   977.36), SIMDE_FLOAT32_C(  -906.16),
                         SIMDE_FLOAT32_C(   331.34), SIMDE_FLOAT32_C(    99.93), SIMDE_FLOAT32_C(   462.95), SIMDE_FLOAT32_C(  -738.19)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.51), SIMDE_FLOAT32_C(     0.27), SIMDE_FLOAT32_C(    -0.62), SIMDE_FLOAT32_C(     0.59),
                         SIMDE_FLOAT32_C(    -0.94), SIMDE_FLOAT32_C(    -0.88), SIMDE_FLOAT32_C(    -1.00), SIMDE_FLOAT32_C(    -0.09),
                         SIMDE_FLOAT32_C(    -0.07), SIMDE_FLOAT32_C(    -0.76), SIMDE_FLOAT32_C(    -0.95), SIMDE_FLOAT32_C(     0.19),
                         SIMDE_FLOAT32_C(    -0.10), SIMDE_FLOAT32_C(     0.82), SIMDE_FLOAT32_C(    -0.42), SIMDE_FLOAT32_C(    -1.00)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -769.09), SIMDE_FLOAT32_C(   822.06), SIMDE_FLOAT32_C(  -573.81), SIMDE_FLOAT32_C(  -997.63),
                         SIMDE_FLOAT32_C(  -337.60), SIMDE_FLOAT32_C(   923.64), SIMDE_FLOAT32_C(   293.64), SIMDE_FLOAT32_C(  -768.12),
                         SIMDE_FLOAT32_C(  -576.22), SIMDE_FLOAT32_C(   -67.64), SIMDE_FLOAT32_C(   710.38), SIMDE_FLOAT32_C(   977.49),
                         SIMDE_FLOAT32_C(  -756.42), SIMDE_FLOAT32_C(   424.81), SIMDE_FLOAT32_C(    27.25), SIMDE_FLOAT32_C(   -95.15)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    -0.83), SIMDE_FLOAT32_C(     0.51), SIMDE_FLOAT32_C(    -0.45), SIMDE_FLOAT32_C(     0.17),
                         SIMDE_FLOAT32_C(    -0.12), SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(    -0.10), SIMDE_FLOAT32_C(    -0.00),
                         SIMDE_FLOAT32_C(    -0.26), SIMDE_FLOAT32_C(     0.10), SIMDE_FLOAT32_C(     0.93), SIMDE_FLOAT32_C(    -0.90),
                         SIMDE_FLOAT32_C(    -0.76), SIMDE_FLOAT32_C(    -0.77), SIMDE_FLOAT32_C(    -0.52), SIMDE_FLOAT32_C(     0.62)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -438.19), SIMDE_FLOAT32_C(  -359.76), SIMDE_FLOAT32_C(  -752.43), SIMDE_FLOAT32_C(   -33.67),
                         SIMDE_FLOAT32_C(   932.66), SIMDE_FLOAT32_C(     7.27), SIMDE_FLOAT32_C(  -327.22), SIMDE_FLOAT32_C(  -125.20),
                         SIMDE_FLOAT32_C(  -182.45), SIMDE_FLOAT32_C(    39.93), SIMDE_FLOAT32_C(   510.85), SIMDE_FLOAT32_C(   394.67),
                         SIMDE_FLOAT32_C(    14.34), SIMDE_FLOAT32_C(  -304.73), SIMDE_FLOAT32_C(   916.26), SIMDE_FLOAT32_C(  -696.69)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    -0.06), SIMDE_FLOAT32_C(    -0.05), SIMDE_FLOAT32_C(     0.02), SIMDE_FLOAT32_C(    -0.63),
                         SIMDE_FLOAT32_C(    -0.92), SIMDE_FLOAT32_C(     0.55), SIMDE_FLOAT32_C(     0.88), SIMDE_FLOAT32_C(     0.89),
                         SIMDE_FLOAT32_C(     0.97), SIMDE_FLOAT32_C(    -0.61), SIMDE_FLOAT32_C(    -0.33), SIMDE_FLOAT32_C(     0.39),
                         SIMDE_FLOAT32_C(    -0.20), SIMDE_FLOAT32_C(    -1.00), SIMDE_FLOAT32_C(     0.47), SIMDE_FLOAT32_C(     0.74)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512 r = simde_mm512_cos_ps(test_vec[i].a);
    simde_assert_m512_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_mask_cos_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512 src;
    simde__mmask16 k;
    simde__m512 a;
    simde__m512 r;
  } test_vec[8] = {
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -450.67), SIMDE_FLOAT32_C(   687.09), SIMDE_FLOAT32_C(  -212.54), SIMDE_FLOAT32_C(  -660.80),
                         SIMDE_FLOAT32_C(    28.47), SIMDE_FLOAT32_C(  -923.64), SIMDE_FLOAT32_C(  -860.95), SIMDE_FLOAT32_C(   696.87),
                         SIMDE_FLOAT32_C(  -686.13), SIMDE_FLOAT32_C(   571.46), SIMDE_FLOAT32_C(   422.21), SIMDE_FLOAT32_C(   467.76),
                         SIMDE_FLOAT32_C(   670.24), SIMDE_FLOAT32_C(    34.06), SIMDE_FLOAT32_C(    39.01), SIMDE_FLOAT32_C(   346.63)),
      UINT16_C(41466),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   178.20), SIMDE_FLOAT32_C(   233.37), SIMDE_FLOAT32_C(   261.31), SIMDE_FLOAT32_C(  -976.55),
                         SIMDE_FLOAT32_C(  -444.81), SIMDE_FLOAT32_C(  -384.03), SIMDE_FLOAT32_C(  -305.07), SIMDE_FLOAT32_C(  -417.54),
                         SIMDE_FLOAT32_C(  -678.17), SIMDE_FLOAT32_C(    84.77), SIMDE_FLOAT32_C(   825.53), SIMDE_FLOAT32_C(  -269.45),
                         SIMDE_FLOAT32_C(   497.31), SIMDE_FLOAT32_C(  -297.45), SIMDE_FLOAT32_C(  -186.21), SIMDE_FLOAT32_C(  -754.38)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    -0.64), SIMDE_FLOAT32_C(   687.09), SIMDE_FLOAT32_C(    -0.85), SIMDE_FLOAT32_C(  -660.80),
                         SIMDE_FLOAT32_C(    28.47), SIMDE_FLOAT32_C(  -923.64), SIMDE_FLOAT32_C(  -860.95), SIMDE_FLOAT32_C(    -0.96),
                         SIMDE_FLOAT32_C(     0.92), SIMDE_FLOAT32_C(    -1.00), SIMDE_FLOAT32_C(    -0.76), SIMDE_FLOAT32_C(     0.75),
                         SIMDE_FLOAT32_C(     0.59), SIMDE_FLOAT32_C(    34.06), SIMDE_FLOAT32_C(    -0.66), SIMDE_FLOAT32_C(   346.63)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   469.66), SIMDE_FLOAT32_C(  -148.69), SIMDE_FLOAT32_C(   910.03), SIMDE_FLOAT32_C(   791.23),
                         SIMDE_FLOAT32_C(  -203.65), SIMDE_FLOAT32_C(   336.73), SIMDE_FLOAT32_C(  -747.59), SIMDE_FLOAT32_C(  -554.19),
                         SIMDE_FLOAT32_C(  -387.90), SIMDE_FLOAT32_C(   655.87), SIMDE_FLOAT32_C(   532.35), SIMDE_FLOAT32_C(   780.64),
                         SIMDE_FLOAT32_C(  -770.35), SIMDE_FLOAT32_C(  -583.60), SIMDE_FLOAT32_C(  -770.72), SIMDE_FLOAT32_C(    28.08)),
      UINT16_C(36797),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -171.51), SIMDE_FLOAT32_C(   680.02), SIMDE_FLOAT32_C(   818.66), SIMDE_FLOAT32_C(   600.47),
                         SIMDE_FLOAT32_C(   254.31), SIMDE_FLOAT32_C(   -80.73), SIMDE_FLOAT32_C(  -944.78), SIMDE_FLOAT32_C(  -767.23),
                         SIMDE_FLOAT32_C(   398.82), SIMDE_FLOAT32_C(   395.92), SIMDE_FLOAT32_C(   339.21), SIMDE_FLOAT32_C(  -263.99),
                         SIMDE_FLOAT32_C(   -30.79), SIMDE_FLOAT32_C(   443.48), SIMDE_FLOAT32_C(   380.46), SIMDE_FLOAT32_C(   993.90)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    -0.29), SIMDE_FLOAT32_C(  -148.69), SIMDE_FLOAT32_C(   910.03), SIMDE_FLOAT32_C(   791.23),
                         SIMDE_FLOAT32_C(    -0.99), SIMDE_FLOAT32_C(     0.58), SIMDE_FLOAT32_C(    -0.67), SIMDE_FLOAT32_C(     0.78),
                         SIMDE_FLOAT32_C(    -0.99), SIMDE_FLOAT32_C(   655.87), SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(     1.00),
                         SIMDE_FLOAT32_C(     0.81), SIMDE_FLOAT32_C(    -0.87), SIMDE_FLOAT32_C(  -770.72), SIMDE_FLOAT32_C(     0.40)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   -95.15), SIMDE_FLOAT32_C(   840.65), SIMDE_FLOAT32_C(  -591.56), SIMDE_FLOAT32_C(   731.49),
                         SIMDE_FLOAT32_C(   623.70), SIMDE_FLOAT32_C(   140.67), SIMDE_FLOAT32_C(  -906.16), SIMDE_FLOAT32_C(    99.93),
                         SIMDE_FLOAT32_C(  -738.19), SIMDE_FLOAT32_C(   758.79), SIMDE_FLOAT32_C(   343.48), SIMDE_FLOAT32_C(  -797.92),
                         SIMDE_FLOAT32_C(  -525.83), SIMDE_FLOAT32_C(  -822.65), SIMDE_FLOAT32_C(   655.67), SIMDE_FLOAT32_C(   543.35)),
      UINT16_C(16804),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    27.25), SIMDE_FLOAT32_C(   690.12), SIMDE_FLOAT32_C(   -21.09), SIMDE_FLOAT32_C(  -448.89),
                         SIMDE_FLOAT32_C(   505.79), SIMDE_FLOAT32_C(   831.02), SIMDE_FLOAT32_C(   977.36), SIMDE_FLOAT32_C(   331.34),
                         SIMDE_FLOAT32_C(   462.95), SIMDE_FLOAT32_C(  -178.99), SIMDE_FLOAT32_C(   324.62), SIMDE_FLOAT32_C(  -874.31),
                         SIMDE_FLOAT32_C(  -328.54), SIMDE_FLOAT32_C(  -192.31), SIMDE_FLOAT32_C(   561.36), SIMDE_FLOAT32_C(   -70.91)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   -95.15), SIMDE_FLOAT32_C(     0.51), SIMDE_FLOAT32_C(  -591.56), SIMDE_FLOAT32_C(   731.49),
                         SIMDE_FLOAT32_C(   623.70), SIMDE_FLOAT32_C(   140.67), SIMDE_FLOAT32_C(  -906.16), SIMDE_FLOAT32_C(    -0.10),
                         SIMDE_FLOAT32_C(    -0.42), SIMDE_FLOAT32_C(   758.79), SIMDE_FLOAT32_C(    -0.51), SIMDE_FLOAT32_C(  -797.92),
                         SIMDE_FLOAT32_C(  -525.83), SIMDE_FLOAT32_C(    -0.78), SIMDE_FLOAT32_C(   655.67), SIMDE_FLOAT32_C(   543.35)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -348.70), SIMDE_FLOAT32_C(  -438.19), SIMDE_FLOAT32_C(  -752.43), SIMDE_FLOAT32_C(   932.66),
                         SIMDE_FLOAT32_C(  -327.22), SIMDE_FLOAT32_C(  -182.45), SIMDE_FLOAT32_C(   510.85), SIMDE_FLOAT32_C(    14.34),
                         SIMDE_FLOAT32_C(   916.26), SIMDE_FLOAT32_C(  -769.09), SIMDE_FLOAT32_C(  -573.81), SIMDE_FLOAT32_C(  -337.60),
                         SIMDE_FLOAT32_C(   293.64), SIMDE_FLOAT32_C(  -576.22), SIMDE_FLOAT32_C(   710.38), SIMDE_FLOAT32_C(  -756.42)),
      UINT16_C( 2107),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   897.27), SIMDE_FLOAT32_C(  -197.89), SIMDE_FLOAT32_C(  -359.76), SIMDE_FLOAT32_C(   -33.67),
                         SIMDE_FLOAT32_C(     7.27), SIMDE_FLOAT32_C(  -125.20), SIMDE_FLOAT32_C(    39.93), SIMDE_FLOAT32_C(   394.67),
                         SIMDE_FLOAT32_C(  -304.73), SIMDE_FLOAT32_C(  -696.69), SIMDE_FLOAT32_C(   822.06), SIMDE_FLOAT32_C(  -997.63),
                         SIMDE_FLOAT32_C(   923.64), SIMDE_FLOAT32_C(  -768.12), SIMDE_FLOAT32_C(   -67.64), SIMDE_FLOAT32_C(   977.49)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -348.70), SIMDE_FLOAT32_C(  -438.19), SIMDE_FLOAT32_C(  -752.43), SIMDE_FLOAT32_C(   932.66),
                         SIMDE_FLOAT32_C(     0.55), SIMDE_FLOAT32_C(  -182.45), SIMDE_FLOAT32_C(   510.85), SIMDE_FLOAT32_C(    14.34),
                         SIMDE_FLOAT32_C(   916.26), SIMDE_FLOAT32_C(  -769.09), SIMDE_FLOAT32_C(     0.51), SIMDE_FLOAT32_C(     0.17),
                         SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(  -576.22), SIMDE_FLOAT32_C(     0.10), SIMDE_FLOAT32_C(    -0.90)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   -15.61), SIMDE_FLOAT32_C(  -737.13), SIMDE_FLOAT32_C(  -314.93), SIMDE_FLOAT32_C(   177.92),
                         SIMDE_FLOAT32_C(   345.93), SIMDE_FLOAT32_C(   888.71), SIMDE_FLOAT32_C(   915.71), SIMDE_FLOAT32_C(   133.52),
                         SIMDE_FLOAT32_C(   484.94), SIMDE_FLOAT32_C(  -598.06), SIMDE_FLOAT32_C(  -791.07), SIMDE_FLOAT32_C(  -765.93),
                         SIMDE_FLOAT32_C(   221.37), SIMDE_FLOAT32_C(  -788.36), SIMDE_FLOAT32_C(  -775.04), SIMDE_FLOAT32_C(   440.64)),
      UINT16_C(22274),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   496.57), SIMDE_FLOAT32_C(   915.19), SIMDE_FLOAT32_C(  -718.40), SIMDE_FLOAT32_C(   159.97),
                         SIMDE_FLOAT32_C(  -861.01), SIMDE_FLOAT32_C(   426.61), SIMDE_FLOAT32_C(   932.11), SIMDE_FLOAT32_C(   110.36),
                         SIMDE_FLOAT32_C(   826.84), SIMDE_FLOAT32_C(   -76.75), SIMDE_FLOAT32_C(   237.58), SIMDE_FLOAT32_C(  -378.50),
                         SIMDE_FLOAT32_C(  -601.68), SIMDE_FLOAT32_C(  -623.50), SIMDE_FLOAT32_C(  -942.47), SIMDE_FLOAT32_C(   475.51)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   -15.61), SIMDE_FLOAT32_C(    -0.55), SIMDE_FLOAT32_C(  -314.93), SIMDE_FLOAT32_C(    -0.97),
                         SIMDE_FLOAT32_C(   345.93), SIMDE_FLOAT32_C(     0.80), SIMDE_FLOAT32_C(    -0.59), SIMDE_FLOAT32_C(    -0.92),
                         SIMDE_FLOAT32_C(   484.94), SIMDE_FLOAT32_C(  -598.06), SIMDE_FLOAT32_C(  -791.07), SIMDE_FLOAT32_C(  -765.93),
                         SIMDE_FLOAT32_C(   221.37), SIMDE_FLOAT32_C(  -788.36), SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(   440.64)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   883.05), SIMDE_FLOAT32_C(  -807.28), SIMDE_FLOAT32_C(   -70.05), SIMDE_FLOAT32_C(  -784.34),
                         SIMDE_FLOAT32_C(    92.52), SIMDE_FLOAT32_C(   206.60), SIMDE_FLOAT32_C(   834.60), SIMDE_FLOAT32_C(   -65.60),
                         SIMDE_FLOAT32_C(  -286.07), SIMDE_FLOAT32_C(  -212.86), SIMDE_FLOAT32_C(  -318.38), SIMDE_FLOAT32_C(   783.48),
                         SIMDE_FLOAT32_C(  -628.82), SIMDE_FLOAT32_C(   556.35), SIMDE_FLOAT32_C(   439.43), SIMDE_FLOAT32_C(   434.03)),
      UINT16_C(27396),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -964.25), SIMDE_FLOAT32_C(  -406.33), SIMDE_FLOAT32_C(  -743.66), SIMDE_FLOAT32_C(  -764.58),
                         SIMDE_FLOAT32_C(   789.89), SIMDE_FLOAT32_C(     4.83), SIMDE_FLOAT32_C(  -818.54), SIMDE_FLOAT32_C(   161.06),
                         SIMDE_FLOAT32_C(   579.25), SIMDE_FLOAT32_C(   -11.78), SIMDE_FLOAT32_C(  -308.52), SIMDE_FLOAT32_C(  -719.57),
                         SIMDE_FLOAT32_C(   334.00), SIMDE_FLOAT32_C(   274.71), SIMDE_FLOAT32_C(  -916.82), SIMDE_FLOAT32_C(  -490.00)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   883.05), SIMDE_FLOAT32_C(    -0.48), SIMDE_FLOAT32_C(    -0.62), SIMDE_FLOAT32_C(  -784.34),
                         SIMDE_FLOAT32_C(    -0.22), SIMDE_FLOAT32_C(   206.60), SIMDE_FLOAT32_C(    -0.15), SIMDE_FLOAT32_C(    -0.67),
                         SIMDE_FLOAT32_C(  -286.07), SIMDE_FLOAT32_C(  -212.86), SIMDE_FLOAT32_C(  -318.38), SIMDE_FLOAT32_C(   783.48),
                         SIMDE_FLOAT32_C(  -628.82), SIMDE_FLOAT32_C(    -0.18), SIMDE_FLOAT32_C(   439.43), SIMDE_FLOAT32_C(   434.03)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   529.63), SIMDE_FLOAT32_C(   -24.89), SIMDE_FLOAT32_C(  -967.78), SIMDE_FLOAT32_C(   638.94),
                         SIMDE_FLOAT32_C(   450.90), SIMDE_FLOAT32_C(  -771.54), SIMDE_FLOAT32_C(   105.79), SIMDE_FLOAT32_C(   590.10),
                         SIMDE_FLOAT32_C(    30.91), SIMDE_FLOAT32_C(   635.35), SIMDE_FLOAT32_C(   -84.00), SIMDE_FLOAT32_C(    80.04),
                         SIMDE_FLOAT32_C(  -709.46), SIMDE_FLOAT32_C(   607.86), SIMDE_FLOAT32_C(   394.58), SIMDE_FLOAT32_C(  -889.11)),
      UINT16_C(  953),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    18.75), SIMDE_FLOAT32_C(   809.05), SIMDE_FLOAT32_C(   144.05), SIMDE_FLOAT32_C(  -427.72),
                         SIMDE_FLOAT32_C(   308.28), SIMDE_FLOAT32_C(  -177.05), SIMDE_FLOAT32_C(  -457.77), SIMDE_FLOAT32_C(   678.24),
                         SIMDE_FLOAT32_C(    66.05), SIMDE_FLOAT32_C(  -267.71), SIMDE_FLOAT32_C(   117.28), SIMDE_FLOAT32_C(  -576.80),
                         SIMDE_FLOAT32_C(   -38.39), SIMDE_FLOAT32_C(  -250.14), SIMDE_FLOAT32_C(   -53.92), SIMDE_FLOAT32_C(    91.94)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   529.63), SIMDE_FLOAT32_C(   -24.89), SIMDE_FLOAT32_C(  -967.78), SIMDE_FLOAT32_C(   638.94),
                         SIMDE_FLOAT32_C(   450.90), SIMDE_FLOAT32_C(  -771.54), SIMDE_FLOAT32_C(     0.62), SIMDE_FLOAT32_C(     0.94),
                         SIMDE_FLOAT32_C(    -1.00), SIMDE_FLOAT32_C(   635.35), SIMDE_FLOAT32_C(    -0.51), SIMDE_FLOAT32_C(     0.31),
                         SIMDE_FLOAT32_C(     0.77), SIMDE_FLOAT32_C(   607.86), SIMDE_FLOAT32_C(   394.58), SIMDE_FLOAT32_C(    -0.67)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -788.39), SIMDE_FLOAT32_C(   330.43), SIMDE_FLOAT32_C(  -493.41), SIMDE_FLOAT32_C(   822.72),
                         SIMDE_FLOAT32_C(   956.68), SIMDE_FLOAT32_C(   954.62), SIMDE_FLOAT32_C(   825.49), SIMDE_FLOAT32_C(  -816.27),
                         SIMDE_FLOAT32_C(  -209.34), SIMDE_FLOAT32_C(  -933.21), SIMDE_FLOAT32_C(  -728.70), SIMDE_FLOAT32_C(  -420.06),
                         SIMDE_FLOAT32_C(   100.32), SIMDE_FLOAT32_C(   103.15), SIMDE_FLOAT32_C(   439.77), SIMDE_FLOAT32_C(  -204.33)),
      UINT16_C(12713),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -841.43), SIMDE_FLOAT32_C(   -14.16), SIMDE_FLOAT32_C(   824.88), SIMDE_FLOAT32_C(   793.63),
                         SIMDE_FLOAT32_C(  -736.75), SIMDE_FLOAT32_C(  -310.57), SIMDE_FLOAT32_C(   728.87), SIMDE_FLOAT32_C(  -350.72),
                         SIMDE_FLOAT32_C(    60.89), SIMDE_FLOAT32_C(   109.81), SIMDE_FLOAT32_C(   715.94), SIMDE_FLOAT32_C(  -250.60),
                         SIMDE_FLOAT32_C(   944.14), SIMDE_FLOAT32_C(   361.85), SIMDE_FLOAT32_C(   -13.07), SIMDE_FLOAT32_C(   852.60)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -788.39), SIMDE_FLOAT32_C(   330.43), SIMDE_FLOAT32_C(    -0.21), SIMDE_FLOAT32_C(    -0.37),
                         SIMDE_FLOAT32_C(   956.68), SIMDE_FLOAT32_C(   954.62), SIMDE_FLOAT32_C(   825.49), SIMDE_FLOAT32_C(     0.42),
                         SIMDE_FLOAT32_C(    -0.36), SIMDE_FLOAT32_C(  -933.21), SIMDE_FLOAT32_C(     0.94), SIMDE_FLOAT32_C(  -420.06),
                         SIMDE_FLOAT32_C(    -0.09), SIMDE_FLOAT32_C(   103.15), SIMDE_FLOAT32_C(   439.77), SIMDE_FLOAT32_C(    -0.34)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512 r = simde_mm512_mask_cos_ps(test_vec[i].src, test_vec[i].k, test_vec[i].a);
    simde_assert_m512_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_cos_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512d a;
    simde__m512d r;
  } test_vec[8] = {
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  497.31), SIMDE_FLOAT64_C(  670.24),
                         SIMDE_FLOAT64_C( -297.45), SIMDE_FLOAT64_C(   34.06),
                         SIMDE_FLOAT64_C( -186.21), SIMDE_FLOAT64_C(   39.01),
                         SIMDE_FLOAT64_C( -754.38), SIMDE_FLOAT64_C(  346.63)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.59), SIMDE_FLOAT64_C(   -0.47),
                         SIMDE_FLOAT64_C(   -0.54), SIMDE_FLOAT64_C(   -0.88),
                         SIMDE_FLOAT64_C(   -0.66), SIMDE_FLOAT64_C(    0.26),
                         SIMDE_FLOAT64_C(    0.92), SIMDE_FLOAT64_C(    0.49)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -678.17), SIMDE_FLOAT64_C( -686.13),
                         SIMDE_FLOAT64_C(   84.77), SIMDE_FLOAT64_C(  571.46),
                         SIMDE_FLOAT64_C(  825.53), SIMDE_FLOAT64_C(  422.21),
                         SIMDE_FLOAT64_C( -269.45), SIMDE_FLOAT64_C(  467.76)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.92), SIMDE_FLOAT64_C(    0.30),
                         SIMDE_FLOAT64_C(   -1.00), SIMDE_FLOAT64_C(    0.95),
                         SIMDE_FLOAT64_C(   -0.76), SIMDE_FLOAT64_C(    0.33),
                         SIMDE_FLOAT64_C(    0.75), SIMDE_FLOAT64_C(   -0.94)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -444.81), SIMDE_FLOAT64_C(   28.47),
                         SIMDE_FLOAT64_C( -384.03), SIMDE_FLOAT64_C( -923.64),
                         SIMDE_FLOAT64_C( -305.07), SIMDE_FLOAT64_C( -860.95),
                         SIMDE_FLOAT64_C( -417.54), SIMDE_FLOAT64_C(  696.87)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.27), SIMDE_FLOAT64_C(   -0.98),
                         SIMDE_FLOAT64_C(    0.73), SIMDE_FLOAT64_C(    1.00),
                         SIMDE_FLOAT64_C(   -0.94), SIMDE_FLOAT64_C(    0.99),
                         SIMDE_FLOAT64_C(   -0.96), SIMDE_FLOAT64_C(    0.85)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  178.20), SIMDE_FLOAT64_C( -450.67),
                         SIMDE_FLOAT64_C(  233.37), SIMDE_FLOAT64_C(  687.09),
                         SIMDE_FLOAT64_C(  261.31), SIMDE_FLOAT64_C( -212.54),
                         SIMDE_FLOAT64_C( -976.55), SIMDE_FLOAT64_C( -660.80)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   -0.64), SIMDE_FLOAT64_C(   -0.15),
                         SIMDE_FLOAT64_C(    0.63), SIMDE_FLOAT64_C(   -0.61),
                         SIMDE_FLOAT64_C(   -0.85), SIMDE_FLOAT64_C(    0.46),
                         SIMDE_FLOAT64_C(   -0.88), SIMDE_FLOAT64_C(    0.48)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -770.35), SIMDE_FLOAT64_C(  443.48),
                         SIMDE_FLOAT64_C( -583.60), SIMDE_FLOAT64_C(  380.46),
                         SIMDE_FLOAT64_C( -770.72), SIMDE_FLOAT64_C(  993.90),
                         SIMDE_FLOAT64_C(   28.08), SIMDE_FLOAT64_C(  841.21)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   -0.79), SIMDE_FLOAT64_C(   -0.87),
                         SIMDE_FLOAT64_C(    0.74), SIMDE_FLOAT64_C(   -0.95),
                         SIMDE_FLOAT64_C(   -0.51), SIMDE_FLOAT64_C(    0.40),
                         SIMDE_FLOAT64_C(   -0.98), SIMDE_FLOAT64_C(    0.74)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -387.90), SIMDE_FLOAT64_C(  395.92),
                         SIMDE_FLOAT64_C(  655.87), SIMDE_FLOAT64_C(  339.21),
                         SIMDE_FLOAT64_C(  532.35), SIMDE_FLOAT64_C( -263.99),
                         SIMDE_FLOAT64_C(  780.64), SIMDE_FLOAT64_C(  -30.79)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   -0.09), SIMDE_FLOAT64_C(    1.00),
                         SIMDE_FLOAT64_C(   -0.75), SIMDE_FLOAT64_C(    1.00),
                         SIMDE_FLOAT64_C(   -0.15), SIMDE_FLOAT64_C(    1.00),
                         SIMDE_FLOAT64_C(    0.05), SIMDE_FLOAT64_C(    0.81)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -203.65), SIMDE_FLOAT64_C(  -80.73),
                         SIMDE_FLOAT64_C(  336.73), SIMDE_FLOAT64_C( -944.78),
                         SIMDE_FLOAT64_C( -747.59), SIMDE_FLOAT64_C( -767.23),
                         SIMDE_FLOAT64_C( -554.19), SIMDE_FLOAT64_C(  398.82)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   -0.85), SIMDE_FLOAT64_C(    0.58),
                         SIMDE_FLOAT64_C(   -0.84), SIMDE_FLOAT64_C(   -0.67),
                         SIMDE_FLOAT64_C(    0.99), SIMDE_FLOAT64_C(    0.78),
                         SIMDE_FLOAT64_C(    0.30), SIMDE_FLOAT64_C(   -0.99)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  469.66), SIMDE_FLOAT64_C(  680.02),
                         SIMDE_FLOAT64_C( -148.69), SIMDE_FLOAT64_C(  818.66),
                         SIMDE_FLOAT64_C(  910.03), SIMDE_FLOAT64_C(  600.47),
                         SIMDE_FLOAT64_C(  791.23), SIMDE_FLOAT64_C(  254.31)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   -0.01), SIMDE_FLOAT64_C(    0.13),
                         SIMDE_FLOAT64_C(   -0.51), SIMDE_FLOAT64_C(   -0.27),
                         SIMDE_FLOAT64_C(    0.51), SIMDE_FLOAT64_C(   -0.91),
                         SIMDE_FLOAT64_C(    0.90), SIMDE_FLOAT64_C(   -0.99)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512d r = simde_mm512_cos_pd(test_vec[i].a);
    simde_assert_m512d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_mask_cos_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512d src;
    simde__mmask8 k;
    simde__m512d a;
    simde__m512d r;
  } test_vec[8] = {
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -686.13), SIMDE_FLOAT64_C(  571.46),
                         SIMDE_FLOAT64_C(  422.21), SIMDE_FLOAT64_C(  467.76),
                         SIMDE_FLOAT64_C(  670.24), SIMDE_FLOAT64_C(   34.06),
                         SIMDE_FLOAT64_C(   39.01), SIMDE_FLOAT64_C(  346.63)),
      UINT8_C(139),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -678.17), SIMDE_FLOAT64_C(   84.77),
                         SIMDE_FLOAT64_C(  825.53), SIMDE_FLOAT64_C( -269.45),
                         SIMDE_FLOAT64_C(  497.31), SIMDE_FLOAT64_C( -297.45),
                         SIMDE_FLOAT64_C( -186.21), SIMDE_FLOAT64_C( -754.38)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.92), SIMDE_FLOAT64_C(  571.46),
                         SIMDE_FLOAT64_C(  422.21), SIMDE_FLOAT64_C(  467.76),
                         SIMDE_FLOAT64_C(    0.59), SIMDE_FLOAT64_C(   34.06),
                         SIMDE_FLOAT64_C(   -0.66), SIMDE_FLOAT64_C(    0.92)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  178.20), SIMDE_FLOAT64_C(  233.37),
                         SIMDE_FLOAT64_C(  261.31), SIMDE_FLOAT64_C( -976.55),
                         SIMDE_FLOAT64_C( -444.81), SIMDE_FLOAT64_C( -384.03),
                         SIMDE_FLOAT64_C( -305.07), SIMDE_FLOAT64_C( -417.54)),
      UINT8_C(229),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  841.21), SIMDE_FLOAT64_C( -450.67),
                         SIMDE_FLOAT64_C(  687.09), SIMDE_FLOAT64_C( -212.54),
                         SIMDE_FLOAT64_C( -660.80), SIMDE_FLOAT64_C(   28.47),
                         SIMDE_FLOAT64_C( -923.64), SIMDE_FLOAT64_C( -860.95)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.74), SIMDE_FLOAT64_C(   -0.15),
                         SIMDE_FLOAT64_C(   -0.61), SIMDE_FLOAT64_C( -976.55),
                         SIMDE_FLOAT64_C( -444.81), SIMDE_FLOAT64_C(   -0.98),
                         SIMDE_FLOAT64_C( -305.07), SIMDE_FLOAT64_C(    0.99)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  398.82), SIMDE_FLOAT64_C(  395.92),
                         SIMDE_FLOAT64_C(  339.21), SIMDE_FLOAT64_C( -263.99),
                         SIMDE_FLOAT64_C(  -30.79), SIMDE_FLOAT64_C(  443.48),
                         SIMDE_FLOAT64_C(  380.46), SIMDE_FLOAT64_C(  993.90)),
      UINT8_C(253),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -554.19), SIMDE_FLOAT64_C( -387.90),
                         SIMDE_FLOAT64_C(  655.87), SIMDE_FLOAT64_C(  532.35),
                         SIMDE_FLOAT64_C(  780.64), SIMDE_FLOAT64_C( -770.35),
                         SIMDE_FLOAT64_C( -583.60), SIMDE_FLOAT64_C( -770.72)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.30), SIMDE_FLOAT64_C(   -0.09),
                         SIMDE_FLOAT64_C(   -0.75), SIMDE_FLOAT64_C(   -0.15),
                         SIMDE_FLOAT64_C(    0.05), SIMDE_FLOAT64_C(   -0.79),
                         SIMDE_FLOAT64_C(  380.46), SIMDE_FLOAT64_C(   -0.51)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  120.65), SIMDE_FLOAT64_C(  469.66),
                         SIMDE_FLOAT64_C( -148.69), SIMDE_FLOAT64_C(  910.03),
                         SIMDE_FLOAT64_C(  791.23), SIMDE_FLOAT64_C( -203.65),
                         SIMDE_FLOAT64_C(  336.73), SIMDE_FLOAT64_C( -747.59)),
      UINT8_C( 93),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  543.35), SIMDE_FLOAT64_C( -171.51),
                         SIMDE_FLOAT64_C(  680.02), SIMDE_FLOAT64_C(  818.66),
                         SIMDE_FLOAT64_C(  600.47), SIMDE_FLOAT64_C(  254.31),
                         SIMDE_FLOAT64_C(  -80.73), SIMDE_FLOAT64_C( -944.78)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  120.65), SIMDE_FLOAT64_C(   -0.29),
                         SIMDE_FLOAT64_C( -148.69), SIMDE_FLOAT64_C(   -0.27),
                         SIMDE_FLOAT64_C(   -0.91), SIMDE_FLOAT64_C(   -0.99),
                         SIMDE_FLOAT64_C(  336.73), SIMDE_FLOAT64_C(   -0.67)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(   99.93), SIMDE_FLOAT64_C( -738.19),
                         SIMDE_FLOAT64_C(  758.79), SIMDE_FLOAT64_C(  343.48),
                         SIMDE_FLOAT64_C( -797.92), SIMDE_FLOAT64_C( -525.83),
                         SIMDE_FLOAT64_C( -822.65), SIMDE_FLOAT64_C(  655.67)),
      UINT8_C(145),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  331.34), SIMDE_FLOAT64_C(  462.95),
                         SIMDE_FLOAT64_C( -178.99), SIMDE_FLOAT64_C(  324.62),
                         SIMDE_FLOAT64_C( -874.31), SIMDE_FLOAT64_C( -328.54),
                         SIMDE_FLOAT64_C( -192.31), SIMDE_FLOAT64_C(  561.36)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   -0.10), SIMDE_FLOAT64_C( -738.19),
                         SIMDE_FLOAT64_C(  758.79), SIMDE_FLOAT64_C(   -0.51),
                         SIMDE_FLOAT64_C( -797.92), SIMDE_FLOAT64_C( -525.83),
                         SIMDE_FLOAT64_C( -822.65), SIMDE_FLOAT64_C(   -0.55)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -756.42), SIMDE_FLOAT64_C(   27.25),
                         SIMDE_FLOAT64_C(  690.12), SIMDE_FLOAT64_C(  -21.09),
                         SIMDE_FLOAT64_C( -448.89), SIMDE_FLOAT64_C(  505.79),
                         SIMDE_FLOAT64_C(  831.02), SIMDE_FLOAT64_C(  977.36)),
      UINT8_C( 75),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  977.49), SIMDE_FLOAT64_C(  424.81),
                         SIMDE_FLOAT64_C(  -95.15), SIMDE_FLOAT64_C(  840.65),
                         SIMDE_FLOAT64_C( -591.56), SIMDE_FLOAT64_C(  731.49),
                         SIMDE_FLOAT64_C(  623.70), SIMDE_FLOAT64_C(  140.67)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -756.42), SIMDE_FLOAT64_C(   -0.77),
                         SIMDE_FLOAT64_C(  690.12), SIMDE_FLOAT64_C(  -21.09),
                         SIMDE_FLOAT64_C(    0.59), SIMDE_FLOAT64_C(  505.79),
                         SIMDE_FLOAT64_C(   -0.09), SIMDE_FLOAT64_C(   -0.76)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  394.67), SIMDE_FLOAT64_C( -304.73),
                         SIMDE_FLOAT64_C( -696.69), SIMDE_FLOAT64_C(  822.06),
                         SIMDE_FLOAT64_C( -997.63), SIMDE_FLOAT64_C(  923.64),
                         SIMDE_FLOAT64_C( -768.12), SIMDE_FLOAT64_C(  -67.64)),
      UINT8_C( 93),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  510.85), SIMDE_FLOAT64_C(   14.34),
                         SIMDE_FLOAT64_C(  916.26), SIMDE_FLOAT64_C( -769.09),
                         SIMDE_FLOAT64_C( -573.81), SIMDE_FLOAT64_C( -337.60),
                         SIMDE_FLOAT64_C(  293.64), SIMDE_FLOAT64_C( -576.22)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  394.67), SIMDE_FLOAT64_C(   -0.20),
                         SIMDE_FLOAT64_C( -696.69), SIMDE_FLOAT64_C(   -0.83),
                         SIMDE_FLOAT64_C(   -0.45), SIMDE_FLOAT64_C(   -0.12),
                         SIMDE_FLOAT64_C( -768.12), SIMDE_FLOAT64_C(   -0.26)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  475.51), SIMDE_FLOAT64_C(  936.65),
                         SIMDE_FLOAT64_C( -348.70), SIMDE_FLOAT64_C( -438.19),
                         SIMDE_FLOAT64_C( -752.43), SIMDE_FLOAT64_C(  932.66),
                         SIMDE_FLOAT64_C( -327.22), SIMDE_FLOAT64_C( -182.45)),
      UINT8_C(213),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -775.04), SIMDE_FLOAT64_C(  440.64),
                         SIMDE_FLOAT64_C(  897.27), SIMDE_FLOAT64_C( -197.89),
                         SIMDE_FLOAT64_C( -359.76), SIMDE_FLOAT64_C(  -33.67),
                         SIMDE_FLOAT64_C(    7.27), SIMDE_FLOAT64_C( -125.20)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   -0.60), SIMDE_FLOAT64_C(    0.68),
                         SIMDE_FLOAT64_C( -348.70), SIMDE_FLOAT64_C(   -1.00),
                         SIMDE_FLOAT64_C( -752.43), SIMDE_FLOAT64_C(   -0.63),
                         SIMDE_FLOAT64_C( -327.22), SIMDE_FLOAT64_C(    0.89)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512d r = simde_mm512_mask_cos_pd(test_vec[i].src, test_vec[i].k, test_vec[i].a);
    simde_assert_m512d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cosh_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(     3.48), SIMDE_FLOAT32_C(     4.71), SIMDE_FLOAT32_C(     0.35), SIMDE_FLOAT32_C(     6.41)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    16.25), SIMDE_FLOAT32_C(    55.53), SIMDE_FLOAT32_C(     1.06), SIMDE_FLOAT32_C(   303.95)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(     7.24), SIMDE_FLOAT32_C(     8.19), SIMDE_FLOAT32_C(     2.86), SIMDE_FLOAT32_C(     4.69)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   697.05), SIMDE_FLOAT32_C(  1802.36), SIMDE_FLOAT32_C(     8.76), SIMDE_FLOAT32_C(    54.43)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(     9.04), SIMDE_FLOAT32_C(     6.82), SIMDE_FLOAT32_C(     3.02), SIMDE_FLOAT32_C(     7.07)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  4216.89), SIMDE_FLOAT32_C(   457.99), SIMDE_FLOAT32_C(    10.27), SIMDE_FLOAT32_C(   588.07)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(     0.77), SIMDE_FLOAT32_C(     0.73), SIMDE_FLOAT32_C(     4.97), SIMDE_FLOAT32_C(     7.64)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     1.31), SIMDE_FLOAT32_C(     1.28), SIMDE_FLOAT32_C(    72.02), SIMDE_FLOAT32_C(  1039.87)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(     2.82), SIMDE_FLOAT32_C(    -0.24), SIMDE_FLOAT32_C(     2.20), SIMDE_FLOAT32_C(     8.33)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     8.42), SIMDE_FLOAT32_C(     1.03), SIMDE_FLOAT32_C(     4.57), SIMDE_FLOAT32_C(  2073.21)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(     2.05), SIMDE_FLOAT32_C(     4.66), SIMDE_FLOAT32_C(     2.39), SIMDE_FLOAT32_C(    -0.58)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     3.95), SIMDE_FLOAT32_C(    52.82), SIMDE_FLOAT32_C(     5.50), SIMDE_FLOAT32_C(     1.17)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(     5.94), SIMDE_FLOAT32_C(     3.33), SIMDE_FLOAT32_C(    -0.87), SIMDE_FLOAT32_C(     0.87)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   189.97), SIMDE_FLOAT32_C(    13.99), SIMDE_FLOAT32_C(     1.40), SIMDE_FLOAT32_C(     1.40)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(     5.48), SIMDE_FLOAT32_C(     2.02), SIMDE_FLOAT32_C(     5.78), SIMDE_FLOAT32_C(     8.28)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   119.93), SIMDE_FLOAT32_C(     3.84), SIMDE_FLOAT32_C(   161.88), SIMDE_FLOAT32_C(  1972.10)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_cosh_ps(test_vec[i].a);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }


  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cosh_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   -0.26), SIMDE_FLOAT64_C(    3.04)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    1.03), SIMDE_FLOAT64_C(   10.48)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    1.44), SIMDE_FLOAT64_C(    2.12)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    2.23), SIMDE_FLOAT64_C(    4.23)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    1.11), SIMDE_FLOAT64_C(    2.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    1.68), SIMDE_FLOAT64_C(    4.14)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    3.49), SIMDE_FLOAT64_C(    4.01)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   16.41), SIMDE_FLOAT64_C(   27.58)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    1.19), SIMDE_FLOAT64_C(    3.40)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    1.80), SIMDE_FLOAT64_C(   15.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    4.48), SIMDE_FLOAT64_C(    3.27)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   44.12), SIMDE_FLOAT64_C(   13.17)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    2.25), SIMDE_FLOAT64_C(    3.71)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    4.80), SIMDE_FLOAT64_C(   20.44)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   -0.03), SIMDE_FLOAT64_C(   -0.06)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    1.00), SIMDE_FLOAT64_C(    1.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cosh_pd(test_vec[i].a);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_cosh_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(     7.24), SIMDE_FLOAT32_C(     8.19),
                         SIMDE_FLOAT32_C(     2.86), SIMDE_FLOAT32_C(     4.69),
                         SIMDE_FLOAT32_C(     3.48), SIMDE_FLOAT32_C(     4.71),
                         SIMDE_FLOAT32_C(     0.35), SIMDE_FLOAT32_C(     6.41)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   697.05), SIMDE_FLOAT32_C(  1802.36),
                         SIMDE_FLOAT32_C(     8.76), SIMDE_FLOAT32_C(    54.43),
                         SIMDE_FLOAT32_C(    16.25), SIMDE_FLOAT32_C(    55.53),
                         SIMDE_FLOAT32_C(     1.06), SIMDE_FLOAT32_C(   303.95)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(     0.77), SIMDE_FLOAT32_C(     0.73),
                         SIMDE_FLOAT32_C(     4.97), SIMDE_FLOAT32_C(     7.64),
                         SIMDE_FLOAT32_C(     9.04), SIMDE_FLOAT32_C(     6.82),
                         SIMDE_FLOAT32_C(     3.02), SIMDE_FLOAT32_C(     7.07)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     1.31), SIMDE_FLOAT32_C(     1.28),
                         SIMDE_FLOAT32_C(    72.02), SIMDE_FLOAT32_C(  1039.87),
                         SIMDE_FLOAT32_C(  4216.89), SIMDE_FLOAT32_C(   457.99),
                         SIMDE_FLOAT32_C(    10.27), SIMDE_FLOAT32_C(   588.07)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(     2.05), SIMDE_FLOAT32_C(     4.66),
                         SIMDE_FLOAT32_C(     2.39), SIMDE_FLOAT32_C(    -0.58),
                         SIMDE_FLOAT32_C(     2.82), SIMDE_FLOAT32_C(    -0.24),
                         SIMDE_FLOAT32_C(     2.20), SIMDE_FLOAT32_C(     8.33)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     3.95), SIMDE_FLOAT32_C(    52.82),
                         SIMDE_FLOAT32_C(     5.50), SIMDE_FLOAT32_C(     1.17),
                         SIMDE_FLOAT32_C(     8.42), SIMDE_FLOAT32_C(     1.03),
                         SIMDE_FLOAT32_C(     4.57), SIMDE_FLOAT32_C(  2073.21)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(     5.48), SIMDE_FLOAT32_C(     2.02),
                         SIMDE_FLOAT32_C(     5.78), SIMDE_FLOAT32_C(     8.28),
                         SIMDE_FLOAT32_C(     5.94), SIMDE_FLOAT32_C(     3.33),
                         SIMDE_FLOAT32_C(    -0.87), SIMDE_FLOAT32_C(     0.87)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   119.93), SIMDE_FLOAT32_C(     3.84),
                         SIMDE_FLOAT32_C(   161.88), SIMDE_FLOAT32_C(  1972.10),
                         SIMDE_FLOAT32_C(   189.97), SIMDE_FLOAT32_C(    13.99),
                         SIMDE_FLOAT32_C(     1.40), SIMDE_FLOAT32_C(     1.40)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(     0.26), SIMDE_FLOAT32_C(     6.94),
                         SIMDE_FLOAT32_C(     1.29), SIMDE_FLOAT32_C(     6.59),
                         SIMDE_FLOAT32_C(     0.26), SIMDE_FLOAT32_C(     9.97),
                         SIMDE_FLOAT32_C(     4.65), SIMDE_FLOAT32_C(     9.13)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     1.03), SIMDE_FLOAT32_C(   516.39),
                         SIMDE_FLOAT32_C(     1.95), SIMDE_FLOAT32_C(   363.89),
                         SIMDE_FLOAT32_C(     1.03), SIMDE_FLOAT32_C( 10687.75),
                         SIMDE_FLOAT32_C(    52.30), SIMDE_FLOAT32_C(  4614.01)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(     2.37), SIMDE_FLOAT32_C(     6.68),
                         SIMDE_FLOAT32_C(     8.11), SIMDE_FLOAT32_C(     6.37),
                         SIMDE_FLOAT32_C(     7.43), SIMDE_FLOAT32_C(     3.05),
                         SIMDE_FLOAT32_C(     8.79), SIMDE_FLOAT32_C(     4.33)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     5.40), SIMDE_FLOAT32_C(   398.16),
                         SIMDE_FLOAT32_C(  1663.79), SIMDE_FLOAT32_C(   292.03),
                         SIMDE_FLOAT32_C(   842.90), SIMDE_FLOAT32_C(    10.58),
                         SIMDE_FLOAT32_C(  3284.12), SIMDE_FLOAT32_C(    37.98)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(     3.38), SIMDE_FLOAT32_C(     4.06),
                         SIMDE_FLOAT32_C(     6.35), SIMDE_FLOAT32_C(    -0.70),
                         SIMDE_FLOAT32_C(     0.39), SIMDE_FLOAT32_C(     0.28),
                         SIMDE_FLOAT32_C(     1.45), SIMDE_FLOAT32_C(     6.69)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    14.70), SIMDE_FLOAT32_C(    29.00),
                         SIMDE_FLOAT32_C(   286.25), SIMDE_FLOAT32_C(     1.26),
                         SIMDE_FLOAT32_C(     1.08), SIMDE_FLOAT32_C(     1.04),
                         SIMDE_FLOAT32_C(     2.25), SIMDE_FLOAT32_C(   402.16)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(     7.08), SIMDE_FLOAT32_C(     8.24),
                         SIMDE_FLOAT32_C(     3.68), SIMDE_FLOAT32_C(     9.00),
                         SIMDE_FLOAT32_C(     9.51), SIMDE_FLOAT32_C(     7.80),
                         SIMDE_FLOAT32_C(     8.85), SIMDE_FLOAT32_C(     5.90)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   593.98), SIMDE_FLOAT32_C(  1894.77),
                         SIMDE_FLOAT32_C(    19.84), SIMDE_FLOAT32_C(  4051.54),
                         SIMDE_FLOAT32_C(  6747.00), SIMDE_FLOAT32_C(  1220.30),
                         SIMDE_FLOAT32_C(  3487.20), SIMDE_FLOAT32_C(   182.52)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_cosh_ps(test_vec[i].a);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_cosh_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(    1.44), SIMDE_FLOAT64_C(    2.12),
                         SIMDE_FLOAT64_C(   -0.26), SIMDE_FLOAT64_C(    3.04)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    2.23), SIMDE_FLOAT64_C(    4.23),
                         SIMDE_FLOAT64_C(    1.03), SIMDE_FLOAT64_C(   10.48)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(    3.49), SIMDE_FLOAT64_C(    4.01),
                         SIMDE_FLOAT64_C(    1.11), SIMDE_FLOAT64_C(    2.10)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   16.41), SIMDE_FLOAT64_C(   27.58),
                         SIMDE_FLOAT64_C(    1.68), SIMDE_FLOAT64_C(    4.14)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(    4.48), SIMDE_FLOAT64_C(    3.27),
                         SIMDE_FLOAT64_C(    1.19), SIMDE_FLOAT64_C(    3.40)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   44.12), SIMDE_FLOAT64_C(   13.17),
                         SIMDE_FLOAT64_C(    1.80), SIMDE_FLOAT64_C(   15.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   -0.03), SIMDE_FLOAT64_C(   -0.06),
                         SIMDE_FLOAT64_C(    2.25), SIMDE_FLOAT64_C(    3.71)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    1.00), SIMDE_FLOAT64_C(    1.00),
                         SIMDE_FLOAT64_C(    4.80), SIMDE_FLOAT64_C(   20.44)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(    1.08), SIMDE_FLOAT64_C(   -0.58),
                         SIMDE_FLOAT64_C(    0.75), SIMDE_FLOAT64_C(    4.09)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    1.64), SIMDE_FLOAT64_C(    1.17),
                         SIMDE_FLOAT64_C(    1.29), SIMDE_FLOAT64_C(   29.88)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.67), SIMDE_FLOAT64_C(    2.09),
                         SIMDE_FLOAT64_C(    0.85), SIMDE_FLOAT64_C(   -0.77)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    1.23), SIMDE_FLOAT64_C(    4.10),
                         SIMDE_FLOAT64_C(    1.38), SIMDE_FLOAT64_C(    1.31)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(    2.78), SIMDE_FLOAT64_C(    1.36),
                         SIMDE_FLOAT64_C(   -0.93), SIMDE_FLOAT64_C(    0.02)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    8.09), SIMDE_FLOAT64_C(    2.08),
                         SIMDE_FLOAT64_C(    1.46), SIMDE_FLOAT64_C(    1.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(    2.53), SIMDE_FLOAT64_C(    0.65),
                         SIMDE_FLOAT64_C(    2.70), SIMDE_FLOAT64_C(    4.06)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    6.32), SIMDE_FLOAT64_C(    1.22),
                         SIMDE_FLOAT64_C(    7.47), SIMDE_FLOAT64_C(   29.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_cosh_pd(test_vec[i].a);
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_cosh_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512 a;
    simde__m512 r;
  } test_vec[8] = {
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.77), SIMDE_FLOAT32_C(     0.73), SIMDE_FLOAT32_C(     4.97), SIMDE_FLOAT32_C(     7.64),
                         SIMDE_FLOAT32_C(     9.04), SIMDE_FLOAT32_C(     6.82), SIMDE_FLOAT32_C(     3.02), SIMDE_FLOAT32_C(     7.07),
                         SIMDE_FLOAT32_C(     7.24), SIMDE_FLOAT32_C(     8.19), SIMDE_FLOAT32_C(     2.86), SIMDE_FLOAT32_C(     4.69),
                         SIMDE_FLOAT32_C(     3.48), SIMDE_FLOAT32_C(     4.71), SIMDE_FLOAT32_C(     0.35), SIMDE_FLOAT32_C(     6.41)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     1.31), SIMDE_FLOAT32_C(     1.28), SIMDE_FLOAT32_C(    72.02), SIMDE_FLOAT32_C(  1039.87),
                         SIMDE_FLOAT32_C(  4216.89), SIMDE_FLOAT32_C(   457.99), SIMDE_FLOAT32_C(    10.27), SIMDE_FLOAT32_C(   588.07),
                         SIMDE_FLOAT32_C(   697.05), SIMDE_FLOAT32_C(  1802.36), SIMDE_FLOAT32_C(     8.76), SIMDE_FLOAT32_C(    54.43),
                         SIMDE_FLOAT32_C(    16.25), SIMDE_FLOAT32_C(    55.53), SIMDE_FLOAT32_C(     1.06), SIMDE_FLOAT32_C(   303.95)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(     5.48), SIMDE_FLOAT32_C(     2.02), SIMDE_FLOAT32_C(     5.78), SIMDE_FLOAT32_C(     8.28),
                         SIMDE_FLOAT32_C(     5.94), SIMDE_FLOAT32_C(     3.33), SIMDE_FLOAT32_C(    -0.87), SIMDE_FLOAT32_C(     0.87),
                         SIMDE_FLOAT32_C(     2.05), SIMDE_FLOAT32_C(     4.66), SIMDE_FLOAT32_C(     2.39), SIMDE_FLOAT32_C(    -0.58),
                         SIMDE_FLOAT32_C(     2.82), SIMDE_FLOAT32_C(    -0.24), SIMDE_FLOAT32_C(     2.20), SIMDE_FLOAT32_C(     8.33)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   119.93), SIMDE_FLOAT32_C(     3.84), SIMDE_FLOAT32_C(   161.88), SIMDE_FLOAT32_C(  1972.10),
                         SIMDE_FLOAT32_C(   189.97), SIMDE_FLOAT32_C(    13.99), SIMDE_FLOAT32_C(     1.40), SIMDE_FLOAT32_C(     1.40),
                         SIMDE_FLOAT32_C(     3.95), SIMDE_FLOAT32_C(    52.82), SIMDE_FLOAT32_C(     5.50), SIMDE_FLOAT32_C(     1.17),
                         SIMDE_FLOAT32_C(     8.42), SIMDE_FLOAT32_C(     1.03), SIMDE_FLOAT32_C(     4.57), SIMDE_FLOAT32_C(  2073.21)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(     2.37), SIMDE_FLOAT32_C(     6.68), SIMDE_FLOAT32_C(     8.11), SIMDE_FLOAT32_C(     6.37),
                         SIMDE_FLOAT32_C(     7.43), SIMDE_FLOAT32_C(     3.05), SIMDE_FLOAT32_C(     8.79), SIMDE_FLOAT32_C(     4.33),
                         SIMDE_FLOAT32_C(     0.26), SIMDE_FLOAT32_C(     6.94), SIMDE_FLOAT32_C(     1.29), SIMDE_FLOAT32_C(     6.59),
                         SIMDE_FLOAT32_C(     0.26), SIMDE_FLOAT32_C(     9.97), SIMDE_FLOAT32_C(     4.65), SIMDE_FLOAT32_C(     9.13)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     5.40), SIMDE_FLOAT32_C(   398.16), SIMDE_FLOAT32_C(  1663.79), SIMDE_FLOAT32_C(   292.03),
                         SIMDE_FLOAT32_C(   842.90), SIMDE_FLOAT32_C(    10.58), SIMDE_FLOAT32_C(  3284.12), SIMDE_FLOAT32_C(    37.98),
                         SIMDE_FLOAT32_C(     1.03), SIMDE_FLOAT32_C(   516.39), SIMDE_FLOAT32_C(     1.95), SIMDE_FLOAT32_C(   363.89),
                         SIMDE_FLOAT32_C(     1.03), SIMDE_FLOAT32_C( 10687.75), SIMDE_FLOAT32_C(    52.30), SIMDE_FLOAT32_C(  4614.01)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(     7.08), SIMDE_FLOAT32_C(     8.24), SIMDE_FLOAT32_C(     3.68), SIMDE_FLOAT32_C(     9.00),
                         SIMDE_FLOAT32_C(     9.51), SIMDE_FLOAT32_C(     7.80), SIMDE_FLOAT32_C(     8.85), SIMDE_FLOAT32_C(     5.90),
                         SIMDE_FLOAT32_C(     3.38), SIMDE_FLOAT32_C(     4.06), SIMDE_FLOAT32_C(     6.35), SIMDE_FLOAT32_C(    -0.70),
                         SIMDE_FLOAT32_C(     0.39), SIMDE_FLOAT32_C(     0.28), SIMDE_FLOAT32_C(     1.45), SIMDE_FLOAT32_C(     6.69)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   593.98), SIMDE_FLOAT32_C(  1894.77), SIMDE_FLOAT32_C(    19.84), SIMDE_FLOAT32_C(  4051.54),
                         SIMDE_FLOAT32_C(  6747.00), SIMDE_FLOAT32_C(  1220.30), SIMDE_FLOAT32_C(  3487.20), SIMDE_FLOAT32_C(   182.52),
                         SIMDE_FLOAT32_C(    14.70), SIMDE_FLOAT32_C(    29.00), SIMDE_FLOAT32_C(   286.25), SIMDE_FLOAT32_C(     1.26),
                         SIMDE_FLOAT32_C(     1.08), SIMDE_FLOAT32_C(     1.04), SIMDE_FLOAT32_C(     2.25), SIMDE_FLOAT32_C(   402.16)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(     3.52), SIMDE_FLOAT32_C(     8.67), SIMDE_FLOAT32_C(     6.29), SIMDE_FLOAT32_C(     6.39),
                         SIMDE_FLOAT32_C(    -0.31), SIMDE_FLOAT32_C(     0.11), SIMDE_FLOAT32_C(     2.69), SIMDE_FLOAT32_C(     1.61),
                         SIMDE_FLOAT32_C(     3.44), SIMDE_FLOAT32_C(    -0.02), SIMDE_FLOAT32_C(     7.59), SIMDE_FLOAT32_C(     8.11),
                         SIMDE_FLOAT32_C(     4.11), SIMDE_FLOAT32_C(     7.49), SIMDE_FLOAT32_C(     5.16), SIMDE_FLOAT32_C(     3.56)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    16.91), SIMDE_FLOAT32_C(  2912.75), SIMDE_FLOAT32_C(   269.58), SIMDE_FLOAT32_C(   297.93),
                         SIMDE_FLOAT32_C(     1.05), SIMDE_FLOAT32_C(     1.01), SIMDE_FLOAT32_C(     7.40), SIMDE_FLOAT32_C(     2.60),
                         SIMDE_FLOAT32_C(    15.61), SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(   989.16), SIMDE_FLOAT32_C(  1663.79),
                         SIMDE_FLOAT32_C(    30.48), SIMDE_FLOAT32_C(   895.03), SIMDE_FLOAT32_C(    87.09), SIMDE_FLOAT32_C(    17.60)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(     8.30), SIMDE_FLOAT32_C(     9.12), SIMDE_FLOAT32_C(     4.38), SIMDE_FLOAT32_C(     1.25),
                         SIMDE_FLOAT32_C(     2.03), SIMDE_FLOAT32_C(     8.52), SIMDE_FLOAT32_C(     7.28), SIMDE_FLOAT32_C(     7.93),
                         SIMDE_FLOAT32_C(     9.07), SIMDE_FLOAT32_C(     5.27), SIMDE_FLOAT32_C(     9.88), SIMDE_FLOAT32_C(    -0.48),
                         SIMDE_FLOAT32_C(     6.32), SIMDE_FLOAT32_C(     5.05), SIMDE_FLOAT32_C(     7.05), SIMDE_FLOAT32_C(     0.44)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  2011.94), SIMDE_FLOAT32_C(  4568.10), SIMDE_FLOAT32_C(    39.93), SIMDE_FLOAT32_C(     1.89),
                         SIMDE_FLOAT32_C(     3.87), SIMDE_FLOAT32_C(  2507.03), SIMDE_FLOAT32_C(   725.49), SIMDE_FLOAT32_C(  1389.71),
                         SIMDE_FLOAT32_C(  4345.31), SIMDE_FLOAT32_C(    97.21), SIMDE_FLOAT32_C(  9767.86), SIMDE_FLOAT32_C(     1.12),
                         SIMDE_FLOAT32_C(   277.79), SIMDE_FLOAT32_C(    78.01), SIMDE_FLOAT32_C(   576.43), SIMDE_FLOAT32_C(     1.10)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.27), SIMDE_FLOAT32_C(     9.02), SIMDE_FLOAT32_C(     1.34), SIMDE_FLOAT32_C(    -0.99),
                         SIMDE_FLOAT32_C(     2.64), SIMDE_FLOAT32_C(     9.58), SIMDE_FLOAT32_C(     6.12), SIMDE_FLOAT32_C(     0.28),
                         SIMDE_FLOAT32_C(     1.33), SIMDE_FLOAT32_C(     4.13), SIMDE_FLOAT32_C(     8.41), SIMDE_FLOAT32_C(     9.88),
                         SIMDE_FLOAT32_C(     0.34), SIMDE_FLOAT32_C(     6.84), SIMDE_FLOAT32_C(     4.65), SIMDE_FLOAT32_C(     3.98)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     1.04), SIMDE_FLOAT32_C(  4133.39), SIMDE_FLOAT32_C(     2.04), SIMDE_FLOAT32_C(     1.53),
                         SIMDE_FLOAT32_C(     7.04), SIMDE_FLOAT32_C(  7236.21), SIMDE_FLOAT32_C(   227.43), SIMDE_FLOAT32_C(     1.04),
                         SIMDE_FLOAT32_C(     2.02), SIMDE_FLOAT32_C(    31.10), SIMDE_FLOAT32_C(  2245.88), SIMDE_FLOAT32_C(  9767.86),
                         SIMDE_FLOAT32_C(     1.06), SIMDE_FLOAT32_C(   467.25), SIMDE_FLOAT32_C(    52.30), SIMDE_FLOAT32_C(    26.77)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(     2.09), SIMDE_FLOAT32_C(     2.52), SIMDE_FLOAT32_C(     0.36), SIMDE_FLOAT32_C(     4.31),
                         SIMDE_FLOAT32_C(     9.63), SIMDE_FLOAT32_C(     4.54), SIMDE_FLOAT32_C(     2.70), SIMDE_FLOAT32_C(     3.81),
                         SIMDE_FLOAT32_C(     3.50), SIMDE_FLOAT32_C(     4.72), SIMDE_FLOAT32_C(     7.31), SIMDE_FLOAT32_C(     6.67),
                         SIMDE_FLOAT32_C(     4.58), SIMDE_FLOAT32_C(     2.82), SIMDE_FLOAT32_C(     9.54), SIMDE_FLOAT32_C(     0.67)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     4.10), SIMDE_FLOAT32_C(     6.25), SIMDE_FLOAT32_C(     1.07), SIMDE_FLOAT32_C(    37.23),
                         SIMDE_FLOAT32_C(  7607.22), SIMDE_FLOAT32_C(    46.85), SIMDE_FLOAT32_C(     7.47), SIMDE_FLOAT32_C(    22.59),
                         SIMDE_FLOAT32_C(    16.57), SIMDE_FLOAT32_C(    56.09), SIMDE_FLOAT32_C(   747.59), SIMDE_FLOAT32_C(   394.20),
                         SIMDE_FLOAT32_C(    48.76), SIMDE_FLOAT32_C(     8.42), SIMDE_FLOAT32_C(  6952.47), SIMDE_FLOAT32_C(     1.23)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512 r = simde_mm512_cosh_ps(test_vec[i].a);
    simde_assert_m512_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_mask_cosh_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512 src;
    simde__mmask16 k;
    simde__m512 a;
    simde__m512 r;
  } test_vec[8] = {
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(     2.02), SIMDE_FLOAT32_C(     8.28), SIMDE_FLOAT32_C(     3.33), SIMDE_FLOAT32_C(     0.87),
                         SIMDE_FLOAT32_C(     4.66), SIMDE_FLOAT32_C(    -0.58), SIMDE_FLOAT32_C(    -0.24), SIMDE_FLOAT32_C(     8.33),
                         SIMDE_FLOAT32_C(     0.73), SIMDE_FLOAT32_C(     7.64), SIMDE_FLOAT32_C(     6.82), SIMDE_FLOAT32_C(     7.07),
                         SIMDE_FLOAT32_C(     8.19), SIMDE_FLOAT32_C(     4.69), SIMDE_FLOAT32_C(     4.71), SIMDE_FLOAT32_C(     6.41)),
      UINT16_C(41466),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     5.48), SIMDE_FLOAT32_C(     5.78), SIMDE_FLOAT32_C(     5.94), SIMDE_FLOAT32_C(    -0.87),
                         SIMDE_FLOAT32_C(     2.05), SIMDE_FLOAT32_C(     2.39), SIMDE_FLOAT32_C(     2.82), SIMDE_FLOAT32_C(     2.20),
                         SIMDE_FLOAT32_C(     0.77), SIMDE_FLOAT32_C(     4.97), SIMDE_FLOAT32_C(     9.04), SIMDE_FLOAT32_C(     3.02),
                         SIMDE_FLOAT32_C(     7.24), SIMDE_FLOAT32_C(     2.86), SIMDE_FLOAT32_C(     3.48), SIMDE_FLOAT32_C(     0.35)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   119.93), SIMDE_FLOAT32_C(     8.28), SIMDE_FLOAT32_C(   189.97), SIMDE_FLOAT32_C(     0.87),
                         SIMDE_FLOAT32_C(     4.66), SIMDE_FLOAT32_C(    -0.58), SIMDE_FLOAT32_C(    -0.24), SIMDE_FLOAT32_C(     4.57),
                         SIMDE_FLOAT32_C(     1.31), SIMDE_FLOAT32_C(    72.02), SIMDE_FLOAT32_C(  4216.89), SIMDE_FLOAT32_C(    10.27),
                         SIMDE_FLOAT32_C(   697.05), SIMDE_FLOAT32_C(     4.69), SIMDE_FLOAT32_C(    16.25), SIMDE_FLOAT32_C(     6.41)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(     7.08), SIMDE_FLOAT32_C(     3.68), SIMDE_FLOAT32_C(     9.51), SIMDE_FLOAT32_C(     8.85),
                         SIMDE_FLOAT32_C(     3.38), SIMDE_FLOAT32_C(     6.35), SIMDE_FLOAT32_C(     0.39), SIMDE_FLOAT32_C(     1.45),
                         SIMDE_FLOAT32_C(     2.37), SIMDE_FLOAT32_C(     8.11), SIMDE_FLOAT32_C(     7.43), SIMDE_FLOAT32_C(     8.79),
                         SIMDE_FLOAT32_C(     0.26), SIMDE_FLOAT32_C(     1.29), SIMDE_FLOAT32_C(     0.26), SIMDE_FLOAT32_C(     4.65)),
      UINT16_C(36797),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     3.56), SIMDE_FLOAT32_C(     8.24), SIMDE_FLOAT32_C(     9.00), SIMDE_FLOAT32_C(     7.80),
                         SIMDE_FLOAT32_C(     5.90), SIMDE_FLOAT32_C(     4.06), SIMDE_FLOAT32_C(    -0.70), SIMDE_FLOAT32_C(     0.28),
                         SIMDE_FLOAT32_C(     6.69), SIMDE_FLOAT32_C(     6.68), SIMDE_FLOAT32_C(     6.37), SIMDE_FLOAT32_C(     3.05),
                         SIMDE_FLOAT32_C(     4.33), SIMDE_FLOAT32_C(     6.94), SIMDE_FLOAT32_C(     6.59), SIMDE_FLOAT32_C(     9.97)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    17.60), SIMDE_FLOAT32_C(     3.68), SIMDE_FLOAT32_C(     9.51), SIMDE_FLOAT32_C(     8.85),
                         SIMDE_FLOAT32_C(   182.52), SIMDE_FLOAT32_C(    29.00), SIMDE_FLOAT32_C(     1.26), SIMDE_FLOAT32_C(     1.04),
                         SIMDE_FLOAT32_C(   402.16), SIMDE_FLOAT32_C(     8.11), SIMDE_FLOAT32_C(   292.03), SIMDE_FLOAT32_C(    10.58),
                         SIMDE_FLOAT32_C(    37.98), SIMDE_FLOAT32_C(   516.39), SIMDE_FLOAT32_C(     0.26), SIMDE_FLOAT32_C( 10687.75)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(     3.98), SIMDE_FLOAT32_C(     9.12), SIMDE_FLOAT32_C(     1.25), SIMDE_FLOAT32_C(     8.52),
                         SIMDE_FLOAT32_C(     7.93), SIMDE_FLOAT32_C(     5.27), SIMDE_FLOAT32_C(    -0.48), SIMDE_FLOAT32_C(     5.05),
                         SIMDE_FLOAT32_C(     0.44), SIMDE_FLOAT32_C(     8.67), SIMDE_FLOAT32_C(     6.39), SIMDE_FLOAT32_C(     0.11),
                         SIMDE_FLOAT32_C(     1.61), SIMDE_FLOAT32_C(    -0.02), SIMDE_FLOAT32_C(     8.11), SIMDE_FLOAT32_C(     7.49)),
      UINT16_C(16804),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     4.65), SIMDE_FLOAT32_C(     8.30), SIMDE_FLOAT32_C(     4.38), SIMDE_FLOAT32_C(     2.03),
                         SIMDE_FLOAT32_C(     7.28), SIMDE_FLOAT32_C(     9.07), SIMDE_FLOAT32_C(     9.88), SIMDE_FLOAT32_C(     6.32),
                         SIMDE_FLOAT32_C(     7.05), SIMDE_FLOAT32_C(     3.52), SIMDE_FLOAT32_C(     6.29), SIMDE_FLOAT32_C(    -0.31),
                         SIMDE_FLOAT32_C(     2.69), SIMDE_FLOAT32_C(     3.44), SIMDE_FLOAT32_C(     7.59), SIMDE_FLOAT32_C(     4.11)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     3.98), SIMDE_FLOAT32_C(  2011.94), SIMDE_FLOAT32_C(     1.25), SIMDE_FLOAT32_C(     8.52),
                         SIMDE_FLOAT32_C(     7.93), SIMDE_FLOAT32_C(     5.27), SIMDE_FLOAT32_C(    -0.48), SIMDE_FLOAT32_C(   277.79),
                         SIMDE_FLOAT32_C(   576.43), SIMDE_FLOAT32_C(     8.67), SIMDE_FLOAT32_C(   269.58), SIMDE_FLOAT32_C(     0.11),
                         SIMDE_FLOAT32_C(     1.61), SIMDE_FLOAT32_C(    15.61), SIMDE_FLOAT32_C(     8.11), SIMDE_FLOAT32_C(     7.49)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(     2.58), SIMDE_FLOAT32_C(     2.09), SIMDE_FLOAT32_C(     0.36), SIMDE_FLOAT32_C(     9.63),
                         SIMDE_FLOAT32_C(     2.70), SIMDE_FLOAT32_C(     3.50), SIMDE_FLOAT32_C(     7.31), SIMDE_FLOAT32_C(     4.58),
                         SIMDE_FLOAT32_C(     9.54), SIMDE_FLOAT32_C(     0.27), SIMDE_FLOAT32_C(     1.34), SIMDE_FLOAT32_C(     2.64),
                         SIMDE_FLOAT32_C(     6.12), SIMDE_FLOAT32_C(     1.33), SIMDE_FLOAT32_C(     8.41), SIMDE_FLOAT32_C(     0.34)),
      UINT16_C( 2107),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     9.43), SIMDE_FLOAT32_C(     3.41), SIMDE_FLOAT32_C(     2.52), SIMDE_FLOAT32_C(     4.31),
                         SIMDE_FLOAT32_C(     4.54), SIMDE_FLOAT32_C(     3.81), SIMDE_FLOAT32_C(     4.72), SIMDE_FLOAT32_C(     6.67),
                         SIMDE_FLOAT32_C(     2.82), SIMDE_FLOAT32_C(     0.67), SIMDE_FLOAT32_C(     9.02), SIMDE_FLOAT32_C(    -0.99),
                         SIMDE_FLOAT32_C(     9.58), SIMDE_FLOAT32_C(     0.28), SIMDE_FLOAT32_C(     4.13), SIMDE_FLOAT32_C(     9.88)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     2.58), SIMDE_FLOAT32_C(     2.09), SIMDE_FLOAT32_C(     0.36), SIMDE_FLOAT32_C(     9.63),
                         SIMDE_FLOAT32_C(    46.85), SIMDE_FLOAT32_C(     3.50), SIMDE_FLOAT32_C(     7.31), SIMDE_FLOAT32_C(     4.58),
                         SIMDE_FLOAT32_C(     9.54), SIMDE_FLOAT32_C(     0.27), SIMDE_FLOAT32_C(  4133.39), SIMDE_FLOAT32_C(     1.53),
                         SIMDE_FLOAT32_C(  7236.21), SIMDE_FLOAT32_C(     1.33), SIMDE_FLOAT32_C(    31.10), SIMDE_FLOAT32_C(  9767.86)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(     4.41), SIMDE_FLOAT32_C(     0.45), SIMDE_FLOAT32_C(     2.77), SIMDE_FLOAT32_C(     5.48),
                         SIMDE_FLOAT32_C(     6.40), SIMDE_FLOAT32_C(     9.39), SIMDE_FLOAT32_C(     9.54), SIMDE_FLOAT32_C(     5.23),
                         SIMDE_FLOAT32_C(     7.17), SIMDE_FLOAT32_C(     1.21), SIMDE_FLOAT32_C(     0.15), SIMDE_FLOAT32_C(     0.29),
                         SIMDE_FLOAT32_C(     5.72), SIMDE_FLOAT32_C(     0.16), SIMDE_FLOAT32_C(     0.24), SIMDE_FLOAT32_C(     6.92)),
      UINT16_C(22274),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     7.23), SIMDE_FLOAT32_C(     9.53), SIMDE_FLOAT32_C(     0.55), SIMDE_FLOAT32_C(     5.38),
                         SIMDE_FLOAT32_C(    -0.24), SIMDE_FLOAT32_C(     6.85), SIMDE_FLOAT32_C(     9.63), SIMDE_FLOAT32_C(     5.11),
                         SIMDE_FLOAT32_C(     9.05), SIMDE_FLOAT32_C(     4.08), SIMDE_FLOAT32_C(     5.81), SIMDE_FLOAT32_C(     2.42),
                         SIMDE_FLOAT32_C(     1.19), SIMDE_FLOAT32_C(     1.07), SIMDE_FLOAT32_C(    -0.68), SIMDE_FLOAT32_C(     7.12)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     4.41), SIMDE_FLOAT32_C(  6883.29), SIMDE_FLOAT32_C(     2.77), SIMDE_FLOAT32_C(   108.51),
                         SIMDE_FLOAT32_C(     6.40), SIMDE_FLOAT32_C(   471.94), SIMDE_FLOAT32_C(  7607.22), SIMDE_FLOAT32_C(    82.84),
                         SIMDE_FLOAT32_C(     7.17), SIMDE_FLOAT32_C(     1.21), SIMDE_FLOAT32_C(     0.15), SIMDE_FLOAT32_C(     0.29),
                         SIMDE_FLOAT32_C(     5.72), SIMDE_FLOAT32_C(     0.16), SIMDE_FLOAT32_C(     1.24), SIMDE_FLOAT32_C(     6.92)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(     9.36), SIMDE_FLOAT32_C(     0.06), SIMDE_FLOAT32_C(     4.11), SIMDE_FLOAT32_C(     0.19),
                         SIMDE_FLOAT32_C(     5.01), SIMDE_FLOAT32_C(     5.64), SIMDE_FLOAT32_C(     9.09), SIMDE_FLOAT32_C(     4.14),
                         SIMDE_FLOAT32_C(     2.93), SIMDE_FLOAT32_C(     3.33), SIMDE_FLOAT32_C(     2.75), SIMDE_FLOAT32_C(     8.81),
                         SIMDE_FLOAT32_C(     1.04), SIMDE_FLOAT32_C(     7.56), SIMDE_FLOAT32_C(     6.92), SIMDE_FLOAT32_C(     6.89)),
      UINT16_C(27396),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    -0.80), SIMDE_FLOAT32_C(     2.27), SIMDE_FLOAT32_C(     0.41), SIMDE_FLOAT32_C(     0.29),
                         SIMDE_FLOAT32_C(     8.84), SIMDE_FLOAT32_C(     4.53), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     5.39),
                         SIMDE_FLOAT32_C(     7.69), SIMDE_FLOAT32_C(     4.44), SIMDE_FLOAT32_C(     2.80), SIMDE_FLOAT32_C(     0.54),
                         SIMDE_FLOAT32_C(     6.34), SIMDE_FLOAT32_C(     6.01), SIMDE_FLOAT32_C(    -0.54), SIMDE_FLOAT32_C(     1.81)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     9.36), SIMDE_FLOAT32_C(     4.89), SIMDE_FLOAT32_C(     1.09), SIMDE_FLOAT32_C(     0.19),
                         SIMDE_FLOAT32_C(  3452.50), SIMDE_FLOAT32_C(     5.64), SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(   109.60),
                         SIMDE_FLOAT32_C(     2.93), SIMDE_FLOAT32_C(     3.33), SIMDE_FLOAT32_C(     2.75), SIMDE_FLOAT32_C(     8.81),
                         SIMDE_FLOAT32_C(     1.04), SIMDE_FLOAT32_C(   203.74), SIMDE_FLOAT32_C(     6.92), SIMDE_FLOAT32_C(     6.89)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(     7.41), SIMDE_FLOAT32_C(     4.36), SIMDE_FLOAT32_C(    -0.82), SIMDE_FLOAT32_C(     8.01),
                         SIMDE_FLOAT32_C(     6.98), SIMDE_FLOAT32_C(     0.26), SIMDE_FLOAT32_C(     5.08), SIMDE_FLOAT32_C(     7.75),
                         SIMDE_FLOAT32_C(     4.67), SIMDE_FLOAT32_C(     7.99), SIMDE_FLOAT32_C(     4.04), SIMDE_FLOAT32_C(     4.94),
                         SIMDE_FLOAT32_C(     0.60), SIMDE_FLOAT32_C(     7.84), SIMDE_FLOAT32_C(     6.67), SIMDE_FLOAT32_C(    -0.39)),
      UINT16_C(  953),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     4.60), SIMDE_FLOAT32_C(     8.95), SIMDE_FLOAT32_C(     5.29), SIMDE_FLOAT32_C(     2.15),
                         SIMDE_FLOAT32_C(     6.20), SIMDE_FLOAT32_C(     3.53), SIMDE_FLOAT32_C(     1.98), SIMDE_FLOAT32_C(     8.23),
                         SIMDE_FLOAT32_C(     4.86), SIMDE_FLOAT32_C(     3.03), SIMDE_FLOAT32_C(     5.15), SIMDE_FLOAT32_C(     1.33),
                         SIMDE_FLOAT32_C(     4.29), SIMDE_FLOAT32_C(     3.12), SIMDE_FLOAT32_C(     4.20), SIMDE_FLOAT32_C(     5.01)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     7.41), SIMDE_FLOAT32_C(     4.36), SIMDE_FLOAT32_C(    -0.82), SIMDE_FLOAT32_C(     8.01),
                         SIMDE_FLOAT32_C(     6.98), SIMDE_FLOAT32_C(     0.26), SIMDE_FLOAT32_C(     3.69), SIMDE_FLOAT32_C(  1875.92),
                         SIMDE_FLOAT32_C(    64.52), SIMDE_FLOAT32_C(     7.99), SIMDE_FLOAT32_C(    86.22), SIMDE_FLOAT32_C(     2.02),
                         SIMDE_FLOAT32_C(    36.49), SIMDE_FLOAT32_C(     7.84), SIMDE_FLOAT32_C(     6.67), SIMDE_FLOAT32_C(    74.96)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.16), SIMDE_FLOAT32_C(     6.32), SIMDE_FLOAT32_C(     1.79), SIMDE_FLOAT32_C(     9.02),
                         SIMDE_FLOAT32_C(     9.76), SIMDE_FLOAT32_C(     9.75), SIMDE_FLOAT32_C(     9.04), SIMDE_FLOAT32_C(     0.01),
                         SIMDE_FLOAT32_C(     3.35), SIMDE_FLOAT32_C(    -0.63), SIMDE_FLOAT32_C(     0.49), SIMDE_FLOAT32_C(     2.19),
                         SIMDE_FLOAT32_C(     5.05), SIMDE_FLOAT32_C(     5.07), SIMDE_FLOAT32_C(     6.92), SIMDE_FLOAT32_C(     3.38)),
      UINT16_C(12713),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    -0.13), SIMDE_FLOAT32_C(     4.42), SIMDE_FLOAT32_C(     9.04), SIMDE_FLOAT32_C(     8.86),
                         SIMDE_FLOAT32_C(     0.45), SIMDE_FLOAT32_C(     2.79), SIMDE_FLOAT32_C(     8.51), SIMDE_FLOAT32_C(     2.57),
                         SIMDE_FLOAT32_C(     4.83), SIMDE_FLOAT32_C(     5.10), SIMDE_FLOAT32_C(     8.44), SIMDE_FLOAT32_C(     3.12),
                         SIMDE_FLOAT32_C(     9.69), SIMDE_FLOAT32_C(     6.49), SIMDE_FLOAT32_C(     4.43), SIMDE_FLOAT32_C(     9.19)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.16), SIMDE_FLOAT32_C(     6.32), SIMDE_FLOAT32_C(  4216.89), SIMDE_FLOAT32_C(  3522.24),
                         SIMDE_FLOAT32_C(     9.76), SIMDE_FLOAT32_C(     9.75), SIMDE_FLOAT32_C(     9.04), SIMDE_FLOAT32_C(     6.57),
                         SIMDE_FLOAT32_C(    62.61), SIMDE_FLOAT32_C(    -0.63), SIMDE_FLOAT32_C(  2314.28), SIMDE_FLOAT32_C(     2.19),
                         SIMDE_FLOAT32_C(  8077.62), SIMDE_FLOAT32_C(     5.07), SIMDE_FLOAT32_C(     6.92), SIMDE_FLOAT32_C(  4899.32)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512 r = simde_mm512_mask_cosh_ps(test_vec[i].src, test_vec[i].k, test_vec[i].a);
    simde_assert_m512_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_cosh_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512d a;
    simde__m512d r;
  } test_vec[8] = {
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(    3.49), SIMDE_FLOAT64_C(    4.01),
                         SIMDE_FLOAT64_C(    1.11), SIMDE_FLOAT64_C(    2.10),
                         SIMDE_FLOAT64_C(    1.44), SIMDE_FLOAT64_C(    2.12),
                         SIMDE_FLOAT64_C(   -0.26), SIMDE_FLOAT64_C(    3.04)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   16.41), SIMDE_FLOAT64_C(   27.58),
                         SIMDE_FLOAT64_C(    1.68), SIMDE_FLOAT64_C(    4.14),
                         SIMDE_FLOAT64_C(    2.23), SIMDE_FLOAT64_C(    4.23),
                         SIMDE_FLOAT64_C(    1.03), SIMDE_FLOAT64_C(   10.48)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(   -0.03), SIMDE_FLOAT64_C(   -0.06),
                         SIMDE_FLOAT64_C(    2.25), SIMDE_FLOAT64_C(    3.71),
                         SIMDE_FLOAT64_C(    4.48), SIMDE_FLOAT64_C(    3.27),
                         SIMDE_FLOAT64_C(    1.19), SIMDE_FLOAT64_C(    3.40)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    1.00), SIMDE_FLOAT64_C(    1.00),
                         SIMDE_FLOAT64_C(    4.80), SIMDE_FLOAT64_C(   20.44),
                         SIMDE_FLOAT64_C(   44.12), SIMDE_FLOAT64_C(   13.17),
                         SIMDE_FLOAT64_C(    1.80), SIMDE_FLOAT64_C(   15.00)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.67), SIMDE_FLOAT64_C(    2.09),
                         SIMDE_FLOAT64_C(    0.85), SIMDE_FLOAT64_C(   -0.77),
                         SIMDE_FLOAT64_C(    1.08), SIMDE_FLOAT64_C(   -0.58),
                         SIMDE_FLOAT64_C(    0.75), SIMDE_FLOAT64_C(    4.09)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    1.23), SIMDE_FLOAT64_C(    4.10),
                         SIMDE_FLOAT64_C(    1.38), SIMDE_FLOAT64_C(    1.31),
                         SIMDE_FLOAT64_C(    1.64), SIMDE_FLOAT64_C(    1.17),
                         SIMDE_FLOAT64_C(    1.29), SIMDE_FLOAT64_C(   29.88)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(    2.53), SIMDE_FLOAT64_C(    0.65),
                         SIMDE_FLOAT64_C(    2.70), SIMDE_FLOAT64_C(    4.06),
                         SIMDE_FLOAT64_C(    2.78), SIMDE_FLOAT64_C(    1.36),
                         SIMDE_FLOAT64_C(   -0.93), SIMDE_FLOAT64_C(    0.02)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    6.32), SIMDE_FLOAT64_C(    1.22),
                         SIMDE_FLOAT64_C(    7.47), SIMDE_FLOAT64_C(   29.00),
                         SIMDE_FLOAT64_C(    8.09), SIMDE_FLOAT64_C(    2.08),
                         SIMDE_FLOAT64_C(    1.46), SIMDE_FLOAT64_C(    1.00)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(   -0.31), SIMDE_FLOAT64_C(    3.33),
                         SIMDE_FLOAT64_C(    0.25), SIMDE_FLOAT64_C(    3.14),
                         SIMDE_FLOAT64_C(   -0.31), SIMDE_FLOAT64_C(    4.98),
                         SIMDE_FLOAT64_C(    2.08), SIMDE_FLOAT64_C(    4.52)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    1.05), SIMDE_FLOAT64_C(   13.99),
                         SIMDE_FLOAT64_C(    1.03), SIMDE_FLOAT64_C(   11.57),
                         SIMDE_FLOAT64_C(    1.05), SIMDE_FLOAT64_C(   72.74),
                         SIMDE_FLOAT64_C(    4.06), SIMDE_FLOAT64_C(   45.92)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.84), SIMDE_FLOAT64_C(    3.19),
                         SIMDE_FLOAT64_C(    3.97), SIMDE_FLOAT64_C(    3.02),
                         SIMDE_FLOAT64_C(    3.60), SIMDE_FLOAT64_C(    1.21),
                         SIMDE_FLOAT64_C(    4.34), SIMDE_FLOAT64_C(    1.91)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    1.37), SIMDE_FLOAT64_C(   12.16),
                         SIMDE_FLOAT64_C(   26.50), SIMDE_FLOAT64_C(   10.27),
                         SIMDE_FLOAT64_C(   18.31), SIMDE_FLOAT64_C(    1.83),
                         SIMDE_FLOAT64_C(   38.36), SIMDE_FLOAT64_C(    3.45)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(    1.39), SIMDE_FLOAT64_C(    1.76),
                         SIMDE_FLOAT64_C(    3.01), SIMDE_FLOAT64_C(   -0.83),
                         SIMDE_FLOAT64_C(   -0.24), SIMDE_FLOAT64_C(   -0.30),
                         SIMDE_FLOAT64_C(    0.34), SIMDE_FLOAT64_C(    3.20)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    2.13), SIMDE_FLOAT64_C(    2.99),
                         SIMDE_FLOAT64_C(   10.17), SIMDE_FLOAT64_C(    1.36),
                         SIMDE_FLOAT64_C(    1.03), SIMDE_FLOAT64_C(    1.05),
                         SIMDE_FLOAT64_C(    1.06), SIMDE_FLOAT64_C(   12.29)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(    3.41), SIMDE_FLOAT64_C(    4.04),
                         SIMDE_FLOAT64_C(    1.55), SIMDE_FLOAT64_C(    4.46),
                         SIMDE_FLOAT64_C(    4.73), SIMDE_FLOAT64_C(    3.80),
                         SIMDE_FLOAT64_C(    4.37), SIMDE_FLOAT64_C(    2.76)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   15.15), SIMDE_FLOAT64_C(   28.42),
                         SIMDE_FLOAT64_C(    2.46), SIMDE_FLOAT64_C(   43.25),
                         SIMDE_FLOAT64_C(   56.65), SIMDE_FLOAT64_C(   22.36),
                         SIMDE_FLOAT64_C(   39.53), SIMDE_FLOAT64_C(    7.93)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512d r = simde_mm512_cosh_pd(test_vec[i].a);
    simde_assert_m512d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_mask_cosh_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512d src;
    simde__mmask8 k;
    simde__m512d a;
    simde__m512d r;
  } test_vec[8] = {
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(   -0.06), SIMDE_FLOAT64_C(    3.71),
                         SIMDE_FLOAT64_C(    3.27), SIMDE_FLOAT64_C(    3.40),
                         SIMDE_FLOAT64_C(    4.01), SIMDE_FLOAT64_C(    2.10),
                         SIMDE_FLOAT64_C(    2.12), SIMDE_FLOAT64_C(    3.04)),
      UINT8_C(139),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   -0.03), SIMDE_FLOAT64_C(    2.25),
                         SIMDE_FLOAT64_C(    4.48), SIMDE_FLOAT64_C(    1.19),
                         SIMDE_FLOAT64_C(    3.49), SIMDE_FLOAT64_C(    1.11),
                         SIMDE_FLOAT64_C(    1.44), SIMDE_FLOAT64_C(   -0.26)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    1.00), SIMDE_FLOAT64_C(    3.71),
                         SIMDE_FLOAT64_C(    3.27), SIMDE_FLOAT64_C(    3.40),
                         SIMDE_FLOAT64_C(   16.41), SIMDE_FLOAT64_C(    2.10),
                         SIMDE_FLOAT64_C(    2.23), SIMDE_FLOAT64_C(    1.03)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(    2.53), SIMDE_FLOAT64_C(    2.70),
                         SIMDE_FLOAT64_C(    2.78), SIMDE_FLOAT64_C(   -0.93),
                         SIMDE_FLOAT64_C(    0.67), SIMDE_FLOAT64_C(    0.85),
                         SIMDE_FLOAT64_C(    1.08), SIMDE_FLOAT64_C(    0.75)),
      UINT8_C(229),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    4.52), SIMDE_FLOAT64_C(    0.65),
                         SIMDE_FLOAT64_C(    4.06), SIMDE_FLOAT64_C(    1.36),
                         SIMDE_FLOAT64_C(    0.02), SIMDE_FLOAT64_C(    2.09),
                         SIMDE_FLOAT64_C(   -0.77), SIMDE_FLOAT64_C(   -0.58)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   45.92), SIMDE_FLOAT64_C(    1.22),
                         SIMDE_FLOAT64_C(   29.00), SIMDE_FLOAT64_C(   -0.93),
                         SIMDE_FLOAT64_C(    0.67), SIMDE_FLOAT64_C(    4.10),
                         SIMDE_FLOAT64_C(    1.08), SIMDE_FLOAT64_C(    1.17)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(    3.20), SIMDE_FLOAT64_C(    3.19),
                         SIMDE_FLOAT64_C(    3.02), SIMDE_FLOAT64_C(    1.21),
                         SIMDE_FLOAT64_C(    1.91), SIMDE_FLOAT64_C(    3.33),
                         SIMDE_FLOAT64_C(    3.14), SIMDE_FLOAT64_C(    4.98)),
      UINT8_C(253),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.34), SIMDE_FLOAT64_C(    0.84),
                         SIMDE_FLOAT64_C(    3.97), SIMDE_FLOAT64_C(    3.60),
                         SIMDE_FLOAT64_C(    4.34), SIMDE_FLOAT64_C(   -0.31),
                         SIMDE_FLOAT64_C(    0.25), SIMDE_FLOAT64_C(   -0.31)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    1.06), SIMDE_FLOAT64_C(    1.37),
                         SIMDE_FLOAT64_C(   26.50), SIMDE_FLOAT64_C(   18.31),
                         SIMDE_FLOAT64_C(   38.36), SIMDE_FLOAT64_C(    1.05),
                         SIMDE_FLOAT64_C(    3.14), SIMDE_FLOAT64_C(    1.05)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(    2.36), SIMDE_FLOAT64_C(    3.41),
                         SIMDE_FLOAT64_C(    1.55), SIMDE_FLOAT64_C(    4.73),
                         SIMDE_FLOAT64_C(    4.37), SIMDE_FLOAT64_C(    1.39),
                         SIMDE_FLOAT64_C(    3.01), SIMDE_FLOAT64_C(   -0.24)),
      UINT8_C( 93),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    3.63), SIMDE_FLOAT64_C(    1.49),
                         SIMDE_FLOAT64_C(    4.04), SIMDE_FLOAT64_C(    4.46),
                         SIMDE_FLOAT64_C(    3.80), SIMDE_FLOAT64_C(    2.76),
                         SIMDE_FLOAT64_C(    1.76), SIMDE_FLOAT64_C(   -0.83)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    2.36), SIMDE_FLOAT64_C(    2.33),
                         SIMDE_FLOAT64_C(    1.55), SIMDE_FLOAT64_C(   43.25),
                         SIMDE_FLOAT64_C(   22.36), SIMDE_FLOAT64_C(    7.93),
                         SIMDE_FLOAT64_C(    3.01), SIMDE_FLOAT64_C(    1.36)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(    2.30), SIMDE_FLOAT64_C(   -0.21),
                         SIMDE_FLOAT64_C(    4.28), SIMDE_FLOAT64_C(    3.03),
                         SIMDE_FLOAT64_C(   -0.39), SIMDE_FLOAT64_C(    0.42),
                         SIMDE_FLOAT64_C(   -0.47), SIMDE_FLOAT64_C(    3.97)),
      UINT8_C(145),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    2.99), SIMDE_FLOAT64_C(    3.39),
                         SIMDE_FLOAT64_C(    1.46), SIMDE_FLOAT64_C(    2.97),
                         SIMDE_FLOAT64_C(   -0.62), SIMDE_FLOAT64_C(    1.01),
                         SIMDE_FLOAT64_C(    1.42), SIMDE_FLOAT64_C(    3.68)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    9.97), SIMDE_FLOAT64_C(   -0.21),
                         SIMDE_FLOAT64_C(    4.28), SIMDE_FLOAT64_C(    9.77),
                         SIMDE_FLOAT64_C(   -0.39), SIMDE_FLOAT64_C(    0.42),
                         SIMDE_FLOAT64_C(   -0.47), SIMDE_FLOAT64_C(   19.84)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(   -0.27), SIMDE_FLOAT64_C(    2.08),
                         SIMDE_FLOAT64_C(    4.07), SIMDE_FLOAT64_C(    1.94),
                         SIMDE_FLOAT64_C(    0.65), SIMDE_FLOAT64_C(    3.52),
                         SIMDE_FLOAT64_C(    4.49), SIMDE_FLOAT64_C(    4.93)),
      UINT8_C( 75),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    4.93), SIMDE_FLOAT64_C(    3.27),
                         SIMDE_FLOAT64_C(    1.71), SIMDE_FLOAT64_C(    4.52),
                         SIMDE_FLOAT64_C(    0.23), SIMDE_FLOAT64_C(    4.19),
                         SIMDE_FLOAT64_C(    3.87), SIMDE_FLOAT64_C(    2.42)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   -0.27), SIMDE_FLOAT64_C(   13.17),
                         SIMDE_FLOAT64_C(    4.07), SIMDE_FLOAT64_C(    1.94),
                         SIMDE_FLOAT64_C(    1.03), SIMDE_FLOAT64_C(    3.52),
                         SIMDE_FLOAT64_C(   23.98), SIMDE_FLOAT64_C(    5.67)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(    3.18), SIMDE_FLOAT64_C(    1.09),
                         SIMDE_FLOAT64_C(   -0.09), SIMDE_FLOAT64_C(    4.47),
                         SIMDE_FLOAT64_C(   -0.99), SIMDE_FLOAT64_C(    4.77),
                         SIMDE_FLOAT64_C(   -0.30), SIMDE_FLOAT64_C(    1.80)),
      UINT8_C( 93),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    3.53), SIMDE_FLOAT64_C(    2.04),
                         SIMDE_FLOAT64_C(    4.75), SIMDE_FLOAT64_C(   -0.31),
                         SIMDE_FLOAT64_C(    0.28), SIMDE_FLOAT64_C(    0.99),
                         SIMDE_FLOAT64_C(    2.88), SIMDE_FLOAT64_C(    0.27)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    3.18), SIMDE_FLOAT64_C(    3.91),
                         SIMDE_FLOAT64_C(   -0.09), SIMDE_FLOAT64_C(    1.05),
                         SIMDE_FLOAT64_C(    1.04), SIMDE_FLOAT64_C(    1.53),
                         SIMDE_FLOAT64_C(   -0.30), SIMDE_FLOAT64_C(    1.04)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(    3.43), SIMDE_FLOAT64_C(    4.81),
                         SIMDE_FLOAT64_C(    0.95), SIMDE_FLOAT64_C(    0.69),
                         SIMDE_FLOAT64_C(   -0.26), SIMDE_FLOAT64_C(    4.80),
                         SIMDE_FLOAT64_C(    1.02), SIMDE_FLOAT64_C(    1.45)),
      UINT8_C(213),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   -0.33), SIMDE_FLOAT64_C(    3.32),
                         SIMDE_FLOAT64_C(    4.69), SIMDE_FLOAT64_C(    1.41),
                         SIMDE_FLOAT64_C(    0.92), SIMDE_FLOAT64_C(    1.90),
                         SIMDE_FLOAT64_C(    2.02), SIMDE_FLOAT64_C(    1.62)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    1.05), SIMDE_FLOAT64_C(   13.85),
                         SIMDE_FLOAT64_C(    0.95), SIMDE_FLOAT64_C(    2.17),
                         SIMDE_FLOAT64_C(   -0.26), SIMDE_FLOAT64_C(    3.42),
                         SIMDE_FLOAT64_C(    1.02), SIMDE_FLOAT64_C(    2.63)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512d r = simde_mm512_mask_cosh_pd(test_vec[i].src, test_vec[i].k, test_vec[i].a);
    simde_assert_m512d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_div_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi8(INT8_C(  80), INT8_C(  26), INT8_C( -96), INT8_C(  63),
                        INT8_C(  84), INT8_C(   0), INT8_C(  86), INT8_C( -92),
                        INT8_C(  19), INT8_C(  73), INT8_C(  49), INT8_C(  84),
                        INT8_C(  93), INT8_C( -26), INT8_C(  48), INT8_C( -85)),
      simde_mm_set_epi8(INT8_C(   4), INT8_C(   4), INT8_C(   3), INT8_C(  27),
                        INT8_C(  44), INT8_C(  48), INT8_C(   3), INT8_C(  53),
                        INT8_C(  11), INT8_C(   6), INT8_C(   2), INT8_C(  14),
                        INT8_C(  89), INT8_C(  10), INT8_C(   3), INT8_C(   1)),
      simde_mm_set_epi8(INT8_C(  20), INT8_C(   6), INT8_C( -32), INT8_C(   2),
                        INT8_C(   1), INT8_C(   0), INT8_C(  28), INT8_C(  -1),
                        INT8_C(   1), INT8_C(  12), INT8_C(  24), INT8_C(   6),
                        INT8_C(   1), INT8_C(  -2), INT8_C(  16), INT8_C( -85)) },
    { simde_mm_set_epi8(INT8_C( -53), INT8_C(-123), INT8_C(  83), INT8_C(  82),
                        INT8_C( -17), INT8_C(  32), INT8_C( -32), INT8_C(  68),
                        INT8_C( -20), INT8_C(   5), INT8_C(  -1), INT8_C( -23),
                        INT8_C( 118), INT8_C(-101), INT8_C(  53), INT8_C(   4)),
      simde_mm_set_epi8(INT8_C(   9), INT8_C(   1), INT8_C( -68), INT8_C(   1),
                        INT8_C(   1), INT8_C(   1), INT8_C(  22), INT8_C(  17),
                        INT8_C(   4), INT8_C(   8), INT8_C(   6), INT8_C(  10),
                        INT8_C(  55), INT8_C(   3), INT8_C(  14), INT8_C(  14)),
      simde_mm_set_epi8(INT8_C(  -5), INT8_C(-123), INT8_C(  -1), INT8_C(  82),
                        INT8_C( -17), INT8_C(  32), INT8_C(  -1), INT8_C(   4),
                        INT8_C(  -5), INT8_C(   0), INT8_C(   0), INT8_C(  -2),
                        INT8_C(   2), INT8_C( -33), INT8_C(   3), INT8_C(   0)) },
    { simde_mm_set_epi8(INT8_C( 122), INT8_C( 103), INT8_C(  28), INT8_C(-102),
                        INT8_C( -41), INT8_C(-105), INT8_C( -14), INT8_C(-120),
                        INT8_C( -71), INT8_C(  84), INT8_C(  90), INT8_C(   8),
                        INT8_C(  84), INT8_C( 120), INT8_C( -59), INT8_C(   9)),
      simde_mm_set_epi8(INT8_C(  59), INT8_C( -21), INT8_C(  22), INT8_C(  53),
                        INT8_C(  22), INT8_C(   3), INT8_C(   5), INT8_C(   6),
                        INT8_C(   2), INT8_C(  21), INT8_C(   3), INT8_C(   3),
                        INT8_C(   2), INT8_C(  10), INT8_C(  10), INT8_C(   3)),
      simde_mm_set_epi8(INT8_C(   2), INT8_C(  -4), INT8_C(   1), INT8_C(  -1),
                        INT8_C(  -1), INT8_C( -35), INT8_C(  -2), INT8_C( -20),
                        INT8_C( -35), INT8_C(   4), INT8_C(  30), INT8_C(   2),
                        INT8_C(  42), INT8_C(  12), INT8_C(  -5), INT8_C(   3)) },
    { simde_mm_set_epi8(INT8_C( 121), INT8_C( -15), INT8_C(-123), INT8_C(  80),
                        INT8_C(  43), INT8_C(  58), INT8_C( 119), INT8_C( -49),
                        INT8_C( 107), INT8_C( -94), INT8_C(  51), INT8_C(-118),
                        INT8_C(  68), INT8_C( 112), INT8_C( -56), INT8_C(-103)),
      simde_mm_set_epi8(INT8_C(  44), INT8_C(  13), INT8_C(  14), INT8_C(   8),
                        INT8_C( -24), INT8_C(  77), INT8_C( 118), INT8_C(  21),
                        INT8_C(   1), INT8_C( -34), INT8_C(   2), INT8_C(  29),
                        INT8_C(  14), INT8_C(  53), INT8_C(   1), INT8_C(  54)),
      simde_mm_set_epi8(INT8_C(   2), INT8_C(  -1), INT8_C(  -8), INT8_C(  10),
                        INT8_C(  -1), INT8_C(   0), INT8_C(   1), INT8_C(  -2),
                        INT8_C( 107), INT8_C(   2), INT8_C(  25), INT8_C(  -4),
                        INT8_C(   4), INT8_C(   2), INT8_C( -56), INT8_C(  -1)) },
    { simde_mm_set_epi8(INT8_C( -42), INT8_C(  14), INT8_C(-113), INT8_C(  62),
                        INT8_C( -34), INT8_C( -16), INT8_C(-103), INT8_C(-122),
                        INT8_C(-128), INT8_C( -77), INT8_C( -15), INT8_C( -38),
                        INT8_C(  87), INT8_C( -72), INT8_C(  57), INT8_C( -40)),
      simde_mm_set_epi8(INT8_C(  30), INT8_C( 124), INT8_C( -94), INT8_C(   4),
                        INT8_C(  46), INT8_C(  11), INT8_C(   3), INT8_C( -54),
                        INT8_C(  11), INT8_C(   8), INT8_C(-114), INT8_C(   3),
                        INT8_C(   6), INT8_C(   1), INT8_C(-121), INT8_C(   4)),
      simde_mm_set_epi8(INT8_C(  -1), INT8_C(   0), INT8_C(   1), INT8_C(  15),
                        INT8_C(   0), INT8_C(  -1), INT8_C( -34), INT8_C(   2),
                        INT8_C( -11), INT8_C(  -9), INT8_C(   0), INT8_C( -12),
                        INT8_C(  14), INT8_C( -72), INT8_C(   0), INT8_C( -10)) },
    { simde_mm_set_epi8(INT8_C( -13), INT8_C( -82), INT8_C(  64), INT8_C( -67),
                        INT8_C(-120), INT8_C(  26), INT8_C(-105), INT8_C(  40),
                        INT8_C(  59), INT8_C( -83), INT8_C(  64), INT8_C( -39),
                        INT8_C(  99), INT8_C( -73), INT8_C( -97), INT8_C(  -1)),
      simde_mm_set_epi8(INT8_C( -27), INT8_C( 114), INT8_C(-109), INT8_C(   8),
                        INT8_C(  12), INT8_C(   4), INT8_C(   2), INT8_C(   2),
                        INT8_C(   3), INT8_C(  11), INT8_C(   3), INT8_C(  11),
                        INT8_C(  82), INT8_C(  14), INT8_C( 120), INT8_C(-107)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -8),
                        INT8_C( -10), INT8_C(   6), INT8_C( -52), INT8_C(  20),
                        INT8_C(  19), INT8_C(  -7), INT8_C(  21), INT8_C(  -3),
                        INT8_C(   1), INT8_C(  -5), INT8_C(   0), INT8_C(   0)) },
    { simde_mm_set_epi8(INT8_C( -57), INT8_C(  53), INT8_C( 114), INT8_C( -35),
                        INT8_C( -22), INT8_C( -59), INT8_C(  52), INT8_C( 113),
                        INT8_C(  25), INT8_C(  16), INT8_C(  -8), INT8_C( -67),
                        INT8_C(   7), INT8_C( -33), INT8_C(  51), INT8_C( 118)),
      simde_mm_set_epi8(INT8_C(  14), INT8_C(  15), INT8_C(  24), INT8_C(  83),
                        INT8_C(   4), INT8_C(  45), INT8_C(   4), INT8_C(  34),
                        INT8_C(   9), INT8_C(  19), INT8_C(   4), INT8_C(  11),
                        INT8_C(   8), INT8_C(  14), INT8_C( 102), INT8_C( -88)),
      simde_mm_set_epi8(INT8_C(  -4), INT8_C(   3), INT8_C(   4), INT8_C(   0),
                        INT8_C(  -5), INT8_C(  -1), INT8_C(  13), INT8_C(   3),
                        INT8_C(   2), INT8_C(   0), INT8_C(  -2), INT8_C(  -6),
                        INT8_C(   0), INT8_C(  -2), INT8_C(   0), INT8_C(  -1)) },
    { simde_mm_set_epi8(INT8_C( -69), INT8_C(  57), INT8_C(   3), INT8_C( 127),
                        INT8_C( -28), INT8_C( -47), INT8_C(-127), INT8_C( -14),
                        INT8_C( -28), INT8_C(  68), INT8_C( -27), INT8_C( -44),
                        INT8_C( -16), INT8_C(   1), INT8_C( -44), INT8_C( 112)),
      simde_mm_set_epi8(INT8_C(  57), INT8_C(   1), INT8_C( -43), INT8_C( 103),
                        INT8_C(   4), INT8_C(   1), INT8_C(   2), INT8_C(  96),
                        INT8_C(   9), INT8_C(  57), INT8_C(  54), INT8_C( 105),
                        INT8_C(   1), INT8_C(  31), INT8_C( -85), INT8_C( 104)),
      simde_mm_set_epi8(INT8_C(  -1), INT8_C(  57), INT8_C(   0), INT8_C(   1),
                        INT8_C(  -7), INT8_C( -47), INT8_C( -63), INT8_C(   0),
                        INT8_C(  -3), INT8_C(   1), INT8_C(   0), INT8_C(   0),
                        INT8_C( -16), INT8_C(   0), INT8_C(   0), INT8_C(   1)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_div_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_div_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(INT16_C(  7569), INT16_C(-21774), INT16_C(  5125), INT16_C( 21356),
                         INT16_C(  9222), INT16_C(  7511), INT16_C(-21561), INT16_C( 29102)),
      simde_mm_set_epi16(INT16_C(  6450), INT16_C(    -2), INT16_C(   190), INT16_C(   -44),
                         INT16_C(    -3), INT16_C(    -9), INT16_C(  -911), INT16_C(     3)),
      simde_mm_set_epi16(INT16_C(     1), INT16_C( 10887), INT16_C(    26), INT16_C(  -485),
                         INT16_C( -3074), INT16_C(  -834), INT16_C(    23), INT16_C(  9700)) },
    { simde_mm_set_epi16(INT16_C( 14790), INT16_C(-17845), INT16_C( 12471), INT16_C( 16666),
                         INT16_C( -4541), INT16_C( 18926), INT16_C(  4112), INT16_C( 26905)),
      simde_mm_set_epi16(INT16_C(    -1), INT16_C(    -8), INT16_C(    15), INT16_C(   -16),
                         INT16_C(    -1), INT16_C(   -28), INT16_C( -3387), INT16_C(    -5)),
      simde_mm_set_epi16(INT16_C(-14790), INT16_C(  2230), INT16_C(   831), INT16_C( -1041),
                         INT16_C(  4541), INT16_C(  -675), INT16_C(    -1), INT16_C( -5381)) },
    { simde_mm_set_epi16(INT16_C( 24700), INT16_C( 18820), INT16_C( -6493), INT16_C(-11852),
                         INT16_C(  7293), INT16_C( 18330), INT16_C(-13423), INT16_C( 30834)),
      simde_mm_set_epi16(INT16_C(  9411), INT16_C(    -2), INT16_C(    -2), INT16_C(   -10),
                         INT16_C(   942), INT16_C(  5062), INT16_C(  3712), INT16_C(-24297)),
      simde_mm_set_epi16(INT16_C(     2), INT16_C( -9410), INT16_C(  3246), INT16_C(  1185),
                         INT16_C(     7), INT16_C(     3), INT16_C(    -3), INT16_C(    -1)) },
    { simde_mm_set_epi16(INT16_C( -8188), INT16_C( -5752), INT16_C( -6400), INT16_C(-18754),
                         INT16_C( 26203), INT16_C( 11990), INT16_C( 27655), INT16_C( 30479)),
      simde_mm_set_epi16(INT16_C( -2891), INT16_C(    -9), INT16_C(     1), INT16_C(    24),
                         INT16_C(  1410), INT16_C( -7348), INT16_C(    56), INT16_C(    -8)),
      simde_mm_set_epi16(INT16_C(     2), INT16_C(   639), INT16_C( -6400), INT16_C(  -781),
                         INT16_C(    18), INT16_C(    -1), INT16_C(   493), INT16_C( -3809)) },
    { simde_mm_set_epi16(INT16_C( 27464), INT16_C( 30742), INT16_C(-17463), INT16_C(  5584),
                         INT16_C( 16882), INT16_C(-13221), INT16_C(-30009), INT16_C( 27529)),
      simde_mm_set_epi16(INT16_C(    92), INT16_C(  -245), INT16_C(    87), INT16_C(  2027),
                         INT16_C(  -218), INT16_C(   181), INT16_C(     1), INT16_C(  -448)),
      simde_mm_set_epi16(INT16_C(   298), INT16_C(  -125), INT16_C(  -200), INT16_C(     2),
                         INT16_C(   -77), INT16_C(   -73), INT16_C(-30009), INT16_C(   -61)) },
    { simde_mm_set_epi16(INT16_C(-28312), INT16_C( -6464), INT16_C(  7438), INT16_C(-24771),
                         INT16_C( 27969), INT16_C( 18884), INT16_C( 17235), INT16_C( 31019)),
      simde_mm_set_epi16(INT16_C( -3989), INT16_C(     8), INT16_C(    -1), INT16_C(   -27),
                         INT16_C(    53), INT16_C(   -58), INT16_C(  2274), INT16_C(    -9)),
      simde_mm_set_epi16(INT16_C(     7), INT16_C(  -808), INT16_C( -7438), INT16_C(   917),
                         INT16_C(   527), INT16_C(  -325), INT16_C(     7), INT16_C( -3446)) },
    { simde_mm_set_epi16(INT16_C(-31090), INT16_C( 20346), INT16_C( 14276), INT16_C(-27653),
                         INT16_C( 19203), INT16_C(-24798), INT16_C(-17826), INT16_C( 16379)),
      simde_mm_set_epi16(INT16_C(     3), INT16_C(     8), INT16_C(   -60), INT16_C(    14),
                         INT16_C(  -435), INT16_C(    -1), INT16_C(  -395), INT16_C( -1532)),
      simde_mm_set_epi16(INT16_C(-10363), INT16_C(  2543), INT16_C(  -237), INT16_C( -1975),
                         INT16_C(   -44), INT16_C( 24798), INT16_C(    45), INT16_C(   -10)) },
    { simde_mm_set_epi16(INT16_C( -4012), INT16_C( 17981), INT16_C( 26341), INT16_C(-11451),
                         INT16_C(-22746), INT16_C(-13246), INT16_C( -6273), INT16_C( 15936)),
      simde_mm_set_epi16(INT16_C(    -5), INT16_C(   325), INT16_C(    10), INT16_C( -2018),
                         INT16_C(-26192), INT16_C(   -15), INT16_C(   -29), INT16_C(  2009)),
      simde_mm_set_epi16(INT16_C(   802), INT16_C(    55), INT16_C(  2634), INT16_C(     5),
                         INT16_C(     0), INT16_C(   883), INT16_C(   216), INT16_C(     7)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_div_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_div_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C(-2101284579), INT32_C( 1788896628), INT32_C(  742774378), INT32_C( -512831871)),
      simde_mm_set_epi32(INT32_C(       -173), INT32_C(  -20613654), INT32_C(      28772), INT32_C(        118)),
      simde_mm_set_epi32(INT32_C(   12146153), INT32_C(        -86), INT32_C(      25815), INT32_C(   -4346032)) },
    { simde_mm_set_epi32(INT32_C(  505370509), INT32_C( -307733024), INT32_C( -192358019), INT32_C( -299231491)),
      simde_mm_set_epi32(INT32_C(      34268), INT32_C(         -6), INT32_C(       6850), INT32_C(    1214711)),
      simde_mm_set_epi32(INT32_C(      14747), INT32_C(   51288837), INT32_C(     -28081), INT32_C(       -246)) },
    { simde_mm_set_epi32(INT32_C(-1154189768), INT32_C(   94538029), INT32_C(  423884488), INT32_C( 1619435962)),
      simde_mm_set_epi32(INT32_C(       -565), INT32_C(    -128659), INT32_C(        -59), INT32_C( -208397178)),
      simde_mm_set_epi32(INT32_C(    2042813), INT32_C(       -734), INT32_C(   -7184482), INT32_C(         -7)) },
    { simde_mm_set_epi32(INT32_C(-1938127942), INT32_C( -553846699), INT32_C(  685427224), INT32_C(  -86375451)),
      simde_mm_set_epi32(INT32_C( 1223981911), INT32_C(    -108113), INT32_C(          3), INT32_C(      -3698)),
      simde_mm_set_epi32(INT32_C(         -1), INT32_C(       5122), INT32_C(  228475741), INT32_C(      23357)) },
    { simde_mm_set_epi32(INT32_C(-1690889220), INT32_C( -667367235), INT32_C( 1220206139), INT32_C(-1217543723)),
      simde_mm_set_epi32(INT32_C(        299), INT32_C(       7724), INT32_C(         -1), INT32_C(  173051558)),
      simde_mm_set_epi32(INT32_C(   -5655147), INT32_C(     -86401), INT32_C(-1220206139), INT32_C(         -7)) },
    { simde_mm_set_epi32(INT32_C(   93323521), INT32_C( 1996592708), INT32_C( 2087305602), INT32_C(   27568495)),
      simde_mm_set_epi32(INT32_C(         -2), INT32_C(   15626723), INT32_C(       1507), INT32_C(       5412)),
      simde_mm_set_epi32(INT32_C(  -46661760), INT32_C(        127), INT32_C(    1385073), INT32_C(       5093)) },
    { simde_mm_set_epi32(INT32_C( 1825211631), INT32_C( 1750705004), INT32_C( 1935103134), INT32_C(-1042289581)),
      simde_mm_set_epi32(INT32_C(     -20153), INT32_C( -109992928), INT32_C(         -4), INT32_C(          3)),
      simde_mm_set_epi32(INT32_C(     -90567), INT32_C(        -15), INT32_C( -483775783), INT32_C( -347429860)) },
    { simde_mm_set_epi32(INT32_C( -836927167), INT32_C(-2031963629), INT32_C( 1244477192), INT32_C(  662038781)),
      simde_mm_set_epi32(INT32_C(       -226), INT32_C(        320), INT32_C(   17085036), INT32_C(       -883)),
      simde_mm_set_epi32(INT32_C(    3703217), INT32_C(   -6349886), INT32_C(         72), INT32_C(    -749760)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_div_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_div_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi64x(INT64_C(-8762915026342605517), INT64_C( 6327019035084041530)),
      simde_mm_set_epi64x(INT64_C( 1040172869250133860), INT64_C(         -3393154419)),
      simde_mm_set_epi64x(INT64_C(                  -8), INT64_C(         -1864642233)) },
    { simde_mm_set_epi64x(INT64_C( 7086115847005357544), INT64_C( 7169462887889416879)),
      simde_mm_set_epi64x(INT64_C(             -402272), INT64_C(            -6362438)),
      simde_mm_set_epi64x(INT64_C(     -17615235082246), INT64_C(      -1126842082844)) },
    { simde_mm_set_epi64x(INT64_C( 3227829673356714047), INT64_C( 5122063021698718134)),
      simde_mm_set_epi64x(INT64_C(              290796), INT64_C(             -647054)),
      simde_mm_set_epi64x(INT64_C(      11099979619240), INT64_C(      -7915974588981)) },
    { simde_mm_set_epi64x(INT64_C( -712959233727550094), INT64_C( 8175697730423622547)),
      simde_mm_set_epi64x(INT64_C(          -114108996), INT64_C(           727492806)),
      simde_mm_set_epi64x(INT64_C(          6248054568), INT64_C(         11238183612)) },
    { simde_mm_set_epi64x(INT64_C( 7475816922473172733), INT64_C(-1631503293395556188)),
      simde_mm_set_epi64x(INT64_C(                   5), INT64_C(        -24770378177)),
      simde_mm_set_epi64x(INT64_C( 1495163384494634546), INT64_C(            65865094)) },
    { simde_mm_set_epi64x(INT64_C(-7220293124938945390), INT64_C( 5345879758546587877)),
      simde_mm_set_epi64x(INT64_C(                -716), INT64_C(             1692902)),
      simde_mm_set_epi64x(INT64_C(   10084208275054393), INT64_C(       3157819979270)) },
    { simde_mm_set_epi64x(INT64_C(-2100788141468237692), INT64_C( 1869244361192362281)),
      simde_mm_set_epi64x(INT64_C(                  -1), INT64_C(         27867346395)),
      simde_mm_set_epi64x(INT64_C( 2100788141468237692), INT64_C(            67076510)) },
    { simde_mm_set_epi64x(INT64_C(-4218200756000910912), INT64_C( 8429274423139369867)),
      simde_mm_set_epi64x(INT64_C(                  25), INT64_C(        -63869567732)),
      simde_mm_set_epi64x(INT64_C( -168728030240036436), INT64_C(          -131976381)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_div_epi64(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_div_epu8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu8(UINT8_C( 15), UINT8_C( 75), UINT8_C(224), UINT8_C(156),
                          UINT8_C(  1), UINT8_C( 34), UINT8_C( 35), UINT8_C(127),
                          UINT8_C(127), UINT8_C(120), UINT8_C(177), UINT8_C( 31),
                          UINT8_C(136), UINT8_C(180), UINT8_C(141), UINT8_C(206)),
      simde_x_mm_set_epu8(UINT8_C( 45), UINT8_C(  8), UINT8_C(  9), UINT8_C( 13),
                          UINT8_C(246), UINT8_C(  1), UINT8_C( 15), UINT8_C(  2),
                          UINT8_C(152), UINT8_C( 45), UINT8_C( 56), UINT8_C( 26),
                          UINT8_C(  1), UINT8_C(  1), UINT8_C( 16), UINT8_C( 15)),
      simde_x_mm_set_epu8(UINT8_C(  0), UINT8_C(  9), UINT8_C( 24), UINT8_C( 12),
                          UINT8_C(  0), UINT8_C( 34), UINT8_C(  2), UINT8_C( 63),
                          UINT8_C(  0), UINT8_C(  2), UINT8_C(  3), UINT8_C(  1),
                          UINT8_C(136), UINT8_C(180), UINT8_C(  8), UINT8_C( 13)) },
    { simde_x_mm_set_epu8(UINT8_C( 75), UINT8_C(233), UINT8_C(186), UINT8_C(216),
                          UINT8_C(224), UINT8_C( 45), UINT8_C( 40), UINT8_C(134),
                          UINT8_C(  1), UINT8_C( 47), UINT8_C( 23), UINT8_C(119),
                          UINT8_C(229), UINT8_C(107), UINT8_C(175), UINT8_C( 79)),
      simde_x_mm_set_epu8(UINT8_C(  9), UINT8_C( 12), UINT8_C( 46), UINT8_C( 39),
                          UINT8_C( 11), UINT8_C( 15), UINT8_C( 32), UINT8_C( 13),
                          UINT8_C( 21), UINT8_C(239), UINT8_C(  5), UINT8_C(  2),
                          UINT8_C(  1), UINT8_C( 26), UINT8_C(182), UINT8_C( 29)),
      simde_x_mm_set_epu8(UINT8_C(  8), UINT8_C( 19), UINT8_C(  4), UINT8_C(  5),
                          UINT8_C( 20), UINT8_C(  3), UINT8_C(  1), UINT8_C( 10),
                          UINT8_C(  0), UINT8_C(  0), UINT8_C(  4), UINT8_C( 59),
                          UINT8_C(229), UINT8_C(  4), UINT8_C(  0), UINT8_C(  2)) },
    { simde_x_mm_set_epu8(UINT8_C( 75), UINT8_C(109), UINT8_C( 28), UINT8_C(204),
                          UINT8_C( 53), UINT8_C(255), UINT8_C(143), UINT8_C(254),
                          UINT8_C( 82), UINT8_C(109), UINT8_C(205), UINT8_C( 21),
                          UINT8_C( 16), UINT8_C( 18), UINT8_C(221), UINT8_C(119)),
      simde_x_mm_set_epu8(UINT8_C(210), UINT8_C(108), UINT8_C( 89), UINT8_C( 21),
                          UINT8_C(154), UINT8_C( 52), UINT8_C( 17), UINT8_C(  8),
                          UINT8_C( 90), UINT8_C(  6), UINT8_C(  1), UINT8_C(  5),
                          UINT8_C(  1), UINT8_C(201), UINT8_C( 23), UINT8_C(  2)),
      simde_x_mm_set_epu8(UINT8_C(  0), UINT8_C(  1), UINT8_C(  0), UINT8_C(  9),
                          UINT8_C(  0), UINT8_C(  4), UINT8_C(  8), UINT8_C( 31),
                          UINT8_C(  0), UINT8_C( 18), UINT8_C(205), UINT8_C(  4),
                          UINT8_C( 16), UINT8_C(  0), UINT8_C(  9), UINT8_C( 59)) },
    { simde_x_mm_set_epu8(UINT8_C( 23), UINT8_C(229), UINT8_C(200), UINT8_C( 62),
                          UINT8_C(169), UINT8_C(116), UINT8_C(131), UINT8_C(205),
                          UINT8_C(117), UINT8_C( 49), UINT8_C(130), UINT8_C( 21),
                          UINT8_C( 91), UINT8_C(138), UINT8_C(101), UINT8_C(205)),
      simde_x_mm_set_epu8(UINT8_C( 43), UINT8_C( 65), UINT8_C( 28), UINT8_C( 61),
                          UINT8_C( 12), UINT8_C(  4), UINT8_C( 37), UINT8_C(  4),
                          UINT8_C(237), UINT8_C( 25), UINT8_C( 38), UINT8_C( 15),
                          UINT8_C(  9), UINT8_C(  6), UINT8_C(140), UINT8_C( 10)),
      simde_x_mm_set_epu8(UINT8_C(  0), UINT8_C(  3), UINT8_C(  7), UINT8_C(  1),
                          UINT8_C( 14), UINT8_C( 29), UINT8_C(  3), UINT8_C( 51),
                          UINT8_C(  0), UINT8_C(  1), UINT8_C(  3), UINT8_C(  1),
                          UINT8_C( 10), UINT8_C( 23), UINT8_C(  0), UINT8_C( 20)) },
    { simde_x_mm_set_epu8(UINT8_C(140), UINT8_C(170), UINT8_C(150), UINT8_C(208),
                          UINT8_C( 64), UINT8_C(  6), UINT8_C(116), UINT8_C(102),
                          UINT8_C(200), UINT8_C(110), UINT8_C(136), UINT8_C(125),
                          UINT8_C(201), UINT8_C( 22), UINT8_C(166), UINT8_C(235)),
      simde_x_mm_set_epu8(UINT8_C(  1), UINT8_C(  7), UINT8_C( 23), UINT8_C(  2),
                          UINT8_C( 12), UINT8_C(103), UINT8_C( 24), UINT8_C( 18),
                          UINT8_C(234), UINT8_C( 11), UINT8_C(  6), UINT8_C(  2),
                          UINT8_C(  5), UINT8_C( 34), UINT8_C( 60), UINT8_C( 13)),
      simde_x_mm_set_epu8(UINT8_C(140), UINT8_C( 24), UINT8_C(  6), UINT8_C(104),
                          UINT8_C(  5), UINT8_C(  0), UINT8_C(  4), UINT8_C(  5),
                          UINT8_C(  0), UINT8_C( 10), UINT8_C( 22), UINT8_C( 62),
                          UINT8_C( 40), UINT8_C(  0), UINT8_C(  2), UINT8_C( 18)) },
    { simde_x_mm_set_epu8(UINT8_C(143), UINT8_C( 77), UINT8_C(114), UINT8_C( 66),
                          UINT8_C( 82), UINT8_C(133), UINT8_C( 93), UINT8_C(122),
                          UINT8_C(225), UINT8_C(230), UINT8_C(202), UINT8_C(147),
                          UINT8_C(170), UINT8_C(252), UINT8_C(163), UINT8_C(161)),
      simde_x_mm_set_epu8(UINT8_C(  5), UINT8_C(  8), UINT8_C( 15), UINT8_C( 99),
                          UINT8_C( 10), UINT8_C(  4), UINT8_C(  1), UINT8_C(  1),
                          UINT8_C( 15), UINT8_C( 21), UINT8_C(  3), UINT8_C(  1),
                          UINT8_C(  2), UINT8_C( 18), UINT8_C( 18), UINT8_C(  2)),
      simde_x_mm_set_epu8(UINT8_C( 28), UINT8_C(  9), UINT8_C(  7), UINT8_C(  0),
                          UINT8_C(  8), UINT8_C( 33), UINT8_C( 93), UINT8_C(122),
                          UINT8_C( 15), UINT8_C( 10), UINT8_C( 67), UINT8_C(147),
                          UINT8_C( 85), UINT8_C( 14), UINT8_C(  9), UINT8_C( 80)) },
    { simde_x_mm_set_epu8(UINT8_C(125), UINT8_C(134), UINT8_C(114), UINT8_C( 16),
                          UINT8_C(101), UINT8_C( 75), UINT8_C( 71), UINT8_C(136),
                          UINT8_C(137), UINT8_C(104), UINT8_C(249), UINT8_C(115),
                          UINT8_C(110), UINT8_C(132), UINT8_C(229), UINT8_C( 48)),
      simde_x_mm_set_epu8(UINT8_C( 69), UINT8_C( 11), UINT8_C(  3), UINT8_C(  2),
                          UINT8_C(  2), UINT8_C( 21), UINT8_C(  3), UINT8_C(  1),
                          UINT8_C(  5), UINT8_C(  1), UINT8_C(  3), UINT8_C(  2),
                          UINT8_C(  1), UINT8_C(163), UINT8_C(  1), UINT8_C(  2)),
      simde_x_mm_set_epu8(UINT8_C(  1), UINT8_C( 12), UINT8_C( 38), UINT8_C(  8),
                          UINT8_C( 50), UINT8_C(  3), UINT8_C( 23), UINT8_C(136),
                          UINT8_C( 27), UINT8_C(104), UINT8_C( 83), UINT8_C( 57),
                          UINT8_C(110), UINT8_C(  0), UINT8_C(229), UINT8_C( 24)) },
    { simde_x_mm_set_epu8(UINT8_C( 72), UINT8_C(139), UINT8_C(120), UINT8_C(127),
                          UINT8_C(102), UINT8_C(165), UINT8_C( 82), UINT8_C( 63),
                          UINT8_C(192), UINT8_C( 18), UINT8_C(103), UINT8_C(151),
                          UINT8_C( 81), UINT8_C(222), UINT8_C(212), UINT8_C(  1)),
      simde_x_mm_set_epu8(UINT8_C(  7), UINT8_C( 26), UINT8_C( 32), UINT8_C(  1),
                          UINT8_C(  1), UINT8_C(  1), UINT8_C(  3), UINT8_C(  2),
                          UINT8_C( 65), UINT8_C( 24), UINT8_C(  1), UINT8_C( 97),
                          UINT8_C( 14), UINT8_C(  8), UINT8_C( 89), UINT8_C( 11)),
      simde_x_mm_set_epu8(UINT8_C( 10), UINT8_C(  5), UINT8_C(  3), UINT8_C(127),
                          UINT8_C(102), UINT8_C(165), UINT8_C( 27), UINT8_C( 31),
                          UINT8_C(  2), UINT8_C(  0), UINT8_C(103), UINT8_C(  1),
                          UINT8_C(  5), UINT8_C( 27), UINT8_C(  2), UINT8_C(  0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_div_epu8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_div_epu16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu16(UINT16_C(27566), UINT16_C(40504), UINT16_C( 4629), UINT16_C(53715),
                           UINT16_C( 9716), UINT16_C( 9411), UINT16_C(47476), UINT16_C(41385)),
      simde_x_mm_set_epu16(UINT16_C(   13), UINT16_C( 6506), UINT16_C( 2031), UINT16_C( 2041),
                           UINT16_C(   41), UINT16_C( 3089), UINT16_C( 4707), UINT16_C(    3)),
      simde_x_mm_set_epu16(UINT16_C( 2120), UINT16_C(    6), UINT16_C(    2), UINT16_C(   26),
                           UINT16_C(  236), UINT16_C(    3), UINT16_C(   10), UINT16_C(13795)) },
    { simde_x_mm_set_epu16(UINT16_C( 9353), UINT16_C(  761), UINT16_C( 3256), UINT16_C(15648),
                           UINT16_C(54529), UINT16_C(37909), UINT16_C( 6524), UINT16_C(24806)),
      simde_x_mm_set_epu16(UINT16_C(17088), UINT16_C( 3660), UINT16_C(    3), UINT16_C(    9),
                           UINT16_C(  186), UINT16_C(    2), UINT16_C(    7), UINT16_C( 1856)),
      simde_x_mm_set_epu16(UINT16_C(    0), UINT16_C(    0), UINT16_C( 1085), UINT16_C( 1738),
                           UINT16_C(  293), UINT16_C(18954), UINT16_C(  932), UINT16_C(   13)) },
    { simde_x_mm_set_epu16(UINT16_C(19795), UINT16_C(45332), UINT16_C(60579), UINT16_C(32327),
                           UINT16_C(25905), UINT16_C(63671), UINT16_C(  930), UINT16_C(32017)),
      simde_x_mm_set_epu16(UINT16_C(    8), UINT16_C(30488), UINT16_C(   26), UINT16_C( 3397),
                           UINT16_C( 1518), UINT16_C(    2), UINT16_C(   20), UINT16_C(    6)),
      simde_x_mm_set_epu16(UINT16_C( 2474), UINT16_C(    1), UINT16_C( 2329), UINT16_C(    9),
                           UINT16_C(   17), UINT16_C(31835), UINT16_C(   46), UINT16_C( 5336)) },
    { simde_x_mm_set_epu16(UINT16_C(29801), UINT16_C(62435), UINT16_C(31106), UINT16_C(58247),
                           UINT16_C(47275), UINT16_C(34875), UINT16_C(63847), UINT16_C( 8602)),
      simde_x_mm_set_epu16(UINT16_C(    5), UINT16_C(    1), UINT16_C(  842), UINT16_C( 1634),
                           UINT16_C(   11), UINT16_C(   25), UINT16_C( 3640), UINT16_C(  932)),
      simde_x_mm_set_epu16(UINT16_C( 5960), UINT16_C(62435), UINT16_C(   36), UINT16_C(   35),
                           UINT16_C( 4297), UINT16_C( 1395), UINT16_C(   17), UINT16_C(    9)) },
    { simde_x_mm_set_epu16(UINT16_C(41564), UINT16_C(16940), UINT16_C(39647), UINT16_C(59460),
                           UINT16_C(17425), UINT16_C(59711), UINT16_C(30880), UINT16_C(42139)),
      simde_x_mm_set_epu16(UINT16_C(25139), UINT16_C( 3416), UINT16_C(   43), UINT16_C(    6),
                           UINT16_C(    4), UINT16_C( 1256), UINT16_C(   60), UINT16_C(  129)),
      simde_x_mm_set_epu16(UINT16_C(    1), UINT16_C(    4), UINT16_C(  922), UINT16_C( 9910),
                           UINT16_C( 4356), UINT16_C(   47), UINT16_C(  514), UINT16_C(  326)) },
    { simde_x_mm_set_epu16(UINT16_C(39593), UINT16_C(41522), UINT16_C(58894), UINT16_C( 6383),
                           UINT16_C(39956), UINT16_C( 2820), UINT16_C(20260), UINT16_C(57360)),
      simde_x_mm_set_epu16(UINT16_C(    1), UINT16_C(10468), UINT16_C(    2), UINT16_C(   79),
                           UINT16_C(    5), UINT16_C( 1166), UINT16_C(    2), UINT16_C(    3)),
      simde_x_mm_set_epu16(UINT16_C(39593), UINT16_C(    3), UINT16_C(29447), UINT16_C(   80),
                           UINT16_C( 7991), UINT16_C(    2), UINT16_C(10130), UINT16_C(19120)) },
    { simde_x_mm_set_epu16(UINT16_C(58633), UINT16_C(30014), UINT16_C(57061), UINT16_C(60439),
                           UINT16_C(22536), UINT16_C(20868), UINT16_C(20870), UINT16_C(13916)),
      simde_x_mm_set_epu16(UINT16_C(   15), UINT16_C(  490), UINT16_C( 2338), UINT16_C(   64),
                           UINT16_C(  876), UINT16_C(  706), UINT16_C(   65), UINT16_C(  320)),
      simde_x_mm_set_epu16(UINT16_C( 3908), UINT16_C(   61), UINT16_C(   24), UINT16_C(  944),
                           UINT16_C(   25), UINT16_C(   29), UINT16_C(  321), UINT16_C(   43)) },
    { simde_x_mm_set_epu16(UINT16_C( 6697), UINT16_C(21906), UINT16_C(59582), UINT16_C(44845),
                           UINT16_C(35883), UINT16_C(64682), UINT16_C(55100), UINT16_C(57711)),
      simde_x_mm_set_epu16(UINT16_C( 7058), UINT16_C(   10), UINT16_C(60566), UINT16_C(    1),
                           UINT16_C(    1), UINT16_C(  872), UINT16_C(  109), UINT16_C(    1)),
      simde_x_mm_set_epu16(UINT16_C(    0), UINT16_C( 2190), UINT16_C(    0), UINT16_C(44845),
                           UINT16_C(35883), UINT16_C(   74), UINT16_C(  505), UINT16_C(57711)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_div_epu16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_div_epu32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu32(UINT32_C(3152261024), UINT32_C(2598586578), UINT32_C(1610828679), UINT32_C(3536337768)),
      simde_x_mm_set_epu32(UINT32_C(     14157), UINT32_C(       947), UINT32_C(1043337665), UINT32_C(     97937)),
      simde_x_mm_set_epu32(UINT32_C(    222664), UINT32_C(   2744019), UINT32_C(         1), UINT32_C(     36108)) },
    { simde_x_mm_set_epu32(UINT32_C(  75140339), UINT32_C(1941562012), UINT32_C( 857740081), UINT32_C(1336535286)),
      simde_x_mm_set_epu32(UINT32_C(        22), UINT32_C(      1682), UINT32_C(        11), UINT32_C(         2)),
      simde_x_mm_set_epu32(UINT32_C(   3415469), UINT32_C(   1154317), UINT32_C(  77976371), UINT32_C( 668267643)) },
    { simde_x_mm_set_epu32(UINT32_C( 948661264), UINT32_C(1195769225), UINT32_C( 694120276), UINT32_C(3517239447)),
      simde_x_mm_set_epu32(UINT32_C(      3949), UINT32_C(       275), UINT32_C(  12430067), UINT32_C(     15794)),
      simde_x_mm_set_epu32(UINT32_C(    240228), UINT32_C(   4348251), UINT32_C(        55), UINT32_C(    222694)) },
    { simde_x_mm_set_epu32(UINT32_C(3023938951), UINT32_C(4109050401), UINT32_C( 287757059), UINT32_C(2648669825)),
      simde_x_mm_set_epu32(UINT32_C(     57756), UINT32_C(        40), UINT32_C(1080216164), UINT32_C(    173312)),
      simde_x_mm_set_epu32(UINT32_C(     52357), UINT32_C( 102726260), UINT32_C(         0), UINT32_C(     15282)) },
    { simde_x_mm_set_epu32(UINT32_C( 864299658), UINT32_C(2427378437), UINT32_C( 823539242), UINT32_C(1758563044)),
      simde_x_mm_set_epu32(UINT32_C(       225), UINT32_C(        75), UINT32_C(     11529), UINT32_C( 119418298)),
      simde_x_mm_set_epu32(UINT32_C(   3841331), UINT32_C(  32365045), UINT32_C(     71431), UINT32_C(        14)) },
    { simde_x_mm_set_epu32(UINT32_C(2662820398), UINT32_C(1208068616), UINT32_C(2158211537), UINT32_C(3417661837)),
      simde_x_mm_set_epu32(UINT32_C(      2367), UINT32_C(    126619), UINT32_C(     55203), UINT32_C(       155)),
      simde_x_mm_set_epu32(UINT32_C(   1124976), UINT32_C(      9540), UINT32_C(     39095), UINT32_C(  22049431)) },
    { simde_x_mm_set_epu32(UINT32_C(1097247740), UINT32_C(3448507951), UINT32_C(4106436665), UINT32_C(3017338787)),
      simde_x_mm_set_epu32(UINT32_C(  61963115), UINT32_C( 238397327), UINT32_C(    245318), UINT32_C(   3312135)),
      simde_x_mm_set_epu32(UINT32_C(        17), UINT32_C(        14), UINT32_C(     16739), UINT32_C(       910)) },
    { simde_x_mm_set_epu32(UINT32_C(3006363325), UINT32_C(2983927188), UINT32_C(2177891039), UINT32_C(1117727917)),
      simde_x_mm_set_epu32(UINT32_C(        24), UINT32_C(        12), UINT32_C(1067413818), UINT32_C(       206)),
      simde_x_mm_set_epu32(UINT32_C( 125265138), UINT32_C( 248660599), UINT32_C(         2), UINT32_C(   5425863)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_div_epu32(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_div_epu64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu64x(UINT64_C(14823946846053138543), UINT64_C( 2773213006356142856)),
      simde_x_mm_set_epu64x(UINT64_C(   22806630538915743), UINT64_C(                1295)),
      simde_x_mm_set_epu64x(UINT64_C(                 649), UINT64_C(    2141477224985438)) },
    { simde_x_mm_set_epu64x(UINT64_C(16338394746286416599), UINT64_C( 4395568244008230294)),
      simde_x_mm_set_epu64x(UINT64_C(                1610), UINT64_C(         68247035008)),
      simde_x_mm_set_epu64x(UINT64_C(   10148071270985351), UINT64_C(            64406728)) },
    { simde_x_mm_set_epu64x(UINT64_C( 6431957656146818365), UINT64_C(14710883493083458909)),
      simde_x_mm_set_epu64x(UINT64_C(       2399266305377), UINT64_C(   16092627197291141)),
      simde_x_mm_set_epu64x(UINT64_C(             2680801), UINT64_C(                 914)) },
    { simde_x_mm_set_epu64x(UINT64_C( 7920700281052633117), UINT64_C(15482760419196872328)),
      simde_x_mm_set_epu64x(UINT64_C(         45928957131), UINT64_C(              837231)),
      simde_x_mm_set_epu64x(UINT64_C(           172455478), UINT64_C(      18492817895176)) },
    { simde_x_mm_set_epu64x(UINT64_C(  230158309193392347), UINT64_C(18390356791266391163)),
      simde_x_mm_set_epu64x(UINT64_C(                2253), UINT64_C(       1691141090999)),
      simde_x_mm_set_epu64x(UINT64_C(     102156373365908), UINT64_C(            10874525)) },
    { simde_x_mm_set_epu64x(UINT64_C(12307531484633875995), UINT64_C(16695234188854570094)),
      simde_x_mm_set_epu64x(UINT64_C(           131150029), UINT64_C(  516657134296053652)),
      simde_x_mm_set_epu64x(UINT64_C(         93843147260), UINT64_C(                  32)) },
    { simde_x_mm_set_epu64x(UINT64_C(11764896934406933200), UINT64_C(18439918542668248477)),
      simde_x_mm_set_epu64x(UINT64_C(        306481550847), UINT64_C(  776223621938168297)),
      simde_x_mm_set_epu64x(UINT64_C(            38386966), UINT64_C(                  23)) },
    { simde_x_mm_set_epu64x(UINT64_C(15338454595408931369), UINT64_C(14530768559531423502)),
      simde_x_mm_set_epu64x(UINT64_C(                3408), UINT64_C(                   2)),
      simde_x_mm_set_epu64x(UINT64_C(    4500720245131728), UINT64_C( 7265384279765711751)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_div_epu64(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_div_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi8(INT8_C( -27), INT8_C(  46), INT8_C(-122), INT8_C(  87),
                           INT8_C(  34), INT8_C( -53), INT8_C(  64), INT8_C( -70),
                           INT8_C(  25), INT8_C( -17), INT8_C(  56), INT8_C(   3),
                           INT8_C( -75), INT8_C( -17), INT8_C( -12), INT8_C(  60),
                           INT8_C( 100), INT8_C(  -7), INT8_C(-102), INT8_C(  -6),
                           INT8_C( -10), INT8_C(-111), INT8_C( 106), INT8_C( -43),
                           INT8_C( -28), INT8_C( -46), INT8_C(  42), INT8_C( -58),
                           INT8_C(  85), INT8_C( -33), INT8_C(-106), INT8_C(-106)),
      simde_mm256_set_epi8(INT8_C(   1), INT8_C(   4), INT8_C( -31), INT8_C(   6),
                           INT8_C(  13), INT8_C(  15), INT8_C(  20), INT8_C(   3),
                           INT8_C( -77), INT8_C(  32), INT8_C(   5), INT8_C(  55),
                           INT8_C(   5), INT8_C(   1), INT8_C(  16), INT8_C(  49),
                           INT8_C(  43), INT8_C(  83), INT8_C(   5), INT8_C(  16),
                           INT8_C(  34), INT8_C(  20), INT8_C(   2), INT8_C(  13),
                           INT8_C(   8), INT8_C(   2), INT8_C(  90), INT8_C(   2),
                           INT8_C(  23), INT8_C(  12), INT8_C(   2), INT8_C(   5)),
      simde_mm256_set_epi8(INT8_C( -27), INT8_C(  11), INT8_C(   3), INT8_C(  14),
                           INT8_C(   2), INT8_C(  -3), INT8_C(   3), INT8_C( -23),
                           INT8_C(   0), INT8_C(   0), INT8_C(  11), INT8_C(   0),
                           INT8_C( -15), INT8_C( -17), INT8_C(   0), INT8_C(   1),
                           INT8_C(   2), INT8_C(   0), INT8_C( -20), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -5), INT8_C(  53), INT8_C(  -3),
                           INT8_C(  -3), INT8_C( -23), INT8_C(   0), INT8_C( -29),
                           INT8_C(   3), INT8_C(  -2), INT8_C( -53), INT8_C( -21)) },
    { simde_mm256_set_epi8(INT8_C(  64), INT8_C(-114), INT8_C(  66), INT8_C( -73),
                           INT8_C( -80), INT8_C(  97), INT8_C( 103), INT8_C( -46),
                           INT8_C( -83), INT8_C( 104), INT8_C(  22), INT8_C( -39),
                           INT8_C( 114), INT8_C( -82), INT8_C(  83), INT8_C( 122),
                           INT8_C(   1), INT8_C(  51), INT8_C(  75), INT8_C(-100),
                           INT8_C(  17), INT8_C(  37), INT8_C(  53), INT8_C( -57),
                           INT8_C( 121), INT8_C( -35), INT8_C( 108), INT8_C( -68),
                           INT8_C(  25), INT8_C( -78), INT8_C( -54), INT8_C(-104)),
      simde_mm256_set_epi8(INT8_C(  91), INT8_C(  10), INT8_C( -96), INT8_C(  14),
                           INT8_C(  21), INT8_C(  23), INT8_C(   1), INT8_C(   8),
                           INT8_C(   9), INT8_C(   2), INT8_C(   8), INT8_C(  30),
                           INT8_C(   1), INT8_C( -75), INT8_C(  15), INT8_C(   1),
                           INT8_C(  27), INT8_C(   5), INT8_C( 104), INT8_C(  48),
                           INT8_C(  11), INT8_C(   4), INT8_C(  31), INT8_C(   3),
                           INT8_C(  20), INT8_C( 118), INT8_C(   1), INT8_C(  18),
                           INT8_C(   1), INT8_C(  22), INT8_C(  20), INT8_C(  33)),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C( -11), INT8_C(   0), INT8_C(  -5),
                           INT8_C(  -3), INT8_C(   4), INT8_C( 103), INT8_C(  -5),
                           INT8_C(  -9), INT8_C(  52), INT8_C(   2), INT8_C(  -1),
                           INT8_C( 114), INT8_C(   1), INT8_C(   5), INT8_C( 122),
                           INT8_C(   0), INT8_C(  10), INT8_C(   0), INT8_C(  -2),
                           INT8_C(   1), INT8_C(   9), INT8_C(   1), INT8_C( -19),
                           INT8_C(   6), INT8_C(   0), INT8_C( 108), INT8_C(  -3),
                           INT8_C(  25), INT8_C(  -3), INT8_C(  -2), INT8_C(  -3)) },
    { simde_mm256_set_epi8(INT8_C( 123), INT8_C(  92), INT8_C( -58), INT8_C(  47),
                           INT8_C(  51), INT8_C(  47), INT8_C(  69), INT8_C(  12),
                           INT8_C(  68), INT8_C( -99), INT8_C(  76), INT8_C(  32),
                           INT8_C(  85), INT8_C( -81), INT8_C(  -3), INT8_C(  -4),
                           INT8_C( -35), INT8_C( -48), INT8_C(  17), INT8_C( -73),
                           INT8_C( 109), INT8_C(  88), INT8_C( -56), INT8_C( -99),
                           INT8_C(-114), INT8_C( 127), INT8_C(  26), INT8_C( -29),
                           INT8_C( -48), INT8_C( -28), INT8_C(  93), INT8_C( -85)),
      simde_mm256_set_epi8(INT8_C(  86), INT8_C(  12), INT8_C(  90), INT8_C(  46),
                           INT8_C(  10), INT8_C(  18), INT8_C(   1), INT8_C(  58),
                           INT8_C( -94), INT8_C(   4), INT8_C(   2), INT8_C(   1),
                           INT8_C(  20), INT8_C(  20), INT8_C(   1), INT8_C(  10),
                           INT8_C(   4), INT8_C(  13), INT8_C(   1), INT8_C(   1),
                           INT8_C(   1), INT8_C(   3), INT8_C(  16), INT8_C(   4),
                           INT8_C(   4), INT8_C(   2), INT8_C(   8), INT8_C( -96),
                           INT8_C(   1), INT8_C(   5), INT8_C( -98), INT8_C(  11)),
      simde_mm256_set_epi8(INT8_C(   1), INT8_C(   7), INT8_C(   0), INT8_C(   1),
                           INT8_C(   5), INT8_C(   2), INT8_C(  69), INT8_C(   0),
                           INT8_C(   0), INT8_C( -24), INT8_C(  38), INT8_C(  32),
                           INT8_C(   4), INT8_C(  -4), INT8_C(  -3), INT8_C(   0),
                           INT8_C(  -8), INT8_C(  -3), INT8_C(  17), INT8_C( -73),
                           INT8_C( 109), INT8_C(  29), INT8_C(  -3), INT8_C( -24),
                           INT8_C( -28), INT8_C(  63), INT8_C(   3), INT8_C(   0),
                           INT8_C( -48), INT8_C(  -5), INT8_C(   0), INT8_C(  -7)) },
    { simde_mm256_set_epi8(INT8_C( -83), INT8_C(   8), INT8_C(  39), INT8_C(  32),
                           INT8_C( -68), INT8_C(   0), INT8_C(  93), INT8_C(   7),
                           INT8_C( -26), INT8_C( -37), INT8_C(   3), INT8_C( -23),
                           INT8_C(  38), INT8_C( -61), INT8_C(  87), INT8_C(  32),
                           INT8_C(  65), INT8_C(  24), INT8_C( -17), INT8_C( -19),
                           INT8_C( 113), INT8_C( -25), INT8_C(  58), INT8_C(   4),
                           INT8_C(-127), INT8_C(  41), INT8_C( -74), INT8_C( 113),
                           INT8_C(  49), INT8_C( -39), INT8_C( -48), INT8_C( 114)),
      simde_mm256_set_epi8(INT8_C(-102), INT8_C(   1), INT8_C(  22), INT8_C(   1),
                           INT8_C(  15), INT8_C(   2), INT8_C(  19), INT8_C(  69),
                           INT8_C(   1), INT8_C(  49), INT8_C(  66), INT8_C(   2),
                           INT8_C(   1), INT8_C(   2), INT8_C(  10), INT8_C(   8),
                           INT8_C(   1), INT8_C(   1), INT8_C(   4), INT8_C(  66),
                           INT8_C(  11), INT8_C(  22), INT8_C(-126), INT8_C(  49),
                           INT8_C(   1), INT8_C(  38), INT8_C(   1), INT8_C(   3),
                           INT8_C(   7), INT8_C(   3), INT8_C(  21), INT8_C(  21)),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(   8), INT8_C(   1), INT8_C(  32),
                           INT8_C(  -4), INT8_C(   0), INT8_C(   4), INT8_C(   0),
                           INT8_C( -26), INT8_C(   0), INT8_C(   0), INT8_C( -11),
                           INT8_C(  38), INT8_C( -30), INT8_C(   8), INT8_C(   4),
                           INT8_C(  65), INT8_C(  24), INT8_C(  -4), INT8_C(   0),
                           INT8_C(  10), INT8_C(  -1), INT8_C(   0), INT8_C(   0),
                           INT8_C(-127), INT8_C(   1), INT8_C( -74), INT8_C(  37),
                           INT8_C(   7), INT8_C( -13), INT8_C(  -2), INT8_C(   5)) },
    { simde_mm256_set_epi8(INT8_C(  66), INT8_C( 127), INT8_C(  41), INT8_C(-124),
                           INT8_C( -90), INT8_C(  28), INT8_C(-118), INT8_C(  18),
                           INT8_C(  79), INT8_C(  17), INT8_C( 126), INT8_C( -43),
                           INT8_C( -78), INT8_C(  78), INT8_C(  76), INT8_C(  46),
                           INT8_C(  60), INT8_C(-126), INT8_C( -41), INT8_C( -77),
                           INT8_C( -62), INT8_C(-116), INT8_C(-115), INT8_C(  55),
                           INT8_C(  19), INT8_C( 104), INT8_C(-104), INT8_C( -29),
                           INT8_C(  54), INT8_C(-118), INT8_C( -40), INT8_C( -58)),
      simde_mm256_set_epi8(INT8_C(   3), INT8_C(  53), INT8_C(  28), INT8_C( -96),
                           INT8_C(   1), INT8_C(  91), INT8_C(   7), INT8_C(   1),
                           INT8_C(  29), INT8_C(  30), INT8_C(   1), INT8_C(  10),
                           INT8_C(   1), INT8_C(  36), INT8_C(   7), INT8_C(   1),
                           INT8_C(-101), INT8_C(   5), INT8_C(  13), INT8_C(   5),
                           INT8_C(  85), INT8_C(  11), INT8_C(  34), INT8_C(  48),
                           INT8_C(  17), INT8_C(  42), INT8_C(   3), INT8_C(  87),
                           INT8_C(   1), INT8_C(   2), INT8_C(  74), INT8_C(   8)),
      simde_mm256_set_epi8(INT8_C(  22), INT8_C(   2), INT8_C(   1), INT8_C(   1),
                           INT8_C( -90), INT8_C(   0), INT8_C( -16), INT8_C(  18),
                           INT8_C(   2), INT8_C(   0), INT8_C( 126), INT8_C(  -4),
                           INT8_C( -78), INT8_C(   2), INT8_C(  10), INT8_C(  46),
                           INT8_C(   0), INT8_C( -25), INT8_C(  -3), INT8_C( -15),
                           INT8_C(   0), INT8_C( -10), INT8_C(  -3), INT8_C(   1),
                           INT8_C(   1), INT8_C(   2), INT8_C( -34), INT8_C(   0),
                           INT8_C(  54), INT8_C( -59), INT8_C(   0), INT8_C(  -7)) },
    { simde_mm256_set_epi8(INT8_C(  79), INT8_C( -60), INT8_C( 106), INT8_C( -93),
                           INT8_C(-111), INT8_C( 118), INT8_C( -87), INT8_C( -78),
                           INT8_C( -28), INT8_C( 107), INT8_C( -12), INT8_C( -54),
                           INT8_C( 101), INT8_C( -62), INT8_C(   4), INT8_C( -51),
                           INT8_C( -90), INT8_C(-114), INT8_C(  14), INT8_C( 124),
                           INT8_C( -67), INT8_C(  47), INT8_C(  41), INT8_C(  37),
                           INT8_C( 126), INT8_C( -20), INT8_C( 119), INT8_C( 105),
                           INT8_C( -17), INT8_C(  95), INT8_C( -41), INT8_C(  19)),
      simde_mm256_set_epi8(INT8_C( -34), INT8_C(   4), INT8_C(  32), INT8_C(   1),
                           INT8_C(   4), INT8_C(  10), INT8_C(   7), INT8_C(   5),
                           INT8_C( 120), INT8_C(   1), INT8_C(   1), INT8_C(   1),
                           INT8_C(  26), INT8_C(   6), INT8_C(  44), INT8_C(   2),
                           INT8_C(  55), INT8_C(  14), INT8_C(   4), INT8_C(  41),
                           INT8_C(  41), INT8_C(   6), INT8_C(  10), INT8_C(   7),
                           INT8_C(   7), INT8_C(  21), INT8_C( 126), INT8_C(  59),
                           INT8_C(  13), INT8_C(   8), INT8_C(   2), INT8_C(   6)),
      simde_mm256_set_epi8(INT8_C(  -2), INT8_C( -15), INT8_C(   3), INT8_C( -93),
                           INT8_C( -27), INT8_C(  11), INT8_C( -12), INT8_C( -15),
                           INT8_C(   0), INT8_C( 107), INT8_C( -12), INT8_C( -54),
                           INT8_C(   3), INT8_C( -10), INT8_C(   0), INT8_C( -25),
                           INT8_C(  -1), INT8_C(  -8), INT8_C(   3), INT8_C(   3),
                           INT8_C(  -1), INT8_C(   7), INT8_C(   4), INT8_C(   5),
                           INT8_C(  18), INT8_C(   0), INT8_C(   0), INT8_C(   1),
                           INT8_C(  -1), INT8_C(  11), INT8_C( -20), INT8_C(   3)) },
    { simde_mm256_set_epi8(INT8_C( -48), INT8_C( -29), INT8_C(  23), INT8_C(  39),
                           INT8_C( 106), INT8_C( -37), INT8_C(   1), INT8_C(  62),
                           INT8_C( -21), INT8_C(  -4), INT8_C( -92), INT8_C( -12),
                           INT8_C(  78), INT8_C( -93), INT8_C(  36), INT8_C( -10),
                           INT8_C( -84), INT8_C( 102), INT8_C(   9), INT8_C(  70),
                           INT8_C( -16), INT8_C( -90), INT8_C(  82), INT8_C(-124),
                           INT8_C( -78), INT8_C(  58), INT8_C(  35), INT8_C( 108),
                           INT8_C(-105), INT8_C( -72), INT8_C( -16), INT8_C(-103)),
      simde_mm256_set_epi8(INT8_C(   2), INT8_C(   4), INT8_C(  28), INT8_C( 120),
                           INT8_C(   1), INT8_C(   5), INT8_C(   2), INT8_C(  61),
                           INT8_C(   1), INT8_C(  33), INT8_C( 110), INT8_C(   1),
                           INT8_C( 102), INT8_C(   3), INT8_C(   3), INT8_C(   1),
                           INT8_C(   1), INT8_C(  26), INT8_C(  11), INT8_C(   7),
                           INT8_C(  75), INT8_C(   3), INT8_C(   5), INT8_C(  19),
                           INT8_C(   3), INT8_C( -26), INT8_C(  56), INT8_C(   5),
                           INT8_C(   7), INT8_C(   6), INT8_C(   2), INT8_C(   5)),
      simde_mm256_set_epi8(INT8_C( -24), INT8_C(  -7), INT8_C(   0), INT8_C(   0),
                           INT8_C( 106), INT8_C(  -7), INT8_C(   0), INT8_C(   1),
                           INT8_C( -21), INT8_C(   0), INT8_C(   0), INT8_C( -12),
                           INT8_C(   0), INT8_C( -31), INT8_C(  12), INT8_C( -10),
                           INT8_C( -84), INT8_C(   3), INT8_C(   0), INT8_C(  10),
                           INT8_C(   0), INT8_C( -30), INT8_C(  16), INT8_C(  -6),
                           INT8_C( -26), INT8_C(  -2), INT8_C(   0), INT8_C(  21),
                           INT8_C( -15), INT8_C( -12), INT8_C(  -8), INT8_C( -20)) },
    { simde_mm256_set_epi8(INT8_C( 110), INT8_C(  56), INT8_C(-120), INT8_C( -32),
                           INT8_C( -22), INT8_C(  97), INT8_C( -56), INT8_C(  55),
                           INT8_C( -90), INT8_C(  33), INT8_C(  92), INT8_C(  89),
                           INT8_C(-107), INT8_C(  55), INT8_C( -50), INT8_C( -88),
                           INT8_C(  35), INT8_C(  21), INT8_C(  54), INT8_C(  26),
                           INT8_C(-122), INT8_C( 103), INT8_C(  76), INT8_C(  38),
                           INT8_C(-110), INT8_C(  11), INT8_C(  26), INT8_C( -11),
                           INT8_C(   0), INT8_C(   3), INT8_C(  30), INT8_C(  59)),
      simde_mm256_set_epi8(INT8_C( -31), INT8_C( -83), INT8_C( 101), INT8_C(  17),
                           INT8_C(   8), INT8_C(  15), INT8_C(   2), INT8_C(   7),
                           INT8_C(  37), INT8_C(  84), INT8_C( -52), INT8_C(  25),
                           INT8_C(  42), INT8_C( -27), INT8_C(   1), INT8_C(  10),
                           INT8_C(   7), INT8_C(  37), INT8_C(  54), INT8_C(  31),
                           INT8_C(  54), INT8_C(  62), INT8_C(  11), INT8_C(  54),
                           INT8_C(  43), INT8_C(   1), INT8_C(   4), INT8_C(   5),
                           INT8_C(  93), INT8_C( 124), INT8_C(   2), INT8_C(   3)),
      simde_mm256_set_epi8(INT8_C(  -3), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -2), INT8_C(   6), INT8_C( -28), INT8_C(   7),
                           INT8_C(  -2), INT8_C(   0), INT8_C(  -1), INT8_C(   3),
                           INT8_C(  -2), INT8_C(  -2), INT8_C( -50), INT8_C(  -8),
                           INT8_C(   5), INT8_C(   0), INT8_C(   1), INT8_C(   0),
                           INT8_C(  -2), INT8_C(   1), INT8_C(   6), INT8_C(   0),
                           INT8_C(  -2), INT8_C(  11), INT8_C(   6), INT8_C(  -2),
                           INT8_C(   0), INT8_C(   0), INT8_C(  15), INT8_C(  19)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_div_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_div_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi16(INT16_C(-29867), INT16_C(  9314), INT16_C(  7980), INT16_C(  8102),
                            INT16_C(-24663), INT16_C(  4367), INT16_C(-15443), INT16_C( -5657),
                            INT16_C(-20080), INT16_C(-10092), INT16_C(-31734), INT16_C(  6262),
                            INT16_C(  3510), INT16_C(-31811), INT16_C( -4053), INT16_C( -6124)),
      simde_mm256_set_epi16(INT16_C(     1), INT16_C(  1438), INT16_C(    -9), INT16_C(   435),
                            INT16_C(   -11), INT16_C(     2), INT16_C(  -496), INT16_C( 10321),
                            INT16_C( -1000), INT16_C(   -27), INT16_C(    -4), INT16_C(   453),
                            INT16_C(    -2), INT16_C( 19741), INT16_C(  -615), INT16_C( -3265)),
      simde_mm256_set_epi16(INT16_C(-29867), INT16_C(     6), INT16_C(  -886), INT16_C(    18),
                            INT16_C(  2242), INT16_C(  2183), INT16_C(    31), INT16_C(     0),
                            INT16_C(    20), INT16_C(   373), INT16_C(  7933), INT16_C(    13),
                            INT16_C( -1755), INT16_C(    -1), INT16_C(     6), INT16_C(     1)) },
    { simde_mm256_set_epi16(INT16_C( -6800), INT16_C( 13259), INT16_C( -2233), INT16_C(  1354),
                            INT16_C( -8106), INT16_C(-17039), INT16_C(  9504), INT16_C( 22255),
                            INT16_C( 12402), INT16_C( -2677), INT16_C(  4463), INT16_C( 28303),
                            INT16_C(-12322), INT16_C(-19201), INT16_C( 30668), INT16_C( 15284)),
      simde_mm256_set_epi16(INT16_C( 16270), INT16_C(-26534), INT16_C(   -13), INT16_C(   -20),
                            INT16_C(   -12), INT16_C(  -182), INT16_C(   -13), INT16_C(    -2),
                            INT16_C(   399), INT16_C(  -245), INT16_C(    -1), INT16_C(    -1),
                            INT16_C(    -3), INT16_C(    59), INT16_C(    11), INT16_C( -9799)),
      simde_mm256_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(   171), INT16_C(   -67),
                            INT16_C(   675), INT16_C(    93), INT16_C(  -731), INT16_C(-11127),
                            INT16_C(    31), INT16_C(    10), INT16_C( -4463), INT16_C(-28303),
                            INT16_C(  4107), INT16_C(  -325), INT16_C(  2788), INT16_C(    -1)) },
    { simde_mm256_set_epi16(INT16_C( 23535), INT16_C( 10930), INT16_C( 30193), INT16_C( -8194),
                            INT16_C( -8688), INT16_C(  2183), INT16_C(-14596), INT16_C(-28144),
                            INT16_C(-10670), INT16_C(  1107), INT16_C( 31427), INT16_C( -7322),
                            INT16_C( 17038), INT16_C(-32679), INT16_C( 23368), INT16_C(-24524)),
      simde_mm256_set_epi16(INT16_C(    19), INT16_C(  -388), INT16_C(    -1), INT16_C( -2261),
                            INT16_C( -7651), INT16_C(  1639), INT16_C(   -50), INT16_C( -2059),
                            INT16_C(   -25), INT16_C(   -57), INT16_C(  -952), INT16_C(    17),
                            INT16_C( -4528), INT16_C(  -764), INT16_C(  -925), INT16_C(   -20)),
      simde_mm256_set_epi16(INT16_C(  1238), INT16_C(   -28), INT16_C(-30193), INT16_C(     3),
                            INT16_C(     1), INT16_C(     1), INT16_C(   291), INT16_C(    13),
                            INT16_C(   426), INT16_C(   -19), INT16_C(   -33), INT16_C(  -430),
                            INT16_C(    -3), INT16_C(    42), INT16_C(   -25), INT16_C(  1226)) },
    { simde_mm256_set_epi16(INT16_C( 22767), INT16_C( 28543), INT16_C(-30401), INT16_C( 25623),
                            INT16_C(  2206), INT16_C(-16640), INT16_C(-13607), INT16_C(-30899),
                            INT16_C( -2384), INT16_C( -1714), INT16_C( 12691), INT16_C(  9427),
                            INT16_C( 11864), INT16_C( 29526), INT16_C(  8259), INT16_C(  6808)),
      simde_mm256_set_epi16(INT16_C( 15244), INT16_C(     1), INT16_C(    -1), INT16_C(    -3),
                            INT16_C(   -18), INT16_C(   -10), INT16_C(-15299), INT16_C(  -824),
                            INT16_C(  2005), INT16_C(   471), INT16_C(  2069), INT16_C(   204),
                            INT16_C(    25), INT16_C(   -13), INT16_C(    -3), INT16_C(    11)),
      simde_mm256_set_epi16(INT16_C(     1), INT16_C( 28543), INT16_C( 30401), INT16_C( -8541),
                            INT16_C(  -122), INT16_C(  1664), INT16_C(     0), INT16_C(    37),
                            INT16_C(    -1), INT16_C(    -3), INT16_C(     6), INT16_C(    46),
                            INT16_C(   474), INT16_C( -2271), INT16_C( -2753), INT16_C(   618)) },
    { simde_mm256_set_epi16(INT16_C(-16585), INT16_C(-25277), INT16_C( -4139), INT16_C(-27065),
                            INT16_C(-28777), INT16_C( -9487), INT16_C(-18713), INT16_C(-30387),
                            INT16_C(-14811), INT16_C( 24102), INT16_C(-10162), INT16_C(  7921),
                            INT16_C( 29417), INT16_C( 15464), INT16_C( 24785), INT16_C( -1285)),
      simde_mm256_set_epi16(INT16_C(  -121), INT16_C(   328), INT16_C(    10), INT16_C(  -385),
                            INT16_C(    -1), INT16_C(     4), INT16_C(   388), INT16_C(    -1),
                            INT16_C(     1), INT16_C(  4863), INT16_C(  -499), INT16_C(     3),
                            INT16_C(  -226), INT16_C(-15244), INT16_C(     5), INT16_C(    -5)),
      simde_mm256_set_epi16(INT16_C(   137), INT16_C(   -77), INT16_C(  -413), INT16_C(    70),
                            INT16_C( 28777), INT16_C( -2371), INT16_C(   -48), INT16_C( 30387),
                            INT16_C(-14811), INT16_C(     4), INT16_C(    20), INT16_C(  2640),
                            INT16_C(  -130), INT16_C(    -1), INT16_C(  4957), INT16_C(   257)) },
    { simde_mm256_set_epi16(INT16_C( -8831), INT16_C(-12421), INT16_C( 28092), INT16_C(-15215),
                            INT16_C(  5495), INT16_C( 15560), INT16_C(  8747), INT16_C( 22186),
                            INT16_C(-22634), INT16_C(-23262), INT16_C(   360), INT16_C(-18340),
                            INT16_C(-15939), INT16_C(-18429), INT16_C(-10641), INT16_C(-25953)),
      simde_mm256_set_epi16(INT16_C(  6646), INT16_C(  -440), INT16_C(     5), INT16_C(     9),
                            INT16_C(  5230), INT16_C( 14027), INT16_C(  -115), INT16_C(    -1),
                            INT16_C(  -118), INT16_C(  -466), INT16_C(  -288), INT16_C(    -9),
                            INT16_C(   114), INT16_C( -2656), INT16_C( -2539), INT16_C(  1803)),
      simde_mm256_set_epi16(INT16_C(    -1), INT16_C(    28), INT16_C(  5618), INT16_C( -1690),
                            INT16_C(     1), INT16_C(     1), INT16_C(   -76), INT16_C(-22186),
                            INT16_C(   191), INT16_C(    49), INT16_C(    -1), INT16_C(  2037),
                            INT16_C(  -139), INT16_C(     6), INT16_C(     4), INT16_C(   -14)) },
    { simde_mm256_set_epi16(INT16_C(  2118), INT16_C( 26269), INT16_C( 31059), INT16_C( 17912),
                            INT16_C(-28141), INT16_C(  5202), INT16_C( 30957), INT16_C(-32121),
                            INT16_C( -2609), INT16_C(-12316), INT16_C(-10959), INT16_C( 17018),
                            INT16_C(  4376), INT16_C(  1963), INT16_C( 14912), INT16_C(  8031)),
      simde_mm256_set_epi16(INT16_C( -2197), INT16_C(    11), INT16_C(   -18), INT16_C( -3745),
                            INT16_C(    -1), INT16_C(    -3), INT16_C(     4), INT16_C(  3362),
                            INT16_C( -1965), INT16_C(     2), INT16_C(   574), INT16_C(  1347),
                            INT16_C(  -888), INT16_C(   -15), INT16_C(  1260), INT16_C(  -640)),
      simde_mm256_set_epi16(INT16_C(     0), INT16_C(  2388), INT16_C( -1725), INT16_C(    -4),
                            INT16_C( 28141), INT16_C( -1734), INT16_C(  7739), INT16_C(    -9),
                            INT16_C(     1), INT16_C( -6158), INT16_C(   -19), INT16_C(    12),
                            INT16_C(    -4), INT16_C(  -130), INT16_C(    11), INT16_C(   -12)) },
    { simde_mm256_set_epi16(INT16_C(-28159), INT16_C(  7162), INT16_C(-24830), INT16_C(  4589),
                            INT16_C(  7038), INT16_C(  3178), INT16_C(  4246), INT16_C( -8357),
                            INT16_C( -4695), INT16_C( -9928), INT16_C( -5517), INT16_C(-27023),
                            INT16_C( 18843), INT16_C(   726), INT16_C( 30135), INT16_C( -4871)),
      simde_mm256_set_epi16(INT16_C(   -48), INT16_C(   767), INT16_C(    10), INT16_C(    14),
                            INT16_C( -2039), INT16_C(    -2), INT16_C(   -53), INT16_C(    -1),
                            INT16_C( -1865), INT16_C( -5344), INT16_C(    63), INT16_C(  -505),
                            INT16_C(  2993), INT16_C(-14674), INT16_C(     3), INT16_C(    -2)),
      simde_mm256_set_epi16(INT16_C(   586), INT16_C(     9), INT16_C( -2483), INT16_C(   327),
                            INT16_C(    -3), INT16_C( -1589), INT16_C(   -80), INT16_C(  8357),
                            INT16_C(     2), INT16_C(     1), INT16_C(   -87), INT16_C(    53),
                            INT16_C(     6), INT16_C(     0), INT16_C( 10045), INT16_C(  2435)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_div_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_div_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi32(INT32_C( 1220357195), INT32_C( 1053623553), INT32_C( 1487300768), INT32_C(-1113593972),
                            INT32_C( -270466921), INT32_C( 1339961381), INT32_C(  586340423), INT32_C( 1641199948)),
      simde_mm256_set_epi32(INT32_C(  119685834), INT32_C(         18), INT32_C(   13175516), INT32_C(    2634495),
                            INT32_C(         17), INT32_C(      43789), INT32_C(        -89), INT32_C(         14)),
      simde_mm256_set_epi32(INT32_C(         10), INT32_C(   58534641), INT32_C(        112), INT32_C(       -422),
                            INT32_C(  -15909818), INT32_C(      30600), INT32_C(   -6588094), INT32_C(  117228567)) },
    { simde_mm256_set_epi32(INT32_C( 1446174898), INT32_C( 1812297946), INT32_C(-2020316623), INT32_C(  843765864),
                            INT32_C(-1892632155), INT32_C( -473868741), INT32_C( -150363910), INT32_C(-1673359813)),
      simde_mm256_set_epi32(INT32_C(    2569135), INT32_C(       8168), INT32_C(   -4111977), INT32_C(       -322),
                            INT32_C(  -34091386), INT32_C(       6306), INT32_C(     363174), INT32_C(     -37460)),
      simde_mm256_set_epi32(INT32_C(        562), INT32_C(     221877), INT32_C(        491), INT32_C(   -2620390),
                            INT32_C(         55), INT32_C(     -75145), INT32_C(       -414), INT32_C(      44670)) },
    { simde_mm256_set_epi32(INT32_C( 1015973964), INT32_C( -637033789), INT32_C(-1269659180), INT32_C(-1847076164),
                            INT32_C(  841308417), INT32_C(-1365136816), INT32_C( -621262370), INT32_C( -734285761)),
      simde_mm256_set_epi32(INT32_C(   -1597720), INT32_C(     192391), INT32_C(    2145556), INT32_C(      -4054),
                            INT32_C(         -1), INT32_C(      63753), INT32_C(   24015328), INT32_C(        267)),
      simde_mm256_set_epi32(INT32_C(       -635), INT32_C(      -3311), INT32_C(       -591), INT32_C(     455618),
                            INT32_C( -841308417), INT32_C(     -21412), INT32_C(        -25), INT32_C(   -2750133)) },
    { simde_mm256_set_epi32(INT32_C(   55709148), INT32_C( 1036348942), INT32_C( 1622954205), INT32_C( 1464937075),
                            INT32_C(  309602207), INT32_C(  765487752), INT32_C(-1883826060), INT32_C(  396580110)),
      simde_mm256_set_epi32(INT32_C(      81348), INT32_C(     130432), INT32_C(   -2896201), INT32_C(     130033),
                            INT32_C(       2659), INT32_C(      12656), INT32_C(        -49), INT32_C(      -3976)),
      simde_mm256_set_epi32(INT32_C(        684), INT32_C(       7945), INT32_C(       -560), INT32_C(      11265),
                            INT32_C(     116435), INT32_C(      60484), INT32_C(   38445429), INT32_C(     -99743)) },
    { simde_mm256_set_epi32(INT32_C( -679308904), INT32_C( 1402916027), INT32_C( -568259373), INT32_C( -151984025),
                            INT32_C(-1276596492), INT32_C(  897258790), INT32_C( 1125465930), INT32_C(-1843912592)),
      simde_mm256_set_epi32(INT32_C(        -32), INT32_C(      -3810), INT32_C(        -77), INT32_C(     -56604),
                            INT32_C(       2670), INT32_C(      -7949), INT32_C(       3200), INT32_C(      22045)),
      simde_mm256_set_epi32(INT32_C(   21228403), INT32_C(    -368219), INT32_C(    7379991), INT32_C(       2685),
                            INT32_C(    -478126), INT32_C(    -112876), INT32_C(     351708), INT32_C(     -83643)) },
    { simde_mm256_set_epi32(INT32_C(-2128829075), INT32_C( -944286219), INT32_C(-1801390937), INT32_C( 1597729863),
                            INT32_C( -919883082), INT32_C(  243529930), INT32_C(-1346833089), INT32_C( -703593878)),
      simde_mm256_set_epi32(INT32_C(    -702474), INT32_C(       -505), INT32_C(  -33538370), INT32_C(         98),
                            INT32_C(    -989384), INT32_C(   -3405840), INT32_C(    1441037), INT32_C(         13)),
      simde_mm256_set_epi32(INT32_C(       3030), INT32_C(    1869873), INT32_C(         53), INT32_C(   16303365),
                            INT32_C(        929), INT32_C(        -71), INT32_C(       -934), INT32_C(  -54122606)) },
    { simde_mm256_set_epi32(INT32_C( 2104898600), INT32_C( 1858378377), INT32_C(  427610695), INT32_C( 1702051599),
                            INT32_C( 1832473397), INT32_C(  333005662), INT32_C( 2145787203), INT32_C(-1223503753)),
      simde_mm256_set_epi32(INT32_C( -558822192), INT32_C(   -1119473), INT32_C(         71), INT32_C(         -1),
                            INT32_C(      83208), INT32_C(        -24), INT32_C(        490), INT32_C(    1423105)),
      simde_mm256_set_epi32(INT32_C(         -3), INT32_C(      -1660), INT32_C(    6022685), INT32_C(-1702051599),
                            INT32_C(      22022), INT32_C(  -13875235), INT32_C(    4379157), INT32_C(       -859)) },
    { simde_mm256_set_epi32(INT32_C( 1485879823), INT32_C( -139198096), INT32_C(  325243915), INT32_C( 1406493107),
                            INT32_C(  631640676), INT32_C( -221831503), INT32_C(-1100348538), INT32_C(-1615759789)),
      simde_mm256_set_epi32(INT32_C(         -5), INT32_C(    6019751), INT32_C(  240957918), INT32_C(     -11512),
                            INT32_C(        598), INT32_C(      -2086), INT32_C(       -398), INT32_C(   57524929)),
      simde_mm256_set_epi32(INT32_C( -297175964), INT32_C(        -23), INT32_C(          1), INT32_C(    -122176),
                            INT32_C(    1056255), INT32_C(     106343), INT32_C(    2764694), INT32_C(        -28)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_div_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_div_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi64x(INT64_C(-3334573923423752375), INT64_C( 5523377417165557950),
                             INT64_C( 8907494989684855351), INT64_C(-7237415305059575746)),
      simde_mm256_set_epi64x(INT64_C(      -9171626596647), INT64_C(       -528646059918),
                             INT64_C(             -547414), INT64_C(                -408)),
      simde_mm256_set_epi64x(INT64_C(              363574), INT64_C(           -10448157),
                             INT64_C(     -16271953201205), INT64_C(   17738763002596999)) },
    { simde_mm256_set_epi64x(INT64_C( 1061533355853207499), INT64_C(-6945701440990101118),
                             INT64_C( 2574461366811200995), INT64_C( 5644549884645175906)),
      simde_mm256_set_epi64x(INT64_C(            -7767261), INT64_C(                  10),
                             INT64_C(           703320391), INT64_C(               12482)),
      simde_mm256_set_epi64x(INT64_C(       -136667656185), INT64_C( -694570144099010111),
                             INT64_C(          3660438968), INT64_C(     452215180631723)) },
    { simde_mm256_set_epi64x(INT64_C( 6574854431853233270), INT64_C(-4435882974713226150),
                             INT64_C(-7281891715377237835), INT64_C( 5757222003030846963)),
      simde_mm256_set_epi64x(INT64_C(   -6789037658203169), INT64_C(              -17570),
                             INT64_C(   13607885161437703), INT64_C(            -3435095)),
      simde_mm256_set_epi64x(INT64_C(                -968), INT64_C(     252469150524372),
                             INT64_C(                -535), INT64_C(      -1676000810175)) },
    { simde_mm256_set_epi64x(INT64_C( 8744553519166698091), INT64_C( 1287292031192317940),
                             INT64_C( 3174243940922689145), INT64_C( 1491394686146555130)),
      simde_mm256_set_epi64x(INT64_C( 4922490686897444762), INT64_C(         39224412374),
                             INT64_C(     408105256075342), INT64_C(       -123591096713)),
      simde_mm256_set_epi64x(INT64_C(                   1), INT64_C(            32818644),
                             INT64_C(                7778), INT64_C(           -12067169)) },
    { simde_mm256_set_epi64x(INT64_C( 7799483112595335323), INT64_C(-7884857912053188380),
                             INT64_C( 7107489308993436793), INT64_C( 8695475100908985079)),
      simde_mm256_set_epi64x(INT64_C(                  87), INT64_C(             9826793),
                             INT64_C(          -161255109), INT64_C(   -1858599442623445)),
      simde_mm256_set_epi64x(INT64_C(   89649231179256727), INT64_C(       -802383637474),
                             INT64_C(        -44076056585), INT64_C(               -4678)) },
    { simde_mm256_set_epi64x(INT64_C(-7825910496387937639), INT64_C( -900763466419687908),
                             INT64_C(-4456690812175475739), INT64_C(-5053240277275181299)),
      simde_mm256_set_epi64x(INT64_C(      -6606649764768), INT64_C(              -57398),
                             INT64_C( -568604113828926107), INT64_C(             4737239)),
      simde_mm256_set_epi64x(INT64_C(             1184550), INT64_C(      15693290121950),
                             INT64_C(                   7), INT64_C(      -1066705791553)) },
    { simde_mm256_set_epi64x(INT64_C(-3221953081539923764), INT64_C(-1956032791701614517),
                             INT64_C( 7374977017813000944), INT64_C( 1124803906659433418)),
      simde_mm256_set_epi64x(INT64_C( -339969907608416876), INT64_C(              -15370),
                             INT64_C(         -1321351535), INT64_C(                  -7)),
      simde_mm256_set_epi64x(INT64_C(                   9), INT64_C(     127263031340378),
                             INT64_C(         -5581389072), INT64_C( -160686272379919059)) },
    { simde_mm256_set_epi64x(INT64_C( 2535418176622027197), INT64_C(-1425521063377864898),
                             INT64_C( 5027060343823160394), INT64_C(-2416798548878703366)),
      simde_mm256_set_epi64x(INT64_C(                -250), INT64_C(                  51),
                             INT64_C(                3355), INT64_C(      22043462023905)),
      simde_mm256_set_epi64x(INT64_C(  -10141672706488108), INT64_C(  -27951393399565978),
                             INT64_C(    1498378641974116), INT64_C(             -109637)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_div_epi64(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_div_epu8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_x_mm256_set_epu8(UINT8_C(236), UINT8_C(194), UINT8_C(120), UINT8_C(  0),
                             UINT8_C(238), UINT8_C(197), UINT8_C(223), UINT8_C( 50),
                             UINT8_C(177), UINT8_C( 51), UINT8_C( 14), UINT8_C(208),
                             UINT8_C(118), UINT8_C(136), UINT8_C(234), UINT8_C(162),
                             UINT8_C( 34), UINT8_C(152), UINT8_C( 32), UINT8_C( 62),
                             UINT8_C( 35), UINT8_C(101), UINT8_C( 72), UINT8_C(  2),
                             UINT8_C(139), UINT8_C(150), UINT8_C(255), UINT8_C(  2),
                             UINT8_C( 37), UINT8_C(232), UINT8_C(  3), UINT8_C(210)),
      simde_x_mm256_set_epu8(UINT8_C(218), UINT8_C( 43), UINT8_C(  2), UINT8_C(  2),
                             UINT8_C( 29), UINT8_C( 90), UINT8_C( 30), UINT8_C( 31),
                             UINT8_C( 20), UINT8_C(  1), UINT8_C( 24), UINT8_C( 92),
                             UINT8_C(  3), UINT8_C(  1), UINT8_C( 33), UINT8_C(  6),
                             UINT8_C( 14), UINT8_C( 38), UINT8_C(  5), UINT8_C(  4),
                             UINT8_C( 13), UINT8_C(  2), UINT8_C( 11), UINT8_C(  1),
                             UINT8_C(  1), UINT8_C( 25), UINT8_C(242), UINT8_C(  3),
                             UINT8_C( 12), UINT8_C( 59), UINT8_C( 75), UINT8_C(192)),
      simde_x_mm256_set_epu8(UINT8_C(  1), UINT8_C(  4), UINT8_C( 60), UINT8_C(  0),
                             UINT8_C(  8), UINT8_C(  2), UINT8_C(  7), UINT8_C(  1),
                             UINT8_C(  8), UINT8_C( 51), UINT8_C(  0), UINT8_C(  2),
                             UINT8_C( 39), UINT8_C(136), UINT8_C(  7), UINT8_C( 27),
                             UINT8_C(  2), UINT8_C(  4), UINT8_C(  6), UINT8_C( 15),
                             UINT8_C(  2), UINT8_C( 50), UINT8_C(  6), UINT8_C(  2),
                             UINT8_C(139), UINT8_C(  6), UINT8_C(  1), UINT8_C(  0),
                             UINT8_C(  3), UINT8_C(  3), UINT8_C(  0), UINT8_C(  1)) },
    { simde_x_mm256_set_epu8(UINT8_C(223), UINT8_C(136), UINT8_C(181), UINT8_C(189),
                             UINT8_C(144), UINT8_C(162), UINT8_C( 60), UINT8_C(122),
                             UINT8_C(180), UINT8_C(157), UINT8_C(255), UINT8_C(  4),
                             UINT8_C(248), UINT8_C( 71), UINT8_C( 45), UINT8_C(231),
                             UINT8_C(108), UINT8_C(100), UINT8_C( 13), UINT8_C(181),
                             UINT8_C(158), UINT8_C(251), UINT8_C(141), UINT8_C( 49),
                             UINT8_C(175), UINT8_C( 90), UINT8_C(251), UINT8_C( 13),
                             UINT8_C(151), UINT8_C(233), UINT8_C(181), UINT8_C(181)),
      simde_x_mm256_set_epu8(UINT8_C(  2), UINT8_C(  7), UINT8_C(  2), UINT8_C(  7),
                             UINT8_C(  6), UINT8_C( 23), UINT8_C(  1), UINT8_C( 22),
                             UINT8_C(  9), UINT8_C( 21), UINT8_C(  6), UINT8_C(  1),
                             UINT8_C(  1), UINT8_C( 27), UINT8_C(  1), UINT8_C(254),
                             UINT8_C( 30), UINT8_C( 92), UINT8_C(  8), UINT8_C( 13),
                             UINT8_C(  7), UINT8_C(  4), UINT8_C( 29), UINT8_C( 24),
                             UINT8_C(  1), UINT8_C( 15), UINT8_C( 31), UINT8_C(  1),
                             UINT8_C(190), UINT8_C(  1), UINT8_C( 20), UINT8_C(  8)),
      simde_x_mm256_set_epu8(UINT8_C(111), UINT8_C( 19), UINT8_C( 90), UINT8_C( 27),
                             UINT8_C( 24), UINT8_C(  7), UINT8_C( 60), UINT8_C(  5),
                             UINT8_C( 20), UINT8_C(  7), UINT8_C( 42), UINT8_C(  4),
                             UINT8_C(248), UINT8_C(  2), UINT8_C( 45), UINT8_C(  0),
                             UINT8_C(  3), UINT8_C(  1), UINT8_C(  1), UINT8_C( 13),
                             UINT8_C( 22), UINT8_C( 62), UINT8_C(  4), UINT8_C(  2),
                             UINT8_C(175), UINT8_C(  6), UINT8_C(  8), UINT8_C( 13),
                             UINT8_C(  0), UINT8_C(233), UINT8_C(  9), UINT8_C( 22)) },
    { simde_x_mm256_set_epu8(UINT8_C(162), UINT8_C(  7), UINT8_C(145), UINT8_C(154),
                             UINT8_C(168), UINT8_C(175), UINT8_C( 61), UINT8_C(  3),
                             UINT8_C( 93), UINT8_C(  6), UINT8_C(114), UINT8_C( 59),
                             UINT8_C( 17), UINT8_C(165), UINT8_C(240), UINT8_C(189),
                             UINT8_C(201), UINT8_C( 90), UINT8_C( 72), UINT8_C( 56),
                             UINT8_C( 98), UINT8_C(155), UINT8_C( 93), UINT8_C(190),
                             UINT8_C( 59), UINT8_C(174), UINT8_C(136), UINT8_C(  6),
                             UINT8_C(153), UINT8_C(172), UINT8_C(102), UINT8_C(120)),
      simde_x_mm256_set_epu8(UINT8_C(110), UINT8_C( 41), UINT8_C(  3), UINT8_C( 12),
                             UINT8_C(210), UINT8_C(  1), UINT8_C(  5), UINT8_C(  6),
                             UINT8_C( 47), UINT8_C( 58), UINT8_C( 48), UINT8_C( 20),
                             UINT8_C(109), UINT8_C(  3), UINT8_C( 34), UINT8_C(  3),
                             UINT8_C(  8), UINT8_C(  5), UINT8_C(  3), UINT8_C(  1),
                             UINT8_C( 20), UINT8_C( 14), UINT8_C(  1), UINT8_C(  6),
                             UINT8_C( 15), UINT8_C(  3), UINT8_C( 95), UINT8_C(  1),
                             UINT8_C(  4), UINT8_C(  1), UINT8_C(  7), UINT8_C(  1)),
      simde_x_mm256_set_epu8(UINT8_C(  1), UINT8_C(  0), UINT8_C( 48), UINT8_C( 12),
                             UINT8_C(  0), UINT8_C(175), UINT8_C( 12), UINT8_C(  0),
                             UINT8_C(  1), UINT8_C(  0), UINT8_C(  2), UINT8_C(  2),
                             UINT8_C(  0), UINT8_C( 55), UINT8_C(  7), UINT8_C( 63),
                             UINT8_C( 25), UINT8_C( 18), UINT8_C( 24), UINT8_C( 56),
                             UINT8_C(  4), UINT8_C( 11), UINT8_C( 93), UINT8_C( 31),
                             UINT8_C(  3), UINT8_C( 58), UINT8_C(  1), UINT8_C(  6),
                             UINT8_C( 38), UINT8_C(172), UINT8_C( 14), UINT8_C(120)) },
    { simde_x_mm256_set_epu8(UINT8_C(  3), UINT8_C( 62), UINT8_C(201), UINT8_C( 91),
                             UINT8_C( 81), UINT8_C(108), UINT8_C(219), UINT8_C(124),
                             UINT8_C(107), UINT8_C(229), UINT8_C(194), UINT8_C(  6),
                             UINT8_C(247), UINT8_C(122), UINT8_C( 69), UINT8_C(216),
                             UINT8_C(192), UINT8_C(132), UINT8_C( 14), UINT8_C(210),
                             UINT8_C(242), UINT8_C(228), UINT8_C( 76), UINT8_C(247),
                             UINT8_C(164), UINT8_C(249), UINT8_C(124), UINT8_C(200),
                             UINT8_C(141), UINT8_C(206), UINT8_C(142), UINT8_C(235)),
      simde_x_mm256_set_epu8(UINT8_C(182), UINT8_C(  3), UINT8_C( 13), UINT8_C( 91),
                             UINT8_C( 12), UINT8_C( 10), UINT8_C(  1), UINT8_C(  3),
                             UINT8_C(  4), UINT8_C(  8), UINT8_C( 93), UINT8_C(  1),
                             UINT8_C(  2), UINT8_C( 38), UINT8_C(  3), UINT8_C(172),
                             UINT8_C( 38), UINT8_C( 15), UINT8_C( 55), UINT8_C( 26),
                             UINT8_C(  4), UINT8_C( 16), UINT8_C( 28), UINT8_C( 54),
                             UINT8_C( 21), UINT8_C( 30), UINT8_C(  3), UINT8_C( 39),
                             UINT8_C( 14), UINT8_C(171), UINT8_C(  2), UINT8_C(  4)),
      simde_x_mm256_set_epu8(UINT8_C(  0), UINT8_C( 20), UINT8_C( 15), UINT8_C(  1),
                             UINT8_C(  6), UINT8_C( 10), UINT8_C(219), UINT8_C( 41),
                             UINT8_C( 26), UINT8_C( 28), UINT8_C(  2), UINT8_C(  6),
                             UINT8_C(123), UINT8_C(  3), UINT8_C( 23), UINT8_C(  1),
                             UINT8_C(  5), UINT8_C(  8), UINT8_C(  0), UINT8_C(  8),
                             UINT8_C( 60), UINT8_C( 14), UINT8_C(  2), UINT8_C(  4),
                             UINT8_C(  7), UINT8_C(  8), UINT8_C( 41), UINT8_C(  5),
                             UINT8_C( 10), UINT8_C(  1), UINT8_C( 71), UINT8_C( 58)) },
    { simde_x_mm256_set_epu8(UINT8_C(168), UINT8_C(  0), UINT8_C(141), UINT8_C(215),
                             UINT8_C( 23), UINT8_C(105), UINT8_C(153), UINT8_C(228),
                             UINT8_C(144), UINT8_C(204), UINT8_C(214), UINT8_C(202),
                             UINT8_C(227), UINT8_C(255), UINT8_C( 22), UINT8_C(115),
                             UINT8_C(131), UINT8_C(142), UINT8_C( 73), UINT8_C(133),
                             UINT8_C( 47), UINT8_C(243), UINT8_C(254), UINT8_C(234),
                             UINT8_C( 91), UINT8_C(217), UINT8_C(119), UINT8_C(247),
                             UINT8_C(245), UINT8_C( 31), UINT8_C( 46), UINT8_C( 19)),
      simde_x_mm256_set_epu8(UINT8_C(  1), UINT8_C(248), UINT8_C(  3), UINT8_C(  9),
                             UINT8_C(  3), UINT8_C( 87), UINT8_C(117), UINT8_C( 58),
                             UINT8_C( 18), UINT8_C(  9), UINT8_C(  7), UINT8_C( 77),
                             UINT8_C( 11), UINT8_C( 11), UINT8_C( 28), UINT8_C( 49),
                             UINT8_C( 64), UINT8_C( 46), UINT8_C(  5), UINT8_C(  1),
                             UINT8_C(115), UINT8_C(  2), UINT8_C(  1), UINT8_C(  1),
                             UINT8_C( 86), UINT8_C( 10), UINT8_C(  3), UINT8_C( 12),
                             UINT8_C( 49), UINT8_C(155), UINT8_C(  1), UINT8_C(  3)),
      simde_x_mm256_set_epu8(UINT8_C(168), UINT8_C(  0), UINT8_C( 47), UINT8_C( 23),
                             UINT8_C(  7), UINT8_C(  1), UINT8_C(  1), UINT8_C(  3),
                             UINT8_C(  8), UINT8_C( 22), UINT8_C( 30), UINT8_C(  2),
                             UINT8_C( 20), UINT8_C( 23), UINT8_C(  0), UINT8_C(  2),
                             UINT8_C(  2), UINT8_C(  3), UINT8_C( 14), UINT8_C(133),
                             UINT8_C(  0), UINT8_C(121), UINT8_C(254), UINT8_C(234),
                             UINT8_C(  1), UINT8_C( 21), UINT8_C( 39), UINT8_C( 20),
                             UINT8_C(  5), UINT8_C(  0), UINT8_C( 46), UINT8_C(  6)) },
    { simde_x_mm256_set_epu8(UINT8_C(163), UINT8_C(117), UINT8_C( 13), UINT8_C( 71),
                             UINT8_C(173), UINT8_C(230), UINT8_C(206), UINT8_C(  2),
                             UINT8_C( 15), UINT8_C(252), UINT8_C( 14), UINT8_C(197),
                             UINT8_C(249), UINT8_C(198), UINT8_C( 30), UINT8_C(180),
                             UINT8_C(128), UINT8_C( 78), UINT8_C(184), UINT8_C(254),
                             UINT8_C(184), UINT8_C(231), UINT8_C(238), UINT8_C( 30),
                             UINT8_C(194), UINT8_C( 37), UINT8_C(226), UINT8_C( 86),
                             UINT8_C(140), UINT8_C( 24), UINT8_C(144), UINT8_C( 16)),
      simde_x_mm256_set_epu8(UINT8_C( 48), UINT8_C(  1), UINT8_C(  7), UINT8_C(  6),
                             UINT8_C(119), UINT8_C( 41), UINT8_C(111), UINT8_C(  8),
                             UINT8_C(135), UINT8_C(  2), UINT8_C( 23), UINT8_C(  1),
                             UINT8_C( 88), UINT8_C( 15), UINT8_C( 65), UINT8_C( 79),
                             UINT8_C( 29), UINT8_C(  5), UINT8_C(  5), UINT8_C(  6),
                             UINT8_C( 44), UINT8_C( 21), UINT8_C(  2), UINT8_C(  3),
                             UINT8_C( 15), UINT8_C(  1), UINT8_C(  3), UINT8_C(  3),
                             UINT8_C(  1), UINT8_C( 10), UINT8_C(  1), UINT8_C( 55)),
      simde_x_mm256_set_epu8(UINT8_C(  3), UINT8_C(117), UINT8_C(  1), UINT8_C( 11),
                             UINT8_C(  1), UINT8_C(  5), UINT8_C(  1), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(126), UINT8_C(  0), UINT8_C(197),
                             UINT8_C(  2), UINT8_C( 13), UINT8_C(  0), UINT8_C(  2),
                             UINT8_C(  4), UINT8_C( 15), UINT8_C( 36), UINT8_C( 42),
                             UINT8_C(  4), UINT8_C( 11), UINT8_C(119), UINT8_C( 10),
                             UINT8_C( 12), UINT8_C( 37), UINT8_C( 75), UINT8_C( 28),
                             UINT8_C(140), UINT8_C(  2), UINT8_C(144), UINT8_C(  0)) },
    { simde_x_mm256_set_epu8(UINT8_C(239), UINT8_C(204), UINT8_C( 51), UINT8_C(246),
                             UINT8_C( 77), UINT8_C(149), UINT8_C( 40), UINT8_C( 86),
                             UINT8_C( 29), UINT8_C(  8), UINT8_C(140), UINT8_C(202),
                             UINT8_C(138), UINT8_C(208), UINT8_C(142), UINT8_C( 95),
                             UINT8_C(247), UINT8_C(102), UINT8_C( 63), UINT8_C(232),
                             UINT8_C(115), UINT8_C(187), UINT8_C(122), UINT8_C(179),
                             UINT8_C( 81), UINT8_C(192), UINT8_C( 47), UINT8_C( 34),
                             UINT8_C( 24), UINT8_C(133), UINT8_C( 98), UINT8_C(208)),
      simde_x_mm256_set_epu8(UINT8_C( 11), UINT8_C(  8), UINT8_C(  2), UINT8_C( 10),
                             UINT8_C(  3), UINT8_C(  7), UINT8_C( 38), UINT8_C( 21),
                             UINT8_C(247), UINT8_C( 14), UINT8_C(  4), UINT8_C(  3),
                             UINT8_C( 85), UINT8_C( 59), UINT8_C( 41), UINT8_C(  1),
                             UINT8_C(  1), UINT8_C(250), UINT8_C(  1), UINT8_C(  2),
                             UINT8_C(  6), UINT8_C(  8), UINT8_C(  6), UINT8_C( 40),
                             UINT8_C(136), UINT8_C( 10), UINT8_C( 29), UINT8_C(  7),
                             UINT8_C( 36), UINT8_C(  8), UINT8_C(  1), UINT8_C(  7)),
      simde_x_mm256_set_epu8(UINT8_C( 21), UINT8_C( 25), UINT8_C( 25), UINT8_C( 24),
                             UINT8_C( 25), UINT8_C( 21), UINT8_C(  1), UINT8_C(  4),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C( 35), UINT8_C( 67),
                             UINT8_C(  1), UINT8_C(  3), UINT8_C(  3), UINT8_C( 95),
                             UINT8_C(247), UINT8_C(  0), UINT8_C( 63), UINT8_C(116),
                             UINT8_C( 19), UINT8_C( 23), UINT8_C( 20), UINT8_C(  4),
                             UINT8_C(  0), UINT8_C( 19), UINT8_C(  1), UINT8_C(  4),
                             UINT8_C(  0), UINT8_C( 16), UINT8_C( 98), UINT8_C( 29)) },
    { simde_x_mm256_set_epu8(UINT8_C(179), UINT8_C(197), UINT8_C(124), UINT8_C(228),
                             UINT8_C(210), UINT8_C(205), UINT8_C(251), UINT8_C( 37),
                             UINT8_C( 37), UINT8_C( 57), UINT8_C( 27), UINT8_C( 38),
                             UINT8_C( 13), UINT8_C(212), UINT8_C(201), UINT8_C(125),
                             UINT8_C( 84), UINT8_C(229), UINT8_C( 76), UINT8_C(128),
                             UINT8_C(139), UINT8_C(203), UINT8_C(238), UINT8_C(218),
                             UINT8_C( 40), UINT8_C( 95), UINT8_C(243), UINT8_C(110),
                             UINT8_C( 74), UINT8_C(  0), UINT8_C(215), UINT8_C( 43)),
      simde_x_mm256_set_epu8(UINT8_C(  2), UINT8_C(  2), UINT8_C(  4), UINT8_C(  5),
                             UINT8_C(  7), UINT8_C(  2), UINT8_C(195), UINT8_C(  2),
                             UINT8_C( 30), UINT8_C(  1), UINT8_C(  9), UINT8_C( 24),
                             UINT8_C(  6), UINT8_C(  7), UINT8_C( 28), UINT8_C( 58),
                             UINT8_C(  3), UINT8_C( 77), UINT8_C( 90), UINT8_C( 51),
                             UINT8_C( 13), UINT8_C( 12), UINT8_C(  7), UINT8_C( 91),
                             UINT8_C(243), UINT8_C( 40), UINT8_C(  1), UINT8_C( 45),
                             UINT8_C( 77), UINT8_C( 45), UINT8_C( 60), UINT8_C(  3)),
      simde_x_mm256_set_epu8(UINT8_C( 89), UINT8_C( 98), UINT8_C( 31), UINT8_C( 45),
                             UINT8_C( 30), UINT8_C(102), UINT8_C(  1), UINT8_C( 18),
                             UINT8_C(  1), UINT8_C( 57), UINT8_C(  3), UINT8_C(  1),
                             UINT8_C(  2), UINT8_C( 30), UINT8_C(  7), UINT8_C(  2),
                             UINT8_C( 28), UINT8_C(  2), UINT8_C(  0), UINT8_C(  2),
                             UINT8_C( 10), UINT8_C( 16), UINT8_C( 34), UINT8_C(  2),
                             UINT8_C(  0), UINT8_C(  2), UINT8_C(243), UINT8_C(  2),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C(  3), UINT8_C( 14)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_div_epu8(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_u8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_div_epu16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_x_mm256_set_epu16(UINT16_C( 50042), UINT16_C( 33648), UINT16_C(  7535), UINT16_C( 12279),
                              UINT16_C( 36071), UINT16_C( 18107), UINT16_C( 48674), UINT16_C( 48206),
                              UINT16_C(  9011), UINT16_C( 45275), UINT16_C(  7845), UINT16_C( 54048),
                              UINT16_C( 27322), UINT16_C( 31657), UINT16_C( 43497), UINT16_C( 33598)),
      simde_x_mm256_set_epu16(UINT16_C( 12011), UINT16_C(   249), UINT16_C(     5), UINT16_C(     2),
                              UINT16_C(  1870), UINT16_C(  2904), UINT16_C(  1530), UINT16_C( 42479),
                              UINT16_C( 63442), UINT16_C(  1039), UINT16_C(    54), UINT16_C(     1),
                              UINT16_C(    98), UINT16_C(  7948), UINT16_C(  2053), UINT16_C(    29)),
      simde_x_mm256_set_epu16(UINT16_C(     4), UINT16_C(   135), UINT16_C(  1507), UINT16_C(  6139),
                              UINT16_C(    19), UINT16_C(     6), UINT16_C(    31), UINT16_C(     1),
                              UINT16_C(     0), UINT16_C(    43), UINT16_C(   145), UINT16_C( 54048),
                              UINT16_C(   278), UINT16_C(     3), UINT16_C(    21), UINT16_C(  1158)) },
    { simde_x_mm256_set_epu16(UINT16_C( 31411), UINT16_C( 55001), UINT16_C( 38051), UINT16_C( 20389),
                              UINT16_C( 61351), UINT16_C( 22045), UINT16_C( 61939), UINT16_C( 10168),
                              UINT16_C( 65482), UINT16_C( 32951), UINT16_C( 59114), UINT16_C(  9472),
                              UINT16_C( 21787), UINT16_C(  1387), UINT16_C( 60519), UINT16_C( 39038)),
      simde_x_mm256_set_epu16(UINT16_C( 11771), UINT16_C(     1), UINT16_C(   490), UINT16_C( 32408),
                              UINT16_C(  2225), UINT16_C(   134), UINT16_C( 13968), UINT16_C(     1),
                              UINT16_C(   387), UINT16_C( 14591), UINT16_C(    24), UINT16_C(    46),
                              UINT16_C(  8450), UINT16_C(  1053), UINT16_C(   908), UINT16_C(  5686)),
      simde_x_mm256_set_epu16(UINT16_C(     2), UINT16_C( 55001), UINT16_C(    77), UINT16_C(     0),
                              UINT16_C(    27), UINT16_C(   164), UINT16_C(     4), UINT16_C( 10168),
                              UINT16_C(   169), UINT16_C(     2), UINT16_C(  2463), UINT16_C(   205),
                              UINT16_C(     2), UINT16_C(     1), UINT16_C(    66), UINT16_C(     6)) },
    { simde_x_mm256_set_epu16(UINT16_C( 22899), UINT16_C(   630), UINT16_C( 34558), UINT16_C(  7884),
                              UINT16_C( 39724), UINT16_C( 33230), UINT16_C( 54475), UINT16_C( 22805),
                              UINT16_C( 61755), UINT16_C( 34661), UINT16_C( 28373), UINT16_C( 58279),
                              UINT16_C( 22187), UINT16_C( 56981), UINT16_C( 43877), UINT16_C(  3469)),
      simde_x_mm256_set_epu16(UINT16_C( 12306), UINT16_C(   182), UINT16_C( 29239), UINT16_C(  4194),
                              UINT16_C(   818), UINT16_C(    16), UINT16_C(     5), UINT16_C(    38),
                              UINT16_C( 42688), UINT16_C(     8), UINT16_C(     1), UINT16_C(    96),
                              UINT16_C(     3), UINT16_C(     1), UINT16_C(   508), UINT16_C(     1)),
      simde_x_mm256_set_epu16(UINT16_C(     1), UINT16_C(     3), UINT16_C(     1), UINT16_C(     1),
                              UINT16_C(    48), UINT16_C(  2076), UINT16_C( 10895), UINT16_C(   600),
                              UINT16_C(     1), UINT16_C(  4332), UINT16_C( 28373), UINT16_C(   607),
                              UINT16_C(  7395), UINT16_C( 56981), UINT16_C(    86), UINT16_C(  3469)) },
    { simde_x_mm256_set_epu16(UINT16_C( 29363), UINT16_C( 50584), UINT16_C( 56168), UINT16_C( 44370),
                              UINT16_C( 62910), UINT16_C( 23255), UINT16_C( 39479), UINT16_C( 21044),
                              UINT16_C(  7491), UINT16_C( 25737), UINT16_C(  6938), UINT16_C( 40142),
                              UINT16_C( 22210), UINT16_C( 63545), UINT16_C( 33358), UINT16_C(  9014)),
      simde_x_mm256_set_epu16(UINT16_C(    61), UINT16_C(   274), UINT16_C(   365), UINT16_C( 58937),
                              UINT16_C(     2), UINT16_C(   172), UINT16_C(   432), UINT16_C(     2),
                              UINT16_C(   957), UINT16_C(   351), UINT16_C(    18), UINT16_C( 12717),
                              UINT16_C(     4), UINT16_C(   417), UINT16_C(     1), UINT16_C( 10550)),
      simde_x_mm256_set_epu16(UINT16_C(   481), UINT16_C(   184), UINT16_C(   153), UINT16_C(     0),
                              UINT16_C( 31455), UINT16_C(   135), UINT16_C(    91), UINT16_C( 10522),
                              UINT16_C(     7), UINT16_C(    73), UINT16_C(   385), UINT16_C(     3),
                              UINT16_C(  5552), UINT16_C(   152), UINT16_C( 33358), UINT16_C(     0)) },
    { simde_x_mm256_set_epu16(UINT16_C( 22208), UINT16_C( 58940), UINT16_C( 24739), UINT16_C( 29405),
                              UINT16_C(  9863), UINT16_C( 41917), UINT16_C( 30045), UINT16_C( 40634),
                              UINT16_C( 50211), UINT16_C(  4668), UINT16_C( 42314), UINT16_C( 29370),
                              UINT16_C( 57744), UINT16_C( 37787), UINT16_C( 17171), UINT16_C( 34222)),
      simde_x_mm256_set_epu16(UINT16_C(  4256), UINT16_C( 23971), UINT16_C(   171), UINT16_C(    12),
                              UINT16_C(  8070), UINT16_C(  2906), UINT16_C(    22), UINT16_C(   107),
                              UINT16_C(     3), UINT16_C(     1), UINT16_C( 28355), UINT16_C(  2210),
                              UINT16_C(     1), UINT16_C(  1161), UINT16_C(   613), UINT16_C( 51426)),
      simde_x_mm256_set_epu16(UINT16_C(     5), UINT16_C(     2), UINT16_C(   144), UINT16_C(  2450),
                              UINT16_C(     1), UINT16_C(    14), UINT16_C(  1365), UINT16_C(   379),
                              UINT16_C( 16737), UINT16_C(  4668), UINT16_C(     1), UINT16_C(    13),
                              UINT16_C( 57744), UINT16_C(    32), UINT16_C(    28), UINT16_C(     0)) },
    { simde_x_mm256_set_epu16(UINT16_C(  9143), UINT16_C( 55963), UINT16_C( 46820), UINT16_C( 55354),
                              UINT16_C( 21540), UINT16_C( 21596), UINT16_C( 49435), UINT16_C( 42142),
                              UINT16_C( 28170), UINT16_C(  3714), UINT16_C( 39462), UINT16_C( 28043),
                              UINT16_C( 45359), UINT16_C( 22609), UINT16_C( 55149), UINT16_C( 21886)),
      simde_x_mm256_set_epu16(UINT16_C(  3121), UINT16_C(   103), UINT16_C(     1), UINT16_C(   283),
                              UINT16_C(   201), UINT16_C(    53), UINT16_C( 25996), UINT16_C(  3169),
                              UINT16_C(     1), UINT16_C(     2), UINT16_C(    38), UINT16_C(    24),
                              UINT16_C(    55), UINT16_C( 25444), UINT16_C(  5182), UINT16_C(     9)),
      simde_x_mm256_set_epu16(UINT16_C(     2), UINT16_C(   543), UINT16_C( 46820), UINT16_C(   195),
                              UINT16_C(   107), UINT16_C(   407), UINT16_C(     1), UINT16_C(    13),
                              UINT16_C( 28170), UINT16_C(  1857), UINT16_C(  1038), UINT16_C(  1168),
                              UINT16_C(   824), UINT16_C(     0), UINT16_C(    10), UINT16_C(  2431)) },
    { simde_x_mm256_set_epu16(UINT16_C( 51894), UINT16_C(  1840), UINT16_C( 33552), UINT16_C( 50070),
                              UINT16_C( 16848), UINT16_C( 13340), UINT16_C( 25356), UINT16_C( 34016),
                              UINT16_C( 61275), UINT16_C( 22886), UINT16_C( 28292), UINT16_C( 37845),
                              UINT16_C(  1481), UINT16_C(   559), UINT16_C( 12899), UINT16_C( 38851)),
      simde_x_mm256_set_epu16(UINT16_C( 16266), UINT16_C(   376), UINT16_C( 62048), UINT16_C(     8),
                              UINT16_C(    53), UINT16_C(  1573), UINT16_C(     8), UINT16_C(   212),
                              UINT16_C( 15505), UINT16_C(     1), UINT16_C(    10), UINT16_C(  2744),
                              UINT16_C(     2), UINT16_C(     5), UINT16_C(  4478), UINT16_C( 12656)),
      simde_x_mm256_set_epu16(UINT16_C(     3), UINT16_C(     4), UINT16_C(     0), UINT16_C(  6258),
                              UINT16_C(   317), UINT16_C(     8), UINT16_C(  3169), UINT16_C(   160),
                              UINT16_C(     3), UINT16_C( 22886), UINT16_C(  2829), UINT16_C(    13),
                              UINT16_C(   740), UINT16_C(   111), UINT16_C(     2), UINT16_C(     3)) },
    { simde_x_mm256_set_epu16(UINT16_C( 40946), UINT16_C( 11832), UINT16_C( 52869), UINT16_C( 41324),
                              UINT16_C( 41064), UINT16_C( 57085), UINT16_C( 14204), UINT16_C( 23869),
                              UINT16_C( 30467), UINT16_C( 20149), UINT16_C( 58844), UINT16_C( 49602),
                              UINT16_C( 36092), UINT16_C( 39146), UINT16_C( 62840), UINT16_C( 19573)),
      simde_x_mm256_set_epu16(UINT16_C(  7725), UINT16_C(  5897), UINT16_C(    81), UINT16_C(   199),
                              UINT16_C( 33008), UINT16_C( 55443), UINT16_C(   925), UINT16_C(  4043),
                              UINT16_C(   362), UINT16_C(   156), UINT16_C(  2592), UINT16_C(    29),
                              UINT16_C(   213), UINT16_C(    14), UINT16_C(    39), UINT16_C(   178)),
      simde_x_mm256_set_epu16(UINT16_C(     5), UINT16_C(     2), UINT16_C(   652), UINT16_C(   207),
                              UINT16_C(     1), UINT16_C(     1), UINT16_C(    15), UINT16_C(     5),
                              UINT16_C(    84), UINT16_C(   129), UINT16_C(    22), UINT16_C(  1710),
                              UINT16_C(   169), UINT16_C(  2796), UINT16_C(  1611), UINT16_C(   109)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_div_epu16(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_u16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_div_epu32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_x_mm256_set_epu32(UINT32_C( 621216267), UINT32_C(2973447507), UINT32_C(1814279233), UINT32_C(3673557536),
                              UINT32_C(4015780858), UINT32_C(1070914538), UINT32_C(2707640519), UINT32_C(3041291274)),
      simde_x_mm256_set_epu32(UINT32_C(    122731), UINT32_C(  51630147), UINT32_C(    152670), UINT32_C(   7731229),
                              UINT32_C(    711400), UINT32_C(   1744981), UINT32_C( 164943127), UINT32_C(    169494)),
      simde_x_mm256_set_epu32(UINT32_C(      5061), UINT32_C(        57), UINT32_C(     11883), UINT32_C(       475),
                              UINT32_C(      5644), UINT32_C(       613), UINT32_C(        16), UINT32_C(     17943)) },
    { simde_x_mm256_set_epu32(UINT32_C(1084014678), UINT32_C(1666523830), UINT32_C(3454667769), UINT32_C(4029614313),
                              UINT32_C(3425016021), UINT32_C(2449839571), UINT32_C(1601532569), UINT32_C(1519388398)),
      simde_x_mm256_set_epu32(UINT32_C(    130157), UINT32_C(   5585515), UINT32_C(  62691231), UINT32_C(     37123),
                              UINT32_C(   2515600), UINT32_C( 106484982), UINT32_C(4168501606), UINT32_C(   2781814)),
      simde_x_mm256_set_epu32(UINT32_C(      8328), UINT32_C(       298), UINT32_C(        55), UINT32_C(    108547),
                              UINT32_C(      1361), UINT32_C(        23), UINT32_C(         0), UINT32_C(       546)) },
    { simde_x_mm256_set_epu32(UINT32_C(2187853776), UINT32_C( 131263503), UINT32_C(  20338031), UINT32_C(3062800456),
                              UINT32_C(1802896354), UINT32_C(  22231847), UINT32_C(3438214155), UINT32_C(1776513196)),
      simde_x_mm256_set_epu32(UINT32_C(  28353115), UINT32_C(  92496104), UINT32_C(  15335526), UINT32_C(  99105532),
                              UINT32_C(   5905009), UINT32_C(     27824), UINT32_C(     28986), UINT32_C(  12459911)),
      simde_x_mm256_set_epu32(UINT32_C(        77), UINT32_C(         1), UINT32_C(         1), UINT32_C(        30),
                              UINT32_C(       305), UINT32_C(       799), UINT32_C(    118616), UINT32_C(       142)) },
    { simde_x_mm256_set_epu32(UINT32_C( 524596333), UINT32_C(3965897825), UINT32_C(1593754725), UINT32_C( 694203496),
                              UINT32_C(1917650066), UINT32_C(2692610113), UINT32_C(1620259645), UINT32_C( 607116294)),
      simde_x_mm256_set_epu32(UINT32_C(  29757558), UINT32_C(     80117), UINT32_C( 412054571), UINT32_C(    878110),
                              UINT32_C(4124070325), UINT32_C(   8250706), UINT32_C(   7930575), UINT32_C(     51813)),
      simde_x_mm256_set_epu32(UINT32_C(        17), UINT32_C(     49501), UINT32_C(         3), UINT32_C(       790),
                              UINT32_C(         0), UINT32_C(       326), UINT32_C(       204), UINT32_C(     11717)) },
    { simde_x_mm256_set_epu32(UINT32_C( 625862951), UINT32_C( 793130310), UINT32_C(2489185635), UINT32_C(2468815203),
                              UINT32_C(3079066921), UINT32_C( 802958712), UINT32_C(1537818066), UINT32_C(1678295724)),
      simde_x_mm256_set_epu32(UINT32_C(   8259237), UINT32_C(    229091), UINT32_C(   7899398), UINT32_C(  41009690),
                              UINT32_C(  26030333), UINT32_C(    228627), UINT32_C(1200021710), UINT32_C(    186204)),
      simde_x_mm256_set_epu32(UINT32_C(        75), UINT32_C(      3462), UINT32_C(       315), UINT32_C(        60),
                              UINT32_C(       118), UINT32_C(      3512), UINT32_C(         1), UINT32_C(      9013)) },
    { simde_x_mm256_set_epu32(UINT32_C(3334078645), UINT32_C(2226952893), UINT32_C(1901933944), UINT32_C(3456551705),
                              UINT32_C(3394846076), UINT32_C(2592342753), UINT32_C(1822000161), UINT32_C(3060682219)),
      simde_x_mm256_set_epu32(UINT32_C(     55529), UINT32_C(     95077), UINT32_C(  61849330), UINT32_C(     77269),
                              UINT32_C(    181901), UINT32_C(     66287), UINT32_C(     46407), UINT32_C(      1962)),
      simde_x_mm256_set_epu32(UINT32_C(     60042), UINT32_C(     23422), UINT32_C(        30), UINT32_C(     44734),
                              UINT32_C(     18663), UINT32_C(     39107), UINT32_C(     39261), UINT32_C(   1559980)) },
    { simde_x_mm256_set_epu32(UINT32_C(2418478797), UINT32_C(3856569345), UINT32_C(2562700829), UINT32_C(2670510577),
                              UINT32_C(3958231909), UINT32_C(3386864730), UINT32_C(2249491002), UINT32_C( 367242130)),
      simde_x_mm256_set_epu32(UINT32_C( 106591767), UINT32_C( 591565864), UINT32_C(    241208), UINT32_C(    384474),
                              UINT32_C(  63569588), UINT32_C(1007016971), UINT32_C( 701090048), UINT32_C(   4482965)),
      simde_x_mm256_set_epu32(UINT32_C(        22), UINT32_C(         6), UINT32_C(     10624), UINT32_C(      6945),
                              UINT32_C(        62), UINT32_C(         3), UINT32_C(         3), UINT32_C(        81)) },
    { simde_x_mm256_set_epu32(UINT32_C(3497551851), UINT32_C(3538232808), UINT32_C(3581222707), UINT32_C(2092274030),
                              UINT32_C(1202922035), UINT32_C(3381143079), UINT32_C(1645890362), UINT32_C(2497764821)),
      simde_x_mm256_set_epu32(UINT32_C(   7255461), UINT32_C(    387871), UINT32_C( 216379987), UINT32_C(   1108325),
                              UINT32_C(   9779926), UINT32_C( 265173482), UINT32_C(    305369), UINT32_C(1628979148)),
      simde_x_mm256_set_epu32(UINT32_C(       482), UINT32_C(      9122), UINT32_C(        16), UINT32_C(      1887),
                              UINT32_C(       122), UINT32_C(        12), UINT32_C(      5389), UINT32_C(         1)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_div_epu32(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_u32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_div_epu64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_x_mm256_set_epu64x(UINT64_C(10385902570114433083), UINT64_C(14228451038995253976),
                               UINT64_C( 3524803476344021799), UINT64_C( 9008088981795720991)),
      simde_x_mm256_set_epu64x(UINT64_C(      11435629647830), UINT64_C(        134705148152),
                               UINT64_C(                1685), UINT64_C(         72468903699)),
      simde_x_mm256_set_epu64x(UINT64_C(18446744073708846728), UINT64_C(18446744073678236607),
                               UINT64_C(    2091871499313959), UINT64_C(           124302818)) },
    { simde_x_mm256_set_epu64x(UINT64_C( 2776707612149100363), UINT64_C(15446686956822865619),
                               UINT64_C( 8116027459326381863), UINT64_C(10577862568627142107)),
      simde_x_mm256_set_epu64x(UINT64_C(              160900), UINT64_C(                 876),
                               UINT64_C(             6656645), UINT64_C(                 198)),
      simde_x_mm256_set_epu64x(UINT64_C(      17257349982281), UINT64_C(18443319350973379601),
                               UINT64_C(       1219236936824), UINT64_C(18407002247926307124)) },
    { simde_x_mm256_set_epu64x(UINT64_C(17966513918331168112), UINT64_C(15404442576328540960),
                               UINT64_C( 1544001744444053712), UINT64_C(12311626015854130554)),
      simde_x_mm256_set_epu64x(UINT64_C(         73453582701), UINT64_C(       2241703492778),
                               UINT64_C(                 149), UINT64_C(    1898802076338580)),
      simde_x_mm256_set_epu64x(UINT64_C(18446744073703013744), UINT64_C(18446744073708194478),
                               UINT64_C(   10362427815060763), UINT64_C(18446744073709548385)) },
    { simde_x_mm256_set_epu64x(UINT64_C( 4996618049503500636), UINT64_C( 3587306346705364576),
                               UINT64_C( 1416661578746677042), UINT64_C(18012200189266188151)),
      simde_x_mm256_set_epu64x(UINT64_C(       9141117518131), UINT64_C(  259684114065326460),
                               UINT64_C(          3735868918), UINT64_C(      13028085907926)),
      simde_x_mm256_set_epu64x(UINT64_C(              546609), UINT64_C(                  13),
                               UINT64_C(           379205376), UINT64_C(18446744073709518262)) },
    { simde_x_mm256_set_epu64x(UINT64_C(17900245410321819662), UINT64_C(   86463307544105486),
                               UINT64_C( 7004808110937624000), UINT64_C( 5352056724630121100)),
      simde_x_mm256_set_epu64x(UINT64_C(           574976069), UINT64_C(   26168849408611714),
                               UINT64_C(           479458176), UINT64_C(         85883846687)),
      simde_x_mm256_set_epu64x(UINT64_C(18446744072759079601), UINT64_C(                   3),
                               UINT64_C(         14609841820), UINT64_C(            62317384)) },
    { simde_x_mm256_set_epu64x(UINT64_C(18191047755947595201), UINT64_C(11274709867061747164),
                               UINT64_C( 4957427800472277352), UINT64_C( 2636046644056480855)),
      simde_x_mm256_set_epu64x(UINT64_C(           455513034), UINT64_C( 4176708352330988763),
                               UINT64_C(              255407), UINT64_C(   77468887445572755)),
      simde_x_mm256_set_epu64x(UINT64_C(18446744073148214621), UINT64_C(18446744073709551615),
                               UINT64_C(      19409913590748), UINT64_C(                  34)) },
    { simde_x_mm256_set_epu64x(UINT64_C(17236629464649076584), UINT64_C( 6716520602983844465),
                               UINT64_C(12794135593178656259), UINT64_C( 3865374743078695737)),
      simde_x_mm256_set_epu64x(UINT64_C(      13893724010244), UINT64_C(                   1),
                               UINT64_C(           142890905), UINT64_C(        135073488234)),
      simde_x_mm256_set_epu64x(UINT64_C(18446744073709464519), UINT64_C( 6716520602983844465),
                               UINT64_C(18446744034150641408), UINT64_C(            28616827)) },
    { simde_x_mm256_set_epu64x(UINT64_C( 3248934010021333275), UINT64_C( 8464322280604302303),
                               UINT64_C(10783963704762759650), UINT64_C(14288989654597257942)),
      simde_x_mm256_set_epu64x(UINT64_C(      37187973814779), UINT64_C(           988730192),
                               UINT64_C(       9409064941619), UINT64_C(           554649997)),
      simde_x_mm256_set_epu64x(UINT64_C(               87365), UINT64_C(          8560800862),
                               UINT64_C(18446744073708737212), UINT64_C(18446744066213374853)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_div_epi64(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_div_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512i a;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {
    { simde_mm512_set_epi8(INT8_C( 114), INT8_C(  89), INT8_C(   1), INT8_C( 122),
                           INT8_C(  12), INT8_C( 107), INT8_C(  92), INT8_C(-102),
                           INT8_C( -63), INT8_C( 120), INT8_C( 107), INT8_C( -43),
                           INT8_C(-119), INT8_C( -10), INT8_C(  98), INT8_C( -26),
                           INT8_C( 122), INT8_C(   1), INT8_C( -83), INT8_C(  43),
                           INT8_C(  82), INT8_C( -59), INT8_C( -43), INT8_C( -10),
                           INT8_C(  77), INT8_C( -22), INT8_C( -72), INT8_C( -94),
                           INT8_C(  75), INT8_C( -23), INT8_C( -92), INT8_C( -69),
                           INT8_C( 108), INT8_C(  26), INT8_C(  71), INT8_C( -21),
                           INT8_C(  15), INT8_C( 107), INT8_C(-112), INT8_C( -22),
                           INT8_C( -24), INT8_C(  35), INT8_C(  87), INT8_C(  75),
                           INT8_C(  27), INT8_C( -73), INT8_C(   9), INT8_C( -72),
                           INT8_C(  35), INT8_C(  -9), INT8_C( -68), INT8_C(  73),
                           INT8_C( -61), INT8_C( 118), INT8_C(  78), INT8_C( -20),
                           INT8_C( -42), INT8_C( -19), INT8_C(-125), INT8_C(  51),
                           INT8_C( -14), INT8_C(  17), INT8_C( -24), INT8_C( -72)),
      simde_mm512_set_epi8(INT8_C(  14), INT8_C(-123), INT8_C(  73), INT8_C(  -6),
                           INT8_C( -78), INT8_C( -38), INT8_C( -82), INT8_C( -80),
                           INT8_C(  31), INT8_C(  -9), INT8_C(  35), INT8_C(-110),
                           INT8_C(  -7), INT8_C(  74), INT8_C( -30), INT8_C( 100),
                           INT8_C(  10), INT8_C(  23), INT8_C( -11), INT8_C(  90),
                           INT8_C(  71), INT8_C(-126), INT8_C( -11), INT8_C(  -5),
                           INT8_C(  26), INT8_C(  58), INT8_C(-123), INT8_C( 125),
                           INT8_C(-104), INT8_C(  39), INT8_C(  75), INT8_C(  69),
                           INT8_C(   5), INT8_C(-119), INT8_C(  20), INT8_C(   6),
                           INT8_C( -18), INT8_C( -87), INT8_C(  95), INT8_C(  24),
                           INT8_C(  15), INT8_C( -48), INT8_C( -40), INT8_C(  79),
                           INT8_C(-107), INT8_C( -73), INT8_C(-108), INT8_C( -43),
                           INT8_C(  53), INT8_C( -95), INT8_C(  75), INT8_C(-123),
                           INT8_C(  61), INT8_C(  28), INT8_C(  20), INT8_C(  -5),
                           INT8_C(-127), INT8_C( -90), INT8_C(  94), INT8_C( -61),
                           INT8_C(  91), INT8_C( -70), INT8_C(-111), INT8_C(  30)),
      simde_mm512_set_epi8(INT8_C(   8), INT8_C(   0), INT8_C(   0), INT8_C( -20),
                           INT8_C(   0), INT8_C(  -2), INT8_C(  -1), INT8_C(   1),
                           INT8_C(  -2), INT8_C( -13), INT8_C(   3), INT8_C(   0),
                           INT8_C(  17), INT8_C(   0), INT8_C(  -3), INT8_C(   0),
                           INT8_C(  12), INT8_C(   0), INT8_C(   7), INT8_C(   0),
                           INT8_C(   1), INT8_C(   0), INT8_C(   3), INT8_C(   2),
                           INT8_C(   2), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  21), INT8_C(   0), INT8_C(   3), INT8_C(  -3),
                           INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                           INT8_C(  -1), INT8_C(   0), INT8_C(  -2), INT8_C(   0),
                           INT8_C(   0), INT8_C(   1), INT8_C(   0), INT8_C(   1),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(   4), INT8_C(   3), INT8_C(   4),
                           INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -2)) },
    { simde_mm512_set_epi8(INT8_C(  12), INT8_C( -52), INT8_C(  -7), INT8_C(  17),
                           INT8_C(-122), INT8_C(  53), INT8_C( -15), INT8_C(-121),
                           INT8_C( -47), INT8_C(-109), INT8_C( -20), INT8_C(  -5),
                           INT8_C( -34), INT8_C(   6), INT8_C(   3), INT8_C( -49),
                           INT8_C(  63), INT8_C(  48), INT8_C( -18), INT8_C( 117),
                           INT8_C( -63), INT8_C(  63), INT8_C(  77), INT8_C( -90),
                           INT8_C( -12), INT8_C(  83), INT8_C(  69), INT8_C( 113),
                           INT8_C(  28), INT8_C( 104), INT8_C( -69), INT8_C( -69),
                           INT8_C(-128), INT8_C(  96), INT8_C(  18), INT8_C(   9),
                           INT8_C(  99), INT8_C(-100), INT8_C( -63), INT8_C(  74),
                           INT8_C( -69), INT8_C(  22), INT8_C( 126), INT8_C(  62),
                           INT8_C(  46), INT8_C(  88), INT8_C(  24), INT8_C(  21),
                           INT8_C( 121), INT8_C(  64), INT8_C(  24), INT8_C(-125),
                           INT8_C(-125), INT8_C( -56), INT8_C( -13), INT8_C(  51),
                           INT8_C(  53), INT8_C( -41), INT8_C( -85), INT8_C(-121),
                           INT8_C( -44), INT8_C( -43), INT8_C( -24), INT8_C( 102)),
      simde_mm512_set_epi8(INT8_C( 109), INT8_C(-119), INT8_C(  12), INT8_C(  72),
                           INT8_C( -36), INT8_C(-115), INT8_C(  98), INT8_C(-110),
                           INT8_C(  58), INT8_C(  -6), INT8_C( -54), INT8_C(  39),
                           INT8_C( -42), INT8_C(  -8), INT8_C( -77), INT8_C( -22),
                           INT8_C( -49), INT8_C(   4), INT8_C( 119), INT8_C(  82),
                           INT8_C( 112), INT8_C(   3), INT8_C(  74), INT8_C(  94),
                           INT8_C( -27), INT8_C(  90), INT8_C(  17), INT8_C(  13),
                           INT8_C(   5), INT8_C(  89), INT8_C(-121), INT8_C(  56),
                           INT8_C(  46), INT8_C( -66), INT8_C( 124), INT8_C( -23),
                           INT8_C(  38), INT8_C(  53), INT8_C(  18), INT8_C( -68),
                           INT8_C(  -6), INT8_C( -62), INT8_C(  -9), INT8_C(  11),
                           INT8_C(  -6), INT8_C(  56), INT8_C( -81), INT8_C(  41),
                           INT8_C( 112), INT8_C(  58), INT8_C( -21), INT8_C( 108),
                           INT8_C(  17), INT8_C(  40), INT8_C(   4), INT8_C(  80),
                           INT8_C(  75), INT8_C(  35), INT8_C(  80), INT8_C( -85),
                           INT8_C(  88), INT8_C( -11), INT8_C(  23), INT8_C(  51)),
      simde_mm512_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   3), INT8_C(   0), INT8_C(   0), INT8_C(   1),
                           INT8_C(   0), INT8_C(  18), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   2),
                           INT8_C(  -1), INT8_C(  12), INT8_C(   0), INT8_C(   1),
                           INT8_C(   0), INT8_C(  21), INT8_C(   1), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   4), INT8_C(   8),
                           INT8_C(   5), INT8_C(   1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -2), INT8_C(  -1), INT8_C(   0), INT8_C(   0),
                           INT8_C(   2), INT8_C(  -1), INT8_C(  -3), INT8_C(  -1),
                           INT8_C(  11), INT8_C(   0), INT8_C( -14), INT8_C(   5),
                           INT8_C(  -7), INT8_C(   1), INT8_C(   0), INT8_C(   0),
                           INT8_C(   1), INT8_C(   1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -7), INT8_C(  -1), INT8_C(  -3), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(   1),
                           INT8_C(   0), INT8_C(   3), INT8_C(  -1), INT8_C(   2)) },
    { simde_mm512_set_epi8(INT8_C(-111), INT8_C(  -3), INT8_C( 110), INT8_C( -96),
                           INT8_C( 117), INT8_C( -29), INT8_C(-127), INT8_C( 101),
                           INT8_C(-120), INT8_C(  11), INT8_C(  87), INT8_C(  17),
                           INT8_C(-108), INT8_C(  87), INT8_C(   4), INT8_C( -21),
                           INT8_C(  98), INT8_C(   2), INT8_C( -60), INT8_C( -28),
                           INT8_C(  66), INT8_C(-109), INT8_C(   8), INT8_C( -58),
                           INT8_C(  13), INT8_C( -66), INT8_C( -49), INT8_C(  93),
                           INT8_C(-119), INT8_C(  58), INT8_C(  30), INT8_C(  10),
                           INT8_C( -11), INT8_C(  78), INT8_C(  76), INT8_C( 108),
                           INT8_C( -34), INT8_C( -94), INT8_C( -77), INT8_C(-122),
                           INT8_C(  37), INT8_C( -32), INT8_C( -97), INT8_C( 121),
                           INT8_C( -95), INT8_C( -80), INT8_C( -87), INT8_C( -89),
                           INT8_C(  -4), INT8_C( 115), INT8_C( -42), INT8_C( -55),
                           INT8_C(  95), INT8_C( -63), INT8_C(  31), INT8_C( -74),
                           INT8_C( -45), INT8_C( 119), INT8_C(  57), INT8_C( -52),
                           INT8_C( -69), INT8_C(-123), INT8_C( 106), INT8_C( 119)),
      simde_mm512_set_epi8(INT8_C( -74), INT8_C( -32), INT8_C(  89), INT8_C(  50),
                           INT8_C(-105), INT8_C(  85), INT8_C( -71), INT8_C( 105),
                           INT8_C( -37), INT8_C( -78), INT8_C(-107), INT8_C( -67),
                           INT8_C(   9), INT8_C(   2), INT8_C(  83), INT8_C(  67),
                           INT8_C(  25), INT8_C(-103), INT8_C( -90), INT8_C(  30),
                           INT8_C(  69), INT8_C(-127), INT8_C( 114), INT8_C( -99),
                           INT8_C( -97), INT8_C( -52), INT8_C( 120), INT8_C(  78),
                           INT8_C(  97), INT8_C( 124), INT8_C(  31), INT8_C(  72),
                           INT8_C(  -6), INT8_C(  19), INT8_C(  -4), INT8_C( -65),
                           INT8_C( 107), INT8_C( -15), INT8_C(-116), INT8_C( -13),
                           INT8_C( 106), INT8_C( -71), INT8_C( -14), INT8_C( -87),
                           INT8_C(-122), INT8_C( -59), INT8_C( -65), INT8_C( -58),
                           INT8_C( -26), INT8_C(  55), INT8_C(  28), INT8_C( -31),
                           INT8_C( -20), INT8_C( -40), INT8_C( -47), INT8_C(  58),
                           INT8_C(  -3), INT8_C(  67), INT8_C( -47), INT8_C(  93),
                           INT8_C( -77), INT8_C(  21), INT8_C(  49), INT8_C( -54)),
      simde_mm512_set_epi8(INT8_C(   1), INT8_C(   0), INT8_C(   1), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   1), INT8_C(   0),
                           INT8_C(   3), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C( -12), INT8_C(  43), INT8_C(   0), INT8_C(   0),
                           INT8_C(   3), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   1), INT8_C(   0), INT8_C(   1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   1), INT8_C(   4), INT8_C( -19), INT8_C(  -1),
                           INT8_C(   0), INT8_C(   6), INT8_C(   0), INT8_C(   9),
                           INT8_C(   0), INT8_C(   0), INT8_C(   6), INT8_C(  -1),
                           INT8_C(   0), INT8_C(   1), INT8_C(   1), INT8_C(   1),
                           INT8_C(   0), INT8_C(   2), INT8_C(  -1), INT8_C(   1),
                           INT8_C(  -4), INT8_C(   1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  15), INT8_C(   1), INT8_C(  -1), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -5), INT8_C(   2), INT8_C(  -2)) },
    { simde_mm512_set_epi8(INT8_C( -91), INT8_C( 110), INT8_C( 126), INT8_C(  44),
                           INT8_C(  21), INT8_C( -84), INT8_C( 100), INT8_C( -15),
                           INT8_C( -61), INT8_C( -53), INT8_C(  75), INT8_C( -30),
                           INT8_C( -56), INT8_C( -86), INT8_C(  52), INT8_C( 108),
                           INT8_C(  96), INT8_C(   6), INT8_C(-100), INT8_C(-109),
                           INT8_C(  -7), INT8_C( -22), INT8_C( 109), INT8_C( 124),
                           INT8_C(  85), INT8_C(  53), INT8_C( -45), INT8_C( 122),
                           INT8_C(   7), INT8_C( -21), INT8_C(-123), INT8_C(   4),
                           INT8_C(   3), INT8_C(  94), INT8_C(-127), INT8_C(  73),
                           INT8_C(  65), INT8_C( -69), INT8_C( -91), INT8_C(-115),
                           INT8_C( 117), INT8_C(-104), INT8_C(  66), INT8_C(  79),
                           INT8_C( -63), INT8_C(-115), INT8_C( -77), INT8_C( -89),
                           INT8_C(-113), INT8_C(  34), INT8_C( 100), INT8_C(  96),
                           INT8_C(-101), INT8_C( -34), INT8_C(  64), INT8_C( -59),
                           INT8_C( -53), INT8_C(  87), INT8_C(  48), INT8_C(  95),
                           INT8_C( -53), INT8_C(  61), INT8_C(  63), INT8_C( 106)),
      simde_mm512_set_epi8(INT8_C(  -1), INT8_C(  95), INT8_C(  91), INT8_C( 117),
                           INT8_C(  15), INT8_C( -50), INT8_C( -39), INT8_C(  74),
                           INT8_C(  36), INT8_C( 100), INT8_C( -62), INT8_C(-111),
                           INT8_C(   9), INT8_C(  41), INT8_C(  36), INT8_C( -21),
                           INT8_C(  71), INT8_C( -85), INT8_C( 120), INT8_C( -33),
                           INT8_C( 125), INT8_C(  38), INT8_C(-127), INT8_C(  39),
                           INT8_C(  28), INT8_C(-118), INT8_C(  31), INT8_C(  92),
                           INT8_C(  22), INT8_C(  48), INT8_C( 122), INT8_C(  -6),
                           INT8_C( 107), INT8_C(-101), INT8_C(  14), INT8_C( -17),
                           INT8_C(  26), INT8_C(  -4), INT8_C( -71), INT8_C(  13),
                           INT8_C( -39), INT8_C( -26), INT8_C( -37), INT8_C( 110),
                           INT8_C(  36), INT8_C(  78), INT8_C( -24), INT8_C( -52),
                           INT8_C(-117), INT8_C( -27), INT8_C( 113), INT8_C(-111),
                           INT8_C( -59), INT8_C(  38), INT8_C( -10), INT8_C( -53),
                           INT8_C( 110), INT8_C(  62), INT8_C(  -4), INT8_C(  19),
                           INT8_C( -15), INT8_C(  42), INT8_C( 122), INT8_C( 105)),
      simde_mm512_set_epi8(INT8_C(  91), INT8_C(   1), INT8_C(   1), INT8_C(   0),
                           INT8_C(   1), INT8_C(   1), INT8_C(  -2), INT8_C(   0),
                           INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                           INT8_C(  -6), INT8_C(  -2), INT8_C(   1), INT8_C(  -5),
                           INT8_C(   1), INT8_C(   0), INT8_C(   0), INT8_C(   3),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   3),
                           INT8_C(   3), INT8_C(   0), INT8_C(  -1), INT8_C(   1),
                           INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(  -9), INT8_C(  -4),
                           INT8_C(   2), INT8_C(  17), INT8_C(   1), INT8_C(  -8),
                           INT8_C(  -3), INT8_C(   4), INT8_C(  -1), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(   3), INT8_C(   1),
                           INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0),
                           INT8_C(   1), INT8_C(   0), INT8_C(  -6), INT8_C(   1),
                           INT8_C(   0), INT8_C(   1), INT8_C( -12), INT8_C(   5),
                           INT8_C(   3), INT8_C(   1), INT8_C(   0), INT8_C(   1)) },
    { simde_mm512_set_epi8(INT8_C( -55), INT8_C( -14), INT8_C(   9), INT8_C(-109),
                           INT8_C(  77), INT8_C( -36), INT8_C(  82), INT8_C( -60),
                           INT8_C( -11), INT8_C(  52), INT8_C(  95), INT8_C( 118),
                           INT8_C( 124), INT8_C( 103), INT8_C( 108), INT8_C(   5),
                           INT8_C(  -7), INT8_C(  55), INT8_C(   1), INT8_C( -90),
                           INT8_C(  89), INT8_C( 106), INT8_C( -80), INT8_C(-113),
                           INT8_C( -97), INT8_C( 113), INT8_C( 100), INT8_C(   9),
                           INT8_C( 122), INT8_C( -51), INT8_C(-121), INT8_C(  78),
                           INT8_C(-100), INT8_C(  26), INT8_C( -23), INT8_C( -89),
                           INT8_C(  20), INT8_C(  19), INT8_C( -91), INT8_C( -38),
                           INT8_C( -59), INT8_C(  10), INT8_C(-121), INT8_C( -30),
                           INT8_C(  79), INT8_C(  49), INT8_C( 104), INT8_C(  55),
                           INT8_C(   2), INT8_C(  -2), INT8_C( -24), INT8_C( -48),
                           INT8_C( -25), INT8_C( -39), INT8_C(  89), INT8_C(  19),
                           INT8_C( -33), INT8_C( 101), INT8_C(  31), INT8_C( -59),
                           INT8_C(-123), INT8_C(  38), INT8_C( 124), INT8_C( 108)),
      simde_mm512_set_epi8(INT8_C( -47), INT8_C( -85), INT8_C(  13), INT8_C( -86),
                           INT8_C(  92), INT8_C(  23), INT8_C(  69), INT8_C( -53),
                           INT8_C(  11), INT8_C( -74), INT8_C(  93), INT8_C(  45),
                           INT8_C( 123), INT8_C( -37), INT8_C(   6), INT8_C( -51),
                           INT8_C(  52), INT8_C( -77), INT8_C( -79), INT8_C( -50),
                           INT8_C( -32), INT8_C(   4), INT8_C( -47), INT8_C( -53),
                           INT8_C( -18), INT8_C( -18), INT8_C( 115), INT8_C( 117),
                           INT8_C( -67), INT8_C( -53), INT8_C( -72), INT8_C(  83),
                           INT8_C( -37), INT8_C(  34), INT8_C( 127), INT8_C( -10),
                           INT8_C( 126), INT8_C( -99), INT8_C(-106), INT8_C(  33),
                           INT8_C( 106), INT8_C( -41), INT8_C( -43), INT8_C(  -4),
                           INT8_C(-104), INT8_C(  77), INT8_C(-107), INT8_C( -78),
                           INT8_C( 126), INT8_C(  37), INT8_C(-124), INT8_C( -92),
                           INT8_C( -30), INT8_C( -11), INT8_C( -49), INT8_C(  22),
                           INT8_C(  41), INT8_C(  82), INT8_C( -75), INT8_C(  81),
                           INT8_C(  39), INT8_C( -91), INT8_C(  65), INT8_C( -12)),
      simde_mm512_set_epi8(INT8_C(   1), INT8_C(   0), INT8_C(   0), INT8_C(   1),
                           INT8_C(   0), INT8_C(  -1), INT8_C(   1), INT8_C(   1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   1), INT8_C(   2),
                           INT8_C(   1), INT8_C(  -2), INT8_C(  18), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   1),
                           INT8_C(  -2), INT8_C(  26), INT8_C(   1), INT8_C(   2),
                           INT8_C(   5), INT8_C(  -6), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   1), INT8_C(   0),
                           INT8_C(   2), INT8_C(   0), INT8_C(   0), INT8_C(   8),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   0), INT8_C(   0), INT8_C(   2), INT8_C(   7),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   3), INT8_C(  -1), INT8_C(   0),
                           INT8_C(   0), INT8_C(   1), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -3), INT8_C(   0), INT8_C(   1), INT8_C(  -9)) },
    { simde_mm512_set_epi8(INT8_C( 101), INT8_C(  62), INT8_C( -23), INT8_C(  48),
                           INT8_C( 118), INT8_C(  51), INT8_C(  -2), INT8_C(-103),
                           INT8_C( 110), INT8_C( -27), INT8_C( 109), INT8_C(  60),
                           INT8_C(  81), INT8_C(  82), INT8_C(  61), INT8_C( -96),
                           INT8_C( -57), INT8_C( 116), INT8_C(  -5), INT8_C(   0),
                           INT8_C(  28), INT8_C(  71), INT8_C( -24), INT8_C(  46),
                           INT8_C( -73), INT8_C(   2), INT8_C( -88), INT8_C(  76),
                           INT8_C(  95), INT8_C( -58), INT8_C(  94), INT8_C(  46),
                           INT8_C(  20), INT8_C( 112), INT8_C( -69), INT8_C( 111),
                           INT8_C( -44), INT8_C( -74), INT8_C( -18), INT8_C(  53),
                           INT8_C( 127), INT8_C(  36), INT8_C(  79), INT8_C( -48),
                           INT8_C( 114), INT8_C(  84), INT8_C(  65), INT8_C(-112),
                           INT8_C(-112), INT8_C(  23), INT8_C(  37), INT8_C(  63),
                           INT8_C( -88), INT8_C( -57), INT8_C( 100), INT8_C( 121),
                           INT8_C(  97), INT8_C( 122), INT8_C(  12), INT8_C( -79),
                           INT8_C(  47), INT8_C(  60), INT8_C( -36), INT8_C( -83)),
      simde_mm512_set_epi8(INT8_C(  -6), INT8_C(  53), INT8_C(  88), INT8_C( -36),
                           INT8_C(  96), INT8_C(  32), INT8_C(  77), INT8_C(   2),
                           INT8_C(  -8), INT8_C( -42), INT8_C( -69), INT8_C(  40),
                           INT8_C( -69), INT8_C(  97), INT8_C(  30), INT8_C( 102),
                           INT8_C( -84), INT8_C( -54), INT8_C(-126), INT8_C(  91),
                           INT8_C(  69), INT8_C(  35), INT8_C( 100), INT8_C(-118),
                           INT8_C( -93), INT8_C( 108), INT8_C(  21), INT8_C( -16),
                           INT8_C(  32), INT8_C( 106), INT8_C( -36), INT8_C( -46),
                           INT8_C( -28), INT8_C( -81), INT8_C(  80), INT8_C(  14),
                           INT8_C( -78), INT8_C(   3), INT8_C(  82), INT8_C(-104),
                           INT8_C(  13), INT8_C( -56), INT8_C(-106), INT8_C(  89),
                           INT8_C( -24), INT8_C(  42), INT8_C(  41), INT8_C(  68),
                           INT8_C( -88), INT8_C(-107), INT8_C( -36), INT8_C(  52),
                           INT8_C(  32), INT8_C( -59), INT8_C( -33), INT8_C( 120),
                           INT8_C(  47), INT8_C(-127), INT8_C(  64), INT8_C( 114),
                           INT8_C( 107), INT8_C( -75), INT8_C( 127), INT8_C(  23)),
      simde_mm512_set_epi8(INT8_C( -16), INT8_C(   1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   1), INT8_C(   1), INT8_C(   0), INT8_C( -51),
                           INT8_C( -13), INT8_C(   0), INT8_C(  -1), INT8_C(   1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   2), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -2), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   2), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(  -4), INT8_C(  -4),
                           INT8_C(   2), INT8_C(   0), INT8_C(  -2), INT8_C(  -1),
                           INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   7),
                           INT8_C(   0), INT8_C( -24), INT8_C(   0), INT8_C(   0),
                           INT8_C(   9), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -4), INT8_C(   2), INT8_C(   1), INT8_C(  -1),
                           INT8_C(   1), INT8_C(   0), INT8_C(  -1), INT8_C(   1),
                           INT8_C(  -2), INT8_C(   0), INT8_C(  -3), INT8_C(   1),
                           INT8_C(   2), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -3)) },
    { simde_mm512_set_epi8(INT8_C( 106), INT8_C( -71), INT8_C(  61), INT8_C(  19),
                           INT8_C(  29), INT8_C(  79), INT8_C(  45), INT8_C(  94),
                           INT8_C(-112), INT8_C(  60), INT8_C(   2), INT8_C(  77),
                           INT8_C(  30), INT8_C( -34), INT8_C( 102), INT8_C(  43),
                           INT8_C( -87), INT8_C(  52), INT8_C(-104), INT8_C(  -8),
                           INT8_C(-103), INT8_C(  79), INT8_C( -22), INT8_C(  31),
                           INT8_C(  11), INT8_C( 124), INT8_C(  70), INT8_C( -64),
                           INT8_C( -91), INT8_C(  88), INT8_C( -70), INT8_C( -61),
                           INT8_C( -84), INT8_C(-108), INT8_C( -57), INT8_C(  13),
                           INT8_C( -58), INT8_C(  -7), INT8_C(  39), INT8_C(  66),
                           INT8_C(  50), INT8_C( -61), INT8_C(  -9), INT8_C( -41),
                           INT8_C(  25), INT8_C( -31), INT8_C(  64), INT8_C(  18),
                           INT8_C(  73), INT8_C(  60), INT8_C( -53), INT8_C(  42),
                           INT8_C(  -1), INT8_C(  50), INT8_C(  95), INT8_C(  78),
                           INT8_C(  39), INT8_C(  -9), INT8_C(-121), INT8_C( -72),
                           INT8_C(  48), INT8_C(  20), INT8_C(  76), INT8_C( -48)),
      simde_mm512_set_epi8(INT8_C(  12), INT8_C(  55), INT8_C(-111), INT8_C( -85),
                           INT8_C( -94), INT8_C( -11), INT8_C(  57), INT8_C(  93),
                           INT8_C(  32), INT8_C(  57), INT8_C(  61), INT8_C( -21),
                           INT8_C(-102), INT8_C(  75), INT8_C( -15), INT8_C(-114),
                           INT8_C(  26), INT8_C(  71), INT8_C(-127), INT8_C( -52),
                           INT8_C( -57), INT8_C( -26), INT8_C( -36), INT8_C(  -4),
                           INT8_C(  -7), INT8_C(  40), INT8_C(  60), INT8_C(  82),
                           INT8_C(   6), INT8_C( -12), INT8_C(  52), INT8_C( -37),
                           INT8_C( -96), INT8_C(-117), INT8_C( 104), INT8_C( -99),
                           INT8_C(  -1), INT8_C(  95), INT8_C(  81), INT8_C( -70),
                           INT8_C( -22), INT8_C( -86), INT8_C( 114), INT8_C( -43),
                           INT8_C(-120), INT8_C( 109), INT8_C( -86), INT8_C( -33),
                           INT8_C( -23), INT8_C(  69), INT8_C( -80), INT8_C(  61),
                           INT8_C( -35), INT8_C( 107), INT8_C( -31), INT8_C(  11),
                           INT8_C( -45), INT8_C( 125), INT8_C( -53), INT8_C(  -7),
                           INT8_C(  88), INT8_C(-111), INT8_C(  86), INT8_C(-105)),
      simde_mm512_set_epi8(INT8_C(   8), INT8_C(  -1), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -7), INT8_C(   0), INT8_C(   1),
                           INT8_C(  -3), INT8_C(   1), INT8_C(   0), INT8_C(  -3),
                           INT8_C(   0), INT8_C(   0), INT8_C(  -6), INT8_C(   0),
                           INT8_C(  -3), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   1), INT8_C(  -3), INT8_C(   0), INT8_C(  -7),
                           INT8_C(  -1), INT8_C(   3), INT8_C(   1), INT8_C(   0),
                           INT8_C( -15), INT8_C(  -7), INT8_C(  -1), INT8_C(   1),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(  58), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -2), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -3), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(  -3), INT8_C(   7),
                           INT8_C(   0), INT8_C(   0), INT8_C(   2), INT8_C(  10),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0)) },
    { simde_mm512_set_epi8(INT8_C( 102), INT8_C(  35), INT8_C(  43), INT8_C( -33),
                           INT8_C( -74), INT8_C(  81), INT8_C(  81), INT8_C( 115),
                           INT8_C( -81), INT8_C(  72), INT8_C(-127), INT8_C( 118),
                           INT8_C(-113), INT8_C( 106), INT8_C(  25), INT8_C(  84),
                           INT8_C( -82), INT8_C(  58), INT8_C(  13), INT8_C( -38),
                           INT8_C(  -3), INT8_C( 104), INT8_C(  85), INT8_C(-112),
                           INT8_C(  -4), INT8_C(  52), INT8_C(  -2), INT8_C( -64),
                           INT8_C( -23), INT8_C(   5), INT8_C(  33), INT8_C( -11),
                           INT8_C( 116), INT8_C( 110), INT8_C(  21), INT8_C(  84),
                           INT8_C(  42), INT8_C(  77), INT8_C(  25), INT8_C(  68),
                           INT8_C(  71), INT8_C(  60), INT8_C( -51), INT8_C( -46),
                           INT8_C(  -1), INT8_C( -12), INT8_C(  88), INT8_C(  19),
                           INT8_C( -70), INT8_C(  27), INT8_C(  -6), INT8_C(  61),
                           INT8_C( -48), INT8_C( 119), INT8_C(-107), INT8_C(-115),
                           INT8_C(  90), INT8_C(  64), INT8_C(  19), INT8_C(  64),
                           INT8_C( -19), INT8_C(  -7), INT8_C(  40), INT8_C( -68)),
      simde_mm512_set_epi8(INT8_C(  66), INT8_C(  58), INT8_C(  74), INT8_C( -51),
                           INT8_C( -69), INT8_C( -59), INT8_C(  84), INT8_C(  27),
                           INT8_C(  43), INT8_C( -40), INT8_C( -56), INT8_C( 125),
                           INT8_C(   1), INT8_C(  92), INT8_C( -82), INT8_C(  49),
                           INT8_C( -14), INT8_C(  14), INT8_C(  52), INT8_C( -25),
                           INT8_C(  47), INT8_C( -55), INT8_C( -54), INT8_C( -50),
                           INT8_C( -40), INT8_C(-118), INT8_C(  97), INT8_C( -86),
                           INT8_C(  93), INT8_C( 116), INT8_C( -54), INT8_C(-127),
                           INT8_C(  17), INT8_C( -57), INT8_C( -81), INT8_C( -49),
                           INT8_C(  73), INT8_C(  79), INT8_C( -43), INT8_C(  61),
                           INT8_C( -14), INT8_C(  18), INT8_C( 125), INT8_C( -11),
                           INT8_C( -70), INT8_C(  81), INT8_C(-107), INT8_C( -13),
                           INT8_C( -75), INT8_C(  46), INT8_C(  17), INT8_C( -39),
                           INT8_C( -35), INT8_C(  57), INT8_C(  -8), INT8_C( -62),
                           INT8_C( -61), INT8_C( 118), INT8_C( -33), INT8_C( 116),
                           INT8_C(  -5), INT8_C( 120), INT8_C( 126), INT8_C( -48)),
      simde_mm512_set_epi8(INT8_C(   1), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   1), INT8_C(  -1), INT8_C(   0), INT8_C(   4),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(   2), INT8_C(   0),
                           INT8_C(-113), INT8_C(   1), INT8_C(   0), INT8_C(   1),
                           INT8_C(   5), INT8_C(   4), INT8_C(   0), INT8_C(   1),
                           INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(   2),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   6), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   1),
                           INT8_C(  -5), INT8_C(   3), INT8_C(   0), INT8_C(   4),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   1), INT8_C(   2), INT8_C(  13), INT8_C(   1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   3), INT8_C(   0), INT8_C(   0), INT8_C(   1)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_div_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m512i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_div_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512i a;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {
    { simde_mm512_set_epi16(INT16_C(-20040), INT16_C(  8356), INT16_C(-32332), INT16_C( 10333),
                            INT16_C( -5915), INT16_C( 26879), INT16_C(  2532), INT16_C( 21861),
                            INT16_C(-27724), INT16_C(-13980), INT16_C(-30566), INT16_C(-12851),
                            INT16_C( 30608), INT16_C( 27665), INT16_C(   548), INT16_C(  7224),
                            INT16_C(-23312), INT16_C( -9410), INT16_C(  2838), INT16_C(-28448),
                            INT16_C( 30003), INT16_C(-15914), INT16_C(-27549), INT16_C(  6027),
                            INT16_C( 28687), INT16_C(-19881), INT16_C(  5735), INT16_C(  9519),
                            INT16_C( -3746), INT16_C(-25453), INT16_C(-16345), INT16_C(-27291)),
      simde_mm512_set_epi16(INT16_C(  4335), INT16_C( -8694), INT16_C( 20589), INT16_C( -2761),
                            INT16_C( -3216), INT16_C(-24783), INT16_C(-17777), INT16_C(  -501),
                            INT16_C( 25504), INT16_C( 26559), INT16_C( 27843), INT16_C( 31769),
                            INT16_C(-18807), INT16_C(  5762), INT16_C(-26736), INT16_C( 14349),
                            INT16_C(-15519), INT16_C(  4924), INT16_C(-19685), INT16_C( 31074),
                            INT16_C(-20201), INT16_C( -4452), INT16_C( 11125), INT16_C( 19762),
                            INT16_C(-31890), INT16_C(-20519), INT16_C(-27796), INT16_C(  4844),
                            INT16_C(  1980), INT16_C(-25222), INT16_C(-27366), INT16_C( 20455)),
      simde_mm512_set_epi16(INT16_C(    -4), INT16_C(     0), INT16_C(    -1), INT16_C(    -3),
                            INT16_C(     1), INT16_C(    -1), INT16_C(     0), INT16_C(   -43),
                            INT16_C(    -1), INT16_C(     0), INT16_C(    -1), INT16_C(     0),
                            INT16_C(    -1), INT16_C(     4), INT16_C(     0), INT16_C(     0),
                            INT16_C(     1), INT16_C(    -1), INT16_C(     0), INT16_C(     0),
                            INT16_C(    -1), INT16_C(     3), INT16_C(    -2), INT16_C(     0),
                            INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(     1),
                            INT16_C(    -1), INT16_C(     1), INT16_C(     0), INT16_C(    -1)) },
    { simde_mm512_set_epi16(INT16_C( 30542), INT16_C(-21686), INT16_C(-12987), INT16_C(-10637),
                            INT16_C( -1601), INT16_C(-28302), INT16_C( 15211), INT16_C(-14111),
                            INT16_C( 25976), INT16_C( 21242), INT16_C(-23929), INT16_C(-19059),
                            INT16_C(-25081), INT16_C(  5942), INT16_C(-21376), INT16_C(  4770),
                            INT16_C( -1129), INT16_C(-19990), INT16_C( 26476), INT16_C(-29290),
                            INT16_C(-16617), INT16_C(-24641), INT16_C( 13060), INT16_C(-26392),
                            INT16_C(-31122), INT16_C(  1166), INT16_C(-13169), INT16_C( 10959),
                            INT16_C(  3043), INT16_C(-24353), INT16_C(-25618), INT16_C(  3998)),
      simde_mm512_set_epi16(INT16_C(  8697), INT16_C(  4862), INT16_C(-26319), INT16_C(-11370),
                            INT16_C(  4314), INT16_C(-16926), INT16_C( 26882), INT16_C(  8784),
                            INT16_C(-23412), INT16_C(  6784), INT16_C( 27807), INT16_C( 29358),
                            INT16_C( 28774), INT16_C( -1248), INT16_C( 14871), INT16_C(  4639),
                            INT16_C( 17536), INT16_C( -3921), INT16_C(-31860), INT16_C( 18313),
                            INT16_C( 13025), INT16_C(-15494), INT16_C( -6838), INT16_C(-31563),
                            INT16_C( 10488), INT16_C( 29317), INT16_C(  5913), INT16_C( -5447),
                            INT16_C( 11124), INT16_C(-18588), INT16_C(-20055), INT16_C( 31068)),
      simde_mm512_set_epi16(INT16_C(     3), INT16_C(    -4), INT16_C(     0), INT16_C(     0),
                            INT16_C(     0), INT16_C(     1), INT16_C(     0), INT16_C(    -1),
                            INT16_C(    -1), INT16_C(     3), INT16_C(     0), INT16_C(     0),
                            INT16_C(     0), INT16_C(    -4), INT16_C(    -1), INT16_C(     1),
                            INT16_C(     0), INT16_C(     5), INT16_C(     0), INT16_C(    -1),
                            INT16_C(    -1), INT16_C(     1), INT16_C(    -1), INT16_C(     0),
                            INT16_C(    -2), INT16_C(     0), INT16_C(    -2), INT16_C(    -2),
                            INT16_C(     0), INT16_C(     1), INT16_C(     1), INT16_C(     0)) },
    { simde_mm512_set_epi16(INT16_C( 10506), INT16_C( 27276), INT16_C( 10689), INT16_C(  7669),
                            INT16_C( -9146), INT16_C(-17193), INT16_C(  7411), INT16_C(  5177),
                            INT16_C( 18940), INT16_C(-16405), INT16_C(  3246), INT16_C(  3104),
                            INT16_C( -7140), INT16_C( 31568), INT16_C( -2399), INT16_C(-28909),
                            INT16_C( 26564), INT16_C(-28507), INT16_C(  3797), INT16_C( -9359),
                            INT16_C(-12946), INT16_C( 18074), INT16_C( -6465), INT16_C(  3679),
                            INT16_C( 17483), INT16_C( -5905), INT16_C(  3591), INT16_C(-20227),
                            INT16_C( -6079), INT16_C( -1639), INT16_C(-29076), INT16_C( 29393)),
      simde_mm512_set_epi16(INT16_C( 11630), INT16_C(  9206), INT16_C(-15696), INT16_C(  3180),
                            INT16_C( 12868), INT16_C(-30976), INT16_C( -5774), INT16_C(-11992),
                            INT16_C(-18085), INT16_C( 32470), INT16_C( 17470), INT16_C(-31399),
                            INT16_C(  9368), INT16_C(  3571), INT16_C(  7161), INT16_C(-27278),
                            INT16_C(  9802), INT16_C( 20270), INT16_C(-19501), INT16_C( 19621),
                            INT16_C( 14613), INT16_C( -6394), INT16_C( -6716), INT16_C( -8239),
                            INT16_C(-25839), INT16_C( 28062), INT16_C( -8851), INT16_C(-12431),
                            INT16_C( -8955), INT16_C(  -676), INT16_C( 10256), INT16_C( 15625)),
      simde_mm512_set_epi16(INT16_C(     0), INT16_C(     2), INT16_C(     0), INT16_C(     2),
                            INT16_C(     0), INT16_C(     0), INT16_C(    -1), INT16_C(     0),
                            INT16_C(    -1), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                            INT16_C(     0), INT16_C(     8), INT16_C(     0), INT16_C(     1),
                            INT16_C(     2), INT16_C(    -1), INT16_C(     0), INT16_C(     0),
                            INT16_C(     0), INT16_C(    -2), INT16_C(     0), INT16_C(     0),
                            INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(     1),
                            INT16_C(     0), INT16_C(     2), INT16_C(    -2), INT16_C(     1)) },
    { simde_mm512_set_epi16(INT16_C( 14453), INT16_C(-27323), INT16_C( 14069), INT16_C(-15038),
                            INT16_C( 29890), INT16_C(-32496), INT16_C( -8033), INT16_C(  2034),
                            INT16_C( 28252), INT16_C(-12993), INT16_C(-12172), INT16_C( 21268),
                            INT16_C(-19693), INT16_C( -3590), INT16_C( -7723), INT16_C(-15496),
                            INT16_C( -5494), INT16_C( 10297), INT16_C( 10325), INT16_C( 32003),
                            INT16_C(-11357), INT16_C( 14609), INT16_C(-13537), INT16_C( 17128),
                            INT16_C(  6812), INT16_C( 32194), INT16_C(   287), INT16_C(  5824),
                            INT16_C( 13352), INT16_C(-19334), INT16_C(  8294), INT16_C(-20267)),
      simde_mm512_set_epi16(INT16_C(-10192), INT16_C(-26586), INT16_C( 32452), INT16_C(  4989),
                            INT16_C(-13693), INT16_C(-13838), INT16_C(  2151), INT16_C( 31183),
                            INT16_C(-12217), INT16_C( 28038), INT16_C( 27497), INT16_C(-25404),
                            INT16_C(-25184), INT16_C(-12134), INT16_C( 25347), INT16_C( -5075),
                            INT16_C( 19038), INT16_C(  9321), INT16_C(-20974), INT16_C( 22487),
                            INT16_C( -3253), INT16_C(-14033), INT16_C( 24624), INT16_C( 14772),
                            INT16_C( 16067), INT16_C(-16101), INT16_C( 12034), INT16_C( 11420),
                            INT16_C(-30652), INT16_C(-30195), INT16_C(-10496), INT16_C( 32407)),
      simde_mm512_set_epi16(INT16_C(    -1), INT16_C(     1), INT16_C(     0), INT16_C(    -3),
                            INT16_C(    -2), INT16_C(     2), INT16_C(    -3), INT16_C(     0),
                            INT16_C(    -2), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                            INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(     3),
                            INT16_C(     0), INT16_C(     1), INT16_C(     0), INT16_C(     1),
                            INT16_C(     3), INT16_C(    -1), INT16_C(     0), INT16_C(     1),
                            INT16_C(     0), INT16_C(    -1), INT16_C(     0), INT16_C(     0),
                            INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(     0)) },
    { simde_mm512_set_epi16(INT16_C(-12762), INT16_C(  -143), INT16_C( 24201), INT16_C( 27500),
                            INT16_C(-21606), INT16_C(-10954), INT16_C( 30460), INT16_C( 28331),
                            INT16_C(-22171), INT16_C(-30589), INT16_C( 16765), INT16_C(-17393),
                            INT16_C( 31673), INT16_C( 13306), INT16_C( -8624), INT16_C( -3653),
                            INT16_C(-23812), INT16_C(  2378), INT16_C( -6069), INT16_C( -8645),
                            INT16_C(  9750), INT16_C(  6252), INT16_C(-30407), INT16_C(-28082),
                            INT16_C(-14686), INT16_C( -5840), INT16_C( 24502), INT16_C( 12329),
                            INT16_C( -5959), INT16_C(-16932), INT16_C( -4867), INT16_C( 10388)),
      simde_mm512_set_epi16(INT16_C(-30203), INT16_C(-31292), INT16_C(  7054), INT16_C( 31766),
                            INT16_C(-23643), INT16_C( -7634), INT16_C( 23958), INT16_C(-19164),
                            INT16_C( 32358), INT16_C( 32485), INT16_C( -8137), INT16_C(  2854),
                            INT16_C(   443), INT16_C(  3757), INT16_C(-31602), INT16_C( 26770),
                            INT16_C(  1434), INT16_C(-26880), INT16_C(-13137), INT16_C(-25600),
                            INT16_C(  3310), INT16_C( 31739), INT16_C( 22782), INT16_C( 27721),
                            INT16_C(-28215), INT16_C( 10286), INT16_C( 11994), INT16_C(-23317),
                            INT16_C(-11843), INT16_C(  6466), INT16_C(  8900), INT16_C( 11867)),
      simde_mm512_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(     3), INT16_C(     0),
                            INT16_C(     0), INT16_C(     1), INT16_C(     1), INT16_C(    -1),
                            INT16_C(     0), INT16_C(     0), INT16_C(    -2), INT16_C(    -6),
                            INT16_C(    71), INT16_C(     3), INT16_C(     0), INT16_C(     0),
                            INT16_C(   -16), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                            INT16_C(     2), INT16_C(     0), INT16_C(    -1), INT16_C(    -1),
                            INT16_C(     0), INT16_C(     0), INT16_C(     2), INT16_C(     0),
                            INT16_C(     0), INT16_C(    -2), INT16_C(     0), INT16_C(     0)) },
    { simde_mm512_set_epi16(INT16_C(-29408), INT16_C(  7369), INT16_C( -5051), INT16_C(  7942),
                            INT16_C( 18019), INT16_C(-25065), INT16_C( -8302), INT16_C( 17011),
                            INT16_C(  2762), INT16_C( 27559), INT16_C( 18647), INT16_C( 22035),
                            INT16_C(-10618), INT16_C( -3223), INT16_C( 25352), INT16_C(-32696),
                            INT16_C( -1859), INT16_C(-20090), INT16_C( 18297), INT16_C(-27701),
                            INT16_C(-31478), INT16_C(-13300), INT16_C(-15493), INT16_C(-16792),
                            INT16_C(-23954), INT16_C(-14239), INT16_C(-15716), INT16_C( 12103),
                            INT16_C(-30330), INT16_C( -2111), INT16_C(-26781), INT16_C( 25851)),
      simde_mm512_set_epi16(INT16_C( 11252), INT16_C(-25669), INT16_C(-31001), INT16_C( 13518),
                            INT16_C( 30845), INT16_C(-14200), INT16_C(-30880), INT16_C( 22795),
                            INT16_C(-15552), INT16_C( -1554), INT16_C( 29162), INT16_C( -8371),
                            INT16_C(  5731), INT16_C( 22086), INT16_C(  7870), INT16_C(-26229),
                            INT16_C( 19406), INT16_C(-22832), INT16_C(-14386), INT16_C( 22375),
                            INT16_C( -8274), INT16_C( -9174), INT16_C(-24184), INT16_C( 24847),
                            INT16_C( 26808), INT16_C( -2235), INT16_C(  4293), INT16_C(-30072),
                            INT16_C( 23713), INT16_C( 20910), INT16_C(  6378), INT16_C(-18450)),
      simde_mm512_set_epi16(INT16_C(    -2), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                            INT16_C(     0), INT16_C(     1), INT16_C(     0), INT16_C(     0),
                            INT16_C(     0), INT16_C(   -17), INT16_C(     0), INT16_C(    -2),
                            INT16_C(    -1), INT16_C(     0), INT16_C(     3), INT16_C(     1),
                            INT16_C(     0), INT16_C(     0), INT16_C(    -1), INT16_C(    -1),
                            INT16_C(     3), INT16_C(     1), INT16_C(     0), INT16_C(     0),
                            INT16_C(     0), INT16_C(     6), INT16_C(    -3), INT16_C(     0),
                            INT16_C(    -1), INT16_C(     0), INT16_C(    -4), INT16_C(    -1)) },
    { simde_mm512_set_epi16(INT16_C( -8644), INT16_C(  4438), INT16_C(  1025), INT16_C(-26642),
                            INT16_C( 18378), INT16_C(-13976), INT16_C( 21110), INT16_C( 14955),
                            INT16_C(  2525), INT16_C(-19773), INT16_C( 28133), INT16_C(-32693),
                            INT16_C( 12259), INT16_C(-21141), INT16_C(-27294), INT16_C( 16198),
                            INT16_C( -2640), INT16_C( 31144), INT16_C(-15827), INT16_C( 20747),
                            INT16_C(-19791), INT16_C( 30374), INT16_C( -9055), INT16_C(-20334),
                            INT16_C( 28339), INT16_C( 29800), INT16_C( 32312), INT16_C(-19316),
                            INT16_C(-15043), INT16_C(-27434), INT16_C( 29424), INT16_C(-25521)),
      simde_mm512_set_epi16(INT16_C(-24272), INT16_C( -9025), INT16_C(-17538), INT16_C(-13789),
                            INT16_C(  3646), INT16_C( 17578), INT16_C( -9614), INT16_C(-11054),
                            INT16_C( 23757), INT16_C( -5736), INT16_C(  8067), INT16_C( 10531),
                            INT16_C(-24488), INT16_C( 16639), INT16_C(-22179), INT16_C( -8704),
                            INT16_C(  -927), INT16_C(-31517), INT16_C( 10091), INT16_C( 19448),
                            INT16_C( 12069), INT16_C(  8742), INT16_C( 16653), INT16_C( 31958),
                            INT16_C(-18440), INT16_C(-30513), INT16_C( -3426), INT16_C( -7330),
                            INT16_C( 24804), INT16_C( 18228), INT16_C( 16072), INT16_C(-15326)),
      simde_mm512_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(     1),
                            INT16_C(     5), INT16_C(     0), INT16_C(    -2), INT16_C(    -1),
                            INT16_C(     0), INT16_C(     3), INT16_C(     3), INT16_C(    -3),
                            INT16_C(     0), INT16_C(    -1), INT16_C(     1), INT16_C(    -1),
                            INT16_C(     2), INT16_C(     0), INT16_C(    -1), INT16_C(     1),
                            INT16_C(    -1), INT16_C(     3), INT16_C(     0), INT16_C(     0),
                            INT16_C(    -1), INT16_C(     0), INT16_C(    -9), INT16_C(     2),
                            INT16_C(     0), INT16_C(    -1), INT16_C(     1), INT16_C(     1)) },
    { simde_mm512_set_epi16(INT16_C( 23232), INT16_C(-29257), INT16_C(  1254), INT16_C( -9317),
                            INT16_C(-20336), INT16_C( 10081), INT16_C( 18681), INT16_C( 12677),
                            INT16_C( 17973), INT16_C(-10276), INT16_C(-23503), INT16_C( 18772),
                            INT16_C(  8312), INT16_C( 15138), INT16_C( -9415), INT16_C(-23183),
                            INT16_C(  4065), INT16_C( 14928), INT16_C( -9505), INT16_C( -3213),
                            INT16_C( -8135), INT16_C(-17864), INT16_C(-23451), INT16_C( -2372),
                            INT16_C( 14548), INT16_C(-10992), INT16_C(  6282), INT16_C(-22066),
                            INT16_C(-11858), INT16_C( 14867), INT16_C( -6173), INT16_C( 24146)),
      simde_mm512_set_epi16(INT16_C(-20244), INT16_C( 14874), INT16_C(  7829), INT16_C( 32218),
                            INT16_C( 17818), INT16_C(   309), INT16_C( 27668), INT16_C(  9211),
                            INT16_C( 15166), INT16_C(  4076), INT16_C( 28109), INT16_C(-30601),
                            INT16_C(  4803), INT16_C(-19074), INT16_C(-23287), INT16_C(-27917),
                            INT16_C(  7634), INT16_C(-13255), INT16_C( 14290), INT16_C( -8590),
                            INT16_C(-11602), INT16_C(  9361), INT16_C(-18559), INT16_C(  3976),
                            INT16_C( 20763), INT16_C( 17266), INT16_C(  8709), INT16_C(-30498),
                            INT16_C( 31994), INT16_C(-17983), INT16_C( 25233), INT16_C( 29991)),
      simde_mm512_set_epi16(INT16_C(    -1), INT16_C(    -1), INT16_C(     0), INT16_C(     0),
                            INT16_C(    -1), INT16_C(    32), INT16_C(     0), INT16_C(     1),
                            INT16_C(     1), INT16_C(    -2), INT16_C(     0), INT16_C(     0),
                            INT16_C(     1), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                            INT16_C(     0), INT16_C(    -1), INT16_C(     0), INT16_C(     0),
                            INT16_C(     0), INT16_C(    -1), INT16_C(     1), INT16_C(     0),
                            INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                            INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(     0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_div_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m512i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_div_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512i a;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {
    { simde_mm512_set_epi32(INT32_C(-1425964510), INT32_C( 1884851068), INT32_C( -245085200), INT32_C(  312441627),
                            INT32_C( 1361020823), INT32_C( -269027644), INT32_C( 2046290516), INT32_C(  253262419),
                            INT32_C(-1435031175), INT32_C( -983397284), INT32_C( 1158205006), INT32_C( 2142968427),
                            INT32_C( -610621785), INT32_C(-1874018384), INT32_C(  408084487), INT32_C(  314643093)),
      simde_mm512_set_epi32(INT32_C(-1816447538), INT32_C( 1352799684), INT32_C(  437452333), INT32_C(-2106809533),
                            INT32_C(  850823800), INT32_C(-1580883911), INT32_C(-2115707304), INT32_C( 1577531711),
                            INT32_C(  801246884), INT32_C(   59025302), INT32_C(  905783489), INT32_C(-1645941779),
                            INT32_C(  962943312), INT32_C( 2128170875), INT32_C(-1348448230), INT32_C( -975134432)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(          1), INT32_C(          0), INT32_C(          0),
                            INT32_C(          1), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(         -1), INT32_C(        -16), INT32_C(          1), INT32_C(         -1),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
    { simde_mm512_set_epi32(INT32_C( 1427225802), INT32_C(-1035302594), INT32_C( -199744603), INT32_C( 1376388625),
                            INT32_C(-2114897409), INT32_C( 1679349706), INT32_C(-1031333846), INT32_C(-1198347443),
                            INT32_C( -637748341), INT32_C( 1314591131), INT32_C(  282479090), INT32_C( 1660196054),
                            INT32_C(-1167126507), INT32_C(-1998854068), INT32_C(  933881032), INT32_C( -624384653)),
      simde_mm512_set_epi32(INT32_C( 1612321322), INT32_C( 2051698478), INT32_C( 1596883036), INT32_C(-1369467325),
                            INT32_C( 1851004364), INT32_C( 1092388812), INT32_C(  828772877), INT32_C( -259189725),
                            INT32_C( -849691191), INT32_C(-1191458488), INT32_C(  801339023), INT32_C( -104328386),
                            INT32_C(  757083857), INT32_C(-1236967236), INT32_C( -850146114), INT32_C( 1258625824)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(         -1),
                            INT32_C(         -1), INT32_C(          1), INT32_C(         -1), INT32_C(          4),
                            INT32_C(          0), INT32_C(         -1), INT32_C(          0), INT32_C(        -15),
                            INT32_C(         -1), INT32_C(          1), INT32_C(         -1), INT32_C(          0)) },
    { simde_mm512_set_epi32(INT32_C(  237418199), INT32_C(  -70579339), INT32_C(-2042257710), INT32_C( 1462546998),
                            INT32_C( -202189538), INT32_C(-1353367648), INT32_C(  304511606), INT32_C( -539003093),
                            INT32_C( 1923205305), INT32_C(  464427515), INT32_C( -694421636), INT32_C(-1729085762),
                            INT32_C( 1377800186), INT32_C( -626233146), INT32_C(-2090091895), INT32_C( 1314335058)),
      simde_mm512_set_epi32(INT32_C(   38009422), INT32_C( -855531694), INT32_C( 1096529400), INT32_C(  740723389),
                            INT32_C( -703601695), INT32_C(-1082310854), INT32_C(  120520136), INT32_C(  494300544),
                            INT32_C(-1280011607), INT32_C(-1943894617), INT32_C( -321878744), INT32_C( -690430536),
                            INT32_C( 1135419008), INT32_C( 1818004981), INT32_C( 1471877533), INT32_C(  559240384)),
      simde_mm512_set_epi32(INT32_C(          6), INT32_C(          0), INT32_C(         -1), INT32_C(          1),
                            INT32_C(          0), INT32_C(          1), INT32_C(          2), INT32_C(         -1),
                            INT32_C(         -1), INT32_C(          0), INT32_C(          2), INT32_C(          2),
                            INT32_C(          1), INT32_C(          0), INT32_C(         -1), INT32_C(          2)) },
    { simde_mm512_set_epi32(INT32_C(-1724745069), INT32_C( 1135206576), INT32_C( 1179583658), INT32_C(-1966673560),
                            INT32_C(  876279100), INT32_C( -587502732), INT32_C( -149418425), INT32_C( -921830900),
                            INT32_C(   17215575), INT32_C(-1719497158), INT32_C(-1349196793), INT32_C( 1245762398),
                            INT32_C(  813297065), INT32_C( -835921648), INT32_C(-1975778091), INT32_C( 2110087211)),
      simde_mm512_set_epi32(INT32_C(-1421142882), INT32_C( -720107087), INT32_C( -533473336), INT32_C(-1235553858),
                            INT32_C( 1997884077), INT32_C(-1507361050), INT32_C(   21786729), INT32_C(  743816821),
                            INT32_C(  150690827), INT32_C(-1210873139), INT32_C( 1036977320), INT32_C( -399295069),
                            INT32_C(-1569884506), INT32_C( -616191901), INT32_C(-1839631465), INT32_C( -912247900)),
      simde_mm512_set_epi32(INT32_C(          1), INT32_C(         -1), INT32_C(         -2), INT32_C(          1),
                            INT32_C(          0), INT32_C(          0), INT32_C(         -6), INT32_C(         -1),
                            INT32_C(          0), INT32_C(          1), INT32_C(         -1), INT32_C(         -3),
                            INT32_C(          0), INT32_C(          1), INT32_C(          1), INT32_C(         -2)) },
    { simde_mm512_set_epi32(INT32_C( -788754092), INT32_C( 1871593252), INT32_C(-1494005905), INT32_C(-1673341020),
                            INT32_C( -802349852), INT32_C( 1483795222), INT32_C( -482009835), INT32_C(  -91245467),
                            INT32_C( 1580169915), INT32_C(  692091070), INT32_C( 1863695169), INT32_C( -863865867),
                            INT32_C(-1394651654), INT32_C( -860864123), INT32_C(  684761994), INT32_C(-1721896503)),
      simde_mm512_set_epi32(INT32_C(-1337054377), INT32_C(   66234694), INT32_C(-1856118156), INT32_C(-1127800230),
                            INT32_C(  814009506), INT32_C(-2034345199), INT32_C( 1765405247), INT32_C(-1048066647),
                            INT32_C( -423083536), INT32_C(-1848382006), INT32_C( -152706477), INT32_C(-1375856509),
                            INT32_C(  -23675804), INT32_C( -242644348), INT32_C( 1836148713), INT32_C(  -17324905)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(         28), INT32_C(          0), INT32_C(          1),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(         -3), INT32_C(          0), INT32_C(        -12), INT32_C(          0),
                            INT32_C(         58), INT32_C(          3), INT32_C(          0), INT32_C(         99)) },
    { simde_mm512_set_epi32(INT32_C( -463247298), INT32_C( -951467140), INT32_C( 1433027324), INT32_C(-1349535490),
                            INT32_C( -916446608), INT32_C(-1679952824), INT32_C(  515026148), INT32_C(  -79374441),
                            INT32_C(-1055204414), INT32_C( 1214763982), INT32_C( -351626877), INT32_C(  427209663),
                            INT32_C( 1651021910), INT32_C( -181051643), INT32_C(-1481830173), INT32_C( 1285378207)),
      simde_mm512_set_epi32(INT32_C( -895026020), INT32_C(-2124493776), INT32_C( -806312731), INT32_C(  721610054),
                            INT32_C(  677519448), INT32_C( 1470235459), INT32_C(-2123699180), INT32_C(  883454038),
                            INT32_C(-2020088518), INT32_C( -300465294), INT32_C( 1493254397), INT32_C( 2062995345),
                            INT32_C(  -10095941), INT32_C(-1400374264), INT32_C( 1068728589), INT32_C(  234142625)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(         -1), INT32_C(         -1),
                            INT32_C(         -1), INT32_C(         -1), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(         -4), INT32_C(          0), INT32_C(          0),
                            INT32_C(       -163), INT32_C(          0), INT32_C(         -1), INT32_C(          5)) },
    { simde_mm512_set_epi32(INT32_C( -939190848), INT32_C(-2083825761), INT32_C( 2014997186), INT32_C(  790185633),
                            INT32_C(-1507225536), INT32_C( -384122450), INT32_C(-1588213257), INT32_C(-1040817544),
                            INT32_C( 1965628193), INT32_C(-2067530457), INT32_C( 1204204418), INT32_C(  -39160501),
                            INT32_C( -605764870), INT32_C(  561973657), INT32_C( 1912174450), INT32_C( 1415728252)),
      simde_mm512_set_epi32(INT32_C( -927506034), INT32_C(  155586444), INT32_C( -406884871), INT32_C( -252994257),
                            INT32_C( 1219028873), INT32_C(-1972688074), INT32_C( -597390303), INT32_C(  291669377),
                            INT32_C( -695882735), INT32_C(  879590202), INT32_C( 1348714758), INT32_C( 1712617745),
                            INT32_C( -236530514), INT32_C( 1880792230), INT32_C( 1810070042), INT32_C(-1599785869)),
      simde_mm512_set_epi32(INT32_C(          1), INT32_C(        -13), INT32_C(         -4), INT32_C(         -3),
                            INT32_C(         -1), INT32_C(          0), INT32_C(          2), INT32_C(         -3),
                            INT32_C(         -2), INT32_C(         -2), INT32_C(          0), INT32_C(          0),
                            INT32_C(          2), INT32_C(          0), INT32_C(          1), INT32_C(          0)) },
    { simde_mm512_set_epi32(INT32_C(-1601700614), INT32_C( 1985924496), INT32_C( -342633815), INT32_C(-2007999861),
                            INT32_C(  297828713), INT32_C( 1383645848), INT32_C(-2056044415), INT32_C(  373512753),
                            INT32_C(  -26545593), INT32_C( -328575199), INT32_C( -462276628), INT32_C( 1976153041),
                            INT32_C( 1430984961), INT32_C(-1934079238), INT32_C(  399344654), INT32_C( 1569206763)),
      simde_mm512_set_epi32(INT32_C(  102595444), INT32_C(  731375272), INT32_C(-1673993680), INT32_C( -406822977),
                            INT32_C( -578959028), INT32_C( 1173139127), INT32_C(-1295304556), INT32_C(  955166905),
                            INT32_C(  270270084), INT32_C(  134608446), INT32_C( -519669996), INT32_C( -265658570),
                            INT32_C(-1584344142), INT32_C( 1279036686), INT32_C(-1076842770), INT32_C(  -44502324)),
      simde_mm512_set_epi32(INT32_C(        -15), INT32_C(          2), INT32_C(          0), INT32_C(          4),
                            INT32_C(          0), INT32_C(          1), INT32_C(          1), INT32_C(          0),
                            INT32_C(          0), INT32_C(         -2), INT32_C(          0), INT32_C(         -7),
                            INT32_C(          0), INT32_C(         -1), INT32_C(          0), INT32_C(        -35)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_div_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m512i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_mask_div_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512i src;
    simde__mmask16 k;
    simde__m512i a;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {
    { simde_mm512_set_epi32(INT32_C(  691121094), INT32_C(  674034227), INT32_C(-1965434887), INT32_C( -920286947),
                            INT32_C( -374673026), INT32_C(-1240805178), INT32_C( 1568850865), INT32_C(-1142977539),
                            INT32_C(-1079516608), INT32_C( -708153743), INT32_C( 1508722402), INT32_C(-2074345640),
                            INT32_C( 1747596798), INT32_C(-2063703989), INT32_C(  527472553), INT32_C(-1403096998)),
      UINT16_C(63371),
      simde_mm512_set_epi32(INT32_C( -341007878), INT32_C(-1764810870), INT32_C( 1179683687), INT32_C(-1646326602),
                            INT32_C( -671967289), INT32_C(-1586327268), INT32_C( 1691051285), INT32_C(   50347892),
                            INT32_C(  728425428), INT32_C( 1192263444), INT32_C(-2086343723), INT32_C( 1322777130),
                            INT32_C(  163989560), INT32_C( 1492341726), INT32_C(  298608154), INT32_C( 1250819173)),
      simde_mm512_set_epi32(INT32_C(-1291033589), INT32_C( 1314482530), INT32_C(-1297250617), INT32_C( -739008036),
                            INT32_C(-1419039999), INT32_C(-1004264650), INT32_C( 1580565751), INT32_C( -471064457),
                            INT32_C( 2081361826), INT32_C(  493161721), INT32_C(-1195115819), INT32_C(  894221337),
                            INT32_C(-1330460172), INT32_C(  492373082), INT32_C(  -13096811), INT32_C(-2087181083)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(         -1), INT32_C(          0), INT32_C(          2),
                            INT32_C( -374673026), INT32_C(          1), INT32_C(          1), INT32_C(          0),
                            INT32_C(          0), INT32_C( -708153743), INT32_C( 1508722402), INT32_C(-2074345640),
                            INT32_C(          0), INT32_C(-2063703989), INT32_C(        -22), INT32_C(          0)) },
    { simde_mm512_set_epi32(INT32_C( 1779168063), INT32_C(-1138893231), INT32_C( -687161637), INT32_C( 1828175063),
                            INT32_C( -389420023), INT32_C( -193211433), INT32_C( -857989172), INT32_C( -448329300),
                            INT32_C(-1601364212), INT32_C( 1710148738), INT32_C( 1974123080), INT32_C(-1424367196),
                            INT32_C(  118588227), INT32_C(  542053192), INT32_C(  499863549), INT32_C(  957375358)),
      UINT16_C(36797),
      simde_mm512_set_epi32(INT32_C(-1153303869), INT32_C(  562234020), INT32_C( 1763100483), INT32_C( -518004559),
                            INT32_C(-1450358898), INT32_C(-1409866198), INT32_C(  269910347), INT32_C(  433971495),
                            INT32_C( 1441956227), INT32_C( 1018271575), INT32_C( 1734496959), INT32_C(  380846712),
                            INT32_C( -941967689), INT32_C( -739443621), INT32_C( 1995198557), INT32_C( -980655097)),
      simde_mm512_set_epi32(INT32_C(-2088961787), INT32_C( 1943141679), INT32_C( -665465241), INT32_C( -342195833),
                            INT32_C( 2102184556), INT32_C(  877111492), INT32_C( 1183491905), INT32_C( -576610979),
                            INT32_C(-1061316197), INT32_C( -808097400), INT32_C( -362876916), INT32_C(-1845390533),
                            INT32_C(  -48621016), INT32_C(  201516689), INT32_C(-1435930720), INT32_C(-1932876068)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(-1138893231), INT32_C( -687161637), INT32_C( 1828175063),
                            INT32_C(          0), INT32_C(         -1), INT32_C(          0), INT32_C(          0),
                            INT32_C(         -1), INT32_C( 1710148738), INT32_C(         -4), INT32_C(          0),
                            INT32_C(         19), INT32_C(         -3), INT32_C(  499863549), INT32_C(          0)) },
    { simde_mm512_set_epi32(INT32_C( -179829877), INT32_C(  651362699), INT32_C(  495870887), INT32_C( -382126427),
                            INT32_C(  915244711), INT32_C(    5081424), INT32_C( 1422501384), INT32_C( -163979724),
                            INT32_C(-1516900265), INT32_C(  497965579), INT32_C(  910061584), INT32_C( 2002226944),
                            INT32_C( -621963189), INT32_C(  -48343218), INT32_C(  523093293), INT32_C(-1235205724)),
      UINT16_C(46902),
      simde_mm512_set_epi32(INT32_C( -220620904), INT32_C( 1398655610), INT32_C( 1722520923), INT32_C( 1206471293),
                            INT32_C( 1374915518), INT32_C(  531653117), INT32_C( 2075187308), INT32_C( -144618549),
                            INT32_C(-2131865715), INT32_C( 1444783055), INT32_C( 1878625233), INT32_C( 1755684145),
                            INT32_C(-2061726371), INT32_C(-1050443653), INT32_C(-1299940555), INT32_C(-2116696545)),
      simde_mm512_set_epi32(INT32_C(-1106093489), INT32_C( 1982658188), INT32_C(  863153207), INT32_C(-1637276628),
                            INT32_C(  448681074), INT32_C( 1334667053), INT32_C(  502667641), INT32_C(  855395764),
                            INT32_C(-1672092948), INT32_C(  808531712), INT32_C(  454488139), INT32_C(  123547093),
                            INT32_C(  483090439), INT32_C(-1126329757), INT32_C(-1201220189), INT32_C( -136050629)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(  651362699), INT32_C(          1), INT32_C(          0),
                            INT32_C(  915244711), INT32_C(          0), INT32_C(          4), INT32_C(          0),
                            INT32_C(-1516900265), INT32_C(  497965579), INT32_C(          4), INT32_C(         14),
                            INT32_C( -621963189), INT32_C(          0), INT32_C(          1), INT32_C(-1235205724)) },
    { simde_mm512_set_epi32(INT32_C( 2113970745), INT32_C( -182128842), INT32_C(  564512596), INT32_C(  604721400),
                            INT32_C( 1471174399), INT32_C(-1803940708), INT32_C(-1765392929), INT32_C(  298473775),
                            INT32_C(-1404600737), INT32_C(-1231334921), INT32_C( -238983338), INT32_C( -145797796),
                            INT32_C( -181019162), INT32_C(-1910480170), INT32_C(-1860760170), INT32_C( -371855625)),
      UINT16_C(38914),
      simde_mm512_set_epi32(INT32_C( 1533151625), INT32_C( 2122196136), INT32_C( 1690360675), INT32_C( 1484935627),
                            INT32_C( 1463758672), INT32_C(  602211615), INT32_C( -464964305), INT32_C(-1430226195),
                            INT32_C(  797104998), INT32_C(-1557543977), INT32_C( -952737410), INT32_C(  178625368),
                            INT32_C(-1203806300), INT32_C( 1095216728), INT32_C(-1215405554), INT32_C(  430790402)),
      simde_mm512_set_epi32(INT32_C( -251141702), INT32_C( 1274901810), INT32_C(  413860084), INT32_C(  550494320),
                            INT32_C( 1997049765), INT32_C(  505563651), INT32_C(  463125220), INT32_C( -451213519),
                            INT32_C(-1948793453), INT32_C(-2137102362), INT32_C(-1703809327), INT32_C(  389679318),
                            INT32_C( -355192167), INT32_C(-1801602389), INT32_C( 2006619059), INT32_C( -903558132)),
      simde_mm512_set_epi32(INT32_C(         -6), INT32_C( -182128842), INT32_C(  564512596), INT32_C(          2),
                            INT32_C(          0), INT32_C(-1803940708), INT32_C(-1765392929), INT32_C(  298473775),
                            INT32_C(-1404600737), INT32_C(-1231334921), INT32_C( -238983338), INT32_C( -145797796),
                            INT32_C( -181019162), INT32_C(-1910480170), INT32_C(          0), INT32_C( -371855625)) },
    { simde_mm512_set_epi32(INT32_C( 1572579389), INT32_C( -783078337), INT32_C(-1895621282), INT32_C( 1967093325),
                            INT32_C(  908815803), INT32_C(-1975591270), INT32_C( 2065037155), INT32_C(  623932649),
                            INT32_C( 1610322797), INT32_C( -842122991), INT32_C( 2031682359), INT32_C(-1300130353),
                            INT32_C(-1950048210), INT32_C(  238137788), INT32_C( 1978166020), INT32_C(   76768592)),
      UINT16_C(  883),
      simde_mm512_set_epi32(INT32_C(-1010119490), INT32_C( -410070063), INT32_C( 2094036024), INT32_C(-1838133114),
                            INT32_C(   69201629), INT32_C( 1228958503), INT32_C( -775379327), INT32_C(-1485462767),
                            INT32_C(-1179177847), INT32_C( 1767270276), INT32_C(  490610321), INT32_C( 1164436618),
                            INT32_C(-1920297499), INT32_C( -690964678), INT32_C( -880248267), INT32_C(-2005634277)),
      simde_mm512_set_epi32(INT32_C(-1911659531), INT32_C(  143428987), INT32_C( -610024215), INT32_C(  582607980),
                            INT32_C( 1609326889), INT32_C( 1245407235), INT32_C( -119962198), INT32_C(-1932052969),
                            INT32_C(-1370414254), INT32_C(-1925960308), INT32_C( 2119408419), INT32_C(-1203088886),
                            INT32_C( -316530353), INT32_C( 1708684203), INT32_C( 1202455481), INT32_C(-2107221827)),
      simde_mm512_set_epi32(INT32_C( 1572579389), INT32_C( -783078337), INT32_C(-1895621282), INT32_C( 1967093325),
                            INT32_C(  908815803), INT32_C(-1975591270), INT32_C(          6), INT32_C(          0),
                            INT32_C( 1610322797), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(-1950048210), INT32_C(  238137788), INT32_C(          0), INT32_C(          0)) },
    { simde_mm512_set_epi32(INT32_C( 2117071873), INT32_C(-1437889529), INT32_C( -376074104), INT32_C( 1087893388),
                            INT32_C( -443183285), INT32_C( -380695552), INT32_C(  565328458), INT32_C(  -93024748),
                            INT32_C( 1480532604), INT32_C(  -97460760), INT32_C( -582247600), INT32_C( -374749470),
                            INT32_C( 1394313506), INT32_C(  394553965), INT32_C(-2016714120), INT32_C( 1697927724)),
      UINT16_C(12254),
      simde_mm512_set_epi32(INT32_C(   56443211), INT32_C(-2036514643), INT32_C( -510270824), INT32_C( 1139427205),
                            INT32_C( 1090384090), INT32_C(-1905231405), INT32_C(-2079359983), INT32_C( -477294891),
                            INT32_C( -673197028), INT32_C( 2071747620), INT32_C( -442789099), INT32_C( -601334711),
                            INT32_C(  319530416), INT32_C(-2115012481), INT32_C( -501730903), INT32_C(  340519338)),
      simde_mm512_set_epi32(INT32_C( 1219537084), INT32_C( 1349635715), INT32_C(  732887738), INT32_C(-1728641921),
                            INT32_C(-1388433411), INT32_C( 1765754685), INT32_C(-1574983663), INT32_C(  846129112),
                            INT32_C( 1578410935), INT32_C(-1659872458), INT32_C( 1045536663), INT32_C(  957117985),
                            INT32_C(-1265958651), INT32_C( 1309498779), INT32_C(-1001015299), INT32_C( 1022360677)),
      simde_mm512_set_epi32(INT32_C( 2117071873), INT32_C(-1437889529), INT32_C(          0), INT32_C( 1087893388),
                            INT32_C(          0), INT32_C(         -1), INT32_C(          1), INT32_C(          0),
                            INT32_C(          0), INT32_C(         -1), INT32_C( -582247600), INT32_C(          0),
                            INT32_C(          0), INT32_C(         -1), INT32_C(          0), INT32_C( 1697927724)) },
    { simde_mm512_set_epi32(INT32_C( -304885978), INT32_C(  991545752), INT32_C( -143034937), INT32_C(  843112042),
                            INT32_C( -227554783), INT32_C( 2124182542), INT32_C(-1526246088), INT32_C(-1991977382),
                            INT32_C( 1224533822), INT32_C( -819361196), INT32_C( -684010252), INT32_C(-1738921185),
                            INT32_C(-1259570772), INT32_C( -691865929), INT32_C( -973523371), INT32_C(   45581573)),
      UINT16_C(42669),
      simde_mm512_set_epi32(INT32_C( -156799603), INT32_C(-1073012339), INT32_C(-2130532125), INT32_C(  397240391),
                            INT32_C(  200936922), INT32_C(-1030980309), INT32_C(-1758363174), INT32_C( -665586367),
                            INT32_C(  453331046), INT32_C( 1704580573), INT32_C( 1606190487), INT32_C(-1085658047),
                            INT32_C(-1335469644), INT32_C( -368070561), INT32_C(-1419559633), INT32_C( 2069966669)),
      simde_mm512_set_epi32(INT32_C( 1379668640), INT32_C(   66581512), INT32_C( -557301797), INT32_C(  304428974),
                            INT32_C(-1608262788), INT32_C(  532978979), INT32_C(  946958552), INT32_C(-1911324669),
                            INT32_C(-2118093156), INT32_C(  283691898), INT32_C( -446072631), INT32_C( -458781294),
                            INT32_C( 1951055651), INT32_C(  765387914), INT32_C(  822559116), INT32_C(    7445617)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(  991545752), INT32_C(          3), INT32_C(  843112042),
                            INT32_C( -227554783), INT32_C(         -1), INT32_C(         -1), INT32_C(-1991977382),
                            INT32_C(          0), INT32_C( -819361196), INT32_C(         -3), INT32_C(-1738921185),
                            INT32_C(          0), INT32_C(          0), INT32_C( -973523371), INT32_C(        278)) },
    { simde_mm512_set_epi32(INT32_C(-1981938926), INT32_C(  869237081), INT32_C( -190053534), INT32_C(-1469275330),
                            INT32_C( -717100794), INT32_C(-1303072888), INT32_C(-2122918671), INT32_C( 1617119933),
                            INT32_C( 1521363431), INT32_C(  553638116), INT32_C( 1036201367), INT32_C(-1187933851),
                            INT32_C( -412155886), INT32_C( -760582943), INT32_C( -423751457), INT32_C( 1273589632)),
      UINT16_C(35103),
      simde_mm512_set_epi32(INT32_C(-1836595644), INT32_C(  260676470), INT32_C( 1724614860), INT32_C( -144514633),
                            INT32_C( -478630580), INT32_C(-2086755061), INT32_C(  932145867), INT32_C(-1862372735),
                            INT32_C( 1756892633), INT32_C(  382632965), INT32_C( 1295078740), INT32_C( -995802034),
                            INT32_C(  152308919), INT32_C( -351555508), INT32_C(   31813624), INT32_C(  807463845)),
      simde_mm512_set_epi32(INT32_C(  615301803), INT32_C(  382786341), INT32_C( 1852603705), INT32_C( 1998007730),
                            INT32_C(  231325888), INT32_C( 1842039329), INT32_C(  968682756), INT32_C(  316335394),
                            INT32_C(-2071382094), INT32_C( -803185337), INT32_C(-2126995500), INT32_C( 1587647099),
                            INT32_C(-1328358584), INT32_C(  320339033), INT32_C(  282380179), INT32_C( -108102092)),
      simde_mm512_set_epi32(INT32_C(         -2), INT32_C(  869237081), INT32_C( -190053534), INT32_C(-1469275330),
                            INT32_C(         -2), INT32_C(-1303072888), INT32_C(-2122918671), INT32_C(         -5),
                            INT32_C( 1521363431), INT32_C(  553638116), INT32_C( 1036201367), INT32_C(          0),
                            INT32_C(          0), INT32_C(         -1), INT32_C(          0), INT32_C(         -7)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_mask_div_epi32(test_vec[i].src, test_vec[i].k, test_vec[i].a, test_vec[i].b);
    simde_assert_m512i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_div_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512i a;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {
    { simde_mm512_set_epi64(INT64_C(-7120494377185439159), INT64_C( 5095015079852768951),
                            INT64_C( -719755322986504865), INT64_C( 1195398499335632561),
                            INT64_C( 4232475372952240435), INT64_C(-1117570177728981140),
                            INT64_C(-4721763859644106046), INT64_C( 6636524825657073074)),
      simde_mm512_set_epi64(INT64_C( 6283111750805844985), INT64_C(-7772496718970349305),
                            INT64_C(-6967007030435791671), INT64_C( 2761331052478409707),
                            INT64_C(-5439727342880208313), INT64_C(-6280010522852202514),
                            INT64_C(-2361957704355445009), INT64_C(-3413538286934776973)),
      simde_mm512_set_epi64(INT64_C(                  -1), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                   1), INT64_C(                  -1)) },
    { simde_mm512_set_epi64(INT64_C( 7047516970419020428), INT64_C( 2488576598769637001),
                            INT64_C( 4233591199077735008), INT64_C( 1735409980007662056),
                            INT64_C(-2964306467966319268), INT64_C(-6472988581173317799),
                            INT64_C( 1870256929123231698), INT64_C(-5453281473672019922)),
      simde_mm512_set_epi64(INT64_C(-6026337221937727695), INT64_C( 8654798725117969005),
                            INT64_C(  743584473088107844), INT64_C( 5114866458456107677),
                            INT64_C( 1917095392115883075), INT64_C( 8815346252210924017),
                            INT64_C(-1666651333186431127), INT64_C( 4973081304470687258)),
      simde_mm512_set_epi64(INT64_C(                  -1), INT64_C(                   0),
                            INT64_C(                   5), INT64_C(                   0),
                            INT64_C(                  -1), INT64_C(                   0),
                            INT64_C(                  -1), INT64_C(                  -1)) },
    { simde_mm512_set_epi64(INT64_C(-1433819957247000466), INT64_C(-7270540428235491436),
                            INT64_C( 3506767658669433751), INT64_C(-6269164040512613371),
                            INT64_C(-2703740818469134807), INT64_C( 3442758576787517783),
                            INT64_C(-4507715808807193748), INT64_C( 4997387685805642122)),
      simde_mm512_set_epi64(INT64_C(-3375611624029359751), INT64_C(  155579560497872257),
                            INT64_C( 4346579001240147982), INT64_C( 8478054430600792515),
                            INT64_C( 7917529543412977905), INT64_C( 6077094839460323156),
                            INT64_C(-3234198817213444484), INT64_C( 5455426772165090925)),
      simde_mm512_set_epi64(INT64_C(                   0), INT64_C(                 -46),
                            INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                   1), INT64_C(                   0)) },
    { simde_mm512_set_epi64(INT64_C( 5060007040297057440), INT64_C(-6547486212696877775),
                            INT64_C( 4083773956347780040), INT64_C(-7582952476466356489),
                            INT64_C( -533799245190218148), INT64_C( 6528011672062484486),
                            INT64_C( 8505594160370567764), INT64_C(-7955306051941505966)),
      simde_mm512_set_epi64(INT64_C( 8381795236484256749), INT64_C(-8094121819208130597),
                            INT64_C(-4463810942012697177), INT64_C( 1695569373680370472),
                            INT64_C( 6457800057248167752), INT64_C( 2509734679188915375),
                            INT64_C(-1817858424181439867), INT64_C(-1140679629593449988)),
      simde_mm512_set_epi64(INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(                  -4),
                            INT64_C(                   0), INT64_C(                   2),
                            INT64_C(                  -4), INT64_C(                   6)) },
    { simde_mm512_set_epi64(INT64_C(-3727073512330556719), INT64_C( 1145199535931310009),
                            INT64_C( 6618746106828964781), INT64_C( -318594899546127361),
                            INT64_C(-8348228873903822999), INT64_C( 6522300981577637255),
                            INT64_C(-2123306667443487570), INT64_C(-4210181406724347525)),
      simde_mm512_set_epi64(INT64_C(-5833250200550208329), INT64_C( 8217300129052611844),
                            INT64_C( -649664904511148711), INT64_C( 3231016623164402124),
                            INT64_C( 8024018119100712605), INT64_C( 4306653136982574157),
                            INT64_C(-5380031023357226466), INT64_C( 2544237471105729967)),
      simde_mm512_set_epi64(INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                 -10), INT64_C(                   0),
                            INT64_C(                  -1), INT64_C(                   1),
                            INT64_C(                   0), INT64_C(                  -1)) },
    { simde_mm512_set_epi64(INT64_C(-6427790700478275098), INT64_C(-3168480089241839861),
                            INT64_C(-5000559488767708993), INT64_C( 2755885615249137538),
                            INT64_C( -821966059249139816), INT64_C( 1089871025732147351),
                            INT64_C( 4566772594003817295), INT64_C(-9114574651084812253)),
      simde_mm512_set_epi64(INT64_C( 1778890864282373370), INT64_C( 5911759041868723302),
                            INT64_C( 4553617065988887085), INT64_C( -523178035921802922),
                            INT64_C( 8875040781716651384), INT64_C( 2040058868339841473),
                            INT64_C(-2732208005963885166), INT64_C(-4435516374878659804)),
      simde_mm512_set_epi64(INT64_C(                  -3), INT64_C(                   0),
                            INT64_C(                  -1), INT64_C(                  -5),
                            INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                  -1), INT64_C(                   2)) },
    { simde_mm512_set_epi64(INT64_C(  423237589908350744), INT64_C( 2795901596537384901),
                            INT64_C( 1719109459006160254), INT64_C(-9093479824318774446),
                            INT64_C(-4511267031708830231), INT64_C(-3402553166296368495),
                            INT64_C( 1216620777318406949), INT64_C( -836102980820378689)),
      simde_mm512_set_epi64(INT64_C( 7782115963838117574), INT64_C(-6846698536887599933),
                            INT64_C( 4072223690207540333), INT64_C(-1026965696159348843),
                            INT64_C( 4340400659569160523), INT64_C(-8299269241811916492),
                            INT64_C( 7360887374546597504), INT64_C(-6651085920823128052)),
      simde_mm512_set_epi64(INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(                   8),
                            INT64_C(                  -1), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(                   0)) },
    { simde_mm512_set_epi64(INT64_C(  453211281016332666), INT64_C( 5434252921191502101),
                            INT64_C(-6060319301844209563), INT64_C(-5254139409542070482),
                            INT64_C(-8624885551201065882), INT64_C( 8329149627836272144),
                            INT64_C( 8516875663163240125), INT64_C(-4575460702098419673)),
      simde_mm512_set_epi64(INT64_C(-5051260979279221837), INT64_C( 6222948671724306809),
                            INT64_C( 6742741209152957138), INT64_C( 5958951964162816685),
                            INT64_C( 2981515940173974322), INT64_C( 3752367916961311345),
                            INT64_C(-2840979297342041250), INT64_C(-2506264265844715430)),
      simde_mm512_set_epi64(INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                  -2), INT64_C(                   2),
                            INT64_C(                  -2), INT64_C(                   1)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_div_epi64(test_vec[i].a, test_vec[i].b);
    simde_assert_m512i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_div_epu8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512i a;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {
    { simde_x_mm512_set_epu8(UINT8_C( 41), UINT8_C( 49), UINT8_C(171), UINT8_C(198),
                             UINT8_C( 40), UINT8_C( 44), UINT8_C(242), UINT8_C( 51),
                             UINT8_C(138), UINT8_C(217), UINT8_C(215), UINT8_C(249),
                             UINT8_C(201), UINT8_C( 37), UINT8_C(137), UINT8_C( 29),
                             UINT8_C(233), UINT8_C(170), UINT8_C(241), UINT8_C(126),
                             UINT8_C(182), UINT8_C( 10), UINT8_C(208), UINT8_C(198),
                             UINT8_C( 93), UINT8_C(130), UINT8_C(195), UINT8_C(177),
                             UINT8_C(187), UINT8_C(223), UINT8_C(139), UINT8_C(253),
                             UINT8_C(191), UINT8_C(167), UINT8_C(226), UINT8_C( 64),
                             UINT8_C(213), UINT8_C(202), UINT8_C(110), UINT8_C(113),
                             UINT8_C( 89), UINT8_C(237), UINT8_C( 70), UINT8_C(226),
                             UINT8_C(132), UINT8_C( 91), UINT8_C(255), UINT8_C( 88),
                             UINT8_C(104), UINT8_C( 42), UINT8_C( 53), UINT8_C(254),
                             UINT8_C(132), UINT8_C(254), UINT8_C( 96), UINT8_C( 75),
                             UINT8_C( 31), UINT8_C(112), UINT8_C(151), UINT8_C(169),
                             UINT8_C(172), UINT8_C( 94), UINT8_C(112), UINT8_C( 90)),
      simde_x_mm512_set_epu8(UINT8_C(195), UINT8_C( 49), UINT8_C( 14), UINT8_C(170),
                             UINT8_C(203), UINT8_C(167), UINT8_C(  3), UINT8_C(215),
                             UINT8_C( 63), UINT8_C(248), UINT8_C( 55), UINT8_C(219),
                             UINT8_C(221), UINT8_C(135), UINT8_C( 61), UINT8_C(191),
                             UINT8_C(209), UINT8_C( 91), UINT8_C( 87), UINT8_C(137),
                             UINT8_C( 87), UINT8_C( 76), UINT8_C( 44), UINT8_C(140),
                             UINT8_C(  2), UINT8_C(200), UINT8_C( 36), UINT8_C(195),
                             UINT8_C(200), UINT8_C(125), UINT8_C(254), UINT8_C(139),
                             UINT8_C(226), UINT8_C( 71), UINT8_C( 92), UINT8_C(129),
                             UINT8_C(182), UINT8_C(119), UINT8_C(247), UINT8_C( 34),
                             UINT8_C(121), UINT8_C( 85), UINT8_C(153), UINT8_C(116),
                             UINT8_C(218), UINT8_C( 21), UINT8_C(101), UINT8_C(122),
                             UINT8_C( 10), UINT8_C(231), UINT8_C( 54), UINT8_C( 71),
                             UINT8_C(156), UINT8_C(149), UINT8_C(244), UINT8_C( 84),
                             UINT8_C(148), UINT8_C( 85), UINT8_C(170), UINT8_C(184),
                             UINT8_C( 94), UINT8_C(154), UINT8_C(229), UINT8_C( 11)),
      simde_x_mm512_set_epu8(UINT8_C(  0), UINT8_C(  1), UINT8_C( 12), UINT8_C(  1),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C( 80), UINT8_C(  0),
                             UINT8_C(  2), UINT8_C(  0), UINT8_C(  3), UINT8_C(  1),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C(  2), UINT8_C(  0),
                             UINT8_C(  1), UINT8_C(  1), UINT8_C(  2), UINT8_C(  0),
                             UINT8_C(  2), UINT8_C(  0), UINT8_C(  4), UINT8_C(  1),
                             UINT8_C( 46), UINT8_C(  0), UINT8_C(  5), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(  1), UINT8_C(  0), UINT8_C(  1),
                             UINT8_C(  0), UINT8_C(  2), UINT8_C(  2), UINT8_C(  0),
                             UINT8_C(  1), UINT8_C(  1), UINT8_C(  0), UINT8_C(  3),
                             UINT8_C(  0), UINT8_C(  2), UINT8_C(  0), UINT8_C(  1),
                             UINT8_C(  0), UINT8_C(  4), UINT8_C(  2), UINT8_C(  0),
                             UINT8_C( 10), UINT8_C(  0), UINT8_C(  0), UINT8_C(  3),
                             UINT8_C(  0), UINT8_C(  1), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(  1), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  1), UINT8_C(  0), UINT8_C(  0), UINT8_C(  8)) },
    { simde_x_mm512_set_epu8(UINT8_C(216), UINT8_C( 85), UINT8_C(206), UINT8_C(103),
                             UINT8_C(235), UINT8_C(154), UINT8_C(129), UINT8_C(135),
                             UINT8_C(125), UINT8_C( 76), UINT8_C(202), UINT8_C(108),
                             UINT8_C( 52), UINT8_C( 71), UINT8_C(168), UINT8_C(196),
                             UINT8_C( 70), UINT8_C(138), UINT8_C(167), UINT8_C( 65),
                             UINT8_C(221), UINT8_C(161), UINT8_C(157), UINT8_C( 93),
                             UINT8_C(192), UINT8_C(189), UINT8_C(153), UINT8_C(155),
                             UINT8_C(207), UINT8_C(213), UINT8_C(105), UINT8_C(136),
                             UINT8_C(234), UINT8_C( 94), UINT8_C(240), UINT8_C( 12),
                             UINT8_C(146), UINT8_C(  1), UINT8_C(147), UINT8_C( 59),
                             UINT8_C(253), UINT8_C( 26), UINT8_C( 26), UINT8_C( 40),
                             UINT8_C( 12), UINT8_C(  2), UINT8_C(230), UINT8_C(145),
                             UINT8_C(170), UINT8_C(105), UINT8_C(111), UINT8_C(160),
                             UINT8_C(140), UINT8_C(202), UINT8_C(166), UINT8_C(220),
                             UINT8_C(187), UINT8_C( 65), UINT8_C(250), UINT8_C(195),
                             UINT8_C( 33), UINT8_C(131), UINT8_C(  2), UINT8_C(164)),
      simde_x_mm512_set_epu8(UINT8_C(120), UINT8_C(127), UINT8_C( 28), UINT8_C( 95),
                             UINT8_C(175), UINT8_C(223), UINT8_C(119), UINT8_C(214),
                             UINT8_C(220), UINT8_C(102), UINT8_C( 86), UINT8_C( 22),
                             UINT8_C(119), UINT8_C(207), UINT8_C( 12), UINT8_C(183),
                             UINT8_C(172), UINT8_C(242), UINT8_C(173), UINT8_C(249),
                             UINT8_C( 52), UINT8_C(108), UINT8_C(128), UINT8_C(203),
                             UINT8_C( 85), UINT8_C(135), UINT8_C(227), UINT8_C( 35),
                             UINT8_C(187), UINT8_C( 24), UINT8_C(250), UINT8_C(219),
                             UINT8_C(253), UINT8_C( 62), UINT8_C(125), UINT8_C(236),
                             UINT8_C( 75), UINT8_C( 13), UINT8_C( 79), UINT8_C( 81),
                             UINT8_C(177), UINT8_C(221), UINT8_C(251), UINT8_C(181),
                             UINT8_C(159), UINT8_C(182), UINT8_C( 11), UINT8_C( 11),
                             UINT8_C( 39), UINT8_C( 37), UINT8_C( 39), UINT8_C(208),
                             UINT8_C(136), UINT8_C(180), UINT8_C(215), UINT8_C(139),
                             UINT8_C(144), UINT8_C(128), UINT8_C(203), UINT8_C(206),
                             UINT8_C(173), UINT8_C( 36), UINT8_C(133), UINT8_C(175)),
      simde_x_mm512_set_epu8(UINT8_C(  1), UINT8_C(  0), UINT8_C(  7), UINT8_C(  1),
                             UINT8_C(  1), UINT8_C(  0), UINT8_C(  1), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C(  2), UINT8_C(  4),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C( 14), UINT8_C(  1),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  4), UINT8_C(  1), UINT8_C(  1), UINT8_C(  0),
                             UINT8_C(  2), UINT8_C(  1), UINT8_C(  0), UINT8_C(  4),
                             UINT8_C(  1), UINT8_C(  8), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(  1), UINT8_C(  1), UINT8_C(  0),
                             UINT8_C(  1), UINT8_C(  0), UINT8_C(  1), UINT8_C(  0),
                             UINT8_C(  1), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C( 20), UINT8_C( 13),
                             UINT8_C(  4), UINT8_C(  2), UINT8_C(  2), UINT8_C(  0),
                             UINT8_C(  1), UINT8_C(  1), UINT8_C(  0), UINT8_C(  1),
                             UINT8_C(  1), UINT8_C(  0), UINT8_C(  1), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(  3), UINT8_C(  0), UINT8_C(  0)) },
    { simde_x_mm512_set_epu8(UINT8_C( 87), UINT8_C( 63), UINT8_C( 47), UINT8_C( 80),
                             UINT8_C( 35), UINT8_C(229), UINT8_C(  5), UINT8_C( 31),
                             UINT8_C(228), UINT8_C( 73), UINT8_C( 53), UINT8_C( 47),
                             UINT8_C(170), UINT8_C(192), UINT8_C(122), UINT8_C(237),
                             UINT8_C( 47), UINT8_C(130), UINT8_C(219), UINT8_C(102),
                             UINT8_C(163), UINT8_C( 41), UINT8_C(195), UINT8_C(215),
                             UINT8_C(199), UINT8_C( 54), UINT8_C( 97), UINT8_C(126),
                             UINT8_C( 10), UINT8_C(165), UINT8_C(155), UINT8_C( 88),
                             UINT8_C(184), UINT8_C( 63), UINT8_C( 95), UINT8_C(164),
                             UINT8_C( 65), UINT8_C( 71), UINT8_C(174), UINT8_C( 88),
                             UINT8_C(183), UINT8_C(142), UINT8_C( 98), UINT8_C( 14),
                             UINT8_C( 25), UINT8_C(173), UINT8_C( 87), UINT8_C(  2),
                             UINT8_C(191), UINT8_C(143), UINT8_C(152), UINT8_C(  2),
                             UINT8_C(126), UINT8_C(  0), UINT8_C(162), UINT8_C( 57),
                             UINT8_C(245), UINT8_C( 36), UINT8_C(239), UINT8_C( 54),
                             UINT8_C( 33), UINT8_C(165), UINT8_C(199), UINT8_C( 84)),
      simde_x_mm512_set_epu8(UINT8_C(131), UINT8_C( 42), UINT8_C(151), UINT8_C(210),
                             UINT8_C( 12), UINT8_C(163), UINT8_C(138), UINT8_C(207),
                             UINT8_C( 43), UINT8_C( 57), UINT8_C( 61), UINT8_C( 62),
                             UINT8_C( 81), UINT8_C(184), UINT8_C(  6), UINT8_C( 93),
                             UINT8_C(167), UINT8_C(  1), UINT8_C(145), UINT8_C(  9),
                             UINT8_C(  4), UINT8_C( 17), UINT8_C( 10), UINT8_C(101),
                             UINT8_C(186), UINT8_C(181), UINT8_C(155), UINT8_C(243),
                             UINT8_C(189), UINT8_C(191), UINT8_C(222), UINT8_C(205),
                             UINT8_C( 59), UINT8_C( 26), UINT8_C(227), UINT8_C(105),
                             UINT8_C(237), UINT8_C(145), UINT8_C(183), UINT8_C( 79),
                             UINT8_C(174), UINT8_C( 60), UINT8_C(132), UINT8_C(208),
                             UINT8_C( 58), UINT8_C(178), UINT8_C(116), UINT8_C(240),
                             UINT8_C( 37), UINT8_C(131), UINT8_C(100), UINT8_C(177),
                             UINT8_C( 19), UINT8_C(102), UINT8_C( 81), UINT8_C( 86),
                             UINT8_C( 25), UINT8_C( 43), UINT8_C( 51), UINT8_C(140),
                             UINT8_C(  9), UINT8_C( 40), UINT8_C(227), UINT8_C( 75)),
      simde_x_mm512_set_epu8(UINT8_C(  0), UINT8_C(  1), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  2), UINT8_C(  1), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  5), UINT8_C(  1), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  2), UINT8_C(  1), UINT8_C( 20), UINT8_C(  2),
                             UINT8_C(  0), UINT8_C(130), UINT8_C(  1), UINT8_C( 11),
                             UINT8_C( 40), UINT8_C(  2), UINT8_C( 19), UINT8_C(  2),
                             UINT8_C(  1), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  3), UINT8_C(  2), UINT8_C(  0), UINT8_C(  1),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  1),
                             UINT8_C(  1), UINT8_C(  2), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  5), UINT8_C(  1), UINT8_C(  1), UINT8_C(  0),
                             UINT8_C(  6), UINT8_C(  0), UINT8_C(  2), UINT8_C(  0),
                             UINT8_C(  9), UINT8_C(  0), UINT8_C(  4), UINT8_C(  0),
                             UINT8_C(  3), UINT8_C(  4), UINT8_C(  0), UINT8_C(  1)) },
    { simde_x_mm512_set_epu8(UINT8_C(233), UINT8_C( 79), UINT8_C( 12), UINT8_C(  0),
                             UINT8_C( 33), UINT8_C(178), UINT8_C( 58), UINT8_C( 74),
                             UINT8_C(250), UINT8_C(116), UINT8_C(142), UINT8_C( 20),
                             UINT8_C( 88), UINT8_C( 63), UINT8_C( 34), UINT8_C(124),
                             UINT8_C(250), UINT8_C( 48), UINT8_C(221), UINT8_C(232),
                             UINT8_C(221), UINT8_C( 75), UINT8_C(155), UINT8_C( 80),
                             UINT8_C(233), UINT8_C(169), UINT8_C(198), UINT8_C(226),
                             UINT8_C( 83), UINT8_C( 27), UINT8_C(137), UINT8_C( 34),
                             UINT8_C( 23), UINT8_C(132), UINT8_C(106), UINT8_C(109),
                             UINT8_C(135), UINT8_C(203), UINT8_C( 98), UINT8_C(120),
                             UINT8_C(101), UINT8_C( 52), UINT8_C( 82), UINT8_C( 44),
                             UINT8_C(142), UINT8_C( 14), UINT8_C( 99), UINT8_C(245),
                             UINT8_C(  8), UINT8_C(140), UINT8_C(141), UINT8_C(123),
                             UINT8_C(219), UINT8_C(163), UINT8_C(196), UINT8_C(233),
                             UINT8_C( 34), UINT8_C(185), UINT8_C(228), UINT8_C(108),
                             UINT8_C( 95), UINT8_C(236), UINT8_C( 97), UINT8_C( 41)),
      simde_x_mm512_set_epu8(UINT8_C(193), UINT8_C(230), UINT8_C( 93), UINT8_C( 23),
                             UINT8_C(193), UINT8_C( 52), UINT8_C(223), UINT8_C(175),
                             UINT8_C(205), UINT8_C( 45), UINT8_C(166), UINT8_C( 24),
                             UINT8_C( 71), UINT8_C(234), UINT8_C(161), UINT8_C(142),
                             UINT8_C(184), UINT8_C(218), UINT8_C(190), UINT8_C(212),
                             UINT8_C(116), UINT8_C(159), UINT8_C( 44), UINT8_C( 55),
                             UINT8_C(213), UINT8_C(133), UINT8_C( 60), UINT8_C(  3),
                             UINT8_C( 58), UINT8_C(255), UINT8_C(125), UINT8_C(189),
                             UINT8_C(145), UINT8_C( 88), UINT8_C( 55), UINT8_C(182),
                             UINT8_C( 23), UINT8_C(161), UINT8_C(133), UINT8_C( 27),
                             UINT8_C(125), UINT8_C(229), UINT8_C(203), UINT8_C( 45),
                             UINT8_C( 24), UINT8_C(  5), UINT8_C( 90), UINT8_C( 83),
                             UINT8_C(145), UINT8_C( 85), UINT8_C(156), UINT8_C(164),
                             UINT8_C(149), UINT8_C(201), UINT8_C( 48), UINT8_C(255),
                             UINT8_C( 41), UINT8_C( 42), UINT8_C( 94), UINT8_C(129),
                             UINT8_C(135), UINT8_C(  8), UINT8_C( 12), UINT8_C(203)),
      simde_x_mm512_set_epu8(UINT8_C(  1), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(  3), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  1), UINT8_C(  2), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  1), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  1), UINT8_C(  0), UINT8_C(  1), UINT8_C(  1),
                             UINT8_C(  1), UINT8_C(  0), UINT8_C(  3), UINT8_C(  1),
                             UINT8_C(  1), UINT8_C(  1), UINT8_C(  3), UINT8_C( 75),
                             UINT8_C(  1), UINT8_C(  0), UINT8_C(  1), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(  1), UINT8_C(  1), UINT8_C(  0),
                             UINT8_C(  5), UINT8_C(  1), UINT8_C(  0), UINT8_C(  4),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  5), UINT8_C(  2), UINT8_C(  1), UINT8_C(  2),
                             UINT8_C(  0), UINT8_C(  1), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  1), UINT8_C(  0), UINT8_C(  4), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(  4), UINT8_C(  2), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C( 29), UINT8_C(  8), UINT8_C(  0)) },
    { simde_x_mm512_set_epu8(UINT8_C(142), UINT8_C( 19), UINT8_C(128), UINT8_C(  3),
                             UINT8_C(129), UINT8_C(192), UINT8_C(118), UINT8_C(156),
                             UINT8_C( 16), UINT8_C(232), UINT8_C(203), UINT8_C(122),
                             UINT8_C(229), UINT8_C(105), UINT8_C(120), UINT8_C(201),
                             UINT8_C(228), UINT8_C(167), UINT8_C(141), UINT8_C(146),
                             UINT8_C(116), UINT8_C( 74), UINT8_C(191), UINT8_C( 35),
                             UINT8_C( 45), UINT8_C(158), UINT8_C(228), UINT8_C(138),
                             UINT8_C( 49), UINT8_C(  7), UINT8_C( 65), UINT8_C(140),
                             UINT8_C(  0), UINT8_C(113), UINT8_C(156), UINT8_C(113),
                             UINT8_C(246), UINT8_C(167), UINT8_C(109), UINT8_C(141),
                             UINT8_C(192), UINT8_C( 11), UINT8_C( 33), UINT8_C(141),
                             UINT8_C(129), UINT8_C(  2), UINT8_C(168), UINT8_C(227),
                             UINT8_C( 23), UINT8_C(173), UINT8_C(104), UINT8_C( 71),
                             UINT8_C( 11), UINT8_C(250), UINT8_C( 13), UINT8_C(218),
                             UINT8_C(194), UINT8_C(140), UINT8_C(125), UINT8_C( 43),
                             UINT8_C(151), UINT8_C( 49), UINT8_C(129), UINT8_C(218)),
      simde_x_mm512_set_epu8(UINT8_C(  8), UINT8_C( 25), UINT8_C(147), UINT8_C(220),
                             UINT8_C(173), UINT8_C(138), UINT8_C( 38), UINT8_C(150),
                             UINT8_C( 35), UINT8_C( 43), UINT8_C(165), UINT8_C(185),
                             UINT8_C( 50), UINT8_C( 64), UINT8_C(161), UINT8_C(132),
                             UINT8_C(162), UINT8_C( 50), UINT8_C(199), UINT8_C( 84),
                             UINT8_C(251), UINT8_C(200), UINT8_C(217), UINT8_C( 19),
                             UINT8_C(180), UINT8_C(196), UINT8_C(246), UINT8_C( 76),
                             UINT8_C( 55), UINT8_C(204), UINT8_C(139), UINT8_C( 75),
                             UINT8_C(  1), UINT8_C( 89), UINT8_C(133), UINT8_C(212),
                             UINT8_C(206), UINT8_C( 55), UINT8_C(204), UINT8_C(120),
                             UINT8_C( 37), UINT8_C(159), UINT8_C(146), UINT8_C(217),
                             UINT8_C(226), UINT8_C(190), UINT8_C(134), UINT8_C(  8),
                             UINT8_C(113), UINT8_C( 61), UINT8_C(103), UINT8_C(100),
                             UINT8_C( 23), UINT8_C(229), UINT8_C(146), UINT8_C( 97),
                             UINT8_C( 95), UINT8_C( 32), UINT8_C(136), UINT8_C( 91),
                             UINT8_C( 46), UINT8_C(252), UINT8_C(163), UINT8_C( 88)),
      simde_x_mm512_set_epu8(UINT8_C( 17), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(  1), UINT8_C(  3), UINT8_C(  1),
                             UINT8_C(  0), UINT8_C(  5), UINT8_C(  1), UINT8_C(  0),
                             UINT8_C(  4), UINT8_C(  1), UINT8_C(  0), UINT8_C(  1),
                             UINT8_C(  1), UINT8_C(  3), UINT8_C(  0), UINT8_C(  1),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  1),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  1),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  1),
                             UINT8_C(  0), UINT8_C(  1), UINT8_C(  1), UINT8_C(  0),
                             UINT8_C(  1), UINT8_C(  3), UINT8_C(  0), UINT8_C(  1),
                             UINT8_C(  5), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C(  1), UINT8_C( 28),
                             UINT8_C(  0), UINT8_C(  2), UINT8_C(  1), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(  1), UINT8_C(  0), UINT8_C(  2),
                             UINT8_C(  2), UINT8_C(  4), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  3), UINT8_C(  0), UINT8_C(  0), UINT8_C(  2)) },
    { simde_x_mm512_set_epu8(UINT8_C( 46), UINT8_C( 43), UINT8_C(246), UINT8_C(157),
                             UINT8_C( 80), UINT8_C(154), UINT8_C( 27), UINT8_C(118),
                             UINT8_C(176), UINT8_C(216), UINT8_C( 46), UINT8_C(142),
                             UINT8_C(198), UINT8_C(248), UINT8_C( 88), UINT8_C( 29),
                             UINT8_C(176), UINT8_C( 25), UINT8_C(101), UINT8_C( 54),
                             UINT8_C(103), UINT8_C(120), UINT8_C( 94), UINT8_C( 16),
                             UINT8_C(197), UINT8_C(205), UINT8_C( 71), UINT8_C(246),
                             UINT8_C(158), UINT8_C(176), UINT8_C(218), UINT8_C( 43),
                             UINT8_C(235), UINT8_C(249), UINT8_C(116), UINT8_C(137),
                             UINT8_C( 89), UINT8_C(212), UINT8_C(132), UINT8_C( 56),
                             UINT8_C(230), UINT8_C(137), UINT8_C( 66), UINT8_C( 41),
                             UINT8_C( 44), UINT8_C( 35), UINT8_C(189), UINT8_C(155),
                             UINT8_C(125), UINT8_C(130), UINT8_C(123), UINT8_C(117),
                             UINT8_C(123), UINT8_C(127), UINT8_C(151), UINT8_C( 60),
                             UINT8_C(153), UINT8_C(185), UINT8_C(250), UINT8_C(100),
                             UINT8_C( 83), UINT8_C(112), UINT8_C( 33), UINT8_C(140)),
      simde_x_mm512_set_epu8(UINT8_C( 36), UINT8_C( 33), UINT8_C( 42), UINT8_C( 75),
                             UINT8_C(179), UINT8_C(172), UINT8_C(126), UINT8_C(171),
                             UINT8_C(110), UINT8_C(150), UINT8_C(107), UINT8_C(180),
                             UINT8_C(134), UINT8_C( 73), UINT8_C(207), UINT8_C( 15),
                             UINT8_C(241), UINT8_C(103), UINT8_C(103), UINT8_C(150),
                             UINT8_C(103), UINT8_C( 58), UINT8_C(104), UINT8_C( 35),
                             UINT8_C(249), UINT8_C( 79), UINT8_C(113), UINT8_C( 97),
                             UINT8_C(189), UINT8_C(197), UINT8_C(174), UINT8_C(222),
                             UINT8_C(224), UINT8_C(104), UINT8_C(123), UINT8_C(124),
                             UINT8_C( 49), UINT8_C(226), UINT8_C( 37), UINT8_C( 22),
                             UINT8_C(105), UINT8_C(157), UINT8_C(110), UINT8_C( 52),
                             UINT8_C(254), UINT8_C(103), UINT8_C(162), UINT8_C(210),
                             UINT8_C(202), UINT8_C( 39), UINT8_C(193), UINT8_C(151),
                             UINT8_C(183), UINT8_C( 73), UINT8_C( 97), UINT8_C(187),
                             UINT8_C(102), UINT8_C(195), UINT8_C( 68), UINT8_C(190),
                             UINT8_C( 65), UINT8_C( 60), UINT8_C(165), UINT8_C(126)),
      simde_x_mm512_set_epu8(UINT8_C(  1), UINT8_C(  1), UINT8_C(  5), UINT8_C(  2),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  1), UINT8_C(  1), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  1), UINT8_C(  3), UINT8_C(  0), UINT8_C(  1),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  1), UINT8_C(  2), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(  2), UINT8_C(  0), UINT8_C(  2),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C(  1), UINT8_C(  0),
                             UINT8_C(  1), UINT8_C(  2), UINT8_C(  0), UINT8_C(  1),
                             UINT8_C(  1), UINT8_C(  0), UINT8_C(  3), UINT8_C(  2),
                             UINT8_C(  2), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C(  1), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(  3), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(  1), UINT8_C(  1), UINT8_C(  0),
                             UINT8_C(  1), UINT8_C(  0), UINT8_C(  3), UINT8_C(  0),
                             UINT8_C(  1), UINT8_C(  1), UINT8_C(  0), UINT8_C(  1)) },
    { simde_x_mm512_set_epu8(UINT8_C(240), UINT8_C(169), UINT8_C(  8), UINT8_C( 54),
                             UINT8_C( 66), UINT8_C( 99), UINT8_C( 14), UINT8_C( 32),
                             UINT8_C(148), UINT8_C( 92), UINT8_C(122), UINT8_C(200),
                             UINT8_C(192), UINT8_C(186), UINT8_C(225), UINT8_C( 52),
                             UINT8_C(182), UINT8_C(244), UINT8_C(253), UINT8_C(228),
                             UINT8_C(141), UINT8_C(228), UINT8_C(148), UINT8_C(168),
                             UINT8_C(231), UINT8_C(107), UINT8_C( 47), UINT8_C(205),
                             UINT8_C(126), UINT8_C(  7), UINT8_C(182), UINT8_C(245),
                             UINT8_C(165), UINT8_C(186), UINT8_C(213), UINT8_C( 84),
                             UINT8_C( 19), UINT8_C(131), UINT8_C( 54), UINT8_C( 13),
                             UINT8_C(185), UINT8_C(182), UINT8_C( 72), UINT8_C( 61),
                             UINT8_C(125), UINT8_C(104), UINT8_C(147), UINT8_C( 11),
                             UINT8_C( 89), UINT8_C(204), UINT8_C( 62), UINT8_C(163),
                             UINT8_C(198), UINT8_C(162), UINT8_C(205), UINT8_C(  9),
                             UINT8_C(182), UINT8_C(123), UINT8_C( 65), UINT8_C(208),
                             UINT8_C(145), UINT8_C(179), UINT8_C( 34), UINT8_C(195)),
      simde_x_mm512_set_epu8(UINT8_C(141), UINT8_C(103), UINT8_C(116), UINT8_C( 12),
                             UINT8_C(174), UINT8_C(226), UINT8_C(193), UINT8_C(175),
                             UINT8_C(155), UINT8_C(174), UINT8_C( 73), UINT8_C(  6),
                             UINT8_C(141), UINT8_C(140), UINT8_C(254), UINT8_C(193),
                             UINT8_C(100), UINT8_C(151), UINT8_C( 14), UINT8_C( 19),
                             UINT8_C( 38), UINT8_C(115), UINT8_C(201), UINT8_C(118),
                             UINT8_C( 74), UINT8_C(186), UINT8_C( 89), UINT8_C(183),
                             UINT8_C( 65), UINT8_C(138), UINT8_C( 64), UINT8_C( 90),
                             UINT8_C(152), UINT8_C(241), UINT8_C(229), UINT8_C(218),
                             UINT8_C(126), UINT8_C( 38), UINT8_C(159), UINT8_C( 27),
                             UINT8_C(164), UINT8_C(199), UINT8_C( 25), UINT8_C(253),
                             UINT8_C(181), UINT8_C(104), UINT8_C(  6), UINT8_C(183),
                             UINT8_C( 36), UINT8_C(203), UINT8_C(138), UINT8_C(145),
                             UINT8_C(116), UINT8_C(155), UINT8_C(218), UINT8_C( 24),
                             UINT8_C(205), UINT8_C(238), UINT8_C(242), UINT8_C( 26),
                             UINT8_C(226), UINT8_C( 76), UINT8_C(226), UINT8_C(214)),
      simde_x_mm512_set_epu8(UINT8_C(  1), UINT8_C(  1), UINT8_C(  0), UINT8_C(  4),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C(  1), UINT8_C( 33),
                             UINT8_C(  1), UINT8_C(  1), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  1), UINT8_C(  1), UINT8_C( 18), UINT8_C( 12),
                             UINT8_C(  3), UINT8_C(  1), UINT8_C(  0), UINT8_C(  1),
                             UINT8_C(  3), UINT8_C(  0), UINT8_C(  0), UINT8_C(  1),
                             UINT8_C(  1), UINT8_C(  0), UINT8_C(  2), UINT8_C(  2),
                             UINT8_C(  1), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(  3), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  1), UINT8_C(  0), UINT8_C(  2), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(  1), UINT8_C( 24), UINT8_C(  0),
                             UINT8_C(  2), UINT8_C(  1), UINT8_C(  0), UINT8_C(  1),
                             UINT8_C(  1), UINT8_C(  1), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  8),
                             UINT8_C(  0), UINT8_C(  2), UINT8_C(  0), UINT8_C(  0)) },
    { simde_x_mm512_set_epu8(UINT8_C(197), UINT8_C( 52), UINT8_C(145), UINT8_C( 20),
                             UINT8_C( 26), UINT8_C(178), UINT8_C(121), UINT8_C( 16),
                             UINT8_C( 45), UINT8_C(229), UINT8_C( 11), UINT8_C(230),
                             UINT8_C( 53), UINT8_C(  2), UINT8_C(234), UINT8_C(  7),
                             UINT8_C(207), UINT8_C(146), UINT8_C(169), UINT8_C(233),
                             UINT8_C(206), UINT8_C(116), UINT8_C( 55), UINT8_C(156),
                             UINT8_C(180), UINT8_C( 91), UINT8_C( 56), UINT8_C(146),
                             UINT8_C( 55), UINT8_C(137), UINT8_C(200), UINT8_C( 76),
                             UINT8_C( 43), UINT8_C(245), UINT8_C(138), UINT8_C(  3),
                             UINT8_C(213), UINT8_C(156), UINT8_C(166), UINT8_C(234),
                             UINT8_C(199), UINT8_C(  2), UINT8_C( 86), UINT8_C( 72),
                             UINT8_C( 93), UINT8_C(254), UINT8_C(190), UINT8_C(121),
                             UINT8_C(119), UINT8_C( 75), UINT8_C(159), UINT8_C( 76),
                             UINT8_C( 70), UINT8_C(218), UINT8_C( 17), UINT8_C(239),
                             UINT8_C( 43), UINT8_C(152), UINT8_C(222), UINT8_C( 80),
                             UINT8_C(197), UINT8_C(113), UINT8_C(112), UINT8_C( 81)),
      simde_x_mm512_set_epu8(UINT8_C(193), UINT8_C(162), UINT8_C(178), UINT8_C( 36),
                             UINT8_C(178), UINT8_C( 86), UINT8_C( 79), UINT8_C(167),
                             UINT8_C(179), UINT8_C( 45), UINT8_C( 18), UINT8_C(231),
                             UINT8_C(113), UINT8_C(127), UINT8_C(211), UINT8_C(181),
                             UINT8_C(121), UINT8_C(171), UINT8_C( 76), UINT8_C(135),
                             UINT8_C( 15), UINT8_C(133), UINT8_C(247), UINT8_C( 32),
                             UINT8_C(181), UINT8_C(168), UINT8_C(236), UINT8_C( 99),
                             UINT8_C( 85), UINT8_C(151), UINT8_C( 36), UINT8_C( 99),
                             UINT8_C(101), UINT8_C( 42), UINT8_C( 63), UINT8_C( 96),
                             UINT8_C(210), UINT8_C(198), UINT8_C(202), UINT8_C(105),
                             UINT8_C(214), UINT8_C( 74), UINT8_C(199), UINT8_C( 17),
                             UINT8_C(234), UINT8_C( 22), UINT8_C(134), UINT8_C(112),
                             UINT8_C( 62), UINT8_C(141), UINT8_C(156), UINT8_C( 91),
                             UINT8_C( 99), UINT8_C( 24), UINT8_C(198), UINT8_C(131),
                             UINT8_C( 88), UINT8_C(136), UINT8_C( 61), UINT8_C( 94),
                             UINT8_C(189), UINT8_C(213), UINT8_C(249), UINT8_C(131)),
      simde_x_mm512_set_epu8(UINT8_C(  1), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(  2), UINT8_C(  1), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(  5), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C(  1), UINT8_C(  0),
                             UINT8_C(  1), UINT8_C(  0), UINT8_C(  2), UINT8_C(  1),
                             UINT8_C( 13), UINT8_C(  0), UINT8_C(  0), UINT8_C(  4),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  1),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C(  5), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(  5), UINT8_C(  2), UINT8_C(  0),
                             UINT8_C(  1), UINT8_C(  0), UINT8_C(  0), UINT8_C(  2),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  4),
                             UINT8_C(  0), UINT8_C( 11), UINT8_C(  1), UINT8_C(  1),
                             UINT8_C(  1), UINT8_C(  0), UINT8_C(  1), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(  9), UINT8_C(  0), UINT8_C(  1),
                             UINT8_C(  0), UINT8_C(  1), UINT8_C(  3), UINT8_C(  0),
                             UINT8_C(  1), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_div_epu8(test_vec[i].a, test_vec[i].b);
    simde_assert_m512i_u8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_div_epu16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512i a;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {
    { simde_x_mm512_set_epu16(UINT16_C( 10545), UINT16_C( 43974), UINT16_C( 10284), UINT16_C( 62003),
                              UINT16_C( 35545), UINT16_C( 55289), UINT16_C( 51493), UINT16_C( 35101),
                              UINT16_C( 59818), UINT16_C( 61822), UINT16_C( 46602), UINT16_C( 53446),
                              UINT16_C( 23938), UINT16_C( 50097), UINT16_C( 48095), UINT16_C( 35837),
                              UINT16_C( 49063), UINT16_C( 57920), UINT16_C( 54730), UINT16_C( 28273),
                              UINT16_C( 23021), UINT16_C( 18146), UINT16_C( 33883), UINT16_C( 65368),
                              UINT16_C( 26666), UINT16_C( 13822), UINT16_C( 34046), UINT16_C( 24651),
                              UINT16_C(  8048), UINT16_C( 38825), UINT16_C( 44126), UINT16_C( 28762)),
      simde_x_mm512_set_epu16(UINT16_C( 38607), UINT16_C(  8074), UINT16_C( 18000), UINT16_C( 35687),
                              UINT16_C( 40415), UINT16_C(  3254), UINT16_C( 55282), UINT16_C( 38855),
                              UINT16_C( 41330), UINT16_C( 37148), UINT16_C( 25803), UINT16_C( 25877),
                              UINT16_C(   768), UINT16_C( 16244), UINT16_C( 11114), UINT16_C( 58324),
                              UINT16_C( 18192), UINT16_C( 32532), UINT16_C( 33700), UINT16_C( 60373),
                              UINT16_C( 20183), UINT16_C( 64042), UINT16_C(  2502), UINT16_C( 18488),
                              UINT16_C( 22771), UINT16_C( 21470), UINT16_C(  4556), UINT16_C( 26138),
                              UINT16_C( 19085), UINT16_C( 64613), UINT16_C( 55602), UINT16_C( 63371)),
      simde_x_mm512_set_epu16(UINT16_C(     0), UINT16_C(     5), UINT16_C(     0), UINT16_C(     1),
                              UINT16_C(     0), UINT16_C(    16), UINT16_C(     0), UINT16_C(     0),
                              UINT16_C(     1), UINT16_C(     1), UINT16_C(     1), UINT16_C(     2),
                              UINT16_C(    31), UINT16_C(     3), UINT16_C(     4), UINT16_C(     0),
                              UINT16_C(     2), UINT16_C(     1), UINT16_C(     1), UINT16_C(     0),
                              UINT16_C(     1), UINT16_C(     0), UINT16_C(    13), UINT16_C(     3),
                              UINT16_C(     1), UINT16_C(     0), UINT16_C(     7), UINT16_C(     0),
                              UINT16_C(     0), UINT16_C(     0), UINT16_C(     0), UINT16_C(     0)) },
    { simde_x_mm512_set_epu16(UINT16_C( 20057), UINT16_C( 26978), UINT16_C( 45741), UINT16_C( 34503),
                              UINT16_C( 54259), UINT16_C( 41436), UINT16_C( 43883), UINT16_C( 11009),
                              UINT16_C( 50212), UINT16_C(  9014), UINT16_C( 24117), UINT16_C( 34039),
                              UINT16_C( 58348), UINT16_C(  8311), UINT16_C( 31759), UINT16_C(  4002),
                              UINT16_C(  7525), UINT16_C(  3321), UINT16_C( 47299), UINT16_C( 64213),
                              UINT16_C( 13644), UINT16_C( 48153), UINT16_C( 45234), UINT16_C( 51700),
                              UINT16_C(  7513), UINT16_C(  1114), UINT16_C( 65336), UINT16_C( 10389),
                              UINT16_C( 33688), UINT16_C(  9445), UINT16_C( 60332), UINT16_C( 41466)),
      simde_x_mm512_set_epu16(UINT16_C( 48157), UINT16_C( 56913), UINT16_C( 55050), UINT16_C( 48859),
                              UINT16_C( 27895), UINT16_C( 48343), UINT16_C( 59593), UINT16_C( 60425),
                              UINT16_C( 62587), UINT16_C( 54231), UINT16_C( 52444), UINT16_C(  8140),
                              UINT16_C( 58695), UINT16_C(  2476), UINT16_C( 41101), UINT16_C(  7948),
                              UINT16_C( 26094), UINT16_C( 52354), UINT16_C( 30122), UINT16_C( 47688),
                              UINT16_C( 43801), UINT16_C( 57764), UINT16_C(  1809), UINT16_C( 33603),
                              UINT16_C(  8271), UINT16_C(  4936), UINT16_C(  7627), UINT16_C( 20477),
                              UINT16_C( 14608), UINT16_C( 25470), UINT16_C( 45836), UINT16_C( 25611)),
      simde_x_mm512_set_epu16(UINT16_C(     0), UINT16_C(     0), UINT16_C(     0), UINT16_C(     0),
                              UINT16_C(     1), UINT16_C(     0), UINT16_C(     0), UINT16_C(     0),
                              UINT16_C(     0), UINT16_C(     0), UINT16_C(     0), UINT16_C(     4),
                              UINT16_C(     0), UINT16_C(     3), UINT16_C(     0), UINT16_C(     0),
                              UINT16_C(     0), UINT16_C(     0), UINT16_C(     1), UINT16_C(     1),
                              UINT16_C(     0), UINT16_C(     0), UINT16_C(    25), UINT16_C(     1),
                              UINT16_C(     0), UINT16_C(     0), UINT16_C(     8), UINT16_C(     0),
                              UINT16_C(     2), UINT16_C(     0), UINT16_C(     1), UINT16_C(     1)) },
    { simde_x_mm512_set_epu16(UINT16_C( 26902), UINT16_C( 51011), UINT16_C( 57631), UINT16_C( 57521),
                              UINT16_C( 43405), UINT16_C( 18318), UINT16_C( 44023), UINT16_C(  9770),
                              UINT16_C(  4118), UINT16_C( 33099), UINT16_C(  6621), UINT16_C( 57639),
                              UINT16_C( 22002), UINT16_C( 33155), UINT16_C( 15537), UINT16_C( 38743),
                              UINT16_C( 26466), UINT16_C( 21183), UINT16_C(  5811), UINT16_C( 17016),
                              UINT16_C( 51162), UINT16_C( 46775), UINT16_C( 54252), UINT16_C( 64603),
                              UINT16_C( 30444), UINT16_C( 20573), UINT16_C( 50572), UINT16_C( 25607),
                              UINT16_C( 36721), UINT16_C( 36797), UINT16_C( 27147), UINT16_C( 62271)),
      simde_x_mm512_set_epu16(UINT16_C( 55381), UINT16_C( 52839), UINT16_C( 60314), UINT16_C( 33159),
                              UINT16_C( 32076), UINT16_C( 51820), UINT16_C( 13383), UINT16_C( 43204),
                              UINT16_C( 18058), UINT16_C( 42817), UINT16_C( 56737), UINT16_C( 40285),
                              UINT16_C( 49341), UINT16_C( 39323), UINT16_C( 53205), UINT16_C( 27016),
                              UINT16_C( 59998), UINT16_C( 61452), UINT16_C( 37377), UINT16_C( 37691),
                              UINT16_C( 64794), UINT16_C(  6696), UINT16_C(  3074), UINT16_C( 59025),
                              UINT16_C( 43625), UINT16_C( 28576), UINT16_C( 36042), UINT16_C( 42716),
                              UINT16_C( 47937), UINT16_C( 64195), UINT16_C(  8579), UINT16_C(   676)),
      simde_x_mm512_set_epu16(UINT16_C(     0), UINT16_C(     0), UINT16_C(     0), UINT16_C(     1),
                              UINT16_C(     1), UINT16_C(     0), UINT16_C(     3), UINT16_C(     0),
                              UINT16_C(     0), UINT16_C(     0), UINT16_C(     0), UINT16_C(     1),
                              UINT16_C(     0), UINT16_C(     0), UINT16_C(     0), UINT16_C(     1),
                              UINT16_C(     0), UINT16_C(     0), UINT16_C(     0), UINT16_C(     0),
                              UINT16_C(     0), UINT16_C(     6), UINT16_C(    17), UINT16_C(     1),
                              UINT16_C(     0), UINT16_C(     0), UINT16_C(     1), UINT16_C(     0),
                              UINT16_C(     0), UINT16_C(     0), UINT16_C(     3), UINT16_C(    92)) },
    { simde_x_mm512_set_epu16(UINT16_C(  7566), UINT16_C( 25511), UINT16_C( 59705), UINT16_C( 13989),
                              UINT16_C( 13965), UINT16_C( 34471), UINT16_C(    77), UINT16_C( 35152),
                              UINT16_C( 21705), UINT16_C( 42504), UINT16_C( 63033), UINT16_C( 56884),
                              UINT16_C( 42389), UINT16_C( 61527), UINT16_C(  7598), UINT16_C( 23051),
                              UINT16_C( 13886), UINT16_C( 28688), UINT16_C( 30551), UINT16_C( 36608),
                              UINT16_C( 56045), UINT16_C( 38987), UINT16_C( 64798), UINT16_C( 22350),
                              UINT16_C(  7981), UINT16_C( 50477), UINT16_C( 46688), UINT16_C( 16804),
                              UINT16_C( 33660), UINT16_C( 63749), UINT16_C( 29649), UINT16_C( 64815)),
      simde_x_mm512_set_epu16(UINT16_C( 18409), UINT16_C( 19069), UINT16_C( 20979), UINT16_C( 35774),
                              UINT16_C(  8112), UINT16_C( 25085), UINT16_C( 31664), UINT16_C( 55404),
                              UINT16_C( 63329), UINT16_C( 19403), UINT16_C( 33006), UINT16_C( 20365),
                              UINT16_C( 22045), UINT16_C( 41935), UINT16_C( 28665), UINT16_C( 35793),
                              UINT16_C( 26789), UINT16_C( 40241), UINT16_C( 34076), UINT16_C( 36189),
                              UINT16_C( 49507), UINT16_C( 32891), UINT16_C( 45700), UINT16_C( 31541),
                              UINT16_C( 33237), UINT16_C( 50719), UINT16_C( 22782), UINT16_C( 46902),
                              UINT16_C( 62792), UINT16_C(   907), UINT16_C(  9939), UINT16_C(   395)),
      simde_x_mm512_set_epu16(UINT16_C(     0), UINT16_C(     1), UINT16_C(     2), UINT16_C(     0),
                              UINT16_C(     1), UINT16_C(     1), UINT16_C(     0), UINT16_C(     0),
                              UINT16_C(     0), UINT16_C(     2), UINT16_C(     1), UINT16_C(     2),
                              UINT16_C(     1), UINT16_C(     1), UINT16_C(     0), UINT16_C(     0),
                              UINT16_C(     0), UINT16_C(     0), UINT16_C(     0), UINT16_C(     1),
                              UINT16_C(     1), UINT16_C(     1), UINT16_C(     1), UINT16_C(     0),
                              UINT16_C(     0), UINT16_C(     0), UINT16_C(     2), UINT16_C(     0),
                              UINT16_C(     0), UINT16_C(    70), UINT16_C(     2), UINT16_C(   164)) },
    { simde_x_mm512_set_epu16(UINT16_C( 40553), UINT16_C(  9260), UINT16_C(  6846), UINT16_C( 21618),
                              UINT16_C( 20365), UINT16_C( 26413), UINT16_C(  7670), UINT16_C(  6521),
                              UINT16_C( 13052), UINT16_C( 19892), UINT16_C( 40021), UINT16_C( 58092),
                              UINT16_C( 12337), UINT16_C( 14080), UINT16_C(  6934), UINT16_C( 61515),
                              UINT16_C(  1885), UINT16_C( 11733), UINT16_C(  7371), UINT16_C( 24583),
                              UINT16_C( 48349), UINT16_C( 37475), UINT16_C( 47206), UINT16_C( 54691),
                              UINT16_C( 63460), UINT16_C(  2107), UINT16_C( 62169), UINT16_C( 38808),
                              UINT16_C( 21341), UINT16_C( 51834), UINT16_C( 26283), UINT16_C( 38235)),
      simde_x_mm512_set_epu16(UINT16_C(  9227), UINT16_C( 20728), UINT16_C( 22448), UINT16_C( 22271),
                              UINT16_C( 38010), UINT16_C(  3228), UINT16_C( 38598), UINT16_C( 15839),
                              UINT16_C(  4554), UINT16_C( 22831), UINT16_C( 44103), UINT16_C( 32351),
                              UINT16_C( 46747), UINT16_C( 20983), UINT16_C( 61889), UINT16_C( 26454),
                              UINT16_C( 63311), UINT16_C( 19804), UINT16_C( 62773), UINT16_C( 56806),
                              UINT16_C( 36384), UINT16_C( 25302), UINT16_C( 37143), UINT16_C(  3478),
                              UINT16_C( 59861), UINT16_C( 61175), UINT16_C( 48658), UINT16_C( 23119),
                              UINT16_C( 30252), UINT16_C( 63116), UINT16_C( 13170), UINT16_C( 44087)),
      simde_x_mm512_set_epu16(UINT16_C(     4), UINT16_C(     0), UINT16_C(     0), UINT16_C(     0),
                              UINT16_C(     0), UINT16_C(     8), UINT16_C(     0), UINT16_C(     0),
                              UINT16_C(     2), UINT16_C(     0), UINT16_C(     0), UINT16_C(     1),
                              UINT16_C(     0), UINT16_C(     0), UINT16_C(     0), UINT16_C(     2),
                              UINT16_C(     0), UINT16_C(     0), UINT16_C(     0), UINT16_C(     0),
                              UINT16_C(     1), UINT16_C(     1), UINT16_C(     1), UINT16_C(    15),
                              UINT16_C(     1), UINT16_C(     0), UINT16_C(     1), UINT16_C(     1),
                              UINT16_C(     0), UINT16_C(     0), UINT16_C(     1), UINT16_C(     0)) },
    { simde_x_mm512_set_epu16(UINT16_C( 22335), UINT16_C( 12112), UINT16_C(  9189), UINT16_C(  1311),
                              UINT16_C( 58441), UINT16_C( 13615), UINT16_C( 43712), UINT16_C( 31469),
                              UINT16_C( 12162), UINT16_C( 56166), UINT16_C( 41769), UINT16_C( 50135),
                              UINT16_C( 50998), UINT16_C( 24958), UINT16_C(  2725), UINT16_C( 39768),
                              UINT16_C( 47167), UINT16_C( 24484), UINT16_C( 16711), UINT16_C( 44632),
                              UINT16_C( 46990), UINT16_C( 25102), UINT16_C(  6573), UINT16_C( 22274),
                              UINT16_C( 49039), UINT16_C( 38914), UINT16_C( 32256), UINT16_C( 41529),
                              UINT16_C( 62756), UINT16_C( 61238), UINT16_C(  8613), UINT16_C( 51028)),
      simde_x_mm512_set_epu16(UINT16_C( 30472), UINT16_C( 36773), UINT16_C(  7714), UINT16_C( 18947),
                              UINT16_C(  7066), UINT16_C( 47844), UINT16_C( 58651), UINT16_C(  1841),
                              UINT16_C( 35799), UINT16_C( 50579), UINT16_C( 32926), UINT16_C( 26598),
                              UINT16_C( 39537), UINT16_C( 61137), UINT16_C(  5946), UINT16_C(  2262),
                              UINT16_C( 60116), UINT16_C( 12953), UINT16_C( 38045), UINT16_C( 47787),
                              UINT16_C( 30618), UINT16_C( 37811), UINT16_C( 51748), UINT16_C( 52236),
                              UINT16_C( 23394), UINT16_C(  2441), UINT16_C( 32382), UINT16_C(  9384),
                              UINT16_C( 25792), UINT16_C( 56163), UINT16_C( 22658), UINT16_C( 20939)),
      simde_x_mm512_set_epu16(UINT16_C(     0), UINT16_C(     0), UINT16_C(     1), UINT16_C(     0),
                              UINT16_C(     8), UINT16_C(     0), UINT16_C(     0), UINT16_C(    17),
                              UINT16_C(     0), UINT16_C(     1), UINT16_C(     1), UINT16_C(     1),
                              UINT16_C(     1), UINT16_C(     0), UINT16_C(     0), UINT16_C(    17),
                              UINT16_C(     0), UINT16_C(     1), UINT16_C(     0), UINT16_C(     0),
                              UINT16_C(     1), UINT16_C(     0), UINT16_C(     0), UINT16_C(     0),
                              UINT16_C(     2), UINT16_C(    15), UINT16_C(     0), UINT16_C(     4),
                              UINT16_C(     2), UINT16_C(     1), UINT16_C(     0), UINT16_C(     2)) },
    { simde_x_mm512_set_epu16(UINT16_C( 13867), UINT16_C( 28091), UINT16_C( 35390), UINT16_C( 56986),
                              UINT16_C( 31509), UINT16_C( 63331), UINT16_C(  9520), UINT16_C( 29929),
                              UINT16_C( 24571), UINT16_C( 37741), UINT16_C( 52686), UINT16_C( 14609),
                              UINT16_C( 31001), UINT16_C(   823), UINT16_C( 45697), UINT16_C( 38351),
                              UINT16_C( 35780), UINT16_C( 41006), UINT16_C(  3633), UINT16_C( 45500),
                              UINT16_C( 30184), UINT16_C( 27396), UINT16_C(  1171), UINT16_C( 25936),
                              UINT16_C( 61703), UINT16_C( 57786), UINT16_C( 19453), UINT16_C( 30002),
                              UINT16_C(  6315), UINT16_C(   244), UINT16_C(  8399), UINT16_C( 57456)),
      simde_x_mm512_set_epu16(UINT16_C( 18752), UINT16_C( 27431), UINT16_C( 53704), UINT16_C( 42625),
                              UINT16_C( 42869), UINT16_C( 41745), UINT16_C( 47543), UINT16_C( 11401),
                              UINT16_C( 26966), UINT16_C( 26500), UINT16_C(  7486), UINT16_C(  7825),
                              UINT16_C( 17767), UINT16_C( 58506), UINT16_C( 36234), UINT16_C( 38373),
                              UINT16_C( 54992), UINT16_C( 46906), UINT16_C( 52104), UINT16_C( 31285),
                              UINT16_C( 34932), UINT16_C( 29467), UINT16_C( 33781), UINT16_C(   883),
                              UINT16_C( 23995), UINT16_C( 43069), UINT16_C( 53587), UINT16_C( 11327),
                              UINT16_C( 36611), UINT16_C(  7518), UINT16_C( 30015), UINT16_C( 30285)),
      simde_x_mm512_set_epu16(UINT16_C(     0), UINT16_C(     1), UINT16_C(     0), UINT16_C(     1),
                              UINT16_C(     0), UINT16_C(     1), UINT16_C(     0), UINT16_C(     2),
                              UINT16_C(     0), UINT16_C(     1), UINT16_C(     7), UINT16_C(     1),
                              UINT16_C(     1), UINT16_C(     0), UINT16_C(     1), UINT16_C(     0),
                              UINT16_C(     0), UINT16_C(     0), UINT16_C(     0), UINT16_C(     1),
                              UINT16_C(     0), UINT16_C(     0), UINT16_C(     0), UINT16_C(    29),
                              UINT16_C(     2), UINT16_C(     1), UINT16_C(     0), UINT16_C(     2),
                              UINT16_C(     0), UINT16_C(     0), UINT16_C(     0), UINT16_C(     1)) },
    { simde_x_mm512_set_epu16(UINT16_C( 19003), UINT16_C( 26627), UINT16_C( 63705), UINT16_C( 34218),
                              UINT16_C( 36055), UINT16_C( 13847), UINT16_C( 44625), UINT16_C(  9042),
                              UINT16_C( 36148), UINT16_C( 11660), UINT16_C( 32339), UINT16_C( 39715),
                              UINT16_C( 47178), UINT16_C( 21002), UINT16_C( 60706), UINT16_C(  8527),
                              UINT16_C( 26072), UINT16_C( 29611), UINT16_C( 18348), UINT16_C(   953),
                              UINT16_C( 33382), UINT16_C( 22717), UINT16_C( 50122), UINT16_C( 52414),
                              UINT16_C( 59278), UINT16_C( 54225), UINT16_C( 31952), UINT16_C( 29752),
                              UINT16_C( 37488), UINT16_C( 20614), UINT16_C(  1055), UINT16_C( 61149)),
      simde_x_mm512_set_epu16(UINT16_C( 59727), UINT16_C(  3072), UINT16_C(  8626), UINT16_C( 14922),
                              UINT16_C( 64116), UINT16_C( 36372), UINT16_C( 22591), UINT16_C(  8828),
                              UINT16_C( 64048), UINT16_C( 56808), UINT16_C( 56651), UINT16_C( 39760),
                              UINT16_C( 59817), UINT16_C( 50914), UINT16_C( 21275), UINT16_C( 35106),
                              UINT16_C(  6020), UINT16_C( 27245), UINT16_C( 34763), UINT16_C( 25208),
                              UINT16_C( 25908), UINT16_C( 21036), UINT16_C( 36366), UINT16_C( 25589),
                              UINT16_C(  2188), UINT16_C( 36219), UINT16_C( 56227), UINT16_C( 50409),
                              UINT16_C(  8889), UINT16_C( 58476), UINT16_C( 24556), UINT16_C( 24873)),
      simde_x_mm512_set_epu16(UINT16_C(     0), UINT16_C(     8), UINT16_C(     7), UINT16_C(     2),
                              UINT16_C(     0), UINT16_C(     0), UINT16_C(     1), UINT16_C(     1),
                              UINT16_C(     0), UINT16_C(     0), UINT16_C(     0), UINT16_C(     0),
                              UINT16_C(     0), UINT16_C(     0), UINT16_C(     2), UINT16_C(     0),
                              UINT16_C(     4), UINT16_C(     1), UINT16_C(     0), UINT16_C(     0),
                              UINT16_C(     1), UINT16_C(     1), UINT16_C(     1), UINT16_C(     2),
                              UINT16_C(    27), UINT16_C(     1), UINT16_C(     0), UINT16_C(     0),
                              UINT16_C(     4), UINT16_C(     0), UINT16_C(     0), UINT16_C(     2)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_div_epu16(test_vec[i].a, test_vec[i].b);
    simde_assert_m512i_u16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_div_epu32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512i a;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {
    { simde_x_mm512_set_epu32(UINT32_C( 691121094), UINT32_C( 674034227), UINT32_C(2329532409), UINT32_C(3374680349),
                              UINT32_C(3920294270), UINT32_C(3054162118), UINT32_C(1568850865), UINT32_C(3151989757),
                              UINT32_C(3215450688), UINT32_C(3586813553), UINT32_C(1508722402), UINT32_C(2220621656),
                              UINT32_C(1747596798), UINT32_C(2231263307), UINT32_C( 527472553), UINT32_C(2891870298)),
      simde_x_mm512_set_epu32(UINT32_C(2530156426), UINT32_C(1179683687), UINT32_C(2648640694), UINT32_C(3623000007),
                              UINT32_C(2708640028), UINT32_C(1691051285), UINT32_C(  50347892), UINT32_C( 728425428),
                              UINT32_C(1192263444), UINT32_C(2208623573), UINT32_C(1322777130), UINT32_C( 163989560),
                              UINT32_C(1492341726), UINT32_C( 298608154), UINT32_C(1250819173), UINT32_C(3643996043)),
      simde_x_mm512_set_epu32(UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),
                              UINT32_C(         1), UINT32_C(         1), UINT32_C(        31), UINT32_C(         4),
                              UINT32_C(         2), UINT32_C(         1), UINT32_C(         1), UINT32_C(        13),
                              UINT32_C(         1), UINT32_C(         7), UINT32_C(         0), UINT32_C(         0)) },
    { simde_x_mm512_set_epu32(UINT32_C(1314482530), UINT32_C(2997716679), UINT32_C(3555959260), UINT32_C(2875927297),
                              UINT32_C(3290702646), UINT32_C(1580565751), UINT32_C(3823902839), UINT32_C(2081361826),
                              UINT32_C( 493161721), UINT32_C(3099851477), UINT32_C( 894221337), UINT32_C(2964507124),
                              UINT32_C( 492373082), UINT32_C(4281870485), UINT32_C(2207786213), UINT32_C(3953959418)),
      simde_x_mm512_set_epu32(UINT32_C(3156074065), UINT32_C(3607805659), UINT32_C(1828175063), UINT32_C(3905547273),
                              UINT32_C(4101755863), UINT32_C(3436978124), UINT32_C(3846637996), UINT32_C(2693603084),
                              UINT32_C(1710148738), UINT32_C(1974123080), UINT32_C(2870600100), UINT32_C( 118588227),
                              UINT32_C( 542053192), UINT32_C( 499863549), UINT32_C( 957375358), UINT32_C(3003933707)),
      simde_x_mm512_set_epu32(UINT32_C(         0), UINT32_C(         0), UINT32_C(         1), UINT32_C(         0),
                              UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),
                              UINT32_C(         0), UINT32_C(         1), UINT32_C(         0), UINT32_C(        24),
                              UINT32_C(         0), UINT32_C(         8), UINT32_C(         2), UINT32_C(         1)) },
    { simde_x_mm512_set_epu32(UINT32_C(1763100483), UINT32_C(3776962737), UINT32_C(2844608398), UINT32_C(2885101098),
                              UINT32_C( 269910347), UINT32_C( 433971495), UINT32_C(1441956227), UINT32_C(1018271575),
                              UINT32_C(1734496959), UINT32_C( 380846712), UINT32_C(3352999607), UINT32_C(3555523675),
                              UINT32_C(1995198557), UINT32_C(3314312199), UINT32_C(2406584253), UINT32_C(1779168063)),
      simde_x_mm512_set_epu32(UINT32_C(3629502055), UINT32_C(3952771463), UINT32_C(2102184556), UINT32_C( 877111492),
                              UINT32_C(1183491905), UINT32_C(3718356317), UINT32_C(3233651099), UINT32_C(3486869896),
                              UINT32_C(3932090380), UINT32_C(2449576763), UINT32_C(4246346280), UINT32_C( 201516689),
                              UINT32_C(2859036576), UINT32_C(2362091228), UINT32_C(3141663427), UINT32_C( 562234020)),
      simde_x_mm512_set_epu32(UINT32_C(         0), UINT32_C(         0), UINT32_C(         1), UINT32_C(         3),
                              UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),
                              UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(        17),
                              UINT32_C(         0), UINT32_C(         1), UINT32_C(         0), UINT32_C(         3)) },
    { simde_x_mm512_set_epu32(UINT32_C( 495870887), UINT32_C(3912840869), UINT32_C( 915244711), UINT32_C(   5081424),
                              UINT32_C(1422501384), UINT32_C(4130987572), UINT32_C(2778067031), UINT32_C( 497965579),
                              UINT32_C( 910061584), UINT32_C(2002226944), UINT32_C(3673004107), UINT32_C(4246624078),
                              UINT32_C( 523093293), UINT32_C(3059761572), UINT32_C(2206005509), UINT32_C(1943141679)),
      simde_x_mm512_set_epu32(UINT32_C(1206471293), UINT32_C(1374915518), UINT32_C( 531653117), UINT32_C(2075187308),
                              UINT32_C(4150348747), UINT32_C(2163101581), UINT32_C(1444783055), UINT32_C(1878625233),
                              UINT32_C(1755684145), UINT32_C(2233240925), UINT32_C(3244523643), UINT32_C(2995026741),
                              UINT32_C(2178270751), UINT32_C(1493088054), UINT32_C(4115137419), UINT32_C( 651362699)),
      simde_x_mm512_set_epu32(UINT32_C(         0), UINT32_C(         2), UINT32_C(         1), UINT32_C(         0),
                              UINT32_C(         0), UINT32_C(         1), UINT32_C(         1), UINT32_C(         0),
                              UINT32_C(         0), UINT32_C(         0), UINT32_C(         1), UINT32_C(         1),
                              UINT32_C(         0), UINT32_C(         2), UINT32_C(         0), UINT32_C(         2)) },
    { simde_x_mm512_set_epu32(UINT32_C(2657690668), UINT32_C( 448681074), UINT32_C(1334667053), UINT32_C( 502667641),
                              UINT32_C( 855395764), UINT32_C(2622874348), UINT32_C( 808531712), UINT32_C( 454488139),
                              UINT32_C( 123547093), UINT32_C( 483090439), UINT32_C(3168637539), UINT32_C(3093747107),
                              UINT32_C(4158916667), UINT32_C(4074346392), UINT32_C(1398655610), UINT32_C(1722520923)),
      simde_x_mm512_set_epu32(UINT32_C( 604721400), UINT32_C(1471174399), UINT32_C(2491026588), UINT32_C(2529574367),
                              UINT32_C( 298473775), UINT32_C(2890366559), UINT32_C(3063632375), UINT32_C(4055983958),
                              UINT32_C(4149169500), UINT32_C(4113948134), UINT32_C(2384487126), UINT32_C(2434207126),
                              UINT32_C(3923111671), UINT32_C(3188873807), UINT32_C(1982658188), UINT32_C( 863153207)),
      simde_x_mm512_set_epu32(UINT32_C(         4), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),
                              UINT32_C(         2), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),
                              UINT32_C(         0), UINT32_C(         0), UINT32_C(         1), UINT32_C(         1),
                              UINT32_C(         1), UINT32_C(         1), UINT32_C(         0), UINT32_C(         1)) },
    { simde_x_mm512_set_epu32(UINT32_C(1463758672), UINT32_C( 602211615), UINT32_C(3830002991), UINT32_C(2864741101),
                              UINT32_C( 797104998), UINT32_C(2737423319), UINT32_C(3342229886), UINT32_C( 178625368),
                              UINT32_C(3091160996), UINT32_C(1095216728), UINT32_C(3079561742), UINT32_C( 430790402),
                              UINT32_C(3213858818), UINT32_C(2113970745), UINT32_C(4112838454), UINT32_C( 564512596)),
      simde_x_mm512_set_epu32(UINT32_C(1997049765), UINT32_C( 505563651), UINT32_C( 463125220), UINT32_C(3843753777),
                              UINT32_C(2346173843), UINT32_C(2157864934), UINT32_C(2591157969), UINT32_C( 389679318),
                              UINT32_C(3939775129), UINT32_C(2493364907), UINT32_C(2006619059), UINT32_C(3391409164),
                              UINT32_C(1533151625), UINT32_C(2122196136), UINT32_C(1690360675), UINT32_C(1484935627)),
      simde_x_mm512_set_epu32(UINT32_C(         0), UINT32_C(         1), UINT32_C(         8), UINT32_C(         0),
                              UINT32_C(         0), UINT32_C(         1), UINT32_C(         1), UINT32_C(         0),
                              UINT32_C(         0), UINT32_C(         0), UINT32_C(         1), UINT32_C(         0),
                              UINT32_C(         2), UINT32_C(         0), UINT32_C(         2), UINT32_C(         0)) },
    { simde_x_mm512_set_epu32(UINT32_C( 908815803), UINT32_C(2319376026), UINT32_C(2065037155), UINT32_C( 623932649),
                              UINT32_C(1610322797), UINT32_C(3452844305), UINT32_C(2031682359), UINT32_C(2994836943),
                              UINT32_C(2344919086), UINT32_C( 238137788), UINT32_C(1978166020), UINT32_C(  76768592),
                              UINT32_C(4043825594), UINT32_C(1274901810), UINT32_C( 413860084), UINT32_C( 550494320)),
      simde_x_mm512_set_epu32(UINT32_C(1228958503), UINT32_C(3519587969), UINT32_C(2809504529), UINT32_C(3115789449),
                              UINT32_C(1767270276), UINT32_C( 490610321), UINT32_C(1164436618), UINT32_C(2374669797),
                              UINT32_C(3604002618), UINT32_C(3414719029), UINT32_C(2289333019), UINT32_C(2213872499),
                              UINT32_C(1572579389), UINT32_C(3511888959), UINT32_C(2399346014), UINT32_C(1967093325)),
      simde_x_mm512_set_epu32(UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),
                              UINT32_C(         0), UINT32_C(         7), UINT32_C(         1), UINT32_C(         1),
                              UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),
                              UINT32_C(         2), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0)) },
    { simde_x_mm512_set_epu32(UINT32_C(1245407235), UINT32_C(4175005098), UINT32_C(2362914327), UINT32_C(2924553042),
                              UINT32_C(2369006988), UINT32_C(2119408419), UINT32_C(3091878410), UINT32_C(3978436943),
                              UINT32_C(1708684203), UINT32_C(1202455481), UINT32_C(2187745469), UINT32_C(3284847806),
                              UINT32_C(3884897233), UINT32_C(2094036024), UINT32_C(2456834182), UINT32_C(  69201629)),
      simde_x_mm512_set_epu32(UINT32_C(3914271744), UINT32_C( 565328458), UINT32_C(4201942548), UINT32_C(1480532604),
                              UINT32_C(4197506536), UINT32_C(3712719696), UINT32_C(3920217826), UINT32_C(1394313506),
                              UINT32_C( 394553965), UINT32_C(2278253176), UINT32_C(1697927724), UINT32_C(2383307765),
                              UINT32_C( 143428987), UINT32_C(3684943081), UINT32_C( 582607980), UINT32_C(1609326889)),
      simde_x_mm512_set_epu32(UINT32_C(         0), UINT32_C(         7), UINT32_C(         0), UINT32_C(         1),
                              UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         2),
                              UINT32_C(         4), UINT32_C(         0), UINT32_C(         1), UINT32_C(         1),
                              UINT32_C(        27), UINT32_C(         0), UINT32_C(         4), UINT32_C(         0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_div_epu32(test_vec[i].a, test_vec[i].b);
    simde_assert_m512i_u32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_mask_div_epu32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512i src;
    simde__mmask16 k;
    simde__m512i a;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {
    { simde_x_mm512_set_epu32(UINT32_C( 691121094), UINT32_C( 674034227), UINT32_C(2329532409), UINT32_C(3374680349),
                              UINT32_C(3920294270), UINT32_C(3054162118), UINT32_C(1568850865), UINT32_C(3151989757),
                              UINT32_C(3215450688), UINT32_C(3586813553), UINT32_C(1508722402), UINT32_C(2220621656),
                              UINT32_C(1747596798), UINT32_C(2231263307), UINT32_C( 527472553), UINT32_C(2891870298)),
      UINT16_C(63371),
      simde_x_mm512_set_epu32(UINT32_C(3953959418), UINT32_C(2530156426), UINT32_C(1179683687), UINT32_C(2648640694),
                              UINT32_C(3623000007), UINT32_C(2708640028), UINT32_C(1691051285), UINT32_C(  50347892),
                              UINT32_C( 728425428), UINT32_C(1192263444), UINT32_C(2208623573), UINT32_C(1322777130),
                              UINT32_C( 163989560), UINT32_C(1492341726), UINT32_C( 298608154), UINT32_C(1250819173)),
      simde_x_mm512_set_epu32(UINT32_C(3003933707), UINT32_C(1314482530), UINT32_C(2997716679), UINT32_C(3555959260),
                              UINT32_C(2875927297), UINT32_C(3290702646), UINT32_C(1580565751), UINT32_C(3823902839),
                              UINT32_C(2081361826), UINT32_C( 493161721), UINT32_C(3099851477), UINT32_C( 894221337),
                              UINT32_C(2964507124), UINT32_C( 492373082), UINT32_C(4281870485), UINT32_C(2207786213)),
      simde_x_mm512_set_epu32(UINT32_C(         1), UINT32_C(         1), UINT32_C(         0), UINT32_C(         0),
                              UINT32_C(3920294270), UINT32_C(         0), UINT32_C(         1), UINT32_C(         0),
                              UINT32_C(         0), UINT32_C(3586813553), UINT32_C(1508722402), UINT32_C(2220621656),
                              UINT32_C(         0), UINT32_C(2231263307), UINT32_C(         0), UINT32_C(         0)) },
    { simde_x_mm512_set_epu32(UINT32_C(1779168063), UINT32_C(3156074065), UINT32_C(3607805659), UINT32_C(1828175063),
                              UINT32_C(3905547273), UINT32_C(4101755863), UINT32_C(3436978124), UINT32_C(3846637996),
                              UINT32_C(2693603084), UINT32_C(1710148738), UINT32_C(1974123080), UINT32_C(2870600100),
                              UINT32_C( 118588227), UINT32_C( 542053192), UINT32_C( 499863549), UINT32_C( 957375358)),
      UINT16_C(36797),
      simde_x_mm512_set_epu32(UINT32_C(3141663427), UINT32_C( 562234020), UINT32_C(1763100483), UINT32_C(3776962737),
                              UINT32_C(2844608398), UINT32_C(2885101098), UINT32_C( 269910347), UINT32_C( 433971495),
                              UINT32_C(1441956227), UINT32_C(1018271575), UINT32_C(1734496959), UINT32_C( 380846712),
                              UINT32_C(3352999607), UINT32_C(3555523675), UINT32_C(1995198557), UINT32_C(3314312199)),
      simde_x_mm512_set_epu32(UINT32_C(2206005509), UINT32_C(1943141679), UINT32_C(3629502055), UINT32_C(3952771463),
                              UINT32_C(2102184556), UINT32_C( 877111492), UINT32_C(1183491905), UINT32_C(3718356317),
                              UINT32_C(3233651099), UINT32_C(3486869896), UINT32_C(3932090380), UINT32_C(2449576763),
                              UINT32_C(4246346280), UINT32_C( 201516689), UINT32_C(2859036576), UINT32_C(2362091228)),
      simde_x_mm512_set_epu32(UINT32_C(         1), UINT32_C(3156074065), UINT32_C(3607805659), UINT32_C(1828175063),
                              UINT32_C(         1), UINT32_C(         3), UINT32_C(         0), UINT32_C(         0),
                              UINT32_C(         0), UINT32_C(1710148738), UINT32_C(         0), UINT32_C(         0),
                              UINT32_C(         0), UINT32_C(        17), UINT32_C( 499863549), UINT32_C(         1)) },
    { simde_x_mm512_set_epu32(UINT32_C(4115137419), UINT32_C( 651362699), UINT32_C( 495870887), UINT32_C(3912840869),
                              UINT32_C( 915244711), UINT32_C(   5081424), UINT32_C(1422501384), UINT32_C(4130987572),
                              UINT32_C(2778067031), UINT32_C( 497965579), UINT32_C( 910061584), UINT32_C(2002226944),
                              UINT32_C(3673004107), UINT32_C(4246624078), UINT32_C( 523093293), UINT32_C(3059761572)),
      UINT16_C(46902),
      simde_x_mm512_set_epu32(UINT32_C(4074346392), UINT32_C(1398655610), UINT32_C(1722520923), UINT32_C(1206471293),
                              UINT32_C(1374915518), UINT32_C( 531653117), UINT32_C(2075187308), UINT32_C(4150348747),
                              UINT32_C(2163101581), UINT32_C(1444783055), UINT32_C(1878625233), UINT32_C(1755684145),
                              UINT32_C(2233240925), UINT32_C(3244523643), UINT32_C(2995026741), UINT32_C(2178270751)),
      simde_x_mm512_set_epu32(UINT32_C(3188873807), UINT32_C(1982658188), UINT32_C( 863153207), UINT32_C(2657690668),
                              UINT32_C( 448681074), UINT32_C(1334667053), UINT32_C( 502667641), UINT32_C( 855395764),
                              UINT32_C(2622874348), UINT32_C( 808531712), UINT32_C( 454488139), UINT32_C( 123547093),
                              UINT32_C( 483090439), UINT32_C(3168637539), UINT32_C(3093747107), UINT32_C(4158916667)),
      simde_x_mm512_set_epu32(UINT32_C(         1), UINT32_C( 651362699), UINT32_C(         1), UINT32_C(         0),
                              UINT32_C( 915244711), UINT32_C(         0), UINT32_C(         4), UINT32_C(         4),
                              UINT32_C(2778067031), UINT32_C( 497965579), UINT32_C(         4), UINT32_C(        14),
                              UINT32_C(3673004107), UINT32_C(         1), UINT32_C(         0), UINT32_C(3059761572)) },
    { simde_x_mm512_set_epu32(UINT32_C(2113970745), UINT32_C(4112838454), UINT32_C( 564512596), UINT32_C( 604721400),
                              UINT32_C(1471174399), UINT32_C(2491026588), UINT32_C(2529574367), UINT32_C( 298473775),
                              UINT32_C(2890366559), UINT32_C(3063632375), UINT32_C(4055983958), UINT32_C(4149169500),
                              UINT32_C(4113948134), UINT32_C(2384487126), UINT32_C(2434207126), UINT32_C(3923111671)),
      UINT16_C(38914),
      simde_x_mm512_set_epu32(UINT32_C(1533151625), UINT32_C(2122196136), UINT32_C(1690360675), UINT32_C(1484935627),
                              UINT32_C(1463758672), UINT32_C( 602211615), UINT32_C(3830002991), UINT32_C(2864741101),
                              UINT32_C( 797104998), UINT32_C(2737423319), UINT32_C(3342229886), UINT32_C( 178625368),
                              UINT32_C(3091160996), UINT32_C(1095216728), UINT32_C(3079561742), UINT32_C( 430790402)),
      simde_x_mm512_set_epu32(UINT32_C(4043825594), UINT32_C(1274901810), UINT32_C( 413860084), UINT32_C( 550494320),
                              UINT32_C(1997049765), UINT32_C( 505563651), UINT32_C( 463125220), UINT32_C(3843753777),
                              UINT32_C(2346173843), UINT32_C(2157864934), UINT32_C(2591157969), UINT32_C( 389679318),
                              UINT32_C(3939775129), UINT32_C(2493364907), UINT32_C(2006619059), UINT32_C(3391409164)),
      simde_x_mm512_set_epu32(UINT32_C(         0), UINT32_C(4112838454), UINT32_C( 564512596), UINT32_C(         2),
                              UINT32_C(         0), UINT32_C(2491026588), UINT32_C(2529574367), UINT32_C( 298473775),
                              UINT32_C(2890366559), UINT32_C(3063632375), UINT32_C(4055983958), UINT32_C(4149169500),
                              UINT32_C(4113948134), UINT32_C(2384487126), UINT32_C(         1), UINT32_C(3923111671)) },
    { simde_x_mm512_set_epu32(UINT32_C(1572579389), UINT32_C(3511888959), UINT32_C(2399346014), UINT32_C(1967093325),
                              UINT32_C( 908815803), UINT32_C(2319376026), UINT32_C(2065037155), UINT32_C( 623932649),
                              UINT32_C(1610322797), UINT32_C(3452844305), UINT32_C(2031682359), UINT32_C(2994836943),
                              UINT32_C(2344919086), UINT32_C( 238137788), UINT32_C(1978166020), UINT32_C(  76768592)),
      UINT16_C(  883),
      simde_x_mm512_set_epu32(UINT32_C(3284847806), UINT32_C(3884897233), UINT32_C(2094036024), UINT32_C(2456834182),
                              UINT32_C(  69201629), UINT32_C(1228958503), UINT32_C(3519587969), UINT32_C(2809504529),
                              UINT32_C(3115789449), UINT32_C(1767270276), UINT32_C( 490610321), UINT32_C(1164436618),
                              UINT32_C(2374669797), UINT32_C(3604002618), UINT32_C(3414719029), UINT32_C(2289333019)),
      simde_x_mm512_set_epu32(UINT32_C(2383307765), UINT32_C( 143428987), UINT32_C(3684943081), UINT32_C( 582607980),
                              UINT32_C(1609326889), UINT32_C(1245407235), UINT32_C(4175005098), UINT32_C(2362914327),
                              UINT32_C(2924553042), UINT32_C(2369006988), UINT32_C(2119408419), UINT32_C(3091878410),
                              UINT32_C(3978436943), UINT32_C(1708684203), UINT32_C(1202455481), UINT32_C(2187745469)),
      simde_x_mm512_set_epu32(UINT32_C(1572579389), UINT32_C(3511888959), UINT32_C(2399346014), UINT32_C(1967093325),
                              UINT32_C( 908815803), UINT32_C(2319376026), UINT32_C(         0), UINT32_C(         1),
                              UINT32_C(1610322797), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),
                              UINT32_C(2344919086), UINT32_C( 238137788), UINT32_C(         2), UINT32_C(         1)) },
    { simde_x_mm512_set_epu32(UINT32_C(2117071873), UINT32_C(2857077767), UINT32_C(3918893192), UINT32_C(1087893388),
                              UINT32_C(3851784011), UINT32_C(3914271744), UINT32_C( 565328458), UINT32_C(4201942548),
                              UINT32_C(1480532604), UINT32_C(4197506536), UINT32_C(3712719696), UINT32_C(3920217826),
                              UINT32_C(1394313506), UINT32_C( 394553965), UINT32_C(2278253176), UINT32_C(1697927724)),
      UINT16_C(12254),
      simde_x_mm512_set_epu32(UINT32_C(  56443211), UINT32_C(2258452653), UINT32_C(3784696472), UINT32_C(1139427205),
                              UINT32_C(1090384090), UINT32_C(2389735891), UINT32_C(2215607313), UINT32_C(3817672405),
                              UINT32_C(3621770268), UINT32_C(2071747620), UINT32_C(3852178197), UINT32_C(3693632585),
                              UINT32_C( 319530416), UINT32_C(2179954815), UINT32_C(3793236393), UINT32_C( 340519338)),
      simde_x_mm512_set_epu32(UINT32_C(1219537084), UINT32_C(1349635715), UINT32_C( 732887738), UINT32_C(2566325375),
                              UINT32_C(2906533885), UINT32_C(1765754685), UINT32_C(2719983633), UINT32_C( 846129112),
                              UINT32_C(1578410935), UINT32_C(2635094838), UINT32_C(1045536663), UINT32_C( 957117985),
                              UINT32_C(3029008645), UINT32_C(1309498779), UINT32_C(3293951997), UINT32_C(1022360677)),
      simde_x_mm512_set_epu32(UINT32_C(2117071873), UINT32_C(2857077767), UINT32_C(         5), UINT32_C(1087893388),
                              UINT32_C(         0), UINT32_C(         1), UINT32_C(         0), UINT32_C(         4),
                              UINT32_C(         2), UINT32_C(         0), UINT32_C(3712719696), UINT32_C(         3),
                              UINT32_C(         0), UINT32_C(         1), UINT32_C(         1), UINT32_C(1697927724)) },
    { simde_x_mm512_set_epu32(UINT32_C(3990081318), UINT32_C( 991545752), UINT32_C(4151932359), UINT32_C( 843112042),
                              UINT32_C(4067412513), UINT32_C(2124182542), UINT32_C(2768721208), UINT32_C(2302989914),
                              UINT32_C(1224533822), UINT32_C(3475606100), UINT32_C(3610957044), UINT32_C(2556046111),
                              UINT32_C(3035396524), UINT32_C(3603101367), UINT32_C(3321443925), UINT32_C(  45581573)),
      UINT16_C(42669),
      simde_x_mm512_set_epu32(UINT32_C(4138167693), UINT32_C(3221954957), UINT32_C(2164435171), UINT32_C( 397240391),
                              UINT32_C( 200936922), UINT32_C(3263986987), UINT32_C(2536604122), UINT32_C(3629380929),
                              UINT32_C( 453331046), UINT32_C(1704580573), UINT32_C(1606190487), UINT32_C(3209309249),
                              UINT32_C(2959497652), UINT32_C(3926896735), UINT32_C(2875407663), UINT32_C(2069966669)),
      simde_x_mm512_set_epu32(UINT32_C(1379668640), UINT32_C(  66581512), UINT32_C(3737665499), UINT32_C( 304428974),
                              UINT32_C(2686704508), UINT32_C( 532978979), UINT32_C( 946958552), UINT32_C(2383642627),
                              UINT32_C(2176874140), UINT32_C( 283691898), UINT32_C(3848894665), UINT32_C(3836186002),
                              UINT32_C(1951055651), UINT32_C( 765387914), UINT32_C( 822559116), UINT32_C(   7445617)),
      simde_x_mm512_set_epu32(UINT32_C(         2), UINT32_C( 991545752), UINT32_C(         0), UINT32_C( 843112042),
                              UINT32_C(4067412513), UINT32_C(         6), UINT32_C(         2), UINT32_C(2302989914),
                              UINT32_C(         0), UINT32_C(3475606100), UINT32_C(         0), UINT32_C(2556046111),
                              UINT32_C(         1), UINT32_C(         5), UINT32_C(3321443925), UINT32_C(       278)) },
    { simde_x_mm512_set_epu32(UINT32_C(2313028370), UINT32_C( 869237081), UINT32_C(4104913762), UINT32_C(2825691966),
                              UINT32_C(3577866502), UINT32_C(2991894408), UINT32_C(2172048625), UINT32_C(1617119933),
                              UINT32_C(1521363431), UINT32_C( 553638116), UINT32_C(1036201367), UINT32_C(3107033445),
                              UINT32_C(3882811410), UINT32_C(3534384353), UINT32_C(3871215839), UINT32_C(1273589632)),
      UINT16_C(35103),
      simde_x_mm512_set_epu32(UINT32_C(2458371652), UINT32_C( 260676470), UINT32_C(1724614860), UINT32_C(4150452663),
                              UINT32_C(3816336716), UINT32_C(2208212235), UINT32_C( 932145867), UINT32_C(2432594561),
                              UINT32_C(1756892633), UINT32_C( 382632965), UINT32_C(1295078740), UINT32_C(3299165262),
                              UINT32_C( 152308919), UINT32_C(3943411788), UINT32_C(  31813624), UINT32_C( 807463845)),
      simde_x_mm512_set_epu32(UINT32_C( 615301803), UINT32_C( 382786341), UINT32_C(1852603705), UINT32_C(1998007730),
                              UINT32_C( 231325888), UINT32_C(1842039329), UINT32_C( 968682756), UINT32_C( 316335394),
                              UINT32_C(2223585202), UINT32_C(3491781959), UINT32_C(2167971796), UINT32_C(1587647099),
                              UINT32_C(2966608712), UINT32_C( 320339033), UINT32_C( 282380179), UINT32_C(4186865204)),
      simde_x_mm512_set_epu32(UINT32_C(         3), UINT32_C( 869237081), UINT32_C(4104913762), UINT32_C(2825691966),
                              UINT32_C(        16), UINT32_C(2991894408), UINT32_C(2172048625), UINT32_C(         7),
                              UINT32_C(1521363431), UINT32_C( 553638116), UINT32_C(1036201367), UINT32_C(         2),
                              UINT32_C(         0), UINT32_C(        12), UINT32_C(         0), UINT32_C(         0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_mask_div_epu32(test_vec[i].src, test_vec[i].k, test_vec[i].a, test_vec[i].b);
    simde_assert_m512i_u32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_div_epu64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512i a;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {
    { simde_x_mm512_set_epu64(UINT64_C( 2968342496979776051), UINT64_C(10005265515001776413),
                              UINT64_C(16837535683400356038), UINT64_C( 6738163160628300797),
                              UINT64_C(13810255550447513201), UINT64_C( 6479913377553186648),
                              UINT64_C( 7505871096235581515), UINT64_C( 2265477367564496986)),
      simde_x_mm512_set_epu64(UINT64_C(10866939104613927783), UINT64_C(11375825163207743431),
                              UINT64_C(11633520338587575573), UINT64_C(  216242550290965460),
                              UINT64_C( 5120732502404950997), UINT64_C( 5681284513410730040),
                              UINT64_C( 6409558907924801050), UINT64_C( 5372227444888762251)),
      simde_x_mm512_set_epu64(UINT64_C(                   0), UINT64_C(                   0),
                              UINT64_C(                   1), UINT64_C(                  31),
                              UINT64_C(                   2), UINT64_C(                   1),
                              UINT64_C(                   1), UINT64_C(                   0)) },
    { simde_x_mm512_set_epu64(UINT64_C( 5645659480511055559), UINT64_C(15272728730484288257),
                              UINT64_C(14133460247011230967), UINT64_C(16423537638667915170),
                              UINT64_C( 2118113466433927893), UINT64_C( 3840651400764901876),
                              UINT64_C( 2114726288902596757), UINT64_C( 9482369585348649466)),
      simde_x_mm512_set_epu64(UINT64_C(13555234896536583899), UINT64_C( 7851952110853286921),
                              UINT64_C(17616907291198234572), UINT64_C(16521184395064581900),
                              UINT64_C( 7345032902979795528), UINT64_C(12329133549512917827),
                              UINT64_C( 2328100732832272381), UINT64_C( 4111895855610225675)),
      simde_x_mm512_set_epu64(UINT64_C(                   0), UINT64_C(                   1),
                              UINT64_C(                   0), UINT64_C(                   0),
                              UINT64_C(                   0), UINT64_C(                   0),
                              UINT64_C(                   0), UINT64_C(                   2)) },
    { simde_x_mm512_set_epu64(UINT64_C( 7572458917823766705), UINT64_C(12217500042222052906),
                              UINT64_C( 1159256113650983207), UINT64_C( 6193154838246823767),
                              UINT64_C( 7449607714297299576), UINT64_C(14401023659121376347),
                              UINT64_C( 8569312554655704071), UINT64_C(10336200663482757951)),
      simde_x_mm512_set_epu64(UINT64_C(15588592630942564743), UINT64_C( 9028813919053392068),
                              UINT64_C( 5083059030774095197), UINT64_C(13888425720366328200),
                              UINT64_C(16888199589465789243), UINT64_C(18237918400292775569),
                              UINT64_C(12279468594349909724), UINT64_C(13493341674566517412)),
      simde_x_mm512_set_epu64(UINT64_C(                   0), UINT64_C(                   1),
                              UINT64_C(                   0), UINT64_C(                   0),
                              UINT64_C(                   0), UINT64_C(                   0),
                              UINT64_C(                   0), UINT64_C(                   0)) },
    { simde_x_mm512_set_epu64(UINT64_C( 2129749246616352421), UINT64_C( 3930946101587052880),
                              UINT64_C( 6109596926925725236), UINT64_C(11931707044738783755),
                              UINT64_C( 3908684742628183808), UINT64_C(15775432521885308750),
                              UINT64_C( 2246668589251707300), UINT64_C( 9474721517893975343)),
      simde_x_mm512_set_epu64(UINT64_C( 5181754748372749246), UINT64_C( 2283432752406648940),
                              UINT64_C(17825612137522679693), UINT64_C( 6205295972918594513),
                              UINT64_C( 7540605987113962845), UINT64_C(13935122940778806069),
                              UINT64_C( 9355601638871447350), UINT64_C(17674380633802211723)),
      simde_x_mm512_set_epu64(UINT64_C(                   0), UINT64_C(                   1),
                              UINT64_C(                   0), UINT64_C(                   1),
                              UINT64_C(                   0), UINT64_C(                   1),
                              UINT64_C(                   0), UINT64_C(                   0)) },
    { simde_x_mm512_set_epu64(UINT64_C(11414694502393074802), UINT64_C( 5732351344186366329),
                              UINT64_C( 3673896834139808492), UINT64_C( 3472617261273378891),
                              UINT64_C(  530630724433960967), UINT64_C(13609194605976671651),
                              UINT64_C(17862411075628668824), UINT64_C( 6007180105039451483)),
      simde_x_mm512_set_epu64(UINT64_C( 2597258637662508799), UINT64_C(10698877731456040415),
                              UINT64_C( 1281935105229028959), UINT64_C(13158200861647791958),
                              UINT64_C(17820547312174620134), UINT64_C(10241294226337238422),
                              UINT64_C(16849636328689785423), UINT64_C( 8515452077469772855)),
      simde_x_mm512_set_epu64(UINT64_C(                   4), UINT64_C(                   0),
                              UINT64_C(                   2), UINT64_C(                   0),
                              UINT64_C(                   0), UINT64_C(                   1),
                              UINT64_C(                   1), UINT64_C(                   0)) },
    { simde_x_mm512_set_epu64(UINT64_C( 6286795626078602527), UINT64_C(16449737592791923437),
                              UINT64_C( 3423539900625568727), UINT64_C(14354768056262433624),
                              UINT64_C(13276435385586003544), UINT64_C(13226616968333580034),
                              UINT64_C(13803418519385186873), UINT64_C(17664506654225712980)),
      simde_x_mm512_set_epu64(UINT64_C( 8577263429665049091), UINT64_C( 1989107677696558897),
                              UINT64_C(10076739928573503462), UINT64_C(11128938736014461142),
                              UINT64_C(16921205335142546091), UINT64_C( 8618363237326703628),
                              UINT64_C( 6584836091306452136), UINT64_C( 7260043819054420427)),
      simde_x_mm512_set_epu64(UINT64_C(                   0), UINT64_C(                   8),
                              UINT64_C(                   0), UINT64_C(                   1),
                              UINT64_C(                   0), UINT64_C(                   1),
                              UINT64_C(                   2), UINT64_C(                   2)) },
    { simde_x_mm512_set_epu64(UINT64_C( 3903334154292354714), UINT64_C( 8869267046373815529),
                              UINT64_C( 6916283752571091217), UINT64_C( 8726009290759968207),
                              UINT64_C(10071350786374349244), UINT64_C( 8496158362035250512),
                              UINT64_C(17368098678232675634), UINT64_C( 1777515526450307184)),
      simde_x_mm512_set_epu64(UINT64_C( 5278336582045705857), UINT64_C(12066730073134673033),
                              UINT64_C( 7590368039103504017), UINT64_C( 5001217194949514725),
                              UINT64_C(15479073382423099957), UINT64_C( 9832610448471819123),
                              UINT64_C( 6754177049630551103), UINT64_C(10305112663885051469)),
      simde_x_mm512_set_epu64(UINT64_C(                   0), UINT64_C(                   0),
                              UINT64_C(                   0), UINT64_C(                   1),
                              UINT64_C(                   0), UINT64_C(                   0),
                              UINT64_C(                   2), UINT64_C(                   0)) },
    { simde_x_mm512_set_epu64(UINT64_C( 5348983348701791658), UINT64_C(10148639760639402834),
                              UINT64_C(10174807539574872867), UINT64_C(13279516658136916303),
                              UINT64_C( 7338742772279280569), UINT64_C( 9396295244612029630),
                              UINT64_C(16685506566149927992), UINT64_C(10552022463454113501)),
      simde_x_mm512_set_epu64(UINT64_C(16811669128702212682), UINT64_C(18047205824811442812),
                              UINT64_C(18028153300578966352), UINT64_C(16837207357260532002),
                              UINT64_C( 1694596378460381816), UINT64_C( 7292544047935022069),
                              UINT64_C(  616022812148352233), UINT64_C( 2502282222097948969)),
      simde_x_mm512_set_epu64(UINT64_C(                   0), UINT64_C(                   0),
                              UINT64_C(                   0), UINT64_C(                   0),
                              UINT64_C(                   4), UINT64_C(                   1),
                              UINT64_C(                  27), UINT64_C(                   4)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_div_epu64(test_vec[i].a, test_vec[i].b);
    simde_assert_m512i_u64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_idivrem_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i rem;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C( 1747596798), INT32_C(-2063703989), INT32_C(  527472553), INT32_C(-1403096998)),
      simde_mm_set_epi32(INT32_C( -269879152), INT32_C( -177038436), INT32_C(  377180600), INT32_C( -518586410)),
      simde_mm_set_epi32(INT32_C(  128321886), INT32_C( -116281193), INT32_C(  150291953), INT32_C( -365924178)),
      simde_mm_set_epi32(INT32_C(         -6), INT32_C(         11), INT32_C(          1), INT32_C(          2)) },
    { simde_mm_set_epi32(INT32_C( -374673026), INT32_C(-1240805178), INT32_C( 1568850865), INT32_C(-1142977539)),
      simde_mm_set_epi32(INT32_C(  172780273), INT32_C(  168508556), INT32_C( -491358722), INT32_C( -230071737)),
      simde_mm_set_epi32(INT32_C(  -29112480), INT32_C(  -61245286), INT32_C(   94774699), INT32_C( -222690591)),
      simde_mm_set_epi32(INT32_C(         -2), INT32_C(         -7), INT32_C(         -3), INT32_C(          4)) },
    { simde_mm_set_epi32(INT32_C( 1492341726), INT32_C(  298608154), INT32_C( 1250819173), INT32_C( -650971253)),
      simde_mm_set_epi32(INT32_C(  298065861), INT32_C( -521585931), INT32_C(  330694282), INT32_C(   40997390)),
      simde_mm_set_epi32(INT32_C(    2012421), INT32_C(  298608154), INT32_C(  258736327), INT32_C(  -36010403)),
      simde_mm_set_epi32(INT32_C(          5), INT32_C(          0), INT32_C(          3), INT32_C(        -15)) },
    { simde_mm_set_epi32(INT32_C(-1586327268), INT32_C( 1691051285), INT32_C(   50347892), INT32_C(  728425428)),
      simde_mm_set_epi32(INT32_C( -441202718), INT32_C(  294920921), INT32_C( -411581651), INT32_C( -167991823)),
      simde_mm_set_epi32(INT32_C( -262719114), INT32_C(  216446680), INT32_C(   50347892), INT32_C(   56458136)),
      simde_mm_set_epi32(INT32_C(          3), INT32_C(          5), INT32_C(          0), INT32_C(         -4)) },
    { simde_mm_set_epi32(INT32_C(  492373082), INT32_C(  -13096811), INT32_C(-2087181083), INT32_C( -341007878)),
      simde_mm_set_epi32(INT32_C(  123290430), INT32_C( -298778955), INT32_C(  223555334), INT32_C( -332615043)),
      simde_mm_set_epi32(INT32_C(  122501792), INT32_C(  -13096811), INT32_C(  -75183077), INT32_C(   -8392835)),
      simde_mm_set_epi32(INT32_C(          3), INT32_C(          0), INT32_C(         -9), INT32_C(          1)) },
    { simde_mm_set_epi32(INT32_C(-1004264650), INT32_C( 1580565751), INT32_C( -471064457), INT32_C( 2081361826)),
      simde_mm_set_epi32(INT32_C(  328620632), INT32_C( -324312655), INT32_C( -184752009), INT32_C( -354760000)),
      simde_mm_set_epi32(INT32_C(  -18402754), INT32_C(  283315131), INT32_C( -101560439), INT32_C(  307561826)),
      simde_mm_set_epi32(INT32_C(         -3), INT32_C(         -4), INT32_C(          2), INT32_C(         -5)) },
    { simde_mm_set_epi32(INT32_C(  542053192), INT32_C(  499863549), INT32_C(  957375358), INT32_C(-1291033589)),
      simde_mm_set_epi32(INT32_C(  427537184), INT32_C(  493530770), INT32_C( -356091799), INT32_C(   29647056)),
      simde_mm_set_epi32(INT32_C(  114516008), INT32_C(    6332779), INT32_C(  245191760), INT32_C(  -16210181)),
      simde_mm_set_epi32(INT32_C(          1), INT32_C(          1), INT32_C(         -2), INT32_C(        -43)) },
    { simde_mm_set_epi32(INT32_C( -193211433), INT32_C( -857989172), INT32_C( -448329300), INT32_C(-1601364212)),
      simde_mm_set_epi32(INT32_C( -284723308), INT32_C( -171790410), INT32_C(  457043765), INT32_C(  -97355006)),
      simde_mm_set_epi32(INT32_C( -193211433), INT32_C( -170827532), INT32_C( -448329300), INT32_C(  -43684116)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(          4), INT32_C(          0), INT32_C(         16)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i rem;
    simde__m128i r = simde_mm_idivrem_epi32(&rem, test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
    simde_assert_m128i_i32(rem, ==, test_vec[i].rem);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_idivrem_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i rem;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi32(INT32_C(-1079516608), INT32_C( -708153743), INT32_C( 1508722402), INT32_C(-2074345640),
                            INT32_C( 1747596798), INT32_C(-2063703989), INT32_C(  527472553), INT32_C(-1403096998)),
      simde_mm256_set_epi32(INT32_C(  172780273), INT32_C(  168508556), INT32_C( -491358722), INT32_C( -230071737),
                            INT32_C(  -93668257), INT32_C( -310201295), INT32_C(  392212716), INT32_C( -285744385)),
      simde_mm256_set_epi32(INT32_C(  -42834970), INT32_C(  -34119519), INT32_C(   34646236), INT32_C(   -3700007),
                            INT32_C(   61568172), INT32_C( -202496219), INT32_C(  135259837), INT32_C( -260119458)),
      simde_mm256_set_epi32(INT32_C(         -6), INT32_C(         -4), INT32_C(         -3), INT32_C(          9),
                            INT32_C(        -18), INT32_C(          6), INT32_C(          1), INT32_C(          4)) },
    { simde_mm256_set_epi32(INT32_C( 1192263444), INT32_C(-2086343723), INT32_C( 1322777130), INT32_C(  163989560),
                            INT32_C( 1492341726), INT32_C(  298608154), INT32_C( 1250819173), INT32_C( -650971253)),
      simde_mm256_set_epi32(INT32_C( -441202718), INT32_C(  294920921), INT32_C( -411581651), INT32_C( -167991823),
                            INT32_C( -396581817), INT32_C(  422762821), INT32_C(   12586973), INT32_C(  182106357)),
      simde_mm256_set_epi32(INT32_C(  309858008), INT32_C(  -21897276), INT32_C(   88032177), INT32_C(  163989560),
                            INT32_C(  302596275), INT32_C(  298608154), INT32_C(    4708846), INT32_C( -104652182)),
      simde_mm256_set_epi32(INT32_C(         -2), INT32_C(         -7), INT32_C(         -3), INT32_C(          0),
                            INT32_C(         -3), INT32_C(          0), INT32_C(         99), INT32_C(         -3)) },
    { simde_mm256_set_epi32(INT32_C(  493161721), INT32_C(-1195115819), INT32_C(  894221337), INT32_C(-1330460172),
                            INT32_C(  492373082), INT32_C(  -13096811), INT32_C(-2087181083), INT32_C( -341007878)),
      simde_mm256_set_epi32(INT32_C(  328620632), INT32_C( -324312655), INT32_C( -184752009), INT32_C( -354760000),
                            INT32_C( -251066163), INT32_C(  395141437), INT32_C( -117766115), INT32_C(  520340456)),
      simde_mm256_set_epi32(INT32_C(  164541089), INT32_C( -222177854), INT32_C(  155213301), INT32_C( -266180172),
                            INT32_C(  241306919), INT32_C(  -13096811), INT32_C(  -85157128), INT32_C( -341007878)),
      simde_mm256_set_epi32(INT32_C(          1), INT32_C(          3), INT32_C(         -4), INT32_C(          3),
                            INT32_C(         -1), INT32_C(          0), INT32_C(         17), INT32_C(          0)) },
    { simde_mm256_set_epi32(INT32_C( 1710148738), INT32_C( 1974123080), INT32_C(-1424367196), INT32_C(  118588227),
                            INT32_C(  542053192), INT32_C(  499863549), INT32_C(  957375358), INT32_C(-1291033589)),
      simde_mm256_set_epi32(INT32_C( -284723308), INT32_C( -171790410), INT32_C(  457043765), INT32_C(  -97355006),
                            INT32_C(  -48302859), INT32_C( -214497293), INT32_C( -112082325), INT32_C( -400341053)),
      simde_mm256_set_epi32(INT32_C(    1808890), INT32_C(   84428570), INT32_C(  -53235901), INT32_C(   21233221),
                            INT32_C(   10721743), INT32_C(   70868963), INT32_C(   60716758), INT32_C(  -90010430)),
      simde_mm256_set_epi32(INT32_C(         -6), INT32_C(        -11), INT32_C(         -3), INT32_C(         -1),
                            INT32_C(        -11), INT32_C(         -2), INT32_C(         -8), INT32_C(          3)) },
    { simde_mm256_set_epi32(INT32_C( 1734496959), INT32_C(  380846712), INT32_C( -941967689), INT32_C( -739443621),
                            INT32_C( 1995198557), INT32_C( -980655097), INT32_C(-1888383043), INT32_C( 1779168063)),
      simde_mm256_set_epi32(INT32_C(  440775120), INT32_C( -129501140), INT32_C( -362589725), INT32_C( -352466550),
                            INT32_C(   67477586), INT32_C(  108492873), INT32_C(  360489056), INT32_C(  254567893)),
      simde_mm256_set_epi32(INT32_C(  412171599), INT32_C(  121844432), INT32_C( -216788239), INT32_C(  -34510521),
                            INT32_C(   38348563), INT32_C(   -4219240), INT32_C(  -85937763), INT32_C(  251760705)),
      simde_mm256_set_epi32(INT32_C(          3), INT32_C(         -2), INT32_C(          2), INT32_C(          2),
                            INT32_C(         29), INT32_C(         -9), INT32_C(         -5), INT32_C(          6)) },
    { simde_mm256_set_epi32(INT32_C( -362876916), INT32_C(-1845390533), INT32_C(  -48621016), INT32_C(  201516689),
                            INT32_C(-1435930720), INT32_C(-1932876068), INT32_C(-1153303869), INT32_C(  562234020)),
      simde_mm256_set_epi32(INT32_C( -166366311), INT32_C(  -85548959), INT32_C(  525546139), INT32_C(  219277873),
                            INT32_C(  295872976), INT32_C( -144152745), INT32_C( -265329050), INT32_C( -202024350)),
      simde_mm256_set_epi32(INT32_C(  -30144294), INT32_C(  -48862394), INT32_C(  -48621016), INT32_C(  201516689),
                            INT32_C( -252438816), INT32_C(  -58890383), INT32_C(  -91987669), INT32_C(  158185320)),
      simde_mm256_set_epi32(INT32_C(          2), INT32_C(         21), INT32_C(          0), INT32_C(          0),
                            INT32_C(         -4), INT32_C(         13), INT32_C(          4), INT32_C(         -2)) },
    { simde_mm256_set_epi32(INT32_C(  910061584), INT32_C( 2002226944), INT32_C( -621963189), INT32_C(  -48343218),
                            INT32_C(  523093293), INT32_C(-1235205724), INT32_C(-2088961787), INT32_C( 1943141679)),
      simde_mm256_set_epi32(INT32_C(  123967721), INT32_C(  -95531607), INT32_C(  228811177), INT32_C(    1270356),
                            INT32_C(  355625346), INT32_C(  -40994931), INT32_C( -379225067), INT32_C(  124491394)),
      simde_mm256_set_epi32(INT32_C(   42287537), INT32_C(   91594804), INT32_C( -164340835), INT32_C(     -69690),
                            INT32_C(  167467947), INT32_C(   -5357794), INT32_C( -192836452), INT32_C(   75770769)),
      simde_mm256_set_epi32(INT32_C(          7), INT32_C(        -20), INT32_C(         -2), INT32_C(        -38),
                            INT32_C(          1), INT32_C(         30), INT32_C(          5), INT32_C(         15)) },
    { simde_mm256_set_epi32(INT32_C( 1755684145), INT32_C(-2061726371), INT32_C(-1050443653), INT32_C(-1299940555),
                            INT32_C(-2116696545), INT32_C( 1493088054), INT32_C( -179829877), INT32_C(  651362699)),
      simde_mm256_set_epi32(INT32_C(  301617823), INT32_C(  343728879), INT32_C(  132913279), INT32_C(  518796827),
                            INT32_C(  -36154638), INT32_C( -532966429), INT32_C(  361195763), INT32_C(  469656308)),
      simde_mm256_set_epi32(INT32_C(  247595030), INT32_C( -343081976), INT32_C( -120050700), INT32_C( -262346901),
                            INT32_C(  -19727541), INT32_C(  427155196), INT32_C( -179829877), INT32_C(  181706391)),
      simde_mm256_set_epi32(INT32_C(          5), INT32_C(         -5), INT32_C(         -7), INT32_C(         -2),
                            INT32_C(         58), INT32_C(         -2), INT32_C(          0), INT32_C(          1)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i rem;
    simde__m256i r = simde_mm256_idivrem_epi32(&rem, test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
    simde_assert_m256i_i32(rem, ==, test_vec[i].rem);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_rem_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi8(INT8_C( 104), INT8_C(  42), INT8_C(  53), INT8_C(  -2),
                        INT8_C(-124), INT8_C(  -2), INT8_C(  96), INT8_C(  75),
                        INT8_C(  31), INT8_C( 112), INT8_C(-105), INT8_C( -87),
                        INT8_C( -84), INT8_C(  94), INT8_C( 112), INT8_C(  90)),
      simde_mm_set_epi8(INT8_C( -65), INT8_C( -89), INT8_C( -30), INT8_C(  64),
                        INT8_C( -43), INT8_C( -54), INT8_C( 110), INT8_C( 113),
                        INT8_C(  89), INT8_C( -19), INT8_C(  70), INT8_C( -30),
                        INT8_C(-124), INT8_C(  91), INT8_C(  -1), INT8_C(  88)),
      simde_mm_set_epi8(INT8_C(  39), INT8_C(  42), INT8_C(  23), INT8_C(  -2),
                        INT8_C( -38), INT8_C(  -2), INT8_C(  96), INT8_C(  75),
                        INT8_C(  31), INT8_C(  17), INT8_C( -35), INT8_C( -27),
                        INT8_C( -84), INT8_C(   3), INT8_C(   0), INT8_C(   2)) },
    { simde_mm_set_epi8(INT8_C( -23), INT8_C( -86), INT8_C( -15), INT8_C( 126),
                        INT8_C( -74), INT8_C(  10), INT8_C( -48), INT8_C( -58),
                        INT8_C(  93), INT8_C(-126), INT8_C( -61), INT8_C( -79),
                        INT8_C( -69), INT8_C( -33), INT8_C(-117), INT8_C(  -3)),
      simde_mm_set_epi8(INT8_C(  41), INT8_C(  49), INT8_C( -85), INT8_C( -58),
                        INT8_C(  40), INT8_C(  44), INT8_C( -14), INT8_C(  51),
                        INT8_C(-118), INT8_C( -39), INT8_C( -41), INT8_C(  -7),
                        INT8_C( -55), INT8_C(  37), INT8_C(-119), INT8_C(  29)),
      simde_mm_set_epi8(INT8_C( -23), INT8_C( -37), INT8_C( -15), INT8_C(  10),
                        INT8_C( -34), INT8_C(  10), INT8_C(  -6), INT8_C(  -7),
                        INT8_C(  93), INT8_C(  -9), INT8_C( -20), INT8_C(  -2),
                        INT8_C( -14), INT8_C( -33), INT8_C(-117), INT8_C(  -3)) },
    { simde_mm_set_epi8(INT8_C(  88), INT8_C( -13), INT8_C(  83), INT8_C( -34),
                        INT8_C(  17), INT8_C( -52), INT8_C( 102), INT8_C(  26),
                        INT8_C(  74), INT8_C(-115), INT8_C(  -4), INT8_C( 101),
                        INT8_C( -39), INT8_C(  50), INT8_C(  -9), INT8_C(-117)),
      simde_mm_set_epi8(INT8_C(  71), INT8_C(  16), INT8_C( 127), INT8_C(  20),
                        INT8_C(-125), INT8_C( -92), INT8_C( -21), INT8_C( -43),
                        INT8_C(  78), INT8_C( -41), INT8_C(  -6), INT8_C(  42),
                        INT8_C(   9), INT8_C( -58), INT8_C(  72), INT8_C(  56)),
      simde_mm_set_epi8(INT8_C(  17), INT8_C( -13), INT8_C(  83), INT8_C( -14),
                        INT8_C(  17), INT8_C( -52), INT8_C(  18), INT8_C(  26),
                        INT8_C(  74), INT8_C( -33), INT8_C(  -4), INT8_C(  17),
                        INT8_C(  -3), INT8_C(  50), INT8_C(  -9), INT8_C(  -5)) },
    { simde_mm_set_epi8(INT8_C( -95), INT8_C( 114), INT8_C(-111), INT8_C(  28),
                        INT8_C( 100), INT8_C( -53), INT8_C( 101), INT8_C(  21),
                        INT8_C(   3), INT8_C(   0), INT8_C(  63), INT8_C( 116),
                        INT8_C(  43), INT8_C( 106), INT8_C( -29), INT8_C( -44)),
      simde_mm_set_epi8(INT8_C(-106), INT8_C( -49), INT8_C(  31), INT8_C(-118),
                        INT8_C(  70), INT8_C(  80), INT8_C(-117), INT8_C( 103),
                        INT8_C( -99), INT8_C( -33), INT8_C(  12), INT8_C( -74),
                        INT8_C( -41), INT8_C( -14), INT8_C(-105), INT8_C( -57)),
      simde_mm_set_epi8(INT8_C( -95), INT8_C(  16), INT8_C( -18), INT8_C(  28),
                        INT8_C(  30), INT8_C( -53), INT8_C( 101), INT8_C(  21),
                        INT8_C(   3), INT8_C(   0), INT8_C(   3), INT8_C(  42),
                        INT8_C(   2), INT8_C(   8), INT8_C( -29), INT8_C( -44)) },
    { simde_mm_set_epi8(INT8_C(  29), INT8_C(  89), INT8_C(   4), INT8_C(  90),
                        INT8_C(  -1), INT8_C(  56), INT8_C(  40), INT8_C(-107),
                        INT8_C(-125), INT8_C(-104), INT8_C(  36), INT8_C( -27),
                        INT8_C( -21), INT8_C( -84), INT8_C( -95), INT8_C(  -6)),
      simde_mm_set_epi8(INT8_C(  29), INT8_C( 101), INT8_C(  12), INT8_C(  -7),
                        INT8_C( -72), INT8_C( -61), INT8_C(  -6), INT8_C( -43),
                        INT8_C(  53), INT8_C(  76), INT8_C( -68), INT8_C(  25),
                        INT8_C( -80), INT8_C( -78), INT8_C( -55), INT8_C( -12)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(  89), INT8_C(   4), INT8_C(   6),
                        INT8_C(  -1), INT8_C(  56), INT8_C(   4), INT8_C( -21),
                        INT8_C( -19), INT8_C( -28), INT8_C(  36), INT8_C(  -2),
                        INT8_C( -21), INT8_C(  -6), INT8_C( -40), INT8_C(  -6)) },
    { simde_mm_set_epi8(INT8_C( -60), INT8_C(  36), INT8_C(  35), INT8_C(  54),
                        INT8_C(  94), INT8_C(  53), INT8_C(-124), INT8_C(  -9),
                        INT8_C( -29), INT8_C( -20), INT8_C(  32), INT8_C( 119),
                        INT8_C( 124), INT8_C(  15), INT8_C(  15), INT8_C( -94)),
      simde_mm_set_epi8(INT8_C(  78), INT8_C(  89), INT8_C( 105), INT8_C(  98),
                        INT8_C( -78), INT8_C( -83), INT8_C(-122), INT8_C( -57),
                        INT8_C( -45), INT8_C( -13), INT8_C( -95), INT8_C( -36),
                        INT8_C( -85), INT8_C( 107), INT8_C(  43), INT8_C(   1)),
      simde_mm_set_epi8(INT8_C( -60), INT8_C(  36), INT8_C(  35), INT8_C(  54),
                        INT8_C(  16), INT8_C(  53), INT8_C(  -2), INT8_C(  -9),
                        INT8_C( -29), INT8_C(  -7), INT8_C(  32), INT8_C(  11),
                        INT8_C(  39), INT8_C(  15), INT8_C(  15), INT8_C(   0)) },
    { simde_mm_set_epi8(INT8_C(  32), INT8_C(  79), INT8_C(  19), INT8_C(  72),
                        INT8_C(  29), INT8_C( -53), INT8_C(  79), INT8_C(  -3),
                        INT8_C(  57), INT8_C(  16), INT8_C(  99), INT8_C( 126),
                        INT8_C( -77), INT8_C(  12), INT8_C( 100), INT8_C(  11)),
      simde_mm_set_epi8(INT8_C( 101), INT8_C( -18), INT8_C( -52), INT8_C(-126),
                        INT8_C( 117), INT8_C( -86), INT8_C( -70), INT8_C(  72),
                        INT8_C( -85), INT8_C(  25), INT8_C( -31), INT8_C( -92),
                        INT8_C(   7), INT8_C(  17), INT8_C(-125), INT8_C(  67)),
      simde_mm_set_epi8(INT8_C(  32), INT8_C(   7), INT8_C(  19), INT8_C(  72),
                        INT8_C(  29), INT8_C( -53), INT8_C(   9), INT8_C(  -3),
                        INT8_C(  57), INT8_C(  16), INT8_C(   6), INT8_C(  34),
                        INT8_C(   0), INT8_C(  12), INT8_C( 100), INT8_C(  11)) },
    { simde_mm_set_epi8(INT8_C( -12), INT8_C( 123), INT8_C( -45), INT8_C( -41),
                        INT8_C( -52), INT8_C( -36), INT8_C(  31), INT8_C( -52),
                        INT8_C( -27), INT8_C(  71), INT8_C(   9), INT8_C( -84),
                        INT8_C( -96), INT8_C(-115), INT8_C(  31), INT8_C(  12)),
      simde_mm_set_epi8(INT8_C( -68), INT8_C(  29), INT8_C( -34), INT8_C(  81),
                        INT8_C( -41), INT8_C(  10), INT8_C( -66), INT8_C( -37),
                        INT8_C( 108), INT8_C(  -9), INT8_C( -68), INT8_C( -41),
                        INT8_C( -24), INT8_C( -55), INT8_C( -20), INT8_C(   9)),
      simde_mm_set_epi8(INT8_C( -12), INT8_C(   7), INT8_C( -11), INT8_C( -41),
                        INT8_C( -11), INT8_C(  -6), INT8_C(  31), INT8_C( -15),
                        INT8_C( -27), INT8_C(   8), INT8_C(   9), INT8_C(  -2),
                        INT8_C(   0), INT8_C(  -5), INT8_C(  11), INT8_C(   3)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_rem_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_rem_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(INT16_C( 26666), INT16_C( 13822), INT16_C(-31490), INT16_C( 24651),
                         INT16_C(  8048), INT16_C(-26711), INT16_C(-21410), INT16_C( 28762)),
      simde_mm_set_epi16(INT16_C(-16473), INT16_C( -7616), INT16_C(-10806), INT16_C( 28273),
                         INT16_C( 23021), INT16_C( 18146), INT16_C(-31653), INT16_C(  -168)),
      simde_mm_set_epi16(INT16_C( 10193), INT16_C(  6206), INT16_C( -9878), INT16_C( 24651),
                         INT16_C(  8048), INT16_C( -8565), INT16_C(-21410), INT16_C(    34)) },
    { simde_mm_set_epi16(INT16_C( -5718), INT16_C( -3714), INT16_C(-18934), INT16_C(-12090),
                         INT16_C( 23938), INT16_C(-15439), INT16_C(-17441), INT16_C(-29699)),
      simde_mm_set_epi16(INT16_C( 10545), INT16_C(-21562), INT16_C( 10284), INT16_C( -3533),
                         INT16_C(-29991), INT16_C(-10247), INT16_C(-14043), INT16_C(-30435)),
      simde_mm_set_epi16(INT16_C( -5718), INT16_C( -3714), INT16_C( -8650), INT16_C( -1491),
                         INT16_C( 23938), INT16_C( -5192), INT16_C( -3398), INT16_C(-29699)) },
    { simde_mm_set_epi16(INT16_C( 22771), INT16_C( 21470), INT16_C(  4556), INT16_C( 26138),
                         INT16_C( 19085), INT16_C(  -923), INT16_C( -9934), INT16_C( -2165)),
      simde_mm_set_epi16(INT16_C( 18192), INT16_C( 32532), INT16_C(-31836), INT16_C( -5163),
                         INT16_C( 20183), INT16_C( -1494), INT16_C(  2502), INT16_C( 18488)),
      simde_mm_set_epi16(INT16_C(  4579), INT16_C( 21470), INT16_C(  4556), INT16_C(   323),
                         INT16_C( 19085), INT16_C(  -923), INT16_C( -2428), INT16_C( -2165)) },
    { simde_mm_set_epi16(INT16_C(-24206), INT16_C(-28388), INT16_C( 25803), INT16_C( 25877),
                         INT16_C(   768), INT16_C( 16244), INT16_C( 11114), INT16_C( -7212)),
      simde_mm_set_epi16(INT16_C(-26929), INT16_C(  8074), INT16_C( 18000), INT16_C(-29849),
                         INT16_C(-25121), INT16_C(  3254), INT16_C(-10254), INT16_C(-26681)),
      simde_mm_set_epi16(INT16_C(-24206), INT16_C( -4166), INT16_C(  7803), INT16_C( 25877),
                         INT16_C(   768), INT16_C(  3228), INT16_C(   860), INT16_C( -7212)) },
    { simde_mm_set_epi16(INT16_C(  7513), INT16_C(  1114), INT16_C(  -200), INT16_C( 10389),
                         INT16_C(-31848), INT16_C(  9445), INT16_C( -5204), INT16_C(-24070)),
      simde_mm_set_epi16(INT16_C(  7525), INT16_C(  3321), INT16_C(-18237), INT16_C( -1323),
                         INT16_C( 13644), INT16_C(-17383), INT16_C(-20302), INT16_C(-13836)),
      simde_mm_set_epi16(INT16_C(  7513), INT16_C(  1114), INT16_C(  -200), INT16_C(  1128),
                         INT16_C( -4560), INT16_C(  9445), INT16_C( -5204), INT16_C(-10234)) },
    { simde_mm_set_epi16(INT16_C(-15324), INT16_C(  9014), INT16_C( 24117), INT16_C(-31497),
                         INT16_C( -7188), INT16_C(  8311), INT16_C( 31759), INT16_C(  4002)),
      simde_mm_set_epi16(INT16_C( 20057), INT16_C( 26978), INT16_C(-19795), INT16_C(-31033),
                         INT16_C(-11277), INT16_C(-24100), INT16_C(-21653), INT16_C( 11009)),
      simde_mm_set_epi16(INT16_C(-15324), INT16_C(  9014), INT16_C(  4322), INT16_C(  -464),
                         INT16_C( -7188), INT16_C(  8311), INT16_C( 10106), INT16_C(  4002)) },
    { simde_mm_set_epi16(INT16_C(  8271), INT16_C(  4936), INT16_C(  7627), INT16_C( 20477),
                         INT16_C( 14608), INT16_C( 25470), INT16_C(-19700), INT16_C( 25611)),
      simde_mm_set_epi16(INT16_C( 26094), INT16_C(-13182), INT16_C( 30122), INT16_C(-17848),
                         INT16_C(-21735), INT16_C( -7772), INT16_C(  1809), INT16_C(-31933)),
      simde_mm_set_epi16(INT16_C(  8271), INT16_C(  4936), INT16_C(  7627), INT16_C(  2629),
                         INT16_C( 14608), INT16_C(  2154), INT16_C( -1610), INT16_C( 25611)) },
    { simde_mm_set_epi16(INT16_C( -2949), INT16_C(-11305), INT16_C(-13092), INT16_C(  8140),
                         INT16_C( -6841), INT16_C(  2476), INT16_C(-24435), INT16_C(  7948)),
      simde_mm_set_epi16(INT16_C(-17379), INT16_C( -8623), INT16_C(-10486), INT16_C(-16677),
                         INT16_C( 27895), INT16_C(-17193), INT16_C( -5943), INT16_C( -5111)),
      simde_mm_set_epi16(INT16_C( -2949), INT16_C( -2682), INT16_C( -2606), INT16_C(  8140),
                         INT16_C( -6841), INT16_C(  2476), INT16_C(  -663), INT16_C(  2837)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_rem_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_rem_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C( 1747596798), INT32_C(-2063703989), INT32_C(  527472553), INT32_C(-1403096998)),
      simde_mm_set_epi32(INT32_C(-1079516608), INT32_C( -708153743), INT32_C( 1508722402), INT32_C(-2074345640)),
      simde_mm_set_epi32(INT32_C(  668080190), INT32_C( -647396503), INT32_C(  527472553), INT32_C(-1403096998)) },
    { simde_mm_set_epi32(INT32_C( -374673026), INT32_C(-1240805178), INT32_C( 1568850865), INT32_C(-1142977539)),
      simde_mm_set_epi32(INT32_C(  691121094), INT32_C(  674034227), INT32_C(-1965434887), INT32_C( -920286947)),
      simde_mm_set_epi32(INT32_C( -374673026), INT32_C( -566770951), INT32_C( 1568850865), INT32_C( -222690592)) },
    { simde_mm_set_epi32(INT32_C( 1492341726), INT32_C(  298608154), INT32_C( 1250819173), INT32_C( -650971253)),
      simde_mm_set_epi32(INT32_C( 1192263444), INT32_C(-2086343723), INT32_C( 1322777130), INT32_C(  163989560)),
      simde_mm_set_epi32(INT32_C(  300078282), INT32_C(  298608154), INT32_C( 1250819173), INT32_C( -159002573)) },
    { simde_mm_set_epi32(INT32_C(-1586327268), INT32_C( 1691051285), INT32_C(   50347892), INT32_C(  728425428)),
      simde_mm_set_epi32(INT32_C(-1764810870), INT32_C( 1179683687), INT32_C(-1646326602), INT32_C( -671967289)),
      simde_mm_set_epi32(INT32_C(-1586327268), INT32_C(  511367598), INT32_C(   50347892), INT32_C(   56458139)) },
    { simde_mm_set_epi32(INT32_C(  492373082), INT32_C(  -13096811), INT32_C(-2087181083), INT32_C( -341007878)),
      simde_mm_set_epi32(INT32_C(  493161721), INT32_C(-1195115819), INT32_C(  894221337), INT32_C(-1330460172)),
      simde_mm_set_epi32(INT32_C(  492373082), INT32_C(  -13096811), INT32_C( -298738409), INT32_C( -341007878)) },
    { simde_mm_set_epi32(INT32_C(-1004264650), INT32_C( 1580565751), INT32_C( -471064457), INT32_C( 2081361826)),
      simde_mm_set_epi32(INT32_C( 1314482530), INT32_C(-1297250617), INT32_C( -739008036), INT32_C(-1419039999)),
      simde_mm_set_epi32(INT32_C(-1004264650), INT32_C(  283315134), INT32_C( -471064457), INT32_C(  662321827)) },
    { simde_mm_set_epi32(INT32_C(  542053192), INT32_C(  499863549), INT32_C(  957375358), INT32_C(-1291033589)),
      simde_mm_set_epi32(INT32_C( 1710148738), INT32_C( 1974123080), INT32_C(-1424367196), INT32_C(  118588227)),
      simde_mm_set_epi32(INT32_C(  542053192), INT32_C(  499863549), INT32_C(  957375358), INT32_C( -105151319)) },
    { simde_mm_set_epi32(INT32_C( -193211433), INT32_C( -857989172), INT32_C( -448329300), INT32_C(-1601364212)),
      simde_mm_set_epi32(INT32_C(-1138893231), INT32_C( -687161637), INT32_C( 1828175063), INT32_C( -389420023)),
      simde_mm_set_epi32(INT32_C( -193211433), INT32_C( -170827535), INT32_C( -448329300), INT32_C(  -43684120)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_rem_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_rem_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi64x(INT64_C( 7505871096235581515), INT64_C( 2265477367564496986)),
      simde_mm_set_epi64x(INT64_C(-4636488523262038415), INT64_C( 6479913377553186648)),
      simde_mm_set_epi64x(INT64_C( 2869382572973543100), INT64_C( 2265477367564496986)) },
    { simde_mm_set_epi64x(INT64_C(-1609208390309195578), INT64_C( 6738163160628300797)),
      simde_mm_set_epi64x(INT64_C( 2968342496979776051), INT64_C(-8441478558707775203)),
      simde_mm_set_epi64x(INT64_C(-1609208390309195578), INT64_C( 6738163160628300797)) },
    { simde_mm_set_epi64x(INT64_C( 6409558907924801050), INT64_C( 5372227444888762251)),
      simde_mm_set_epi64x(INT64_C( 5120732502404950997), INT64_C( 5681284513410730040)),
      simde_mm_set_epi64x(INT64_C( 1288826405519850053), INT64_C( 5372227444888762251)) },
    { simde_mm_set_epi64x(INT64_C(-6813223735121976043), INT64_C(  216242550290965460)),
      simde_mm_set_epi64x(INT64_C(-7579804969095623833), INT64_C(-7070918910501808185)),
      simde_mm_set_epi64x(INT64_C(-6813223735121976043), INT64_C(  216242550290965460)) },
    { simde_mm_set_epi64x(INT64_C( 2114726288902596757), INT64_C(-8964374488360902150)),
      simde_mm_set_epi64x(INT64_C( 2118113466433927893), INT64_C( 3840651400764901876)),
      simde_mm_set_epi64x(INT64_C( 2114726288902596757), INT64_C(-1283071686831098398)) },
    { simde_mm_set_epi64x(INT64_C(-4313283826698320649), INT64_C(-2023206435041636446)),
      simde_mm_set_epi64x(INT64_C( 5645659480511055559), INT64_C(-3174015343225263359)),
      simde_mm_set_epi64x(INT64_C(-4313283826698320649), INT64_C(-2023206435041636446)) },
    { simde_mm_set_epi64x(INT64_C( 2328100732832272381), INT64_C( 4111895855610225675)),
      simde_mm_set_epi64x(INT64_C( 7345032902979795528), INT64_C(-6117610524196633789)),
      simde_mm_set_epi64x(INT64_C( 2328100732832272381), INT64_C( 4111895855610225675)) },
    { simde_mm_set_epi64x(INT64_C( -829836782511317044), INT64_C(-1925559678644969716)),
      simde_mm_set_epi64x(INT64_C(-4891509177172967717), INT64_C( 7851952110853286921)),
      simde_mm_set_epi64x(INT64_C( -829836782511317044), INT64_C(-1925559678644969716)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_rem_epi64(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_rem_epu8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu8(UINT8_C(104), UINT8_C( 42), UINT8_C( 53), UINT8_C(254),
                          UINT8_C(132), UINT8_C(254), UINT8_C( 96), UINT8_C( 75),
                          UINT8_C( 31), UINT8_C(112), UINT8_C(151), UINT8_C(169),
                          UINT8_C(172), UINT8_C( 94), UINT8_C(112), UINT8_C( 90)),
      simde_x_mm_set_epu8(UINT8_C(191), UINT8_C(167), UINT8_C(226), UINT8_C( 64),
                          UINT8_C(213), UINT8_C(202), UINT8_C(110), UINT8_C(113),
                          UINT8_C( 89), UINT8_C(237), UINT8_C( 70), UINT8_C(226),
                          UINT8_C(132), UINT8_C( 91), UINT8_C(255), UINT8_C( 88)),
      simde_x_mm_set_epu8(UINT8_C(104), UINT8_C( 42), UINT8_C( 53), UINT8_C( 62),
                          UINT8_C(132), UINT8_C( 52), UINT8_C( 96), UINT8_C( 75),
                          UINT8_C( 31), UINT8_C(112), UINT8_C( 11), UINT8_C(169),
                          UINT8_C( 40), UINT8_C(  3), UINT8_C(112), UINT8_C(  2)) },
    { simde_x_mm_set_epu8(UINT8_C(233), UINT8_C(170), UINT8_C(241), UINT8_C(126),
                          UINT8_C(182), UINT8_C( 10), UINT8_C(208), UINT8_C(198),
                          UINT8_C( 93), UINT8_C(130), UINT8_C(195), UINT8_C(177),
                          UINT8_C(187), UINT8_C(223), UINT8_C(139), UINT8_C(253)),
      simde_x_mm_set_epu8(UINT8_C( 41), UINT8_C( 49), UINT8_C(171), UINT8_C(198),
                          UINT8_C( 40), UINT8_C( 44), UINT8_C(242), UINT8_C( 51),
                          UINT8_C(138), UINT8_C(217), UINT8_C(215), UINT8_C(249),
                          UINT8_C(201), UINT8_C( 37), UINT8_C(137), UINT8_C( 29)),
      simde_x_mm_set_epu8(UINT8_C( 28), UINT8_C( 23), UINT8_C( 70), UINT8_C(126),
                          UINT8_C( 22), UINT8_C( 10), UINT8_C(208), UINT8_C( 45),
                          UINT8_C( 93), UINT8_C(130), UINT8_C(195), UINT8_C(177),
                          UINT8_C(187), UINT8_C(  1), UINT8_C(  2), UINT8_C( 21)) },
    { simde_x_mm_set_epu8(UINT8_C( 88), UINT8_C(243), UINT8_C( 83), UINT8_C(222),
                          UINT8_C( 17), UINT8_C(204), UINT8_C(102), UINT8_C( 26),
                          UINT8_C( 74), UINT8_C(141), UINT8_C(252), UINT8_C(101),
                          UINT8_C(217), UINT8_C( 50), UINT8_C(247), UINT8_C(139)),
      simde_x_mm_set_epu8(UINT8_C( 71), UINT8_C( 16), UINT8_C(127), UINT8_C( 20),
                          UINT8_C(131), UINT8_C(164), UINT8_C(235), UINT8_C(213),
                          UINT8_C( 78), UINT8_C(215), UINT8_C(250), UINT8_C( 42),
                          UINT8_C(  9), UINT8_C(198), UINT8_C( 72), UINT8_C( 56)),
      simde_x_mm_set_epu8(UINT8_C( 17), UINT8_C(  3), UINT8_C( 83), UINT8_C(  2),
                          UINT8_C( 17), UINT8_C( 40), UINT8_C(102), UINT8_C( 26),
                          UINT8_C( 74), UINT8_C(141), UINT8_C(  2), UINT8_C( 17),
                          UINT8_C(  1), UINT8_C( 50), UINT8_C( 31), UINT8_C( 27)) },
    { simde_x_mm_set_epu8(UINT8_C(161), UINT8_C(114), UINT8_C(145), UINT8_C( 28),
                          UINT8_C(100), UINT8_C(203), UINT8_C(101), UINT8_C( 21),
                          UINT8_C(  3), UINT8_C(  0), UINT8_C( 63), UINT8_C(116),
                          UINT8_C( 43), UINT8_C(106), UINT8_C(227), UINT8_C(212)),
      simde_x_mm_set_epu8(UINT8_C(150), UINT8_C(207), UINT8_C( 31), UINT8_C(138),
                          UINT8_C( 70), UINT8_C( 80), UINT8_C(139), UINT8_C(103),
                          UINT8_C(157), UINT8_C(223), UINT8_C( 12), UINT8_C(182),
                          UINT8_C(215), UINT8_C(242), UINT8_C(151), UINT8_C(199)),
      simde_x_mm_set_epu8(UINT8_C( 11), UINT8_C(114), UINT8_C( 21), UINT8_C( 28),
                          UINT8_C( 30), UINT8_C( 43), UINT8_C(101), UINT8_C( 21),
                          UINT8_C(  3), UINT8_C(  0), UINT8_C(  3), UINT8_C(116),
                          UINT8_C( 43), UINT8_C(106), UINT8_C( 76), UINT8_C( 13)) },
    { simde_x_mm_set_epu8(UINT8_C( 29), UINT8_C( 89), UINT8_C(  4), UINT8_C( 90),
                          UINT8_C(255), UINT8_C( 56), UINT8_C( 40), UINT8_C(149),
                          UINT8_C(131), UINT8_C(152), UINT8_C( 36), UINT8_C(229),
                          UINT8_C(235), UINT8_C(172), UINT8_C(161), UINT8_C(250)),
      simde_x_mm_set_epu8(UINT8_C( 29), UINT8_C(101), UINT8_C( 12), UINT8_C(249),
                          UINT8_C(184), UINT8_C(195), UINT8_C(250), UINT8_C(213),
                          UINT8_C( 53), UINT8_C( 76), UINT8_C(188), UINT8_C( 25),
                          UINT8_C(176), UINT8_C(178), UINT8_C(201), UINT8_C(244)),
      simde_x_mm_set_epu8(UINT8_C(  0), UINT8_C( 89), UINT8_C(  4), UINT8_C( 90),
                          UINT8_C( 71), UINT8_C( 56), UINT8_C( 40), UINT8_C(149),
                          UINT8_C( 25), UINT8_C(  0), UINT8_C( 36), UINT8_C(  4),
                          UINT8_C( 59), UINT8_C(172), UINT8_C(161), UINT8_C(  6)) },
    { simde_x_mm_set_epu8(UINT8_C(196), UINT8_C( 36), UINT8_C( 35), UINT8_C( 54),
                          UINT8_C( 94), UINT8_C( 53), UINT8_C(132), UINT8_C(247),
                          UINT8_C(227), UINT8_C(236), UINT8_C( 32), UINT8_C(119),
                          UINT8_C(124), UINT8_C( 15), UINT8_C( 15), UINT8_C(162)),
      simde_x_mm_set_epu8(UINT8_C( 78), UINT8_C( 89), UINT8_C(105), UINT8_C( 98),
                          UINT8_C(178), UINT8_C(173), UINT8_C(134), UINT8_C(199),
                          UINT8_C(211), UINT8_C(243), UINT8_C(161), UINT8_C(220),
                          UINT8_C(171), UINT8_C(107), UINT8_C( 43), UINT8_C(  1)),
      simde_x_mm_set_epu8(UINT8_C( 40), UINT8_C( 36), UINT8_C( 35), UINT8_C( 54),
                          UINT8_C( 94), UINT8_C( 53), UINT8_C(132), UINT8_C( 48),
                          UINT8_C( 16), UINT8_C(236), UINT8_C( 32), UINT8_C(119),
                          UINT8_C(124), UINT8_C( 15), UINT8_C( 15), UINT8_C(  0)) },
    { simde_x_mm_set_epu8(UINT8_C( 32), UINT8_C( 79), UINT8_C( 19), UINT8_C( 72),
                          UINT8_C( 29), UINT8_C(203), UINT8_C( 79), UINT8_C(253),
                          UINT8_C( 57), UINT8_C( 16), UINT8_C( 99), UINT8_C(126),
                          UINT8_C(179), UINT8_C( 12), UINT8_C(100), UINT8_C( 11)),
      simde_x_mm_set_epu8(UINT8_C(101), UINT8_C(238), UINT8_C(204), UINT8_C(130),
                          UINT8_C(117), UINT8_C(170), UINT8_C(186), UINT8_C( 72),
                          UINT8_C(171), UINT8_C( 25), UINT8_C(225), UINT8_C(164),
                          UINT8_C(  7), UINT8_C( 17), UINT8_C(131), UINT8_C( 67)),
      simde_x_mm_set_epu8(UINT8_C( 32), UINT8_C( 79), UINT8_C( 19), UINT8_C( 72),
                          UINT8_C( 29), UINT8_C( 33), UINT8_C( 79), UINT8_C( 37),
                          UINT8_C( 57), UINT8_C( 16), UINT8_C( 99), UINT8_C(126),
                          UINT8_C(  4), UINT8_C( 12), UINT8_C(100), UINT8_C( 11)) },
    { simde_x_mm_set_epu8(UINT8_C(244), UINT8_C(123), UINT8_C(211), UINT8_C(215),
                          UINT8_C(204), UINT8_C(220), UINT8_C( 31), UINT8_C(204),
                          UINT8_C(229), UINT8_C( 71), UINT8_C(  9), UINT8_C(172),
                          UINT8_C(160), UINT8_C(141), UINT8_C( 31), UINT8_C( 12)),
      simde_x_mm_set_epu8(UINT8_C(188), UINT8_C( 29), UINT8_C(222), UINT8_C( 81),
                          UINT8_C(215), UINT8_C( 10), UINT8_C(190), UINT8_C(219),
                          UINT8_C(108), UINT8_C(247), UINT8_C(188), UINT8_C(215),
                          UINT8_C(232), UINT8_C(201), UINT8_C(236), UINT8_C(  9)),
      simde_x_mm_set_epu8(UINT8_C( 56), UINT8_C(  7), UINT8_C(211), UINT8_C( 53),
                          UINT8_C(204), UINT8_C(  0), UINT8_C( 31), UINT8_C(204),
                          UINT8_C( 13), UINT8_C( 71), UINT8_C(  9), UINT8_C(172),
                          UINT8_C(160), UINT8_C(141), UINT8_C( 31), UINT8_C(  3)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_rem_epu8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_rem_epu16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu16(UINT16_C(26666), UINT16_C(13822), UINT16_C(34046), UINT16_C(24651),
                           UINT16_C( 8048), UINT16_C(38825), UINT16_C(44126), UINT16_C(28762)),
      simde_x_mm_set_epu16(UINT16_C(49063), UINT16_C(57920), UINT16_C(54730), UINT16_C(28273),
                           UINT16_C(23021), UINT16_C(18146), UINT16_C(33883), UINT16_C(65368)),
      simde_x_mm_set_epu16(UINT16_C(26666), UINT16_C(13822), UINT16_C(34046), UINT16_C(24651),
                           UINT16_C( 8048), UINT16_C( 2533), UINT16_C(10243), UINT16_C(28762)) },
    { simde_x_mm_set_epu16(UINT16_C(59818), UINT16_C(61822), UINT16_C(46602), UINT16_C(53446),
                           UINT16_C(23938), UINT16_C(50097), UINT16_C(48095), UINT16_C(35837)),
      simde_x_mm_set_epu16(UINT16_C(10545), UINT16_C(43974), UINT16_C(10284), UINT16_C(62003),
                           UINT16_C(35545), UINT16_C(55289), UINT16_C(51493), UINT16_C(35101)),
      simde_x_mm_set_epu16(UINT16_C( 7093), UINT16_C(17848), UINT16_C( 5466), UINT16_C(53446),
                           UINT16_C(23938), UINT16_C(50097), UINT16_C(48095), UINT16_C(  736)) },
    { simde_x_mm_set_epu16(UINT16_C(22771), UINT16_C(21470), UINT16_C( 4556), UINT16_C(26138),
                           UINT16_C(19085), UINT16_C(64613), UINT16_C(55602), UINT16_C(63371)),
      simde_x_mm_set_epu16(UINT16_C(18192), UINT16_C(32532), UINT16_C(33700), UINT16_C(60373),
                           UINT16_C(20183), UINT16_C(64042), UINT16_C( 2502), UINT16_C(18488)),
      simde_x_mm_set_epu16(UINT16_C( 4579), UINT16_C(21470), UINT16_C( 4556), UINT16_C(26138),
                           UINT16_C(19085), UINT16_C(  571), UINT16_C(  558), UINT16_C( 7907)) },
    { simde_x_mm_set_epu16(UINT16_C(41330), UINT16_C(37148), UINT16_C(25803), UINT16_C(25877),
                           UINT16_C(  768), UINT16_C(16244), UINT16_C(11114), UINT16_C(58324)),
      simde_x_mm_set_epu16(UINT16_C(38607), UINT16_C( 8074), UINT16_C(18000), UINT16_C(35687),
                           UINT16_C(40415), UINT16_C( 3254), UINT16_C(55282), UINT16_C(38855)),
      simde_x_mm_set_epu16(UINT16_C( 2723), UINT16_C( 4852), UINT16_C( 7803), UINT16_C(25877),
                           UINT16_C(  768), UINT16_C( 3228), UINT16_C(11114), UINT16_C(19469)) },
    { simde_x_mm_set_epu16(UINT16_C( 7513), UINT16_C( 1114), UINT16_C(65336), UINT16_C(10389),
                           UINT16_C(33688), UINT16_C( 9445), UINT16_C(60332), UINT16_C(41466)),
      simde_x_mm_set_epu16(UINT16_C( 7525), UINT16_C( 3321), UINT16_C(47299), UINT16_C(64213),
                           UINT16_C(13644), UINT16_C(48153), UINT16_C(45234), UINT16_C(51700)),
      simde_x_mm_set_epu16(UINT16_C( 7513), UINT16_C( 1114), UINT16_C(18037), UINT16_C(10389),
                           UINT16_C( 6400), UINT16_C( 9445), UINT16_C(15098), UINT16_C(41466)) },
    { simde_x_mm_set_epu16(UINT16_C(50212), UINT16_C( 9014), UINT16_C(24117), UINT16_C(34039),
                           UINT16_C(58348), UINT16_C( 8311), UINT16_C(31759), UINT16_C( 4002)),
      simde_x_mm_set_epu16(UINT16_C(20057), UINT16_C(26978), UINT16_C(45741), UINT16_C(34503),
                           UINT16_C(54259), UINT16_C(41436), UINT16_C(43883), UINT16_C(11009)),
      simde_x_mm_set_epu16(UINT16_C(10098), UINT16_C( 9014), UINT16_C(24117), UINT16_C(34039),
                           UINT16_C( 4089), UINT16_C( 8311), UINT16_C(31759), UINT16_C( 4002)) },
    { simde_x_mm_set_epu16(UINT16_C( 8271), UINT16_C( 4936), UINT16_C( 7627), UINT16_C(20477),
                           UINT16_C(14608), UINT16_C(25470), UINT16_C(45836), UINT16_C(25611)),
      simde_x_mm_set_epu16(UINT16_C(26094), UINT16_C(52354), UINT16_C(30122), UINT16_C(47688),
                           UINT16_C(43801), UINT16_C(57764), UINT16_C( 1809), UINT16_C(33603)),
      simde_x_mm_set_epu16(UINT16_C( 8271), UINT16_C( 4936), UINT16_C( 7627), UINT16_C(20477),
                           UINT16_C(14608), UINT16_C(25470), UINT16_C(  611), UINT16_C(25611)) },
    { simde_x_mm_set_epu16(UINT16_C(62587), UINT16_C(54231), UINT16_C(52444), UINT16_C( 8140),
                           UINT16_C(58695), UINT16_C( 2476), UINT16_C(41101), UINT16_C( 7948)),
      simde_x_mm_set_epu16(UINT16_C(48157), UINT16_C(56913), UINT16_C(55050), UINT16_C(48859),
                           UINT16_C(27895), UINT16_C(48343), UINT16_C(59593), UINT16_C(60425)),
      simde_x_mm_set_epu16(UINT16_C(14430), UINT16_C(54231), UINT16_C(52444), UINT16_C( 8140),
                           UINT16_C( 2905), UINT16_C( 2476), UINT16_C(41101), UINT16_C( 7948)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_rem_epu16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_rem_epu32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu32(UINT32_C(1747596798), UINT32_C(2231263307), UINT32_C( 527472553), UINT32_C(2891870298)),
      simde_x_mm_set_epu32(UINT32_C(3215450688), UINT32_C(3586813553), UINT32_C(1508722402), UINT32_C(2220621656)),
      simde_x_mm_set_epu32(UINT32_C(1747596798), UINT32_C(2231263307), UINT32_C( 527472553), UINT32_C( 671248642)) },
    { simde_x_mm_set_epu32(UINT32_C(3920294270), UINT32_C(3054162118), UINT32_C(1568850865), UINT32_C(3151989757)),
      simde_x_mm_set_epu32(UINT32_C( 691121094), UINT32_C( 674034227), UINT32_C(2329532409), UINT32_C(3374680349)),
      simde_x_mm_set_epu32(UINT32_C( 464688800), UINT32_C( 358025210), UINT32_C(1568850865), UINT32_C(3151989757)) },
    { simde_x_mm_set_epu32(UINT32_C(1492341726), UINT32_C( 298608154), UINT32_C(1250819173), UINT32_C(3643996043)),
      simde_x_mm_set_epu32(UINT32_C(1192263444), UINT32_C(2208623573), UINT32_C(1322777130), UINT32_C( 163989560)),
      simde_x_mm_set_epu32(UINT32_C( 300078282), UINT32_C( 298608154), UINT32_C(1250819173), UINT32_C(  36225723)) },
    { simde_x_mm_set_epu32(UINT32_C(2708640028), UINT32_C(1691051285), UINT32_C(  50347892), UINT32_C( 728425428)),
      simde_x_mm_set_epu32(UINT32_C(2530156426), UINT32_C(1179683687), UINT32_C(2648640694), UINT32_C(3623000007)),
      simde_x_mm_set_epu32(UINT32_C( 178483602), UINT32_C( 511367598), UINT32_C(  50347892), UINT32_C( 728425428)) },
    { simde_x_mm_set_epu32(UINT32_C( 492373082), UINT32_C(4281870485), UINT32_C(2207786213), UINT32_C(3953959418)),
      simde_x_mm_set_epu32(UINT32_C( 493161721), UINT32_C(3099851477), UINT32_C( 894221337), UINT32_C(2964507124)),
      simde_x_mm_set_epu32(UINT32_C( 492373082), UINT32_C(1182019008), UINT32_C( 419343539), UINT32_C( 989452294)) },
    { simde_x_mm_set_epu32(UINT32_C(3290702646), UINT32_C(1580565751), UINT32_C(3823902839), UINT32_C(2081361826)),
      simde_x_mm_set_epu32(UINT32_C(1314482530), UINT32_C(2997716679), UINT32_C(3555959260), UINT32_C(2875927297)),
      simde_x_mm_set_epu32(UINT32_C( 661737586), UINT32_C(1580565751), UINT32_C( 267943579), UINT32_C(2081361826)) },
    { simde_x_mm_set_epu32(UINT32_C( 542053192), UINT32_C( 499863549), UINT32_C( 957375358), UINT32_C(3003933707)),
      simde_x_mm_set_epu32(UINT32_C(1710148738), UINT32_C(1974123080), UINT32_C(2870600100), UINT32_C( 118588227)),
      simde_x_mm_set_epu32(UINT32_C( 542053192), UINT32_C( 499863549), UINT32_C( 957375358), UINT32_C(  39228032)) },
    { simde_x_mm_set_epu32(UINT32_C(4101755863), UINT32_C(3436978124), UINT32_C(3846637996), UINT32_C(2693603084)),
      simde_x_mm_set_epu32(UINT32_C(3156074065), UINT32_C(3607805659), UINT32_C(1828175063), UINT32_C(3905547273)),
      simde_x_mm_set_epu32(UINT32_C( 945681798), UINT32_C(3436978124), UINT32_C( 190287870), UINT32_C(2693603084)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_rem_epu32(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_rem_epu64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu64x(UINT64_C( 7505871096235581515), UINT64_C( 2265477367564496986)),
      simde_x_mm_set_epu64x(UINT64_C(13810255550447513201), UINT64_C( 6479913377553186648)),
      simde_x_mm_set_epu64x(UINT64_C( 7505871096235581515), UINT64_C( 2265477367564496986)) },
    { simde_x_mm_set_epu64x(UINT64_C(16837535683400356038), UINT64_C( 6738163160628300797)),
      simde_x_mm_set_epu64x(UINT64_C( 2968342496979776051), UINT64_C(10005265515001776413)),
      simde_x_mm_set_epu64x(UINT64_C( 1995823198501475783), UINT64_C( 6738163160628300797)) },
    { simde_x_mm_set_epu64x(UINT64_C( 6409558907924801050), UINT64_C( 5372227444888762251)),
      simde_x_mm_set_epu64x(UINT64_C( 5120732502404950997), UINT64_C( 5681284513410730040)),
      simde_x_mm_set_epu64x(UINT64_C( 1288826405519850053), UINT64_C( 5372227444888762251)) },
    { simde_x_mm_set_epu64x(UINT64_C(11633520338587575573), UINT64_C(  216242550290965460)),
      simde_x_mm_set_epu64x(UINT64_C(10866939104613927783), UINT64_C(11375825163207743431)),
      simde_x_mm_set_epu64x(UINT64_C(  766581233973647790), UINT64_C(  216242550290965460)) },
    { simde_x_mm_set_epu64x(UINT64_C( 2114726288902596757), UINT64_C( 9482369585348649466)),
      simde_x_mm_set_epu64x(UINT64_C( 2118113466433927893), UINT64_C( 3840651400764901876)),
      simde_x_mm_set_epu64x(UINT64_C( 2114726288902596757), UINT64_C( 1801066783818845714)) },
    { simde_x_mm_set_epu64x(UINT64_C(14133460247011230967), UINT64_C(16423537638667915170)),
      simde_x_mm_set_epu64x(UINT64_C( 5645659480511055559), UINT64_C(15272728730484288257)),
      simde_x_mm_set_epu64x(UINT64_C( 2842141285989119849), UINT64_C( 1150808908183626913)) },
    { simde_x_mm_set_epu64x(UINT64_C( 2328100732832272381), UINT64_C( 4111895855610225675)),
      simde_x_mm_set_epu64x(UINT64_C( 7345032902979795528), UINT64_C(12329133549512917827)),
      simde_x_mm_set_epu64x(UINT64_C( 2328100732832272381), UINT64_C( 4111895855610225675)) },
    { simde_x_mm_set_epu64x(UINT64_C(17616907291198234572), UINT64_C(16521184395064581900)),
      simde_x_mm_set_epu64x(UINT64_C(13555234896536583899), UINT64_C( 7851952110853286921)),
      simde_x_mm_set_epu64x(UINT64_C( 4061672394661650673), UINT64_C(  817280173358008058)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_rem_epu64(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_rem_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi8(INT8_C( -65), INT8_C( -89), INT8_C( -30), INT8_C(  64),
                           INT8_C( -43), INT8_C( -54), INT8_C( 110), INT8_C( 113),
                           INT8_C(  89), INT8_C( -19), INT8_C(  70), INT8_C( -30),
                           INT8_C(-124), INT8_C(  91), INT8_C(  -1), INT8_C(  88),
                           INT8_C( 104), INT8_C(  42), INT8_C(  53), INT8_C(  -2),
                           INT8_C(-124), INT8_C(  -2), INT8_C(  96), INT8_C(  75),
                           INT8_C(  31), INT8_C( 112), INT8_C(-105), INT8_C( -87),
                           INT8_C( -84), INT8_C(  94), INT8_C( 112), INT8_C(  90)),
      simde_mm256_set_epi8(INT8_C( 121), INT8_C(  85), INT8_C(-103), INT8_C( 116),
                           INT8_C( -38), INT8_C(  21), INT8_C( 101), INT8_C( 122),
                           INT8_C(  10), INT8_C( -25), INT8_C(  54), INT8_C(  71),
                           INT8_C(-100), INT8_C(-107), INT8_C( -12), INT8_C(  84),
                           INT8_C(-108), INT8_C(  85), INT8_C( -86), INT8_C( -72),
                           INT8_C(  94), INT8_C(-102), INT8_C( -27), INT8_C(  11),
                           INT8_C(  70), INT8_C( -77), INT8_C( 121), INT8_C( -99),
                           INT8_C(  -2), INT8_C(  70), INT8_C(  49), INT8_C( 125)),
      simde_mm256_set_epi8(INT8_C( -65), INT8_C(  -4), INT8_C( -30), INT8_C(  64),
                           INT8_C(  -5), INT8_C( -12), INT8_C(   9), INT8_C( 113),
                           INT8_C(   9), INT8_C( -19), INT8_C(  16), INT8_C( -30),
                           INT8_C( -24), INT8_C(  91), INT8_C(  -1), INT8_C(   4),
                           INT8_C( 104), INT8_C(  42), INT8_C(  53), INT8_C(  -2),
                           INT8_C( -30), INT8_C(  -2), INT8_C(  15), INT8_C(   9),
                           INT8_C(  31), INT8_C(  35), INT8_C(-105), INT8_C( -87),
                           INT8_C(   0), INT8_C(  24), INT8_C(  14), INT8_C(  90)) },
    { simde_mm256_set_epi8(INT8_C(  78), INT8_C(  89), INT8_C( 105), INT8_C(  98),
                           INT8_C( -78), INT8_C( -83), INT8_C(-122), INT8_C( -57),
                           INT8_C( -45), INT8_C( -13), INT8_C( -95), INT8_C( -36),
                           INT8_C( -85), INT8_C( 107), INT8_C(  43), INT8_C(   1),
                           INT8_C( -60), INT8_C(  36), INT8_C(  35), INT8_C(  54),
                           INT8_C(  94), INT8_C(  53), INT8_C(-124), INT8_C(  -9),
                           INT8_C( -29), INT8_C( -20), INT8_C(  32), INT8_C( 119),
                           INT8_C( 124), INT8_C(  15), INT8_C(  15), INT8_C( -94)),
      simde_mm256_set_epi8(INT8_C( -61), INT8_C(  49), INT8_C(  14), INT8_C( -86),
                           INT8_C( -53), INT8_C( -89), INT8_C(   3), INT8_C( -41),
                           INT8_C(  63), INT8_C(  -8), INT8_C(  55), INT8_C( -37),
                           INT8_C( -35), INT8_C(-121), INT8_C(  61), INT8_C( -65),
                           INT8_C( -47), INT8_C(  91), INT8_C(  87), INT8_C(-119),
                           INT8_C(  87), INT8_C(  76), INT8_C(  44), INT8_C(-116),
                           INT8_C(   2), INT8_C( -56), INT8_C(  36), INT8_C( -61),
                           INT8_C( -56), INT8_C( 125), INT8_C(  -2), INT8_C(-117)),
      simde_mm256_set_epi8(INT8_C(  17), INT8_C(  40), INT8_C(   7), INT8_C(  12),
                           INT8_C( -25), INT8_C( -83), INT8_C(  -2), INT8_C( -16),
                           INT8_C( -45), INT8_C(  -5), INT8_C( -40), INT8_C( -36),
                           INT8_C( -15), INT8_C( 107), INT8_C(  43), INT8_C(   1),
                           INT8_C( -13), INT8_C(  36), INT8_C(  35), INT8_C(  54),
                           INT8_C(   7), INT8_C(  53), INT8_C( -36), INT8_C(  -9),
                           INT8_C(  -1), INT8_C( -20), INT8_C(  32), INT8_C(  58),
                           INT8_C(  12), INT8_C(  15), INT8_C(   1), INT8_C( -94)) },
    { simde_mm256_set_epi8(INT8_C( -22), INT8_C(  94), INT8_C( -16), INT8_C(  12),
                           INT8_C(-110), INT8_C(   1), INT8_C(-109), INT8_C(  59),
                           INT8_C(  -3), INT8_C(  26), INT8_C(  26), INT8_C(  40),
                           INT8_C(  12), INT8_C(   2), INT8_C( -26), INT8_C(-111),
                           INT8_C( -86), INT8_C( 105), INT8_C( 111), INT8_C( -96),
                           INT8_C(-116), INT8_C( -54), INT8_C( -90), INT8_C( -36),
                           INT8_C( -69), INT8_C(  65), INT8_C(  -6), INT8_C( -61),
                           INT8_C(  33), INT8_C(-125), INT8_C(   2), INT8_C( -92)),
      simde_mm256_set_epi8(INT8_C( -79), INT8_C( -35), INT8_C(  -5), INT8_C( -75),
                           INT8_C( -97), INT8_C( -74), INT8_C(  11), INT8_C(  11),
                           INT8_C(  39), INT8_C(  37), INT8_C(  39), INT8_C( -48),
                           INT8_C(-120), INT8_C( -76), INT8_C( -41), INT8_C(-117),
                           INT8_C(-112), INT8_C(-128), INT8_C( -53), INT8_C( -50),
                           INT8_C( -83), INT8_C(  36), INT8_C(-123), INT8_C( -81),
                           INT8_C( -25), INT8_C(   7), INT8_C( -20), INT8_C(  68),
                           INT8_C( -63), INT8_C( -35), INT8_C(  27), INT8_C(   8)),
      simde_mm256_set_epi8(INT8_C( -22), INT8_C(  24), INT8_C(  -1), INT8_C(  12),
                           INT8_C( -13), INT8_C(   1), INT8_C( -10), INT8_C(   4),
                           INT8_C(  -3), INT8_C(  26), INT8_C(  26), INT8_C(  40),
                           INT8_C(  12), INT8_C(   2), INT8_C( -26), INT8_C(-111),
                           INT8_C( -86), INT8_C( 105), INT8_C(   5), INT8_C( -46),
                           INT8_C( -33), INT8_C( -18), INT8_C( -90), INT8_C( -36),
                           INT8_C( -19), INT8_C(   2), INT8_C(  -6), INT8_C( -61),
                           INT8_C(  33), INT8_C( -20), INT8_C(   2), INT8_C(  -4)) },
    { simde_mm256_set_epi8(INT8_C(  71), INT8_C( -23), INT8_C(  74), INT8_C( 125),
                           INT8_C(  81), INT8_C( -13), INT8_C(-117), INT8_C( -66),
                           INT8_C(  31), INT8_C( -80), INT8_C(  97), INT8_C(  -3),
                           INT8_C( 123), INT8_C( -80), INT8_C( -40), INT8_C( 108),
                           INT8_C(  -9), INT8_C(  97), INT8_C(  75), INT8_C( -53),
                           INT8_C(-128), INT8_C( -18), INT8_C(  79), INT8_C(-115),
                           INT8_C(  86), INT8_C(  29), INT8_C( -93), INT8_C( -49),
                           INT8_C( 111), INT8_C(  -7), INT8_C(-117), INT8_C( -47)),
      simde_mm256_set_epi8(INT8_C( 120), INT8_C( 127), INT8_C(  28), INT8_C(  95),
                           INT8_C( -81), INT8_C( -33), INT8_C( 119), INT8_C( -42),
                           INT8_C( -36), INT8_C( 102), INT8_C(  86), INT8_C(  22),
                           INT8_C( 119), INT8_C( -49), INT8_C(  12), INT8_C( -73),
                           INT8_C( -84), INT8_C( -14), INT8_C( -83), INT8_C(  -7),
                           INT8_C(  52), INT8_C( 108), INT8_C(-128), INT8_C( -53),
                           INT8_C(  85), INT8_C(-121), INT8_C( -29), INT8_C(  35),
                           INT8_C( -69), INT8_C(  24), INT8_C(  -6), INT8_C( -37)),
      simde_mm256_set_epi8(INT8_C(  71), INT8_C( -23), INT8_C(  18), INT8_C(  30),
                           INT8_C(   0), INT8_C( -13), INT8_C(-117), INT8_C( -24),
                           INT8_C(  31), INT8_C( -80), INT8_C(  11), INT8_C(  -3),
                           INT8_C(   4), INT8_C( -31), INT8_C(  -4), INT8_C(  35),
                           INT8_C(  -9), INT8_C(  13), INT8_C(  75), INT8_C(  -4),
                           INT8_C( -24), INT8_C( -18), INT8_C(  79), INT8_C(  -9),
                           INT8_C(   1), INT8_C(  29), INT8_C(  -6), INT8_C( -14),
                           INT8_C(  42), INT8_C(  -7), INT8_C(  -3), INT8_C( -10)) },
    { simde_mm256_set_epi8(INT8_C( -72), INT8_C(  63), INT8_C(  95), INT8_C( -92),
                           INT8_C(  65), INT8_C(  71), INT8_C( -82), INT8_C(  88),
                           INT8_C( -73), INT8_C(-114), INT8_C(  98), INT8_C(  14),
                           INT8_C(  25), INT8_C( -83), INT8_C(  87), INT8_C(   2),
                           INT8_C( -65), INT8_C(-113), INT8_C(-104), INT8_C(   2),
                           INT8_C( 126), INT8_C(   0), INT8_C( -94), INT8_C(  57),
                           INT8_C( -11), INT8_C(  36), INT8_C( -17), INT8_C(  54),
                           INT8_C(  33), INT8_C( -91), INT8_C( -57), INT8_C(  84)),
      simde_mm256_set_epi8(INT8_C( -82), INT8_C(  60), INT8_C(-124), INT8_C( -48),
                           INT8_C(  58), INT8_C( -78), INT8_C( 116), INT8_C( -16),
                           INT8_C(  37), INT8_C(-125), INT8_C( 100), INT8_C( -79),
                           INT8_C(  19), INT8_C( 102), INT8_C(  81), INT8_C(  86),
                           INT8_C(  25), INT8_C(  43), INT8_C(  51), INT8_C(-116),
                           INT8_C(   9), INT8_C(  40), INT8_C( -29), INT8_C(  75),
                           INT8_C( -48), INT8_C( -97), INT8_C( -81), INT8_C( 109),
                           INT8_C( -26), INT8_C(  87), INT8_C(  -2), INT8_C( -40)),
      simde_mm256_set_epi8(INT8_C( -72), INT8_C(   3), INT8_C(  95), INT8_C( -44),
                           INT8_C(   7), INT8_C(  71), INT8_C( -82), INT8_C(   8),
                           INT8_C( -36), INT8_C(-114), INT8_C(  98), INT8_C(  14),
                           INT8_C(   6), INT8_C( -83), INT8_C(   6), INT8_C(   2),
                           INT8_C( -15), INT8_C( -27), INT8_C(  -2), INT8_C(   2),
                           INT8_C(   0), INT8_C(   0), INT8_C(  -7), INT8_C(  57),
                           INT8_C( -11), INT8_C(  36), INT8_C( -17), INT8_C(  54),
                           INT8_C(   7), INT8_C(  -4), INT8_C(  -1), INT8_C(   4)) },
    { simde_mm256_set_epi8(INT8_C(  54), INT8_C(  43), INT8_C( 109), INT8_C( -69),
                           INT8_C(-118), INT8_C(  62), INT8_C( -34), INT8_C(-102),
                           INT8_C( 123), INT8_C(  21), INT8_C(  -9), INT8_C(  99),
                           INT8_C(  37), INT8_C(  48), INT8_C( 116), INT8_C( -23),
                           INT8_C(  95), INT8_C(  -5), INT8_C(-109), INT8_C( 109),
                           INT8_C( -51), INT8_C( -50), INT8_C(  57), INT8_C(  17),
                           INT8_C( 121), INT8_C(  25), INT8_C(   3), INT8_C(  55),
                           INT8_C( -78), INT8_C(-127), INT8_C(-107), INT8_C( -49)),
      simde_mm256_set_epi8(INT8_C(-125), INT8_C(  42), INT8_C(-105), INT8_C( -46),
                           INT8_C(  12), INT8_C( -93), INT8_C(-118), INT8_C( -49),
                           INT8_C(  43), INT8_C(  57), INT8_C(  61), INT8_C(  62),
                           INT8_C(  81), INT8_C( -72), INT8_C(   6), INT8_C(  93),
                           INT8_C( -89), INT8_C(   1), INT8_C(-111), INT8_C(   9),
                           INT8_C(   4), INT8_C(  17), INT8_C(  10), INT8_C( 101),
                           INT8_C( -70), INT8_C( -75), INT8_C(-101), INT8_C( -13),
                           INT8_C( -67), INT8_C( -65), INT8_C( -34), INT8_C( -51)),
      simde_mm256_set_epi8(INT8_C(  54), INT8_C(   1), INT8_C(   4), INT8_C( -23),
                           INT8_C( -10), INT8_C(  62), INT8_C( -34), INT8_C(  -4),
                           INT8_C(  37), INT8_C(  21), INT8_C(  -9), INT8_C(  37),
                           INT8_C(  37), INT8_C(  48), INT8_C(   2), INT8_C( -23),
                           INT8_C(   6), INT8_C(   0), INT8_C(-109), INT8_C(   1),
                           INT8_C(  -3), INT8_C( -16), INT8_C(   7), INT8_C(  17),
                           INT8_C(  51), INT8_C(  25), INT8_C(   3), INT8_C(   3),
                           INT8_C( -11), INT8_C( -62), INT8_C(  -5), INT8_C( -49)) },
    { simde_mm256_set_epi8(INT8_C(  23), INT8_C(-124), INT8_C( 106), INT8_C( 109),
                           INT8_C(-121), INT8_C( -53), INT8_C(  98), INT8_C( 120),
                           INT8_C( 101), INT8_C(  52), INT8_C(  82), INT8_C(  44),
                           INT8_C(-114), INT8_C(  14), INT8_C(  99), INT8_C( -11),
                           INT8_C(   8), INT8_C(-116), INT8_C(-115), INT8_C( 123),
                           INT8_C( -37), INT8_C( -93), INT8_C( -60), INT8_C( -23),
                           INT8_C(  34), INT8_C( -71), INT8_C( -28), INT8_C( 108),
                           INT8_C(  95), INT8_C( -20), INT8_C(  97), INT8_C(  41)),
      simde_mm256_set_epi8(INT8_C( 125), INT8_C( -27), INT8_C( -53), INT8_C(  45),
                           INT8_C(  24), INT8_C(   5), INT8_C(  90), INT8_C(  83),
                           INT8_C(-111), INT8_C(  85), INT8_C(-100), INT8_C( -92),
                           INT8_C(-107), INT8_C( -55), INT8_C(  48), INT8_C(  -1),
                           INT8_C(  41), INT8_C(  42), INT8_C(  94), INT8_C(-127),
                           INT8_C(-121), INT8_C(   8), INT8_C(  12), INT8_C( -53),
                           INT8_C(-128), INT8_C( -54), INT8_C(-108), INT8_C(  -4),
                           INT8_C( 104), INT8_C( -48), INT8_C(  98), INT8_C( -94)),
      simde_mm256_set_epi8(INT8_C(  23), INT8_C( -16), INT8_C(   0), INT8_C(  19),
                           INT8_C(  -1), INT8_C(  -3), INT8_C(   8), INT8_C(  37),
                           INT8_C( 101), INT8_C(  52), INT8_C(  82), INT8_C(  44),
                           INT8_C(  -7), INT8_C(  14), INT8_C(   3), INT8_C(   0),
                           INT8_C(   8), INT8_C( -32), INT8_C( -21), INT8_C( 123),
                           INT8_C( -37), INT8_C(  -5), INT8_C(   0), INT8_C( -23),
                           INT8_C(  34), INT8_C( -17), INT8_C( -28), INT8_C(   0),
                           INT8_C(  95), INT8_C( -20), INT8_C(  97), INT8_C(  41)) },
    { simde_mm256_set_epi8(INT8_C( -94), INT8_C(  31), INT8_C( -88), INT8_C(  17),
                           INT8_C(  50), INT8_C( 110), INT8_C( -25), INT8_C( -40),
                           INT8_C(  94), INT8_C(  20), INT8_C( -93), INT8_C( -73),
                           INT8_C( -99), INT8_C(  16), INT8_C(  91), INT8_C(  54),
                           INT8_C(  62), INT8_C(  81), INT8_C( -97), INT8_C(-105),
                           INT8_C(  57), INT8_C(  12), INT8_C( 118), INT8_C(  33),
                           INT8_C( -76), INT8_C(-117), INT8_C(   1), INT8_C(   5),
                           INT8_C(  78), INT8_C(  13), INT8_C(  93), INT8_C(-101)),
      simde_mm256_set_epi8(INT8_C( -63), INT8_C( -26), INT8_C(  93), INT8_C(  23),
                           INT8_C( -63), INT8_C(  52), INT8_C( -33), INT8_C( -81),
                           INT8_C( -51), INT8_C(  45), INT8_C( -90), INT8_C(  24),
                           INT8_C(  71), INT8_C( -22), INT8_C( -95), INT8_C(-114),
                           INT8_C( -72), INT8_C( -38), INT8_C( -66), INT8_C( -44),
                           INT8_C( 116), INT8_C( -97), INT8_C(  44), INT8_C(  55),
                           INT8_C( -43), INT8_C(-123), INT8_C(  60), INT8_C(   3),
                           INT8_C(  58), INT8_C(  -1), INT8_C( 125), INT8_C( -67)),
      simde_mm256_set_epi8(INT8_C( -31), INT8_C(   5), INT8_C( -88), INT8_C(  17),
                           INT8_C(  50), INT8_C(   6), INT8_C( -25), INT8_C( -40),
                           INT8_C(  43), INT8_C(  20), INT8_C(  -3), INT8_C(  -1),
                           INT8_C( -28), INT8_C(  16), INT8_C(  91), INT8_C(  54),
                           INT8_C(  62), INT8_C(   5), INT8_C( -31), INT8_C( -17),
                           INT8_C(  57), INT8_C(  12), INT8_C(  30), INT8_C(  33),
                           INT8_C( -33), INT8_C(-117), INT8_C(   1), INT8_C(   2),
                           INT8_C(  20), INT8_C(   0), INT8_C(  93), INT8_C( -34)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_rem_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_rem_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi16(INT16_C(-16473), INT16_C( -7616), INT16_C(-10806), INT16_C( 28273),
                            INT16_C( 23021), INT16_C( 18146), INT16_C(-31653), INT16_C(  -168),
                            INT16_C( 26666), INT16_C( 13822), INT16_C(-31490), INT16_C( 24651),
                            INT16_C(  8048), INT16_C(-26711), INT16_C(-21410), INT16_C( 28762)),
      simde_mm256_set_epi16(INT16_C( 10545), INT16_C(-21562), INT16_C( 10284), INT16_C( -3533),
                            INT16_C(-29991), INT16_C(-10247), INT16_C(-14043), INT16_C(-30435),
                            INT16_C( -5718), INT16_C( -3714), INT16_C(-18934), INT16_C(-12090),
                            INT16_C( 23938), INT16_C(-15439), INT16_C(-17441), INT16_C(-29699)),
      simde_mm256_set_epi16(INT16_C( -5928), INT16_C( -7616), INT16_C(  -522), INT16_C(     9),
                            INT16_C( 23021), INT16_C(  7899), INT16_C( -3567), INT16_C(  -168),
                            INT16_C(  3794), INT16_C(  2680), INT16_C(-12556), INT16_C(   471),
                            INT16_C(  8048), INT16_C(-11272), INT16_C( -3969), INT16_C( 28762)) },
    { simde_mm256_set_epi16(INT16_C( 18192), INT16_C( 32532), INT16_C(-31836), INT16_C( -5163),
                            INT16_C( 20183), INT16_C( -1494), INT16_C(  2502), INT16_C( 18488),
                            INT16_C( 22771), INT16_C( 21470), INT16_C(  4556), INT16_C( 26138),
                            INT16_C( 19085), INT16_C(  -923), INT16_C( -9934), INT16_C( -2165)),
      simde_mm256_set_epi16(INT16_C(-26929), INT16_C(  8074), INT16_C( 18000), INT16_C(-29849),
                            INT16_C(-25121), INT16_C(  3254), INT16_C(-10254), INT16_C(-26681),
                            INT16_C(-24206), INT16_C(-28388), INT16_C( 25803), INT16_C( 25877),
                            INT16_C(   768), INT16_C( 16244), INT16_C( 11114), INT16_C( -7212)),
      simde_mm256_set_epi16(INT16_C( 18192), INT16_C(   236), INT16_C(-13836), INT16_C( -5163),
                            INT16_C( 20183), INT16_C( -1494), INT16_C(  2502), INT16_C( 18488),
                            INT16_C( 22771), INT16_C( 21470), INT16_C(  4556), INT16_C(   261),
                            INT16_C(   653), INT16_C(  -923), INT16_C( -9934), INT16_C( -2165)) },
    { simde_mm256_set_epi16(INT16_C(  7525), INT16_C(  3321), INT16_C(-18237), INT16_C( -1323),
                            INT16_C( 13644), INT16_C(-17383), INT16_C(-20302), INT16_C(-13836),
                            INT16_C(  7513), INT16_C(  1114), INT16_C(  -200), INT16_C( 10389),
                            INT16_C(-31848), INT16_C(  9445), INT16_C( -5204), INT16_C(-24070)),
      simde_mm256_set_epi16(INT16_C( 20057), INT16_C( 26978), INT16_C(-19795), INT16_C(-31033),
                            INT16_C(-11277), INT16_C(-24100), INT16_C(-21653), INT16_C( 11009),
                            INT16_C(-15324), INT16_C(  9014), INT16_C( 24117), INT16_C(-31497),
                            INT16_C( -7188), INT16_C(  8311), INT16_C( 31759), INT16_C(  4002)),
      simde_mm256_set_epi16(INT16_C(  7525), INT16_C(  3321), INT16_C(-18237), INT16_C( -1323),
                            INT16_C(  2367), INT16_C(-17383), INT16_C(-20302), INT16_C( -2827),
                            INT16_C(  7513), INT16_C(  1114), INT16_C(  -200), INT16_C( 10389),
                            INT16_C( -3096), INT16_C(  1134), INT16_C( -5204), INT16_C(   -58)) },
    { simde_mm256_set_epi16(INT16_C( 26094), INT16_C(-13182), INT16_C( 30122), INT16_C(-17848),
                            INT16_C(-21735), INT16_C( -7772), INT16_C(  1809), INT16_C(-31933),
                            INT16_C(  8271), INT16_C(  4936), INT16_C(  7627), INT16_C( 20477),
                            INT16_C( 14608), INT16_C( 25470), INT16_C(-19700), INT16_C( 25611)),
      simde_mm256_set_epi16(INT16_C(-17379), INT16_C( -8623), INT16_C(-10486), INT16_C(-16677),
                            INT16_C( 27895), INT16_C(-17193), INT16_C( -5943), INT16_C( -5111),
                            INT16_C( -2949), INT16_C(-11305), INT16_C(-13092), INT16_C(  8140),
                            INT16_C( -6841), INT16_C(  2476), INT16_C(-24435), INT16_C(  7948)),
      simde_mm256_set_epi16(INT16_C(  8715), INT16_C( -4559), INT16_C(  9150), INT16_C( -1171),
                            INT16_C(-21735), INT16_C( -7772), INT16_C(  1809), INT16_C( -1267),
                            INT16_C(  2373), INT16_C(  4936), INT16_C(  7627), INT16_C(  4197),
                            INT16_C(   926), INT16_C(   710), INT16_C(-19700), INT16_C(  1767)) },
    { simde_mm256_set_epi16(INT16_C( 26466), INT16_C( 21183), INT16_C(  5811), INT16_C( 17016),
                            INT16_C(-14374), INT16_C(-18761), INT16_C(-11284), INT16_C(  -933),
                            INT16_C( 30444), INT16_C( 20573), INT16_C(-14964), INT16_C( 25607),
                            INT16_C(-28815), INT16_C(-28739), INT16_C( 27147), INT16_C( -3265)),
      simde_mm256_set_epi16(INT16_C( 26902), INT16_C(-14525), INT16_C( -7905), INT16_C( -8015),
                            INT16_C(-22131), INT16_C( 18318), INT16_C(-21513), INT16_C(  9770),
                            INT16_C(  4118), INT16_C(-32437), INT16_C(  6621), INT16_C( -7897),
                            INT16_C( 22002), INT16_C(-32381), INT16_C( 15537), INT16_C(-26793)),
      simde_mm256_set_epi16(INT16_C( 26466), INT16_C(  6658), INT16_C(  5811), INT16_C(   986),
                            INT16_C(-14374), INT16_C(  -443), INT16_C(-11284), INT16_C(  -933),
                            INT16_C(  1618), INT16_C( 20573), INT16_C( -1722), INT16_C(  1916),
                            INT16_C( -6813), INT16_C(-28739), INT16_C( 11610), INT16_C( -3265)) },
    { simde_mm256_set_epi16(INT16_C( -5538), INT16_C( -4084), INT16_C(-28159), INT16_C(-27845),
                            INT16_C(  -742), INT16_C(  6696), INT16_C(  3074), INT16_C( -6511),
                            INT16_C(-21911), INT16_C( 28576), INT16_C(-29494), INT16_C(-22820),
                            INT16_C(-17599), INT16_C( -1341), INT16_C(  8579), INT16_C(   676)),
      simde_mm256_set_epi16(INT16_C(-10155), INT16_C(-12697), INT16_C( -5222), INT16_C(-32377),
                            INT16_C( 32076), INT16_C(-13716), INT16_C( 13383), INT16_C(-22332),
                            INT16_C( 18058), INT16_C(-22719), INT16_C( -8799), INT16_C(-25251),
                            INT16_C(-16195), INT16_C(-26213), INT16_C(-12331), INT16_C( 27016)),
      simde_mm256_set_epi16(INT16_C( -5538), INT16_C( -4084), INT16_C( -2049), INT16_C(-27845),
                            INT16_C(  -742), INT16_C(  6696), INT16_C(  3074), INT16_C( -6511),
                            INT16_C( -3853), INT16_C(  5857), INT16_C( -3097), INT16_C(-22820),
                            INT16_C( -1404), INT16_C( -1341), INT16_C(  8579), INT16_C(   676)) },
    { simde_mm256_set_epi16(INT16_C( 13886), INT16_C( 28688), INT16_C( 30551), INT16_C(-28928),
                            INT16_C( -9491), INT16_C(-26549), INT16_C(  -738), INT16_C( 22350),
                            INT16_C(  7981), INT16_C(-15059), INT16_C(-18848), INT16_C( 16804),
                            INT16_C(-31876), INT16_C( -1787), INT16_C( 29649), INT16_C(  -721)),
      simde_mm256_set_epi16(INT16_C(  7566), INT16_C( 25511), INT16_C( -5831), INT16_C( 13989),
                            INT16_C( 13965), INT16_C(-31065), INT16_C(    77), INT16_C(-30384),
                            INT16_C( 21705), INT16_C(-23032), INT16_C( -2503), INT16_C( -8652),
                            INT16_C(-23147), INT16_C( -4009), INT16_C(  7598), INT16_C( 23051)),
      simde_mm256_set_epi16(INT16_C(  6320), INT16_C(  3177), INT16_C(  1396), INT16_C(  -950),
                            INT16_C( -9491), INT16_C(-26549), INT16_C(   -45), INT16_C( 22350),
                            INT16_C(  7981), INT16_C(-15059), INT16_C( -1327), INT16_C(  8152),
                            INT16_C( -8729), INT16_C( -1787), INT16_C(  6855), INT16_C(  -721)) },
    { simde_mm256_set_epi16(INT16_C( 26789), INT16_C(-25295), INT16_C(-31460), INT16_C(-29347),
                            INT16_C(-16029), INT16_C(-32645), INT16_C(-19836), INT16_C( 31541),
                            INT16_C(-32299), INT16_C(-14817), INT16_C( 22782), INT16_C(-18634),
                            INT16_C( -2744), INT16_C(   907), INT16_C(  9939), INT16_C(   395)),
      simde_mm256_set_epi16(INT16_C( 18409), INT16_C( 19069), INT16_C( 20979), INT16_C(-29762),
                            INT16_C(  8112), INT16_C( 25085), INT16_C( 31664), INT16_C(-10132),
                            INT16_C( -2207), INT16_C( 19403), INT16_C(-32530), INT16_C( 20365),
                            INT16_C( 22045), INT16_C(-23601), INT16_C( 28665), INT16_C(-29743)),
      simde_mm256_set_epi16(INT16_C(  8380), INT16_C( -6226), INT16_C(-10481), INT16_C(-29347),
                            INT16_C( -7917), INT16_C( -7560), INT16_C(-19836), INT16_C(  1145),
                            INT16_C( -1401), INT16_C(-14817), INT16_C( 22782), INT16_C(-18634),
                            INT16_C( -2744), INT16_C(   907), INT16_C(  9939), INT16_C(   395)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_rem_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_rem_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi32(INT32_C(-1079516608), INT32_C( -708153743), INT32_C( 1508722402), INT32_C(-2074345640),
                            INT32_C( 1747596798), INT32_C(-2063703989), INT32_C(  527472553), INT32_C(-1403096998)),
      simde_mm256_set_epi32(INT32_C(  691121094), INT32_C(  674034227), INT32_C(-1965434887), INT32_C( -920286947),
                            INT32_C( -374673026), INT32_C(-1240805178), INT32_C( 1568850865), INT32_C(-1142977539)),
      simde_mm256_set_epi32(INT32_C( -388395514), INT32_C(  -34119516), INT32_C( 1508722402), INT32_C( -233771746),
                            INT32_C(  248904694), INT32_C( -822898811), INT32_C(  527472553), INT32_C( -260119459)) },
    { simde_mm256_set_epi32(INT32_C( 1192263444), INT32_C(-2086343723), INT32_C( 1322777130), INT32_C(  163989560),
                            INT32_C( 1492341726), INT32_C(  298608154), INT32_C( 1250819173), INT32_C( -650971253)),
      simde_mm256_set_epi32(INT32_C(-1764810870), INT32_C( 1179683687), INT32_C(-1646326602), INT32_C( -671967289),
                            INT32_C(-1586327268), INT32_C( 1691051285), INT32_C(   50347892), INT32_C(  728425428)),
      simde_mm256_set_epi32(INT32_C( 1192263444), INT32_C( -906660036), INT32_C( 1322777130), INT32_C(  163989560),
                            INT32_C( 1492341726), INT32_C(  298608154), INT32_C(   42469765), INT32_C( -650971253)) },
    { simde_mm256_set_epi32(INT32_C(  493161721), INT32_C(-1195115819), INT32_C(  894221337), INT32_C(-1330460172),
                            INT32_C(  492373082), INT32_C(  -13096811), INT32_C(-2087181083), INT32_C( -341007878)),
      simde_mm256_set_epi32(INT32_C( 1314482530), INT32_C(-1297250617), INT32_C( -739008036), INT32_C(-1419039999),
                            INT32_C(-1004264650), INT32_C( 1580565751), INT32_C( -471064457), INT32_C( 2081361826)),
      simde_mm256_set_epi32(INT32_C(  493161721), INT32_C(-1195115819), INT32_C(  155213301), INT32_C(-1330460172),
                            INT32_C(  492373082), INT32_C(  -13096811), INT32_C( -202923255), INT32_C( -341007878)) },
    { simde_mm256_set_epi32(INT32_C( 1710148738), INT32_C( 1974123080), INT32_C(-1424367196), INT32_C(  118588227),
                            INT32_C(  542053192), INT32_C(  499863549), INT32_C(  957375358), INT32_C(-1291033589)),
      simde_mm256_set_epi32(INT32_C(-1138893231), INT32_C( -687161637), INT32_C( 1828175063), INT32_C( -389420023),
                            INT32_C( -193211433), INT32_C( -857989172), INT32_C( -448329300), INT32_C(-1601364212)),
      simde_mm256_set_epi32(INT32_C(  571255507), INT32_C(  599799806), INT32_C(-1424367196), INT32_C(  118588227),
                            INT32_C(  155630326), INT32_C(  499863549), INT32_C(   60716758), INT32_C(-1291033589)) },
    { simde_mm256_set_epi32(INT32_C( 1734496959), INT32_C(  380846712), INT32_C( -941967689), INT32_C( -739443621),
                            INT32_C( 1995198557), INT32_C( -980655097), INT32_C(-1888383043), INT32_C( 1779168063)),
      simde_mm256_set_epi32(INT32_C( 1763100483), INT32_C( -518004559), INT32_C(-1450358898), INT32_C(-1409866198),
                            INT32_C(  269910347), INT32_C(  433971495), INT32_C( 1441956227), INT32_C( 1018271575)),
      simde_mm256_set_epi32(INT32_C( 1734496959), INT32_C(  380846712), INT32_C( -941967689), INT32_C( -739443621),
                            INT32_C(  105826128), INT32_C( -112712107), INT32_C( -446426816), INT32_C(  760896488)) },
    { simde_mm256_set_epi32(INT32_C( -362876916), INT32_C(-1845390533), INT32_C(  -48621016), INT32_C(  201516689),
                            INT32_C(-1435930720), INT32_C(-1932876068), INT32_C(-1153303869), INT32_C(  562234020)),
      simde_mm256_set_epi32(INT32_C( -665465241), INT32_C( -342195833), INT32_C( 2102184556), INT32_C(  877111492),
                            INT32_C( 1183491905), INT32_C( -576610979), INT32_C(-1061316197), INT32_C( -808097400)),
      simde_mm256_set_epi32(INT32_C( -362876916), INT32_C( -134411368), INT32_C(  -48621016), INT32_C(  201516689),
                            INT32_C( -252438815), INT32_C( -203043131), INT32_C(  -91987672), INT32_C(  562234020)) },
    { simde_mm256_set_epi32(INT32_C(  910061584), INT32_C( 2002226944), INT32_C( -621963189), INT32_C(  -48343218),
                            INT32_C(  523093293), INT32_C(-1235205724), INT32_C(-2088961787), INT32_C( 1943141679)),
      simde_mm256_set_epi32(INT32_C(  495870887), INT32_C( -382126427), INT32_C(  915244711), INT32_C(    5081424),
                            INT32_C( 1422501384), INT32_C( -163979724), INT32_C(-1516900265), INT32_C(  497965579)),
      simde_mm256_set_epi32(INT32_C(  414190697), INT32_C(   91594809), INT32_C( -621963189), INT32_C(   -2610402),
                            INT32_C(  523093293), INT32_C(  -87347656), INT32_C( -572061522), INT32_C(  449244942)) },
    { simde_mm256_set_epi32(INT32_C( 1755684145), INT32_C(-2061726371), INT32_C(-1050443653), INT32_C(-1299940555),
                            INT32_C(-2116696545), INT32_C( 1493088054), INT32_C( -179829877), INT32_C(  651362699)),
      simde_mm256_set_epi32(INT32_C( 1206471293), INT32_C( 1374915518), INT32_C(  531653117), INT32_C( 2075187308),
                            INT32_C( -144618549), INT32_C(-2131865715), INT32_C( 1444783055), INT32_C( 1878625233)),
      simde_mm256_set_epi32(INT32_C(  549212852), INT32_C( -686810853), INT32_C( -518790536), INT32_C(-1299940555),
                            INT32_C(  -92036859), INT32_C( 1493088054), INT32_C( -179829877), INT32_C(  651362699)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_rem_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_rem_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi64x(INT64_C(-4636488523262038415), INT64_C( 6479913377553186648),
                             INT64_C( 7505871096235581515), INT64_C( 2265477367564496986)),
      simde_mm256_set_epi64x(INT64_C( 2968342496979776051), INT64_C(-8441478558707775203),
                             INT64_C(-1609208390309195578), INT64_C( 6738163160628300797)),
      simde_mm256_set_epi64x(INT64_C(-1668146026282262364), INT64_C( 6479913377553186648),
                             INT64_C( 1069037534998799203), INT64_C( 2265477367564496986)) },
    { simde_mm256_set_epi64x(INT64_C( 5120732502404950997), INT64_C( 5681284513410730040),
                             INT64_C( 6409558907924801050), INT64_C( 5372227444888762251)),
      simde_mm256_set_epi64x(INT64_C(-7579804969095623833), INT64_C(-7070918910501808185),
                             INT64_C(-6813223735121976043), INT64_C(  216242550290965460)),
      simde_mm256_set_epi64x(INT64_C( 5120732502404950997), INT64_C( 5681284513410730040),
                             INT64_C( 6409558907924801050), INT64_C(  182406237905591211)) },
    { simde_mm256_set_epi64x(INT64_C( 2118113466433927893), INT64_C( 3840651400764901876),
                             INT64_C( 2114726288902596757), INT64_C(-8964374488360902150)),
      simde_mm256_set_epi64x(INT64_C( 5645659480511055559), INT64_C(-3174015343225263359),
                             INT64_C(-4313283826698320649), INT64_C(-2023206435041636446)),
      simde_mm256_set_epi64x(INT64_C( 2118113466433927893), INT64_C(  666636057539638517),
                             INT64_C( 2114726288902596757), INT64_C( -871548748194356366)) },
    { simde_mm256_set_epi64x(INT64_C( 7345032902979795528), INT64_C(-6117610524196633789),
                             INT64_C( 2328100732832272381), INT64_C( 4111895855610225675)),
      simde_mm256_set_epi64x(INT64_C(-4891509177172967717), INT64_C( 7851952110853286921),
                             INT64_C( -829836782511317044), INT64_C(-1925559678644969716)),
      simde_mm256_set_epi64x(INT64_C( 2453523725806827811), INT64_C(-6117610524196633789),
                             INT64_C(  668427167809638293), INT64_C(  260776498320286243)) },
    { simde_mm256_set_epi64x(INT64_C( 7449607714297299576), INT64_C(-4045720414588175269),
                             INT64_C( 8569312554655704071), INT64_C(-8110543410226793665)),
      simde_mm256_set_epi64x(INT64_C( 7572458917823766705), INT64_C(-6229244031487498710),
                             INT64_C( 1159256113650983207), INT64_C( 6193154838246823767)),
      simde_mm256_set_epi64x(INT64_C( 7449607714297299576), INT64_C(-4045720414588175269),
                             INT64_C(  454519759098821622), INT64_C(-1917388571979969898)) },
    { simde_mm256_set_epi64x(INT64_C(-1558544484243762373), INT64_C( -208825673416776047),
                             INT64_C(-6167275479359641892), INT64_C(-4953402399143034204)),
      simde_mm256_set_epi64x(INT64_C(-2858151442766986873), INT64_C( 9028813919053392068),
                             INT64_C( 5083059030774095197), INT64_C(-4558318353343223416)),
      simde_mm256_set_epi64x(INT64_C(-1558544484243762373), INT64_C( -208825673416776047),
                             INT64_C(-1084216448585546695), INT64_C( -395084045799810788)) },
    { simde_mm256_set_epi64x(INT64_C( 3908684742628183808), INT64_C(-2671311551824242866),
                             INT64_C( 2246668589251707300), INT64_C(-8972022555815576273)),
      simde_mm256_set_epi64x(INT64_C( 2129749246616352421), INT64_C( 3930946101587052880),
                             INT64_C( 6109596926925725236), INT64_C(-6515037028970767861)),
      simde_mm256_set_epi64x(INT64_C( 1778935496011831387), INT64_C(-2671311551824242866),
                             INT64_C( 2246668589251707300), INT64_C(-2456985526844808412)) },
    { simde_mm256_set_epi64x(INT64_C( 7540605987113962845), INT64_C(-4511621132930745547),
                             INT64_C(-9091142434838104266), INT64_C( -772363439907339893)),
      simde_mm256_set_epi64x(INT64_C( 5181754748372749246), INT64_C( 2283432752406648940),
                             INT64_C( -621131936186871923), INT64_C( 6205295972918594513)),
      simde_mm256_set_epi64x(INT64_C( 2358851238741213599), INT64_C(-2228188380524096607),
                             INT64_C( -395295328221897344), INT64_C( -772363439907339893)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_rem_epi64(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_rem_epu8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_x_mm256_set_epu8(UINT8_C(191), UINT8_C(167), UINT8_C(226), UINT8_C( 64),
                             UINT8_C(213), UINT8_C(202), UINT8_C(110), UINT8_C(113),
                             UINT8_C( 89), UINT8_C(237), UINT8_C( 70), UINT8_C(226),
                             UINT8_C(132), UINT8_C( 91), UINT8_C(255), UINT8_C( 88),
                             UINT8_C(104), UINT8_C( 42), UINT8_C( 53), UINT8_C(254),
                             UINT8_C(132), UINT8_C(254), UINT8_C( 96), UINT8_C( 75),
                             UINT8_C( 31), UINT8_C(112), UINT8_C(151), UINT8_C(169),
                             UINT8_C(172), UINT8_C( 94), UINT8_C(112), UINT8_C( 90)),
      simde_x_mm256_set_epu8(UINT8_C(121), UINT8_C( 85), UINT8_C(153), UINT8_C(116),
                             UINT8_C(218), UINT8_C( 21), UINT8_C(101), UINT8_C(122),
                             UINT8_C( 10), UINT8_C(231), UINT8_C( 54), UINT8_C( 71),
                             UINT8_C(156), UINT8_C(149), UINT8_C(244), UINT8_C( 84),
                             UINT8_C(148), UINT8_C( 85), UINT8_C(170), UINT8_C(184),
                             UINT8_C( 94), UINT8_C(154), UINT8_C(229), UINT8_C( 11),
                             UINT8_C( 70), UINT8_C(179), UINT8_C(121), UINT8_C(157),
                             UINT8_C(254), UINT8_C( 70), UINT8_C( 49), UINT8_C(125)),
      simde_x_mm256_set_epu8(UINT8_C( 70), UINT8_C( 82), UINT8_C( 73), UINT8_C( 64),
                             UINT8_C(213), UINT8_C( 13), UINT8_C(  9), UINT8_C(113),
                             UINT8_C(  9), UINT8_C(  6), UINT8_C( 16), UINT8_C( 13),
                             UINT8_C(132), UINT8_C( 91), UINT8_C( 11), UINT8_C(  4),
                             UINT8_C(104), UINT8_C( 42), UINT8_C( 53), UINT8_C( 70),
                             UINT8_C( 38), UINT8_C(100), UINT8_C( 96), UINT8_C(  9),
                             UINT8_C( 31), UINT8_C(112), UINT8_C( 30), UINT8_C( 12),
                             UINT8_C(172), UINT8_C( 24), UINT8_C( 14), UINT8_C( 90)) },
    { simde_x_mm256_set_epu8(UINT8_C( 78), UINT8_C( 89), UINT8_C(105), UINT8_C( 98),
                             UINT8_C(178), UINT8_C(173), UINT8_C(134), UINT8_C(199),
                             UINT8_C(211), UINT8_C(243), UINT8_C(161), UINT8_C(220),
                             UINT8_C(171), UINT8_C(107), UINT8_C( 43), UINT8_C(  1),
                             UINT8_C(196), UINT8_C( 36), UINT8_C( 35), UINT8_C( 54),
                             UINT8_C( 94), UINT8_C( 53), UINT8_C(132), UINT8_C(247),
                             UINT8_C(227), UINT8_C(236), UINT8_C( 32), UINT8_C(119),
                             UINT8_C(124), UINT8_C( 15), UINT8_C( 15), UINT8_C(162)),
      simde_x_mm256_set_epu8(UINT8_C(195), UINT8_C( 49), UINT8_C( 14), UINT8_C(170),
                             UINT8_C(203), UINT8_C(167), UINT8_C(  3), UINT8_C(215),
                             UINT8_C( 63), UINT8_C(248), UINT8_C( 55), UINT8_C(219),
                             UINT8_C(221), UINT8_C(135), UINT8_C( 61), UINT8_C(191),
                             UINT8_C(209), UINT8_C( 91), UINT8_C( 87), UINT8_C(137),
                             UINT8_C( 87), UINT8_C( 76), UINT8_C( 44), UINT8_C(140),
                             UINT8_C(  2), UINT8_C(200), UINT8_C( 36), UINT8_C(195),
                             UINT8_C(200), UINT8_C(125), UINT8_C(254), UINT8_C(139)),
      simde_x_mm256_set_epu8(UINT8_C( 78), UINT8_C( 40), UINT8_C(  7), UINT8_C( 98),
                             UINT8_C(178), UINT8_C(  6), UINT8_C(  2), UINT8_C(199),
                             UINT8_C( 22), UINT8_C(243), UINT8_C( 51), UINT8_C(  1),
                             UINT8_C(171), UINT8_C(107), UINT8_C( 43), UINT8_C(  1),
                             UINT8_C(196), UINT8_C( 36), UINT8_C( 35), UINT8_C( 54),
                             UINT8_C(  7), UINT8_C( 53), UINT8_C(  0), UINT8_C(107),
                             UINT8_C(  1), UINT8_C( 36), UINT8_C( 32), UINT8_C(119),
                             UINT8_C(124), UINT8_C( 15), UINT8_C( 15), UINT8_C( 23)) },
    { simde_x_mm256_set_epu8(UINT8_C(234), UINT8_C( 94), UINT8_C(240), UINT8_C( 12),
                             UINT8_C(146), UINT8_C(  1), UINT8_C(147), UINT8_C( 59),
                             UINT8_C(253), UINT8_C( 26), UINT8_C( 26), UINT8_C( 40),
                             UINT8_C( 12), UINT8_C(  2), UINT8_C(230), UINT8_C(145),
                             UINT8_C(170), UINT8_C(105), UINT8_C(111), UINT8_C(160),
                             UINT8_C(140), UINT8_C(202), UINT8_C(166), UINT8_C(220),
                             UINT8_C(187), UINT8_C( 65), UINT8_C(250), UINT8_C(195),
                             UINT8_C( 33), UINT8_C(131), UINT8_C(  2), UINT8_C(164)),
      simde_x_mm256_set_epu8(UINT8_C(177), UINT8_C(221), UINT8_C(251), UINT8_C(181),
                             UINT8_C(159), UINT8_C(182), UINT8_C( 11), UINT8_C( 11),
                             UINT8_C( 39), UINT8_C( 37), UINT8_C( 39), UINT8_C(208),
                             UINT8_C(136), UINT8_C(180), UINT8_C(215), UINT8_C(139),
                             UINT8_C(144), UINT8_C(128), UINT8_C(203), UINT8_C(206),
                             UINT8_C(173), UINT8_C( 36), UINT8_C(133), UINT8_C(175),
                             UINT8_C(231), UINT8_C(  7), UINT8_C(236), UINT8_C( 68),
                             UINT8_C(193), UINT8_C(221), UINT8_C( 27), UINT8_C(  8)),
      simde_x_mm256_set_epu8(UINT8_C( 57), UINT8_C( 94), UINT8_C(240), UINT8_C( 12),
                             UINT8_C(146), UINT8_C(  1), UINT8_C(  4), UINT8_C(  4),
                             UINT8_C( 19), UINT8_C( 26), UINT8_C( 26), UINT8_C( 40),
                             UINT8_C( 12), UINT8_C(  2), UINT8_C( 15), UINT8_C(  6),
                             UINT8_C( 26), UINT8_C(105), UINT8_C(111), UINT8_C(160),
                             UINT8_C(140), UINT8_C( 22), UINT8_C( 33), UINT8_C( 45),
                             UINT8_C(187), UINT8_C(  2), UINT8_C( 14), UINT8_C( 59),
                             UINT8_C( 33), UINT8_C(131), UINT8_C(  2), UINT8_C(  4)) },
    { simde_x_mm256_set_epu8(UINT8_C( 71), UINT8_C(233), UINT8_C( 74), UINT8_C(125),
                             UINT8_C( 81), UINT8_C(243), UINT8_C(139), UINT8_C(190),
                             UINT8_C( 31), UINT8_C(176), UINT8_C( 97), UINT8_C(253),
                             UINT8_C(123), UINT8_C(176), UINT8_C(216), UINT8_C(108),
                             UINT8_C(247), UINT8_C( 97), UINT8_C( 75), UINT8_C(203),
                             UINT8_C(128), UINT8_C(238), UINT8_C( 79), UINT8_C(141),
                             UINT8_C( 86), UINT8_C( 29), UINT8_C(163), UINT8_C(207),
                             UINT8_C(111), UINT8_C(249), UINT8_C(139), UINT8_C(209)),
      simde_x_mm256_set_epu8(UINT8_C(120), UINT8_C(127), UINT8_C( 28), UINT8_C( 95),
                             UINT8_C(175), UINT8_C(223), UINT8_C(119), UINT8_C(214),
                             UINT8_C(220), UINT8_C(102), UINT8_C( 86), UINT8_C( 22),
                             UINT8_C(119), UINT8_C(207), UINT8_C( 12), UINT8_C(183),
                             UINT8_C(172), UINT8_C(242), UINT8_C(173), UINT8_C(249),
                             UINT8_C( 52), UINT8_C(108), UINT8_C(128), UINT8_C(203),
                             UINT8_C( 85), UINT8_C(135), UINT8_C(227), UINT8_C( 35),
                             UINT8_C(187), UINT8_C( 24), UINT8_C(250), UINT8_C(219)),
      simde_x_mm256_set_epu8(UINT8_C( 71), UINT8_C(106), UINT8_C( 18), UINT8_C( 30),
                             UINT8_C( 81), UINT8_C( 20), UINT8_C( 20), UINT8_C(190),
                             UINT8_C( 31), UINT8_C( 74), UINT8_C( 11), UINT8_C( 11),
                             UINT8_C(  4), UINT8_C(176), UINT8_C(  0), UINT8_C(108),
                             UINT8_C( 75), UINT8_C( 97), UINT8_C( 75), UINT8_C(203),
                             UINT8_C( 24), UINT8_C( 22), UINT8_C( 79), UINT8_C(141),
                             UINT8_C(  1), UINT8_C( 29), UINT8_C(163), UINT8_C( 32),
                             UINT8_C(111), UINT8_C(  9), UINT8_C(139), UINT8_C(209)) },
    { simde_x_mm256_set_epu8(UINT8_C(184), UINT8_C( 63), UINT8_C( 95), UINT8_C(164),
                             UINT8_C( 65), UINT8_C( 71), UINT8_C(174), UINT8_C( 88),
                             UINT8_C(183), UINT8_C(142), UINT8_C( 98), UINT8_C( 14),
                             UINT8_C( 25), UINT8_C(173), UINT8_C( 87), UINT8_C(  2),
                             UINT8_C(191), UINT8_C(143), UINT8_C(152), UINT8_C(  2),
                             UINT8_C(126), UINT8_C(  0), UINT8_C(162), UINT8_C( 57),
                             UINT8_C(245), UINT8_C( 36), UINT8_C(239), UINT8_C( 54),
                             UINT8_C( 33), UINT8_C(165), UINT8_C(199), UINT8_C( 84)),
      simde_x_mm256_set_epu8(UINT8_C(174), UINT8_C( 60), UINT8_C(132), UINT8_C(208),
                             UINT8_C( 58), UINT8_C(178), UINT8_C(116), UINT8_C(240),
                             UINT8_C( 37), UINT8_C(131), UINT8_C(100), UINT8_C(177),
                             UINT8_C( 19), UINT8_C(102), UINT8_C( 81), UINT8_C( 86),
                             UINT8_C( 25), UINT8_C( 43), UINT8_C( 51), UINT8_C(140),
                             UINT8_C(  9), UINT8_C( 40), UINT8_C(227), UINT8_C( 75),
                             UINT8_C(208), UINT8_C(159), UINT8_C(175), UINT8_C(109),
                             UINT8_C(230), UINT8_C( 87), UINT8_C(254), UINT8_C(216)),
      simde_x_mm256_set_epu8(UINT8_C( 10), UINT8_C(  3), UINT8_C( 95), UINT8_C(164),
                             UINT8_C(  7), UINT8_C( 71), UINT8_C( 58), UINT8_C( 88),
                             UINT8_C( 35), UINT8_C( 11), UINT8_C( 98), UINT8_C( 14),
                             UINT8_C(  6), UINT8_C( 71), UINT8_C(  6), UINT8_C(  2),
                             UINT8_C( 16), UINT8_C( 14), UINT8_C( 50), UINT8_C(  2),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C(162), UINT8_C( 57),
                             UINT8_C( 37), UINT8_C( 36), UINT8_C( 64), UINT8_C( 54),
                             UINT8_C( 33), UINT8_C( 78), UINT8_C(199), UINT8_C( 84)) },
    { simde_x_mm256_set_epu8(UINT8_C( 54), UINT8_C( 43), UINT8_C(109), UINT8_C(187),
                             UINT8_C(138), UINT8_C( 62), UINT8_C(222), UINT8_C(154),
                             UINT8_C(123), UINT8_C( 21), UINT8_C(247), UINT8_C( 99),
                             UINT8_C( 37), UINT8_C( 48), UINT8_C(116), UINT8_C(233),
                             UINT8_C( 95), UINT8_C(251), UINT8_C(147), UINT8_C(109),
                             UINT8_C(205), UINT8_C(206), UINT8_C( 57), UINT8_C( 17),
                             UINT8_C(121), UINT8_C( 25), UINT8_C(  3), UINT8_C( 55),
                             UINT8_C(178), UINT8_C(129), UINT8_C(149), UINT8_C(207)),
      simde_x_mm256_set_epu8(UINT8_C(131), UINT8_C( 42), UINT8_C(151), UINT8_C(210),
                             UINT8_C( 12), UINT8_C(163), UINT8_C(138), UINT8_C(207),
                             UINT8_C( 43), UINT8_C( 57), UINT8_C( 61), UINT8_C( 62),
                             UINT8_C( 81), UINT8_C(184), UINT8_C(  6), UINT8_C( 93),
                             UINT8_C(167), UINT8_C(  1), UINT8_C(145), UINT8_C(  9),
                             UINT8_C(  4), UINT8_C( 17), UINT8_C( 10), UINT8_C(101),
                             UINT8_C(186), UINT8_C(181), UINT8_C(155), UINT8_C(243),
                             UINT8_C(189), UINT8_C(191), UINT8_C(222), UINT8_C(205)),
      simde_x_mm256_set_epu8(UINT8_C( 54), UINT8_C(  1), UINT8_C(109), UINT8_C(187),
                             UINT8_C(  6), UINT8_C( 62), UINT8_C( 84), UINT8_C(154),
                             UINT8_C( 37), UINT8_C( 21), UINT8_C(  3), UINT8_C( 37),
                             UINT8_C( 37), UINT8_C( 48), UINT8_C(  2), UINT8_C( 47),
                             UINT8_C( 95), UINT8_C(  0), UINT8_C(  2), UINT8_C(  1),
                             UINT8_C(  1), UINT8_C(  2), UINT8_C(  7), UINT8_C( 17),
                             UINT8_C(121), UINT8_C( 25), UINT8_C(  3), UINT8_C( 55),
                             UINT8_C(178), UINT8_C(129), UINT8_C(149), UINT8_C(  2)) },
    { simde_x_mm256_set_epu8(UINT8_C( 23), UINT8_C(132), UINT8_C(106), UINT8_C(109),
                             UINT8_C(135), UINT8_C(203), UINT8_C( 98), UINT8_C(120),
                             UINT8_C(101), UINT8_C( 52), UINT8_C( 82), UINT8_C( 44),
                             UINT8_C(142), UINT8_C( 14), UINT8_C( 99), UINT8_C(245),
                             UINT8_C(  8), UINT8_C(140), UINT8_C(141), UINT8_C(123),
                             UINT8_C(219), UINT8_C(163), UINT8_C(196), UINT8_C(233),
                             UINT8_C( 34), UINT8_C(185), UINT8_C(228), UINT8_C(108),
                             UINT8_C( 95), UINT8_C(236), UINT8_C( 97), UINT8_C( 41)),
      simde_x_mm256_set_epu8(UINT8_C(125), UINT8_C(229), UINT8_C(203), UINT8_C( 45),
                             UINT8_C( 24), UINT8_C(  5), UINT8_C( 90), UINT8_C( 83),
                             UINT8_C(145), UINT8_C( 85), UINT8_C(156), UINT8_C(164),
                             UINT8_C(149), UINT8_C(201), UINT8_C( 48), UINT8_C(255),
                             UINT8_C( 41), UINT8_C( 42), UINT8_C( 94), UINT8_C(129),
                             UINT8_C(135), UINT8_C(  8), UINT8_C( 12), UINT8_C(203),
                             UINT8_C(128), UINT8_C(202), UINT8_C(148), UINT8_C(252),
                             UINT8_C(104), UINT8_C(208), UINT8_C( 98), UINT8_C(162)),
      simde_x_mm256_set_epu8(UINT8_C( 23), UINT8_C(132), UINT8_C(106), UINT8_C( 19),
                             UINT8_C( 15), UINT8_C(  3), UINT8_C(  8), UINT8_C( 37),
                             UINT8_C(101), UINT8_C( 52), UINT8_C( 82), UINT8_C( 44),
                             UINT8_C(142), UINT8_C( 14), UINT8_C(  3), UINT8_C(245),
                             UINT8_C(  8), UINT8_C( 14), UINT8_C( 47), UINT8_C(123),
                             UINT8_C( 84), UINT8_C(  3), UINT8_C(  4), UINT8_C( 30),
                             UINT8_C( 34), UINT8_C(185), UINT8_C( 80), UINT8_C(108),
                             UINT8_C( 95), UINT8_C( 28), UINT8_C( 97), UINT8_C( 41)) },
    { simde_x_mm256_set_epu8(UINT8_C(162), UINT8_C( 31), UINT8_C(168), UINT8_C( 17),
                             UINT8_C( 50), UINT8_C(110), UINT8_C(231), UINT8_C(216),
                             UINT8_C( 94), UINT8_C( 20), UINT8_C(163), UINT8_C(183),
                             UINT8_C(157), UINT8_C( 16), UINT8_C( 91), UINT8_C( 54),
                             UINT8_C( 62), UINT8_C( 81), UINT8_C(159), UINT8_C(151),
                             UINT8_C( 57), UINT8_C( 12), UINT8_C(118), UINT8_C( 33),
                             UINT8_C(180), UINT8_C(139), UINT8_C(  1), UINT8_C(  5),
                             UINT8_C( 78), UINT8_C( 13), UINT8_C( 93), UINT8_C(155)),
      simde_x_mm256_set_epu8(UINT8_C(193), UINT8_C(230), UINT8_C( 93), UINT8_C( 23),
                             UINT8_C(193), UINT8_C( 52), UINT8_C(223), UINT8_C(175),
                             UINT8_C(205), UINT8_C( 45), UINT8_C(166), UINT8_C( 24),
                             UINT8_C( 71), UINT8_C(234), UINT8_C(161), UINT8_C(142),
                             UINT8_C(184), UINT8_C(218), UINT8_C(190), UINT8_C(212),
                             UINT8_C(116), UINT8_C(159), UINT8_C( 44), UINT8_C( 55),
                             UINT8_C(213), UINT8_C(133), UINT8_C( 60), UINT8_C(  3),
                             UINT8_C( 58), UINT8_C(255), UINT8_C(125), UINT8_C(189)),
      simde_x_mm256_set_epu8(UINT8_C(162), UINT8_C( 31), UINT8_C( 75), UINT8_C( 17),
                             UINT8_C( 50), UINT8_C(  6), UINT8_C(  8), UINT8_C( 41),
                             UINT8_C( 94), UINT8_C( 20), UINT8_C(163), UINT8_C( 15),
                             UINT8_C( 15), UINT8_C( 16), UINT8_C( 91), UINT8_C( 54),
                             UINT8_C( 62), UINT8_C( 81), UINT8_C(159), UINT8_C(151),
                             UINT8_C( 57), UINT8_C( 12), UINT8_C( 30), UINT8_C( 33),
                             UINT8_C(180), UINT8_C(  6), UINT8_C(  1), UINT8_C(  2),
                             UINT8_C( 20), UINT8_C( 13), UINT8_C( 93), UINT8_C(155)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_rem_epu8(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_u8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_rem_epu16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_x_mm256_set_epu16(UINT16_C( 49063), UINT16_C( 57920), UINT16_C( 54730), UINT16_C( 28273),
                              UINT16_C( 23021), UINT16_C( 18146), UINT16_C( 33883), UINT16_C( 65368),
                              UINT16_C( 26666), UINT16_C( 13822), UINT16_C( 34046), UINT16_C( 24651),
                              UINT16_C(  8048), UINT16_C( 38825), UINT16_C( 44126), UINT16_C( 28762)),
      simde_x_mm256_set_epu16(UINT16_C( 10545), UINT16_C( 43974), UINT16_C( 10284), UINT16_C( 62003),
                              UINT16_C( 35545), UINT16_C( 55289), UINT16_C( 51493), UINT16_C( 35101),
                              UINT16_C( 59818), UINT16_C( 61822), UINT16_C( 46602), UINT16_C( 53446),
                              UINT16_C( 23938), UINT16_C( 50097), UINT16_C( 48095), UINT16_C( 35837)),
      simde_x_mm256_set_epu16(UINT16_C(  6883), UINT16_C( 13946), UINT16_C(  3310), UINT16_C( 28273),
                              UINT16_C( 23021), UINT16_C( 18146), UINT16_C( 33883), UINT16_C( 30267),
                              UINT16_C( 26666), UINT16_C( 13822), UINT16_C( 34046), UINT16_C( 24651),
                              UINT16_C(  8048), UINT16_C( 38825), UINT16_C( 44126), UINT16_C( 28762)) },
    { simde_x_mm256_set_epu16(UINT16_C( 18192), UINT16_C( 32532), UINT16_C( 33700), UINT16_C( 60373),
                              UINT16_C( 20183), UINT16_C( 64042), UINT16_C(  2502), UINT16_C( 18488),
                              UINT16_C( 22771), UINT16_C( 21470), UINT16_C(  4556), UINT16_C( 26138),
                              UINT16_C( 19085), UINT16_C( 64613), UINT16_C( 55602), UINT16_C( 63371)),
      simde_x_mm256_set_epu16(UINT16_C( 38607), UINT16_C(  8074), UINT16_C( 18000), UINT16_C( 35687),
                              UINT16_C( 40415), UINT16_C(  3254), UINT16_C( 55282), UINT16_C( 38855),
                              UINT16_C( 41330), UINT16_C( 37148), UINT16_C( 25803), UINT16_C( 25877),
                              UINT16_C(   768), UINT16_C( 16244), UINT16_C( 11114), UINT16_C( 58324)),
      simde_x_mm256_set_epu16(UINT16_C( 18192), UINT16_C(   236), UINT16_C( 15700), UINT16_C( 24686),
                              UINT16_C( 20183), UINT16_C(  2216), UINT16_C(  2502), UINT16_C( 18488),
                              UINT16_C( 22771), UINT16_C( 21470), UINT16_C(  4556), UINT16_C(   261),
                              UINT16_C(   653), UINT16_C( 15881), UINT16_C(    32), UINT16_C(  5047)) },
    { simde_x_mm256_set_epu16(UINT16_C(  7525), UINT16_C(  3321), UINT16_C( 47299), UINT16_C( 64213),
                              UINT16_C( 13644), UINT16_C( 48153), UINT16_C( 45234), UINT16_C( 51700),
                              UINT16_C(  7513), UINT16_C(  1114), UINT16_C( 65336), UINT16_C( 10389),
                              UINT16_C( 33688), UINT16_C(  9445), UINT16_C( 60332), UINT16_C( 41466)),
      simde_x_mm256_set_epu16(UINT16_C( 20057), UINT16_C( 26978), UINT16_C( 45741), UINT16_C( 34503),
                              UINT16_C( 54259), UINT16_C( 41436), UINT16_C( 43883), UINT16_C( 11009),
                              UINT16_C( 50212), UINT16_C(  9014), UINT16_C( 24117), UINT16_C( 34039),
                              UINT16_C( 58348), UINT16_C(  8311), UINT16_C( 31759), UINT16_C(  4002)),
      simde_x_mm256_set_epu16(UINT16_C(  7525), UINT16_C(  3321), UINT16_C(  1558), UINT16_C( 29710),
                              UINT16_C( 13644), UINT16_C(  6717), UINT16_C(  1351), UINT16_C(  7664),
                              UINT16_C(  7513), UINT16_C(  1114), UINT16_C( 17102), UINT16_C( 10389),
                              UINT16_C( 33688), UINT16_C(  1134), UINT16_C( 28573), UINT16_C(  1446)) },
    { simde_x_mm256_set_epu16(UINT16_C( 26094), UINT16_C( 52354), UINT16_C( 30122), UINT16_C( 47688),
                              UINT16_C( 43801), UINT16_C( 57764), UINT16_C(  1809), UINT16_C( 33603),
                              UINT16_C(  8271), UINT16_C(  4936), UINT16_C(  7627), UINT16_C( 20477),
                              UINT16_C( 14608), UINT16_C( 25470), UINT16_C( 45836), UINT16_C( 25611)),
      simde_x_mm256_set_epu16(UINT16_C( 48157), UINT16_C( 56913), UINT16_C( 55050), UINT16_C( 48859),
                              UINT16_C( 27895), UINT16_C( 48343), UINT16_C( 59593), UINT16_C( 60425),
                              UINT16_C( 62587), UINT16_C( 54231), UINT16_C( 52444), UINT16_C(  8140),
                              UINT16_C( 58695), UINT16_C(  2476), UINT16_C( 41101), UINT16_C(  7948)),
      simde_x_mm256_set_epu16(UINT16_C( 26094), UINT16_C( 52354), UINT16_C( 30122), UINT16_C( 47688),
                              UINT16_C( 15906), UINT16_C(  9421), UINT16_C(  1809), UINT16_C( 33603),
                              UINT16_C(  8271), UINT16_C(  4936), UINT16_C(  7627), UINT16_C(  4197),
                              UINT16_C( 14608), UINT16_C(   710), UINT16_C(  4735), UINT16_C(  1767)) },
    { simde_x_mm256_set_epu16(UINT16_C( 26466), UINT16_C( 21183), UINT16_C(  5811), UINT16_C( 17016),
                              UINT16_C( 51162), UINT16_C( 46775), UINT16_C( 54252), UINT16_C( 64603),
                              UINT16_C( 30444), UINT16_C( 20573), UINT16_C( 50572), UINT16_C( 25607),
                              UINT16_C( 36721), UINT16_C( 36797), UINT16_C( 27147), UINT16_C( 62271)),
      simde_x_mm256_set_epu16(UINT16_C( 26902), UINT16_C( 51011), UINT16_C( 57631), UINT16_C( 57521),
                              UINT16_C( 43405), UINT16_C( 18318), UINT16_C( 44023), UINT16_C(  9770),
                              UINT16_C(  4118), UINT16_C( 33099), UINT16_C(  6621), UINT16_C( 57639),
                              UINT16_C( 22002), UINT16_C( 33155), UINT16_C( 15537), UINT16_C( 38743)),
      simde_x_mm256_set_epu16(UINT16_C( 26466), UINT16_C( 21183), UINT16_C(  5811), UINT16_C( 17016),
                              UINT16_C(  7757), UINT16_C( 10139), UINT16_C( 10229), UINT16_C(  5983),
                              UINT16_C(  1618), UINT16_C( 20573), UINT16_C(  4225), UINT16_C( 25607),
                              UINT16_C( 14719), UINT16_C(  3642), UINT16_C( 11610), UINT16_C( 23528)) },
    { simde_x_mm256_set_epu16(UINT16_C( 59998), UINT16_C( 61452), UINT16_C( 37377), UINT16_C( 37691),
                              UINT16_C( 64794), UINT16_C(  6696), UINT16_C(  3074), UINT16_C( 59025),
                              UINT16_C( 43625), UINT16_C( 28576), UINT16_C( 36042), UINT16_C( 42716),
                              UINT16_C( 47937), UINT16_C( 64195), UINT16_C(  8579), UINT16_C(   676)),
      simde_x_mm256_set_epu16(UINT16_C( 55381), UINT16_C( 52839), UINT16_C( 60314), UINT16_C( 33159),
                              UINT16_C( 32076), UINT16_C( 51820), UINT16_C( 13383), UINT16_C( 43204),
                              UINT16_C( 18058), UINT16_C( 42817), UINT16_C( 56737), UINT16_C( 40285),
                              UINT16_C( 49341), UINT16_C( 39323), UINT16_C( 53205), UINT16_C( 27016)),
      simde_x_mm256_set_epu16(UINT16_C(  4617), UINT16_C(  8613), UINT16_C( 37377), UINT16_C(  4532),
                              UINT16_C(   642), UINT16_C(  6696), UINT16_C(  3074), UINT16_C( 15821),
                              UINT16_C(  7509), UINT16_C( 28576), UINT16_C( 36042), UINT16_C(  2431),
                              UINT16_C( 47937), UINT16_C( 24872), UINT16_C(  8579), UINT16_C(   676)) },
    { simde_x_mm256_set_epu16(UINT16_C( 13886), UINT16_C( 28688), UINT16_C( 30551), UINT16_C( 36608),
                              UINT16_C( 56045), UINT16_C( 38987), UINT16_C( 64798), UINT16_C( 22350),
                              UINT16_C(  7981), UINT16_C( 50477), UINT16_C( 46688), UINT16_C( 16804),
                              UINT16_C( 33660), UINT16_C( 63749), UINT16_C( 29649), UINT16_C( 64815)),
      simde_x_mm256_set_epu16(UINT16_C(  7566), UINT16_C( 25511), UINT16_C( 59705), UINT16_C( 13989),
                              UINT16_C( 13965), UINT16_C( 34471), UINT16_C(    77), UINT16_C( 35152),
                              UINT16_C( 21705), UINT16_C( 42504), UINT16_C( 63033), UINT16_C( 56884),
                              UINT16_C( 42389), UINT16_C( 61527), UINT16_C(  7598), UINT16_C( 23051)),
      simde_x_mm256_set_epu16(UINT16_C(  6320), UINT16_C(  3177), UINT16_C( 30551), UINT16_C(  8630),
                              UINT16_C(   185), UINT16_C(  4516), UINT16_C(    41), UINT16_C( 22350),
                              UINT16_C(  7981), UINT16_C(  7973), UINT16_C( 46688), UINT16_C( 16804),
                              UINT16_C( 33660), UINT16_C(  2222), UINT16_C(  6855), UINT16_C( 18713)) },
    { simde_x_mm256_set_epu16(UINT16_C( 26789), UINT16_C( 40241), UINT16_C( 34076), UINT16_C( 36189),
                              UINT16_C( 49507), UINT16_C( 32891), UINT16_C( 45700), UINT16_C( 31541),
                              UINT16_C( 33237), UINT16_C( 50719), UINT16_C( 22782), UINT16_C( 46902),
                              UINT16_C( 62792), UINT16_C(   907), UINT16_C(  9939), UINT16_C(   395)),
      simde_x_mm256_set_epu16(UINT16_C( 18409), UINT16_C( 19069), UINT16_C( 20979), UINT16_C( 35774),
                              UINT16_C(  8112), UINT16_C( 25085), UINT16_C( 31664), UINT16_C( 55404),
                              UINT16_C( 63329), UINT16_C( 19403), UINT16_C( 33006), UINT16_C( 20365),
                              UINT16_C( 22045), UINT16_C( 41935), UINT16_C( 28665), UINT16_C( 35793)),
      simde_x_mm256_set_epu16(UINT16_C(  8380), UINT16_C(  2103), UINT16_C( 13097), UINT16_C(   415),
                              UINT16_C(   835), UINT16_C(  7806), UINT16_C( 14036), UINT16_C( 31541),
                              UINT16_C( 33237), UINT16_C( 11913), UINT16_C( 22782), UINT16_C(  6172),
                              UINT16_C( 18702), UINT16_C(   907), UINT16_C(  9939), UINT16_C(   395)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_rem_epu16(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_u16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_rem_epu32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_x_mm256_set_epu32(UINT32_C(3215450688), UINT32_C(3586813553), UINT32_C(1508722402), UINT32_C(2220621656),
                              UINT32_C(1747596798), UINT32_C(2231263307), UINT32_C( 527472553), UINT32_C(2891870298)),
      simde_x_mm256_set_epu32(UINT32_C( 691121094), UINT32_C( 674034227), UINT32_C(2329532409), UINT32_C(3374680349),
                              UINT32_C(3920294270), UINT32_C(3054162118), UINT32_C(1568850865), UINT32_C(3151989757)),
      simde_x_mm256_set_epu32(UINT32_C( 450966312), UINT32_C( 216642418), UINT32_C(1508722402), UINT32_C(2220621656),
                              UINT32_C(1747596798), UINT32_C(2231263307), UINT32_C( 527472553), UINT32_C(2891870298)) },
    { simde_x_mm256_set_epu32(UINT32_C(1192263444), UINT32_C(2208623573), UINT32_C(1322777130), UINT32_C( 163989560),
                              UINT32_C(1492341726), UINT32_C( 298608154), UINT32_C(1250819173), UINT32_C(3643996043)),
      simde_x_mm256_set_epu32(UINT32_C(2530156426), UINT32_C(1179683687), UINT32_C(2648640694), UINT32_C(3623000007),
                              UINT32_C(2708640028), UINT32_C(1691051285), UINT32_C(  50347892), UINT32_C( 728425428)),
      simde_x_mm256_set_epu32(UINT32_C(1192263444), UINT32_C(1028939886), UINT32_C(1322777130), UINT32_C( 163989560),
                              UINT32_C(1492341726), UINT32_C( 298608154), UINT32_C(  42469765), UINT32_C(   1868903)) },
    { simde_x_mm256_set_epu32(UINT32_C( 493161721), UINT32_C(3099851477), UINT32_C( 894221337), UINT32_C(2964507124),
                              UINT32_C( 492373082), UINT32_C(4281870485), UINT32_C(2207786213), UINT32_C(3953959418)),
      simde_x_mm256_set_epu32(UINT32_C(1314482530), UINT32_C(2997716679), UINT32_C(3555959260), UINT32_C(2875927297),
                              UINT32_C(3290702646), UINT32_C(1580565751), UINT32_C(3823902839), UINT32_C(2081361826)),
      simde_x_mm256_set_epu32(UINT32_C( 493161721), UINT32_C( 102134798), UINT32_C( 894221337), UINT32_C(  88579827),
                              UINT32_C( 492373082), UINT32_C(1120738983), UINT32_C(2207786213), UINT32_C(1872597592)) },
    { simde_x_mm256_set_epu32(UINT32_C(1710148738), UINT32_C(1974123080), UINT32_C(2870600100), UINT32_C( 118588227),
                              UINT32_C( 542053192), UINT32_C( 499863549), UINT32_C( 957375358), UINT32_C(3003933707)),
      simde_x_mm256_set_epu32(UINT32_C(3156074065), UINT32_C(3607805659), UINT32_C(1828175063), UINT32_C(3905547273),
                              UINT32_C(4101755863), UINT32_C(3436978124), UINT32_C(3846637996), UINT32_C(2693603084)),
      simde_x_mm256_set_epu32(UINT32_C(1710148738), UINT32_C(1974123080), UINT32_C(1042425037), UINT32_C( 118588227),
                              UINT32_C( 542053192), UINT32_C( 499863549), UINT32_C( 957375358), UINT32_C( 310330623)) },
    { simde_x_mm256_set_epu32(UINT32_C(1734496959), UINT32_C( 380846712), UINT32_C(3352999607), UINT32_C(3555523675),
                              UINT32_C(1995198557), UINT32_C(3314312199), UINT32_C(2406584253), UINT32_C(1779168063)),
      simde_x_mm256_set_epu32(UINT32_C(1763100483), UINT32_C(3776962737), UINT32_C(2844608398), UINT32_C(2885101098),
                              UINT32_C( 269910347), UINT32_C( 433971495), UINT32_C(1441956227), UINT32_C(1018271575)),
      simde_x_mm256_set_epu32(UINT32_C(1734496959), UINT32_C( 380846712), UINT32_C( 508391209), UINT32_C( 670422577),
                              UINT32_C( 105826128), UINT32_C( 276511734), UINT32_C( 964628026), UINT32_C( 760896488)) },
    { simde_x_mm256_set_epu32(UINT32_C(3932090380), UINT32_C(2449576763), UINT32_C(4246346280), UINT32_C( 201516689),
                              UINT32_C(2859036576), UINT32_C(2362091228), UINT32_C(3141663427), UINT32_C( 562234020)),
      simde_x_mm256_set_epu32(UINT32_C(3629502055), UINT32_C(3952771463), UINT32_C(2102184556), UINT32_C( 877111492),
                              UINT32_C(1183491905), UINT32_C(3718356317), UINT32_C(3233651099), UINT32_C(3486869896)),
      simde_x_mm256_set_epu32(UINT32_C( 302588325), UINT32_C(2449576763), UINT32_C(  41977168), UINT32_C( 201516689),
                              UINT32_C( 492052766), UINT32_C(2362091228), UINT32_C(3141663427), UINT32_C( 562234020)) },
    { simde_x_mm256_set_epu32(UINT32_C( 910061584), UINT32_C(2002226944), UINT32_C(3673004107), UINT32_C(4246624078),
                              UINT32_C( 523093293), UINT32_C(3059761572), UINT32_C(2206005509), UINT32_C(1943141679)),
      simde_x_mm256_set_epu32(UINT32_C( 495870887), UINT32_C(3912840869), UINT32_C( 915244711), UINT32_C(   5081424),
                              UINT32_C(1422501384), UINT32_C(4130987572), UINT32_C(2778067031), UINT32_C( 497965579)),
      simde_x_mm256_set_epu32(UINT32_C( 414190697), UINT32_C(2002226944), UINT32_C(  12025263), UINT32_C(   3635038),
                              UINT32_C( 523093293), UINT32_C(3059761572), UINT32_C(2206005509), UINT32_C( 449244942)) },
    { simde_x_mm256_set_epu32(UINT32_C(1755684145), UINT32_C(2233240925), UINT32_C(3244523643), UINT32_C(2995026741),
                              UINT32_C(2178270751), UINT32_C(1493088054), UINT32_C(4115137419), UINT32_C( 651362699)),
      simde_x_mm256_set_epu32(UINT32_C(1206471293), UINT32_C(1374915518), UINT32_C( 531653117), UINT32_C(2075187308),
                              UINT32_C(4150348747), UINT32_C(2163101581), UINT32_C(1444783055), UINT32_C(1878625233)),
      simde_x_mm256_set_epu32(UINT32_C( 549212852), UINT32_C( 858325407), UINT32_C(  54604941), UINT32_C( 919839433),
                              UINT32_C(2178270751), UINT32_C(1493088054), UINT32_C(1225571309), UINT32_C( 651362699)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_rem_epu32(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_u32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_mask_rem_epu32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512i src;
    simde__mmask16 k;
    simde__m512i a;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {
    { simde_x_mm512_set_epu32(UINT32_C( 691121094), UINT32_C( 674034227), UINT32_C(2329532409), UINT32_C(3374680349),
                              UINT32_C(3920294270), UINT32_C(3054162118), UINT32_C(1568850865), UINT32_C(3151989757),
                              UINT32_C(3215450688), UINT32_C(3586813553), UINT32_C(1508722402), UINT32_C(2220621656),
                              UINT32_C(1747596798), UINT32_C(2231263307), UINT32_C( 527472553), UINT32_C(2891870298)),
      UINT16_C(63371),
      simde_x_mm512_set_epu32(UINT32_C(3953959418), UINT32_C(2530156426), UINT32_C(1179683687), UINT32_C(2648640694),
                              UINT32_C(3623000007), UINT32_C(2708640028), UINT32_C(1691051285), UINT32_C(  50347892),
                              UINT32_C( 728425428), UINT32_C(1192263444), UINT32_C(2208623573), UINT32_C(1322777130),
                              UINT32_C( 163989560), UINT32_C(1492341726), UINT32_C( 298608154), UINT32_C(1250819173)),
      simde_x_mm512_set_epu32(UINT32_C(3003933707), UINT32_C(1314482530), UINT32_C(2997716679), UINT32_C(3555959260),
                              UINT32_C(2875927297), UINT32_C(3290702646), UINT32_C(1580565751), UINT32_C(3823902839),
                              UINT32_C(2081361826), UINT32_C( 493161721), UINT32_C(3099851477), UINT32_C( 894221337),
                              UINT32_C(2964507124), UINT32_C( 492373082), UINT32_C(4281870485), UINT32_C(2207786213)),
      simde_x_mm512_set_epu32(UINT32_C( 950025711), UINT32_C(1215673896), UINT32_C(1179683687), UINT32_C(2648640694),
                              UINT32_C(3920294270), UINT32_C(2708640028), UINT32_C( 110485534), UINT32_C(  50347892),
                              UINT32_C( 728425428), UINT32_C(3586813553), UINT32_C(1508722402), UINT32_C(2220621656),
                              UINT32_C( 163989560), UINT32_C(2231263307), UINT32_C( 298608154), UINT32_C(1250819173)) },
    { simde_x_mm512_set_epu32(UINT32_C(1779168063), UINT32_C(3156074065), UINT32_C(3607805659), UINT32_C(1828175063),
                              UINT32_C(3905547273), UINT32_C(4101755863), UINT32_C(3436978124), UINT32_C(3846637996),
                              UINT32_C(2693603084), UINT32_C(1710148738), UINT32_C(1974123080), UINT32_C(2870600100),
                              UINT32_C( 118588227), UINT32_C( 542053192), UINT32_C( 499863549), UINT32_C( 957375358)),
      UINT16_C(36797),
      simde_x_mm512_set_epu32(UINT32_C(3141663427), UINT32_C( 562234020), UINT32_C(1763100483), UINT32_C(3776962737),
                              UINT32_C(2844608398), UINT32_C(2885101098), UINT32_C( 269910347), UINT32_C( 433971495),
                              UINT32_C(1441956227), UINT32_C(1018271575), UINT32_C(1734496959), UINT32_C( 380846712),
                              UINT32_C(3352999607), UINT32_C(3555523675), UINT32_C(1995198557), UINT32_C(3314312199)),
      simde_x_mm512_set_epu32(UINT32_C(2206005509), UINT32_C(1943141679), UINT32_C(3629502055), UINT32_C(3952771463),
                              UINT32_C(2102184556), UINT32_C( 877111492), UINT32_C(1183491905), UINT32_C(3718356317),
                              UINT32_C(3233651099), UINT32_C(3486869896), UINT32_C(3932090380), UINT32_C(2449576763),
                              UINT32_C(4246346280), UINT32_C( 201516689), UINT32_C(2859036576), UINT32_C(2362091228)),
      simde_x_mm512_set_epu32(UINT32_C( 935657918), UINT32_C(3156074065), UINT32_C(3607805659), UINT32_C(1828175063),
                              UINT32_C( 742423842), UINT32_C( 253766622), UINT32_C( 269910347), UINT32_C( 433971495),
                              UINT32_C(1441956227), UINT32_C(1710148738), UINT32_C(1734496959), UINT32_C( 380846712),
                              UINT32_C(3352999607), UINT32_C( 129739962), UINT32_C( 499863549), UINT32_C( 952220971)) },
    { simde_x_mm512_set_epu32(UINT32_C(4115137419), UINT32_C( 651362699), UINT32_C( 495870887), UINT32_C(3912840869),
                              UINT32_C( 915244711), UINT32_C(   5081424), UINT32_C(1422501384), UINT32_C(4130987572),
                              UINT32_C(2778067031), UINT32_C( 497965579), UINT32_C( 910061584), UINT32_C(2002226944),
                              UINT32_C(3673004107), UINT32_C(4246624078), UINT32_C( 523093293), UINT32_C(3059761572)),
      UINT16_C(46902),
      simde_x_mm512_set_epu32(UINT32_C(4074346392), UINT32_C(1398655610), UINT32_C(1722520923), UINT32_C(1206471293),
                              UINT32_C(1374915518), UINT32_C( 531653117), UINT32_C(2075187308), UINT32_C(4150348747),
                              UINT32_C(2163101581), UINT32_C(1444783055), UINT32_C(1878625233), UINT32_C(1755684145),
                              UINT32_C(2233240925), UINT32_C(3244523643), UINT32_C(2995026741), UINT32_C(2178270751)),
      simde_x_mm512_set_epu32(UINT32_C(3188873807), UINT32_C(1982658188), UINT32_C( 863153207), UINT32_C(2657690668),
                              UINT32_C( 448681074), UINT32_C(1334667053), UINT32_C( 502667641), UINT32_C( 855395764),
                              UINT32_C(2622874348), UINT32_C( 808531712), UINT32_C( 454488139), UINT32_C( 123547093),
                              UINT32_C( 483090439), UINT32_C(3168637539), UINT32_C(3093747107), UINT32_C(4158916667)),
      simde_x_mm512_set_epu32(UINT32_C( 885472585), UINT32_C( 651362699), UINT32_C( 859367716), UINT32_C(1206471293),
                              UINT32_C( 915244711), UINT32_C( 531653117), UINT32_C(  64516744), UINT32_C( 728765691),
                              UINT32_C(2778067031), UINT32_C( 497965579), UINT32_C(  60672677), UINT32_C(  26024843),
                              UINT32_C(3673004107), UINT32_C(  75886104), UINT32_C(2995026741), UINT32_C(3059761572)) },
    { simde_x_mm512_set_epu32(UINT32_C(2113970745), UINT32_C(4112838454), UINT32_C( 564512596), UINT32_C( 604721400),
                              UINT32_C(1471174399), UINT32_C(2491026588), UINT32_C(2529574367), UINT32_C( 298473775),
                              UINT32_C(2890366559), UINT32_C(3063632375), UINT32_C(4055983958), UINT32_C(4149169500),
                              UINT32_C(4113948134), UINT32_C(2384487126), UINT32_C(2434207126), UINT32_C(3923111671)),
      UINT16_C(38914),
      simde_x_mm512_set_epu32(UINT32_C(1533151625), UINT32_C(2122196136), UINT32_C(1690360675), UINT32_C(1484935627),
                              UINT32_C(1463758672), UINT32_C( 602211615), UINT32_C(3830002991), UINT32_C(2864741101),
                              UINT32_C( 797104998), UINT32_C(2737423319), UINT32_C(3342229886), UINT32_C( 178625368),
                              UINT32_C(3091160996), UINT32_C(1095216728), UINT32_C(3079561742), UINT32_C( 430790402)),
      simde_x_mm512_set_epu32(UINT32_C(4043825594), UINT32_C(1274901810), UINT32_C( 413860084), UINT32_C( 550494320),
                              UINT32_C(1997049765), UINT32_C( 505563651), UINT32_C( 463125220), UINT32_C(3843753777),
                              UINT32_C(2346173843), UINT32_C(2157864934), UINT32_C(2591157969), UINT32_C( 389679318),
                              UINT32_C(3939775129), UINT32_C(2493364907), UINT32_C(2006619059), UINT32_C(3391409164)),
      simde_x_mm512_set_epu32(UINT32_C(1533151625), UINT32_C(4112838454), UINT32_C( 564512596), UINT32_C( 383946987),
                              UINT32_C(1463758672), UINT32_C(2491026588), UINT32_C(2529574367), UINT32_C( 298473775),
                              UINT32_C(2890366559), UINT32_C(3063632375), UINT32_C(4055983958), UINT32_C(4149169500),
                              UINT32_C(4113948134), UINT32_C(2384487126), UINT32_C(1072942683), UINT32_C(3923111671)) },
    { simde_x_mm512_set_epu32(UINT32_C(1572579389), UINT32_C(3511888959), UINT32_C(2399346014), UINT32_C(1967093325),
                              UINT32_C( 908815803), UINT32_C(2319376026), UINT32_C(2065037155), UINT32_C( 623932649),
                              UINT32_C(1610322797), UINT32_C(3452844305), UINT32_C(2031682359), UINT32_C(2994836943),
                              UINT32_C(2344919086), UINT32_C( 238137788), UINT32_C(1978166020), UINT32_C(  76768592)),
      UINT16_C(  883),
      simde_x_mm512_set_epu32(UINT32_C(3284847806), UINT32_C(3884897233), UINT32_C(2094036024), UINT32_C(2456834182),
                              UINT32_C(  69201629), UINT32_C(1228958503), UINT32_C(3519587969), UINT32_C(2809504529),
                              UINT32_C(3115789449), UINT32_C(1767270276), UINT32_C( 490610321), UINT32_C(1164436618),
                              UINT32_C(2374669797), UINT32_C(3604002618), UINT32_C(3414719029), UINT32_C(2289333019)),
      simde_x_mm512_set_epu32(UINT32_C(2383307765), UINT32_C( 143428987), UINT32_C(3684943081), UINT32_C( 582607980),
                              UINT32_C(1609326889), UINT32_C(1245407235), UINT32_C(4175005098), UINT32_C(2362914327),
                              UINT32_C(2924553042), UINT32_C(2369006988), UINT32_C(2119408419), UINT32_C(3091878410),
                              UINT32_C(3978436943), UINT32_C(1708684203), UINT32_C(1202455481), UINT32_C(2187745469)),
      simde_x_mm512_set_epu32(UINT32_C(1572579389), UINT32_C(3511888959), UINT32_C(2399346014), UINT32_C(1967093325),
                              UINT32_C( 908815803), UINT32_C(2319376026), UINT32_C(3519587969), UINT32_C( 446590202),
                              UINT32_C(1610322797), UINT32_C(1767270276), UINT32_C( 490610321), UINT32_C(1164436618),
                              UINT32_C(2344919086), UINT32_C( 238137788), UINT32_C(1009808067), UINT32_C( 101587550)) },
    { simde_x_mm512_set_epu32(UINT32_C(2117071873), UINT32_C(2857077767), UINT32_C(3918893192), UINT32_C(1087893388),
                              UINT32_C(3851784011), UINT32_C(3914271744), UINT32_C( 565328458), UINT32_C(4201942548),
                              UINT32_C(1480532604), UINT32_C(4197506536), UINT32_C(3712719696), UINT32_C(3920217826),
                              UINT32_C(1394313506), UINT32_C( 394553965), UINT32_C(2278253176), UINT32_C(1697927724)),
      UINT16_C(12254),
      simde_x_mm512_set_epu32(UINT32_C(  56443211), UINT32_C(2258452653), UINT32_C(3784696472), UINT32_C(1139427205),
                              UINT32_C(1090384090), UINT32_C(2389735891), UINT32_C(2215607313), UINT32_C(3817672405),
                              UINT32_C(3621770268), UINT32_C(2071747620), UINT32_C(3852178197), UINT32_C(3693632585),
                              UINT32_C( 319530416), UINT32_C(2179954815), UINT32_C(3793236393), UINT32_C( 340519338)),
      simde_x_mm512_set_epu32(UINT32_C(1219537084), UINT32_C(1349635715), UINT32_C( 732887738), UINT32_C(2566325375),
                              UINT32_C(2906533885), UINT32_C(1765754685), UINT32_C(2719983633), UINT32_C( 846129112),
                              UINT32_C(1578410935), UINT32_C(2635094838), UINT32_C(1045536663), UINT32_C( 957117985),
                              UINT32_C(3029008645), UINT32_C(1309498779), UINT32_C(3293951997), UINT32_C(1022360677)),
      simde_x_mm512_set_epu32(UINT32_C(2117071873), UINT32_C(2857077767), UINT32_C( 120257782), UINT32_C(1087893388),
                              UINT32_C(1090384090), UINT32_C( 623981206), UINT32_C(2215607313), UINT32_C( 433155957),
                              UINT32_C( 464948398), UINT32_C(2071747620), UINT32_C(3712719696), UINT32_C( 822278630),
                              UINT32_C( 319530416), UINT32_C( 870456036), UINT32_C( 499284396), UINT32_C(1697927724)) },
    { simde_x_mm512_set_epu32(UINT32_C(3990081318), UINT32_C( 991545752), UINT32_C(4151932359), UINT32_C( 843112042),
                              UINT32_C(4067412513), UINT32_C(2124182542), UINT32_C(2768721208), UINT32_C(2302989914),
                              UINT32_C(1224533822), UINT32_C(3475606100), UINT32_C(3610957044), UINT32_C(2556046111),
                              UINT32_C(3035396524), UINT32_C(3603101367), UINT32_C(3321443925), UINT32_C(  45581573)),
      UINT16_C(42669),
      simde_x_mm512_set_epu32(UINT32_C(4138167693), UINT32_C(3221954957), UINT32_C(2164435171), UINT32_C( 397240391),
                              UINT32_C( 200936922), UINT32_C(3263986987), UINT32_C(2536604122), UINT32_C(3629380929),
                              UINT32_C( 453331046), UINT32_C(1704580573), UINT32_C(1606190487), UINT32_C(3209309249),
                              UINT32_C(2959497652), UINT32_C(3926896735), UINT32_C(2875407663), UINT32_C(2069966669)),
      simde_x_mm512_set_epu32(UINT32_C(1379668640), UINT32_C(  66581512), UINT32_C(3737665499), UINT32_C( 304428974),
                              UINT32_C(2686704508), UINT32_C( 532978979), UINT32_C( 946958552), UINT32_C(2383642627),
                              UINT32_C(2176874140), UINT32_C( 283691898), UINT32_C(3848894665), UINT32_C(3836186002),
                              UINT32_C(1951055651), UINT32_C( 765387914), UINT32_C( 822559116), UINT32_C(   7445617)),
      simde_x_mm512_set_epu32(UINT32_C(1378830413), UINT32_C( 991545752), UINT32_C(2164435171), UINT32_C( 843112042),
                              UINT32_C(4067412513), UINT32_C(  66113113), UINT32_C( 642687018), UINT32_C(2302989914),
                              UINT32_C( 453331046), UINT32_C(3475606100), UINT32_C(1606190487), UINT32_C(2556046111),
                              UINT32_C(1008442001), UINT32_C(  99957165), UINT32_C(3321443925), UINT32_C(     85143)) },
    { simde_x_mm512_set_epu32(UINT32_C(2313028370), UINT32_C( 869237081), UINT32_C(4104913762), UINT32_C(2825691966),
                              UINT32_C(3577866502), UINT32_C(2991894408), UINT32_C(2172048625), UINT32_C(1617119933),
                              UINT32_C(1521363431), UINT32_C( 553638116), UINT32_C(1036201367), UINT32_C(3107033445),
                              UINT32_C(3882811410), UINT32_C(3534384353), UINT32_C(3871215839), UINT32_C(1273589632)),
      UINT16_C(35103),
      simde_x_mm512_set_epu32(UINT32_C(2458371652), UINT32_C( 260676470), UINT32_C(1724614860), UINT32_C(4150452663),
                              UINT32_C(3816336716), UINT32_C(2208212235), UINT32_C( 932145867), UINT32_C(2432594561),
                              UINT32_C(1756892633), UINT32_C( 382632965), UINT32_C(1295078740), UINT32_C(3299165262),
                              UINT32_C( 152308919), UINT32_C(3943411788), UINT32_C(  31813624), UINT32_C( 807463845)),
      simde_x_mm512_set_epu32(UINT32_C( 615301803), UINT32_C( 382786341), UINT32_C(1852603705), UINT32_C(1998007730),
                              UINT32_C( 231325888), UINT32_C(1842039329), UINT32_C( 968682756), UINT32_C( 316335394),
                              UINT32_C(2223585202), UINT32_C(3491781959), UINT32_C(2167971796), UINT32_C(1587647099),
                              UINT32_C(2966608712), UINT32_C( 320339033), UINT32_C( 282380179), UINT32_C(4186865204)),
      simde_x_mm512_set_epu32(UINT32_C( 612466243), UINT32_C( 869237081), UINT32_C(4104913762), UINT32_C(2825691966),
                              UINT32_C( 115122508), UINT32_C(2991894408), UINT32_C(2172048625), UINT32_C( 218246803),
                              UINT32_C(1521363431), UINT32_C( 553638116), UINT32_C(1036201367), UINT32_C( 123871064),
                              UINT32_C( 152308919), UINT32_C(  99343392), UINT32_C(  31813624), UINT32_C( 807463845)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_mask_rem_epu32(test_vec[i].src, test_vec[i].k, test_vec[i].a, test_vec[i].b);
    simde_assert_m512i_u32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_rem_epu64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_x_mm256_set_epu64x(UINT64_C(13810255550447513201), UINT64_C( 6479913377553186648),
                               UINT64_C( 7505871096235581515), UINT64_C( 2265477367564496986)),
      simde_x_mm256_set_epu64x(UINT64_C( 2968342496979776051), UINT64_C(10005265515001776413),
                               UINT64_C(16837535683400356038), UINT64_C( 6738163160628300797)),
      simde_x_mm256_set_epu64x(UINT64_C( 1936885562528408997), UINT64_C( 6479913377553186648),
                               UINT64_C( 7505871096235581515), UINT64_C( 2265477367564496986)) },
    { simde_x_mm256_set_epu64x(UINT64_C( 5120732502404950997), UINT64_C( 5681284513410730040),
                               UINT64_C( 6409558907924801050), UINT64_C( 5372227444888762251)),
      simde_x_mm256_set_epu64x(UINT64_C(10866939104613927783), UINT64_C(11375825163207743431),
                               UINT64_C(11633520338587575573), UINT64_C(  216242550290965460)),
      simde_x_mm256_set_epu64x(UINT64_C( 5120732502404950997), UINT64_C( 5681284513410730040),
                               UINT64_C( 6409558907924801050), UINT64_C(  182406237905591211)) },
    { simde_x_mm256_set_epu64x(UINT64_C( 2118113466433927893), UINT64_C( 3840651400764901876),
                               UINT64_C( 2114726288902596757), UINT64_C( 9482369585348649466)),
      simde_x_mm256_set_epu64x(UINT64_C( 5645659480511055559), UINT64_C(15272728730484288257),
                               UINT64_C(14133460247011230967), UINT64_C(16423537638667915170)),
      simde_x_mm256_set_epu64x(UINT64_C( 2118113466433927893), UINT64_C( 3840651400764901876),
                               UINT64_C( 2114726288902596757), UINT64_C( 9482369585348649466)) },
    { simde_x_mm256_set_epu64x(UINT64_C( 7345032902979795528), UINT64_C(12329133549512917827),
                               UINT64_C( 2328100732832272381), UINT64_C( 4111895855610225675)),
      simde_x_mm256_set_epu64x(UINT64_C(13555234896536583899), UINT64_C( 7851952110853286921),
                               UINT64_C(17616907291198234572), UINT64_C(16521184395064581900)),
      simde_x_mm256_set_epu64x(UINT64_C( 7345032902979795528), UINT64_C( 4477181438659630906),
                               UINT64_C( 2328100732832272381), UINT64_C( 4111895855610225675)) },
    { simde_x_mm256_set_epu64x(UINT64_C( 7449607714297299576), UINT64_C(14401023659121376347),
                               UINT64_C( 8569312554655704071), UINT64_C(10336200663482757951)),
      simde_x_mm256_set_epu64x(UINT64_C( 7572458917823766705), UINT64_C(12217500042222052906),
                               UINT64_C( 1159256113650983207), UINT64_C( 6193154838246823767)),
      simde_x_mm256_set_epu64x(UINT64_C( 7449607714297299576), UINT64_C( 2183523616899323441),
                               UINT64_C(  454519759098821622), UINT64_C( 4143045825235934184)) },
    { simde_x_mm256_set_epu64x(UINT64_C(16888199589465789243), UINT64_C(18237918400292775569),
                               UINT64_C(12279468594349909724), UINT64_C(13493341674566517412)),
      simde_x_mm256_set_epu64x(UINT64_C(15588592630942564743), UINT64_C( 9028813919053392068),
                               UINT64_C( 5083059030774095197), UINT64_C(13888425720366328200)),
      simde_x_mm256_set_epu64x(UINT64_C( 1299606958523224500), UINT64_C(  180290562185991433),
                               UINT64_C( 2113350532801719330), UINT64_C(13493341674566517412)) },
    { simde_x_mm256_set_epu64x(UINT64_C( 3908684742628183808), UINT64_C(15775432521885308750),
                               UINT64_C( 2246668589251707300), UINT64_C( 9474721517893975343)),
      simde_x_mm256_set_epu64x(UINT64_C( 2129749246616352421), UINT64_C( 3930946101587052880),
                               UINT64_C( 6109596926925725236), UINT64_C(11931707044738783755)),
      simde_x_mm256_set_epu64x(UINT64_C( 1778935496011831387), UINT64_C(   51648115537097230),
                               UINT64_C( 2246668589251707300), UINT64_C( 9474721517893975343)) },
    { simde_x_mm256_set_epu64x(UINT64_C( 7540605987113962845), UINT64_C(13935122940778806069),
                               UINT64_C( 9355601638871447350), UINT64_C(17674380633802211723)),
      simde_x_mm256_set_epu64x(UINT64_C( 5181754748372749246), UINT64_C( 2283432752406648940),
                               UINT64_C(17825612137522679693), UINT64_C( 6205295972918594513)),
      simde_x_mm256_set_epu64x(UINT64_C( 2358851238741213599), UINT64_C(  234526426338912429),
                               UINT64_C( 9355601638871447350), UINT64_C( 5263788687965022697)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_rem_epu64(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_u64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_rem_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512i a;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {
    { simde_mm512_set_epi8(INT8_C(  41), INT8_C(  49), INT8_C( -85), INT8_C( -58),
                           INT8_C(  40), INT8_C(  44), INT8_C( -14), INT8_C(  51),
                           INT8_C(-118), INT8_C( -39), INT8_C( -41), INT8_C(  -7),
                           INT8_C( -55), INT8_C(  37), INT8_C(-119), INT8_C(  29),
                           INT8_C( -23), INT8_C( -86), INT8_C( -15), INT8_C( 126),
                           INT8_C( -74), INT8_C(  10), INT8_C( -48), INT8_C( -58),
                           INT8_C(  93), INT8_C(-126), INT8_C( -61), INT8_C( -79),
                           INT8_C( -69), INT8_C( -33), INT8_C(-117), INT8_C(  -3),
                           INT8_C( -65), INT8_C( -89), INT8_C( -30), INT8_C(  64),
                           INT8_C( -43), INT8_C( -54), INT8_C( 110), INT8_C( 113),
                           INT8_C(  89), INT8_C( -19), INT8_C(  70), INT8_C( -30),
                           INT8_C(-124), INT8_C(  91), INT8_C(  -1), INT8_C(  88),
                           INT8_C( 104), INT8_C(  42), INT8_C(  53), INT8_C(  -2),
                           INT8_C(-124), INT8_C(  -2), INT8_C(  96), INT8_C(  75),
                           INT8_C(  31), INT8_C( 112), INT8_C(-105), INT8_C( -87),
                           INT8_C( -84), INT8_C(  94), INT8_C( 112), INT8_C(  90)),
      simde_mm512_set_epi8(INT8_C( -61), INT8_C(  49), INT8_C(  14), INT8_C( -86),
                           INT8_C( -53), INT8_C( -89), INT8_C(   3), INT8_C( -41),
                           INT8_C(  63), INT8_C(  -8), INT8_C(  55), INT8_C( -37),
                           INT8_C( -35), INT8_C(-121), INT8_C(  61), INT8_C( -65),
                           INT8_C( -47), INT8_C(  91), INT8_C(  87), INT8_C(-119),
                           INT8_C(  87), INT8_C(  76), INT8_C(  44), INT8_C(-116),
                           INT8_C(   2), INT8_C( -56), INT8_C(  36), INT8_C( -61),
                           INT8_C( -56), INT8_C( 125), INT8_C(  -2), INT8_C(-117),
                           INT8_C( -30), INT8_C(  71), INT8_C(  92), INT8_C(-127),
                           INT8_C( -74), INT8_C( 119), INT8_C(  -9), INT8_C(  34),
                           INT8_C( 121), INT8_C(  85), INT8_C(-103), INT8_C( 116),
                           INT8_C( -38), INT8_C(  21), INT8_C( 101), INT8_C( 122),
                           INT8_C(  10), INT8_C( -25), INT8_C(  54), INT8_C(  71),
                           INT8_C(-100), INT8_C(-107), INT8_C( -12), INT8_C(  84),
                           INT8_C(-108), INT8_C(  85), INT8_C( -86), INT8_C( -72),
                           INT8_C(  94), INT8_C(-102), INT8_C( -27), INT8_C(  11)),
      simde_mm512_set_epi8(INT8_C(  41), INT8_C(   0), INT8_C(  -1), INT8_C( -58),
                           INT8_C(  40), INT8_C(  44), INT8_C(  -2), INT8_C(  10),
                           INT8_C( -55), INT8_C(  -7), INT8_C( -41), INT8_C(  -7),
                           INT8_C( -20), INT8_C(  37), INT8_C( -58), INT8_C(  29),
                           INT8_C( -23), INT8_C( -86), INT8_C( -15), INT8_C(   7),
                           INT8_C( -74), INT8_C(  10), INT8_C(  -4), INT8_C( -58),
                           INT8_C(   1), INT8_C( -14), INT8_C( -25), INT8_C( -18),
                           INT8_C( -13), INT8_C( -33), INT8_C(  -1), INT8_C(  -3),
                           INT8_C(  -5), INT8_C( -18), INT8_C( -30), INT8_C(  64),
                           INT8_C( -43), INT8_C( -54), INT8_C(   2), INT8_C(  11),
                           INT8_C(  89), INT8_C( -19), INT8_C(  70), INT8_C( -30),
                           INT8_C( -10), INT8_C(   7), INT8_C(  -1), INT8_C(  88),
                           INT8_C(   4), INT8_C(  17), INT8_C(  53), INT8_C(  -2),
                           INT8_C( -24), INT8_C(  -2), INT8_C(   0), INT8_C(  75),
                           INT8_C(  31), INT8_C(  27), INT8_C( -19), INT8_C( -15),
                           INT8_C( -84), INT8_C(  94), INT8_C(   4), INT8_C(   2)) },
    { simde_mm512_set_epi8(INT8_C( -40), INT8_C(  85), INT8_C( -50), INT8_C( 103),
                           INT8_C( -21), INT8_C(-102), INT8_C(-127), INT8_C(-121),
                           INT8_C( 125), INT8_C(  76), INT8_C( -54), INT8_C( 108),
                           INT8_C(  52), INT8_C(  71), INT8_C( -88), INT8_C( -60),
                           INT8_C(  70), INT8_C(-118), INT8_C( -89), INT8_C(  65),
                           INT8_C( -35), INT8_C( -95), INT8_C( -99), INT8_C(  93),
                           INT8_C( -64), INT8_C( -67), INT8_C(-103), INT8_C(-101),
                           INT8_C( -49), INT8_C( -43), INT8_C( 105), INT8_C(-120),
                           INT8_C( -22), INT8_C(  94), INT8_C( -16), INT8_C(  12),
                           INT8_C(-110), INT8_C(   1), INT8_C(-109), INT8_C(  59),
                           INT8_C(  -3), INT8_C(  26), INT8_C(  26), INT8_C(  40),
                           INT8_C(  12), INT8_C(   2), INT8_C( -26), INT8_C(-111),
                           INT8_C( -86), INT8_C( 105), INT8_C( 111), INT8_C( -96),
                           INT8_C(-116), INT8_C( -54), INT8_C( -90), INT8_C( -36),
                           INT8_C( -69), INT8_C(  65), INT8_C(  -6), INT8_C( -61),
                           INT8_C(  33), INT8_C(-125), INT8_C(   2), INT8_C( -92)),
      simde_mm512_set_epi8(INT8_C( 120), INT8_C( 127), INT8_C(  28), INT8_C(  95),
                           INT8_C( -81), INT8_C( -33), INT8_C( 119), INT8_C( -42),
                           INT8_C( -36), INT8_C( 102), INT8_C(  86), INT8_C(  22),
                           INT8_C( 119), INT8_C( -49), INT8_C(  12), INT8_C( -73),
                           INT8_C( -84), INT8_C( -14), INT8_C( -83), INT8_C(  -7),
                           INT8_C(  52), INT8_C( 108), INT8_C(-128), INT8_C( -53),
                           INT8_C(  85), INT8_C(-121), INT8_C( -29), INT8_C(  35),
                           INT8_C( -69), INT8_C(  24), INT8_C(  -6), INT8_C( -37),
                           INT8_C(  -3), INT8_C(  62), INT8_C( 125), INT8_C( -20),
                           INT8_C(  75), INT8_C(  13), INT8_C(  79), INT8_C(  81),
                           INT8_C( -79), INT8_C( -35), INT8_C(  -5), INT8_C( -75),
                           INT8_C( -97), INT8_C( -74), INT8_C(  11), INT8_C(  11),
                           INT8_C(  39), INT8_C(  37), INT8_C(  39), INT8_C( -48),
                           INT8_C(-120), INT8_C( -76), INT8_C( -41), INT8_C(-117),
                           INT8_C(-112), INT8_C(-128), INT8_C( -53), INT8_C( -50),
                           INT8_C( -83), INT8_C(  36), INT8_C(-123), INT8_C( -81)),
      simde_mm512_set_epi8(INT8_C( -40), INT8_C(  85), INT8_C( -22), INT8_C(   8),
                           INT8_C( -21), INT8_C(  -3), INT8_C(  -8), INT8_C( -37),
                           INT8_C(  17), INT8_C(  76), INT8_C( -54), INT8_C(  20),
                           INT8_C(  52), INT8_C(  22), INT8_C(  -4), INT8_C( -60),
                           INT8_C(  70), INT8_C(  -6), INT8_C(  -6), INT8_C(   2),
                           INT8_C( -35), INT8_C( -95), INT8_C( -99), INT8_C(  40),
                           INT8_C( -64), INT8_C( -67), INT8_C( -16), INT8_C( -31),
                           INT8_C( -49), INT8_C( -19), INT8_C(   3), INT8_C(  -9),
                           INT8_C(  -1), INT8_C(  32), INT8_C( -16), INT8_C(  12),
                           INT8_C( -35), INT8_C(   1), INT8_C( -30), INT8_C(  59),
                           INT8_C(  -3), INT8_C(  26), INT8_C(   1), INT8_C(  40),
                           INT8_C(  12), INT8_C(   2), INT8_C(  -4), INT8_C(  -1),
                           INT8_C(  -8), INT8_C(  31), INT8_C(  33), INT8_C(   0),
                           INT8_C(-116), INT8_C( -54), INT8_C(  -8), INT8_C( -36),
                           INT8_C( -69), INT8_C(  65), INT8_C(  -6), INT8_C( -11),
                           INT8_C(  33), INT8_C( -17), INT8_C(   2), INT8_C( -11)) },
    { simde_mm512_set_epi8(INT8_C(  87), INT8_C(  63), INT8_C(  47), INT8_C(  80),
                           INT8_C(  35), INT8_C( -27), INT8_C(   5), INT8_C(  31),
                           INT8_C( -28), INT8_C(  73), INT8_C(  53), INT8_C(  47),
                           INT8_C( -86), INT8_C( -64), INT8_C( 122), INT8_C( -19),
                           INT8_C(  47), INT8_C(-126), INT8_C( -37), INT8_C( 102),
                           INT8_C( -93), INT8_C(  41), INT8_C( -61), INT8_C( -41),
                           INT8_C( -57), INT8_C(  54), INT8_C(  97), INT8_C( 126),
                           INT8_C(  10), INT8_C( -91), INT8_C(-101), INT8_C(  88),
                           INT8_C( -72), INT8_C(  63), INT8_C(  95), INT8_C( -92),
                           INT8_C(  65), INT8_C(  71), INT8_C( -82), INT8_C(  88),
                           INT8_C( -73), INT8_C(-114), INT8_C(  98), INT8_C(  14),
                           INT8_C(  25), INT8_C( -83), INT8_C(  87), INT8_C(   2),
                           INT8_C( -65), INT8_C(-113), INT8_C(-104), INT8_C(   2),
                           INT8_C( 126), INT8_C(   0), INT8_C( -94), INT8_C(  57),
                           INT8_C( -11), INT8_C(  36), INT8_C( -17), INT8_C(  54),
                           INT8_C(  33), INT8_C( -91), INT8_C( -57), INT8_C(  84)),
      simde_mm512_set_epi8(INT8_C(-125), INT8_C(  42), INT8_C(-105), INT8_C( -46),
                           INT8_C(  12), INT8_C( -93), INT8_C(-118), INT8_C( -49),
                           INT8_C(  43), INT8_C(  57), INT8_C(  61), INT8_C(  62),
                           INT8_C(  81), INT8_C( -72), INT8_C(   6), INT8_C(  93),
                           INT8_C( -89), INT8_C(   1), INT8_C(-111), INT8_C(   9),
                           INT8_C(   4), INT8_C(  17), INT8_C(  10), INT8_C( 101),
                           INT8_C( -70), INT8_C( -75), INT8_C(-101), INT8_C( -13),
                           INT8_C( -67), INT8_C( -65), INT8_C( -34), INT8_C( -51),
                           INT8_C(  59), INT8_C(  26), INT8_C( -29), INT8_C( 105),
                           INT8_C( -19), INT8_C(-111), INT8_C( -73), INT8_C(  79),
                           INT8_C( -82), INT8_C(  60), INT8_C(-124), INT8_C( -48),
                           INT8_C(  58), INT8_C( -78), INT8_C( 116), INT8_C( -16),
                           INT8_C(  37), INT8_C(-125), INT8_C( 100), INT8_C( -79),
                           INT8_C(  19), INT8_C( 102), INT8_C(  81), INT8_C(  86),
                           INT8_C(  25), INT8_C(  43), INT8_C(  51), INT8_C(-116),
                           INT8_C(   9), INT8_C(  40), INT8_C( -29), INT8_C(  75)),
      simde_mm512_set_epi8(INT8_C(  87), INT8_C(  21), INT8_C(  47), INT8_C(  34),
                           INT8_C(  11), INT8_C( -27), INT8_C(   5), INT8_C(  31),
                           INT8_C( -28), INT8_C(  16), INT8_C(  53), INT8_C(  47),
                           INT8_C(  -5), INT8_C( -64), INT8_C(   2), INT8_C( -19),
                           INT8_C(  47), INT8_C(   0), INT8_C( -37), INT8_C(   3),
                           INT8_C(  -1), INT8_C(   7), INT8_C(  -1), INT8_C( -41),
                           INT8_C( -57), INT8_C(  54), INT8_C(  97), INT8_C(   9),
                           INT8_C(  10), INT8_C( -26), INT8_C( -33), INT8_C(  37),
                           INT8_C( -13), INT8_C(  11), INT8_C(   8), INT8_C( -92),
                           INT8_C(   8), INT8_C(  71), INT8_C(  -9), INT8_C(   9),
                           INT8_C( -73), INT8_C( -54), INT8_C(  98), INT8_C(  14),
                           INT8_C(  25), INT8_C(  -5), INT8_C(  87), INT8_C(   2),
                           INT8_C( -28), INT8_C(-113), INT8_C(  -4), INT8_C(   2),
                           INT8_C(  12), INT8_C(   0), INT8_C( -13), INT8_C(  57),
                           INT8_C( -11), INT8_C(  36), INT8_C( -17), INT8_C(  54),
                           INT8_C(   6), INT8_C( -11), INT8_C( -28), INT8_C(   9)) },
    { simde_mm512_set_epi8(INT8_C( -23), INT8_C(  79), INT8_C(  12), INT8_C(   0),
                           INT8_C(  33), INT8_C( -78), INT8_C(  58), INT8_C(  74),
                           INT8_C(  -6), INT8_C( 116), INT8_C(-114), INT8_C(  20),
                           INT8_C(  88), INT8_C(  63), INT8_C(  34), INT8_C( 124),
                           INT8_C(  -6), INT8_C(  48), INT8_C( -35), INT8_C( -24),
                           INT8_C( -35), INT8_C(  75), INT8_C(-101), INT8_C(  80),
                           INT8_C( -23), INT8_C( -87), INT8_C( -58), INT8_C( -30),
                           INT8_C(  83), INT8_C(  27), INT8_C(-119), INT8_C(  34),
                           INT8_C(  23), INT8_C(-124), INT8_C( 106), INT8_C( 109),
                           INT8_C(-121), INT8_C( -53), INT8_C(  98), INT8_C( 120),
                           INT8_C( 101), INT8_C(  52), INT8_C(  82), INT8_C(  44),
                           INT8_C(-114), INT8_C(  14), INT8_C(  99), INT8_C( -11),
                           INT8_C(   8), INT8_C(-116), INT8_C(-115), INT8_C( 123),
                           INT8_C( -37), INT8_C( -93), INT8_C( -60), INT8_C( -23),
                           INT8_C(  34), INT8_C( -71), INT8_C( -28), INT8_C( 108),
                           INT8_C(  95), INT8_C( -20), INT8_C(  97), INT8_C(  41)),
      simde_mm512_set_epi8(INT8_C( -63), INT8_C( -26), INT8_C(  93), INT8_C(  23),
                           INT8_C( -63), INT8_C(  52), INT8_C( -33), INT8_C( -81),
                           INT8_C( -51), INT8_C(  45), INT8_C( -90), INT8_C(  24),
                           INT8_C(  71), INT8_C( -22), INT8_C( -95), INT8_C(-114),
                           INT8_C( -72), INT8_C( -38), INT8_C( -66), INT8_C( -44),
                           INT8_C( 116), INT8_C( -97), INT8_C(  44), INT8_C(  55),
                           INT8_C( -43), INT8_C(-123), INT8_C(  60), INT8_C(   3),
                           INT8_C(  58), INT8_C(  -1), INT8_C( 125), INT8_C( -67),
                           INT8_C(-111), INT8_C(  88), INT8_C(  55), INT8_C( -74),
                           INT8_C(  23), INT8_C( -95), INT8_C(-123), INT8_C(  27),
                           INT8_C( 125), INT8_C( -27), INT8_C( -53), INT8_C(  45),
                           INT8_C(  24), INT8_C(   5), INT8_C(  90), INT8_C(  83),
                           INT8_C(-111), INT8_C(  85), INT8_C(-100), INT8_C( -92),
                           INT8_C(-107), INT8_C( -55), INT8_C(  48), INT8_C(  -1),
                           INT8_C(  41), INT8_C(  42), INT8_C(  94), INT8_C(-127),
                           INT8_C(-121), INT8_C(   8), INT8_C(  12), INT8_C( -53)),
      simde_mm512_set_epi8(INT8_C( -23), INT8_C(   1), INT8_C(  12), INT8_C(   0),
                           INT8_C(  33), INT8_C( -26), INT8_C(  25), INT8_C(  74),
                           INT8_C(  -6), INT8_C(  26), INT8_C( -24), INT8_C(  20),
                           INT8_C(  17), INT8_C(  19), INT8_C(  34), INT8_C(  10),
                           INT8_C(  -6), INT8_C(  10), INT8_C( -35), INT8_C( -24),
                           INT8_C( -35), INT8_C(  75), INT8_C( -13), INT8_C(  25),
                           INT8_C( -23), INT8_C( -87), INT8_C( -58), INT8_C(   0),
                           INT8_C(  25), INT8_C(   0), INT8_C(-119), INT8_C(  34),
                           INT8_C(  23), INT8_C( -36), INT8_C(  51), INT8_C(  35),
                           INT8_C(  -6), INT8_C( -53), INT8_C(  98), INT8_C(  12),
                           INT8_C( 101), INT8_C(  25), INT8_C(  29), INT8_C(  44),
                           INT8_C( -18), INT8_C(   4), INT8_C(   9), INT8_C( -11),
                           INT8_C(   8), INT8_C( -31), INT8_C( -15), INT8_C(  31),
                           INT8_C( -37), INT8_C( -38), INT8_C( -12), INT8_C(   0),
                           INT8_C(  34), INT8_C( -29), INT8_C( -28), INT8_C( 108),
                           INT8_C(  95), INT8_C(  -4), INT8_C(   1), INT8_C(  41)) },
    { simde_mm512_set_epi8(INT8_C(-114), INT8_C(  19), INT8_C(-128), INT8_C(   3),
                           INT8_C(-127), INT8_C( -64), INT8_C( 118), INT8_C(-100),
                           INT8_C(  16), INT8_C( -24), INT8_C( -53), INT8_C( 122),
                           INT8_C( -27), INT8_C( 105), INT8_C( 120), INT8_C( -55),
                           INT8_C( -28), INT8_C( -89), INT8_C(-115), INT8_C(-110),
                           INT8_C( 116), INT8_C(  74), INT8_C( -65), INT8_C(  35),
                           INT8_C(  45), INT8_C( -98), INT8_C( -28), INT8_C(-118),
                           INT8_C(  49), INT8_C(   7), INT8_C(  65), INT8_C(-116),
                           INT8_C(   0), INT8_C( 113), INT8_C(-100), INT8_C( 113),
                           INT8_C( -10), INT8_C( -89), INT8_C( 109), INT8_C(-115),
                           INT8_C( -64), INT8_C(  11), INT8_C(  33), INT8_C(-115),
                           INT8_C(-127), INT8_C(   2), INT8_C( -88), INT8_C( -29),
                           INT8_C(  23), INT8_C( -83), INT8_C( 104), INT8_C(  71),
                           INT8_C(  11), INT8_C(  -6), INT8_C(  13), INT8_C( -38),
                           INT8_C( -62), INT8_C(-116), INT8_C( 125), INT8_C(  43),
                           INT8_C(-105), INT8_C(  49), INT8_C(-127), INT8_C( -38)),
      simde_mm512_set_epi8(INT8_C(   8), INT8_C(  25), INT8_C(-109), INT8_C( -36),
                           INT8_C( -83), INT8_C(-118), INT8_C(  38), INT8_C(-106),
                           INT8_C(  35), INT8_C(  43), INT8_C( -91), INT8_C( -71),
                           INT8_C(  50), INT8_C(  64), INT8_C( -95), INT8_C(-124),
                           INT8_C( -94), INT8_C(  50), INT8_C( -57), INT8_C(  84),
                           INT8_C(  -5), INT8_C( -56), INT8_C( -39), INT8_C(  19),
                           INT8_C( -76), INT8_C( -60), INT8_C( -10), INT8_C(  76),
                           INT8_C(  55), INT8_C( -52), INT8_C(-117), INT8_C(  75),
                           INT8_C(   1), INT8_C(  89), INT8_C(-123), INT8_C( -44),
                           INT8_C( -50), INT8_C(  55), INT8_C( -52), INT8_C( 120),
                           INT8_C(  37), INT8_C( -97), INT8_C(-110), INT8_C( -39),
                           INT8_C( -30), INT8_C( -66), INT8_C(-122), INT8_C(   8),
                           INT8_C( 113), INT8_C(  61), INT8_C( 103), INT8_C( 100),
                           INT8_C(  23), INT8_C( -27), INT8_C(-110), INT8_C(  97),
                           INT8_C(  95), INT8_C(  32), INT8_C(-120), INT8_C(  91),
                           INT8_C(  46), INT8_C(  -4), INT8_C( -93), INT8_C(  88)),
      simde_mm512_set_epi8(INT8_C(  -2), INT8_C(  19), INT8_C( -19), INT8_C(   3),
                           INT8_C( -44), INT8_C( -64), INT8_C(   4), INT8_C(-100),
                           INT8_C(  16), INT8_C( -24), INT8_C( -53), INT8_C(  51),
                           INT8_C( -27), INT8_C(  41), INT8_C(  25), INT8_C( -55),
                           INT8_C( -28), INT8_C( -39), INT8_C(  -1), INT8_C( -26),
                           INT8_C(   1), INT8_C(  18), INT8_C( -26), INT8_C(  16),
                           INT8_C(  45), INT8_C( -38), INT8_C(  -8), INT8_C( -42),
                           INT8_C(  49), INT8_C(   7), INT8_C(  65), INT8_C( -41),
                           INT8_C(   0), INT8_C(  24), INT8_C(-100), INT8_C(  25),
                           INT8_C( -10), INT8_C( -34), INT8_C(   5), INT8_C(-115),
                           INT8_C( -27), INT8_C(  11), INT8_C(  33), INT8_C( -37),
                           INT8_C(  -7), INT8_C(   2), INT8_C( -88), INT8_C(  -5),
                           INT8_C(  23), INT8_C( -22), INT8_C(   1), INT8_C(  71),
                           INT8_C(  11), INT8_C(  -6), INT8_C(  13), INT8_C( -38),
                           INT8_C( -62), INT8_C( -20), INT8_C(   5), INT8_C(  43),
                           INT8_C( -13), INT8_C(   1), INT8_C( -34), INT8_C( -38)) },
    { simde_mm512_set_epi8(INT8_C(  46), INT8_C(  43), INT8_C( -10), INT8_C( -99),
                           INT8_C(  80), INT8_C(-102), INT8_C(  27), INT8_C( 118),
                           INT8_C( -80), INT8_C( -40), INT8_C(  46), INT8_C(-114),
                           INT8_C( -58), INT8_C(  -8), INT8_C(  88), INT8_C(  29),
                           INT8_C( -80), INT8_C(  25), INT8_C( 101), INT8_C(  54),
                           INT8_C( 103), INT8_C( 120), INT8_C(  94), INT8_C(  16),
                           INT8_C( -59), INT8_C( -51), INT8_C(  71), INT8_C( -10),
                           INT8_C( -98), INT8_C( -80), INT8_C( -38), INT8_C(  43),
                           INT8_C( -21), INT8_C(  -7), INT8_C( 116), INT8_C(-119),
                           INT8_C(  89), INT8_C( -44), INT8_C(-124), INT8_C(  56),
                           INT8_C( -26), INT8_C(-119), INT8_C(  66), INT8_C(  41),
                           INT8_C(  44), INT8_C(  35), INT8_C( -67), INT8_C(-101),
                           INT8_C( 125), INT8_C(-126), INT8_C( 123), INT8_C( 117),
                           INT8_C( 123), INT8_C( 127), INT8_C(-105), INT8_C(  60),
                           INT8_C(-103), INT8_C( -71), INT8_C(  -6), INT8_C( 100),
                           INT8_C(  83), INT8_C( 112), INT8_C(  33), INT8_C(-116)),
      simde_mm512_set_epi8(INT8_C(  36), INT8_C(  33), INT8_C(  42), INT8_C(  75),
                           INT8_C( -77), INT8_C( -84), INT8_C( 126), INT8_C( -85),
                           INT8_C( 110), INT8_C(-106), INT8_C( 107), INT8_C( -76),
                           INT8_C(-122), INT8_C(  73), INT8_C( -49), INT8_C(  15),
                           INT8_C( -15), INT8_C( 103), INT8_C( 103), INT8_C(-106),
                           INT8_C( 103), INT8_C(  58), INT8_C( 104), INT8_C(  35),
                           INT8_C(  -7), INT8_C(  79), INT8_C( 113), INT8_C(  97),
                           INT8_C( -67), INT8_C( -59), INT8_C( -82), INT8_C( -34),
                           INT8_C( -32), INT8_C( 104), INT8_C( 123), INT8_C( 124),
                           INT8_C(  49), INT8_C( -30), INT8_C(  37), INT8_C(  22),
                           INT8_C( 105), INT8_C( -99), INT8_C( 110), INT8_C(  52),
                           INT8_C(  -2), INT8_C( 103), INT8_C( -94), INT8_C( -46),
                           INT8_C( -54), INT8_C(  39), INT8_C( -63), INT8_C(-105),
                           INT8_C( -73), INT8_C(  73), INT8_C(  97), INT8_C( -69),
                           INT8_C( 102), INT8_C( -61), INT8_C(  68), INT8_C( -66),
                           INT8_C(  65), INT8_C(  60), INT8_C( -91), INT8_C( 126)),
      simde_mm512_set_epi8(INT8_C(  10), INT8_C(  10), INT8_C( -10), INT8_C( -24),
                           INT8_C(   3), INT8_C( -18), INT8_C(  27), INT8_C(  33),
                           INT8_C( -80), INT8_C( -40), INT8_C(  46), INT8_C( -38),
                           INT8_C( -58), INT8_C(  -8), INT8_C(  39), INT8_C(  14),
                           INT8_C(  -5), INT8_C(  25), INT8_C( 101), INT8_C(  54),
                           INT8_C(   0), INT8_C(   4), INT8_C(  94), INT8_C(  16),
                           INT8_C(  -3), INT8_C( -51), INT8_C(  71), INT8_C( -10),
                           INT8_C( -31), INT8_C( -21), INT8_C( -38), INT8_C(   9),
                           INT8_C( -21), INT8_C(  -7), INT8_C( 116), INT8_C(-119),
                           INT8_C(  40), INT8_C( -14), INT8_C( -13), INT8_C(  12),
                           INT8_C( -26), INT8_C( -20), INT8_C(  66), INT8_C(  41),
                           INT8_C(   0), INT8_C(  35), INT8_C( -67), INT8_C(  -9),
                           INT8_C(  17), INT8_C(  -9), INT8_C(  60), INT8_C(  12),
                           INT8_C(  50), INT8_C(  54), INT8_C(  -8), INT8_C(  60),
                           INT8_C(  -1), INT8_C( -10), INT8_C(  -6), INT8_C(  34),
                           INT8_C(  18), INT8_C(  52), INT8_C(  33), INT8_C(-116)) },
    { simde_mm512_set_epi8(INT8_C( -16), INT8_C( -87), INT8_C(   8), INT8_C(  54),
                           INT8_C(  66), INT8_C(  99), INT8_C(  14), INT8_C(  32),
                           INT8_C(-108), INT8_C(  92), INT8_C( 122), INT8_C( -56),
                           INT8_C( -64), INT8_C( -70), INT8_C( -31), INT8_C(  52),
                           INT8_C( -74), INT8_C( -12), INT8_C(  -3), INT8_C( -28),
                           INT8_C(-115), INT8_C( -28), INT8_C(-108), INT8_C( -88),
                           INT8_C( -25), INT8_C( 107), INT8_C(  47), INT8_C( -51),
                           INT8_C( 126), INT8_C(   7), INT8_C( -74), INT8_C( -11),
                           INT8_C( -91), INT8_C( -70), INT8_C( -43), INT8_C(  84),
                           INT8_C(  19), INT8_C(-125), INT8_C(  54), INT8_C(  13),
                           INT8_C( -71), INT8_C( -74), INT8_C(  72), INT8_C(  61),
                           INT8_C( 125), INT8_C( 104), INT8_C(-109), INT8_C(  11),
                           INT8_C(  89), INT8_C( -52), INT8_C(  62), INT8_C( -93),
                           INT8_C( -58), INT8_C( -94), INT8_C( -51), INT8_C(   9),
                           INT8_C( -74), INT8_C( 123), INT8_C(  65), INT8_C( -48),
                           INT8_C(-111), INT8_C( -77), INT8_C(  34), INT8_C( -61)),
      simde_mm512_set_epi8(INT8_C(-115), INT8_C( 103), INT8_C( 116), INT8_C(  12),
                           INT8_C( -82), INT8_C( -30), INT8_C( -63), INT8_C( -81),
                           INT8_C(-101), INT8_C( -82), INT8_C(  73), INT8_C(   6),
                           INT8_C(-115), INT8_C(-116), INT8_C(  -2), INT8_C( -63),
                           INT8_C( 100), INT8_C(-105), INT8_C(  14), INT8_C(  19),
                           INT8_C(  38), INT8_C( 115), INT8_C( -55), INT8_C( 118),
                           INT8_C(  74), INT8_C( -70), INT8_C(  89), INT8_C( -73),
                           INT8_C(  65), INT8_C(-118), INT8_C(  64), INT8_C(  90),
                           INT8_C(-104), INT8_C( -15), INT8_C( -27), INT8_C( -38),
                           INT8_C( 126), INT8_C(  38), INT8_C( -97), INT8_C(  27),
                           INT8_C( -92), INT8_C( -57), INT8_C(  25), INT8_C(  -3),
                           INT8_C( -75), INT8_C( 104), INT8_C(   6), INT8_C( -73),
                           INT8_C(  36), INT8_C( -53), INT8_C(-118), INT8_C(-111),
                           INT8_C( 116), INT8_C(-101), INT8_C( -38), INT8_C(  24),
                           INT8_C( -51), INT8_C( -18), INT8_C( -14), INT8_C(  26),
                           INT8_C( -30), INT8_C(  76), INT8_C( -30), INT8_C( -42)),
      simde_mm512_set_epi8(INT8_C( -16), INT8_C( -87), INT8_C(   8), INT8_C(   6),
                           INT8_C(  66), INT8_C(   9), INT8_C(  14), INT8_C(  32),
                           INT8_C(  -7), INT8_C(  10), INT8_C(  49), INT8_C(  -2),
                           INT8_C( -64), INT8_C( -70), INT8_C(  -1), INT8_C(  52),
                           INT8_C( -74), INT8_C( -12), INT8_C(  -3), INT8_C(  -9),
                           INT8_C(  -1), INT8_C( -28), INT8_C( -53), INT8_C( -88),
                           INT8_C( -25), INT8_C(  37), INT8_C(  47), INT8_C( -51),
                           INT8_C(  61), INT8_C(   7), INT8_C( -10), INT8_C( -11),
                           INT8_C( -91), INT8_C( -10), INT8_C( -16), INT8_C(   8),
                           INT8_C(  19), INT8_C( -11), INT8_C(  54), INT8_C(  13),
                           INT8_C( -71), INT8_C( -17), INT8_C(  22), INT8_C(   1),
                           INT8_C(  50), INT8_C(   0), INT8_C(  -1), INT8_C(  11),
                           INT8_C(  17), INT8_C( -52), INT8_C(  62), INT8_C( -93),
                           INT8_C( -58), INT8_C( -94), INT8_C( -13), INT8_C(   9),
                           INT8_C( -23), INT8_C(  15), INT8_C(   9), INT8_C( -22),
                           INT8_C( -21), INT8_C(  -1), INT8_C(   4), INT8_C( -19)) },
    { simde_mm512_set_epi8(INT8_C( -59), INT8_C(  52), INT8_C(-111), INT8_C(  20),
                           INT8_C(  26), INT8_C( -78), INT8_C( 121), INT8_C(  16),
                           INT8_C(  45), INT8_C( -27), INT8_C(  11), INT8_C( -26),
                           INT8_C(  53), INT8_C(   2), INT8_C( -22), INT8_C(   7),
                           INT8_C( -49), INT8_C(-110), INT8_C( -87), INT8_C( -23),
                           INT8_C( -50), INT8_C( 116), INT8_C(  55), INT8_C(-100),
                           INT8_C( -76), INT8_C(  91), INT8_C(  56), INT8_C(-110),
                           INT8_C(  55), INT8_C(-119), INT8_C( -56), INT8_C(  76),
                           INT8_C(  43), INT8_C( -11), INT8_C(-118), INT8_C(   3),
                           INT8_C( -43), INT8_C(-100), INT8_C( -90), INT8_C( -22),
                           INT8_C( -57), INT8_C(   2), INT8_C(  86), INT8_C(  72),
                           INT8_C(  93), INT8_C(  -2), INT8_C( -66), INT8_C( 121),
                           INT8_C( 119), INT8_C(  75), INT8_C( -97), INT8_C(  76),
                           INT8_C(  70), INT8_C( -38), INT8_C(  17), INT8_C( -17),
                           INT8_C(  43), INT8_C(-104), INT8_C( -34), INT8_C(  80),
                           INT8_C( -59), INT8_C( 113), INT8_C( 112), INT8_C(  81)),
      simde_mm512_set_epi8(INT8_C( -63), INT8_C( -94), INT8_C( -78), INT8_C(  36),
                           INT8_C( -78), INT8_C(  86), INT8_C(  79), INT8_C( -89),
                           INT8_C( -77), INT8_C(  45), INT8_C(  18), INT8_C( -25),
                           INT8_C( 113), INT8_C( 127), INT8_C( -45), INT8_C( -75),
                           INT8_C( 121), INT8_C( -85), INT8_C(  76), INT8_C(-121),
                           INT8_C(  15), INT8_C(-123), INT8_C(  -9), INT8_C(  32),
                           INT8_C( -75), INT8_C( -88), INT8_C( -20), INT8_C(  99),
                           INT8_C(  85), INT8_C(-105), INT8_C(  36), INT8_C(  99),
                           INT8_C( 101), INT8_C(  42), INT8_C(  63), INT8_C(  96),
                           INT8_C( -46), INT8_C( -58), INT8_C( -54), INT8_C( 105),
                           INT8_C( -42), INT8_C(  74), INT8_C( -57), INT8_C(  17),
                           INT8_C( -22), INT8_C(  22), INT8_C(-122), INT8_C( 112),
                           INT8_C(  62), INT8_C(-115), INT8_C(-100), INT8_C(  91),
                           INT8_C(  99), INT8_C(  24), INT8_C( -58), INT8_C(-125),
                           INT8_C(  88), INT8_C(-120), INT8_C(  61), INT8_C(  94),
                           INT8_C( -67), INT8_C( -43), INT8_C(  -7), INT8_C(-125)),
      simde_mm512_set_epi8(INT8_C( -59), INT8_C(  52), INT8_C( -33), INT8_C(  20),
                           INT8_C(  26), INT8_C( -78), INT8_C(  42), INT8_C(  16),
                           INT8_C(  45), INT8_C( -27), INT8_C(  11), INT8_C(  -1),
                           INT8_C(  53), INT8_C(   2), INT8_C( -22), INT8_C(   7),
                           INT8_C( -49), INT8_C( -25), INT8_C( -11), INT8_C( -23),
                           INT8_C(  -5), INT8_C( 116), INT8_C(   1), INT8_C(  -4),
                           INT8_C(  -1), INT8_C(   3), INT8_C(  16), INT8_C( -11),
                           INT8_C(  55), INT8_C( -14), INT8_C( -20), INT8_C(  76),
                           INT8_C(  43), INT8_C( -11), INT8_C( -55), INT8_C(   3),
                           INT8_C( -43), INT8_C( -42), INT8_C( -36), INT8_C( -22),
                           INT8_C( -15), INT8_C(   2), INT8_C(  29), INT8_C(   4),
                           INT8_C(   5), INT8_C(  -2), INT8_C( -66), INT8_C(   9),
                           INT8_C(  57), INT8_C(  75), INT8_C( -97), INT8_C(  76),
                           INT8_C(  70), INT8_C( -14), INT8_C(  17), INT8_C( -17),
                           INT8_C(  43), INT8_C(-104), INT8_C( -34), INT8_C(  80),
                           INT8_C( -59), INT8_C(  27), INT8_C(   0), INT8_C(  81)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_rem_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m512i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_rem_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512i a;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {
    { simde_mm512_set_epi16(INT16_C( 10545), INT16_C(-21562), INT16_C( 10284), INT16_C( -3533),
                            INT16_C(-29991), INT16_C(-10247), INT16_C(-14043), INT16_C(-30435),
                            INT16_C( -5718), INT16_C( -3714), INT16_C(-18934), INT16_C(-12090),
                            INT16_C( 23938), INT16_C(-15439), INT16_C(-17441), INT16_C(-29699),
                            INT16_C(-16473), INT16_C( -7616), INT16_C(-10806), INT16_C( 28273),
                            INT16_C( 23021), INT16_C( 18146), INT16_C(-31653), INT16_C(  -168),
                            INT16_C( 26666), INT16_C( 13822), INT16_C(-31490), INT16_C( 24651),
                            INT16_C(  8048), INT16_C(-26711), INT16_C(-21410), INT16_C( 28762)),
      simde_mm512_set_epi16(INT16_C(-26929), INT16_C(  8074), INT16_C( 18000), INT16_C(-29849),
                            INT16_C(-25121), INT16_C(  3254), INT16_C(-10254), INT16_C(-26681),
                            INT16_C(-24206), INT16_C(-28388), INT16_C( 25803), INT16_C( 25877),
                            INT16_C(   768), INT16_C( 16244), INT16_C( 11114), INT16_C( -7212),
                            INT16_C( 18192), INT16_C( 32532), INT16_C(-31836), INT16_C( -5163),
                            INT16_C( 20183), INT16_C( -1494), INT16_C(  2502), INT16_C( 18488),
                            INT16_C( 22771), INT16_C( 21470), INT16_C(  4556), INT16_C( 26138),
                            INT16_C( 19085), INT16_C(  -923), INT16_C( -9934), INT16_C( -2165)),
      simde_mm512_set_epi16(INT16_C( 10545), INT16_C( -5414), INT16_C( 10284), INT16_C( -3533),
                            INT16_C( -4870), INT16_C(  -485), INT16_C( -3789), INT16_C( -3754),
                            INT16_C( -5718), INT16_C( -3714), INT16_C(-18934), INT16_C(-12090),
                            INT16_C(   130), INT16_C(-15439), INT16_C( -6327), INT16_C(  -851),
                            INT16_C(-16473), INT16_C( -7616), INT16_C(-10806), INT16_C(  2458),
                            INT16_C(  2838), INT16_C(   218), INT16_C( -1629), INT16_C(  -168),
                            INT16_C(  3895), INT16_C( 13822), INT16_C( -4154), INT16_C( 24651),
                            INT16_C(  8048), INT16_C(  -867), INT16_C( -1542), INT16_C(   617)) },
    { simde_mm512_set_epi16(INT16_C( 20057), INT16_C( 26978), INT16_C(-19795), INT16_C(-31033),
                            INT16_C(-11277), INT16_C(-24100), INT16_C(-21653), INT16_C( 11009),
                            INT16_C(-15324), INT16_C(  9014), INT16_C( 24117), INT16_C(-31497),
                            INT16_C( -7188), INT16_C(  8311), INT16_C( 31759), INT16_C(  4002),
                            INT16_C(  7525), INT16_C(  3321), INT16_C(-18237), INT16_C( -1323),
                            INT16_C( 13644), INT16_C(-17383), INT16_C(-20302), INT16_C(-13836),
                            INT16_C(  7513), INT16_C(  1114), INT16_C(  -200), INT16_C( 10389),
                            INT16_C(-31848), INT16_C(  9445), INT16_C( -5204), INT16_C(-24070)),
      simde_mm512_set_epi16(INT16_C(-17379), INT16_C( -8623), INT16_C(-10486), INT16_C(-16677),
                            INT16_C( 27895), INT16_C(-17193), INT16_C( -5943), INT16_C( -5111),
                            INT16_C( -2949), INT16_C(-11305), INT16_C(-13092), INT16_C(  8140),
                            INT16_C( -6841), INT16_C(  2476), INT16_C(-24435), INT16_C(  7948),
                            INT16_C( 26094), INT16_C(-13182), INT16_C( 30122), INT16_C(-17848),
                            INT16_C(-21735), INT16_C( -7772), INT16_C(  1809), INT16_C(-31933),
                            INT16_C(  8271), INT16_C(  4936), INT16_C(  7627), INT16_C( 20477),
                            INT16_C( 14608), INT16_C( 25470), INT16_C(-19700), INT16_C( 25611)),
      simde_mm512_set_epi16(INT16_C(  2678), INT16_C(  1109), INT16_C( -9309), INT16_C(-14356),
                            INT16_C(-11277), INT16_C( -6907), INT16_C( -3824), INT16_C(   787),
                            INT16_C(  -579), INT16_C(  9014), INT16_C( 11025), INT16_C( -7077),
                            INT16_C(  -347), INT16_C(   883), INT16_C(  7324), INT16_C(  4002),
                            INT16_C(  7525), INT16_C(  3321), INT16_C(-18237), INT16_C( -1323),
                            INT16_C( 13644), INT16_C( -1839), INT16_C(  -403), INT16_C(-13836),
                            INT16_C(  7513), INT16_C(  1114), INT16_C(  -200), INT16_C( 10389),
                            INT16_C( -2632), INT16_C(  9445), INT16_C( -5204), INT16_C(-24070)) },
    { simde_mm512_set_epi16(INT16_C( 26902), INT16_C(-14525), INT16_C( -7905), INT16_C( -8015),
                            INT16_C(-22131), INT16_C( 18318), INT16_C(-21513), INT16_C(  9770),
                            INT16_C(  4118), INT16_C(-32437), INT16_C(  6621), INT16_C( -7897),
                            INT16_C( 22002), INT16_C(-32381), INT16_C( 15537), INT16_C(-26793),
                            INT16_C( 26466), INT16_C( 21183), INT16_C(  5811), INT16_C( 17016),
                            INT16_C(-14374), INT16_C(-18761), INT16_C(-11284), INT16_C(  -933),
                            INT16_C( 30444), INT16_C( 20573), INT16_C(-14964), INT16_C( 25607),
                            INT16_C(-28815), INT16_C(-28739), INT16_C( 27147), INT16_C( -3265)),
      simde_mm512_set_epi16(INT16_C(-10155), INT16_C(-12697), INT16_C( -5222), INT16_C(-32377),
                            INT16_C( 32076), INT16_C(-13716), INT16_C( 13383), INT16_C(-22332),
                            INT16_C( 18058), INT16_C(-22719), INT16_C( -8799), INT16_C(-25251),
                            INT16_C(-16195), INT16_C(-26213), INT16_C(-12331), INT16_C( 27016),
                            INT16_C( -5538), INT16_C( -4084), INT16_C(-28159), INT16_C(-27845),
                            INT16_C(  -742), INT16_C(  6696), INT16_C(  3074), INT16_C( -6511),
                            INT16_C(-21911), INT16_C( 28576), INT16_C(-29494), INT16_C(-22820),
                            INT16_C(-17599), INT16_C( -1341), INT16_C(  8579), INT16_C(   676)),
      simde_mm512_set_epi16(INT16_C(  6592), INT16_C( -1828), INT16_C( -2683), INT16_C( -8015),
                            INT16_C(-22131), INT16_C(  4602), INT16_C( -8130), INT16_C(  9770),
                            INT16_C(  4118), INT16_C( -9718), INT16_C(  6621), INT16_C( -7897),
                            INT16_C(  5807), INT16_C( -6168), INT16_C(  3206), INT16_C(-26793),
                            INT16_C(  4314), INT16_C(   763), INT16_C(  5811), INT16_C( 17016),
                            INT16_C(  -276), INT16_C( -5369), INT16_C( -2062), INT16_C(  -933),
                            INT16_C(  8533), INT16_C( 20573), INT16_C(-14964), INT16_C(  2787),
                            INT16_C(-11216), INT16_C(  -578), INT16_C(  1410), INT16_C(  -561)) },
    { simde_mm512_set_epi16(INT16_C(  7566), INT16_C( 25511), INT16_C( -5831), INT16_C( 13989),
                            INT16_C( 13965), INT16_C(-31065), INT16_C(    77), INT16_C(-30384),
                            INT16_C( 21705), INT16_C(-23032), INT16_C( -2503), INT16_C( -8652),
                            INT16_C(-23147), INT16_C( -4009), INT16_C(  7598), INT16_C( 23051),
                            INT16_C( 13886), INT16_C( 28688), INT16_C( 30551), INT16_C(-28928),
                            INT16_C( -9491), INT16_C(-26549), INT16_C(  -738), INT16_C( 22350),
                            INT16_C(  7981), INT16_C(-15059), INT16_C(-18848), INT16_C( 16804),
                            INT16_C(-31876), INT16_C( -1787), INT16_C( 29649), INT16_C(  -721)),
      simde_mm512_set_epi16(INT16_C( 18409), INT16_C( 19069), INT16_C( 20979), INT16_C(-29762),
                            INT16_C(  8112), INT16_C( 25085), INT16_C( 31664), INT16_C(-10132),
                            INT16_C( -2207), INT16_C( 19403), INT16_C(-32530), INT16_C( 20365),
                            INT16_C( 22045), INT16_C(-23601), INT16_C( 28665), INT16_C(-29743),
                            INT16_C( 26789), INT16_C(-25295), INT16_C(-31460), INT16_C(-29347),
                            INT16_C(-16029), INT16_C(-32645), INT16_C(-19836), INT16_C( 31541),
                            INT16_C(-32299), INT16_C(-14817), INT16_C( 22782), INT16_C(-18634),
                            INT16_C( -2744), INT16_C(   907), INT16_C(  9939), INT16_C(   395)),
      simde_mm512_set_epi16(INT16_C(  7566), INT16_C(  6442), INT16_C( -5831), INT16_C( 13989),
                            INT16_C(  5853), INT16_C( -5980), INT16_C(    77), INT16_C(-10120),
                            INT16_C(  1842), INT16_C( -3629), INT16_C( -2503), INT16_C( -8652),
                            INT16_C( -1102), INT16_C( -4009), INT16_C(  7598), INT16_C( 23051),
                            INT16_C( 13886), INT16_C(  3393), INT16_C( 30551), INT16_C(-28928),
                            INT16_C( -9491), INT16_C(-26549), INT16_C(  -738), INT16_C( 22350),
                            INT16_C(  7981), INT16_C(  -242), INT16_C(-18848), INT16_C( 16804),
                            INT16_C( -1692), INT16_C(  -880), INT16_C(  9771), INT16_C(  -326)) },
    { simde_mm512_set_epi16(INT16_C(-24983), INT16_C(  9260), INT16_C(  6846), INT16_C( 21618),
                            INT16_C( 20365), INT16_C( 26413), INT16_C(  7670), INT16_C(  6521),
                            INT16_C( 13052), INT16_C( 19892), INT16_C(-25515), INT16_C( -7444),
                            INT16_C( 12337), INT16_C( 14080), INT16_C(  6934), INT16_C( -4021),
                            INT16_C(  1885), INT16_C( 11733), INT16_C(  7371), INT16_C( 24583),
                            INT16_C(-17187), INT16_C(-28061), INT16_C(-18330), INT16_C(-10845),
                            INT16_C( -2076), INT16_C(  2107), INT16_C( -3367), INT16_C(-26728),
                            INT16_C( 21341), INT16_C(-13702), INT16_C( 26283), INT16_C(-27301)),
      simde_mm512_set_epi16(INT16_C(  9227), INT16_C( 20728), INT16_C( 22448), INT16_C( 22271),
                            INT16_C(-27526), INT16_C(  3228), INT16_C(-26938), INT16_C( 15839),
                            INT16_C(  4554), INT16_C( 22831), INT16_C(-21433), INT16_C( 32351),
                            INT16_C(-18789), INT16_C( 20983), INT16_C( -3647), INT16_C( 26454),
                            INT16_C( -2225), INT16_C( 19804), INT16_C( -2763), INT16_C( -8730),
                            INT16_C(-29152), INT16_C( 25302), INT16_C(-28393), INT16_C(  3478),
                            INT16_C( -5675), INT16_C( -4361), INT16_C(-16878), INT16_C( 23119),
                            INT16_C( 30252), INT16_C( -2420), INT16_C( 13170), INT16_C(-21449)),
      simde_mm512_set_epi16(INT16_C( -6529), INT16_C(  9260), INT16_C(  6846), INT16_C( 21618),
                            INT16_C( 20365), INT16_C(   589), INT16_C(  7670), INT16_C(  6521),
                            INT16_C(  3944), INT16_C( 19892), INT16_C( -4082), INT16_C( -7444),
                            INT16_C( 12337), INT16_C( 14080), INT16_C(  3287), INT16_C( -4021),
                            INT16_C(  1885), INT16_C( 11733), INT16_C(  1845), INT16_C(  7123),
                            INT16_C(-17187), INT16_C( -2759), INT16_C(-18330), INT16_C(  -411),
                            INT16_C( -2076), INT16_C(  2107), INT16_C( -3367), INT16_C( -3609),
                            INT16_C( 21341), INT16_C( -1602), INT16_C( 13113), INT16_C( -5852)) },
    { simde_mm512_set_epi16(INT16_C( 22335), INT16_C( 12112), INT16_C(  9189), INT16_C(  1311),
                            INT16_C( -7095), INT16_C( 13615), INT16_C(-21824), INT16_C( 31469),
                            INT16_C( 12162), INT16_C( -9370), INT16_C(-23767), INT16_C(-15401),
                            INT16_C(-14538), INT16_C( 24958), INT16_C(  2725), INT16_C(-25768),
                            INT16_C(-18369), INT16_C( 24484), INT16_C( 16711), INT16_C(-20904),
                            INT16_C(-18546), INT16_C( 25102), INT16_C(  6573), INT16_C( 22274),
                            INT16_C(-16497), INT16_C(-26622), INT16_C( 32256), INT16_C(-24007),
                            INT16_C( -2780), INT16_C( -4298), INT16_C(  8613), INT16_C(-14508)),
      simde_mm512_set_epi16(INT16_C( 30472), INT16_C(-28763), INT16_C(  7714), INT16_C( 18947),
                            INT16_C(  7066), INT16_C(-17692), INT16_C( -6885), INT16_C(  1841),
                            INT16_C(-29737), INT16_C(-14957), INT16_C(-32610), INT16_C( 26598),
                            INT16_C(-25999), INT16_C( -4399), INT16_C(  5946), INT16_C(  2262),
                            INT16_C( -5420), INT16_C( 12953), INT16_C(-27491), INT16_C(-17749),
                            INT16_C( 30618), INT16_C(-27725), INT16_C(-13788), INT16_C(-13300),
                            INT16_C( 23394), INT16_C(  2441), INT16_C( 32382), INT16_C(  9384),
                            INT16_C( 25792), INT16_C( -9373), INT16_C( 22658), INT16_C( 20939)),
      simde_mm512_set_epi16(INT16_C( 22335), INT16_C( 12112), INT16_C(  1475), INT16_C(  1311),
                            INT16_C(   -29), INT16_C( 13615), INT16_C( -1169), INT16_C(   172),
                            INT16_C( 12162), INT16_C( -9370), INT16_C(-23767), INT16_C(-15401),
                            INT16_C(-14538), INT16_C(  2963), INT16_C(  2725), INT16_C(  -886),
                            INT16_C( -2109), INT16_C( 11531), INT16_C( 16711), INT16_C( -3155),
                            INT16_C(-18546), INT16_C( 25102), INT16_C(  6573), INT16_C(  8974),
                            INT16_C(-16497), INT16_C( -2212), INT16_C( 32256), INT16_C( -5239),
                            INT16_C( -2780), INT16_C( -4298), INT16_C(  8613), INT16_C(-14508)) },
    { simde_mm512_set_epi16(INT16_C( 13867), INT16_C( 28091), INT16_C(-30146), INT16_C( -8550),
                            INT16_C( 31509), INT16_C( -2205), INT16_C(  9520), INT16_C( 29929),
                            INT16_C( 24571), INT16_C(-27795), INT16_C(-12850), INT16_C( 14609),
                            INT16_C( 31001), INT16_C(   823), INT16_C(-19839), INT16_C(-27185),
                            INT16_C(-29756), INT16_C(-24530), INT16_C(  3633), INT16_C(-20036),
                            INT16_C( 30184), INT16_C( 27396), INT16_C(  1171), INT16_C( 25936),
                            INT16_C( -3833), INT16_C( -7750), INT16_C( 19453), INT16_C( 30002),
                            INT16_C(  6315), INT16_C(   244), INT16_C(  8399), INT16_C( -8080)),
      simde_mm512_set_epi16(INT16_C( 18752), INT16_C( 27431), INT16_C(-11832), INT16_C(-22911),
                            INT16_C(-22667), INT16_C(-23791), INT16_C(-17993), INT16_C( 11401),
                            INT16_C( 26966), INT16_C( 26500), INT16_C(  7486), INT16_C(  7825),
                            INT16_C( 17767), INT16_C( -7030), INT16_C(-29302), INT16_C(-27163),
                            INT16_C(-10544), INT16_C(-18630), INT16_C(-13432), INT16_C( 31285),
                            INT16_C(-30604), INT16_C( 29467), INT16_C(-31755), INT16_C(   883),
                            INT16_C( 23995), INT16_C(-22467), INT16_C(-11949), INT16_C( 11327),
                            INT16_C(-28925), INT16_C(  7518), INT16_C( 30015), INT16_C( 30285)),
      simde_mm512_set_epi16(INT16_C( 13867), INT16_C(   660), INT16_C( -6482), INT16_C( -8550),
                            INT16_C(  8842), INT16_C( -2205), INT16_C(  9520), INT16_C(  7127),
                            INT16_C( 24571), INT16_C( -1295), INT16_C( -5364), INT16_C(  6784),
                            INT16_C( 13234), INT16_C(   823), INT16_C(-19839), INT16_C(   -22),
                            INT16_C( -8668), INT16_C( -5900), INT16_C(  3633), INT16_C(-20036),
                            INT16_C( 30184), INT16_C( 27396), INT16_C(  1171), INT16_C(   329),
                            INT16_C( -3833), INT16_C( -7750), INT16_C(  7504), INT16_C(  7348),
                            INT16_C(  6315), INT16_C(   244), INT16_C(  8399), INT16_C( -8080)) },
    { simde_mm512_set_epi16(INT16_C( 19003), INT16_C( 26627), INT16_C( -1831), INT16_C(-31318),
                            INT16_C(-29481), INT16_C( 13847), INT16_C(-20911), INT16_C(  9042),
                            INT16_C(-29388), INT16_C( 11660), INT16_C( 32339), INT16_C(-25821),
                            INT16_C(-18358), INT16_C( 21002), INT16_C( -4830), INT16_C(  8527),
                            INT16_C( 26072), INT16_C( 29611), INT16_C( 18348), INT16_C(   953),
                            INT16_C(-32154), INT16_C( 22717), INT16_C(-15414), INT16_C(-13122),
                            INT16_C( -6258), INT16_C(-11311), INT16_C( 31952), INT16_C( 29752),
                            INT16_C(-28048), INT16_C( 20614), INT16_C(  1055), INT16_C( -4387)),
      simde_mm512_set_epi16(INT16_C( -5809), INT16_C(  3072), INT16_C(  8626), INT16_C( 14922),
                            INT16_C( -1420), INT16_C(-29164), INT16_C( 22591), INT16_C(  8828),
                            INT16_C( -1488), INT16_C( -8728), INT16_C( -8885), INT16_C(-25776),
                            INT16_C( -5719), INT16_C(-14622), INT16_C( 21275), INT16_C(-30430),
                            INT16_C(  6020), INT16_C( 27245), INT16_C(-30773), INT16_C( 25208),
                            INT16_C( 25908), INT16_C( 21036), INT16_C(-29170), INT16_C( 25589),
                            INT16_C(  2188), INT16_C(-29317), INT16_C( -9309), INT16_C(-15127),
                            INT16_C(  8889), INT16_C( -7060), INT16_C( 24556), INT16_C( 24873)),
      simde_mm512_set_epi16(INT16_C(  1576), INT16_C(  2051), INT16_C( -1831), INT16_C( -1474),
                            INT16_C( -1081), INT16_C( 13847), INT16_C(-20911), INT16_C(   214),
                            INT16_C( -1116), INT16_C(  2932), INT16_C(  5684), INT16_C(   -45),
                            INT16_C( -1201), INT16_C(  6380), INT16_C( -4830), INT16_C(  8527),
                            INT16_C(  1992), INT16_C(  2366), INT16_C( 18348), INT16_C(   953),
                            INT16_C( -6246), INT16_C(  1681), INT16_C(-15414), INT16_C(-13122),
                            INT16_C( -1882), INT16_C(-11311), INT16_C(  4025), INT16_C( 14625),
                            INT16_C( -1381), INT16_C(  6494), INT16_C(  1055), INT16_C( -4387)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_rem_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m512i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_rem_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512i a;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {
    { simde_mm512_set_epi32(INT32_C(  691121094), INT32_C(  674034227), INT32_C(-1965434887), INT32_C( -920286947),
                            INT32_C( -374673026), INT32_C(-1240805178), INT32_C( 1568850865), INT32_C(-1142977539),
                            INT32_C(-1079516608), INT32_C( -708153743), INT32_C( 1508722402), INT32_C(-2074345640),
                            INT32_C( 1747596798), INT32_C(-2063703989), INT32_C(  527472553), INT32_C(-1403096998)),
      simde_mm512_set_epi32(INT32_C(-1764810870), INT32_C( 1179683687), INT32_C(-1646326602), INT32_C( -671967289),
                            INT32_C(-1586327268), INT32_C( 1691051285), INT32_C(   50347892), INT32_C(  728425428),
                            INT32_C( 1192263444), INT32_C(-2086343723), INT32_C( 1322777130), INT32_C(  163989560),
                            INT32_C( 1492341726), INT32_C(  298608154), INT32_C( 1250819173), INT32_C( -650971253)),
      simde_mm512_set_epi32(INT32_C(  691121094), INT32_C(  674034227), INT32_C( -319108285), INT32_C( -248319658),
                            INT32_C( -374673026), INT32_C(-1240805178), INT32_C(    8066213), INT32_C( -414552111),
                            INT32_C(-1079516608), INT32_C( -708153743), INT32_C(  185945272), INT32_C( -106470920),
                            INT32_C(  255255072), INT32_C( -272055065), INT32_C(  527472553), INT32_C( -101154492)) },
    { simde_mm512_set_epi32(INT32_C( 1314482530), INT32_C(-1297250617), INT32_C( -739008036), INT32_C(-1419039999),
                            INT32_C(-1004264650), INT32_C( 1580565751), INT32_C( -471064457), INT32_C( 2081361826),
                            INT32_C(  493161721), INT32_C(-1195115819), INT32_C(  894221337), INT32_C(-1330460172),
                            INT32_C(  492373082), INT32_C(  -13096811), INT32_C(-2087181083), INT32_C( -341007878)),
      simde_mm512_set_epi32(INT32_C(-1138893231), INT32_C( -687161637), INT32_C( 1828175063), INT32_C( -389420023),
                            INT32_C( -193211433), INT32_C( -857989172), INT32_C( -448329300), INT32_C(-1601364212),
                            INT32_C( 1710148738), INT32_C( 1974123080), INT32_C(-1424367196), INT32_C(  118588227),
                            INT32_C(  542053192), INT32_C(  499863549), INT32_C(  957375358), INT32_C(-1291033589)),
      simde_mm512_set_epi32(INT32_C(  175589299), INT32_C( -610088980), INT32_C( -739008036), INT32_C( -250779930),
                            INT32_C(  -38207485), INT32_C(  722576579), INT32_C(  -22735157), INT32_C(  479997614),
                            INT32_C(  493161721), INT32_C(-1195115819), INT32_C(  894221337), INT32_C(  -25989675),
                            INT32_C(  492373082), INT32_C(  -13096811), INT32_C( -172430367), INT32_C( -341007878)) },
    { simde_mm512_set_epi32(INT32_C( 1763100483), INT32_C( -518004559), INT32_C(-1450358898), INT32_C(-1409866198),
                            INT32_C(  269910347), INT32_C(  433971495), INT32_C( 1441956227), INT32_C( 1018271575),
                            INT32_C( 1734496959), INT32_C(  380846712), INT32_C( -941967689), INT32_C( -739443621),
                            INT32_C( 1995198557), INT32_C( -980655097), INT32_C(-1888383043), INT32_C( 1779168063)),
      simde_mm512_set_epi32(INT32_C( -665465241), INT32_C( -342195833), INT32_C( 2102184556), INT32_C(  877111492),
                            INT32_C( 1183491905), INT32_C( -576610979), INT32_C(-1061316197), INT32_C( -808097400),
                            INT32_C( -362876916), INT32_C(-1845390533), INT32_C(  -48621016), INT32_C(  201516689),
                            INT32_C(-1435930720), INT32_C(-1932876068), INT32_C(-1153303869), INT32_C(  562234020)),
      simde_mm512_set_epi32(INT32_C(  432170001), INT32_C( -175808726), INT32_C(-1450358898), INT32_C( -532754706),
                            INT32_C(  269910347), INT32_C(  433971495), INT32_C(  380640030), INT32_C(  210174175),
                            INT32_C(  282989295), INT32_C(  380846712), INT32_C(  -18168385), INT32_C( -134893554),
                            INT32_C(  559267837), INT32_C( -980655097), INT32_C( -735079174), INT32_C(   92466003)) },
    { simde_mm512_set_epi32(INT32_C(  495870887), INT32_C( -382126427), INT32_C(  915244711), INT32_C(    5081424),
                            INT32_C( 1422501384), INT32_C( -163979724), INT32_C(-1516900265), INT32_C(  497965579),
                            INT32_C(  910061584), INT32_C( 2002226944), INT32_C( -621963189), INT32_C(  -48343218),
                            INT32_C(  523093293), INT32_C(-1235205724), INT32_C(-2088961787), INT32_C( 1943141679)),
      simde_mm512_set_epi32(INT32_C( 1206471293), INT32_C( 1374915518), INT32_C(  531653117), INT32_C( 2075187308),
                            INT32_C( -144618549), INT32_C(-2131865715), INT32_C( 1444783055), INT32_C( 1878625233),
                            INT32_C( 1755684145), INT32_C(-2061726371), INT32_C(-1050443653), INT32_C(-1299940555),
                            INT32_C(-2116696545), INT32_C( 1493088054), INT32_C( -179829877), INT32_C(  651362699)),
      simde_mm512_set_epi32(INT32_C(  495870887), INT32_C( -382126427), INT32_C(  383591594), INT32_C(    5081424),
                            INT32_C(  120934443), INT32_C( -163979724), INT32_C(  -72117210), INT32_C(  497965579),
                            INT32_C(  910061584), INT32_C( 2002226944), INT32_C( -621963189), INT32_C(  -48343218),
                            INT32_C(  523093293), INT32_C(-1235205724), INT32_C( -110833140), INT32_C(  640416281)) },
    { simde_mm512_set_epi32(INT32_C(-1637276628), INT32_C(  448681074), INT32_C( 1334667053), INT32_C(  502667641),
                            INT32_C(  855395764), INT32_C(-1672092948), INT32_C(  808531712), INT32_C(  454488139),
                            INT32_C(  123547093), INT32_C(  483090439), INT32_C(-1126329757), INT32_C(-1201220189),
                            INT32_C( -136050629), INT32_C( -220620904), INT32_C( 1398655610), INT32_C( 1722520923)),
      simde_mm512_set_epi32(INT32_C(  604721400), INT32_C( 1471174399), INT32_C(-1803940708), INT32_C(-1765392929),
                            INT32_C(  298473775), INT32_C(-1404600737), INT32_C(-1231334921), INT32_C( -238983338),
                            INT32_C( -145797796), INT32_C( -181019162), INT32_C(-1910480170), INT32_C(-1860760170),
                            INT32_C( -371855625), INT32_C(-1106093489), INT32_C( 1982658188), INT32_C(  863153207)),
      simde_mm512_set_epi32(INT32_C( -427833828), INT32_C(  448681074), INT32_C( 1334667053), INT32_C(  502667641),
                            INT32_C(  258448214), INT32_C( -267492211), INT32_C(  808531712), INT32_C(  215504801),
                            INT32_C(  123547093), INT32_C(  121052115), INT32_C(-1126329757), INT32_C(-1201220189),
                            INT32_C( -136050629), INT32_C( -220620904), INT32_C( 1398655610), INT32_C(  859367716)) },
    { simde_mm512_set_epi32(INT32_C( 1463758672), INT32_C(  602211615), INT32_C( -464964305), INT32_C(-1430226195),
                            INT32_C(  797104998), INT32_C(-1557543977), INT32_C( -952737410), INT32_C(  178625368),
                            INT32_C(-1203806300), INT32_C( 1095216728), INT32_C(-1215405554), INT32_C(  430790402),
                            INT32_C(-1081108478), INT32_C( 2113970745), INT32_C( -182128842), INT32_C(  564512596)),
      simde_mm512_set_epi32(INT32_C( 1997049765), INT32_C(  505563651), INT32_C(  463125220), INT32_C( -451213519),
                            INT32_C(-1948793453), INT32_C(-2137102362), INT32_C(-1703809327), INT32_C(  389679318),
                            INT32_C( -355192167), INT32_C(-1801602389), INT32_C( 2006619059), INT32_C( -903558132),
                            INT32_C( 1533151625), INT32_C( 2122196136), INT32_C( 1690360675), INT32_C( 1484935627)),
      simde_mm512_set_epi32(INT32_C( 1463758672), INT32_C(   96647964), INT32_C(   -1839085), INT32_C(  -76585638),
                            INT32_C(  797104998), INT32_C(-1557543977), INT32_C( -952737410), INT32_C(  178625368),
                            INT32_C( -138229799), INT32_C( 1095216728), INT32_C(-1215405554), INT32_C(  430790402),
                            INT32_C(-1081108478), INT32_C( 2113970745), INT32_C( -182128842), INT32_C(  564512596)) },
    { simde_mm512_set_epi32(INT32_C(  908815803), INT32_C(-1975591270), INT32_C( 2065037155), INT32_C(  623932649),
                            INT32_C( 1610322797), INT32_C( -842122991), INT32_C( 2031682359), INT32_C(-1300130353),
                            INT32_C(-1950048210), INT32_C(  238137788), INT32_C( 1978166020), INT32_C(   76768592),
                            INT32_C( -251141702), INT32_C( 1274901810), INT32_C(  413860084), INT32_C(  550494320)),
      simde_mm512_set_epi32(INT32_C( 1228958503), INT32_C( -775379327), INT32_C(-1485462767), INT32_C(-1179177847),
                            INT32_C( 1767270276), INT32_C(  490610321), INT32_C( 1164436618), INT32_C(-1920297499),
                            INT32_C( -690964678), INT32_C( -880248267), INT32_C(-2005634277), INT32_C(-2081094797),
                            INT32_C( 1572579389), INT32_C( -783078337), INT32_C(-1895621282), INT32_C( 1967093325)),
      simde_mm512_set_epi32(INT32_C(  908815803), INT32_C( -424832616), INT32_C(  579574388), INT32_C(  623932649),
                            INT32_C( 1610322797), INT32_C( -351512670), INT32_C(  867245741), INT32_C(-1300130353),
                            INT32_C( -568118854), INT32_C(  238137788), INT32_C( 1978166020), INT32_C(   76768592),
                            INT32_C( -251141702), INT32_C(  491823473), INT32_C(  413860084), INT32_C(  550494320)) },
    { simde_mm512_set_epi32(INT32_C( 1245407235), INT32_C( -119962198), INT32_C(-1932052969), INT32_C(-1370414254),
                            INT32_C(-1925960308), INT32_C( 2119408419), INT32_C(-1203088886), INT32_C( -316530353),
                            INT32_C( 1708684203), INT32_C( 1202455481), INT32_C(-2107221827), INT32_C(-1010119490),
                            INT32_C( -410070063), INT32_C( 2094036024), INT32_C(-1838133114), INT32_C(   69201629)),
      simde_mm512_set_epi32(INT32_C( -380695552), INT32_C(  565328458), INT32_C(  -93024748), INT32_C( 1480532604),
                            INT32_C(  -97460760), INT32_C( -582247600), INT32_C( -374749470), INT32_C( 1394313506),
                            INT32_C(  394553965), INT32_C(-2016714120), INT32_C( 1697927724), INT32_C(-1911659531),
                            INT32_C(  143428987), INT32_C( -610024215), INT32_C(  582607980), INT32_C( 1609326889)),
      simde_mm512_set_epi32(INT32_C(  103320579), INT32_C( -119962198), INT32_C(  -71558009), INT32_C(-1370414254),
                            INT32_C(  -74205868), INT32_C(  372665619), INT32_C(  -78840476), INT32_C( -316530353),
                            INT32_C(  130468343), INT32_C( 1202455481), INT32_C( -409294103), INT32_C(-1010119490),
                            INT32_C( -123212089), INT32_C(  263963379), INT32_C(  -90309174), INT32_C(   69201629)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_rem_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m512i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_mask_rem_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512i src;
    simde__mmask16 k;
    simde__m512i a;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {
    { simde_mm512_set_epi32(INT32_C(  691121094), INT32_C(  674034227), INT32_C(-1965434887), INT32_C( -920286947),
                            INT32_C( -374673026), INT32_C(-1240805178), INT32_C( 1568850865), INT32_C(-1142977539),
                            INT32_C(-1079516608), INT32_C( -708153743), INT32_C( 1508722402), INT32_C(-2074345640),
                            INT32_C( 1747596798), INT32_C(-2063703989), INT32_C(  527472553), INT32_C(-1403096998)),
      UINT16_C(63371),
      simde_mm512_set_epi32(INT32_C( -341007878), INT32_C(-1764810870), INT32_C( 1179683687), INT32_C(-1646326602),
                            INT32_C( -671967289), INT32_C(-1586327268), INT32_C( 1691051285), INT32_C(   50347892),
                            INT32_C(  728425428), INT32_C( 1192263444), INT32_C(-2086343723), INT32_C( 1322777130),
                            INT32_C(  163989560), INT32_C( 1492341726), INT32_C(  298608154), INT32_C( 1250819173)),
      simde_mm512_set_epi32(INT32_C(-1291033589), INT32_C( 1314482530), INT32_C(-1297250617), INT32_C( -739008036),
                            INT32_C(-1419039999), INT32_C(-1004264650), INT32_C( 1580565751), INT32_C( -471064457),
                            INT32_C( 2081361826), INT32_C(  493161721), INT32_C(-1195115819), INT32_C(  894221337),
                            INT32_C(-1330460172), INT32_C(  492373082), INT32_C(  -13096811), INT32_C(-2087181083)),
      simde_mm512_set_epi32(INT32_C( -341007878), INT32_C( -450328340), INT32_C( 1179683687), INT32_C( -168310530),
                            INT32_C( -374673026), INT32_C( -582062618), INT32_C(  110485534), INT32_C(   50347892),
                            INT32_C(  728425428), INT32_C( -708153743), INT32_C( 1508722402), INT32_C(-2074345640),
                            INT32_C(  163989560), INT32_C(-2063703989), INT32_C(   10478312), INT32_C( 1250819173)) },
    { simde_mm512_set_epi32(INT32_C( 1779168063), INT32_C(-1138893231), INT32_C( -687161637), INT32_C( 1828175063),
                            INT32_C( -389420023), INT32_C( -193211433), INT32_C( -857989172), INT32_C( -448329300),
                            INT32_C(-1601364212), INT32_C( 1710148738), INT32_C( 1974123080), INT32_C(-1424367196),
                            INT32_C(  118588227), INT32_C(  542053192), INT32_C(  499863549), INT32_C(  957375358)),
      UINT16_C(36797),
      simde_mm512_set_epi32(INT32_C(-1153303869), INT32_C(  562234020), INT32_C( 1763100483), INT32_C( -518004559),
                            INT32_C(-1450358898), INT32_C(-1409866198), INT32_C(  269910347), INT32_C(  433971495),
                            INT32_C( 1441956227), INT32_C( 1018271575), INT32_C( 1734496959), INT32_C(  380846712),
                            INT32_C( -941967689), INT32_C( -739443621), INT32_C( 1995198557), INT32_C( -980655097)),
      simde_mm512_set_epi32(INT32_C(-2088961787), INT32_C( 1943141679), INT32_C( -665465241), INT32_C( -342195833),
                            INT32_C( 2102184556), INT32_C(  877111492), INT32_C( 1183491905), INT32_C( -576610979),
                            INT32_C(-1061316197), INT32_C( -808097400), INT32_C( -362876916), INT32_C(-1845390533),
                            INT32_C(  -48621016), INT32_C(  201516689), INT32_C(-1435930720), INT32_C(-1932876068)),
      simde_mm512_set_epi32(INT32_C(-1153303869), INT32_C(-1138893231), INT32_C( -687161637), INT32_C( 1828175063),
                            INT32_C(-1450358898), INT32_C( -532754706), INT32_C(  269910347), INT32_C(  433971495),
                            INT32_C(  380640030), INT32_C( 1710148738), INT32_C(  282989295), INT32_C(  380846712),
                            INT32_C(  -18168385), INT32_C( -134893554), INT32_C(  499863549), INT32_C( -980655097)) },
    { simde_mm512_set_epi32(INT32_C( -179829877), INT32_C(  651362699), INT32_C(  495870887), INT32_C( -382126427),
                            INT32_C(  915244711), INT32_C(    5081424), INT32_C( 1422501384), INT32_C( -163979724),
                            INT32_C(-1516900265), INT32_C(  497965579), INT32_C(  910061584), INT32_C( 2002226944),
                            INT32_C( -621963189), INT32_C(  -48343218), INT32_C(  523093293), INT32_C(-1235205724)),
      UINT16_C(46902),
      simde_mm512_set_epi32(INT32_C( -220620904), INT32_C( 1398655610), INT32_C( 1722520923), INT32_C( 1206471293),
                            INT32_C( 1374915518), INT32_C(  531653117), INT32_C( 2075187308), INT32_C( -144618549),
                            INT32_C(-2131865715), INT32_C( 1444783055), INT32_C( 1878625233), INT32_C( 1755684145),
                            INT32_C(-2061726371), INT32_C(-1050443653), INT32_C(-1299940555), INT32_C(-2116696545)),
      simde_mm512_set_epi32(INT32_C(-1106093489), INT32_C( 1982658188), INT32_C(  863153207), INT32_C(-1637276628),
                            INT32_C(  448681074), INT32_C( 1334667053), INT32_C(  502667641), INT32_C(  855395764),
                            INT32_C(-1672092948), INT32_C(  808531712), INT32_C(  454488139), INT32_C(  123547093),
                            INT32_C(  483090439), INT32_C(-1126329757), INT32_C(-1201220189), INT32_C( -136050629)),
      simde_mm512_set_epi32(INT32_C( -220620904), INT32_C(  651362699), INT32_C(  859367716), INT32_C( 1206471293),
                            INT32_C(  915244711), INT32_C(  531653117), INT32_C(   64516744), INT32_C( -144618549),
                            INT32_C(-1516900265), INT32_C(  497965579), INT32_C(   60672677), INT32_C(   26024843),
                            INT32_C( -621963189), INT32_C(-1050443653), INT32_C(  -98720366), INT32_C(-1235205724)) },
    { simde_mm512_set_epi32(INT32_C( 2113970745), INT32_C( -182128842), INT32_C(  564512596), INT32_C(  604721400),
                            INT32_C( 1471174399), INT32_C(-1803940708), INT32_C(-1765392929), INT32_C(  298473775),
                            INT32_C(-1404600737), INT32_C(-1231334921), INT32_C( -238983338), INT32_C( -145797796),
                            INT32_C( -181019162), INT32_C(-1910480170), INT32_C(-1860760170), INT32_C( -371855625)),
      UINT16_C(38914),
      simde_mm512_set_epi32(INT32_C( 1533151625), INT32_C( 2122196136), INT32_C( 1690360675), INT32_C( 1484935627),
                            INT32_C( 1463758672), INT32_C(  602211615), INT32_C( -464964305), INT32_C(-1430226195),
                            INT32_C(  797104998), INT32_C(-1557543977), INT32_C( -952737410), INT32_C(  178625368),
                            INT32_C(-1203806300), INT32_C( 1095216728), INT32_C(-1215405554), INT32_C(  430790402)),
      simde_mm512_set_epi32(INT32_C( -251141702), INT32_C( 1274901810), INT32_C(  413860084), INT32_C(  550494320),
                            INT32_C( 1997049765), INT32_C(  505563651), INT32_C(  463125220), INT32_C( -451213519),
                            INT32_C(-1948793453), INT32_C(-2137102362), INT32_C(-1703809327), INT32_C(  389679318),
                            INT32_C( -355192167), INT32_C(-1801602389), INT32_C( 2006619059), INT32_C( -903558132)),
      simde_mm512_set_epi32(INT32_C(   26301413), INT32_C( -182128842), INT32_C(  564512596), INT32_C(  383946987),
                            INT32_C( 1463758672), INT32_C(-1803940708), INT32_C(-1765392929), INT32_C(  298473775),
                            INT32_C(-1404600737), INT32_C(-1231334921), INT32_C( -238983338), INT32_C( -145797796),
                            INT32_C( -181019162), INT32_C(-1910480170), INT32_C(-1215405554), INT32_C( -371855625)) },
    { simde_mm512_set_epi32(INT32_C( 1572579389), INT32_C( -783078337), INT32_C(-1895621282), INT32_C( 1967093325),
                            INT32_C(  908815803), INT32_C(-1975591270), INT32_C( 2065037155), INT32_C(  623932649),
                            INT32_C( 1610322797), INT32_C( -842122991), INT32_C( 2031682359), INT32_C(-1300130353),
                            INT32_C(-1950048210), INT32_C(  238137788), INT32_C( 1978166020), INT32_C(   76768592)),
      UINT16_C(  883),
      simde_mm512_set_epi32(INT32_C(-1010119490), INT32_C( -410070063), INT32_C( 2094036024), INT32_C(-1838133114),
                            INT32_C(   69201629), INT32_C( 1228958503), INT32_C( -775379327), INT32_C(-1485462767),
                            INT32_C(-1179177847), INT32_C( 1767270276), INT32_C(  490610321), INT32_C( 1164436618),
                            INT32_C(-1920297499), INT32_C( -690964678), INT32_C( -880248267), INT32_C(-2005634277)),
      simde_mm512_set_epi32(INT32_C(-1911659531), INT32_C(  143428987), INT32_C( -610024215), INT32_C(  582607980),
                            INT32_C( 1609326889), INT32_C( 1245407235), INT32_C( -119962198), INT32_C(-1932052969),
                            INT32_C(-1370414254), INT32_C(-1925960308), INT32_C( 2119408419), INT32_C(-1203088886),
                            INT32_C( -316530353), INT32_C( 1708684203), INT32_C( 1202455481), INT32_C(-2107221827)),
      simde_mm512_set_epi32(INT32_C( 1572579389), INT32_C( -783078337), INT32_C(-1895621282), INT32_C( 1967093325),
                            INT32_C(  908815803), INT32_C(-1975591270), INT32_C(  -55606139), INT32_C(-1485462767),
                            INT32_C( 1610322797), INT32_C( 1767270276), INT32_C(  490610321), INT32_C( 1164436618),
                            INT32_C(-1950048210), INT32_C(  238137788), INT32_C( -880248267), INT32_C(-2005634277)) },
    { simde_mm512_set_epi32(INT32_C( 2117071873), INT32_C(-1437889529), INT32_C( -376074104), INT32_C( 1087893388),
                            INT32_C( -443183285), INT32_C( -380695552), INT32_C(  565328458), INT32_C(  -93024748),
                            INT32_C( 1480532604), INT32_C(  -97460760), INT32_C( -582247600), INT32_C( -374749470),
                            INT32_C( 1394313506), INT32_C(  394553965), INT32_C(-2016714120), INT32_C( 1697927724)),
      UINT16_C(12254),
      simde_mm512_set_epi32(INT32_C(   56443211), INT32_C(-2036514643), INT32_C( -510270824), INT32_C( 1139427205),
                            INT32_C( 1090384090), INT32_C(-1905231405), INT32_C(-2079359983), INT32_C( -477294891),
                            INT32_C( -673197028), INT32_C( 2071747620), INT32_C( -442789099), INT32_C( -601334711),
                            INT32_C(  319530416), INT32_C(-2115012481), INT32_C( -501730903), INT32_C(  340519338)),
      simde_mm512_set_epi32(INT32_C( 1219537084), INT32_C( 1349635715), INT32_C(  732887738), INT32_C(-1728641921),
                            INT32_C(-1388433411), INT32_C( 1765754685), INT32_C(-1574983663), INT32_C(  846129112),
                            INT32_C( 1578410935), INT32_C(-1659872458), INT32_C( 1045536663), INT32_C(  957117985),
                            INT32_C(-1265958651), INT32_C( 1309498779), INT32_C(-1001015299), INT32_C( 1022360677)),
      simde_mm512_set_epi32(INT32_C( 2117071873), INT32_C(-1437889529), INT32_C( -510270824), INT32_C( 1087893388),
                            INT32_C( 1090384090), INT32_C( -139476720), INT32_C( -504376320), INT32_C( -477294891),
                            INT32_C( -673197028), INT32_C(  411875162), INT32_C( -582247600), INT32_C( -601334711),
                            INT32_C(  319530416), INT32_C( -805513702), INT32_C( -501730903), INT32_C( 1697927724)) },
    { simde_mm512_set_epi32(INT32_C( -304885978), INT32_C(  991545752), INT32_C( -143034937), INT32_C(  843112042),
                            INT32_C( -227554783), INT32_C( 2124182542), INT32_C(-1526246088), INT32_C(-1991977382),
                            INT32_C( 1224533822), INT32_C( -819361196), INT32_C( -684010252), INT32_C(-1738921185),
                            INT32_C(-1259570772), INT32_C( -691865929), INT32_C( -973523371), INT32_C(   45581573)),
      UINT16_C(42669),
      simde_mm512_set_epi32(INT32_C( -156799603), INT32_C(-1073012339), INT32_C(-2130532125), INT32_C(  397240391),
                            INT32_C(  200936922), INT32_C(-1030980309), INT32_C(-1758363174), INT32_C( -665586367),
                            INT32_C(  453331046), INT32_C( 1704580573), INT32_C( 1606190487), INT32_C(-1085658047),
                            INT32_C(-1335469644), INT32_C( -368070561), INT32_C(-1419559633), INT32_C( 2069966669)),
      simde_mm512_set_epi32(INT32_C( 1379668640), INT32_C(   66581512), INT32_C( -557301797), INT32_C(  304428974),
                            INT32_C(-1608262788), INT32_C(  532978979), INT32_C(  946958552), INT32_C(-1911324669),
                            INT32_C(-2118093156), INT32_C(  283691898), INT32_C( -446072631), INT32_C( -458781294),
                            INT32_C( 1951055651), INT32_C(  765387914), INT32_C(  822559116), INT32_C(    7445617)),
      simde_mm512_set_epi32(INT32_C( -156799603), INT32_C(  991545752), INT32_C( -458626734), INT32_C(  843112042),
                            INT32_C( -227554783), INT32_C( -498001330), INT32_C( -811404622), INT32_C(-1991977382),
                            INT32_C(  453331046), INT32_C( -819361196), INT32_C(  267972594), INT32_C(-1738921185),
                            INT32_C(-1335469644), INT32_C( -368070561), INT32_C( -973523371), INT32_C(      85143)) },
    { simde_mm512_set_epi32(INT32_C(-1981938926), INT32_C(  869237081), INT32_C( -190053534), INT32_C(-1469275330),
                            INT32_C( -717100794), INT32_C(-1303072888), INT32_C(-2122918671), INT32_C( 1617119933),
                            INT32_C( 1521363431), INT32_C(  553638116), INT32_C( 1036201367), INT32_C(-1187933851),
                            INT32_C( -412155886), INT32_C( -760582943), INT32_C( -423751457), INT32_C( 1273589632)),
      UINT16_C(35103),
      simde_mm512_set_epi32(INT32_C(-1836595644), INT32_C(  260676470), INT32_C( 1724614860), INT32_C( -144514633),
                            INT32_C( -478630580), INT32_C(-2086755061), INT32_C(  932145867), INT32_C(-1862372735),
                            INT32_C( 1756892633), INT32_C(  382632965), INT32_C( 1295078740), INT32_C( -995802034),
                            INT32_C(  152308919), INT32_C( -351555508), INT32_C(   31813624), INT32_C(  807463845)),
      simde_mm512_set_epi32(INT32_C(  615301803), INT32_C(  382786341), INT32_C( 1852603705), INT32_C( 1998007730),
                            INT32_C(  231325888), INT32_C( 1842039329), INT32_C(  968682756), INT32_C(  316335394),
                            INT32_C(-2071382094), INT32_C( -803185337), INT32_C(-2126995500), INT32_C( 1587647099),
                            INT32_C(-1328358584), INT32_C(  320339033), INT32_C(  282380179), INT32_C( -108102092)),
      simde_mm512_set_epi32(INT32_C( -605992038), INT32_C(  869237081), INT32_C( -190053534), INT32_C(-1469275330),
                            INT32_C(  -15978804), INT32_C(-1303072888), INT32_C(-2122918671), INT32_C( -280695765),
                            INT32_C( 1521363431), INT32_C(  553638116), INT32_C( 1036201367), INT32_C( -995802034),
                            INT32_C(  152308919), INT32_C(  -31216475), INT32_C(   31813624), INT32_C(   50749201)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_mask_rem_epi32(test_vec[i].src, test_vec[i].k, test_vec[i].a, test_vec[i].b);
    simde_assert_m512i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_rem_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512i a;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {
    { simde_mm512_set_epi64(INT64_C( 2968342496979776051), INT64_C(-8441478558707775203),
                            INT64_C(-1609208390309195578), INT64_C( 6738163160628300797),
                            INT64_C(-4636488523262038415), INT64_C( 6479913377553186648),
                            INT64_C( 7505871096235581515), INT64_C( 2265477367564496986)),
      simde_mm512_set_epi64(INT64_C(-7579804969095623833), INT64_C(-7070918910501808185),
                            INT64_C(-6813223735121976043), INT64_C(  216242550290965460),
                            INT64_C( 5120732502404950997), INT64_C( 5681284513410730040),
                            INT64_C( 6409558907924801050), INT64_C( 5372227444888762251)),
      simde_mm512_set_epi64(INT64_C( 2968342496979776051), INT64_C(-1370559648205967018),
                            INT64_C(-1609208390309195578), INT64_C(   34644101608371537),
                            INT64_C(-4636488523262038415), INT64_C(  798628864142456608),
                            INT64_C( 1096312188310780465), INT64_C( 2265477367564496986)) },
    { simde_mm512_set_epi64(INT64_C( 5645659480511055559), INT64_C(-3174015343225263359),
                            INT64_C(-4313283826698320649), INT64_C(-2023206435041636446),
                            INT64_C( 2118113466433927893), INT64_C( 3840651400764901876),
                            INT64_C( 2114726288902596757), INT64_C(-8964374488360902150)),
      simde_mm512_set_epi64(INT64_C(-4891509177172967717), INT64_C( 7851952110853286921),
                            INT64_C( -829836782511317044), INT64_C(-1925559678644969716),
                            INT64_C( 7345032902979795528), INT64_C(-6117610524196633789),
                            INT64_C( 2328100732832272381), INT64_C( 4111895855610225675)),
      simde_mm512_set_epi64(INT64_C(  754150303338087842), INT64_C(-3174015343225263359),
                            INT64_C( -164099914141735429), INT64_C(  -97646756396666730),
                            INT64_C( 2118113466433927893), INT64_C( 3840651400764901876),
                            INT64_C( 2114726288902596757), INT64_C( -740582777140450800)) },
    { simde_mm512_set_epi64(INT64_C( 7572458917823766705), INT64_C(-6229244031487498710),
                            INT64_C( 1159256113650983207), INT64_C( 6193154838246823767),
                            INT64_C( 7449607714297299576), INT64_C(-4045720414588175269),
                            INT64_C( 8569312554655704071), INT64_C(-8110543410226793665)),
      simde_mm512_set_epi64(INT64_C(-2858151442766986873), INT64_C( 9028813919053392068),
                            INT64_C( 5083059030774095197), INT64_C(-4558318353343223416),
                            INT64_C(-1558544484243762373), INT64_C( -208825673416776047),
                            INT64_C(-6167275479359641892), INT64_C(-4953402399143034204)),
      simde_mm512_set_epi64(INT64_C( 1856156032289792959), INT64_C(-6229244031487498710),
                            INT64_C( 1159256113650983207), INT64_C( 1634836484903600351),
                            INT64_C( 1215429777322250084), INT64_C(  -78032619669430376),
                            INT64_C( 2402037075296062179), INT64_C(-3157141011083759461)) },
    { simde_mm512_set_epi64(INT64_C( 2129749246616352421), INT64_C( 3930946101587052880),
                            INT64_C( 6109596926925725236), INT64_C(-6515037028970767861),
                            INT64_C( 3908684742628183808), INT64_C(-2671311551824242866),
                            INT64_C( 2246668589251707300), INT64_C(-8972022555815576273)),
      simde_mm512_set_epi64(INT64_C( 5181754748372749246), INT64_C( 2283432752406648940),
                            INT64_C( -621131936186871923), INT64_C( 6205295972918594513),
                            INT64_C( 7540605987113962845), INT64_C(-4511621132930745547),
                            INT64_C(-9091142434838104266), INT64_C( -772363439907339893)),
      simde_mm512_set_epi64(INT64_C( 2129749246616352421), INT64_C( 1647513349180403940),
                            INT64_C(  519409501243877929), INT64_C( -309741056052173348),
                            INT64_C( 3908684742628183808), INT64_C(-2671311551824242866),
                            INT64_C( 2246668589251707300), INT64_C( -476024716834837450)) },
    { simde_mm512_set_epi64(INT64_C(-7032049571316476814), INT64_C( 5732351344186366329),
                            INT64_C( 3673896834139808492), INT64_C( 3472617261273378891),
                            INT64_C(  530630724433960967), INT64_C(-4837549467732879965),
                            INT64_C( -584332998080882792), INT64_C( 6007180105039451483)),
      simde_mm512_set_epi64(INT64_C( 2597258637662508799), INT64_C(-7747866342253511201),
                            INT64_C( 1281935105229028959), INT64_C(-5288543212061759658),
                            INT64_C( -626196761534931482), INT64_C(-8205449847372313194),
                            INT64_C(-1597107745019766193), INT64_C( 8515452077469772855)),
      simde_mm512_set_epi64(INT64_C(-1837532295991459216), INT64_C( 5732351344186366329),
                            INT64_C( 1110026623681750574), INT64_C( 3472617261273378891),
                            INT64_C(  530630724433960967), INT64_C(-4837549467732879965),
                            INT64_C( -584332998080882792), INT64_C( 6007180105039451483)) },
    { simde_mm512_set_epi64(INT64_C( 6286795626078602527), INT64_C(-1997006480917628179),
                            INT64_C( 3423539900625568727), INT64_C(-4091976017447117992),
                            INT64_C(-5170308688123548072), INT64_C(-5220127105375971582),
                            INT64_C(-4643325554324364743), INT64_C( -782237419483838636)),
      simde_mm512_set_epi64(INT64_C( 8577263429665049091), INT64_C( 1989107677696558897),
                            INT64_C(-8370004145136048154), INT64_C(-7317805337695090474),
                            INT64_C(-1525538738567005525), INT64_C( 8618363237326703628),
                            INT64_C( 6584836091306452136), INT64_C( 7260043819054420427)),
      simde_mm512_set_epi64(INT64_C( 6286795626078602527), INT64_C(   -7898803221069282),
                            INT64_C( 3423539900625568727), INT64_C(-4091976017447117992),
                            INT64_C( -593692472422531497), INT64_C(-5220127105375971582),
                            INT64_C(-4643325554324364743), INT64_C( -782237419483838636)) },
    { simde_mm512_set_epi64(INT64_C( 3903334154292354714), INT64_C( 8869267046373815529),
                            INT64_C( 6916283752571091217), INT64_C( 8726009290759968207),
                            INT64_C(-8375393287335202372), INT64_C( 8496158362035250512),
                            INT64_C(-1078645395476875982), INT64_C( 1777515526450307184)),
      simde_mm512_set_epi64(INT64_C( 5278336582045705857), INT64_C(-6380014000574878583),
                            INT64_C( 7590368039103504017), INT64_C( 5001217194949514725),
                            INT64_C(-2967670691286451659), INT64_C(-8614133625237732493),
                            INT64_C( 6754177049630551103), INT64_C(-8141631409824500147)),
      simde_mm512_set_epi64(INT64_C( 3903334154292354714), INT64_C( 2489253045798936946),
                            INT64_C( 6916283752571091217), INT64_C( 3724792095810453482),
                            INT64_C(-2440051904762299054), INT64_C( 8496158362035250512),
                            INT64_C(-1078645395476875982), INT64_C( 1777515526450307184)) },
    { simde_mm512_set_epi64(INT64_C( 5348983348701791658), INT64_C(-8298104313070148782),
                            INT64_C(-8271936534134678749), INT64_C(-5167227415572635313),
                            INT64_C( 7338742772279280569), INT64_C(-9050448829097521986),
                            INT64_C(-1761237507559623624), INT64_C(-7894721610255438115)),
      simde_mm512_set_epi64(INT64_C(-1635074945007338934), INT64_C( -399538248898108804),
                            INT64_C( -418590773130585264), INT64_C(-1609536716449019614),
                            INT64_C( 1694596378460381816), INT64_C( 7292544047935022069),
                            INT64_C(  616022812148352233), INT64_C( 2502282222097948969)),
      simde_mm512_set_epi64(INT64_C(  443758513679774856), INT64_C( -307339335107972702),
                            INT64_C( -318711844653558733), INT64_C( -338617266225576471),
                            INT64_C(  560357258437753305), INT64_C(-1757904781162499917),
                            INT64_C( -529191883262919158), INT64_C( -387874943961591208)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_rem_epi64(test_vec[i].a, test_vec[i].b);
    simde_assert_m512i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_rem_epu8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512i a;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {
    { simde_x_mm512_set_epu8(UINT8_C( 41), UINT8_C( 49), UINT8_C(171), UINT8_C(198),
                             UINT8_C( 40), UINT8_C( 44), UINT8_C(242), UINT8_C( 51),
                             UINT8_C(138), UINT8_C(217), UINT8_C(215), UINT8_C(249),
                             UINT8_C(201), UINT8_C( 37), UINT8_C(137), UINT8_C( 29),
                             UINT8_C(233), UINT8_C(170), UINT8_C(241), UINT8_C(126),
                             UINT8_C(182), UINT8_C( 10), UINT8_C(208), UINT8_C(198),
                             UINT8_C( 93), UINT8_C(130), UINT8_C(195), UINT8_C(177),
                             UINT8_C(187), UINT8_C(223), UINT8_C(139), UINT8_C(253),
                             UINT8_C(191), UINT8_C(167), UINT8_C(226), UINT8_C( 64),
                             UINT8_C(213), UINT8_C(202), UINT8_C(110), UINT8_C(113),
                             UINT8_C( 89), UINT8_C(237), UINT8_C( 70), UINT8_C(226),
                             UINT8_C(132), UINT8_C( 91), UINT8_C(255), UINT8_C( 88),
                             UINT8_C(104), UINT8_C( 42), UINT8_C( 53), UINT8_C(254),
                             UINT8_C(132), UINT8_C(254), UINT8_C( 96), UINT8_C( 75),
                             UINT8_C( 31), UINT8_C(112), UINT8_C(151), UINT8_C(169),
                             UINT8_C(172), UINT8_C( 94), UINT8_C(112), UINT8_C( 90)),
      simde_x_mm512_set_epu8(UINT8_C(195), UINT8_C( 49), UINT8_C( 14), UINT8_C(170),
                             UINT8_C(203), UINT8_C(167), UINT8_C(  3), UINT8_C(215),
                             UINT8_C( 63), UINT8_C(248), UINT8_C( 55), UINT8_C(219),
                             UINT8_C(221), UINT8_C(135), UINT8_C( 61), UINT8_C(191),
                             UINT8_C(209), UINT8_C( 91), UINT8_C( 87), UINT8_C(137),
                             UINT8_C( 87), UINT8_C( 76), UINT8_C( 44), UINT8_C(140),
                             UINT8_C(  2), UINT8_C(200), UINT8_C( 36), UINT8_C(195),
                             UINT8_C(200), UINT8_C(125), UINT8_C(254), UINT8_C(139),
                             UINT8_C(226), UINT8_C( 71), UINT8_C( 92), UINT8_C(129),
                             UINT8_C(182), UINT8_C(119), UINT8_C(247), UINT8_C( 34),
                             UINT8_C(121), UINT8_C( 85), UINT8_C(153), UINT8_C(116),
                             UINT8_C(218), UINT8_C( 21), UINT8_C(101), UINT8_C(122),
                             UINT8_C( 10), UINT8_C(231), UINT8_C( 54), UINT8_C( 71),
                             UINT8_C(156), UINT8_C(149), UINT8_C(244), UINT8_C( 84),
                             UINT8_C(148), UINT8_C( 85), UINT8_C(170), UINT8_C(184),
                             UINT8_C( 94), UINT8_C(154), UINT8_C(229), UINT8_C( 11)),
      simde_x_mm512_set_epu8(UINT8_C( 41), UINT8_C(  0), UINT8_C(  3), UINT8_C( 28),
                             UINT8_C( 40), UINT8_C( 44), UINT8_C(  2), UINT8_C( 51),
                             UINT8_C( 12), UINT8_C(217), UINT8_C( 50), UINT8_C( 30),
                             UINT8_C(201), UINT8_C( 37), UINT8_C( 15), UINT8_C( 29),
                             UINT8_C( 24), UINT8_C( 79), UINT8_C( 67), UINT8_C(126),
                             UINT8_C(  8), UINT8_C( 10), UINT8_C( 32), UINT8_C( 58),
                             UINT8_C(  1), UINT8_C(130), UINT8_C( 15), UINT8_C(177),
                             UINT8_C(187), UINT8_C( 98), UINT8_C(139), UINT8_C(114),
                             UINT8_C(191), UINT8_C( 25), UINT8_C( 42), UINT8_C( 64),
                             UINT8_C( 31), UINT8_C( 83), UINT8_C(110), UINT8_C( 11),
                             UINT8_C( 89), UINT8_C( 67), UINT8_C( 70), UINT8_C(110),
                             UINT8_C(132), UINT8_C(  7), UINT8_C( 53), UINT8_C( 88),
                             UINT8_C(  4), UINT8_C( 42), UINT8_C( 53), UINT8_C( 41),
                             UINT8_C(132), UINT8_C(105), UINT8_C( 96), UINT8_C( 75),
                             UINT8_C( 31), UINT8_C( 27), UINT8_C(151), UINT8_C(169),
                             UINT8_C( 78), UINT8_C( 94), UINT8_C(112), UINT8_C(  2)) },
    { simde_x_mm512_set_epu8(UINT8_C(216), UINT8_C( 85), UINT8_C(206), UINT8_C(103),
                             UINT8_C(235), UINT8_C(154), UINT8_C(129), UINT8_C(135),
                             UINT8_C(125), UINT8_C( 76), UINT8_C(202), UINT8_C(108),
                             UINT8_C( 52), UINT8_C( 71), UINT8_C(168), UINT8_C(196),
                             UINT8_C( 70), UINT8_C(138), UINT8_C(167), UINT8_C( 65),
                             UINT8_C(221), UINT8_C(161), UINT8_C(157), UINT8_C( 93),
                             UINT8_C(192), UINT8_C(189), UINT8_C(153), UINT8_C(155),
                             UINT8_C(207), UINT8_C(213), UINT8_C(105), UINT8_C(136),
                             UINT8_C(234), UINT8_C( 94), UINT8_C(240), UINT8_C( 12),
                             UINT8_C(146), UINT8_C(  1), UINT8_C(147), UINT8_C( 59),
                             UINT8_C(253), UINT8_C( 26), UINT8_C( 26), UINT8_C( 40),
                             UINT8_C( 12), UINT8_C(  2), UINT8_C(230), UINT8_C(145),
                             UINT8_C(170), UINT8_C(105), UINT8_C(111), UINT8_C(160),
                             UINT8_C(140), UINT8_C(202), UINT8_C(166), UINT8_C(220),
                             UINT8_C(187), UINT8_C( 65), UINT8_C(250), UINT8_C(195),
                             UINT8_C( 33), UINT8_C(131), UINT8_C(  2), UINT8_C(164)),
      simde_x_mm512_set_epu8(UINT8_C(120), UINT8_C(127), UINT8_C( 28), UINT8_C( 95),
                             UINT8_C(175), UINT8_C(223), UINT8_C(119), UINT8_C(214),
                             UINT8_C(220), UINT8_C(102), UINT8_C( 86), UINT8_C( 22),
                             UINT8_C(119), UINT8_C(207), UINT8_C( 12), UINT8_C(183),
                             UINT8_C(172), UINT8_C(242), UINT8_C(173), UINT8_C(249),
                             UINT8_C( 52), UINT8_C(108), UINT8_C(128), UINT8_C(203),
                             UINT8_C( 85), UINT8_C(135), UINT8_C(227), UINT8_C( 35),
                             UINT8_C(187), UINT8_C( 24), UINT8_C(250), UINT8_C(219),
                             UINT8_C(253), UINT8_C( 62), UINT8_C(125), UINT8_C(236),
                             UINT8_C( 75), UINT8_C( 13), UINT8_C( 79), UINT8_C( 81),
                             UINT8_C(177), UINT8_C(221), UINT8_C(251), UINT8_C(181),
                             UINT8_C(159), UINT8_C(182), UINT8_C( 11), UINT8_C( 11),
                             UINT8_C( 39), UINT8_C( 37), UINT8_C( 39), UINT8_C(208),
                             UINT8_C(136), UINT8_C(180), UINT8_C(215), UINT8_C(139),
                             UINT8_C(144), UINT8_C(128), UINT8_C(203), UINT8_C(206),
                             UINT8_C(173), UINT8_C( 36), UINT8_C(133), UINT8_C(175)),
      simde_x_mm512_set_epu8(UINT8_C( 96), UINT8_C( 85), UINT8_C( 10), UINT8_C(  8),
                             UINT8_C( 60), UINT8_C(154), UINT8_C( 10), UINT8_C(135),
                             UINT8_C(125), UINT8_C( 76), UINT8_C( 30), UINT8_C( 20),
                             UINT8_C( 52), UINT8_C( 71), UINT8_C(  0), UINT8_C( 13),
                             UINT8_C( 70), UINT8_C(138), UINT8_C(167), UINT8_C( 65),
                             UINT8_C( 13), UINT8_C( 53), UINT8_C( 29), UINT8_C( 93),
                             UINT8_C( 22), UINT8_C( 54), UINT8_C(153), UINT8_C( 15),
                             UINT8_C( 20), UINT8_C( 21), UINT8_C(105), UINT8_C(136),
                             UINT8_C(234), UINT8_C( 32), UINT8_C(115), UINT8_C( 12),
                             UINT8_C( 71), UINT8_C(  1), UINT8_C( 68), UINT8_C( 59),
                             UINT8_C( 76), UINT8_C( 26), UINT8_C( 26), UINT8_C( 40),
                             UINT8_C( 12), UINT8_C(  2), UINT8_C( 10), UINT8_C(  2),
                             UINT8_C( 14), UINT8_C( 31), UINT8_C( 33), UINT8_C(160),
                             UINT8_C(  4), UINT8_C( 22), UINT8_C(166), UINT8_C( 81),
                             UINT8_C( 43), UINT8_C( 65), UINT8_C( 47), UINT8_C(195),
                             UINT8_C( 33), UINT8_C( 23), UINT8_C(  2), UINT8_C(164)) },
    { simde_x_mm512_set_epu8(UINT8_C( 87), UINT8_C( 63), UINT8_C( 47), UINT8_C( 80),
                             UINT8_C( 35), UINT8_C(229), UINT8_C(  5), UINT8_C( 31),
                             UINT8_C(228), UINT8_C( 73), UINT8_C( 53), UINT8_C( 47),
                             UINT8_C(170), UINT8_C(192), UINT8_C(122), UINT8_C(237),
                             UINT8_C( 47), UINT8_C(130), UINT8_C(219), UINT8_C(102),
                             UINT8_C(163), UINT8_C( 41), UINT8_C(195), UINT8_C(215),
                             UINT8_C(199), UINT8_C( 54), UINT8_C( 97), UINT8_C(126),
                             UINT8_C( 10), UINT8_C(165), UINT8_C(155), UINT8_C( 88),
                             UINT8_C(184), UINT8_C( 63), UINT8_C( 95), UINT8_C(164),
                             UINT8_C( 65), UINT8_C( 71), UINT8_C(174), UINT8_C( 88),
                             UINT8_C(183), UINT8_C(142), UINT8_C( 98), UINT8_C( 14),
                             UINT8_C( 25), UINT8_C(173), UINT8_C( 87), UINT8_C(  2),
                             UINT8_C(191), UINT8_C(143), UINT8_C(152), UINT8_C(  2),
                             UINT8_C(126), UINT8_C(  0), UINT8_C(162), UINT8_C( 57),
                             UINT8_C(245), UINT8_C( 36), UINT8_C(239), UINT8_C( 54),
                             UINT8_C( 33), UINT8_C(165), UINT8_C(199), UINT8_C( 84)),
      simde_x_mm512_set_epu8(UINT8_C(131), UINT8_C( 42), UINT8_C(151), UINT8_C(210),
                             UINT8_C( 12), UINT8_C(163), UINT8_C(138), UINT8_C(207),
                             UINT8_C( 43), UINT8_C( 57), UINT8_C( 61), UINT8_C( 62),
                             UINT8_C( 81), UINT8_C(184), UINT8_C(  6), UINT8_C( 93),
                             UINT8_C(167), UINT8_C(  1), UINT8_C(145), UINT8_C(  9),
                             UINT8_C(  4), UINT8_C( 17), UINT8_C( 10), UINT8_C(101),
                             UINT8_C(186), UINT8_C(181), UINT8_C(155), UINT8_C(243),
                             UINT8_C(189), UINT8_C(191), UINT8_C(222), UINT8_C(205),
                             UINT8_C( 59), UINT8_C( 26), UINT8_C(227), UINT8_C(105),
                             UINT8_C(237), UINT8_C(145), UINT8_C(183), UINT8_C( 79),
                             UINT8_C(174), UINT8_C( 60), UINT8_C(132), UINT8_C(208),
                             UINT8_C( 58), UINT8_C(178), UINT8_C(116), UINT8_C(240),
                             UINT8_C( 37), UINT8_C(131), UINT8_C(100), UINT8_C(177),
                             UINT8_C( 19), UINT8_C(102), UINT8_C( 81), UINT8_C( 86),
                             UINT8_C( 25), UINT8_C( 43), UINT8_C( 51), UINT8_C(140),
                             UINT8_C(  9), UINT8_C( 40), UINT8_C(227), UINT8_C( 75)),
      simde_x_mm512_set_epu8(UINT8_C( 87), UINT8_C( 21), UINT8_C( 47), UINT8_C( 80),
                             UINT8_C( 11), UINT8_C( 66), UINT8_C(  5), UINT8_C( 31),
                             UINT8_C( 13), UINT8_C( 16), UINT8_C( 53), UINT8_C( 47),
                             UINT8_C(  8), UINT8_C(  8), UINT8_C(  2), UINT8_C( 51),
                             UINT8_C( 47), UINT8_C(  0), UINT8_C( 74), UINT8_C(  3),
                             UINT8_C(  3), UINT8_C(  7), UINT8_C(  5), UINT8_C( 13),
                             UINT8_C( 13), UINT8_C( 54), UINT8_C( 97), UINT8_C(126),
                             UINT8_C( 10), UINT8_C(165), UINT8_C(155), UINT8_C( 88),
                             UINT8_C(  7), UINT8_C( 11), UINT8_C( 95), UINT8_C( 59),
                             UINT8_C( 65), UINT8_C( 71), UINT8_C(174), UINT8_C(  9),
                             UINT8_C(  9), UINT8_C( 22), UINT8_C( 98), UINT8_C( 14),
                             UINT8_C( 25), UINT8_C(173), UINT8_C( 87), UINT8_C(  2),
                             UINT8_C(  6), UINT8_C( 12), UINT8_C( 52), UINT8_C(  2),
                             UINT8_C( 12), UINT8_C(  0), UINT8_C(  0), UINT8_C( 57),
                             UINT8_C( 20), UINT8_C( 36), UINT8_C( 35), UINT8_C( 54),
                             UINT8_C(  6), UINT8_C(  5), UINT8_C(199), UINT8_C(  9)) },
    { simde_x_mm512_set_epu8(UINT8_C(233), UINT8_C( 79), UINT8_C( 12), UINT8_C(  0),
                             UINT8_C( 33), UINT8_C(178), UINT8_C( 58), UINT8_C( 74),
                             UINT8_C(250), UINT8_C(116), UINT8_C(142), UINT8_C( 20),
                             UINT8_C( 88), UINT8_C( 63), UINT8_C( 34), UINT8_C(124),
                             UINT8_C(250), UINT8_C( 48), UINT8_C(221), UINT8_C(232),
                             UINT8_C(221), UINT8_C( 75), UINT8_C(155), UINT8_C( 80),
                             UINT8_C(233), UINT8_C(169), UINT8_C(198), UINT8_C(226),
                             UINT8_C( 83), UINT8_C( 27), UINT8_C(137), UINT8_C( 34),
                             UINT8_C( 23), UINT8_C(132), UINT8_C(106), UINT8_C(109),
                             UINT8_C(135), UINT8_C(203), UINT8_C( 98), UINT8_C(120),
                             UINT8_C(101), UINT8_C( 52), UINT8_C( 82), UINT8_C( 44),
                             UINT8_C(142), UINT8_C( 14), UINT8_C( 99), UINT8_C(245),
                             UINT8_C(  8), UINT8_C(140), UINT8_C(141), UINT8_C(123),
                             UINT8_C(219), UINT8_C(163), UINT8_C(196), UINT8_C(233),
                             UINT8_C( 34), UINT8_C(185), UINT8_C(228), UINT8_C(108),
                             UINT8_C( 95), UINT8_C(236), UINT8_C( 97), UINT8_C( 41)),
      simde_x_mm512_set_epu8(UINT8_C(193), UINT8_C(230), UINT8_C( 93), UINT8_C( 23),
                             UINT8_C(193), UINT8_C( 52), UINT8_C(223), UINT8_C(175),
                             UINT8_C(205), UINT8_C( 45), UINT8_C(166), UINT8_C( 24),
                             UINT8_C( 71), UINT8_C(234), UINT8_C(161), UINT8_C(142),
                             UINT8_C(184), UINT8_C(218), UINT8_C(190), UINT8_C(212),
                             UINT8_C(116), UINT8_C(159), UINT8_C( 44), UINT8_C( 55),
                             UINT8_C(213), UINT8_C(133), UINT8_C( 60), UINT8_C(  3),
                             UINT8_C( 58), UINT8_C(255), UINT8_C(125), UINT8_C(189),
                             UINT8_C(145), UINT8_C( 88), UINT8_C( 55), UINT8_C(182),
                             UINT8_C( 23), UINT8_C(161), UINT8_C(133), UINT8_C( 27),
                             UINT8_C(125), UINT8_C(229), UINT8_C(203), UINT8_C( 45),
                             UINT8_C( 24), UINT8_C(  5), UINT8_C( 90), UINT8_C( 83),
                             UINT8_C(145), UINT8_C( 85), UINT8_C(156), UINT8_C(164),
                             UINT8_C(149), UINT8_C(201), UINT8_C( 48), UINT8_C(255),
                             UINT8_C( 41), UINT8_C( 42), UINT8_C( 94), UINT8_C(129),
                             UINT8_C(135), UINT8_C(  8), UINT8_C( 12), UINT8_C(203)),
      simde_x_mm512_set_epu8(UINT8_C( 40), UINT8_C( 79), UINT8_C( 12), UINT8_C(  0),
                             UINT8_C( 33), UINT8_C( 22), UINT8_C( 58), UINT8_C( 74),
                             UINT8_C( 45), UINT8_C( 26), UINT8_C(142), UINT8_C( 20),
                             UINT8_C( 17), UINT8_C( 63), UINT8_C( 34), UINT8_C(124),
                             UINT8_C( 66), UINT8_C( 48), UINT8_C( 31), UINT8_C( 20),
                             UINT8_C(105), UINT8_C( 75), UINT8_C( 23), UINT8_C( 25),
                             UINT8_C( 20), UINT8_C( 36), UINT8_C( 18), UINT8_C(  1),
                             UINT8_C( 25), UINT8_C( 27), UINT8_C( 12), UINT8_C( 34),
                             UINT8_C( 23), UINT8_C( 44), UINT8_C( 51), UINT8_C(109),
                             UINT8_C( 20), UINT8_C( 42), UINT8_C( 98), UINT8_C( 12),
                             UINT8_C(101), UINT8_C( 52), UINT8_C( 82), UINT8_C( 44),
                             UINT8_C( 22), UINT8_C(  4), UINT8_C(  9), UINT8_C( 79),
                             UINT8_C(  8), UINT8_C( 55), UINT8_C(141), UINT8_C(123),
                             UINT8_C( 70), UINT8_C(163), UINT8_C(  4), UINT8_C(233),
                             UINT8_C( 34), UINT8_C( 17), UINT8_C( 40), UINT8_C(108),
                             UINT8_C( 95), UINT8_C(  4), UINT8_C(  1), UINT8_C( 41)) },
    { simde_x_mm512_set_epu8(UINT8_C(142), UINT8_C( 19), UINT8_C(128), UINT8_C(  3),
                             UINT8_C(129), UINT8_C(192), UINT8_C(118), UINT8_C(156),
                             UINT8_C( 16), UINT8_C(232), UINT8_C(203), UINT8_C(122),
                             UINT8_C(229), UINT8_C(105), UINT8_C(120), UINT8_C(201),
                             UINT8_C(228), UINT8_C(167), UINT8_C(141), UINT8_C(146),
                             UINT8_C(116), UINT8_C( 74), UINT8_C(191), UINT8_C( 35),
                             UINT8_C( 45), UINT8_C(158), UINT8_C(228), UINT8_C(138),
                             UINT8_C( 49), UINT8_C(  7), UINT8_C( 65), UINT8_C(140),
                             UINT8_C(  0), UINT8_C(113), UINT8_C(156), UINT8_C(113),
                             UINT8_C(246), UINT8_C(167), UINT8_C(109), UINT8_C(141),
                             UINT8_C(192), UINT8_C( 11), UINT8_C( 33), UINT8_C(141),
                             UINT8_C(129), UINT8_C(  2), UINT8_C(168), UINT8_C(227),
                             UINT8_C( 23), UINT8_C(173), UINT8_C(104), UINT8_C( 71),
                             UINT8_C( 11), UINT8_C(250), UINT8_C( 13), UINT8_C(218),
                             UINT8_C(194), UINT8_C(140), UINT8_C(125), UINT8_C( 43),
                             UINT8_C(151), UINT8_C( 49), UINT8_C(129), UINT8_C(218)),
      simde_x_mm512_set_epu8(UINT8_C(  8), UINT8_C( 25), UINT8_C(147), UINT8_C(220),
                             UINT8_C(173), UINT8_C(138), UINT8_C( 38), UINT8_C(150),
                             UINT8_C( 35), UINT8_C( 43), UINT8_C(165), UINT8_C(185),
                             UINT8_C( 50), UINT8_C( 64), UINT8_C(161), UINT8_C(132),
                             UINT8_C(162), UINT8_C( 50), UINT8_C(199), UINT8_C( 84),
                             UINT8_C(251), UINT8_C(200), UINT8_C(217), UINT8_C( 19),
                             UINT8_C(180), UINT8_C(196), UINT8_C(246), UINT8_C( 76),
                             UINT8_C( 55), UINT8_C(204), UINT8_C(139), UINT8_C( 75),
                             UINT8_C(  1), UINT8_C( 89), UINT8_C(133), UINT8_C(212),
                             UINT8_C(206), UINT8_C( 55), UINT8_C(204), UINT8_C(120),
                             UINT8_C( 37), UINT8_C(159), UINT8_C(146), UINT8_C(217),
                             UINT8_C(226), UINT8_C(190), UINT8_C(134), UINT8_C(  8),
                             UINT8_C(113), UINT8_C( 61), UINT8_C(103), UINT8_C(100),
                             UINT8_C( 23), UINT8_C(229), UINT8_C(146), UINT8_C( 97),
                             UINT8_C( 95), UINT8_C( 32), UINT8_C(136), UINT8_C( 91),
                             UINT8_C( 46), UINT8_C(252), UINT8_C(163), UINT8_C( 88)),
      simde_x_mm512_set_epu8(UINT8_C(  6), UINT8_C( 19), UINT8_C(128), UINT8_C(  3),
                             UINT8_C(129), UINT8_C( 54), UINT8_C(  4), UINT8_C(  6),
                             UINT8_C( 16), UINT8_C( 17), UINT8_C( 38), UINT8_C(122),
                             UINT8_C( 29), UINT8_C( 41), UINT8_C(120), UINT8_C( 69),
                             UINT8_C( 66), UINT8_C( 17), UINT8_C(141), UINT8_C( 62),
                             UINT8_C(116), UINT8_C( 74), UINT8_C(191), UINT8_C( 16),
                             UINT8_C( 45), UINT8_C(158), UINT8_C(228), UINT8_C( 62),
                             UINT8_C( 49), UINT8_C(  7), UINT8_C( 65), UINT8_C( 65),
                             UINT8_C(  0), UINT8_C( 24), UINT8_C( 23), UINT8_C(113),
                             UINT8_C( 40), UINT8_C(  2), UINT8_C(109), UINT8_C( 21),
                             UINT8_C(  7), UINT8_C( 11), UINT8_C( 33), UINT8_C(141),
                             UINT8_C(129), UINT8_C(  2), UINT8_C( 34), UINT8_C(  3),
                             UINT8_C( 23), UINT8_C( 51), UINT8_C(  1), UINT8_C( 71),
                             UINT8_C( 11), UINT8_C( 21), UINT8_C( 13), UINT8_C( 24),
                             UINT8_C(  4), UINT8_C( 12), UINT8_C(125), UINT8_C( 43),
                             UINT8_C( 13), UINT8_C( 49), UINT8_C(129), UINT8_C( 42)) },
    { simde_x_mm512_set_epu8(UINT8_C( 46), UINT8_C( 43), UINT8_C(246), UINT8_C(157),
                             UINT8_C( 80), UINT8_C(154), UINT8_C( 27), UINT8_C(118),
                             UINT8_C(176), UINT8_C(216), UINT8_C( 46), UINT8_C(142),
                             UINT8_C(198), UINT8_C(248), UINT8_C( 88), UINT8_C( 29),
                             UINT8_C(176), UINT8_C( 25), UINT8_C(101), UINT8_C( 54),
                             UINT8_C(103), UINT8_C(120), UINT8_C( 94), UINT8_C( 16),
                             UINT8_C(197), UINT8_C(205), UINT8_C( 71), UINT8_C(246),
                             UINT8_C(158), UINT8_C(176), UINT8_C(218), UINT8_C( 43),
                             UINT8_C(235), UINT8_C(249), UINT8_C(116), UINT8_C(137),
                             UINT8_C( 89), UINT8_C(212), UINT8_C(132), UINT8_C( 56),
                             UINT8_C(230), UINT8_C(137), UINT8_C( 66), UINT8_C( 41),
                             UINT8_C( 44), UINT8_C( 35), UINT8_C(189), UINT8_C(155),
                             UINT8_C(125), UINT8_C(130), UINT8_C(123), UINT8_C(117),
                             UINT8_C(123), UINT8_C(127), UINT8_C(151), UINT8_C( 60),
                             UINT8_C(153), UINT8_C(185), UINT8_C(250), UINT8_C(100),
                             UINT8_C( 83), UINT8_C(112), UINT8_C( 33), UINT8_C(140)),
      simde_x_mm512_set_epu8(UINT8_C( 36), UINT8_C( 33), UINT8_C( 42), UINT8_C( 75),
                             UINT8_C(179), UINT8_C(172), UINT8_C(126), UINT8_C(171),
                             UINT8_C(110), UINT8_C(150), UINT8_C(107), UINT8_C(180),
                             UINT8_C(134), UINT8_C( 73), UINT8_C(207), UINT8_C( 15),
                             UINT8_C(241), UINT8_C(103), UINT8_C(103), UINT8_C(150),
                             UINT8_C(103), UINT8_C( 58), UINT8_C(104), UINT8_C( 35),
                             UINT8_C(249), UINT8_C( 79), UINT8_C(113), UINT8_C( 97),
                             UINT8_C(189), UINT8_C(197), UINT8_C(174), UINT8_C(222),
                             UINT8_C(224), UINT8_C(104), UINT8_C(123), UINT8_C(124),
                             UINT8_C( 49), UINT8_C(226), UINT8_C( 37), UINT8_C( 22),
                             UINT8_C(105), UINT8_C(157), UINT8_C(110), UINT8_C( 52),
                             UINT8_C(254), UINT8_C(103), UINT8_C(162), UINT8_C(210),
                             UINT8_C(202), UINT8_C( 39), UINT8_C(193), UINT8_C(151),
                             UINT8_C(183), UINT8_C( 73), UINT8_C( 97), UINT8_C(187),
                             UINT8_C(102), UINT8_C(195), UINT8_C( 68), UINT8_C(190),
                             UINT8_C( 65), UINT8_C( 60), UINT8_C(165), UINT8_C(126)),
      simde_x_mm512_set_epu8(UINT8_C( 10), UINT8_C( 10), UINT8_C( 36), UINT8_C(  7),
                             UINT8_C( 80), UINT8_C(154), UINT8_C( 27), UINT8_C(118),
                             UINT8_C( 66), UINT8_C( 66), UINT8_C( 46), UINT8_C(142),
                             UINT8_C( 64), UINT8_C( 29), UINT8_C( 88), UINT8_C( 14),
                             UINT8_C(176), UINT8_C( 25), UINT8_C(101), UINT8_C( 54),
                             UINT8_C(  0), UINT8_C(  4), UINT8_C( 94), UINT8_C( 16),
                             UINT8_C(197), UINT8_C( 47), UINT8_C( 71), UINT8_C( 52),
                             UINT8_C(158), UINT8_C(176), UINT8_C( 44), UINT8_C( 43),
                             UINT8_C( 11), UINT8_C( 41), UINT8_C(116), UINT8_C( 13),
                             UINT8_C( 40), UINT8_C(212), UINT8_C( 21), UINT8_C( 12),
                             UINT8_C( 20), UINT8_C(137), UINT8_C( 66), UINT8_C( 41),
                             UINT8_C( 44), UINT8_C( 35), UINT8_C( 27), UINT8_C(155),
                             UINT8_C(125), UINT8_C( 13), UINT8_C(123), UINT8_C(117),
                             UINT8_C(123), UINT8_C( 54), UINT8_C( 54), UINT8_C( 60),
                             UINT8_C( 51), UINT8_C(185), UINT8_C( 46), UINT8_C(100),
                             UINT8_C( 18), UINT8_C( 52), UINT8_C( 33), UINT8_C( 14)) },
    { simde_x_mm512_set_epu8(UINT8_C(240), UINT8_C(169), UINT8_C(  8), UINT8_C( 54),
                             UINT8_C( 66), UINT8_C( 99), UINT8_C( 14), UINT8_C( 32),
                             UINT8_C(148), UINT8_C( 92), UINT8_C(122), UINT8_C(200),
                             UINT8_C(192), UINT8_C(186), UINT8_C(225), UINT8_C( 52),
                             UINT8_C(182), UINT8_C(244), UINT8_C(253), UINT8_C(228),
                             UINT8_C(141), UINT8_C(228), UINT8_C(148), UINT8_C(168),
                             UINT8_C(231), UINT8_C(107), UINT8_C( 47), UINT8_C(205),
                             UINT8_C(126), UINT8_C(  7), UINT8_C(182), UINT8_C(245),
                             UINT8_C(165), UINT8_C(186), UINT8_C(213), UINT8_C( 84),
                             UINT8_C( 19), UINT8_C(131), UINT8_C( 54), UINT8_C( 13),
                             UINT8_C(185), UINT8_C(182), UINT8_C( 72), UINT8_C( 61),
                             UINT8_C(125), UINT8_C(104), UINT8_C(147), UINT8_C( 11),
                             UINT8_C( 89), UINT8_C(204), UINT8_C( 62), UINT8_C(163),
                             UINT8_C(198), UINT8_C(162), UINT8_C(205), UINT8_C(  9),
                             UINT8_C(182), UINT8_C(123), UINT8_C( 65), UINT8_C(208),
                             UINT8_C(145), UINT8_C(179), UINT8_C( 34), UINT8_C(195)),
      simde_x_mm512_set_epu8(UINT8_C(141), UINT8_C(103), UINT8_C(116), UINT8_C( 12),
                             UINT8_C(174), UINT8_C(226), UINT8_C(193), UINT8_C(175),
                             UINT8_C(155), UINT8_C(174), UINT8_C( 73), UINT8_C(  6),
                             UINT8_C(141), UINT8_C(140), UINT8_C(254), UINT8_C(193),
                             UINT8_C(100), UINT8_C(151), UINT8_C( 14), UINT8_C( 19),
                             UINT8_C( 38), UINT8_C(115), UINT8_C(201), UINT8_C(118),
                             UINT8_C( 74), UINT8_C(186), UINT8_C( 89), UINT8_C(183),
                             UINT8_C( 65), UINT8_C(138), UINT8_C( 64), UINT8_C( 90),
                             UINT8_C(152), UINT8_C(241), UINT8_C(229), UINT8_C(218),
                             UINT8_C(126), UINT8_C( 38), UINT8_C(159), UINT8_C( 27),
                             UINT8_C(164), UINT8_C(199), UINT8_C( 25), UINT8_C(253),
                             UINT8_C(181), UINT8_C(104), UINT8_C(  6), UINT8_C(183),
                             UINT8_C( 36), UINT8_C(203), UINT8_C(138), UINT8_C(145),
                             UINT8_C(116), UINT8_C(155), UINT8_C(218), UINT8_C( 24),
                             UINT8_C(205), UINT8_C(238), UINT8_C(242), UINT8_C( 26),
                             UINT8_C(226), UINT8_C( 76), UINT8_C(226), UINT8_C(214)),
      simde_x_mm512_set_epu8(UINT8_C( 99), UINT8_C( 66), UINT8_C(  8), UINT8_C(  6),
                             UINT8_C( 66), UINT8_C( 99), UINT8_C( 14), UINT8_C( 32),
                             UINT8_C(148), UINT8_C( 92), UINT8_C( 49), UINT8_C(  2),
                             UINT8_C( 51), UINT8_C( 46), UINT8_C(225), UINT8_C( 52),
                             UINT8_C( 82), UINT8_C( 93), UINT8_C(  1), UINT8_C(  0),
                             UINT8_C( 27), UINT8_C(113), UINT8_C(148), UINT8_C( 50),
                             UINT8_C(  9), UINT8_C(107), UINT8_C( 47), UINT8_C( 22),
                             UINT8_C( 61), UINT8_C(  7), UINT8_C( 54), UINT8_C( 65),
                             UINT8_C( 13), UINT8_C(186), UINT8_C(213), UINT8_C( 84),
                             UINT8_C( 19), UINT8_C( 17), UINT8_C( 54), UINT8_C( 13),
                             UINT8_C( 21), UINT8_C(182), UINT8_C( 22), UINT8_C( 61),
                             UINT8_C(125), UINT8_C(  0), UINT8_C(  3), UINT8_C( 11),
                             UINT8_C( 17), UINT8_C(  1), UINT8_C( 62), UINT8_C( 18),
                             UINT8_C( 82), UINT8_C(  7), UINT8_C(205), UINT8_C(  9),
                             UINT8_C(182), UINT8_C(123), UINT8_C( 65), UINT8_C(  0),
                             UINT8_C(145), UINT8_C( 27), UINT8_C( 34), UINT8_C(195)) },
    { simde_x_mm512_set_epu8(UINT8_C(197), UINT8_C( 52), UINT8_C(145), UINT8_C( 20),
                             UINT8_C( 26), UINT8_C(178), UINT8_C(121), UINT8_C( 16),
                             UINT8_C( 45), UINT8_C(229), UINT8_C( 11), UINT8_C(230),
                             UINT8_C( 53), UINT8_C(  2), UINT8_C(234), UINT8_C(  7),
                             UINT8_C(207), UINT8_C(146), UINT8_C(169), UINT8_C(233),
                             UINT8_C(206), UINT8_C(116), UINT8_C( 55), UINT8_C(156),
                             UINT8_C(180), UINT8_C( 91), UINT8_C( 56), UINT8_C(146),
                             UINT8_C( 55), UINT8_C(137), UINT8_C(200), UINT8_C( 76),
                             UINT8_C( 43), UINT8_C(245), UINT8_C(138), UINT8_C(  3),
                             UINT8_C(213), UINT8_C(156), UINT8_C(166), UINT8_C(234),
                             UINT8_C(199), UINT8_C(  2), UINT8_C( 86), UINT8_C( 72),
                             UINT8_C( 93), UINT8_C(254), UINT8_C(190), UINT8_C(121),
                             UINT8_C(119), UINT8_C( 75), UINT8_C(159), UINT8_C( 76),
                             UINT8_C( 70), UINT8_C(218), UINT8_C( 17), UINT8_C(239),
                             UINT8_C( 43), UINT8_C(152), UINT8_C(222), UINT8_C( 80),
                             UINT8_C(197), UINT8_C(113), UINT8_C(112), UINT8_C( 81)),
      simde_x_mm512_set_epu8(UINT8_C(193), UINT8_C(162), UINT8_C(178), UINT8_C( 36),
                             UINT8_C(178), UINT8_C( 86), UINT8_C( 79), UINT8_C(167),
                             UINT8_C(179), UINT8_C( 45), UINT8_C( 18), UINT8_C(231),
                             UINT8_C(113), UINT8_C(127), UINT8_C(211), UINT8_C(181),
                             UINT8_C(121), UINT8_C(171), UINT8_C( 76), UINT8_C(135),
                             UINT8_C( 15), UINT8_C(133), UINT8_C(247), UINT8_C( 32),
                             UINT8_C(181), UINT8_C(168), UINT8_C(236), UINT8_C( 99),
                             UINT8_C( 85), UINT8_C(151), UINT8_C( 36), UINT8_C( 99),
                             UINT8_C(101), UINT8_C( 42), UINT8_C( 63), UINT8_C( 96),
                             UINT8_C(210), UINT8_C(198), UINT8_C(202), UINT8_C(105),
                             UINT8_C(214), UINT8_C( 74), UINT8_C(199), UINT8_C( 17),
                             UINT8_C(234), UINT8_C( 22), UINT8_C(134), UINT8_C(112),
                             UINT8_C( 62), UINT8_C(141), UINT8_C(156), UINT8_C( 91),
                             UINT8_C( 99), UINT8_C( 24), UINT8_C(198), UINT8_C(131),
                             UINT8_C( 88), UINT8_C(136), UINT8_C( 61), UINT8_C( 94),
                             UINT8_C(189), UINT8_C(213), UINT8_C(249), UINT8_C(131)),
      simde_x_mm512_set_epu8(UINT8_C(  4), UINT8_C( 52), UINT8_C(145), UINT8_C( 20),
                             UINT8_C( 26), UINT8_C(  6), UINT8_C( 42), UINT8_C( 16),
                             UINT8_C( 45), UINT8_C(  4), UINT8_C( 11), UINT8_C(230),
                             UINT8_C( 53), UINT8_C(  2), UINT8_C( 23), UINT8_C(  7),
                             UINT8_C( 86), UINT8_C(146), UINT8_C( 17), UINT8_C( 98),
                             UINT8_C( 11), UINT8_C(116), UINT8_C( 55), UINT8_C( 28),
                             UINT8_C(180), UINT8_C( 91), UINT8_C( 56), UINT8_C( 47),
                             UINT8_C( 55), UINT8_C(137), UINT8_C( 20), UINT8_C( 76),
                             UINT8_C( 43), UINT8_C( 35), UINT8_C( 12), UINT8_C(  3),
                             UINT8_C(  3), UINT8_C(156), UINT8_C(166), UINT8_C( 24),
                             UINT8_C(199), UINT8_C(  2), UINT8_C( 86), UINT8_C(  4),
                             UINT8_C( 93), UINT8_C( 12), UINT8_C( 56), UINT8_C(  9),
                             UINT8_C( 57), UINT8_C( 75), UINT8_C(  3), UINT8_C( 76),
                             UINT8_C( 70), UINT8_C(  2), UINT8_C( 17), UINT8_C(108),
                             UINT8_C( 43), UINT8_C( 16), UINT8_C( 39), UINT8_C( 80),
                             UINT8_C(  8), UINT8_C(113), UINT8_C(112), UINT8_C( 81)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_rem_epu8(test_vec[i].a, test_vec[i].b);
    simde_assert_m512i_u8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_rem_epu16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512i a;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {
    { simde_x_mm512_set_epu16(UINT16_C( 10545), UINT16_C( 43974), UINT16_C( 10284), UINT16_C( 62003),
                              UINT16_C( 35545), UINT16_C( 55289), UINT16_C( 51493), UINT16_C( 35101),
                              UINT16_C( 59818), UINT16_C( 61822), UINT16_C( 46602), UINT16_C( 53446),
                              UINT16_C( 23938), UINT16_C( 50097), UINT16_C( 48095), UINT16_C( 35837),
                              UINT16_C( 49063), UINT16_C( 57920), UINT16_C( 54730), UINT16_C( 28273),
                              UINT16_C( 23021), UINT16_C( 18146), UINT16_C( 33883), UINT16_C( 65368),
                              UINT16_C( 26666), UINT16_C( 13822), UINT16_C( 34046), UINT16_C( 24651),
                              UINT16_C(  8048), UINT16_C( 38825), UINT16_C( 44126), UINT16_C( 28762)),
      simde_x_mm512_set_epu16(UINT16_C( 38607), UINT16_C(  8074), UINT16_C( 18000), UINT16_C( 35687),
                              UINT16_C( 40415), UINT16_C(  3254), UINT16_C( 55282), UINT16_C( 38855),
                              UINT16_C( 41330), UINT16_C( 37148), UINT16_C( 25803), UINT16_C( 25877),
                              UINT16_C(   768), UINT16_C( 16244), UINT16_C( 11114), UINT16_C( 58324),
                              UINT16_C( 18192), UINT16_C( 32532), UINT16_C( 33700), UINT16_C( 60373),
                              UINT16_C( 20183), UINT16_C( 64042), UINT16_C(  2502), UINT16_C( 18488),
                              UINT16_C( 22771), UINT16_C( 21470), UINT16_C(  4556), UINT16_C( 26138),
                              UINT16_C( 19085), UINT16_C( 64613), UINT16_C( 55602), UINT16_C( 63371)),
      simde_x_mm512_set_epu16(UINT16_C( 10545), UINT16_C(  3604), UINT16_C( 10284), UINT16_C( 26316),
                              UINT16_C( 35545), UINT16_C(  3225), UINT16_C( 51493), UINT16_C( 35101),
                              UINT16_C( 18488), UINT16_C( 24674), UINT16_C( 20799), UINT16_C(  1692),
                              UINT16_C(   130), UINT16_C(  1365), UINT16_C(  3639), UINT16_C( 35837),
                              UINT16_C( 12679), UINT16_C( 25388), UINT16_C( 21030), UINT16_C( 28273),
                              UINT16_C(  2838), UINT16_C( 18146), UINT16_C(  1357), UINT16_C(  9904),
                              UINT16_C(  3895), UINT16_C( 13822), UINT16_C(  2154), UINT16_C( 24651),
                              UINT16_C(  8048), UINT16_C( 38825), UINT16_C( 44126), UINT16_C( 28762)) },
    { simde_x_mm512_set_epu16(UINT16_C( 20057), UINT16_C( 26978), UINT16_C( 45741), UINT16_C( 34503),
                              UINT16_C( 54259), UINT16_C( 41436), UINT16_C( 43883), UINT16_C( 11009),
                              UINT16_C( 50212), UINT16_C(  9014), UINT16_C( 24117), UINT16_C( 34039),
                              UINT16_C( 58348), UINT16_C(  8311), UINT16_C( 31759), UINT16_C(  4002),
                              UINT16_C(  7525), UINT16_C(  3321), UINT16_C( 47299), UINT16_C( 64213),
                              UINT16_C( 13644), UINT16_C( 48153), UINT16_C( 45234), UINT16_C( 51700),
                              UINT16_C(  7513), UINT16_C(  1114), UINT16_C( 65336), UINT16_C( 10389),
                              UINT16_C( 33688), UINT16_C(  9445), UINT16_C( 60332), UINT16_C( 41466)),
      simde_x_mm512_set_epu16(UINT16_C( 48157), UINT16_C( 56913), UINT16_C( 55050), UINT16_C( 48859),
                              UINT16_C( 27895), UINT16_C( 48343), UINT16_C( 59593), UINT16_C( 60425),
                              UINT16_C( 62587), UINT16_C( 54231), UINT16_C( 52444), UINT16_C(  8140),
                              UINT16_C( 58695), UINT16_C(  2476), UINT16_C( 41101), UINT16_C(  7948),
                              UINT16_C( 26094), UINT16_C( 52354), UINT16_C( 30122), UINT16_C( 47688),
                              UINT16_C( 43801), UINT16_C( 57764), UINT16_C(  1809), UINT16_C( 33603),
                              UINT16_C(  8271), UINT16_C(  4936), UINT16_C(  7627), UINT16_C( 20477),
                              UINT16_C( 14608), UINT16_C( 25470), UINT16_C( 45836), UINT16_C( 25611)),
      simde_x_mm512_set_epu16(UINT16_C( 20057), UINT16_C( 26978), UINT16_C( 45741), UINT16_C( 34503),
                              UINT16_C( 26364), UINT16_C( 41436), UINT16_C( 43883), UINT16_C( 11009),
                              UINT16_C( 50212), UINT16_C(  9014), UINT16_C( 24117), UINT16_C(  1479),
                              UINT16_C( 58348), UINT16_C(   883), UINT16_C( 31759), UINT16_C(  4002),
                              UINT16_C(  7525), UINT16_C(  3321), UINT16_C( 17177), UINT16_C( 16525),
                              UINT16_C( 13644), UINT16_C( 48153), UINT16_C(     9), UINT16_C( 18097),
                              UINT16_C(  7513), UINT16_C(  1114), UINT16_C(  4320), UINT16_C( 10389),
                              UINT16_C(  4472), UINT16_C(  9445), UINT16_C( 14496), UINT16_C( 15855)) },
    { simde_x_mm512_set_epu16(UINT16_C( 26902), UINT16_C( 51011), UINT16_C( 57631), UINT16_C( 57521),
                              UINT16_C( 43405), UINT16_C( 18318), UINT16_C( 44023), UINT16_C(  9770),
                              UINT16_C(  4118), UINT16_C( 33099), UINT16_C(  6621), UINT16_C( 57639),
                              UINT16_C( 22002), UINT16_C( 33155), UINT16_C( 15537), UINT16_C( 38743),
                              UINT16_C( 26466), UINT16_C( 21183), UINT16_C(  5811), UINT16_C( 17016),
                              UINT16_C( 51162), UINT16_C( 46775), UINT16_C( 54252), UINT16_C( 64603),
                              UINT16_C( 30444), UINT16_C( 20573), UINT16_C( 50572), UINT16_C( 25607),
                              UINT16_C( 36721), UINT16_C( 36797), UINT16_C( 27147), UINT16_C( 62271)),
      simde_x_mm512_set_epu16(UINT16_C( 55381), UINT16_C( 52839), UINT16_C( 60314), UINT16_C( 33159),
                              UINT16_C( 32076), UINT16_C( 51820), UINT16_C( 13383), UINT16_C( 43204),
                              UINT16_C( 18058), UINT16_C( 42817), UINT16_C( 56737), UINT16_C( 40285),
                              UINT16_C( 49341), UINT16_C( 39323), UINT16_C( 53205), UINT16_C( 27016),
                              UINT16_C( 59998), UINT16_C( 61452), UINT16_C( 37377), UINT16_C( 37691),
                              UINT16_C( 64794), UINT16_C(  6696), UINT16_C(  3074), UINT16_C( 59025),
                              UINT16_C( 43625), UINT16_C( 28576), UINT16_C( 36042), UINT16_C( 42716),
                              UINT16_C( 47937), UINT16_C( 64195), UINT16_C(  8579), UINT16_C(   676)),
      simde_x_mm512_set_epu16(UINT16_C( 26902), UINT16_C( 51011), UINT16_C( 57631), UINT16_C( 24362),
                              UINT16_C( 11329), UINT16_C( 18318), UINT16_C(  3874), UINT16_C(  9770),
                              UINT16_C(  4118), UINT16_C( 33099), UINT16_C(  6621), UINT16_C( 17354),
                              UINT16_C( 22002), UINT16_C( 33155), UINT16_C( 15537), UINT16_C( 11727),
                              UINT16_C( 26466), UINT16_C( 21183), UINT16_C(  5811), UINT16_C( 17016),
                              UINT16_C( 51162), UINT16_C(  6599), UINT16_C(  1994), UINT16_C(  5578),
                              UINT16_C( 30444), UINT16_C( 20573), UINT16_C( 14530), UINT16_C( 25607),
                              UINT16_C( 36721), UINT16_C( 36797), UINT16_C(  1410), UINT16_C(    79)) },
    { simde_x_mm512_set_epu16(UINT16_C(  7566), UINT16_C( 25511), UINT16_C( 59705), UINT16_C( 13989),
                              UINT16_C( 13965), UINT16_C( 34471), UINT16_C(    77), UINT16_C( 35152),
                              UINT16_C( 21705), UINT16_C( 42504), UINT16_C( 63033), UINT16_C( 56884),
                              UINT16_C( 42389), UINT16_C( 61527), UINT16_C(  7598), UINT16_C( 23051),
                              UINT16_C( 13886), UINT16_C( 28688), UINT16_C( 30551), UINT16_C( 36608),
                              UINT16_C( 56045), UINT16_C( 38987), UINT16_C( 64798), UINT16_C( 22350),
                              UINT16_C(  7981), UINT16_C( 50477), UINT16_C( 46688), UINT16_C( 16804),
                              UINT16_C( 33660), UINT16_C( 63749), UINT16_C( 29649), UINT16_C( 64815)),
      simde_x_mm512_set_epu16(UINT16_C( 18409), UINT16_C( 19069), UINT16_C( 20979), UINT16_C( 35774),
                              UINT16_C(  8112), UINT16_C( 25085), UINT16_C( 31664), UINT16_C( 55404),
                              UINT16_C( 63329), UINT16_C( 19403), UINT16_C( 33006), UINT16_C( 20365),
                              UINT16_C( 22045), UINT16_C( 41935), UINT16_C( 28665), UINT16_C( 35793),
                              UINT16_C( 26789), UINT16_C( 40241), UINT16_C( 34076), UINT16_C( 36189),
                              UINT16_C( 49507), UINT16_C( 32891), UINT16_C( 45700), UINT16_C( 31541),
                              UINT16_C( 33237), UINT16_C( 50719), UINT16_C( 22782), UINT16_C( 46902),
                              UINT16_C( 62792), UINT16_C(   907), UINT16_C(  9939), UINT16_C(   395)),
      simde_x_mm512_set_epu16(UINT16_C(  7566), UINT16_C(  6442), UINT16_C( 17747), UINT16_C( 13989),
                              UINT16_C(  5853), UINT16_C(  9386), UINT16_C(    77), UINT16_C( 35152),
                              UINT16_C( 21705), UINT16_C(  3698), UINT16_C( 30027), UINT16_C( 16154),
                              UINT16_C( 20344), UINT16_C( 19592), UINT16_C(  7598), UINT16_C( 23051),
                              UINT16_C( 13886), UINT16_C( 28688), UINT16_C( 30551), UINT16_C(   419),
                              UINT16_C(  6538), UINT16_C(  6096), UINT16_C( 19098), UINT16_C( 22350),
                              UINT16_C(  7981), UINT16_C( 50477), UINT16_C(  1124), UINT16_C( 16804),
                              UINT16_C( 33660), UINT16_C(   259), UINT16_C(  9771), UINT16_C(    35)) },
    { simde_x_mm512_set_epu16(UINT16_C( 40553), UINT16_C(  9260), UINT16_C(  6846), UINT16_C( 21618),
                              UINT16_C( 20365), UINT16_C( 26413), UINT16_C(  7670), UINT16_C(  6521),
                              UINT16_C( 13052), UINT16_C( 19892), UINT16_C( 40021), UINT16_C( 58092),
                              UINT16_C( 12337), UINT16_C( 14080), UINT16_C(  6934), UINT16_C( 61515),
                              UINT16_C(  1885), UINT16_C( 11733), UINT16_C(  7371), UINT16_C( 24583),
                              UINT16_C( 48349), UINT16_C( 37475), UINT16_C( 47206), UINT16_C( 54691),
                              UINT16_C( 63460), UINT16_C(  2107), UINT16_C( 62169), UINT16_C( 38808),
                              UINT16_C( 21341), UINT16_C( 51834), UINT16_C( 26283), UINT16_C( 38235)),
      simde_x_mm512_set_epu16(UINT16_C(  9227), UINT16_C( 20728), UINT16_C( 22448), UINT16_C( 22271),
                              UINT16_C( 38010), UINT16_C(  3228), UINT16_C( 38598), UINT16_C( 15839),
                              UINT16_C(  4554), UINT16_C( 22831), UINT16_C( 44103), UINT16_C( 32351),
                              UINT16_C( 46747), UINT16_C( 20983), UINT16_C( 61889), UINT16_C( 26454),
                              UINT16_C( 63311), UINT16_C( 19804), UINT16_C( 62773), UINT16_C( 56806),
                              UINT16_C( 36384), UINT16_C( 25302), UINT16_C( 37143), UINT16_C(  3478),
                              UINT16_C( 59861), UINT16_C( 61175), UINT16_C( 48658), UINT16_C( 23119),
                              UINT16_C( 30252), UINT16_C( 63116), UINT16_C( 13170), UINT16_C( 44087)),
      simde_x_mm512_set_epu16(UINT16_C(  3645), UINT16_C(  9260), UINT16_C(  6846), UINT16_C( 21618),
                              UINT16_C( 20365), UINT16_C(   589), UINT16_C(  7670), UINT16_C(  6521),
                              UINT16_C(  3944), UINT16_C( 19892), UINT16_C( 40021), UINT16_C( 25741),
                              UINT16_C( 12337), UINT16_C( 14080), UINT16_C(  6934), UINT16_C(  8607),
                              UINT16_C(  1885), UINT16_C( 11733), UINT16_C(  7371), UINT16_C( 24583),
                              UINT16_C( 11965), UINT16_C( 12173), UINT16_C( 10063), UINT16_C(  2521),
                              UINT16_C(  3599), UINT16_C(  2107), UINT16_C( 13511), UINT16_C( 15689),
                              UINT16_C( 21341), UINT16_C( 51834), UINT16_C( 13113), UINT16_C( 38235)) },
    { simde_x_mm512_set_epu16(UINT16_C( 22335), UINT16_C( 12112), UINT16_C(  9189), UINT16_C(  1311),
                              UINT16_C( 58441), UINT16_C( 13615), UINT16_C( 43712), UINT16_C( 31469),
                              UINT16_C( 12162), UINT16_C( 56166), UINT16_C( 41769), UINT16_C( 50135),
                              UINT16_C( 50998), UINT16_C( 24958), UINT16_C(  2725), UINT16_C( 39768),
                              UINT16_C( 47167), UINT16_C( 24484), UINT16_C( 16711), UINT16_C( 44632),
                              UINT16_C( 46990), UINT16_C( 25102), UINT16_C(  6573), UINT16_C( 22274),
                              UINT16_C( 49039), UINT16_C( 38914), UINT16_C( 32256), UINT16_C( 41529),
                              UINT16_C( 62756), UINT16_C( 61238), UINT16_C(  8613), UINT16_C( 51028)),
      simde_x_mm512_set_epu16(UINT16_C( 30472), UINT16_C( 36773), UINT16_C(  7714), UINT16_C( 18947),
                              UINT16_C(  7066), UINT16_C( 47844), UINT16_C( 58651), UINT16_C(  1841),
                              UINT16_C( 35799), UINT16_C( 50579), UINT16_C( 32926), UINT16_C( 26598),
                              UINT16_C( 39537), UINT16_C( 61137), UINT16_C(  5946), UINT16_C(  2262),
                              UINT16_C( 60116), UINT16_C( 12953), UINT16_C( 38045), UINT16_C( 47787),
                              UINT16_C( 30618), UINT16_C( 37811), UINT16_C( 51748), UINT16_C( 52236),
                              UINT16_C( 23394), UINT16_C(  2441), UINT16_C( 32382), UINT16_C(  9384),
                              UINT16_C( 25792), UINT16_C( 56163), UINT16_C( 22658), UINT16_C( 20939)),
      simde_x_mm512_set_epu16(UINT16_C( 22335), UINT16_C( 12112), UINT16_C(  1475), UINT16_C(  1311),
                              UINT16_C(  1913), UINT16_C( 13615), UINT16_C( 43712), UINT16_C(   172),
                              UINT16_C( 12162), UINT16_C(  5587), UINT16_C(  8843), UINT16_C( 23537),
                              UINT16_C( 11461), UINT16_C( 24958), UINT16_C(  2725), UINT16_C(  1314),
                              UINT16_C( 47167), UINT16_C( 11531), UINT16_C( 16711), UINT16_C( 44632),
                              UINT16_C( 16372), UINT16_C( 25102), UINT16_C(  6573), UINT16_C( 22274),
                              UINT16_C(  2251), UINT16_C(  2299), UINT16_C( 32256), UINT16_C(  3993),
                              UINT16_C( 11172), UINT16_C(  5075), UINT16_C(  8613), UINT16_C(  9150)) },
    { simde_x_mm512_set_epu16(UINT16_C( 13867), UINT16_C( 28091), UINT16_C( 35390), UINT16_C( 56986),
                              UINT16_C( 31509), UINT16_C( 63331), UINT16_C(  9520), UINT16_C( 29929),
                              UINT16_C( 24571), UINT16_C( 37741), UINT16_C( 52686), UINT16_C( 14609),
                              UINT16_C( 31001), UINT16_C(   823), UINT16_C( 45697), UINT16_C( 38351),
                              UINT16_C( 35780), UINT16_C( 41006), UINT16_C(  3633), UINT16_C( 45500),
                              UINT16_C( 30184), UINT16_C( 27396), UINT16_C(  1171), UINT16_C( 25936),
                              UINT16_C( 61703), UINT16_C( 57786), UINT16_C( 19453), UINT16_C( 30002),
                              UINT16_C(  6315), UINT16_C(   244), UINT16_C(  8399), UINT16_C( 57456)),
      simde_x_mm512_set_epu16(UINT16_C( 18752), UINT16_C( 27431), UINT16_C( 53704), UINT16_C( 42625),
                              UINT16_C( 42869), UINT16_C( 41745), UINT16_C( 47543), UINT16_C( 11401),
                              UINT16_C( 26966), UINT16_C( 26500), UINT16_C(  7486), UINT16_C(  7825),
                              UINT16_C( 17767), UINT16_C( 58506), UINT16_C( 36234), UINT16_C( 38373),
                              UINT16_C( 54992), UINT16_C( 46906), UINT16_C( 52104), UINT16_C( 31285),
                              UINT16_C( 34932), UINT16_C( 29467), UINT16_C( 33781), UINT16_C(   883),
                              UINT16_C( 23995), UINT16_C( 43069), UINT16_C( 53587), UINT16_C( 11327),
                              UINT16_C( 36611), UINT16_C(  7518), UINT16_C( 30015), UINT16_C( 30285)),
      simde_x_mm512_set_epu16(UINT16_C( 13867), UINT16_C(   660), UINT16_C( 35390), UINT16_C( 14361),
                              UINT16_C( 31509), UINT16_C( 21586), UINT16_C(  9520), UINT16_C(  7127),
                              UINT16_C( 24571), UINT16_C( 11241), UINT16_C(   284), UINT16_C(  6784),
                              UINT16_C( 13234), UINT16_C(   823), UINT16_C(  9463), UINT16_C( 38351),
                              UINT16_C( 35780), UINT16_C( 41006), UINT16_C(  3633), UINT16_C( 14215),
                              UINT16_C( 30184), UINT16_C( 27396), UINT16_C(  1171), UINT16_C(   329),
                              UINT16_C( 13713), UINT16_C( 14717), UINT16_C( 19453), UINT16_C(  7348),
                              UINT16_C(  6315), UINT16_C(   244), UINT16_C(  8399), UINT16_C( 27171)) },
    { simde_x_mm512_set_epu16(UINT16_C( 19003), UINT16_C( 26627), UINT16_C( 63705), UINT16_C( 34218),
                              UINT16_C( 36055), UINT16_C( 13847), UINT16_C( 44625), UINT16_C(  9042),
                              UINT16_C( 36148), UINT16_C( 11660), UINT16_C( 32339), UINT16_C( 39715),
                              UINT16_C( 47178), UINT16_C( 21002), UINT16_C( 60706), UINT16_C(  8527),
                              UINT16_C( 26072), UINT16_C( 29611), UINT16_C( 18348), UINT16_C(   953),
                              UINT16_C( 33382), UINT16_C( 22717), UINT16_C( 50122), UINT16_C( 52414),
                              UINT16_C( 59278), UINT16_C( 54225), UINT16_C( 31952), UINT16_C( 29752),
                              UINT16_C( 37488), UINT16_C( 20614), UINT16_C(  1055), UINT16_C( 61149)),
      simde_x_mm512_set_epu16(UINT16_C( 59727), UINT16_C(  3072), UINT16_C(  8626), UINT16_C( 14922),
                              UINT16_C( 64116), UINT16_C( 36372), UINT16_C( 22591), UINT16_C(  8828),
                              UINT16_C( 64048), UINT16_C( 56808), UINT16_C( 56651), UINT16_C( 39760),
                              UINT16_C( 59817), UINT16_C( 50914), UINT16_C( 21275), UINT16_C( 35106),
                              UINT16_C(  6020), UINT16_C( 27245), UINT16_C( 34763), UINT16_C( 25208),
                              UINT16_C( 25908), UINT16_C( 21036), UINT16_C( 36366), UINT16_C( 25589),
                              UINT16_C(  2188), UINT16_C( 36219), UINT16_C( 56227), UINT16_C( 50409),
                              UINT16_C(  8889), UINT16_C( 58476), UINT16_C( 24556), UINT16_C( 24873)),
      simde_x_mm512_set_epu16(UINT16_C( 19003), UINT16_C(  2051), UINT16_C(  3323), UINT16_C(  4374),
                              UINT16_C( 36055), UINT16_C( 13847), UINT16_C( 22034), UINT16_C(   214),
                              UINT16_C( 36148), UINT16_C( 11660), UINT16_C( 32339), UINT16_C( 39715),
                              UINT16_C( 47178), UINT16_C( 21002), UINT16_C( 18156), UINT16_C(  8527),
                              UINT16_C(  1992), UINT16_C(  2366), UINT16_C( 18348), UINT16_C(   953),
                              UINT16_C(  7474), UINT16_C(  1681), UINT16_C( 13756), UINT16_C(  1236),
                              UINT16_C(   202), UINT16_C( 18006), UINT16_C( 31952), UINT16_C( 29752),
                              UINT16_C(  1932), UINT16_C( 20614), UINT16_C(  1055), UINT16_C( 11403)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_rem_epu16(test_vec[i].a, test_vec[i].b);
    simde_assert_m512i_u16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_rem_epu32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512i a;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {
    { simde_x_mm512_set_epu32(UINT32_C( 691121094), UINT32_C( 674034227), UINT32_C(2329532409), UINT32_C(3374680349),
                              UINT32_C(3920294270), UINT32_C(3054162118), UINT32_C(1568850865), UINT32_C(3151989757),
                              UINT32_C(3215450688), UINT32_C(3586813553), UINT32_C(1508722402), UINT32_C(2220621656),
                              UINT32_C(1747596798), UINT32_C(2231263307), UINT32_C( 527472553), UINT32_C(2891870298)),
      simde_x_mm512_set_epu32(UINT32_C(2530156426), UINT32_C(1179683687), UINT32_C(2648640694), UINT32_C(3623000007),
                              UINT32_C(2708640028), UINT32_C(1691051285), UINT32_C(  50347892), UINT32_C( 728425428),
                              UINT32_C(1192263444), UINT32_C(2208623573), UINT32_C(1322777130), UINT32_C( 163989560),
                              UINT32_C(1492341726), UINT32_C( 298608154), UINT32_C(1250819173), UINT32_C(3643996043)),
      simde_x_mm512_set_epu32(UINT32_C( 691121094), UINT32_C( 674034227), UINT32_C(2329532409), UINT32_C(3374680349),
                              UINT32_C(1211654242), UINT32_C(1363110833), UINT32_C(   8066213), UINT32_C( 238288045),
                              UINT32_C( 830923800), UINT32_C(1378189980), UINT32_C( 185945272), UINT32_C(  88757376),
                              UINT32_C( 255255072), UINT32_C( 141006229), UINT32_C( 527472553), UINT32_C(2891870298)) },
    { simde_x_mm512_set_epu32(UINT32_C(1314482530), UINT32_C(2997716679), UINT32_C(3555959260), UINT32_C(2875927297),
                              UINT32_C(3290702646), UINT32_C(1580565751), UINT32_C(3823902839), UINT32_C(2081361826),
                              UINT32_C( 493161721), UINT32_C(3099851477), UINT32_C( 894221337), UINT32_C(2964507124),
                              UINT32_C( 492373082), UINT32_C(4281870485), UINT32_C(2207786213), UINT32_C(3953959418)),
      simde_x_mm512_set_epu32(UINT32_C(3156074065), UINT32_C(3607805659), UINT32_C(1828175063), UINT32_C(3905547273),
                              UINT32_C(4101755863), UINT32_C(3436978124), UINT32_C(3846637996), UINT32_C(2693603084),
                              UINT32_C(1710148738), UINT32_C(1974123080), UINT32_C(2870600100), UINT32_C( 118588227),
                              UINT32_C( 542053192), UINT32_C( 499863549), UINT32_C( 957375358), UINT32_C(3003933707)),
      simde_x_mm512_set_epu32(UINT32_C(1314482530), UINT32_C(2997716679), UINT32_C(1727784197), UINT32_C(2875927297),
                              UINT32_C(3290702646), UINT32_C(1580565751), UINT32_C(3823902839), UINT32_C(2081361826),
                              UINT32_C( 493161721), UINT32_C(1125728397), UINT32_C( 894221337), UINT32_C( 118389676),
                              UINT32_C( 492373082), UINT32_C( 282962093), UINT32_C( 293035497), UINT32_C( 950025711)) },
    { simde_x_mm512_set_epu32(UINT32_C(1763100483), UINT32_C(3776962737), UINT32_C(2844608398), UINT32_C(2885101098),
                              UINT32_C( 269910347), UINT32_C( 433971495), UINT32_C(1441956227), UINT32_C(1018271575),
                              UINT32_C(1734496959), UINT32_C( 380846712), UINT32_C(3352999607), UINT32_C(3555523675),
                              UINT32_C(1995198557), UINT32_C(3314312199), UINT32_C(2406584253), UINT32_C(1779168063)),
      simde_x_mm512_set_epu32(UINT32_C(3629502055), UINT32_C(3952771463), UINT32_C(2102184556), UINT32_C( 877111492),
                              UINT32_C(1183491905), UINT32_C(3718356317), UINT32_C(3233651099), UINT32_C(3486869896),
                              UINT32_C(3932090380), UINT32_C(2449576763), UINT32_C(4246346280), UINT32_C( 201516689),
                              UINT32_C(2859036576), UINT32_C(2362091228), UINT32_C(3141663427), UINT32_C( 562234020)),
      simde_x_mm512_set_epu32(UINT32_C(1763100483), UINT32_C(3776962737), UINT32_C( 742423842), UINT32_C( 253766622),
                              UINT32_C( 269910347), UINT32_C( 433971495), UINT32_C(1441956227), UINT32_C(1018271575),
                              UINT32_C(1734496959), UINT32_C( 380846712), UINT32_C(3352999607), UINT32_C( 129739962),
                              UINT32_C(1995198557), UINT32_C( 952220971), UINT32_C(2406584253), UINT32_C(  92466003)) },
    { simde_x_mm512_set_epu32(UINT32_C( 495870887), UINT32_C(3912840869), UINT32_C( 915244711), UINT32_C(   5081424),
                              UINT32_C(1422501384), UINT32_C(4130987572), UINT32_C(2778067031), UINT32_C( 497965579),
                              UINT32_C( 910061584), UINT32_C(2002226944), UINT32_C(3673004107), UINT32_C(4246624078),
                              UINT32_C( 523093293), UINT32_C(3059761572), UINT32_C(2206005509), UINT32_C(1943141679)),
      simde_x_mm512_set_epu32(UINT32_C(1206471293), UINT32_C(1374915518), UINT32_C( 531653117), UINT32_C(2075187308),
                              UINT32_C(4150348747), UINT32_C(2163101581), UINT32_C(1444783055), UINT32_C(1878625233),
                              UINT32_C(1755684145), UINT32_C(2233240925), UINT32_C(3244523643), UINT32_C(2995026741),
                              UINT32_C(2178270751), UINT32_C(1493088054), UINT32_C(4115137419), UINT32_C( 651362699)),
      simde_x_mm512_set_epu32(UINT32_C( 495870887), UINT32_C(1163009833), UINT32_C( 383591594), UINT32_C(   5081424),
                              UINT32_C(1422501384), UINT32_C(1967885991), UINT32_C(1333283976), UINT32_C( 497965579),
                              UINT32_C( 910061584), UINT32_C(2002226944), UINT32_C( 428480464), UINT32_C(1251597337),
                              UINT32_C( 523093293), UINT32_C(  73585464), UINT32_C(2206005509), UINT32_C( 640416281)) },
    { simde_x_mm512_set_epu32(UINT32_C(2657690668), UINT32_C( 448681074), UINT32_C(1334667053), UINT32_C( 502667641),
                              UINT32_C( 855395764), UINT32_C(2622874348), UINT32_C( 808531712), UINT32_C( 454488139),
                              UINT32_C( 123547093), UINT32_C( 483090439), UINT32_C(3168637539), UINT32_C(3093747107),
                              UINT32_C(4158916667), UINT32_C(4074346392), UINT32_C(1398655610), UINT32_C(1722520923)),
      simde_x_mm512_set_epu32(UINT32_C( 604721400), UINT32_C(1471174399), UINT32_C(2491026588), UINT32_C(2529574367),
                              UINT32_C( 298473775), UINT32_C(2890366559), UINT32_C(3063632375), UINT32_C(4055983958),
                              UINT32_C(4149169500), UINT32_C(4113948134), UINT32_C(2384487126), UINT32_C(2434207126),
                              UINT32_C(3923111671), UINT32_C(3188873807), UINT32_C(1982658188), UINT32_C( 863153207)),
      simde_x_mm512_set_epu32(UINT32_C( 238805068), UINT32_C( 448681074), UINT32_C(1334667053), UINT32_C( 502667641),
                              UINT32_C( 258448214), UINT32_C(2622874348), UINT32_C( 808531712), UINT32_C( 454488139),
                              UINT32_C( 123547093), UINT32_C( 483090439), UINT32_C( 784150413), UINT32_C( 659539981),
                              UINT32_C( 235804996), UINT32_C( 885472585), UINT32_C(1398655610), UINT32_C( 859367716)) },
    { simde_x_mm512_set_epu32(UINT32_C(1463758672), UINT32_C( 602211615), UINT32_C(3830002991), UINT32_C(2864741101),
                              UINT32_C( 797104998), UINT32_C(2737423319), UINT32_C(3342229886), UINT32_C( 178625368),
                              UINT32_C(3091160996), UINT32_C(1095216728), UINT32_C(3079561742), UINT32_C( 430790402),
                              UINT32_C(3213858818), UINT32_C(2113970745), UINT32_C(4112838454), UINT32_C( 564512596)),
      simde_x_mm512_set_epu32(UINT32_C(1997049765), UINT32_C( 505563651), UINT32_C( 463125220), UINT32_C(3843753777),
                              UINT32_C(2346173843), UINT32_C(2157864934), UINT32_C(2591157969), UINT32_C( 389679318),
                              UINT32_C(3939775129), UINT32_C(2493364907), UINT32_C(2006619059), UINT32_C(3391409164),
                              UINT32_C(1533151625), UINT32_C(2122196136), UINT32_C(1690360675), UINT32_C(1484935627)),
      simde_x_mm512_set_epu32(UINT32_C(1463758672), UINT32_C(  96647964), UINT32_C( 125001231), UINT32_C(2864741101),
                              UINT32_C( 797104998), UINT32_C( 579558385), UINT32_C( 751071917), UINT32_C( 178625368),
                              UINT32_C(3091160996), UINT32_C(1095216728), UINT32_C(1072942683), UINT32_C( 430790402),
                              UINT32_C( 147555568), UINT32_C(2113970745), UINT32_C( 732117104), UINT32_C( 564512596)) },
    { simde_x_mm512_set_epu32(UINT32_C( 908815803), UINT32_C(2319376026), UINT32_C(2065037155), UINT32_C( 623932649),
                              UINT32_C(1610322797), UINT32_C(3452844305), UINT32_C(2031682359), UINT32_C(2994836943),
                              UINT32_C(2344919086), UINT32_C( 238137788), UINT32_C(1978166020), UINT32_C(  76768592),
                              UINT32_C(4043825594), UINT32_C(1274901810), UINT32_C( 413860084), UINT32_C( 550494320)),
      simde_x_mm512_set_epu32(UINT32_C(1228958503), UINT32_C(3519587969), UINT32_C(2809504529), UINT32_C(3115789449),
                              UINT32_C(1767270276), UINT32_C( 490610321), UINT32_C(1164436618), UINT32_C(2374669797),
                              UINT32_C(3604002618), UINT32_C(3414719029), UINT32_C(2289333019), UINT32_C(2213872499),
                              UINT32_C(1572579389), UINT32_C(3511888959), UINT32_C(2399346014), UINT32_C(1967093325)),
      simde_x_mm512_set_epu32(UINT32_C( 908815803), UINT32_C(2319376026), UINT32_C(2065037155), UINT32_C( 623932649),
                              UINT32_C(1610322797), UINT32_C(  18572058), UINT32_C( 867245741), UINT32_C( 620167146),
                              UINT32_C(2344919086), UINT32_C( 238137788), UINT32_C(1978166020), UINT32_C(  76768592),
                              UINT32_C( 898666816), UINT32_C(1274901810), UINT32_C( 413860084), UINT32_C( 550494320)) },
    { simde_x_mm512_set_epu32(UINT32_C(1245407235), UINT32_C(4175005098), UINT32_C(2362914327), UINT32_C(2924553042),
                              UINT32_C(2369006988), UINT32_C(2119408419), UINT32_C(3091878410), UINT32_C(3978436943),
                              UINT32_C(1708684203), UINT32_C(1202455481), UINT32_C(2187745469), UINT32_C(3284847806),
                              UINT32_C(3884897233), UINT32_C(2094036024), UINT32_C(2456834182), UINT32_C(  69201629)),
      simde_x_mm512_set_epu32(UINT32_C(3914271744), UINT32_C( 565328458), UINT32_C(4201942548), UINT32_C(1480532604),
                              UINT32_C(4197506536), UINT32_C(3712719696), UINT32_C(3920217826), UINT32_C(1394313506),
                              UINT32_C( 394553965), UINT32_C(2278253176), UINT32_C(1697927724), UINT32_C(2383307765),
                              UINT32_C( 143428987), UINT32_C(3684943081), UINT32_C( 582607980), UINT32_C(1609326889)),
      simde_x_mm512_set_epu32(UINT32_C(1245407235), UINT32_C( 217705892), UINT32_C(2362914327), UINT32_C(1444020438),
                              UINT32_C(2369006988), UINT32_C(2119408419), UINT32_C(3091878410), UINT32_C(1189809931),
                              UINT32_C( 130468343), UINT32_C(1202455481), UINT32_C( 489817745), UINT32_C( 901540041),
                              UINT32_C(  12314584), UINT32_C(2094036024), UINT32_C( 126402262), UINT32_C(  69201629)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_rem_epu32(test_vec[i].a, test_vec[i].b);
    simde_assert_m512i_u32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_rem_epu64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512i a;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {
    { simde_x_mm512_set_epu64(UINT64_C( 2968342496979776051), UINT64_C(10005265515001776413),
                              UINT64_C(16837535683400356038), UINT64_C( 6738163160628300797),
                              UINT64_C(13810255550447513201), UINT64_C( 6479913377553186648),
                              UINT64_C( 7505871096235581515), UINT64_C( 2265477367564496986)),
      simde_x_mm512_set_epu64(UINT64_C(10866939104613927783), UINT64_C(11375825163207743431),
                              UINT64_C(11633520338587575573), UINT64_C(  216242550290965460),
                              UINT64_C( 5120732502404950997), UINT64_C( 5681284513410730040),
                              UINT64_C( 6409558907924801050), UINT64_C( 5372227444888762251)),
      simde_x_mm512_set_epu64(UINT64_C( 2968342496979776051), UINT64_C(10005265515001776413),
                              UINT64_C( 5204015344812780465), UINT64_C(   34644101608371537),
                              UINT64_C( 3568790545637611207), UINT64_C(  798628864142456608),
                              UINT64_C( 1096312188310780465), UINT64_C( 2265477367564496986)) },
    { simde_x_mm512_set_epu64(UINT64_C( 5645659480511055559), UINT64_C(15272728730484288257),
                              UINT64_C(14133460247011230967), UINT64_C(16423537638667915170),
                              UINT64_C( 2118113466433927893), UINT64_C( 3840651400764901876),
                              UINT64_C( 2114726288902596757), UINT64_C( 9482369585348649466)),
      simde_x_mm512_set_epu64(UINT64_C(13555234896536583899), UINT64_C( 7851952110853286921),
                              UINT64_C(17616907291198234572), UINT64_C(16521184395064581900),
                              UINT64_C( 7345032902979795528), UINT64_C(12329133549512917827),
                              UINT64_C( 2328100732832272381), UINT64_C( 4111895855610225675)),
      simde_x_mm512_set_epu64(UINT64_C( 5645659480511055559), UINT64_C( 7420776619631001336),
                              UINT64_C(14133460247011230967), UINT64_C(16423537638667915170),
                              UINT64_C( 2118113466433927893), UINT64_C( 3840651400764901876),
                              UINT64_C( 2114726288902596757), UINT64_C( 1258577874128198116)) },
    { simde_x_mm512_set_epu64(UINT64_C( 7572458917823766705), UINT64_C(12217500042222052906),
                              UINT64_C( 1159256113650983207), UINT64_C( 6193154838246823767),
                              UINT64_C( 7449607714297299576), UINT64_C(14401023659121376347),
                              UINT64_C( 8569312554655704071), UINT64_C(10336200663482757951)),
      simde_x_mm512_set_epu64(UINT64_C(15588592630942564743), UINT64_C( 9028813919053392068),
                              UINT64_C( 5083059030774095197), UINT64_C(13888425720366328200),
                              UINT64_C(16888199589465789243), UINT64_C(18237918400292775569),
                              UINT64_C(12279468594349909724), UINT64_C(13493341674566517412)),
      simde_x_mm512_set_epu64(UINT64_C( 7572458917823766705), UINT64_C( 3188686123168660838),
                              UINT64_C( 1159256113650983207), UINT64_C( 6193154838246823767),
                              UINT64_C( 7449607714297299576), UINT64_C(14401023659121376347),
                              UINT64_C( 8569312554655704071), UINT64_C(10336200663482757951)) },
    { simde_x_mm512_set_epu64(UINT64_C( 2129749246616352421), UINT64_C( 3930946101587052880),
                              UINT64_C( 6109596926925725236), UINT64_C(11931707044738783755),
                              UINT64_C( 3908684742628183808), UINT64_C(15775432521885308750),
                              UINT64_C( 2246668589251707300), UINT64_C( 9474721517893975343)),
      simde_x_mm512_set_epu64(UINT64_C( 5181754748372749246), UINT64_C( 2283432752406648940),
                              UINT64_C(17825612137522679693), UINT64_C( 6205295972918594513),
                              UINT64_C( 7540605987113962845), UINT64_C(13935122940778806069),
                              UINT64_C( 9355601638871447350), UINT64_C(17674380633802211723)),
      simde_x_mm512_set_epu64(UINT64_C( 2129749246616352421), UINT64_C( 1647513349180403940),
                              UINT64_C( 6109596926925725236), UINT64_C( 5726411071820189242),
                              UINT64_C( 3908684742628183808), UINT64_C( 1840309581106502681),
                              UINT64_C( 2246668589251707300), UINT64_C( 9474721517893975343)) },
    { simde_x_mm512_set_epu64(UINT64_C(11414694502393074802), UINT64_C( 5732351344186366329),
                              UINT64_C( 3673896834139808492), UINT64_C( 3472617261273378891),
                              UINT64_C(  530630724433960967), UINT64_C(13609194605976671651),
                              UINT64_C(17862411075628668824), UINT64_C( 6007180105039451483)),
      simde_x_mm512_set_epu64(UINT64_C( 2597258637662508799), UINT64_C(10698877731456040415),
                              UINT64_C( 1281935105229028959), UINT64_C(13158200861647791958),
                              UINT64_C(17820547312174620134), UINT64_C(10241294226337238422),
                              UINT64_C(16849636328689785423), UINT64_C( 8515452077469772855)),
      simde_x_mm512_set_epu64(UINT64_C( 1025659951743039606), UINT64_C( 5732351344186366329),
                              UINT64_C( 1110026623681750574), UINT64_C( 3472617261273378891),
                              UINT64_C(  530630724433960967), UINT64_C( 3367900379639433229),
                              UINT64_C( 1012774746938883401), UINT64_C( 6007180105039451483)) },
    { simde_x_mm512_set_epu64(UINT64_C( 6286795626078602527), UINT64_C(16449737592791923437),
                              UINT64_C( 3423539900625568727), UINT64_C(14354768056262433624),
                              UINT64_C(13276435385586003544), UINT64_C(13226616968333580034),
                              UINT64_C(13803418519385186873), UINT64_C(17664506654225712980)),
      simde_x_mm512_set_epu64(UINT64_C( 8577263429665049091), UINT64_C( 1989107677696558897),
                              UINT64_C(10076739928573503462), UINT64_C(11128938736014461142),
                              UINT64_C(16921205335142546091), UINT64_C( 8618363237326703628),
                              UINT64_C( 6584836091306452136), UINT64_C( 7260043819054420427)),
      simde_x_mm512_set_epu64(UINT64_C( 6286795626078602527), UINT64_C(  536876171219452261),
                              UINT64_C( 3423539900625568727), UINT64_C( 3225829320247972482),
                              UINT64_C(13276435385586003544), UINT64_C( 4608253731006876406),
                              UINT64_C(  633746336772282601), UINT64_C( 3144419016116872126)) },
    { simde_x_mm512_set_epu64(UINT64_C( 3903334154292354714), UINT64_C( 8869267046373815529),
                              UINT64_C( 6916283752571091217), UINT64_C( 8726009290759968207),
                              UINT64_C(10071350786374349244), UINT64_C( 8496158362035250512),
                              UINT64_C(17368098678232675634), UINT64_C( 1777515526450307184)),
      simde_x_mm512_set_epu64(UINT64_C( 5278336582045705857), UINT64_C(12066730073134673033),
                              UINT64_C( 7590368039103504017), UINT64_C( 5001217194949514725),
                              UINT64_C(15479073382423099957), UINT64_C( 9832610448471819123),
                              UINT64_C( 6754177049630551103), UINT64_C(10305112663885051469)),
      simde_x_mm512_set_epu64(UINT64_C( 3903334154292354714), UINT64_C( 8869267046373815529),
                              UINT64_C( 6916283752571091217), UINT64_C( 3724792095810453482),
                              UINT64_C(10071350786374349244), UINT64_C( 8496158362035250512),
                              UINT64_C( 3859744578971573428), UINT64_C( 1777515526450307184)) },
    { simde_x_mm512_set_epu64(UINT64_C( 5348983348701791658), UINT64_C(10148639760639402834),
                              UINT64_C(10174807539574872867), UINT64_C(13279516658136916303),
                              UINT64_C( 7338742772279280569), UINT64_C( 9396295244612029630),
                              UINT64_C(16685506566149927992), UINT64_C(10552022463454113501)),
      simde_x_mm512_set_epu64(UINT64_C(16811669128702212682), UINT64_C(18047205824811442812),
                              UINT64_C(18028153300578966352), UINT64_C(16837207357260532002),
                              UINT64_C( 1694596378460381816), UINT64_C( 7292544047935022069),
                              UINT64_C(  616022812148352233), UINT64_C( 2502282222097948969)),
      simde_x_mm512_set_epu64(UINT64_C( 5348983348701791658), UINT64_C(10148639760639402834),
                              UINT64_C(10174807539574872867), UINT64_C(13279516658136916303),
                              UINT64_C(  560357258437753305), UINT64_C( 2103751196677007561),
                              UINT64_C(   52890638144417701), UINT64_C(  542893575062317625)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_rem_epu64(test_vec[i].a, test_vec[i].b);
    simde_assert_m512i_u64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_sin_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -186.21), SIMDE_FLOAT32_C(    39.01), SIMDE_FLOAT32_C(  -754.38), SIMDE_FLOAT32_C(   346.63)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.76), SIMDE_FLOAT32_C(     0.97), SIMDE_FLOAT32_C(    -0.39), SIMDE_FLOAT32_C(     0.87)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   497.31), SIMDE_FLOAT32_C(   670.24), SIMDE_FLOAT32_C(  -297.45), SIMDE_FLOAT32_C(    34.06)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.81), SIMDE_FLOAT32_C(    -0.88), SIMDE_FLOAT32_C(    -0.84), SIMDE_FLOAT32_C(     0.48)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   825.53), SIMDE_FLOAT32_C(   422.21), SIMDE_FLOAT32_C(  -269.45), SIMDE_FLOAT32_C(   467.76)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.65), SIMDE_FLOAT32_C(     0.94), SIMDE_FLOAT32_C(     0.66), SIMDE_FLOAT32_C(     0.33)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -678.17), SIMDE_FLOAT32_C(  -686.13), SIMDE_FLOAT32_C(    84.77), SIMDE_FLOAT32_C(   571.46)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.40), SIMDE_FLOAT32_C(    -0.95), SIMDE_FLOAT32_C(     0.05), SIMDE_FLOAT32_C(    -0.30)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -305.07), SIMDE_FLOAT32_C(  -860.95), SIMDE_FLOAT32_C(  -417.54), SIMDE_FLOAT32_C(   696.87)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.33), SIMDE_FLOAT32_C(    -0.15), SIMDE_FLOAT32_C(    -0.29), SIMDE_FLOAT32_C(    -0.53)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -444.81), SIMDE_FLOAT32_C(    28.47), SIMDE_FLOAT32_C(  -384.03), SIMDE_FLOAT32_C(  -923.64)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.96), SIMDE_FLOAT32_C(    -0.19), SIMDE_FLOAT32_C(    -0.69), SIMDE_FLOAT32_C(    -0.01)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   261.31), SIMDE_FLOAT32_C(  -212.54), SIMDE_FLOAT32_C(  -976.55), SIMDE_FLOAT32_C(  -660.80)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    -0.53), SIMDE_FLOAT32_C(     0.89), SIMDE_FLOAT32_C(    -0.47), SIMDE_FLOAT32_C(    -0.88)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   178.20), SIMDE_FLOAT32_C(  -450.67), SIMDE_FLOAT32_C(   233.37), SIMDE_FLOAT32_C(   687.09)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.76), SIMDE_FLOAT32_C(     0.99), SIMDE_FLOAT32_C(     0.78), SIMDE_FLOAT32_C(     0.79)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_sin_ps(test_vec[i].a);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_sin_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -754.38), SIMDE_FLOAT64_C(  346.63)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -0.39), SIMDE_FLOAT64_C(    0.87)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -186.21), SIMDE_FLOAT64_C(   39.01)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.76), SIMDE_FLOAT64_C(    0.97)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -297.45), SIMDE_FLOAT64_C(   34.06)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -0.84), SIMDE_FLOAT64_C(    0.48)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  497.31), SIMDE_FLOAT64_C(  670.24)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.81), SIMDE_FLOAT64_C(   -0.88)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -269.45), SIMDE_FLOAT64_C(  467.76)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.66), SIMDE_FLOAT64_C(    0.33)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  825.53), SIMDE_FLOAT64_C(  422.21)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.65), SIMDE_FLOAT64_C(    0.94)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   84.77), SIMDE_FLOAT64_C(  571.46)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.05), SIMDE_FLOAT64_C(   -0.30)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -678.17), SIMDE_FLOAT64_C( -686.13)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.40), SIMDE_FLOAT64_C(   -0.95)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_sin_pd(test_vec[i].a);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_sin_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   497.31), SIMDE_FLOAT32_C(   670.24),
                         SIMDE_FLOAT32_C(  -297.45), SIMDE_FLOAT32_C(    34.06),
                         SIMDE_FLOAT32_C(  -186.21), SIMDE_FLOAT32_C(    39.01),
                         SIMDE_FLOAT32_C(  -754.38), SIMDE_FLOAT32_C(   346.63)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     0.81), SIMDE_FLOAT32_C(    -0.88),
                         SIMDE_FLOAT32_C(    -0.84), SIMDE_FLOAT32_C(     0.48),
                         SIMDE_FLOAT32_C(     0.76), SIMDE_FLOAT32_C(     0.97),
                         SIMDE_FLOAT32_C(    -0.39), SIMDE_FLOAT32_C(     0.87)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -678.17), SIMDE_FLOAT32_C(  -686.13),
                         SIMDE_FLOAT32_C(    84.77), SIMDE_FLOAT32_C(   571.46),
                         SIMDE_FLOAT32_C(   825.53), SIMDE_FLOAT32_C(   422.21),
                         SIMDE_FLOAT32_C(  -269.45), SIMDE_FLOAT32_C(   467.76)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     0.40), SIMDE_FLOAT32_C(    -0.95),
                         SIMDE_FLOAT32_C(     0.05), SIMDE_FLOAT32_C(    -0.30),
                         SIMDE_FLOAT32_C(     0.65), SIMDE_FLOAT32_C(     0.94),
                         SIMDE_FLOAT32_C(     0.66), SIMDE_FLOAT32_C(     0.33)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -444.81), SIMDE_FLOAT32_C(    28.47),
                         SIMDE_FLOAT32_C(  -384.03), SIMDE_FLOAT32_C(  -923.64),
                         SIMDE_FLOAT32_C(  -305.07), SIMDE_FLOAT32_C(  -860.95),
                         SIMDE_FLOAT32_C(  -417.54), SIMDE_FLOAT32_C(   696.87)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     0.96), SIMDE_FLOAT32_C(    -0.19),
                         SIMDE_FLOAT32_C(    -0.69), SIMDE_FLOAT32_C(    -0.01),
                         SIMDE_FLOAT32_C(     0.33), SIMDE_FLOAT32_C(    -0.15),
                         SIMDE_FLOAT32_C(    -0.29), SIMDE_FLOAT32_C(    -0.53)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   178.20), SIMDE_FLOAT32_C(  -450.67),
                         SIMDE_FLOAT32_C(   233.37), SIMDE_FLOAT32_C(   687.09),
                         SIMDE_FLOAT32_C(   261.31), SIMDE_FLOAT32_C(  -212.54),
                         SIMDE_FLOAT32_C(  -976.55), SIMDE_FLOAT32_C(  -660.80)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     0.76), SIMDE_FLOAT32_C(     0.99),
                         SIMDE_FLOAT32_C(     0.78), SIMDE_FLOAT32_C(     0.79),
                         SIMDE_FLOAT32_C(    -0.53), SIMDE_FLOAT32_C(     0.89),
                         SIMDE_FLOAT32_C(    -0.47), SIMDE_FLOAT32_C(    -0.88)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -770.35), SIMDE_FLOAT32_C(   443.48),
                         SIMDE_FLOAT32_C(  -583.60), SIMDE_FLOAT32_C(   380.46),
                         SIMDE_FLOAT32_C(  -770.72), SIMDE_FLOAT32_C(   993.90),
                         SIMDE_FLOAT32_C(    28.08), SIMDE_FLOAT32_C(   841.21)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     0.61), SIMDE_FLOAT32_C(    -0.49),
                         SIMDE_FLOAT32_C(     0.67), SIMDE_FLOAT32_C(    -0.32),
                         SIMDE_FLOAT32_C(     0.86), SIMDE_FLOAT32_C(     0.92),
                         SIMDE_FLOAT32_C(     0.19), SIMDE_FLOAT32_C(    -0.67)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -387.90), SIMDE_FLOAT32_C(   395.92),
                         SIMDE_FLOAT32_C(   655.87), SIMDE_FLOAT32_C(   339.21),
                         SIMDE_FLOAT32_C(   532.35), SIMDE_FLOAT32_C(  -263.99),
                         SIMDE_FLOAT32_C(   780.64), SIMDE_FLOAT32_C(   -30.79)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(     0.08),
                         SIMDE_FLOAT32_C(     0.66), SIMDE_FLOAT32_C(    -0.08),
                         SIMDE_FLOAT32_C(    -0.99), SIMDE_FLOAT32_C(    -0.10),
                         SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(     0.59)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -203.65), SIMDE_FLOAT32_C(   -80.73),
                         SIMDE_FLOAT32_C(   336.73), SIMDE_FLOAT32_C(  -944.78),
                         SIMDE_FLOAT32_C(  -747.59), SIMDE_FLOAT32_C(  -767.23),
                         SIMDE_FLOAT32_C(  -554.19), SIMDE_FLOAT32_C(   398.82)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    -0.53), SIMDE_FLOAT32_C(     0.81),
                         SIMDE_FLOAT32_C(    -0.55), SIMDE_FLOAT32_C(    -0.74),
                         SIMDE_FLOAT32_C(     0.11), SIMDE_FLOAT32_C(    -0.63),
                         SIMDE_FLOAT32_C(    -0.96), SIMDE_FLOAT32_C(     0.16)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   469.66), SIMDE_FLOAT32_C(   680.02),
                         SIMDE_FLOAT32_C(  -148.69), SIMDE_FLOAT32_C(   818.66),
                         SIMDE_FLOAT32_C(   910.03), SIMDE_FLOAT32_C(   600.47),
                         SIMDE_FLOAT32_C(   791.23), SIMDE_FLOAT32_C(   254.31)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    -1.00), SIMDE_FLOAT32_C(     0.99),
                         SIMDE_FLOAT32_C(     0.86), SIMDE_FLOAT32_C(     0.96),
                         SIMDE_FLOAT32_C(    -0.86), SIMDE_FLOAT32_C(    -0.41),
                         SIMDE_FLOAT32_C(    -0.44), SIMDE_FLOAT32_C(     0.16)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_sin_ps(test_vec[i].a);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_sin_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -186.21), SIMDE_FLOAT64_C(   39.01),
                         SIMDE_FLOAT64_C( -754.38), SIMDE_FLOAT64_C(  346.63)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.76), SIMDE_FLOAT64_C(    0.97),
                         SIMDE_FLOAT64_C(   -0.39), SIMDE_FLOAT64_C(    0.87)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  497.31), SIMDE_FLOAT64_C(  670.24),
                         SIMDE_FLOAT64_C( -297.45), SIMDE_FLOAT64_C(   34.06)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.81), SIMDE_FLOAT64_C(   -0.88),
                         SIMDE_FLOAT64_C(   -0.84), SIMDE_FLOAT64_C(    0.48)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  825.53), SIMDE_FLOAT64_C(  422.21),
                         SIMDE_FLOAT64_C( -269.45), SIMDE_FLOAT64_C(  467.76)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.65), SIMDE_FLOAT64_C(    0.94),
                         SIMDE_FLOAT64_C(    0.66), SIMDE_FLOAT64_C(    0.33)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -678.17), SIMDE_FLOAT64_C( -686.13),
                         SIMDE_FLOAT64_C(   84.77), SIMDE_FLOAT64_C(  571.46)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.40), SIMDE_FLOAT64_C(   -0.95),
                         SIMDE_FLOAT64_C(    0.05), SIMDE_FLOAT64_C(   -0.30)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -305.07), SIMDE_FLOAT64_C( -860.95),
                         SIMDE_FLOAT64_C( -417.54), SIMDE_FLOAT64_C(  696.87)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.33), SIMDE_FLOAT64_C(   -0.15),
                         SIMDE_FLOAT64_C(   -0.29), SIMDE_FLOAT64_C(   -0.53)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -444.81), SIMDE_FLOAT64_C(   28.47),
                         SIMDE_FLOAT64_C( -384.03), SIMDE_FLOAT64_C( -923.64)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.96), SIMDE_FLOAT64_C(   -0.19),
                         SIMDE_FLOAT64_C(   -0.69), SIMDE_FLOAT64_C(   -0.01)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  261.31), SIMDE_FLOAT64_C( -212.54),
                         SIMDE_FLOAT64_C( -976.55), SIMDE_FLOAT64_C( -660.80)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -0.53), SIMDE_FLOAT64_C(    0.89),
                         SIMDE_FLOAT64_C(   -0.47), SIMDE_FLOAT64_C(   -0.88)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  178.20), SIMDE_FLOAT64_C( -450.67),
                         SIMDE_FLOAT64_C(  233.37), SIMDE_FLOAT64_C(  687.09)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.76), SIMDE_FLOAT64_C(    0.99),
                         SIMDE_FLOAT64_C(    0.78), SIMDE_FLOAT64_C(    0.79)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_sin_pd(test_vec[i].a);
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_sin_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512 a;
    simde__m512 r;
  } test_vec[8] = {
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -678.17), SIMDE_FLOAT32_C(  -686.13), SIMDE_FLOAT32_C(    84.77), SIMDE_FLOAT32_C(   571.46),
                         SIMDE_FLOAT32_C(   825.53), SIMDE_FLOAT32_C(   422.21), SIMDE_FLOAT32_C(  -269.45), SIMDE_FLOAT32_C(   467.76),
                         SIMDE_FLOAT32_C(   497.31), SIMDE_FLOAT32_C(   670.24), SIMDE_FLOAT32_C(  -297.45), SIMDE_FLOAT32_C(    34.06),
                         SIMDE_FLOAT32_C(  -186.21), SIMDE_FLOAT32_C(    39.01), SIMDE_FLOAT32_C(  -754.38), SIMDE_FLOAT32_C(   346.63)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.40), SIMDE_FLOAT32_C(    -0.95), SIMDE_FLOAT32_C(     0.05), SIMDE_FLOAT32_C(    -0.30),
                         SIMDE_FLOAT32_C(     0.65), SIMDE_FLOAT32_C(     0.94), SIMDE_FLOAT32_C(     0.66), SIMDE_FLOAT32_C(     0.33),
                         SIMDE_FLOAT32_C(     0.81), SIMDE_FLOAT32_C(    -0.88), SIMDE_FLOAT32_C(    -0.84), SIMDE_FLOAT32_C(     0.48),
                         SIMDE_FLOAT32_C(     0.76), SIMDE_FLOAT32_C(     0.97), SIMDE_FLOAT32_C(    -0.39), SIMDE_FLOAT32_C(     0.87)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   178.20), SIMDE_FLOAT32_C(  -450.67), SIMDE_FLOAT32_C(   233.37), SIMDE_FLOAT32_C(   687.09),
                         SIMDE_FLOAT32_C(   261.31), SIMDE_FLOAT32_C(  -212.54), SIMDE_FLOAT32_C(  -976.55), SIMDE_FLOAT32_C(  -660.80),
                         SIMDE_FLOAT32_C(  -444.81), SIMDE_FLOAT32_C(    28.47), SIMDE_FLOAT32_C(  -384.03), SIMDE_FLOAT32_C(  -923.64),
                         SIMDE_FLOAT32_C(  -305.07), SIMDE_FLOAT32_C(  -860.95), SIMDE_FLOAT32_C(  -417.54), SIMDE_FLOAT32_C(   696.87)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.76), SIMDE_FLOAT32_C(     0.99), SIMDE_FLOAT32_C(     0.78), SIMDE_FLOAT32_C(     0.79),
                         SIMDE_FLOAT32_C(    -0.53), SIMDE_FLOAT32_C(     0.89), SIMDE_FLOAT32_C(    -0.47), SIMDE_FLOAT32_C(    -0.88),
                         SIMDE_FLOAT32_C(     0.96), SIMDE_FLOAT32_C(    -0.19), SIMDE_FLOAT32_C(    -0.69), SIMDE_FLOAT32_C(    -0.01),
                         SIMDE_FLOAT32_C(     0.33), SIMDE_FLOAT32_C(    -0.15), SIMDE_FLOAT32_C(    -0.29), SIMDE_FLOAT32_C(    -0.53)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -387.90), SIMDE_FLOAT32_C(   395.92), SIMDE_FLOAT32_C(   655.87), SIMDE_FLOAT32_C(   339.21),
                         SIMDE_FLOAT32_C(   532.35), SIMDE_FLOAT32_C(  -263.99), SIMDE_FLOAT32_C(   780.64), SIMDE_FLOAT32_C(   -30.79),
                         SIMDE_FLOAT32_C(  -770.35), SIMDE_FLOAT32_C(   443.48), SIMDE_FLOAT32_C(  -583.60), SIMDE_FLOAT32_C(   380.46),
                         SIMDE_FLOAT32_C(  -770.72), SIMDE_FLOAT32_C(   993.90), SIMDE_FLOAT32_C(    28.08), SIMDE_FLOAT32_C(   841.21)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(     0.08), SIMDE_FLOAT32_C(     0.66), SIMDE_FLOAT32_C(    -0.08),
                         SIMDE_FLOAT32_C(    -0.99), SIMDE_FLOAT32_C(    -0.10), SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(     0.59),
                         SIMDE_FLOAT32_C(     0.61), SIMDE_FLOAT32_C(    -0.49), SIMDE_FLOAT32_C(     0.67), SIMDE_FLOAT32_C(    -0.32),
                         SIMDE_FLOAT32_C(     0.86), SIMDE_FLOAT32_C(     0.92), SIMDE_FLOAT32_C(     0.19), SIMDE_FLOAT32_C(    -0.67)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   469.66), SIMDE_FLOAT32_C(   680.02), SIMDE_FLOAT32_C(  -148.69), SIMDE_FLOAT32_C(   818.66),
                         SIMDE_FLOAT32_C(   910.03), SIMDE_FLOAT32_C(   600.47), SIMDE_FLOAT32_C(   791.23), SIMDE_FLOAT32_C(   254.31),
                         SIMDE_FLOAT32_C(  -203.65), SIMDE_FLOAT32_C(   -80.73), SIMDE_FLOAT32_C(   336.73), SIMDE_FLOAT32_C(  -944.78),
                         SIMDE_FLOAT32_C(  -747.59), SIMDE_FLOAT32_C(  -767.23), SIMDE_FLOAT32_C(  -554.19), SIMDE_FLOAT32_C(   398.82)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    -1.00), SIMDE_FLOAT32_C(     0.99), SIMDE_FLOAT32_C(     0.86), SIMDE_FLOAT32_C(     0.96),
                         SIMDE_FLOAT32_C(    -0.86), SIMDE_FLOAT32_C(    -0.41), SIMDE_FLOAT32_C(    -0.44), SIMDE_FLOAT32_C(     0.16),
                         SIMDE_FLOAT32_C(    -0.53), SIMDE_FLOAT32_C(     0.81), SIMDE_FLOAT32_C(    -0.55), SIMDE_FLOAT32_C(    -0.74),
                         SIMDE_FLOAT32_C(     0.11), SIMDE_FLOAT32_C(    -0.63), SIMDE_FLOAT32_C(    -0.96), SIMDE_FLOAT32_C(     0.16)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -178.99), SIMDE_FLOAT32_C(   758.79), SIMDE_FLOAT32_C(   324.62), SIMDE_FLOAT32_C(   343.48),
                         SIMDE_FLOAT32_C(  -874.31), SIMDE_FLOAT32_C(  -797.92), SIMDE_FLOAT32_C(  -328.54), SIMDE_FLOAT32_C(  -525.83),
                         SIMDE_FLOAT32_C(  -192.31), SIMDE_FLOAT32_C(  -822.65), SIMDE_FLOAT32_C(   561.36), SIMDE_FLOAT32_C(   655.67),
                         SIMDE_FLOAT32_C(   -70.91), SIMDE_FLOAT32_C(   543.35), SIMDE_FLOAT32_C(   120.65), SIMDE_FLOAT32_C(  -171.51)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    -0.08), SIMDE_FLOAT32_C(    -1.00), SIMDE_FLOAT32_C(    -0.86), SIMDE_FLOAT32_C(    -0.87),
                         SIMDE_FLOAT32_C(    -0.81), SIMDE_FLOAT32_C(     0.04), SIMDE_FLOAT32_C(    -0.97), SIMDE_FLOAT32_C(     0.93),
                         SIMDE_FLOAT32_C(     0.62), SIMDE_FLOAT32_C(     0.43), SIMDE_FLOAT32_C(     0.83), SIMDE_FLOAT32_C(     0.80),
                         SIMDE_FLOAT32_C(    -0.97), SIMDE_FLOAT32_C(     0.15), SIMDE_FLOAT32_C(     0.95), SIMDE_FLOAT32_C(    -0.96)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   690.12), SIMDE_FLOAT32_C(   840.65), SIMDE_FLOAT32_C(   -21.09), SIMDE_FLOAT32_C(  -591.56),
                         SIMDE_FLOAT32_C(  -448.89), SIMDE_FLOAT32_C(   731.49), SIMDE_FLOAT32_C(   505.79), SIMDE_FLOAT32_C(   623.70),
                         SIMDE_FLOAT32_C(   831.02), SIMDE_FLOAT32_C(   140.67), SIMDE_FLOAT32_C(   977.36), SIMDE_FLOAT32_C(  -906.16),
                         SIMDE_FLOAT32_C(   331.34), SIMDE_FLOAT32_C(    99.93), SIMDE_FLOAT32_C(   462.95), SIMDE_FLOAT32_C(  -738.19)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    -0.86), SIMDE_FLOAT32_C(    -0.96), SIMDE_FLOAT32_C(    -0.78), SIMDE_FLOAT32_C(    -0.81),
                         SIMDE_FLOAT32_C(    -0.35), SIMDE_FLOAT32_C(     0.48), SIMDE_FLOAT32_C(     0.01), SIMDE_FLOAT32_C(     1.00),
                         SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(     0.65), SIMDE_FLOAT32_C(    -0.32), SIMDE_FLOAT32_C(    -0.98),
                         SIMDE_FLOAT32_C(    -1.00), SIMDE_FLOAT32_C(    -0.57), SIMDE_FLOAT32_C(    -0.91), SIMDE_FLOAT32_C(    -0.08)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -769.09), SIMDE_FLOAT32_C(   822.06), SIMDE_FLOAT32_C(  -573.81), SIMDE_FLOAT32_C(  -997.63),
                         SIMDE_FLOAT32_C(  -337.60), SIMDE_FLOAT32_C(   923.64), SIMDE_FLOAT32_C(   293.64), SIMDE_FLOAT32_C(  -768.12),
                         SIMDE_FLOAT32_C(  -576.22), SIMDE_FLOAT32_C(   -67.64), SIMDE_FLOAT32_C(   710.38), SIMDE_FLOAT32_C(   977.49),
                         SIMDE_FLOAT32_C(  -756.42), SIMDE_FLOAT32_C(   424.81), SIMDE_FLOAT32_C(    27.25), SIMDE_FLOAT32_C(   -95.15)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    -0.56), SIMDE_FLOAT32_C(    -0.86), SIMDE_FLOAT32_C(    -0.89), SIMDE_FLOAT32_C(     0.98),
                         SIMDE_FLOAT32_C(     0.99), SIMDE_FLOAT32_C(     0.01), SIMDE_FLOAT32_C(    -1.00), SIMDE_FLOAT32_C(    -1.00),
                         SIMDE_FLOAT32_C(     0.97), SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(     0.37), SIMDE_FLOAT32_C(    -0.44),
                         SIMDE_FLOAT32_C(    -0.65), SIMDE_FLOAT32_C(    -0.64), SIMDE_FLOAT32_C(     0.85), SIMDE_FLOAT32_C(    -0.78)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -438.19), SIMDE_FLOAT32_C(  -359.76), SIMDE_FLOAT32_C(  -752.43), SIMDE_FLOAT32_C(   -33.67),
                         SIMDE_FLOAT32_C(   932.66), SIMDE_FLOAT32_C(     7.27), SIMDE_FLOAT32_C(  -327.22), SIMDE_FLOAT32_C(  -125.20),
                         SIMDE_FLOAT32_C(  -182.45), SIMDE_FLOAT32_C(    39.93), SIMDE_FLOAT32_C(   510.85), SIMDE_FLOAT32_C(   394.67),
                         SIMDE_FLOAT32_C(    14.34), SIMDE_FLOAT32_C(  -304.73), SIMDE_FLOAT32_C(   916.26), SIMDE_FLOAT32_C(  -696.69)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(    -1.00), SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(    -0.78),
                         SIMDE_FLOAT32_C(     0.38), SIMDE_FLOAT32_C(     0.83), SIMDE_FLOAT32_C(    -0.47), SIMDE_FLOAT32_C(     0.45),
                         SIMDE_FLOAT32_C(    -0.24), SIMDE_FLOAT32_C(     0.79), SIMDE_FLOAT32_C(     0.94), SIMDE_FLOAT32_C(    -0.92),
                         SIMDE_FLOAT32_C(     0.98), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(    -0.88), SIMDE_FLOAT32_C(     0.68)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512 r = simde_mm512_sin_ps(test_vec[i].a);
    simde_assert_m512_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_mask_sin_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512 src;
    simde__mmask16 k;
    simde__m512 a;
    simde__m512 r;
  } test_vec[8] = {
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -450.67), SIMDE_FLOAT32_C(   687.09), SIMDE_FLOAT32_C(  -212.54), SIMDE_FLOAT32_C(  -660.80),
                         SIMDE_FLOAT32_C(    28.47), SIMDE_FLOAT32_C(  -923.64), SIMDE_FLOAT32_C(  -860.95), SIMDE_FLOAT32_C(   696.87),
                         SIMDE_FLOAT32_C(  -686.13), SIMDE_FLOAT32_C(   571.46), SIMDE_FLOAT32_C(   422.21), SIMDE_FLOAT32_C(   467.76),
                         SIMDE_FLOAT32_C(   670.24), SIMDE_FLOAT32_C(    34.06), SIMDE_FLOAT32_C(    39.01), SIMDE_FLOAT32_C(   346.63)),
      UINT16_C(41466),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   178.20), SIMDE_FLOAT32_C(   233.37), SIMDE_FLOAT32_C(   261.31), SIMDE_FLOAT32_C(  -976.55),
                         SIMDE_FLOAT32_C(  -444.81), SIMDE_FLOAT32_C(  -384.03), SIMDE_FLOAT32_C(  -305.07), SIMDE_FLOAT32_C(  -417.54),
                         SIMDE_FLOAT32_C(  -678.17), SIMDE_FLOAT32_C(    84.77), SIMDE_FLOAT32_C(   825.53), SIMDE_FLOAT32_C(  -269.45),
                         SIMDE_FLOAT32_C(   497.31), SIMDE_FLOAT32_C(  -297.45), SIMDE_FLOAT32_C(  -186.21), SIMDE_FLOAT32_C(  -754.38)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.76), SIMDE_FLOAT32_C(   687.09), SIMDE_FLOAT32_C(    -0.53), SIMDE_FLOAT32_C(  -660.80),
                         SIMDE_FLOAT32_C(    28.47), SIMDE_FLOAT32_C(  -923.64), SIMDE_FLOAT32_C(  -860.95), SIMDE_FLOAT32_C(    -0.29),
                         SIMDE_FLOAT32_C(     0.40), SIMDE_FLOAT32_C(     0.05), SIMDE_FLOAT32_C(     0.65), SIMDE_FLOAT32_C(     0.66),
                         SIMDE_FLOAT32_C(     0.81), SIMDE_FLOAT32_C(    34.06), SIMDE_FLOAT32_C(     0.76), SIMDE_FLOAT32_C(   346.63)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   469.66), SIMDE_FLOAT32_C(  -148.69), SIMDE_FLOAT32_C(   910.03), SIMDE_FLOAT32_C(   791.23),
                         SIMDE_FLOAT32_C(  -203.65), SIMDE_FLOAT32_C(   336.73), SIMDE_FLOAT32_C(  -747.59), SIMDE_FLOAT32_C(  -554.19),
                         SIMDE_FLOAT32_C(  -387.90), SIMDE_FLOAT32_C(   655.87), SIMDE_FLOAT32_C(   532.35), SIMDE_FLOAT32_C(   780.64),
                         SIMDE_FLOAT32_C(  -770.35), SIMDE_FLOAT32_C(  -583.60), SIMDE_FLOAT32_C(  -770.72), SIMDE_FLOAT32_C(    28.08)),
      UINT16_C(36797),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -171.51), SIMDE_FLOAT32_C(   680.02), SIMDE_FLOAT32_C(   818.66), SIMDE_FLOAT32_C(   600.47),
                         SIMDE_FLOAT32_C(   254.31), SIMDE_FLOAT32_C(   -80.73), SIMDE_FLOAT32_C(  -944.78), SIMDE_FLOAT32_C(  -767.23),
                         SIMDE_FLOAT32_C(   398.82), SIMDE_FLOAT32_C(   395.92), SIMDE_FLOAT32_C(   339.21), SIMDE_FLOAT32_C(  -263.99),
                         SIMDE_FLOAT32_C(   -30.79), SIMDE_FLOAT32_C(   443.48), SIMDE_FLOAT32_C(   380.46), SIMDE_FLOAT32_C(   993.90)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    -0.96), SIMDE_FLOAT32_C(  -148.69), SIMDE_FLOAT32_C(   910.03), SIMDE_FLOAT32_C(   791.23),
                         SIMDE_FLOAT32_C(     0.16), SIMDE_FLOAT32_C(     0.81), SIMDE_FLOAT32_C(    -0.74), SIMDE_FLOAT32_C(    -0.63),
                         SIMDE_FLOAT32_C(     0.16), SIMDE_FLOAT32_C(   655.87), SIMDE_FLOAT32_C(    -0.08), SIMDE_FLOAT32_C(    -0.10),
                         SIMDE_FLOAT32_C(     0.59), SIMDE_FLOAT32_C(    -0.49), SIMDE_FLOAT32_C(  -770.72), SIMDE_FLOAT32_C(     0.92)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   -95.15), SIMDE_FLOAT32_C(   840.65), SIMDE_FLOAT32_C(  -591.56), SIMDE_FLOAT32_C(   731.49),
                         SIMDE_FLOAT32_C(   623.70), SIMDE_FLOAT32_C(   140.67), SIMDE_FLOAT32_C(  -906.16), SIMDE_FLOAT32_C(    99.93),
                         SIMDE_FLOAT32_C(  -738.19), SIMDE_FLOAT32_C(   758.79), SIMDE_FLOAT32_C(   343.48), SIMDE_FLOAT32_C(  -797.92),
                         SIMDE_FLOAT32_C(  -525.83), SIMDE_FLOAT32_C(  -822.65), SIMDE_FLOAT32_C(   655.67), SIMDE_FLOAT32_C(   543.35)),
      UINT16_C(16804),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    27.25), SIMDE_FLOAT32_C(   690.12), SIMDE_FLOAT32_C(   -21.09), SIMDE_FLOAT32_C(  -448.89),
                         SIMDE_FLOAT32_C(   505.79), SIMDE_FLOAT32_C(   831.02), SIMDE_FLOAT32_C(   977.36), SIMDE_FLOAT32_C(   331.34),
                         SIMDE_FLOAT32_C(   462.95), SIMDE_FLOAT32_C(  -178.99), SIMDE_FLOAT32_C(   324.62), SIMDE_FLOAT32_C(  -874.31),
                         SIMDE_FLOAT32_C(  -328.54), SIMDE_FLOAT32_C(  -192.31), SIMDE_FLOAT32_C(   561.36), SIMDE_FLOAT32_C(   -70.91)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   -95.15), SIMDE_FLOAT32_C(    -0.86), SIMDE_FLOAT32_C(  -591.56), SIMDE_FLOAT32_C(   731.49),
                         SIMDE_FLOAT32_C(   623.70), SIMDE_FLOAT32_C(   140.67), SIMDE_FLOAT32_C(  -906.16), SIMDE_FLOAT32_C(    -1.00),
                         SIMDE_FLOAT32_C(    -0.91), SIMDE_FLOAT32_C(   758.79), SIMDE_FLOAT32_C(    -0.86), SIMDE_FLOAT32_C(  -797.92),
                         SIMDE_FLOAT32_C(  -525.83), SIMDE_FLOAT32_C(     0.62), SIMDE_FLOAT32_C(   655.67), SIMDE_FLOAT32_C(   543.35)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -348.70), SIMDE_FLOAT32_C(  -438.19), SIMDE_FLOAT32_C(  -752.43), SIMDE_FLOAT32_C(   932.66),
                         SIMDE_FLOAT32_C(  -327.22), SIMDE_FLOAT32_C(  -182.45), SIMDE_FLOAT32_C(   510.85), SIMDE_FLOAT32_C(    14.34),
                         SIMDE_FLOAT32_C(   916.26), SIMDE_FLOAT32_C(  -769.09), SIMDE_FLOAT32_C(  -573.81), SIMDE_FLOAT32_C(  -337.60),
                         SIMDE_FLOAT32_C(   293.64), SIMDE_FLOAT32_C(  -576.22), SIMDE_FLOAT32_C(   710.38), SIMDE_FLOAT32_C(  -756.42)),
      UINT16_C( 2107),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   897.27), SIMDE_FLOAT32_C(  -197.89), SIMDE_FLOAT32_C(  -359.76), SIMDE_FLOAT32_C(   -33.67),
                         SIMDE_FLOAT32_C(     7.27), SIMDE_FLOAT32_C(  -125.20), SIMDE_FLOAT32_C(    39.93), SIMDE_FLOAT32_C(   394.67),
                         SIMDE_FLOAT32_C(  -304.73), SIMDE_FLOAT32_C(  -696.69), SIMDE_FLOAT32_C(   822.06), SIMDE_FLOAT32_C(  -997.63),
                         SIMDE_FLOAT32_C(   923.64), SIMDE_FLOAT32_C(  -768.12), SIMDE_FLOAT32_C(   -67.64), SIMDE_FLOAT32_C(   977.49)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -348.70), SIMDE_FLOAT32_C(  -438.19), SIMDE_FLOAT32_C(  -752.43), SIMDE_FLOAT32_C(   932.66),
                         SIMDE_FLOAT32_C(     0.83), SIMDE_FLOAT32_C(  -182.45), SIMDE_FLOAT32_C(   510.85), SIMDE_FLOAT32_C(    14.34),
                         SIMDE_FLOAT32_C(   916.26), SIMDE_FLOAT32_C(  -769.09), SIMDE_FLOAT32_C(    -0.86), SIMDE_FLOAT32_C(     0.98),
                         SIMDE_FLOAT32_C(     0.01), SIMDE_FLOAT32_C(  -576.22), SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(    -0.44)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   -15.61), SIMDE_FLOAT32_C(  -737.13), SIMDE_FLOAT32_C(  -314.93), SIMDE_FLOAT32_C(   177.92),
                         SIMDE_FLOAT32_C(   345.93), SIMDE_FLOAT32_C(   888.71), SIMDE_FLOAT32_C(   915.71), SIMDE_FLOAT32_C(   133.52),
                         SIMDE_FLOAT32_C(   484.94), SIMDE_FLOAT32_C(  -598.06), SIMDE_FLOAT32_C(  -791.07), SIMDE_FLOAT32_C(  -765.93),
                         SIMDE_FLOAT32_C(   221.37), SIMDE_FLOAT32_C(  -788.36), SIMDE_FLOAT32_C(  -775.04), SIMDE_FLOAT32_C(   440.64)),
      UINT16_C(22274),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   496.57), SIMDE_FLOAT32_C(   915.19), SIMDE_FLOAT32_C(  -718.40), SIMDE_FLOAT32_C(   159.97),
                         SIMDE_FLOAT32_C(  -861.01), SIMDE_FLOAT32_C(   426.61), SIMDE_FLOAT32_C(   932.11), SIMDE_FLOAT32_C(   110.36),
                         SIMDE_FLOAT32_C(   826.84), SIMDE_FLOAT32_C(   -76.75), SIMDE_FLOAT32_C(   237.58), SIMDE_FLOAT32_C(  -378.50),
                         SIMDE_FLOAT32_C(  -601.68), SIMDE_FLOAT32_C(  -623.50), SIMDE_FLOAT32_C(  -942.47), SIMDE_FLOAT32_C(   475.51)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   -15.61), SIMDE_FLOAT32_C(    -0.83), SIMDE_FLOAT32_C(  -314.93), SIMDE_FLOAT32_C(     0.25),
                         SIMDE_FLOAT32_C(   345.93), SIMDE_FLOAT32_C(    -0.60), SIMDE_FLOAT32_C(     0.81), SIMDE_FLOAT32_C(    -0.39),
                         SIMDE_FLOAT32_C(   484.94), SIMDE_FLOAT32_C(  -598.06), SIMDE_FLOAT32_C(  -791.07), SIMDE_FLOAT32_C(  -765.93),
                         SIMDE_FLOAT32_C(   221.37), SIMDE_FLOAT32_C(  -788.36), SIMDE_FLOAT32_C(     0.01), SIMDE_FLOAT32_C(   440.64)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   883.05), SIMDE_FLOAT32_C(  -807.28), SIMDE_FLOAT32_C(   -70.05), SIMDE_FLOAT32_C(  -784.34),
                         SIMDE_FLOAT32_C(    92.52), SIMDE_FLOAT32_C(   206.60), SIMDE_FLOAT32_C(   834.60), SIMDE_FLOAT32_C(   -65.60),
                         SIMDE_FLOAT32_C(  -286.07), SIMDE_FLOAT32_C(  -212.86), SIMDE_FLOAT32_C(  -318.38), SIMDE_FLOAT32_C(   783.48),
                         SIMDE_FLOAT32_C(  -628.82), SIMDE_FLOAT32_C(   556.35), SIMDE_FLOAT32_C(   439.43), SIMDE_FLOAT32_C(   434.03)),
      UINT16_C(27396),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -964.25), SIMDE_FLOAT32_C(  -406.33), SIMDE_FLOAT32_C(  -743.66), SIMDE_FLOAT32_C(  -764.58),
                         SIMDE_FLOAT32_C(   789.89), SIMDE_FLOAT32_C(     4.83), SIMDE_FLOAT32_C(  -818.54), SIMDE_FLOAT32_C(   161.06),
                         SIMDE_FLOAT32_C(   579.25), SIMDE_FLOAT32_C(   -11.78), SIMDE_FLOAT32_C(  -308.52), SIMDE_FLOAT32_C(  -719.57),
                         SIMDE_FLOAT32_C(   334.00), SIMDE_FLOAT32_C(   274.71), SIMDE_FLOAT32_C(  -916.82), SIMDE_FLOAT32_C(  -490.00)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   883.05), SIMDE_FLOAT32_C(     0.87), SIMDE_FLOAT32_C(    -0.78), SIMDE_FLOAT32_C(  -784.34),
                         SIMDE_FLOAT32_C(    -0.98), SIMDE_FLOAT32_C(   206.60), SIMDE_FLOAT32_C(    -0.99), SIMDE_FLOAT32_C(    -0.74),
                         SIMDE_FLOAT32_C(  -286.07), SIMDE_FLOAT32_C(  -212.86), SIMDE_FLOAT32_C(  -318.38), SIMDE_FLOAT32_C(   783.48),
                         SIMDE_FLOAT32_C(  -628.82), SIMDE_FLOAT32_C(    -0.98), SIMDE_FLOAT32_C(   439.43), SIMDE_FLOAT32_C(   434.03)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   529.63), SIMDE_FLOAT32_C(   -24.89), SIMDE_FLOAT32_C(  -967.78), SIMDE_FLOAT32_C(   638.94),
                         SIMDE_FLOAT32_C(   450.90), SIMDE_FLOAT32_C(  -771.54), SIMDE_FLOAT32_C(   105.79), SIMDE_FLOAT32_C(   590.10),
                         SIMDE_FLOAT32_C(    30.91), SIMDE_FLOAT32_C(   635.35), SIMDE_FLOAT32_C(   -84.00), SIMDE_FLOAT32_C(    80.04),
                         SIMDE_FLOAT32_C(  -709.46), SIMDE_FLOAT32_C(   607.86), SIMDE_FLOAT32_C(   394.58), SIMDE_FLOAT32_C(  -889.11)),
      UINT16_C(  953),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    18.75), SIMDE_FLOAT32_C(   809.05), SIMDE_FLOAT32_C(   144.05), SIMDE_FLOAT32_C(  -427.72),
                         SIMDE_FLOAT32_C(   308.28), SIMDE_FLOAT32_C(  -177.05), SIMDE_FLOAT32_C(  -457.77), SIMDE_FLOAT32_C(   678.24),
                         SIMDE_FLOAT32_C(    66.05), SIMDE_FLOAT32_C(  -267.71), SIMDE_FLOAT32_C(   117.28), SIMDE_FLOAT32_C(  -576.80),
                         SIMDE_FLOAT32_C(   -38.39), SIMDE_FLOAT32_C(  -250.14), SIMDE_FLOAT32_C(   -53.92), SIMDE_FLOAT32_C(    91.94)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   529.63), SIMDE_FLOAT32_C(   -24.89), SIMDE_FLOAT32_C(  -967.78), SIMDE_FLOAT32_C(   638.94),
                         SIMDE_FLOAT32_C(   450.90), SIMDE_FLOAT32_C(  -771.54), SIMDE_FLOAT32_C(     0.78), SIMDE_FLOAT32_C(    -0.34),
                         SIMDE_FLOAT32_C(    -0.08), SIMDE_FLOAT32_C(   635.35), SIMDE_FLOAT32_C(    -0.86), SIMDE_FLOAT32_C(     0.95),
                         SIMDE_FLOAT32_C(    -0.64), SIMDE_FLOAT32_C(   607.86), SIMDE_FLOAT32_C(   394.58), SIMDE_FLOAT32_C(    -0.74)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -788.39), SIMDE_FLOAT32_C(   330.43), SIMDE_FLOAT32_C(  -493.41), SIMDE_FLOAT32_C(   822.72),
                         SIMDE_FLOAT32_C(   956.68), SIMDE_FLOAT32_C(   954.62), SIMDE_FLOAT32_C(   825.49), SIMDE_FLOAT32_C(  -816.27),
                         SIMDE_FLOAT32_C(  -209.34), SIMDE_FLOAT32_C(  -933.21), SIMDE_FLOAT32_C(  -728.70), SIMDE_FLOAT32_C(  -420.06),
                         SIMDE_FLOAT32_C(   100.32), SIMDE_FLOAT32_C(   103.15), SIMDE_FLOAT32_C(   439.77), SIMDE_FLOAT32_C(  -204.33)),
      UINT16_C(12713),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -841.43), SIMDE_FLOAT32_C(   -14.16), SIMDE_FLOAT32_C(   824.88), SIMDE_FLOAT32_C(   793.63),
                         SIMDE_FLOAT32_C(  -736.75), SIMDE_FLOAT32_C(  -310.57), SIMDE_FLOAT32_C(   728.87), SIMDE_FLOAT32_C(  -350.72),
                         SIMDE_FLOAT32_C(    60.89), SIMDE_FLOAT32_C(   109.81), SIMDE_FLOAT32_C(   715.94), SIMDE_FLOAT32_C(  -250.60),
                         SIMDE_FLOAT32_C(   944.14), SIMDE_FLOAT32_C(   361.85), SIMDE_FLOAT32_C(   -13.07), SIMDE_FLOAT32_C(   852.60)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -788.39), SIMDE_FLOAT32_C(   330.43), SIMDE_FLOAT32_C(     0.98), SIMDE_FLOAT32_C(     0.93),
                         SIMDE_FLOAT32_C(   956.68), SIMDE_FLOAT32_C(   954.62), SIMDE_FLOAT32_C(   825.49), SIMDE_FLOAT32_C(     0.91),
                         SIMDE_FLOAT32_C(    -0.93), SIMDE_FLOAT32_C(  -933.21), SIMDE_FLOAT32_C(    -0.34), SIMDE_FLOAT32_C(  -420.06),
                         SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(   103.15), SIMDE_FLOAT32_C(   439.77), SIMDE_FLOAT32_C(    -0.94)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512 r = simde_mm512_mask_sin_ps(test_vec[i].src, test_vec[i].k, test_vec[i].a);
    simde_assert_m512_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_sin_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512d a;
    simde__m512d r;
  } test_vec[8] = {
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  497.31), SIMDE_FLOAT64_C(  670.24),
                         SIMDE_FLOAT64_C( -297.45), SIMDE_FLOAT64_C(   34.06),
                         SIMDE_FLOAT64_C( -186.21), SIMDE_FLOAT64_C(   39.01),
                         SIMDE_FLOAT64_C( -754.38), SIMDE_FLOAT64_C(  346.63)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.81), SIMDE_FLOAT64_C(   -0.88),
                         SIMDE_FLOAT64_C(   -0.84), SIMDE_FLOAT64_C(    0.48),
                         SIMDE_FLOAT64_C(    0.76), SIMDE_FLOAT64_C(    0.97),
                         SIMDE_FLOAT64_C(   -0.39), SIMDE_FLOAT64_C(    0.87)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -678.17), SIMDE_FLOAT64_C( -686.13),
                         SIMDE_FLOAT64_C(   84.77), SIMDE_FLOAT64_C(  571.46),
                         SIMDE_FLOAT64_C(  825.53), SIMDE_FLOAT64_C(  422.21),
                         SIMDE_FLOAT64_C( -269.45), SIMDE_FLOAT64_C(  467.76)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.40), SIMDE_FLOAT64_C(   -0.95),
                         SIMDE_FLOAT64_C(    0.05), SIMDE_FLOAT64_C(   -0.30),
                         SIMDE_FLOAT64_C(    0.65), SIMDE_FLOAT64_C(    0.94),
                         SIMDE_FLOAT64_C(    0.66), SIMDE_FLOAT64_C(    0.33)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -444.81), SIMDE_FLOAT64_C(   28.47),
                         SIMDE_FLOAT64_C( -384.03), SIMDE_FLOAT64_C( -923.64),
                         SIMDE_FLOAT64_C( -305.07), SIMDE_FLOAT64_C( -860.95),
                         SIMDE_FLOAT64_C( -417.54), SIMDE_FLOAT64_C(  696.87)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.96), SIMDE_FLOAT64_C(   -0.19),
                         SIMDE_FLOAT64_C(   -0.69), SIMDE_FLOAT64_C(   -0.01),
                         SIMDE_FLOAT64_C(    0.33), SIMDE_FLOAT64_C(   -0.15),
                         SIMDE_FLOAT64_C(   -0.29), SIMDE_FLOAT64_C(   -0.53)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  178.20), SIMDE_FLOAT64_C( -450.67),
                         SIMDE_FLOAT64_C(  233.37), SIMDE_FLOAT64_C(  687.09),
                         SIMDE_FLOAT64_C(  261.31), SIMDE_FLOAT64_C( -212.54),
                         SIMDE_FLOAT64_C( -976.55), SIMDE_FLOAT64_C( -660.80)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.76), SIMDE_FLOAT64_C(    0.99),
                         SIMDE_FLOAT64_C(    0.78), SIMDE_FLOAT64_C(    0.79),
                         SIMDE_FLOAT64_C(   -0.53), SIMDE_FLOAT64_C(    0.89),
                         SIMDE_FLOAT64_C(   -0.47), SIMDE_FLOAT64_C(   -0.88)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -770.35), SIMDE_FLOAT64_C(  443.48),
                         SIMDE_FLOAT64_C( -583.60), SIMDE_FLOAT64_C(  380.46),
                         SIMDE_FLOAT64_C( -770.72), SIMDE_FLOAT64_C(  993.90),
                         SIMDE_FLOAT64_C(   28.08), SIMDE_FLOAT64_C(  841.21)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.61), SIMDE_FLOAT64_C(   -0.49),
                         SIMDE_FLOAT64_C(    0.67), SIMDE_FLOAT64_C(   -0.32),
                         SIMDE_FLOAT64_C(    0.86), SIMDE_FLOAT64_C(    0.92),
                         SIMDE_FLOAT64_C(    0.19), SIMDE_FLOAT64_C(   -0.67)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -387.90), SIMDE_FLOAT64_C(  395.92),
                         SIMDE_FLOAT64_C(  655.87), SIMDE_FLOAT64_C(  339.21),
                         SIMDE_FLOAT64_C(  532.35), SIMDE_FLOAT64_C( -263.99),
                         SIMDE_FLOAT64_C(  780.64), SIMDE_FLOAT64_C(  -30.79)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    1.00), SIMDE_FLOAT64_C(    0.08),
                         SIMDE_FLOAT64_C(    0.66), SIMDE_FLOAT64_C(   -0.08),
                         SIMDE_FLOAT64_C(   -0.99), SIMDE_FLOAT64_C(   -0.10),
                         SIMDE_FLOAT64_C(    1.00), SIMDE_FLOAT64_C(    0.59)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -203.65), SIMDE_FLOAT64_C(  -80.73),
                         SIMDE_FLOAT64_C(  336.73), SIMDE_FLOAT64_C( -944.78),
                         SIMDE_FLOAT64_C( -747.59), SIMDE_FLOAT64_C( -767.23),
                         SIMDE_FLOAT64_C( -554.19), SIMDE_FLOAT64_C(  398.82)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   -0.53), SIMDE_FLOAT64_C(    0.81),
                         SIMDE_FLOAT64_C(   -0.55), SIMDE_FLOAT64_C(   -0.74),
                         SIMDE_FLOAT64_C(    0.11), SIMDE_FLOAT64_C(   -0.63),
                         SIMDE_FLOAT64_C(   -0.96), SIMDE_FLOAT64_C(    0.16)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  469.66), SIMDE_FLOAT64_C(  680.02),
                         SIMDE_FLOAT64_C( -148.69), SIMDE_FLOAT64_C(  818.66),
                         SIMDE_FLOAT64_C(  910.03), SIMDE_FLOAT64_C(  600.47),
                         SIMDE_FLOAT64_C(  791.23), SIMDE_FLOAT64_C(  254.31)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   -1.00), SIMDE_FLOAT64_C(    0.99),
                         SIMDE_FLOAT64_C(    0.86), SIMDE_FLOAT64_C(    0.96),
                         SIMDE_FLOAT64_C(   -0.86), SIMDE_FLOAT64_C(   -0.41),
                         SIMDE_FLOAT64_C(   -0.44), SIMDE_FLOAT64_C(    0.16)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512d r = simde_mm512_sin_pd(test_vec[i].a);
    simde_assert_m512d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_mask_sin_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512d src;
    simde__mmask8 k;
    simde__m512d a;
    simde__m512d r;
  } test_vec[8] = {
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -686.13), SIMDE_FLOAT64_C(  571.46),
                         SIMDE_FLOAT64_C(  422.21), SIMDE_FLOAT64_C(  467.76),
                         SIMDE_FLOAT64_C(  670.24), SIMDE_FLOAT64_C(   34.06),
                         SIMDE_FLOAT64_C(   39.01), SIMDE_FLOAT64_C(  346.63)),
      UINT8_C(139),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -678.17), SIMDE_FLOAT64_C(   84.77),
                         SIMDE_FLOAT64_C(  825.53), SIMDE_FLOAT64_C( -269.45),
                         SIMDE_FLOAT64_C(  497.31), SIMDE_FLOAT64_C( -297.45),
                         SIMDE_FLOAT64_C( -186.21), SIMDE_FLOAT64_C( -754.38)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.40), SIMDE_FLOAT64_C(  571.46),
                         SIMDE_FLOAT64_C(  422.21), SIMDE_FLOAT64_C(  467.76),
                         SIMDE_FLOAT64_C(    0.81), SIMDE_FLOAT64_C(   34.06),
                         SIMDE_FLOAT64_C(    0.76), SIMDE_FLOAT64_C(   -0.39)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  178.20), SIMDE_FLOAT64_C(  233.37),
                         SIMDE_FLOAT64_C(  261.31), SIMDE_FLOAT64_C( -976.55),
                         SIMDE_FLOAT64_C( -444.81), SIMDE_FLOAT64_C( -384.03),
                         SIMDE_FLOAT64_C( -305.07), SIMDE_FLOAT64_C( -417.54)),
      UINT8_C(229),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  841.21), SIMDE_FLOAT64_C( -450.67),
                         SIMDE_FLOAT64_C(  687.09), SIMDE_FLOAT64_C( -212.54),
                         SIMDE_FLOAT64_C( -660.80), SIMDE_FLOAT64_C(   28.47),
                         SIMDE_FLOAT64_C( -923.64), SIMDE_FLOAT64_C( -860.95)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   -0.67), SIMDE_FLOAT64_C(    0.99),
                         SIMDE_FLOAT64_C(    0.79), SIMDE_FLOAT64_C( -976.55),
                         SIMDE_FLOAT64_C( -444.81), SIMDE_FLOAT64_C(   -0.19),
                         SIMDE_FLOAT64_C( -305.07), SIMDE_FLOAT64_C(   -0.15)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  398.82), SIMDE_FLOAT64_C(  395.92),
                         SIMDE_FLOAT64_C(  339.21), SIMDE_FLOAT64_C( -263.99),
                         SIMDE_FLOAT64_C(  -30.79), SIMDE_FLOAT64_C(  443.48),
                         SIMDE_FLOAT64_C(  380.46), SIMDE_FLOAT64_C(  993.90)),
      UINT8_C(253),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -554.19), SIMDE_FLOAT64_C( -387.90),
                         SIMDE_FLOAT64_C(  655.87), SIMDE_FLOAT64_C(  532.35),
                         SIMDE_FLOAT64_C(  780.64), SIMDE_FLOAT64_C( -770.35),
                         SIMDE_FLOAT64_C( -583.60), SIMDE_FLOAT64_C( -770.72)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   -0.96), SIMDE_FLOAT64_C(    1.00),
                         SIMDE_FLOAT64_C(    0.66), SIMDE_FLOAT64_C(   -0.99),
                         SIMDE_FLOAT64_C(    1.00), SIMDE_FLOAT64_C(    0.61),
                         SIMDE_FLOAT64_C(  380.46), SIMDE_FLOAT64_C(    0.86)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  120.65), SIMDE_FLOAT64_C(  469.66),
                         SIMDE_FLOAT64_C( -148.69), SIMDE_FLOAT64_C(  910.03),
                         SIMDE_FLOAT64_C(  791.23), SIMDE_FLOAT64_C( -203.65),
                         SIMDE_FLOAT64_C(  336.73), SIMDE_FLOAT64_C( -747.59)),
      UINT8_C( 93),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  543.35), SIMDE_FLOAT64_C( -171.51),
                         SIMDE_FLOAT64_C(  680.02), SIMDE_FLOAT64_C(  818.66),
                         SIMDE_FLOAT64_C(  600.47), SIMDE_FLOAT64_C(  254.31),
                         SIMDE_FLOAT64_C(  -80.73), SIMDE_FLOAT64_C( -944.78)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  120.65), SIMDE_FLOAT64_C(   -0.96),
                         SIMDE_FLOAT64_C( -148.69), SIMDE_FLOAT64_C(    0.96),
                         SIMDE_FLOAT64_C(   -0.41), SIMDE_FLOAT64_C(    0.16),
                         SIMDE_FLOAT64_C(  336.73), SIMDE_FLOAT64_C(   -0.74)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(   99.93), SIMDE_FLOAT64_C( -738.19),
                         SIMDE_FLOAT64_C(  758.79), SIMDE_FLOAT64_C(  343.48),
                         SIMDE_FLOAT64_C( -797.92), SIMDE_FLOAT64_C( -525.83),
                         SIMDE_FLOAT64_C( -822.65), SIMDE_FLOAT64_C(  655.67)),
      UINT8_C(145),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  331.34), SIMDE_FLOAT64_C(  462.95),
                         SIMDE_FLOAT64_C( -178.99), SIMDE_FLOAT64_C(  324.62),
                         SIMDE_FLOAT64_C( -874.31), SIMDE_FLOAT64_C( -328.54),
                         SIMDE_FLOAT64_C( -192.31), SIMDE_FLOAT64_C(  561.36)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   -1.00), SIMDE_FLOAT64_C( -738.19),
                         SIMDE_FLOAT64_C(  758.79), SIMDE_FLOAT64_C(   -0.86),
                         SIMDE_FLOAT64_C( -797.92), SIMDE_FLOAT64_C( -525.83),
                         SIMDE_FLOAT64_C( -822.65), SIMDE_FLOAT64_C(    0.83)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -756.42), SIMDE_FLOAT64_C(   27.25),
                         SIMDE_FLOAT64_C(  690.12), SIMDE_FLOAT64_C(  -21.09),
                         SIMDE_FLOAT64_C( -448.89), SIMDE_FLOAT64_C(  505.79),
                         SIMDE_FLOAT64_C(  831.02), SIMDE_FLOAT64_C(  977.36)),
      UINT8_C( 75),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  977.49), SIMDE_FLOAT64_C(  424.81),
                         SIMDE_FLOAT64_C(  -95.15), SIMDE_FLOAT64_C(  840.65),
                         SIMDE_FLOAT64_C( -591.56), SIMDE_FLOAT64_C(  731.49),
                         SIMDE_FLOAT64_C(  623.70), SIMDE_FLOAT64_C(  140.67)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -756.42), SIMDE_FLOAT64_C(   -0.64),
                         SIMDE_FLOAT64_C(  690.12), SIMDE_FLOAT64_C(  -21.09),
                         SIMDE_FLOAT64_C(   -0.81), SIMDE_FLOAT64_C(  505.79),
                         SIMDE_FLOAT64_C(    1.00), SIMDE_FLOAT64_C(    0.65)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  394.67), SIMDE_FLOAT64_C( -304.73),
                         SIMDE_FLOAT64_C( -696.69), SIMDE_FLOAT64_C(  822.06),
                         SIMDE_FLOAT64_C( -997.63), SIMDE_FLOAT64_C(  923.64),
                         SIMDE_FLOAT64_C( -768.12), SIMDE_FLOAT64_C(  -67.64)),
      UINT8_C( 93),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  510.85), SIMDE_FLOAT64_C(   14.34),
                         SIMDE_FLOAT64_C(  916.26), SIMDE_FLOAT64_C( -769.09),
                         SIMDE_FLOAT64_C( -573.81), SIMDE_FLOAT64_C( -337.60),
                         SIMDE_FLOAT64_C(  293.64), SIMDE_FLOAT64_C( -576.22)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  394.67), SIMDE_FLOAT64_C(    0.98),
                         SIMDE_FLOAT64_C( -696.69), SIMDE_FLOAT64_C(   -0.56),
                         SIMDE_FLOAT64_C(   -0.89), SIMDE_FLOAT64_C(    0.99),
                         SIMDE_FLOAT64_C( -768.12), SIMDE_FLOAT64_C(    0.97)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  475.51), SIMDE_FLOAT64_C(  936.65),
                         SIMDE_FLOAT64_C( -348.70), SIMDE_FLOAT64_C( -438.19),
                         SIMDE_FLOAT64_C( -752.43), SIMDE_FLOAT64_C(  932.66),
                         SIMDE_FLOAT64_C( -327.22), SIMDE_FLOAT64_C( -182.45)),
      UINT8_C(213),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -775.04), SIMDE_FLOAT64_C(  440.64),
                         SIMDE_FLOAT64_C(  897.27), SIMDE_FLOAT64_C( -197.89),
                         SIMDE_FLOAT64_C( -359.76), SIMDE_FLOAT64_C(  -33.67),
                         SIMDE_FLOAT64_C(    7.27), SIMDE_FLOAT64_C( -125.20)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   -0.80), SIMDE_FLOAT64_C(    0.73),
                         SIMDE_FLOAT64_C( -348.70), SIMDE_FLOAT64_C(   -0.03),
                         SIMDE_FLOAT64_C( -752.43), SIMDE_FLOAT64_C(   -0.78),
                         SIMDE_FLOAT64_C( -327.22), SIMDE_FLOAT64_C(    0.45)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512d r = simde_mm512_mask_sin_pd(test_vec[i].src, test_vec[i].k, test_vec[i].a);
    simde_assert_m512d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_sinh_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(     2.50), SIMDE_FLOAT32_C(     3.47), SIMDE_FLOAT32_C(     0.06), SIMDE_FLOAT32_C(     4.79)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     6.05), SIMDE_FLOAT32_C(    16.05), SIMDE_FLOAT32_C(     0.06), SIMDE_FLOAT32_C(    60.15)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(     5.44), SIMDE_FLOAT32_C(     6.18), SIMDE_FLOAT32_C(     2.02), SIMDE_FLOAT32_C(     3.45)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   115.22), SIMDE_FLOAT32_C(   241.49), SIMDE_FLOAT32_C(     3.70), SIMDE_FLOAT32_C(    15.73)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(     6.85), SIMDE_FLOAT32_C(     5.12), SIMDE_FLOAT32_C(     2.14), SIMDE_FLOAT32_C(     5.31)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   471.94), SIMDE_FLOAT32_C(    83.66), SIMDE_FLOAT32_C(     4.19), SIMDE_FLOAT32_C(   101.17)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(     0.38), SIMDE_FLOAT32_C(     0.35), SIMDE_FLOAT32_C(     3.66), SIMDE_FLOAT32_C(     5.76)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.39), SIMDE_FLOAT32_C(     0.36), SIMDE_FLOAT32_C(    19.42), SIMDE_FLOAT32_C(   158.67)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(     1.99), SIMDE_FLOAT32_C(    -0.40), SIMDE_FLOAT32_C(     1.50), SIMDE_FLOAT32_C(     6.30)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     3.59), SIMDE_FLOAT32_C(    -0.41), SIMDE_FLOAT32_C(     2.13), SIMDE_FLOAT32_C(   272.29)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(     1.39), SIMDE_FLOAT32_C(     3.42), SIMDE_FLOAT32_C(     1.65), SIMDE_FLOAT32_C(    -0.67)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     1.88), SIMDE_FLOAT32_C(    15.27), SIMDE_FLOAT32_C(     2.51), SIMDE_FLOAT32_C(    -0.72)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(     4.42), SIMDE_FLOAT32_C(     2.39), SIMDE_FLOAT32_C(    -0.90), SIMDE_FLOAT32_C(     0.46)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    41.54), SIMDE_FLOAT32_C(     5.41), SIMDE_FLOAT32_C(    -1.03), SIMDE_FLOAT32_C(     0.48)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(     4.07), SIMDE_FLOAT32_C(     1.36), SIMDE_FLOAT32_C(     4.30), SIMDE_FLOAT32_C(     6.25)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    29.27), SIMDE_FLOAT32_C(     1.82), SIMDE_FLOAT32_C(    36.84), SIMDE_FLOAT32_C(   259.01)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_sinh_ps(test_vec[i].a);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_sinh_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    0.06), SIMDE_FLOAT64_C(    4.79)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.06), SIMDE_FLOAT64_C(   60.15)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    2.50), SIMDE_FLOAT64_C(    3.47)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    6.05), SIMDE_FLOAT64_C(   16.05)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    2.02), SIMDE_FLOAT64_C(    3.45)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    3.70), SIMDE_FLOAT64_C(   15.73)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    5.44), SIMDE_FLOAT64_C(    6.18)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  115.22), SIMDE_FLOAT64_C(  241.49)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    2.14), SIMDE_FLOAT64_C(    5.31)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    4.19), SIMDE_FLOAT64_C(  101.17)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    6.85), SIMDE_FLOAT64_C(    5.12)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  471.94), SIMDE_FLOAT64_C(   83.66)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    3.66), SIMDE_FLOAT64_C(    5.76)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   19.42), SIMDE_FLOAT64_C(  158.67)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    0.38), SIMDE_FLOAT64_C(    0.35)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.39), SIMDE_FLOAT64_C(    0.36)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_sinh_pd(test_vec[i].a);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_sinh_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(     5.44), SIMDE_FLOAT32_C(     6.18),
                         SIMDE_FLOAT32_C(     2.02), SIMDE_FLOAT32_C(     3.45),
                         SIMDE_FLOAT32_C(     2.50), SIMDE_FLOAT32_C(     3.47),
                         SIMDE_FLOAT32_C(     0.06), SIMDE_FLOAT32_C(     4.79)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   115.22), SIMDE_FLOAT32_C(   241.49),
                         SIMDE_FLOAT32_C(     3.70), SIMDE_FLOAT32_C(    15.73),
                         SIMDE_FLOAT32_C(     6.05), SIMDE_FLOAT32_C(    16.05),
                         SIMDE_FLOAT32_C(     0.06), SIMDE_FLOAT32_C(    60.15)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(     0.38), SIMDE_FLOAT32_C(     0.35),
                         SIMDE_FLOAT32_C(     3.66), SIMDE_FLOAT32_C(     5.76),
                         SIMDE_FLOAT32_C(     6.85), SIMDE_FLOAT32_C(     5.12),
                         SIMDE_FLOAT32_C(     2.14), SIMDE_FLOAT32_C(     5.31)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     0.39), SIMDE_FLOAT32_C(     0.36),
                         SIMDE_FLOAT32_C(    19.42), SIMDE_FLOAT32_C(   158.67),
                         SIMDE_FLOAT32_C(   471.94), SIMDE_FLOAT32_C(    83.66),
                         SIMDE_FLOAT32_C(     4.19), SIMDE_FLOAT32_C(   101.17)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(     1.39), SIMDE_FLOAT32_C(     3.42),
                         SIMDE_FLOAT32_C(     1.65), SIMDE_FLOAT32_C(    -0.67),
                         SIMDE_FLOAT32_C(     1.99), SIMDE_FLOAT32_C(    -0.40),
                         SIMDE_FLOAT32_C(     1.50), SIMDE_FLOAT32_C(     6.30)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     1.88), SIMDE_FLOAT32_C(    15.27),
                         SIMDE_FLOAT32_C(     2.51), SIMDE_FLOAT32_C(    -0.72),
                         SIMDE_FLOAT32_C(     3.59), SIMDE_FLOAT32_C(    -0.41),
                         SIMDE_FLOAT32_C(     2.13), SIMDE_FLOAT32_C(   272.29)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(     4.07), SIMDE_FLOAT32_C(     1.36),
                         SIMDE_FLOAT32_C(     4.30), SIMDE_FLOAT32_C(     6.25),
                         SIMDE_FLOAT32_C(     4.42), SIMDE_FLOAT32_C(     2.39),
                         SIMDE_FLOAT32_C(    -0.90), SIMDE_FLOAT32_C(     0.46)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    29.27), SIMDE_FLOAT32_C(     1.82),
                         SIMDE_FLOAT32_C(    36.84), SIMDE_FLOAT32_C(   259.01),
                         SIMDE_FLOAT32_C(    41.54), SIMDE_FLOAT32_C(     5.41),
                         SIMDE_FLOAT32_C(    -1.03), SIMDE_FLOAT32_C(     0.48)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(    -0.01), SIMDE_FLOAT32_C(     5.21),
                         SIMDE_FLOAT32_C(     0.79), SIMDE_FLOAT32_C(     4.94),
                         SIMDE_FLOAT32_C(    -0.01), SIMDE_FLOAT32_C(     7.57),
                         SIMDE_FLOAT32_C(     3.42), SIMDE_FLOAT32_C(     6.92)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    -0.01), SIMDE_FLOAT32_C(    91.54),
                         SIMDE_FLOAT32_C(     0.87), SIMDE_FLOAT32_C(    69.88),
                         SIMDE_FLOAT32_C(    -0.01), SIMDE_FLOAT32_C(   969.57),
                         SIMDE_FLOAT32_C(    15.27), SIMDE_FLOAT32_C(   506.16)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(     1.63), SIMDE_FLOAT32_C(     5.00),
                         SIMDE_FLOAT32_C(     6.12), SIMDE_FLOAT32_C(     4.76),
                         SIMDE_FLOAT32_C(     5.59), SIMDE_FLOAT32_C(     2.16),
                         SIMDE_FLOAT32_C(     6.66), SIMDE_FLOAT32_C(     3.17)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     2.45), SIMDE_FLOAT32_C(    74.20),
                         SIMDE_FLOAT32_C(   227.43), SIMDE_FLOAT32_C(    58.37),
                         SIMDE_FLOAT32_C(   133.87), SIMDE_FLOAT32_C(     4.28),
                         SIMDE_FLOAT32_C(   390.27), SIMDE_FLOAT32_C(    11.88)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(     2.42), SIMDE_FLOAT32_C(     2.95),
                         SIMDE_FLOAT32_C(     4.75), SIMDE_FLOAT32_C(    -0.76),
                         SIMDE_FLOAT32_C(     0.09), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.92), SIMDE_FLOAT32_C(     5.01)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     5.58), SIMDE_FLOAT32_C(     9.53),
                         SIMDE_FLOAT32_C(    57.79), SIMDE_FLOAT32_C(    -0.84),
                         SIMDE_FLOAT32_C(     0.09), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     1.06), SIMDE_FLOAT32_C(    74.95)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(     5.32), SIMDE_FLOAT32_C(     6.22),
                         SIMDE_FLOAT32_C(     2.66), SIMDE_FLOAT32_C(     6.82),
                         SIMDE_FLOAT32_C(     7.21), SIMDE_FLOAT32_C(     5.88),
                         SIMDE_FLOAT32_C(     6.70), SIMDE_FLOAT32_C(     4.39)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   102.19), SIMDE_FLOAT32_C(   251.35),
                         SIMDE_FLOAT32_C(     7.11), SIMDE_FLOAT32_C(   457.99),
                         SIMDE_FLOAT32_C(   676.45), SIMDE_FLOAT32_C(   178.90),
                         SIMDE_FLOAT32_C(   406.20), SIMDE_FLOAT32_C(    40.31)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_sinh_ps(test_vec[i].a);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_sinh_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(    2.50), SIMDE_FLOAT64_C(    3.47),
                         SIMDE_FLOAT64_C(    0.06), SIMDE_FLOAT64_C(    4.79)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    6.05), SIMDE_FLOAT64_C(   16.05),
                         SIMDE_FLOAT64_C(    0.06), SIMDE_FLOAT64_C(   60.15)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(    5.44), SIMDE_FLOAT64_C(    6.18),
                         SIMDE_FLOAT64_C(    2.02), SIMDE_FLOAT64_C(    3.45)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  115.22), SIMDE_FLOAT64_C(  241.49),
                         SIMDE_FLOAT64_C(    3.70), SIMDE_FLOAT64_C(   15.73)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(    6.85), SIMDE_FLOAT64_C(    5.12),
                         SIMDE_FLOAT64_C(    2.14), SIMDE_FLOAT64_C(    5.31)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  471.94), SIMDE_FLOAT64_C(   83.66),
                         SIMDE_FLOAT64_C(    4.19), SIMDE_FLOAT64_C(  101.17)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.38), SIMDE_FLOAT64_C(    0.35),
                         SIMDE_FLOAT64_C(    3.66), SIMDE_FLOAT64_C(    5.76)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.39), SIMDE_FLOAT64_C(    0.36),
                         SIMDE_FLOAT64_C(   19.42), SIMDE_FLOAT64_C(  158.67)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(    1.99), SIMDE_FLOAT64_C(   -0.40),
                         SIMDE_FLOAT64_C(    1.50), SIMDE_FLOAT64_C(    6.30)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    3.59), SIMDE_FLOAT64_C(   -0.41),
                         SIMDE_FLOAT64_C(    2.13), SIMDE_FLOAT64_C(  272.29)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(    1.39), SIMDE_FLOAT64_C(    3.42),
                         SIMDE_FLOAT64_C(    1.65), SIMDE_FLOAT64_C(   -0.67)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    1.88), SIMDE_FLOAT64_C(   15.27),
                         SIMDE_FLOAT64_C(    2.51), SIMDE_FLOAT64_C(   -0.72)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(    4.42), SIMDE_FLOAT64_C(    2.39),
                         SIMDE_FLOAT64_C(   -0.90), SIMDE_FLOAT64_C(    0.46)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   41.54), SIMDE_FLOAT64_C(    5.41),
                         SIMDE_FLOAT64_C(   -1.03), SIMDE_FLOAT64_C(    0.48)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(    4.07), SIMDE_FLOAT64_C(    1.36),
                         SIMDE_FLOAT64_C(    4.30), SIMDE_FLOAT64_C(    6.25)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   29.27), SIMDE_FLOAT64_C(    1.82),
                         SIMDE_FLOAT64_C(   36.84), SIMDE_FLOAT64_C(  259.01)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_sinh_pd(test_vec[i].a);
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_sinh_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512 a;
    simde__m512 r;
  } test_vec[8] = {
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.38), SIMDE_FLOAT32_C(     0.35), SIMDE_FLOAT32_C(     3.66), SIMDE_FLOAT32_C(     5.76),
                         SIMDE_FLOAT32_C(     6.85), SIMDE_FLOAT32_C(     5.12), SIMDE_FLOAT32_C(     2.14), SIMDE_FLOAT32_C(     5.31),
                         SIMDE_FLOAT32_C(     5.44), SIMDE_FLOAT32_C(     6.18), SIMDE_FLOAT32_C(     2.02), SIMDE_FLOAT32_C(     3.45),
                         SIMDE_FLOAT32_C(     2.50), SIMDE_FLOAT32_C(     3.47), SIMDE_FLOAT32_C(     0.06), SIMDE_FLOAT32_C(     4.79)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.39), SIMDE_FLOAT32_C(     0.36), SIMDE_FLOAT32_C(    19.42), SIMDE_FLOAT32_C(   158.67),
                         SIMDE_FLOAT32_C(   471.94), SIMDE_FLOAT32_C(    83.66), SIMDE_FLOAT32_C(     4.19), SIMDE_FLOAT32_C(   101.17),
                         SIMDE_FLOAT32_C(   115.22), SIMDE_FLOAT32_C(   241.49), SIMDE_FLOAT32_C(     3.70), SIMDE_FLOAT32_C(    15.73),
                         SIMDE_FLOAT32_C(     6.05), SIMDE_FLOAT32_C(    16.05), SIMDE_FLOAT32_C(     0.06), SIMDE_FLOAT32_C(    60.15)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(     4.07), SIMDE_FLOAT32_C(     1.36), SIMDE_FLOAT32_C(     4.30), SIMDE_FLOAT32_C(     6.25),
                         SIMDE_FLOAT32_C(     4.42), SIMDE_FLOAT32_C(     2.39), SIMDE_FLOAT32_C(    -0.90), SIMDE_FLOAT32_C(     0.46),
                         SIMDE_FLOAT32_C(     1.39), SIMDE_FLOAT32_C(     3.42), SIMDE_FLOAT32_C(     1.65), SIMDE_FLOAT32_C(    -0.67),
                         SIMDE_FLOAT32_C(     1.99), SIMDE_FLOAT32_C(    -0.40), SIMDE_FLOAT32_C(     1.50), SIMDE_FLOAT32_C(     6.30)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    29.27), SIMDE_FLOAT32_C(     1.82), SIMDE_FLOAT32_C(    36.84), SIMDE_FLOAT32_C(   259.01),
                         SIMDE_FLOAT32_C(    41.54), SIMDE_FLOAT32_C(     5.41), SIMDE_FLOAT32_C(    -1.03), SIMDE_FLOAT32_C(     0.48),
                         SIMDE_FLOAT32_C(     1.88), SIMDE_FLOAT32_C(    15.27), SIMDE_FLOAT32_C(     2.51), SIMDE_FLOAT32_C(    -0.72),
                         SIMDE_FLOAT32_C(     3.59), SIMDE_FLOAT32_C(    -0.41), SIMDE_FLOAT32_C(     2.13), SIMDE_FLOAT32_C(   272.29)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(     1.63), SIMDE_FLOAT32_C(     5.00), SIMDE_FLOAT32_C(     6.12), SIMDE_FLOAT32_C(     4.76),
                         SIMDE_FLOAT32_C(     5.59), SIMDE_FLOAT32_C(     2.16), SIMDE_FLOAT32_C(     6.66), SIMDE_FLOAT32_C(     3.17),
                         SIMDE_FLOAT32_C(    -0.01), SIMDE_FLOAT32_C(     5.21), SIMDE_FLOAT32_C(     0.79), SIMDE_FLOAT32_C(     4.94),
                         SIMDE_FLOAT32_C(    -0.01), SIMDE_FLOAT32_C(     7.57), SIMDE_FLOAT32_C(     3.42), SIMDE_FLOAT32_C(     6.92)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     2.45), SIMDE_FLOAT32_C(    74.20), SIMDE_FLOAT32_C(   227.43), SIMDE_FLOAT32_C(    58.37),
                         SIMDE_FLOAT32_C(   133.87), SIMDE_FLOAT32_C(     4.28), SIMDE_FLOAT32_C(   390.27), SIMDE_FLOAT32_C(    11.88),
                         SIMDE_FLOAT32_C(    -0.01), SIMDE_FLOAT32_C(    91.54), SIMDE_FLOAT32_C(     0.87), SIMDE_FLOAT32_C(    69.88),
                         SIMDE_FLOAT32_C(    -0.01), SIMDE_FLOAT32_C(   969.57), SIMDE_FLOAT32_C(    15.27), SIMDE_FLOAT32_C(   506.16)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(     5.32), SIMDE_FLOAT32_C(     6.22), SIMDE_FLOAT32_C(     2.66), SIMDE_FLOAT32_C(     6.82),
                         SIMDE_FLOAT32_C(     7.21), SIMDE_FLOAT32_C(     5.88), SIMDE_FLOAT32_C(     6.70), SIMDE_FLOAT32_C(     4.39),
                         SIMDE_FLOAT32_C(     2.42), SIMDE_FLOAT32_C(     2.95), SIMDE_FLOAT32_C(     4.75), SIMDE_FLOAT32_C(    -0.76),
                         SIMDE_FLOAT32_C(     0.09), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.92), SIMDE_FLOAT32_C(     5.01)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   102.19), SIMDE_FLOAT32_C(   251.35), SIMDE_FLOAT32_C(     7.11), SIMDE_FLOAT32_C(   457.99),
                         SIMDE_FLOAT32_C(   676.45), SIMDE_FLOAT32_C(   178.90), SIMDE_FLOAT32_C(   406.20), SIMDE_FLOAT32_C(    40.31),
                         SIMDE_FLOAT32_C(     5.58), SIMDE_FLOAT32_C(     9.53), SIMDE_FLOAT32_C(    57.79), SIMDE_FLOAT32_C(    -0.84),
                         SIMDE_FLOAT32_C(     0.09), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     1.06), SIMDE_FLOAT32_C(    74.95)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(     2.53), SIMDE_FLOAT32_C(     6.56), SIMDE_FLOAT32_C(     4.70), SIMDE_FLOAT32_C(     4.78),
                         SIMDE_FLOAT32_C(    -0.46), SIMDE_FLOAT32_C(    -0.13), SIMDE_FLOAT32_C(     1.89), SIMDE_FLOAT32_C(     1.04),
                         SIMDE_FLOAT32_C(     2.47), SIMDE_FLOAT32_C(    -0.24), SIMDE_FLOAT32_C(     5.71), SIMDE_FLOAT32_C(     6.12),
                         SIMDE_FLOAT32_C(     3.00), SIMDE_FLOAT32_C(     5.64), SIMDE_FLOAT32_C(     3.82), SIMDE_FLOAT32_C(     2.56)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     6.24), SIMDE_FLOAT32_C(   353.14), SIMDE_FLOAT32_C(    54.97), SIMDE_FLOAT32_C(    59.55),
                         SIMDE_FLOAT32_C(    -0.48), SIMDE_FLOAT32_C(    -0.13), SIMDE_FLOAT32_C(     3.23), SIMDE_FLOAT32_C(     1.24),
                         SIMDE_FLOAT32_C(     5.87), SIMDE_FLOAT32_C(    -0.24), SIMDE_FLOAT32_C(   150.93), SIMDE_FLOAT32_C(   227.43),
                         SIMDE_FLOAT32_C(    10.02), SIMDE_FLOAT32_C(   140.73), SIMDE_FLOAT32_C(    22.79), SIMDE_FLOAT32_C(     6.43)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(     6.27), SIMDE_FLOAT32_C(     6.91), SIMDE_FLOAT32_C(     3.21), SIMDE_FLOAT32_C(     0.76),
                         SIMDE_FLOAT32_C(     1.37), SIMDE_FLOAT32_C(     6.45), SIMDE_FLOAT32_C(     5.47), SIMDE_FLOAT32_C(     5.98),
                         SIMDE_FLOAT32_C(     6.87), SIMDE_FLOAT32_C(     3.90), SIMDE_FLOAT32_C(     7.50), SIMDE_FLOAT32_C(    -0.60),
                         SIMDE_FLOAT32_C(     4.72), SIMDE_FLOAT32_C(     3.73), SIMDE_FLOAT32_C(     5.29), SIMDE_FLOAT32_C(     0.13)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   264.24), SIMDE_FLOAT32_C(   501.12), SIMDE_FLOAT32_C(    12.37), SIMDE_FLOAT32_C(     0.84),
                         SIMDE_FLOAT32_C(     1.84), SIMDE_FLOAT32_C(   316.35), SIMDE_FLOAT32_C(   118.73), SIMDE_FLOAT32_C(   197.72),
                         SIMDE_FLOAT32_C(   481.47), SIMDE_FLOAT32_C(    24.69), SIMDE_FLOAT32_C(   904.02), SIMDE_FLOAT32_C(    -0.64),
                         SIMDE_FLOAT32_C(    56.08), SIMDE_FLOAT32_C(    20.83), SIMDE_FLOAT32_C(    99.17), SIMDE_FLOAT32_C(     0.13)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(    -0.01), SIMDE_FLOAT32_C(     6.83), SIMDE_FLOAT32_C(     0.83), SIMDE_FLOAT32_C(    -0.99),
                         SIMDE_FLOAT32_C(     1.85), SIMDE_FLOAT32_C(     7.27), SIMDE_FLOAT32_C(     4.56), SIMDE_FLOAT32_C(    -0.00),
                         SIMDE_FLOAT32_C(     0.82), SIMDE_FLOAT32_C(     3.01), SIMDE_FLOAT32_C(     6.35), SIMDE_FLOAT32_C(     7.50),
                         SIMDE_FLOAT32_C(     0.05), SIMDE_FLOAT32_C(     5.13), SIMDE_FLOAT32_C(     3.42), SIMDE_FLOAT32_C(     2.89)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    -0.01), SIMDE_FLOAT32_C(   462.59), SIMDE_FLOAT32_C(     0.93), SIMDE_FLOAT32_C(    -1.16),
                         SIMDE_FLOAT32_C(     3.10), SIMDE_FLOAT32_C(   718.27), SIMDE_FLOAT32_C(    47.79), SIMDE_FLOAT32_C(    -0.00),
                         SIMDE_FLOAT32_C(     0.92), SIMDE_FLOAT32_C(    10.12), SIMDE_FLOAT32_C(   286.25), SIMDE_FLOAT32_C(   904.02),
                         SIMDE_FLOAT32_C(     0.05), SIMDE_FLOAT32_C(    84.51), SIMDE_FLOAT32_C(    15.27), SIMDE_FLOAT32_C(     8.97)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(     1.42), SIMDE_FLOAT32_C(     1.75), SIMDE_FLOAT32_C(     0.06), SIMDE_FLOAT32_C(     3.16),
                         SIMDE_FLOAT32_C(     7.31), SIMDE_FLOAT32_C(     3.33), SIMDE_FLOAT32_C(     1.89), SIMDE_FLOAT32_C(     2.76),
                         SIMDE_FLOAT32_C(     2.52), SIMDE_FLOAT32_C(     3.47), SIMDE_FLOAT32_C(     5.50), SIMDE_FLOAT32_C(     5.00),
                         SIMDE_FLOAT32_C(     3.36), SIMDE_FLOAT32_C(     1.99), SIMDE_FLOAT32_C(     7.24), SIMDE_FLOAT32_C(     0.30)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     1.95), SIMDE_FLOAT32_C(     2.79), SIMDE_FLOAT32_C(     0.06), SIMDE_FLOAT32_C(    11.76),
                         SIMDE_FLOAT32_C(   747.59), SIMDE_FLOAT32_C(    13.95), SIMDE_FLOAT32_C(     3.23), SIMDE_FLOAT32_C(     7.87),
                         SIMDE_FLOAT32_C(     6.17), SIMDE_FLOAT32_C(    16.05), SIMDE_FLOAT32_C(   122.34), SIMDE_FLOAT32_C(    74.20),
                         SIMDE_FLOAT32_C(    14.38), SIMDE_FLOAT32_C(     3.59), SIMDE_FLOAT32_C(   697.05), SIMDE_FLOAT32_C(     0.30)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512 r = simde_mm512_sinh_ps(test_vec[i].a);
    simde_assert_m512_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_mask_sinh_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512 src;
    simde__mmask16 k;
    simde__m512 a;
    simde__m512 r;
  } test_vec[8] = {
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(     1.36), SIMDE_FLOAT32_C(     6.25), SIMDE_FLOAT32_C(     2.39), SIMDE_FLOAT32_C(     0.46),
                         SIMDE_FLOAT32_C(     3.42), SIMDE_FLOAT32_C(    -0.67), SIMDE_FLOAT32_C(    -0.40), SIMDE_FLOAT32_C(     6.30),
                         SIMDE_FLOAT32_C(     0.35), SIMDE_FLOAT32_C(     5.76), SIMDE_FLOAT32_C(     5.12), SIMDE_FLOAT32_C(     5.31),
                         SIMDE_FLOAT32_C(     6.18), SIMDE_FLOAT32_C(     3.45), SIMDE_FLOAT32_C(     3.47), SIMDE_FLOAT32_C(     4.79)),
      UINT16_C(41466),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     4.07), SIMDE_FLOAT32_C(     4.30), SIMDE_FLOAT32_C(     4.42), SIMDE_FLOAT32_C(    -0.90),
                         SIMDE_FLOAT32_C(     1.39), SIMDE_FLOAT32_C(     1.65), SIMDE_FLOAT32_C(     1.99), SIMDE_FLOAT32_C(     1.50),
                         SIMDE_FLOAT32_C(     0.38), SIMDE_FLOAT32_C(     3.66), SIMDE_FLOAT32_C(     6.85), SIMDE_FLOAT32_C(     2.14),
                         SIMDE_FLOAT32_C(     5.44), SIMDE_FLOAT32_C(     2.02), SIMDE_FLOAT32_C(     2.50), SIMDE_FLOAT32_C(     0.06)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    29.27), SIMDE_FLOAT32_C(     6.25), SIMDE_FLOAT32_C(    41.54), SIMDE_FLOAT32_C(     0.46),
                         SIMDE_FLOAT32_C(     3.42), SIMDE_FLOAT32_C(    -0.67), SIMDE_FLOAT32_C(    -0.40), SIMDE_FLOAT32_C(     2.13),
                         SIMDE_FLOAT32_C(     0.39), SIMDE_FLOAT32_C(    19.42), SIMDE_FLOAT32_C(   471.94), SIMDE_FLOAT32_C(     4.19),
                         SIMDE_FLOAT32_C(   115.22), SIMDE_FLOAT32_C(     3.45), SIMDE_FLOAT32_C(     6.05), SIMDE_FLOAT32_C(     4.79)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(     5.32), SIMDE_FLOAT32_C(     2.66), SIMDE_FLOAT32_C(     7.21), SIMDE_FLOAT32_C(     6.70),
                         SIMDE_FLOAT32_C(     2.42), SIMDE_FLOAT32_C(     4.75), SIMDE_FLOAT32_C(     0.09), SIMDE_FLOAT32_C(     0.92),
                         SIMDE_FLOAT32_C(     1.63), SIMDE_FLOAT32_C(     6.12), SIMDE_FLOAT32_C(     5.59), SIMDE_FLOAT32_C(     6.66),
                         SIMDE_FLOAT32_C(    -0.01), SIMDE_FLOAT32_C(     0.79), SIMDE_FLOAT32_C(    -0.01), SIMDE_FLOAT32_C(     3.42)),
      UINT16_C(36797),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     2.56), SIMDE_FLOAT32_C(     6.22), SIMDE_FLOAT32_C(     6.82), SIMDE_FLOAT32_C(     5.88),
                         SIMDE_FLOAT32_C(     4.39), SIMDE_FLOAT32_C(     2.95), SIMDE_FLOAT32_C(    -0.76), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     5.01), SIMDE_FLOAT32_C(     5.00), SIMDE_FLOAT32_C(     4.76), SIMDE_FLOAT32_C(     2.16),
                         SIMDE_FLOAT32_C(     3.17), SIMDE_FLOAT32_C(     5.21), SIMDE_FLOAT32_C(     4.94), SIMDE_FLOAT32_C(     7.57)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     6.43), SIMDE_FLOAT32_C(     2.66), SIMDE_FLOAT32_C(     7.21), SIMDE_FLOAT32_C(     6.70),
                         SIMDE_FLOAT32_C(    40.31), SIMDE_FLOAT32_C(     9.53), SIMDE_FLOAT32_C(    -0.84), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(    74.95), SIMDE_FLOAT32_C(     6.12), SIMDE_FLOAT32_C(    58.37), SIMDE_FLOAT32_C(     4.28),
                         SIMDE_FLOAT32_C(    11.88), SIMDE_FLOAT32_C(    91.54), SIMDE_FLOAT32_C(    -0.01), SIMDE_FLOAT32_C(   969.57)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(     2.89), SIMDE_FLOAT32_C(     6.91), SIMDE_FLOAT32_C(     0.76), SIMDE_FLOAT32_C(     6.45),
                         SIMDE_FLOAT32_C(     5.98), SIMDE_FLOAT32_C(     3.90), SIMDE_FLOAT32_C(    -0.60), SIMDE_FLOAT32_C(     3.73),
                         SIMDE_FLOAT32_C(     0.13), SIMDE_FLOAT32_C(     6.56), SIMDE_FLOAT32_C(     4.78), SIMDE_FLOAT32_C(    -0.13),
                         SIMDE_FLOAT32_C(     1.04), SIMDE_FLOAT32_C(    -0.24), SIMDE_FLOAT32_C(     6.12), SIMDE_FLOAT32_C(     5.64)),
      UINT16_C(16804),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     3.42), SIMDE_FLOAT32_C(     6.27), SIMDE_FLOAT32_C(     3.21), SIMDE_FLOAT32_C(     1.37),
                         SIMDE_FLOAT32_C(     5.47), SIMDE_FLOAT32_C(     6.87), SIMDE_FLOAT32_C(     7.50), SIMDE_FLOAT32_C(     4.72),
                         SIMDE_FLOAT32_C(     5.29), SIMDE_FLOAT32_C(     2.53), SIMDE_FLOAT32_C(     4.70), SIMDE_FLOAT32_C(    -0.46),
                         SIMDE_FLOAT32_C(     1.89), SIMDE_FLOAT32_C(     2.47), SIMDE_FLOAT32_C(     5.71), SIMDE_FLOAT32_C(     3.00)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     2.89), SIMDE_FLOAT32_C(   264.24), SIMDE_FLOAT32_C(     0.76), SIMDE_FLOAT32_C(     6.45),
                         SIMDE_FLOAT32_C(     5.98), SIMDE_FLOAT32_C(     3.90), SIMDE_FLOAT32_C(    -0.60), SIMDE_FLOAT32_C(    56.08),
                         SIMDE_FLOAT32_C(    99.17), SIMDE_FLOAT32_C(     6.56), SIMDE_FLOAT32_C(    54.97), SIMDE_FLOAT32_C(    -0.13),
                         SIMDE_FLOAT32_C(     1.04), SIMDE_FLOAT32_C(     5.87), SIMDE_FLOAT32_C(     6.12), SIMDE_FLOAT32_C(     5.64)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(     1.80), SIMDE_FLOAT32_C(     1.42), SIMDE_FLOAT32_C(     0.06), SIMDE_FLOAT32_C(     7.31),
                         SIMDE_FLOAT32_C(     1.89), SIMDE_FLOAT32_C(     2.52), SIMDE_FLOAT32_C(     5.50), SIMDE_FLOAT32_C(     3.36),
                         SIMDE_FLOAT32_C(     7.24), SIMDE_FLOAT32_C(    -0.01), SIMDE_FLOAT32_C(     0.83), SIMDE_FLOAT32_C(     1.85),
                         SIMDE_FLOAT32_C(     4.56), SIMDE_FLOAT32_C(     0.82), SIMDE_FLOAT32_C(     6.35), SIMDE_FLOAT32_C(     0.05)),
      UINT16_C( 2107),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     7.16), SIMDE_FLOAT32_C(     2.45), SIMDE_FLOAT32_C(     1.75), SIMDE_FLOAT32_C(     3.16),
                         SIMDE_FLOAT32_C(     3.33), SIMDE_FLOAT32_C(     2.76), SIMDE_FLOAT32_C(     3.47), SIMDE_FLOAT32_C(     5.00),
                         SIMDE_FLOAT32_C(     1.99), SIMDE_FLOAT32_C(     0.30), SIMDE_FLOAT32_C(     6.83), SIMDE_FLOAT32_C(    -0.99),
                         SIMDE_FLOAT32_C(     7.27), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     3.01), SIMDE_FLOAT32_C(     7.50)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     1.80), SIMDE_FLOAT32_C(     1.42), SIMDE_FLOAT32_C(     0.06), SIMDE_FLOAT32_C(     7.31),
                         SIMDE_FLOAT32_C(    13.95), SIMDE_FLOAT32_C(     2.52), SIMDE_FLOAT32_C(     5.50), SIMDE_FLOAT32_C(     3.36),
                         SIMDE_FLOAT32_C(     7.24), SIMDE_FLOAT32_C(    -0.01), SIMDE_FLOAT32_C(   462.59), SIMDE_FLOAT32_C(    -1.16),
                         SIMDE_FLOAT32_C(   718.27), SIMDE_FLOAT32_C(     0.82), SIMDE_FLOAT32_C(    10.12), SIMDE_FLOAT32_C(   904.02)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(     3.23), SIMDE_FLOAT32_C(     0.13), SIMDE_FLOAT32_C(     1.95), SIMDE_FLOAT32_C(     4.07),
                         SIMDE_FLOAT32_C(     4.79), SIMDE_FLOAT32_C(     7.12), SIMDE_FLOAT32_C(     7.24), SIMDE_FLOAT32_C(     3.87),
                         SIMDE_FLOAT32_C(     5.39), SIMDE_FLOAT32_C(     0.73), SIMDE_FLOAT32_C(    -0.10), SIMDE_FLOAT32_C(     0.01),
                         SIMDE_FLOAT32_C(     4.25), SIMDE_FLOAT32_C(    -0.09), SIMDE_FLOAT32_C(    -0.03), SIMDE_FLOAT32_C(     5.19)),
      UINT16_C(22274),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     5.44), SIMDE_FLOAT32_C(     7.24), SIMDE_FLOAT32_C(     0.21), SIMDE_FLOAT32_C(     3.99),
                         SIMDE_FLOAT32_C(    -0.40), SIMDE_FLOAT32_C(     5.13), SIMDE_FLOAT32_C(     7.31), SIMDE_FLOAT32_C(     3.77),
                         SIMDE_FLOAT32_C(     6.86), SIMDE_FLOAT32_C(     2.97), SIMDE_FLOAT32_C(     4.32), SIMDE_FLOAT32_C(     1.67),
                         SIMDE_FLOAT32_C(     0.71), SIMDE_FLOAT32_C(     0.62), SIMDE_FLOAT32_C(    -0.75), SIMDE_FLOAT32_C(     5.34)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     3.23), SIMDE_FLOAT32_C(   697.05), SIMDE_FLOAT32_C(     1.95), SIMDE_FLOAT32_C(    27.02),
                         SIMDE_FLOAT32_C(     4.79), SIMDE_FLOAT32_C(    84.51), SIMDE_FLOAT32_C(   747.59), SIMDE_FLOAT32_C(    21.68),
                         SIMDE_FLOAT32_C(     5.39), SIMDE_FLOAT32_C(     0.73), SIMDE_FLOAT32_C(    -0.10), SIMDE_FLOAT32_C(     0.01),
                         SIMDE_FLOAT32_C(     4.25), SIMDE_FLOAT32_C(    -0.09), SIMDE_FLOAT32_C(    -0.82), SIMDE_FLOAT32_C(     5.19)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(     7.10), SIMDE_FLOAT32_C(    -0.17), SIMDE_FLOAT32_C(     3.00), SIMDE_FLOAT32_C(    -0.07),
                         SIMDE_FLOAT32_C(     3.70), SIMDE_FLOAT32_C(     4.19), SIMDE_FLOAT32_C(     6.89), SIMDE_FLOAT32_C(     3.02),
                         SIMDE_FLOAT32_C(     2.07), SIMDE_FLOAT32_C(     2.38), SIMDE_FLOAT32_C(     1.93), SIMDE_FLOAT32_C(     6.67),
                         SIMDE_FLOAT32_C(     0.60), SIMDE_FLOAT32_C(     5.69), SIMDE_FLOAT32_C(     5.19), SIMDE_FLOAT32_C(     5.17)),
      UINT16_C(27396),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    -0.85), SIMDE_FLOAT32_C(     1.55), SIMDE_FLOAT32_C(     0.10), SIMDE_FLOAT32_C(     0.01),
                         SIMDE_FLOAT32_C(     6.70), SIMDE_FLOAT32_C(     3.32), SIMDE_FLOAT32_C(    -0.22), SIMDE_FLOAT32_C(     3.99),
                         SIMDE_FLOAT32_C(     5.79), SIMDE_FLOAT32_C(     3.25), SIMDE_FLOAT32_C(     1.97), SIMDE_FLOAT32_C(     0.21),
                         SIMDE_FLOAT32_C(     4.74), SIMDE_FLOAT32_C(     4.48), SIMDE_FLOAT32_C(    -0.64), SIMDE_FLOAT32_C(     1.19)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     7.10), SIMDE_FLOAT32_C(     2.25), SIMDE_FLOAT32_C(     0.10), SIMDE_FLOAT32_C(    -0.07),
                         SIMDE_FLOAT32_C(   406.20), SIMDE_FLOAT32_C(     4.19), SIMDE_FLOAT32_C(    -0.22), SIMDE_FLOAT32_C(    27.02),
                         SIMDE_FLOAT32_C(     2.07), SIMDE_FLOAT32_C(     2.38), SIMDE_FLOAT32_C(     1.93), SIMDE_FLOAT32_C(     6.67),
                         SIMDE_FLOAT32_C(     0.60), SIMDE_FLOAT32_C(    44.11), SIMDE_FLOAT32_C(     5.19), SIMDE_FLOAT32_C(     5.17)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(     5.58), SIMDE_FLOAT32_C(     3.19), SIMDE_FLOAT32_C(    -0.86), SIMDE_FLOAT32_C(     6.05),
                         SIMDE_FLOAT32_C(     5.24), SIMDE_FLOAT32_C(    -0.02), SIMDE_FLOAT32_C(     3.75), SIMDE_FLOAT32_C(     5.84),
                         SIMDE_FLOAT32_C(     3.43), SIMDE_FLOAT32_C(     6.03), SIMDE_FLOAT32_C(     2.94), SIMDE_FLOAT32_C(     3.64),
                         SIMDE_FLOAT32_C(     0.25), SIMDE_FLOAT32_C(     5.91), SIMDE_FLOAT32_C(     5.00), SIMDE_FLOAT32_C(    -0.52)),
      UINT16_C(  953),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     3.38), SIMDE_FLOAT32_C(     6.78), SIMDE_FLOAT32_C(     3.92), SIMDE_FLOAT32_C(     1.46),
                         SIMDE_FLOAT32_C(     4.63), SIMDE_FLOAT32_C(     2.54), SIMDE_FLOAT32_C(     1.33), SIMDE_FLOAT32_C(     6.22),
                         SIMDE_FLOAT32_C(     3.58), SIMDE_FLOAT32_C(     2.15), SIMDE_FLOAT32_C(     3.80), SIMDE_FLOAT32_C(     0.82),
                         SIMDE_FLOAT32_C(     3.13), SIMDE_FLOAT32_C(     2.22), SIMDE_FLOAT32_C(     3.07), SIMDE_FLOAT32_C(     3.70)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     5.58), SIMDE_FLOAT32_C(     3.19), SIMDE_FLOAT32_C(    -0.86), SIMDE_FLOAT32_C(     6.05),
                         SIMDE_FLOAT32_C(     5.24), SIMDE_FLOAT32_C(    -0.02), SIMDE_FLOAT32_C(     1.76), SIMDE_FLOAT32_C(   251.35),
                         SIMDE_FLOAT32_C(    17.92), SIMDE_FLOAT32_C(     6.03), SIMDE_FLOAT32_C(    22.34), SIMDE_FLOAT32_C(     0.92),
                         SIMDE_FLOAT32_C(    11.42), SIMDE_FLOAT32_C(     5.91), SIMDE_FLOAT32_C(     5.00), SIMDE_FLOAT32_C(    20.21)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(    -0.09), SIMDE_FLOAT32_C(     4.72), SIMDE_FLOAT32_C(     1.18), SIMDE_FLOAT32_C(     6.84),
                         SIMDE_FLOAT32_C(     7.41), SIMDE_FLOAT32_C(     7.40), SIMDE_FLOAT32_C(     6.85), SIMDE_FLOAT32_C(    -0.21),
                         SIMDE_FLOAT32_C(     2.40), SIMDE_FLOAT32_C(    -0.71), SIMDE_FLOAT32_C(     0.17), SIMDE_FLOAT32_C(     1.49),
                         SIMDE_FLOAT32_C(     3.73), SIMDE_FLOAT32_C(     3.74), SIMDE_FLOAT32_C(     5.19), SIMDE_FLOAT32_C(     2.42)),
      UINT16_C(12713),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    -0.32), SIMDE_FLOAT32_C(     3.24), SIMDE_FLOAT32_C(     6.85), SIMDE_FLOAT32_C(     6.71),
                         SIMDE_FLOAT32_C(     0.13), SIMDE_FLOAT32_C(     1.96), SIMDE_FLOAT32_C(     6.43), SIMDE_FLOAT32_C(     1.79),
                         SIMDE_FLOAT32_C(     3.56), SIMDE_FLOAT32_C(     3.77), SIMDE_FLOAT32_C(     6.38), SIMDE_FLOAT32_C(     2.22),
                         SIMDE_FLOAT32_C(     7.36), SIMDE_FLOAT32_C(     4.86), SIMDE_FLOAT32_C(     3.24), SIMDE_FLOAT32_C(     6.97)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    -0.09), SIMDE_FLOAT32_C(     4.72), SIMDE_FLOAT32_C(   471.94), SIMDE_FLOAT32_C(   410.28),
                         SIMDE_FLOAT32_C(     7.41), SIMDE_FLOAT32_C(     7.40), SIMDE_FLOAT32_C(     6.85), SIMDE_FLOAT32_C(     2.91),
                         SIMDE_FLOAT32_C(    17.57), SIMDE_FLOAT32_C(    -0.71), SIMDE_FLOAT32_C(   294.96), SIMDE_FLOAT32_C(     1.49),
                         SIMDE_FLOAT32_C(   785.92), SIMDE_FLOAT32_C(     3.74), SIMDE_FLOAT32_C(     5.19), SIMDE_FLOAT32_C(   532.11)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512 r = simde_mm512_mask_sinh_ps(test_vec[i].src, test_vec[i].k, test_vec[i].a);
    simde_assert_m512_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_sinh_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512d a;
    simde__m512d r;
  } test_vec[8] = {
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(    5.44), SIMDE_FLOAT64_C(    6.18),
                         SIMDE_FLOAT64_C(    2.02), SIMDE_FLOAT64_C(    3.45),
                         SIMDE_FLOAT64_C(    2.50), SIMDE_FLOAT64_C(    3.47),
                         SIMDE_FLOAT64_C(    0.06), SIMDE_FLOAT64_C(    4.79)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  115.22), SIMDE_FLOAT64_C(  241.49),
                         SIMDE_FLOAT64_C(    3.70), SIMDE_FLOAT64_C(   15.73),
                         SIMDE_FLOAT64_C(    6.05), SIMDE_FLOAT64_C(   16.05),
                         SIMDE_FLOAT64_C(    0.06), SIMDE_FLOAT64_C(   60.15)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.38), SIMDE_FLOAT64_C(    0.35),
                         SIMDE_FLOAT64_C(    3.66), SIMDE_FLOAT64_C(    5.76),
                         SIMDE_FLOAT64_C(    6.85), SIMDE_FLOAT64_C(    5.12),
                         SIMDE_FLOAT64_C(    2.14), SIMDE_FLOAT64_C(    5.31)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.39), SIMDE_FLOAT64_C(    0.36),
                         SIMDE_FLOAT64_C(   19.42), SIMDE_FLOAT64_C(  158.67),
                         SIMDE_FLOAT64_C(  471.94), SIMDE_FLOAT64_C(   83.66),
                         SIMDE_FLOAT64_C(    4.19), SIMDE_FLOAT64_C(  101.17)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(    1.39), SIMDE_FLOAT64_C(    3.42),
                         SIMDE_FLOAT64_C(    1.65), SIMDE_FLOAT64_C(   -0.67),
                         SIMDE_FLOAT64_C(    1.99), SIMDE_FLOAT64_C(   -0.40),
                         SIMDE_FLOAT64_C(    1.50), SIMDE_FLOAT64_C(    6.30)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    1.88), SIMDE_FLOAT64_C(   15.27),
                         SIMDE_FLOAT64_C(    2.51), SIMDE_FLOAT64_C(   -0.72),
                         SIMDE_FLOAT64_C(    3.59), SIMDE_FLOAT64_C(   -0.41),
                         SIMDE_FLOAT64_C(    2.13), SIMDE_FLOAT64_C(  272.29)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(    4.07), SIMDE_FLOAT64_C(    1.36),
                         SIMDE_FLOAT64_C(    4.30), SIMDE_FLOAT64_C(    6.25),
                         SIMDE_FLOAT64_C(    4.42), SIMDE_FLOAT64_C(    2.39),
                         SIMDE_FLOAT64_C(   -0.90), SIMDE_FLOAT64_C(    0.46)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   29.27), SIMDE_FLOAT64_C(    1.82),
                         SIMDE_FLOAT64_C(   36.84), SIMDE_FLOAT64_C(  259.01),
                         SIMDE_FLOAT64_C(   41.54), SIMDE_FLOAT64_C(    5.41),
                         SIMDE_FLOAT64_C(   -1.03), SIMDE_FLOAT64_C(    0.48)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(   -0.01), SIMDE_FLOAT64_C(    5.21),
                         SIMDE_FLOAT64_C(    0.79), SIMDE_FLOAT64_C(    4.94),
                         SIMDE_FLOAT64_C(   -0.01), SIMDE_FLOAT64_C(    7.57),
                         SIMDE_FLOAT64_C(    3.42), SIMDE_FLOAT64_C(    6.92)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   -0.01), SIMDE_FLOAT64_C(   91.54),
                         SIMDE_FLOAT64_C(    0.87), SIMDE_FLOAT64_C(   69.88),
                         SIMDE_FLOAT64_C(   -0.01), SIMDE_FLOAT64_C(  969.57),
                         SIMDE_FLOAT64_C(   15.27), SIMDE_FLOAT64_C(  506.16)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(    1.63), SIMDE_FLOAT64_C(    5.00),
                         SIMDE_FLOAT64_C(    6.12), SIMDE_FLOAT64_C(    4.76),
                         SIMDE_FLOAT64_C(    5.59), SIMDE_FLOAT64_C(    2.16),
                         SIMDE_FLOAT64_C(    6.66), SIMDE_FLOAT64_C(    3.17)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    2.45), SIMDE_FLOAT64_C(   74.20),
                         SIMDE_FLOAT64_C(  227.43), SIMDE_FLOAT64_C(   58.37),
                         SIMDE_FLOAT64_C(  133.87), SIMDE_FLOAT64_C(    4.28),
                         SIMDE_FLOAT64_C(  390.27), SIMDE_FLOAT64_C(   11.88)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(    2.42), SIMDE_FLOAT64_C(    2.95),
                         SIMDE_FLOAT64_C(    4.75), SIMDE_FLOAT64_C(   -0.76),
                         SIMDE_FLOAT64_C(    0.09), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.92), SIMDE_FLOAT64_C(    5.01)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    5.58), SIMDE_FLOAT64_C(    9.53),
                         SIMDE_FLOAT64_C(   57.79), SIMDE_FLOAT64_C(   -0.84),
                         SIMDE_FLOAT64_C(    0.09), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    1.06), SIMDE_FLOAT64_C(   74.95)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(    5.32), SIMDE_FLOAT64_C(    6.22),
                         SIMDE_FLOAT64_C(    2.66), SIMDE_FLOAT64_C(    6.82),
                         SIMDE_FLOAT64_C(    7.21), SIMDE_FLOAT64_C(    5.88),
                         SIMDE_FLOAT64_C(    6.70), SIMDE_FLOAT64_C(    4.39)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  102.19), SIMDE_FLOAT64_C(  251.35),
                         SIMDE_FLOAT64_C(    7.11), SIMDE_FLOAT64_C(  457.99),
                         SIMDE_FLOAT64_C(  676.45), SIMDE_FLOAT64_C(  178.90),
                         SIMDE_FLOAT64_C(  406.20), SIMDE_FLOAT64_C(   40.31)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512d r = simde_mm512_sinh_pd(test_vec[i].a);
    simde_assert_m512d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_mask_sinh_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512d src;
    simde__mmask8 k;
    simde__m512d a;
    simde__m512d r;
  } test_vec[8] = {
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.35), SIMDE_FLOAT64_C(    5.76),
                         SIMDE_FLOAT64_C(    5.12), SIMDE_FLOAT64_C(    5.31),
                         SIMDE_FLOAT64_C(    6.18), SIMDE_FLOAT64_C(    3.45),
                         SIMDE_FLOAT64_C(    3.47), SIMDE_FLOAT64_C(    4.79)),
      UINT8_C(139),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.38), SIMDE_FLOAT64_C(    3.66),
                         SIMDE_FLOAT64_C(    6.85), SIMDE_FLOAT64_C(    2.14),
                         SIMDE_FLOAT64_C(    5.44), SIMDE_FLOAT64_C(    2.02),
                         SIMDE_FLOAT64_C(    2.50), SIMDE_FLOAT64_C(    0.06)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.39), SIMDE_FLOAT64_C(    5.76),
                         SIMDE_FLOAT64_C(    5.12), SIMDE_FLOAT64_C(    5.31),
                         SIMDE_FLOAT64_C(  115.22), SIMDE_FLOAT64_C(    3.45),
                         SIMDE_FLOAT64_C(    6.05), SIMDE_FLOAT64_C(    0.06)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(    4.07), SIMDE_FLOAT64_C(    4.30),
                         SIMDE_FLOAT64_C(    4.42), SIMDE_FLOAT64_C(   -0.90),
                         SIMDE_FLOAT64_C(    1.39), SIMDE_FLOAT64_C(    1.65),
                         SIMDE_FLOAT64_C(    1.99), SIMDE_FLOAT64_C(    1.50)),
      UINT8_C(229),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    6.92), SIMDE_FLOAT64_C(    1.36),
                         SIMDE_FLOAT64_C(    6.25), SIMDE_FLOAT64_C(    2.39),
                         SIMDE_FLOAT64_C(    0.46), SIMDE_FLOAT64_C(    3.42),
                         SIMDE_FLOAT64_C(   -0.67), SIMDE_FLOAT64_C(   -0.40)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  506.16), SIMDE_FLOAT64_C(    1.82),
                         SIMDE_FLOAT64_C(  259.01), SIMDE_FLOAT64_C(   -0.90),
                         SIMDE_FLOAT64_C(    1.39), SIMDE_FLOAT64_C(   15.27),
                         SIMDE_FLOAT64_C(    1.99), SIMDE_FLOAT64_C(   -0.41)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(    5.01), SIMDE_FLOAT64_C(    5.00),
                         SIMDE_FLOAT64_C(    4.76), SIMDE_FLOAT64_C(    2.16),
                         SIMDE_FLOAT64_C(    3.17), SIMDE_FLOAT64_C(    5.21),
                         SIMDE_FLOAT64_C(    4.94), SIMDE_FLOAT64_C(    7.57)),
      UINT8_C(253),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.92), SIMDE_FLOAT64_C(    1.63),
                         SIMDE_FLOAT64_C(    6.12), SIMDE_FLOAT64_C(    5.59),
                         SIMDE_FLOAT64_C(    6.66), SIMDE_FLOAT64_C(   -0.01),
                         SIMDE_FLOAT64_C(    0.79), SIMDE_FLOAT64_C(   -0.01)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    1.06), SIMDE_FLOAT64_C(    2.45),
                         SIMDE_FLOAT64_C(  227.43), SIMDE_FLOAT64_C(  133.87),
                         SIMDE_FLOAT64_C(  390.27), SIMDE_FLOAT64_C(   -0.01),
                         SIMDE_FLOAT64_C(    4.94), SIMDE_FLOAT64_C(   -0.01)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(    3.82), SIMDE_FLOAT64_C(    5.32),
                         SIMDE_FLOAT64_C(    2.66), SIMDE_FLOAT64_C(    7.21),
                         SIMDE_FLOAT64_C(    6.70), SIMDE_FLOAT64_C(    2.42),
                         SIMDE_FLOAT64_C(    4.75), SIMDE_FLOAT64_C(    0.09)),
      UINT8_C( 93),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    5.64), SIMDE_FLOAT64_C(    2.56),
                         SIMDE_FLOAT64_C(    6.22), SIMDE_FLOAT64_C(    6.82),
                         SIMDE_FLOAT64_C(    5.88), SIMDE_FLOAT64_C(    4.39),
                         SIMDE_FLOAT64_C(    2.95), SIMDE_FLOAT64_C(   -0.76)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    3.82), SIMDE_FLOAT64_C(    6.43),
                         SIMDE_FLOAT64_C(    2.66), SIMDE_FLOAT64_C(  457.99),
                         SIMDE_FLOAT64_C(  178.90), SIMDE_FLOAT64_C(   40.31),
                         SIMDE_FLOAT64_C(    4.75), SIMDE_FLOAT64_C(   -0.84)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(    3.73), SIMDE_FLOAT64_C(    0.13),
                         SIMDE_FLOAT64_C(    6.56), SIMDE_FLOAT64_C(    4.78),
                         SIMDE_FLOAT64_C(   -0.13), SIMDE_FLOAT64_C(    1.04),
                         SIMDE_FLOAT64_C(   -0.24), SIMDE_FLOAT64_C(    6.12)),
      UINT8_C(145),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    4.72), SIMDE_FLOAT64_C(    5.29),
                         SIMDE_FLOAT64_C(    2.53), SIMDE_FLOAT64_C(    4.70),
                         SIMDE_FLOAT64_C(   -0.46), SIMDE_FLOAT64_C(    1.89),
                         SIMDE_FLOAT64_C(    2.47), SIMDE_FLOAT64_C(    5.71)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   56.08), SIMDE_FLOAT64_C(    0.13),
                         SIMDE_FLOAT64_C(    6.56), SIMDE_FLOAT64_C(   54.97),
                         SIMDE_FLOAT64_C(   -0.13), SIMDE_FLOAT64_C(    1.04),
                         SIMDE_FLOAT64_C(   -0.24), SIMDE_FLOAT64_C(  150.93)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.05), SIMDE_FLOAT64_C(    3.42),
                         SIMDE_FLOAT64_C(    6.27), SIMDE_FLOAT64_C(    3.21),
                         SIMDE_FLOAT64_C(    1.37), SIMDE_FLOAT64_C(    5.47),
                         SIMDE_FLOAT64_C(    6.87), SIMDE_FLOAT64_C(    7.50)),
      UINT8_C( 75),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    7.50), SIMDE_FLOAT64_C(    5.13),
                         SIMDE_FLOAT64_C(    2.89), SIMDE_FLOAT64_C(    6.91),
                         SIMDE_FLOAT64_C(    0.76), SIMDE_FLOAT64_C(    6.45),
                         SIMDE_FLOAT64_C(    5.98), SIMDE_FLOAT64_C(    3.90)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.05), SIMDE_FLOAT64_C(   84.51),
                         SIMDE_FLOAT64_C(    6.27), SIMDE_FLOAT64_C(    3.21),
                         SIMDE_FLOAT64_C(    0.84), SIMDE_FLOAT64_C(    5.47),
                         SIMDE_FLOAT64_C(  197.72), SIMDE_FLOAT64_C(   24.69)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(    5.00), SIMDE_FLOAT64_C(    1.99),
                         SIMDE_FLOAT64_C(    0.30), SIMDE_FLOAT64_C(    6.83),
                         SIMDE_FLOAT64_C(   -0.99), SIMDE_FLOAT64_C(    7.27),
                         SIMDE_FLOAT64_C(   -0.00), SIMDE_FLOAT64_C(    3.01)),
      UINT8_C( 93),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    5.50), SIMDE_FLOAT64_C(    3.36),
                         SIMDE_FLOAT64_C(    7.24), SIMDE_FLOAT64_C(   -0.01),
                         SIMDE_FLOAT64_C(    0.83), SIMDE_FLOAT64_C(    1.85),
                         SIMDE_FLOAT64_C(    4.56), SIMDE_FLOAT64_C(    0.82)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    5.00), SIMDE_FLOAT64_C(   14.38),
                         SIMDE_FLOAT64_C(    0.30), SIMDE_FLOAT64_C(   -0.01),
                         SIMDE_FLOAT64_C(    0.93), SIMDE_FLOAT64_C(    3.10),
                         SIMDE_FLOAT64_C(   -0.00), SIMDE_FLOAT64_C(    0.92)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(    5.34), SIMDE_FLOAT64_C(    7.33),
                         SIMDE_FLOAT64_C(    1.80), SIMDE_FLOAT64_C(    1.42),
                         SIMDE_FLOAT64_C(    0.06), SIMDE_FLOAT64_C(    7.31),
                         SIMDE_FLOAT64_C(    1.89), SIMDE_FLOAT64_C(    2.52)),
      UINT8_C(213),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   -0.03), SIMDE_FLOAT64_C(    5.19),
                         SIMDE_FLOAT64_C(    7.16), SIMDE_FLOAT64_C(    2.45),
                         SIMDE_FLOAT64_C(    1.75), SIMDE_FLOAT64_C(    3.16),
                         SIMDE_FLOAT64_C(    3.33), SIMDE_FLOAT64_C(    2.76)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   -0.03), SIMDE_FLOAT64_C(   89.73),
                         SIMDE_FLOAT64_C(    1.80), SIMDE_FLOAT64_C(    5.75),
                         SIMDE_FLOAT64_C(    0.06), SIMDE_FLOAT64_C(   11.76),
                         SIMDE_FLOAT64_C(    1.89), SIMDE_FLOAT64_C(    7.87)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512d r = simde_mm512_mask_sinh_pd(test_vec[i].src, test_vec[i].k, test_vec[i].a);
    simde_assert_m512d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_tan_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -186.21), SIMDE_FLOAT32_C(    39.01), SIMDE_FLOAT32_C(  -754.38), SIMDE_FLOAT32_C(   346.63)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    -1.15), SIMDE_FLOAT32_C(     3.76), SIMDE_FLOAT32_C(    -0.42), SIMDE_FLOAT32_C(     1.76)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   497.31), SIMDE_FLOAT32_C(   670.24), SIMDE_FLOAT32_C(  -297.45), SIMDE_FLOAT32_C(    34.06)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     1.36), SIMDE_FLOAT32_C(     1.87), SIMDE_FLOAT32_C(     1.56), SIMDE_FLOAT32_C(    -0.54)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   825.53), SIMDE_FLOAT32_C(   422.21), SIMDE_FLOAT32_C(  -269.45), SIMDE_FLOAT32_C(   467.76)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    -0.86), SIMDE_FLOAT32_C(     2.88), SIMDE_FLOAT32_C(     0.89), SIMDE_FLOAT32_C(    -0.35)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -678.17), SIMDE_FLOAT32_C(  -686.13), SIMDE_FLOAT32_C(    84.77), SIMDE_FLOAT32_C(   571.46)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.44), SIMDE_FLOAT32_C(    -3.14), SIMDE_FLOAT32_C(    -0.05), SIMDE_FLOAT32_C(    -0.32)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -305.07), SIMDE_FLOAT32_C(  -860.95), SIMDE_FLOAT32_C(  -417.54), SIMDE_FLOAT32_C(   696.87)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    -0.35), SIMDE_FLOAT32_C(    -0.15), SIMDE_FLOAT32_C(     0.30), SIMDE_FLOAT32_C(    -0.63)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -444.81), SIMDE_FLOAT32_C(    28.47), SIMDE_FLOAT32_C(  -384.03), SIMDE_FLOAT32_C(  -923.64)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     3.55), SIMDE_FLOAT32_C(     0.20), SIMDE_FLOAT32_C(    -0.94), SIMDE_FLOAT32_C(    -0.01)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   261.31), SIMDE_FLOAT32_C(  -212.54), SIMDE_FLOAT32_C(  -976.55), SIMDE_FLOAT32_C(  -660.80)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.62), SIMDE_FLOAT32_C(     1.91), SIMDE_FLOAT32_C(     0.53), SIMDE_FLOAT32_C(    -1.81)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   178.20), SIMDE_FLOAT32_C(  -450.67), SIMDE_FLOAT32_C(   233.37), SIMDE_FLOAT32_C(   687.09)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    -1.19), SIMDE_FLOAT32_C(    -6.68), SIMDE_FLOAT32_C(     1.24), SIMDE_FLOAT32_C(    -1.31)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_tan_ps(test_vec[i].a);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_tan_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -754.38), SIMDE_FLOAT64_C(  346.63)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -0.42), SIMDE_FLOAT64_C(    1.76)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -186.21), SIMDE_FLOAT64_C(   39.01)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -1.15), SIMDE_FLOAT64_C(    3.76)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -297.45), SIMDE_FLOAT64_C(   34.06)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    1.56), SIMDE_FLOAT64_C(   -0.54)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  497.31), SIMDE_FLOAT64_C(  670.24)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    1.36), SIMDE_FLOAT64_C(    1.87)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -269.45), SIMDE_FLOAT64_C(  467.76)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.89), SIMDE_FLOAT64_C(   -0.35)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  825.53), SIMDE_FLOAT64_C(  422.21)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -0.86), SIMDE_FLOAT64_C(    2.88)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   84.77), SIMDE_FLOAT64_C(  571.46)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -0.05), SIMDE_FLOAT64_C(   -0.32)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -678.17), SIMDE_FLOAT64_C( -686.13)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.44), SIMDE_FLOAT64_C(   -3.14)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_tan_pd(test_vec[i].a);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_tan_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   497.31), SIMDE_FLOAT32_C(   670.24),
                         SIMDE_FLOAT32_C(  -297.45), SIMDE_FLOAT32_C(    34.06),
                         SIMDE_FLOAT32_C(  -186.21), SIMDE_FLOAT32_C(    39.01),
                         SIMDE_FLOAT32_C(  -754.38), SIMDE_FLOAT32_C(   346.63)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     1.36), SIMDE_FLOAT32_C(     1.87),
                         SIMDE_FLOAT32_C(     1.56), SIMDE_FLOAT32_C(    -0.54),
                         SIMDE_FLOAT32_C(    -1.15), SIMDE_FLOAT32_C(     3.76),
                         SIMDE_FLOAT32_C(    -0.42), SIMDE_FLOAT32_C(     1.76)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -678.17), SIMDE_FLOAT32_C(  -686.13),
                         SIMDE_FLOAT32_C(    84.77), SIMDE_FLOAT32_C(   571.46),
                         SIMDE_FLOAT32_C(   825.53), SIMDE_FLOAT32_C(   422.21),
                         SIMDE_FLOAT32_C(  -269.45), SIMDE_FLOAT32_C(   467.76)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     0.44), SIMDE_FLOAT32_C(    -3.14),
                         SIMDE_FLOAT32_C(    -0.05), SIMDE_FLOAT32_C(    -0.32),
                         SIMDE_FLOAT32_C(    -0.86), SIMDE_FLOAT32_C(     2.88),
                         SIMDE_FLOAT32_C(     0.89), SIMDE_FLOAT32_C(    -0.35)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -444.81), SIMDE_FLOAT32_C(    28.47),
                         SIMDE_FLOAT32_C(  -384.03), SIMDE_FLOAT32_C(  -923.64),
                         SIMDE_FLOAT32_C(  -305.07), SIMDE_FLOAT32_C(  -860.95),
                         SIMDE_FLOAT32_C(  -417.54), SIMDE_FLOAT32_C(   696.87)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     3.55), SIMDE_FLOAT32_C(     0.20),
                         SIMDE_FLOAT32_C(    -0.94), SIMDE_FLOAT32_C(    -0.01),
                         SIMDE_FLOAT32_C(    -0.35), SIMDE_FLOAT32_C(    -0.15),
                         SIMDE_FLOAT32_C(     0.30), SIMDE_FLOAT32_C(    -0.63)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   178.20), SIMDE_FLOAT32_C(  -450.67),
                         SIMDE_FLOAT32_C(   233.37), SIMDE_FLOAT32_C(   687.09),
                         SIMDE_FLOAT32_C(   261.31), SIMDE_FLOAT32_C(  -212.54),
                         SIMDE_FLOAT32_C(  -976.55), SIMDE_FLOAT32_C(  -660.80)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    -1.19), SIMDE_FLOAT32_C(    -6.68),
                         SIMDE_FLOAT32_C(     1.24), SIMDE_FLOAT32_C(    -1.31),
                         SIMDE_FLOAT32_C(     0.62), SIMDE_FLOAT32_C(     1.91),
                         SIMDE_FLOAT32_C(     0.53), SIMDE_FLOAT32_C(    -1.81)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -770.35), SIMDE_FLOAT32_C(   443.48),
                         SIMDE_FLOAT32_C(  -583.60), SIMDE_FLOAT32_C(   380.46),
                         SIMDE_FLOAT32_C(  -770.72), SIMDE_FLOAT32_C(   993.90),
                         SIMDE_FLOAT32_C(    28.08), SIMDE_FLOAT32_C(   841.21)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    -0.78), SIMDE_FLOAT32_C(     0.57),
                         SIMDE_FLOAT32_C(     0.91), SIMDE_FLOAT32_C(     0.34),
                         SIMDE_FLOAT32_C(    -1.66), SIMDE_FLOAT32_C(     2.28),
                         SIMDE_FLOAT32_C(    -0.20), SIMDE_FLOAT32_C(    -0.91)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -387.90), SIMDE_FLOAT32_C(   395.92),
                         SIMDE_FLOAT32_C(   655.87), SIMDE_FLOAT32_C(   339.21),
                         SIMDE_FLOAT32_C(   532.35), SIMDE_FLOAT32_C(  -263.99),
                         SIMDE_FLOAT32_C(   780.64), SIMDE_FLOAT32_C(   -30.79)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -11.51), SIMDE_FLOAT32_C(     0.08),
                         SIMDE_FLOAT32_C(    -0.88), SIMDE_FLOAT32_C(    -0.08),
                         SIMDE_FLOAT32_C(     6.62), SIMDE_FLOAT32_C(    -0.10),
                         SIMDE_FLOAT32_C(    21.84), SIMDE_FLOAT32_C(     0.72)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -203.65), SIMDE_FLOAT32_C(   -80.73),
                         SIMDE_FLOAT32_C(   336.73), SIMDE_FLOAT32_C(  -944.78),
                         SIMDE_FLOAT32_C(  -747.59), SIMDE_FLOAT32_C(  -767.23),
                         SIMDE_FLOAT32_C(  -554.19), SIMDE_FLOAT32_C(   398.82)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     0.62), SIMDE_FLOAT32_C(     1.40),
                         SIMDE_FLOAT32_C(     0.65), SIMDE_FLOAT32_C(     1.11),
                         SIMDE_FLOAT32_C(     0.11), SIMDE_FLOAT32_C(    -0.81),
                         SIMDE_FLOAT32_C(    -3.22), SIMDE_FLOAT32_C(    -0.16)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   469.66), SIMDE_FLOAT32_C(   680.02),
                         SIMDE_FLOAT32_C(  -148.69), SIMDE_FLOAT32_C(   818.66),
                         SIMDE_FLOAT32_C(   910.03), SIMDE_FLOAT32_C(   600.47),
                         SIMDE_FLOAT32_C(   791.23), SIMDE_FLOAT32_C(   254.31)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   123.48), SIMDE_FLOAT32_C(     7.37),
                         SIMDE_FLOAT32_C(    -1.68), SIMDE_FLOAT32_C(    -3.54),
                         SIMDE_FLOAT32_C(    -1.67), SIMDE_FLOAT32_C(     0.45),
                         SIMDE_FLOAT32_C(    -0.48), SIMDE_FLOAT32_C(    -0.16)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_tan_ps(test_vec[i].a);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_tan_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -186.21), SIMDE_FLOAT64_C(   39.01),
                         SIMDE_FLOAT64_C( -754.38), SIMDE_FLOAT64_C(  346.63)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -1.15), SIMDE_FLOAT64_C(    3.76),
                         SIMDE_FLOAT64_C(   -0.42), SIMDE_FLOAT64_C(    1.76)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  497.31), SIMDE_FLOAT64_C(  670.24),
                         SIMDE_FLOAT64_C( -297.45), SIMDE_FLOAT64_C(   34.06)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    1.36), SIMDE_FLOAT64_C(    1.87),
                         SIMDE_FLOAT64_C(    1.56), SIMDE_FLOAT64_C(   -0.54)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  825.53), SIMDE_FLOAT64_C(  422.21),
                         SIMDE_FLOAT64_C( -269.45), SIMDE_FLOAT64_C(  467.76)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -0.86), SIMDE_FLOAT64_C(    2.88),
                         SIMDE_FLOAT64_C(    0.89), SIMDE_FLOAT64_C(   -0.35)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -678.17), SIMDE_FLOAT64_C( -686.13),
                         SIMDE_FLOAT64_C(   84.77), SIMDE_FLOAT64_C(  571.46)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.44), SIMDE_FLOAT64_C(   -3.14),
                         SIMDE_FLOAT64_C(   -0.05), SIMDE_FLOAT64_C(   -0.32)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -305.07), SIMDE_FLOAT64_C( -860.95),
                         SIMDE_FLOAT64_C( -417.54), SIMDE_FLOAT64_C(  696.87)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -0.35), SIMDE_FLOAT64_C(   -0.15),
                         SIMDE_FLOAT64_C(    0.30), SIMDE_FLOAT64_C(   -0.63)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -444.81), SIMDE_FLOAT64_C(   28.47),
                         SIMDE_FLOAT64_C( -384.03), SIMDE_FLOAT64_C( -923.64)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    3.55), SIMDE_FLOAT64_C(    0.20),
                         SIMDE_FLOAT64_C(   -0.94), SIMDE_FLOAT64_C(   -0.01)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  261.31), SIMDE_FLOAT64_C( -212.54),
                         SIMDE_FLOAT64_C( -976.55), SIMDE_FLOAT64_C( -660.80)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.62), SIMDE_FLOAT64_C(    1.91),
                         SIMDE_FLOAT64_C(    0.53), SIMDE_FLOAT64_C(   -1.81)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  178.20), SIMDE_FLOAT64_C( -450.67),
                         SIMDE_FLOAT64_C(  233.37), SIMDE_FLOAT64_C(  687.09)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -1.19), SIMDE_FLOAT64_C(   -6.68),
                         SIMDE_FLOAT64_C(    1.24), SIMDE_FLOAT64_C(   -1.31)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_tan_pd(test_vec[i].a);
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_tan_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512 a;
    simde__m512 r;
  } test_vec[8] = {
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -678.17), SIMDE_FLOAT32_C(  -686.13), SIMDE_FLOAT32_C(    84.77), SIMDE_FLOAT32_C(   571.46),
                         SIMDE_FLOAT32_C(   825.53), SIMDE_FLOAT32_C(   422.21), SIMDE_FLOAT32_C(  -269.45), SIMDE_FLOAT32_C(   467.76),
                         SIMDE_FLOAT32_C(   497.31), SIMDE_FLOAT32_C(   670.24), SIMDE_FLOAT32_C(  -297.45), SIMDE_FLOAT32_C(    34.06),
                         SIMDE_FLOAT32_C(  -186.21), SIMDE_FLOAT32_C(    39.01), SIMDE_FLOAT32_C(  -754.38), SIMDE_FLOAT32_C(   346.63)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.44), SIMDE_FLOAT32_C(    -3.14), SIMDE_FLOAT32_C(    -0.05), SIMDE_FLOAT32_C(    -0.32),
                         SIMDE_FLOAT32_C(    -0.86), SIMDE_FLOAT32_C(     2.88), SIMDE_FLOAT32_C(     0.89), SIMDE_FLOAT32_C(    -0.35),
                         SIMDE_FLOAT32_C(     1.36), SIMDE_FLOAT32_C(     1.87), SIMDE_FLOAT32_C(     1.56), SIMDE_FLOAT32_C(    -0.54),
                         SIMDE_FLOAT32_C(    -1.15), SIMDE_FLOAT32_C(     3.76), SIMDE_FLOAT32_C(    -0.42), SIMDE_FLOAT32_C(     1.76)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   178.20), SIMDE_FLOAT32_C(  -450.67), SIMDE_FLOAT32_C(   233.37), SIMDE_FLOAT32_C(   687.09),
                         SIMDE_FLOAT32_C(   261.31), SIMDE_FLOAT32_C(  -212.54), SIMDE_FLOAT32_C(  -976.55), SIMDE_FLOAT32_C(  -660.80),
                         SIMDE_FLOAT32_C(  -444.81), SIMDE_FLOAT32_C(    28.47), SIMDE_FLOAT32_C(  -384.03), SIMDE_FLOAT32_C(  -923.64),
                         SIMDE_FLOAT32_C(  -305.07), SIMDE_FLOAT32_C(  -860.95), SIMDE_FLOAT32_C(  -417.54), SIMDE_FLOAT32_C(   696.87)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    -1.19), SIMDE_FLOAT32_C(    -6.68), SIMDE_FLOAT32_C(     1.24), SIMDE_FLOAT32_C(    -1.31),
                         SIMDE_FLOAT32_C(     0.62), SIMDE_FLOAT32_C(     1.91), SIMDE_FLOAT32_C(     0.53), SIMDE_FLOAT32_C(    -1.81),
                         SIMDE_FLOAT32_C(     3.55), SIMDE_FLOAT32_C(     0.20), SIMDE_FLOAT32_C(    -0.94), SIMDE_FLOAT32_C(    -0.01),
                         SIMDE_FLOAT32_C(    -0.35), SIMDE_FLOAT32_C(    -0.15), SIMDE_FLOAT32_C(     0.30), SIMDE_FLOAT32_C(    -0.63)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -387.90), SIMDE_FLOAT32_C(   395.92), SIMDE_FLOAT32_C(   655.87), SIMDE_FLOAT32_C(   339.21),
                         SIMDE_FLOAT32_C(   532.35), SIMDE_FLOAT32_C(  -263.99), SIMDE_FLOAT32_C(   780.64), SIMDE_FLOAT32_C(   -30.79),
                         SIMDE_FLOAT32_C(  -770.35), SIMDE_FLOAT32_C(   443.48), SIMDE_FLOAT32_C(  -583.60), SIMDE_FLOAT32_C(   380.46),
                         SIMDE_FLOAT32_C(  -770.72), SIMDE_FLOAT32_C(   993.90), SIMDE_FLOAT32_C(    28.08), SIMDE_FLOAT32_C(   841.21)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   -11.51), SIMDE_FLOAT32_C(     0.08), SIMDE_FLOAT32_C(    -0.88), SIMDE_FLOAT32_C(    -0.08),
                         SIMDE_FLOAT32_C(     6.62), SIMDE_FLOAT32_C(    -0.10), SIMDE_FLOAT32_C(    21.84), SIMDE_FLOAT32_C(     0.72),
                         SIMDE_FLOAT32_C(    -0.78), SIMDE_FLOAT32_C(     0.57), SIMDE_FLOAT32_C(     0.91), SIMDE_FLOAT32_C(     0.34),
                         SIMDE_FLOAT32_C(    -1.66), SIMDE_FLOAT32_C(     2.28), SIMDE_FLOAT32_C(    -0.20), SIMDE_FLOAT32_C(    -0.91)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   469.66), SIMDE_FLOAT32_C(   680.02), SIMDE_FLOAT32_C(  -148.69), SIMDE_FLOAT32_C(   818.66),
                         SIMDE_FLOAT32_C(   910.03), SIMDE_FLOAT32_C(   600.47), SIMDE_FLOAT32_C(   791.23), SIMDE_FLOAT32_C(   254.31),
                         SIMDE_FLOAT32_C(  -203.65), SIMDE_FLOAT32_C(   -80.73), SIMDE_FLOAT32_C(   336.73), SIMDE_FLOAT32_C(  -944.78),
                         SIMDE_FLOAT32_C(  -747.59), SIMDE_FLOAT32_C(  -767.23), SIMDE_FLOAT32_C(  -554.19), SIMDE_FLOAT32_C(   398.82)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   123.48), SIMDE_FLOAT32_C(     7.37), SIMDE_FLOAT32_C(    -1.68), SIMDE_FLOAT32_C(    -3.54),
                         SIMDE_FLOAT32_C(    -1.67), SIMDE_FLOAT32_C(     0.45), SIMDE_FLOAT32_C(    -0.48), SIMDE_FLOAT32_C(    -0.16),
                         SIMDE_FLOAT32_C(     0.62), SIMDE_FLOAT32_C(     1.40), SIMDE_FLOAT32_C(     0.65), SIMDE_FLOAT32_C(     1.11),
                         SIMDE_FLOAT32_C(     0.11), SIMDE_FLOAT32_C(    -0.81), SIMDE_FLOAT32_C(    -3.22), SIMDE_FLOAT32_C(    -0.16)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -178.99), SIMDE_FLOAT32_C(   758.79), SIMDE_FLOAT32_C(   324.62), SIMDE_FLOAT32_C(   343.48),
                         SIMDE_FLOAT32_C(  -874.31), SIMDE_FLOAT32_C(  -797.92), SIMDE_FLOAT32_C(  -328.54), SIMDE_FLOAT32_C(  -525.83),
                         SIMDE_FLOAT32_C(  -192.31), SIMDE_FLOAT32_C(  -822.65), SIMDE_FLOAT32_C(   561.36), SIMDE_FLOAT32_C(   655.67),
                         SIMDE_FLOAT32_C(   -70.91), SIMDE_FLOAT32_C(   543.35), SIMDE_FLOAT32_C(   120.65), SIMDE_FLOAT32_C(  -171.51)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.08), SIMDE_FLOAT32_C(   -10.46), SIMDE_FLOAT32_C(     1.69), SIMDE_FLOAT32_C(     1.73),
                         SIMDE_FLOAT32_C(    -1.39), SIMDE_FLOAT32_C(     0.04), SIMDE_FLOAT32_C(     4.02), SIMDE_FLOAT32_C(    -2.46),
                         SIMDE_FLOAT32_C(    -0.80), SIMDE_FLOAT32_C(     0.48), SIMDE_FLOAT32_C(    -1.51), SIMDE_FLOAT32_C(    -1.32),
                         SIMDE_FLOAT32_C(     4.39), SIMDE_FLOAT32_C(    -0.15), SIMDE_FLOAT32_C(     3.22), SIMDE_FLOAT32_C(     3.31)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   690.12), SIMDE_FLOAT32_C(   840.65), SIMDE_FLOAT32_C(   -21.09), SIMDE_FLOAT32_C(  -591.56),
                         SIMDE_FLOAT32_C(  -448.89), SIMDE_FLOAT32_C(   731.49), SIMDE_FLOAT32_C(   505.79), SIMDE_FLOAT32_C(   623.70),
                         SIMDE_FLOAT32_C(   831.02), SIMDE_FLOAT32_C(   140.67), SIMDE_FLOAT32_C(   977.36), SIMDE_FLOAT32_C(  -906.16),
                         SIMDE_FLOAT32_C(   331.34), SIMDE_FLOAT32_C(    99.93), SIMDE_FLOAT32_C(   462.95), SIMDE_FLOAT32_C(  -738.19)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    -1.67), SIMDE_FLOAT32_C(    -3.56), SIMDE_FLOAT32_C(     1.26), SIMDE_FLOAT32_C(    -1.37),
                         SIMDE_FLOAT32_C(     0.37), SIMDE_FLOAT32_C(    -0.55), SIMDE_FLOAT32_C(    -0.01), SIMDE_FLOAT32_C(   -10.62),
                         SIMDE_FLOAT32_C(   -14.52), SIMDE_FLOAT32_C(    -0.85), SIMDE_FLOAT32_C(     0.34), SIMDE_FLOAT32_C(    -5.21),
                         SIMDE_FLOAT32_C(    10.17), SIMDE_FLOAT32_C(    -0.69), SIMDE_FLOAT32_C(     2.15), SIMDE_FLOAT32_C(     0.08)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -769.09), SIMDE_FLOAT32_C(   822.06), SIMDE_FLOAT32_C(  -573.81), SIMDE_FLOAT32_C(  -997.63),
                         SIMDE_FLOAT32_C(  -337.60), SIMDE_FLOAT32_C(   923.64), SIMDE_FLOAT32_C(   293.64), SIMDE_FLOAT32_C(  -768.12),
                         SIMDE_FLOAT32_C(  -576.22), SIMDE_FLOAT32_C(   -67.64), SIMDE_FLOAT32_C(   710.38), SIMDE_FLOAT32_C(   977.49),
                         SIMDE_FLOAT32_C(  -756.42), SIMDE_FLOAT32_C(   424.81), SIMDE_FLOAT32_C(    27.25), SIMDE_FLOAT32_C(   -95.15)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.68), SIMDE_FLOAT32_C(    -1.69), SIMDE_FLOAT32_C(     1.97), SIMDE_FLOAT32_C(     5.68),
                         SIMDE_FLOAT32_C(    -8.21), SIMDE_FLOAT32_C(     0.01), SIMDE_FLOAT32_C(    10.08), SIMDE_FLOAT32_C(  1691.15),
                         SIMDE_FLOAT32_C(    -3.72), SIMDE_FLOAT32_C(    10.41), SIMDE_FLOAT32_C(     0.40), SIMDE_FLOAT32_C(     0.49),
                         SIMDE_FLOAT32_C(     0.85), SIMDE_FLOAT32_C(     0.83), SIMDE_FLOAT32_C(    -1.64), SIMDE_FLOAT32_C(    -1.27)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -438.19), SIMDE_FLOAT32_C(  -359.76), SIMDE_FLOAT32_C(  -752.43), SIMDE_FLOAT32_C(   -33.67),
                         SIMDE_FLOAT32_C(   932.66), SIMDE_FLOAT32_C(     7.27), SIMDE_FLOAT32_C(  -327.22), SIMDE_FLOAT32_C(  -125.20),
                         SIMDE_FLOAT32_C(  -182.45), SIMDE_FLOAT32_C(    39.93), SIMDE_FLOAT32_C(   510.85), SIMDE_FLOAT32_C(   394.67),
                         SIMDE_FLOAT32_C(    14.34), SIMDE_FLOAT32_C(  -304.73), SIMDE_FLOAT32_C(   916.26), SIMDE_FLOAT32_C(  -696.69)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   -16.06), SIMDE_FLOAT32_C(    20.97), SIMDE_FLOAT32_C(    53.90), SIMDE_FLOAT32_C(     1.23),
                         SIMDE_FLOAT32_C(    -0.41), SIMDE_FLOAT32_C(     1.51), SIMDE_FLOAT32_C(    -0.54), SIMDE_FLOAT32_C(     0.50),
                         SIMDE_FLOAT32_C(    -0.24), SIMDE_FLOAT32_C(    -1.29), SIMDE_FLOAT32_C(    -2.82), SIMDE_FLOAT32_C(    -2.36),
                         SIMDE_FLOAT32_C(    -4.86), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -1.89), SIMDE_FLOAT32_C(     0.92)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512 r = simde_mm512_tan_ps(test_vec[i].a);
    simde_assert_m512_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_mask_tan_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512 src;
    simde__mmask16 k;
    simde__m512 a;
    simde__m512 r;
  } test_vec[8] = {
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -450.67), SIMDE_FLOAT32_C(   687.09), SIMDE_FLOAT32_C(  -212.54), SIMDE_FLOAT32_C(  -660.80),
                         SIMDE_FLOAT32_C(    28.47), SIMDE_FLOAT32_C(  -923.64), SIMDE_FLOAT32_C(  -860.95), SIMDE_FLOAT32_C(   696.87),
                         SIMDE_FLOAT32_C(  -686.13), SIMDE_FLOAT32_C(   571.46), SIMDE_FLOAT32_C(   422.21), SIMDE_FLOAT32_C(   467.76),
                         SIMDE_FLOAT32_C(   670.24), SIMDE_FLOAT32_C(    34.06), SIMDE_FLOAT32_C(    39.01), SIMDE_FLOAT32_C(   346.63)),
      UINT16_C(41466),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   178.20), SIMDE_FLOAT32_C(   233.37), SIMDE_FLOAT32_C(   261.31), SIMDE_FLOAT32_C(  -976.55),
                         SIMDE_FLOAT32_C(  -444.81), SIMDE_FLOAT32_C(  -384.03), SIMDE_FLOAT32_C(  -305.07), SIMDE_FLOAT32_C(  -417.54),
                         SIMDE_FLOAT32_C(  -678.17), SIMDE_FLOAT32_C(    84.77), SIMDE_FLOAT32_C(   825.53), SIMDE_FLOAT32_C(  -269.45),
                         SIMDE_FLOAT32_C(   497.31), SIMDE_FLOAT32_C(  -297.45), SIMDE_FLOAT32_C(  -186.21), SIMDE_FLOAT32_C(  -754.38)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    -1.19), SIMDE_FLOAT32_C(   687.09), SIMDE_FLOAT32_C(     0.62), SIMDE_FLOAT32_C(  -660.80),
                         SIMDE_FLOAT32_C(    28.47), SIMDE_FLOAT32_C(  -923.64), SIMDE_FLOAT32_C(  -860.95), SIMDE_FLOAT32_C(     0.30),
                         SIMDE_FLOAT32_C(     0.44), SIMDE_FLOAT32_C(    -0.05), SIMDE_FLOAT32_C(    -0.86), SIMDE_FLOAT32_C(     0.89),
                         SIMDE_FLOAT32_C(     1.36), SIMDE_FLOAT32_C(    34.06), SIMDE_FLOAT32_C(    -1.15), SIMDE_FLOAT32_C(   346.63)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   469.66), SIMDE_FLOAT32_C(  -148.69), SIMDE_FLOAT32_C(   910.03), SIMDE_FLOAT32_C(   791.23),
                         SIMDE_FLOAT32_C(  -203.65), SIMDE_FLOAT32_C(   336.73), SIMDE_FLOAT32_C(  -747.59), SIMDE_FLOAT32_C(  -554.19),
                         SIMDE_FLOAT32_C(  -387.90), SIMDE_FLOAT32_C(   655.87), SIMDE_FLOAT32_C(   532.35), SIMDE_FLOAT32_C(   780.64),
                         SIMDE_FLOAT32_C(  -770.35), SIMDE_FLOAT32_C(  -583.60), SIMDE_FLOAT32_C(  -770.72), SIMDE_FLOAT32_C(    28.08)),
      UINT16_C(36797),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -171.51), SIMDE_FLOAT32_C(   680.02), SIMDE_FLOAT32_C(   818.66), SIMDE_FLOAT32_C(   600.47),
                         SIMDE_FLOAT32_C(   254.31), SIMDE_FLOAT32_C(   -80.73), SIMDE_FLOAT32_C(  -944.78), SIMDE_FLOAT32_C(  -767.23),
                         SIMDE_FLOAT32_C(   398.82), SIMDE_FLOAT32_C(   395.92), SIMDE_FLOAT32_C(   339.21), SIMDE_FLOAT32_C(  -263.99),
                         SIMDE_FLOAT32_C(   -30.79), SIMDE_FLOAT32_C(   443.48), SIMDE_FLOAT32_C(   380.46), SIMDE_FLOAT32_C(   993.90)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     3.31), SIMDE_FLOAT32_C(  -148.69), SIMDE_FLOAT32_C(   910.03), SIMDE_FLOAT32_C(   791.23),
                         SIMDE_FLOAT32_C(    -0.16), SIMDE_FLOAT32_C(     1.40), SIMDE_FLOAT32_C(     1.11), SIMDE_FLOAT32_C(    -0.81),
                         SIMDE_FLOAT32_C(    -0.16), SIMDE_FLOAT32_C(   655.87), SIMDE_FLOAT32_C(    -0.08), SIMDE_FLOAT32_C(    -0.10),
                         SIMDE_FLOAT32_C(     0.72), SIMDE_FLOAT32_C(     0.57), SIMDE_FLOAT32_C(  -770.72), SIMDE_FLOAT32_C(     2.28)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   -95.15), SIMDE_FLOAT32_C(   840.65), SIMDE_FLOAT32_C(  -591.56), SIMDE_FLOAT32_C(   731.49),
                         SIMDE_FLOAT32_C(   623.70), SIMDE_FLOAT32_C(   140.67), SIMDE_FLOAT32_C(  -906.16), SIMDE_FLOAT32_C(    99.93),
                         SIMDE_FLOAT32_C(  -738.19), SIMDE_FLOAT32_C(   758.79), SIMDE_FLOAT32_C(   343.48), SIMDE_FLOAT32_C(  -797.92),
                         SIMDE_FLOAT32_C(  -525.83), SIMDE_FLOAT32_C(  -822.65), SIMDE_FLOAT32_C(   655.67), SIMDE_FLOAT32_C(   543.35)),
      UINT16_C(16804),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    27.25), SIMDE_FLOAT32_C(   690.12), SIMDE_FLOAT32_C(   -21.09), SIMDE_FLOAT32_C(  -448.89),
                         SIMDE_FLOAT32_C(   505.79), SIMDE_FLOAT32_C(   831.02), SIMDE_FLOAT32_C(   977.36), SIMDE_FLOAT32_C(   331.34),
                         SIMDE_FLOAT32_C(   462.95), SIMDE_FLOAT32_C(  -178.99), SIMDE_FLOAT32_C(   324.62), SIMDE_FLOAT32_C(  -874.31),
                         SIMDE_FLOAT32_C(  -328.54), SIMDE_FLOAT32_C(  -192.31), SIMDE_FLOAT32_C(   561.36), SIMDE_FLOAT32_C(   -70.91)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   -95.15), SIMDE_FLOAT32_C(    -1.67), SIMDE_FLOAT32_C(  -591.56), SIMDE_FLOAT32_C(   731.49),
                         SIMDE_FLOAT32_C(   623.70), SIMDE_FLOAT32_C(   140.67), SIMDE_FLOAT32_C(  -906.16), SIMDE_FLOAT32_C(    10.17),
                         SIMDE_FLOAT32_C(     2.15), SIMDE_FLOAT32_C(   758.79), SIMDE_FLOAT32_C(     1.69), SIMDE_FLOAT32_C(  -797.92),
                         SIMDE_FLOAT32_C(  -525.83), SIMDE_FLOAT32_C(    -0.80), SIMDE_FLOAT32_C(   655.67), SIMDE_FLOAT32_C(   543.35)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -348.70), SIMDE_FLOAT32_C(  -438.19), SIMDE_FLOAT32_C(  -752.43), SIMDE_FLOAT32_C(   932.66),
                         SIMDE_FLOAT32_C(  -327.22), SIMDE_FLOAT32_C(  -182.45), SIMDE_FLOAT32_C(   510.85), SIMDE_FLOAT32_C(    14.34),
                         SIMDE_FLOAT32_C(   916.26), SIMDE_FLOAT32_C(  -769.09), SIMDE_FLOAT32_C(  -573.81), SIMDE_FLOAT32_C(  -337.60),
                         SIMDE_FLOAT32_C(   293.64), SIMDE_FLOAT32_C(  -576.22), SIMDE_FLOAT32_C(   710.38), SIMDE_FLOAT32_C(  -756.42)),
      UINT16_C( 2107),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   897.27), SIMDE_FLOAT32_C(  -197.89), SIMDE_FLOAT32_C(  -359.76), SIMDE_FLOAT32_C(   -33.67),
                         SIMDE_FLOAT32_C(     7.27), SIMDE_FLOAT32_C(  -125.20), SIMDE_FLOAT32_C(    39.93), SIMDE_FLOAT32_C(   394.67),
                         SIMDE_FLOAT32_C(  -304.73), SIMDE_FLOAT32_C(  -696.69), SIMDE_FLOAT32_C(   822.06), SIMDE_FLOAT32_C(  -997.63),
                         SIMDE_FLOAT32_C(   923.64), SIMDE_FLOAT32_C(  -768.12), SIMDE_FLOAT32_C(   -67.64), SIMDE_FLOAT32_C(   977.49)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -348.70), SIMDE_FLOAT32_C(  -438.19), SIMDE_FLOAT32_C(  -752.43), SIMDE_FLOAT32_C(   932.66),
                         SIMDE_FLOAT32_C(     1.51), SIMDE_FLOAT32_C(  -182.45), SIMDE_FLOAT32_C(   510.85), SIMDE_FLOAT32_C(    14.34),
                         SIMDE_FLOAT32_C(   916.26), SIMDE_FLOAT32_C(  -769.09), SIMDE_FLOAT32_C(    -1.69), SIMDE_FLOAT32_C(     5.68),
                         SIMDE_FLOAT32_C(     0.01), SIMDE_FLOAT32_C(  -576.22), SIMDE_FLOAT32_C(    10.41), SIMDE_FLOAT32_C(     0.49)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   -15.61), SIMDE_FLOAT32_C(  -737.13), SIMDE_FLOAT32_C(  -314.93), SIMDE_FLOAT32_C(   177.92),
                         SIMDE_FLOAT32_C(   345.93), SIMDE_FLOAT32_C(   888.71), SIMDE_FLOAT32_C(   915.71), SIMDE_FLOAT32_C(   133.52),
                         SIMDE_FLOAT32_C(   484.94), SIMDE_FLOAT32_C(  -598.06), SIMDE_FLOAT32_C(  -791.07), SIMDE_FLOAT32_C(  -765.93),
                         SIMDE_FLOAT32_C(   221.37), SIMDE_FLOAT32_C(  -788.36), SIMDE_FLOAT32_C(  -775.04), SIMDE_FLOAT32_C(   440.64)),
      UINT16_C(22274),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   496.57), SIMDE_FLOAT32_C(   915.19), SIMDE_FLOAT32_C(  -718.40), SIMDE_FLOAT32_C(   159.97),
                         SIMDE_FLOAT32_C(  -861.01), SIMDE_FLOAT32_C(   426.61), SIMDE_FLOAT32_C(   932.11), SIMDE_FLOAT32_C(   110.36),
                         SIMDE_FLOAT32_C(   826.84), SIMDE_FLOAT32_C(   -76.75), SIMDE_FLOAT32_C(   237.58), SIMDE_FLOAT32_C(  -378.50),
                         SIMDE_FLOAT32_C(  -601.68), SIMDE_FLOAT32_C(  -623.50), SIMDE_FLOAT32_C(  -942.47), SIMDE_FLOAT32_C(   475.51)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   -15.61), SIMDE_FLOAT32_C(     1.51), SIMDE_FLOAT32_C(  -314.93), SIMDE_FLOAT32_C(    -0.26),
                         SIMDE_FLOAT32_C(   345.93), SIMDE_FLOAT32_C(    -0.75), SIMDE_FLOAT32_C(    -1.38), SIMDE_FLOAT32_C(     0.43),
                         SIMDE_FLOAT32_C(   484.94), SIMDE_FLOAT32_C(  -598.06), SIMDE_FLOAT32_C(  -791.07), SIMDE_FLOAT32_C(  -765.93),
                         SIMDE_FLOAT32_C(   221.37), SIMDE_FLOAT32_C(  -788.36), SIMDE_FLOAT32_C(     0.01), SIMDE_FLOAT32_C(   440.64)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   883.05), SIMDE_FLOAT32_C(  -807.28), SIMDE_FLOAT32_C(   -70.05), SIMDE_FLOAT32_C(  -784.34),
                         SIMDE_FLOAT32_C(    92.52), SIMDE_FLOAT32_C(   206.60), SIMDE_FLOAT32_C(   834.60), SIMDE_FLOAT32_C(   -65.60),
                         SIMDE_FLOAT32_C(  -286.07), SIMDE_FLOAT32_C(  -212.86), SIMDE_FLOAT32_C(  -318.38), SIMDE_FLOAT32_C(   783.48),
                         SIMDE_FLOAT32_C(  -628.82), SIMDE_FLOAT32_C(   556.35), SIMDE_FLOAT32_C(   439.43), SIMDE_FLOAT32_C(   434.03)),
      UINT16_C(27396),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -964.25), SIMDE_FLOAT32_C(  -406.33), SIMDE_FLOAT32_C(  -743.66), SIMDE_FLOAT32_C(  -764.58),
                         SIMDE_FLOAT32_C(   789.89), SIMDE_FLOAT32_C(     4.83), SIMDE_FLOAT32_C(  -818.54), SIMDE_FLOAT32_C(   161.06),
                         SIMDE_FLOAT32_C(   579.25), SIMDE_FLOAT32_C(   -11.78), SIMDE_FLOAT32_C(  -308.52), SIMDE_FLOAT32_C(  -719.57),
                         SIMDE_FLOAT32_C(   334.00), SIMDE_FLOAT32_C(   274.71), SIMDE_FLOAT32_C(  -916.82), SIMDE_FLOAT32_C(  -490.00)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   883.05), SIMDE_FLOAT32_C(    -1.80), SIMDE_FLOAT32_C(     1.25), SIMDE_FLOAT32_C(  -784.34),
                         SIMDE_FLOAT32_C(     4.46), SIMDE_FLOAT32_C(   206.60), SIMDE_FLOAT32_C(     6.40), SIMDE_FLOAT32_C(     1.11),
                         SIMDE_FLOAT32_C(  -286.07), SIMDE_FLOAT32_C(  -212.86), SIMDE_FLOAT32_C(  -318.38), SIMDE_FLOAT32_C(   783.48),
                         SIMDE_FLOAT32_C(  -628.82), SIMDE_FLOAT32_C(     5.52), SIMDE_FLOAT32_C(   439.43), SIMDE_FLOAT32_C(   434.03)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   529.63), SIMDE_FLOAT32_C(   -24.89), SIMDE_FLOAT32_C(  -967.78), SIMDE_FLOAT32_C(   638.94),
                         SIMDE_FLOAT32_C(   450.90), SIMDE_FLOAT32_C(  -771.54), SIMDE_FLOAT32_C(   105.79), SIMDE_FLOAT32_C(   590.10),
                         SIMDE_FLOAT32_C(    30.91), SIMDE_FLOAT32_C(   635.35), SIMDE_FLOAT32_C(   -84.00), SIMDE_FLOAT32_C(    80.04),
                         SIMDE_FLOAT32_C(  -709.46), SIMDE_FLOAT32_C(   607.86), SIMDE_FLOAT32_C(   394.58), SIMDE_FLOAT32_C(  -889.11)),
      UINT16_C(  953),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    18.75), SIMDE_FLOAT32_C(   809.05), SIMDE_FLOAT32_C(   144.05), SIMDE_FLOAT32_C(  -427.72),
                         SIMDE_FLOAT32_C(   308.28), SIMDE_FLOAT32_C(  -177.05), SIMDE_FLOAT32_C(  -457.77), SIMDE_FLOAT32_C(   678.24),
                         SIMDE_FLOAT32_C(    66.05), SIMDE_FLOAT32_C(  -267.71), SIMDE_FLOAT32_C(   117.28), SIMDE_FLOAT32_C(  -576.80),
                         SIMDE_FLOAT32_C(   -38.39), SIMDE_FLOAT32_C(  -250.14), SIMDE_FLOAT32_C(   -53.92), SIMDE_FLOAT32_C(    91.94)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   529.63), SIMDE_FLOAT32_C(   -24.89), SIMDE_FLOAT32_C(  -967.78), SIMDE_FLOAT32_C(   638.94),
                         SIMDE_FLOAT32_C(   450.90), SIMDE_FLOAT32_C(  -771.54), SIMDE_FLOAT32_C(     1.27), SIMDE_FLOAT32_C(    -0.36),
                         SIMDE_FLOAT32_C(     0.08), SIMDE_FLOAT32_C(   635.35), SIMDE_FLOAT32_C(     1.71), SIMDE_FLOAT32_C(     3.04),
                         SIMDE_FLOAT32_C(    -0.83), SIMDE_FLOAT32_C(   607.86), SIMDE_FLOAT32_C(   394.58), SIMDE_FLOAT32_C(     1.10)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -788.39), SIMDE_FLOAT32_C(   330.43), SIMDE_FLOAT32_C(  -493.41), SIMDE_FLOAT32_C(   822.72),
                         SIMDE_FLOAT32_C(   956.68), SIMDE_FLOAT32_C(   954.62), SIMDE_FLOAT32_C(   825.49), SIMDE_FLOAT32_C(  -816.27),
                         SIMDE_FLOAT32_C(  -209.34), SIMDE_FLOAT32_C(  -933.21), SIMDE_FLOAT32_C(  -728.70), SIMDE_FLOAT32_C(  -420.06),
                         SIMDE_FLOAT32_C(   100.32), SIMDE_FLOAT32_C(   103.15), SIMDE_FLOAT32_C(   439.77), SIMDE_FLOAT32_C(  -204.33)),
      UINT16_C(12713),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -841.43), SIMDE_FLOAT32_C(   -14.16), SIMDE_FLOAT32_C(   824.88), SIMDE_FLOAT32_C(   793.63),
                         SIMDE_FLOAT32_C(  -736.75), SIMDE_FLOAT32_C(  -310.57), SIMDE_FLOAT32_C(   728.87), SIMDE_FLOAT32_C(  -350.72),
                         SIMDE_FLOAT32_C(    60.89), SIMDE_FLOAT32_C(   109.81), SIMDE_FLOAT32_C(   715.94), SIMDE_FLOAT32_C(  -250.60),
                         SIMDE_FLOAT32_C(   944.14), SIMDE_FLOAT32_C(   361.85), SIMDE_FLOAT32_C(   -13.07), SIMDE_FLOAT32_C(   852.60)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -788.39), SIMDE_FLOAT32_C(   330.43), SIMDE_FLOAT32_C(    -4.65), SIMDE_FLOAT32_C(    -2.52),
                         SIMDE_FLOAT32_C(   956.68), SIMDE_FLOAT32_C(   954.62), SIMDE_FLOAT32_C(   825.49), SIMDE_FLOAT32_C(     2.17),
                         SIMDE_FLOAT32_C(     2.57), SIMDE_FLOAT32_C(  -933.21), SIMDE_FLOAT32_C(    -0.36), SIMDE_FLOAT32_C(  -420.06),
                         SIMDE_FLOAT32_C(   -10.91), SIMDE_FLOAT32_C(   103.15), SIMDE_FLOAT32_C(   439.77), SIMDE_FLOAT32_C(     2.81)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512 r = simde_mm512_mask_tan_ps(test_vec[i].src, test_vec[i].k, test_vec[i].a);
    simde_assert_m512_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_tan_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512d a;
    simde__m512d r;
  } test_vec[8] = {
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  497.31), SIMDE_FLOAT64_C(  670.24),
                         SIMDE_FLOAT64_C( -297.45), SIMDE_FLOAT64_C(   34.06),
                         SIMDE_FLOAT64_C( -186.21), SIMDE_FLOAT64_C(   39.01),
                         SIMDE_FLOAT64_C( -754.38), SIMDE_FLOAT64_C(  346.63)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    1.36), SIMDE_FLOAT64_C(    1.87),
                         SIMDE_FLOAT64_C(    1.56), SIMDE_FLOAT64_C(   -0.54),
                         SIMDE_FLOAT64_C(   -1.15), SIMDE_FLOAT64_C(    3.76),
                         SIMDE_FLOAT64_C(   -0.42), SIMDE_FLOAT64_C(    1.76)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -678.17), SIMDE_FLOAT64_C( -686.13),
                         SIMDE_FLOAT64_C(   84.77), SIMDE_FLOAT64_C(  571.46),
                         SIMDE_FLOAT64_C(  825.53), SIMDE_FLOAT64_C(  422.21),
                         SIMDE_FLOAT64_C( -269.45), SIMDE_FLOAT64_C(  467.76)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.44), SIMDE_FLOAT64_C(   -3.14),
                         SIMDE_FLOAT64_C(   -0.05), SIMDE_FLOAT64_C(   -0.32),
                         SIMDE_FLOAT64_C(   -0.86), SIMDE_FLOAT64_C(    2.88),
                         SIMDE_FLOAT64_C(    0.89), SIMDE_FLOAT64_C(   -0.35)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -444.81), SIMDE_FLOAT64_C(   28.47),
                         SIMDE_FLOAT64_C( -384.03), SIMDE_FLOAT64_C( -923.64),
                         SIMDE_FLOAT64_C( -305.07), SIMDE_FLOAT64_C( -860.95),
                         SIMDE_FLOAT64_C( -417.54), SIMDE_FLOAT64_C(  696.87)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    3.55), SIMDE_FLOAT64_C(    0.20),
                         SIMDE_FLOAT64_C(   -0.94), SIMDE_FLOAT64_C(   -0.01),
                         SIMDE_FLOAT64_C(   -0.35), SIMDE_FLOAT64_C(   -0.15),
                         SIMDE_FLOAT64_C(    0.30), SIMDE_FLOAT64_C(   -0.63)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  178.20), SIMDE_FLOAT64_C( -450.67),
                         SIMDE_FLOAT64_C(  233.37), SIMDE_FLOAT64_C(  687.09),
                         SIMDE_FLOAT64_C(  261.31), SIMDE_FLOAT64_C( -212.54),
                         SIMDE_FLOAT64_C( -976.55), SIMDE_FLOAT64_C( -660.80)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   -1.19), SIMDE_FLOAT64_C(   -6.68),
                         SIMDE_FLOAT64_C(    1.24), SIMDE_FLOAT64_C(   -1.31),
                         SIMDE_FLOAT64_C(    0.62), SIMDE_FLOAT64_C(    1.91),
                         SIMDE_FLOAT64_C(    0.53), SIMDE_FLOAT64_C(   -1.81)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -770.35), SIMDE_FLOAT64_C(  443.48),
                         SIMDE_FLOAT64_C( -583.60), SIMDE_FLOAT64_C(  380.46),
                         SIMDE_FLOAT64_C( -770.72), SIMDE_FLOAT64_C(  993.90),
                         SIMDE_FLOAT64_C(   28.08), SIMDE_FLOAT64_C(  841.21)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   -0.78), SIMDE_FLOAT64_C(    0.57),
                         SIMDE_FLOAT64_C(    0.91), SIMDE_FLOAT64_C(    0.34),
                         SIMDE_FLOAT64_C(   -1.66), SIMDE_FLOAT64_C(    2.28),
                         SIMDE_FLOAT64_C(   -0.20), SIMDE_FLOAT64_C(   -0.91)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -387.90), SIMDE_FLOAT64_C(  395.92),
                         SIMDE_FLOAT64_C(  655.87), SIMDE_FLOAT64_C(  339.21),
                         SIMDE_FLOAT64_C(  532.35), SIMDE_FLOAT64_C( -263.99),
                         SIMDE_FLOAT64_C(  780.64), SIMDE_FLOAT64_C(  -30.79)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  -11.51), SIMDE_FLOAT64_C(    0.08),
                         SIMDE_FLOAT64_C(   -0.88), SIMDE_FLOAT64_C(   -0.08),
                         SIMDE_FLOAT64_C(    6.62), SIMDE_FLOAT64_C(   -0.10),
                         SIMDE_FLOAT64_C(   21.83), SIMDE_FLOAT64_C(    0.72)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -203.65), SIMDE_FLOAT64_C(  -80.73),
                         SIMDE_FLOAT64_C(  336.73), SIMDE_FLOAT64_C( -944.78),
                         SIMDE_FLOAT64_C( -747.59), SIMDE_FLOAT64_C( -767.23),
                         SIMDE_FLOAT64_C( -554.19), SIMDE_FLOAT64_C(  398.82)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.62), SIMDE_FLOAT64_C(    1.40),
                         SIMDE_FLOAT64_C(    0.65), SIMDE_FLOAT64_C(    1.11),
                         SIMDE_FLOAT64_C(    0.11), SIMDE_FLOAT64_C(   -0.81),
                         SIMDE_FLOAT64_C(   -3.22), SIMDE_FLOAT64_C(   -0.16)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  469.66), SIMDE_FLOAT64_C(  680.02),
                         SIMDE_FLOAT64_C( -148.69), SIMDE_FLOAT64_C(  818.66),
                         SIMDE_FLOAT64_C(  910.03), SIMDE_FLOAT64_C(  600.47),
                         SIMDE_FLOAT64_C(  791.23), SIMDE_FLOAT64_C(  254.31)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  123.43), SIMDE_FLOAT64_C(    7.37),
                         SIMDE_FLOAT64_C(   -1.68), SIMDE_FLOAT64_C(   -3.54),
                         SIMDE_FLOAT64_C(   -1.67), SIMDE_FLOAT64_C(    0.45),
                         SIMDE_FLOAT64_C(   -0.48), SIMDE_FLOAT64_C(   -0.16)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512d r = simde_mm512_tan_pd(test_vec[i].a);
    simde_assert_m512d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_mask_tan_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512d src;
    simde__mmask8 k;
    simde__m512d a;
    simde__m512d r;
  } test_vec[8] = {
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -686.13), SIMDE_FLOAT64_C(  571.46),
                         SIMDE_FLOAT64_C(  422.21), SIMDE_FLOAT64_C(  467.76),
                         SIMDE_FLOAT64_C(  670.24), SIMDE_FLOAT64_C(   34.06),
                         SIMDE_FLOAT64_C(   39.01), SIMDE_FLOAT64_C(  346.63)),
      UINT8_C(139),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -678.17), SIMDE_FLOAT64_C(   84.77),
                         SIMDE_FLOAT64_C(  825.53), SIMDE_FLOAT64_C( -269.45),
                         SIMDE_FLOAT64_C(  497.31), SIMDE_FLOAT64_C( -297.45),
                         SIMDE_FLOAT64_C( -186.21), SIMDE_FLOAT64_C( -754.38)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.44), SIMDE_FLOAT64_C(  571.46),
                         SIMDE_FLOAT64_C(  422.21), SIMDE_FLOAT64_C(  467.76),
                         SIMDE_FLOAT64_C(    1.36), SIMDE_FLOAT64_C(   34.06),
                         SIMDE_FLOAT64_C(   -1.15), SIMDE_FLOAT64_C(   -0.42)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  178.20), SIMDE_FLOAT64_C(  233.37),
                         SIMDE_FLOAT64_C(  261.31), SIMDE_FLOAT64_C( -976.55),
                         SIMDE_FLOAT64_C( -444.81), SIMDE_FLOAT64_C( -384.03),
                         SIMDE_FLOAT64_C( -305.07), SIMDE_FLOAT64_C( -417.54)),
      UINT8_C(229),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  841.21), SIMDE_FLOAT64_C( -450.67),
                         SIMDE_FLOAT64_C(  687.09), SIMDE_FLOAT64_C( -212.54),
                         SIMDE_FLOAT64_C( -660.80), SIMDE_FLOAT64_C(   28.47),
                         SIMDE_FLOAT64_C( -923.64), SIMDE_FLOAT64_C( -860.95)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   -0.91), SIMDE_FLOAT64_C(   -6.68),
                         SIMDE_FLOAT64_C(   -1.31), SIMDE_FLOAT64_C( -976.55),
                         SIMDE_FLOAT64_C( -444.81), SIMDE_FLOAT64_C(    0.20),
                         SIMDE_FLOAT64_C( -305.07), SIMDE_FLOAT64_C(   -0.15)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  398.82), SIMDE_FLOAT64_C(  395.92),
                         SIMDE_FLOAT64_C(  339.21), SIMDE_FLOAT64_C( -263.99),
                         SIMDE_FLOAT64_C(  -30.79), SIMDE_FLOAT64_C(  443.48),
                         SIMDE_FLOAT64_C(  380.46), SIMDE_FLOAT64_C(  993.90)),
      UINT8_C(253),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -554.19), SIMDE_FLOAT64_C( -387.90),
                         SIMDE_FLOAT64_C(  655.87), SIMDE_FLOAT64_C(  532.35),
                         SIMDE_FLOAT64_C(  780.64), SIMDE_FLOAT64_C( -770.35),
                         SIMDE_FLOAT64_C( -583.60), SIMDE_FLOAT64_C( -770.72)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   -3.22), SIMDE_FLOAT64_C(  -11.51),
                         SIMDE_FLOAT64_C(   -0.88), SIMDE_FLOAT64_C(    6.62),
                         SIMDE_FLOAT64_C(   21.83), SIMDE_FLOAT64_C(   -0.78),
                         SIMDE_FLOAT64_C(  380.46), SIMDE_FLOAT64_C(   -1.66)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  120.65), SIMDE_FLOAT64_C(  469.66),
                         SIMDE_FLOAT64_C( -148.69), SIMDE_FLOAT64_C(  910.03),
                         SIMDE_FLOAT64_C(  791.23), SIMDE_FLOAT64_C( -203.65),
                         SIMDE_FLOAT64_C(  336.73), SIMDE_FLOAT64_C( -747.59)),
      UINT8_C( 93),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  543.35), SIMDE_FLOAT64_C( -171.51),
                         SIMDE_FLOAT64_C(  680.02), SIMDE_FLOAT64_C(  818.66),
                         SIMDE_FLOAT64_C(  600.47), SIMDE_FLOAT64_C(  254.31),
                         SIMDE_FLOAT64_C(  -80.73), SIMDE_FLOAT64_C( -944.78)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  120.65), SIMDE_FLOAT64_C(    3.31),
                         SIMDE_FLOAT64_C( -148.69), SIMDE_FLOAT64_C(   -3.54),
                         SIMDE_FLOAT64_C(    0.45), SIMDE_FLOAT64_C(   -0.16),
                         SIMDE_FLOAT64_C(  336.73), SIMDE_FLOAT64_C(    1.11)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(   99.93), SIMDE_FLOAT64_C( -738.19),
                         SIMDE_FLOAT64_C(  758.79), SIMDE_FLOAT64_C(  343.48),
                         SIMDE_FLOAT64_C( -797.92), SIMDE_FLOAT64_C( -525.83),
                         SIMDE_FLOAT64_C( -822.65), SIMDE_FLOAT64_C(  655.67)),
      UINT8_C(145),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  331.34), SIMDE_FLOAT64_C(  462.95),
                         SIMDE_FLOAT64_C( -178.99), SIMDE_FLOAT64_C(  324.62),
                         SIMDE_FLOAT64_C( -874.31), SIMDE_FLOAT64_C( -328.54),
                         SIMDE_FLOAT64_C( -192.31), SIMDE_FLOAT64_C(  561.36)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   10.17), SIMDE_FLOAT64_C( -738.19),
                         SIMDE_FLOAT64_C(  758.79), SIMDE_FLOAT64_C(    1.69),
                         SIMDE_FLOAT64_C( -797.92), SIMDE_FLOAT64_C( -525.83),
                         SIMDE_FLOAT64_C( -822.65), SIMDE_FLOAT64_C(   -1.51)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -756.42), SIMDE_FLOAT64_C(   27.25),
                         SIMDE_FLOAT64_C(  690.12), SIMDE_FLOAT64_C(  -21.09),
                         SIMDE_FLOAT64_C( -448.89), SIMDE_FLOAT64_C(  505.79),
                         SIMDE_FLOAT64_C(  831.02), SIMDE_FLOAT64_C(  977.36)),
      UINT8_C( 75),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  977.49), SIMDE_FLOAT64_C(  424.81),
                         SIMDE_FLOAT64_C(  -95.15), SIMDE_FLOAT64_C(  840.65),
                         SIMDE_FLOAT64_C( -591.56), SIMDE_FLOAT64_C(  731.49),
                         SIMDE_FLOAT64_C(  623.70), SIMDE_FLOAT64_C(  140.67)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -756.42), SIMDE_FLOAT64_C(    0.83),
                         SIMDE_FLOAT64_C(  690.12), SIMDE_FLOAT64_C(  -21.09),
                         SIMDE_FLOAT64_C(   -1.37), SIMDE_FLOAT64_C(  505.79),
                         SIMDE_FLOAT64_C(  -10.62), SIMDE_FLOAT64_C(   -0.85)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  394.67), SIMDE_FLOAT64_C( -304.73),
                         SIMDE_FLOAT64_C( -696.69), SIMDE_FLOAT64_C(  822.06),
                         SIMDE_FLOAT64_C( -997.63), SIMDE_FLOAT64_C(  923.64),
                         SIMDE_FLOAT64_C( -768.12), SIMDE_FLOAT64_C(  -67.64)),
      UINT8_C( 93),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  510.85), SIMDE_FLOAT64_C(   14.34),
                         SIMDE_FLOAT64_C(  916.26), SIMDE_FLOAT64_C( -769.09),
                         SIMDE_FLOAT64_C( -573.81), SIMDE_FLOAT64_C( -337.60),
                         SIMDE_FLOAT64_C(  293.64), SIMDE_FLOAT64_C( -576.22)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  394.67), SIMDE_FLOAT64_C(   -4.86),
                         SIMDE_FLOAT64_C( -696.69), SIMDE_FLOAT64_C(    0.68),
                         SIMDE_FLOAT64_C(    1.97), SIMDE_FLOAT64_C(   -8.21),
                         SIMDE_FLOAT64_C( -768.12), SIMDE_FLOAT64_C(   -3.73)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  475.51), SIMDE_FLOAT64_C(  936.65),
                         SIMDE_FLOAT64_C( -348.70), SIMDE_FLOAT64_C( -438.19),
                         SIMDE_FLOAT64_C( -752.43), SIMDE_FLOAT64_C(  932.66),
                         SIMDE_FLOAT64_C( -327.22), SIMDE_FLOAT64_C( -182.45)),
      UINT8_C(213),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -775.04), SIMDE_FLOAT64_C(  440.64),
                         SIMDE_FLOAT64_C(  897.27), SIMDE_FLOAT64_C( -197.89),
                         SIMDE_FLOAT64_C( -359.76), SIMDE_FLOAT64_C(  -33.67),
                         SIMDE_FLOAT64_C(    7.27), SIMDE_FLOAT64_C( -125.20)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    1.35), SIMDE_FLOAT64_C(    1.07),
                         SIMDE_FLOAT64_C( -348.70), SIMDE_FLOAT64_C(    0.03),
                         SIMDE_FLOAT64_C( -752.43), SIMDE_FLOAT64_C(    1.23),
                         SIMDE_FLOAT64_C( -327.22), SIMDE_FLOAT64_C(    0.50)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512d r = simde_mm512_mask_tan_pd(test_vec[i].src, test_vec[i].k, test_vec[i].a);
    simde_assert_m512d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_udivrem_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i rem;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu32(UINT32_C(1747596798), UINT32_C(2231263307), UINT32_C( 527472553), UINT32_C(2891870298)),
      simde_x_mm_set_epu32(UINT32_C(4025088144), UINT32_C(4117928860), UINT32_C( 377180600), UINT32_C(3776380886)),
      simde_x_mm_set_epu32(UINT32_C(1747596798), UINT32_C(2231263307), UINT32_C( 150291953), UINT32_C(2891870298)),
      simde_x_mm_set_epu32(UINT32_C(         0), UINT32_C(         0), UINT32_C(         1), UINT32_C(         0)) },
    { simde_x_mm_set_epu32(UINT32_C(3920294270), UINT32_C(3054162118), UINT32_C(1568850865), UINT32_C(3151989757)),
      simde_x_mm_set_epu32(UINT32_C( 172780273), UINT32_C( 168508556), UINT32_C(3803608574), UINT32_C(4064895559)),
      simde_x_mm_set_epu32(UINT32_C( 119128264), UINT32_C(  21008110), UINT32_C(1568850865), UINT32_C(3151989757)),
      simde_x_mm_set_epu32(UINT32_C(        22), UINT32_C(        18), UINT32_C(         0), UINT32_C(         0)) },
    { simde_x_mm_set_epu32(UINT32_C(1492341726), UINT32_C( 298608154), UINT32_C(1250819173), UINT32_C(3643996043)),
      simde_x_mm_set_epu32(UINT32_C( 298065861), UINT32_C(3773381365), UINT32_C( 330694282), UINT32_C(  40997390)),
      simde_x_mm_set_epu32(UINT32_C(   2012421), UINT32_C( 298608154), UINT32_C( 258736327), UINT32_C(  36225723)),
      simde_x_mm_set_epu32(UINT32_C(         5), UINT32_C(         0), UINT32_C(         3), UINT32_C(        88)) },
    { simde_x_mm_set_epu32(UINT32_C(2708640028), UINT32_C(1691051285), UINT32_C(  50347892), UINT32_C( 728425428)),
      simde_x_mm_set_epu32(UINT32_C(3853764578), UINT32_C( 294920921), UINT32_C(3883385645), UINT32_C(4126975473)),
      simde_x_mm_set_epu32(UINT32_C(2708640028), UINT32_C( 216446680), UINT32_C(  50347892), UINT32_C( 728425428)),
      simde_x_mm_set_epu32(UINT32_C(         0), UINT32_C(         5), UINT32_C(         0), UINT32_C(         0)) },
    { simde_x_mm_set_epu32(UINT32_C( 492373082), UINT32_C(4281870485), UINT32_C(2207786213), UINT32_C(3953959418)),
      simde_x_mm_set_epu32(UINT32_C( 123290430), UINT32_C(3996188341), UINT32_C( 223555334), UINT32_C(3962352253)),
      simde_x_mm_set_epu32(UINT32_C( 122501792), UINT32_C( 285682144), UINT32_C( 195788207), UINT32_C(3953959418)),
      simde_x_mm_set_epu32(UINT32_C(         3), UINT32_C(         1), UINT32_C(         9), UINT32_C(         0)) },
    { simde_x_mm_set_epu32(UINT32_C(3290702646), UINT32_C(1580565751), UINT32_C(3823902839), UINT32_C(2081361826)),
      simde_x_mm_set_epu32(UINT32_C( 328620632), UINT32_C(3970654641), UINT32_C(4110215287), UINT32_C(3940207296)),
      simde_x_mm_set_epu32(UINT32_C(   4496326), UINT32_C(1580565751), UINT32_C(3823902839), UINT32_C(2081361826)),
      simde_x_mm_set_epu32(UINT32_C(        10), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0)) },
    { simde_x_mm_set_epu32(UINT32_C( 542053192), UINT32_C( 499863549), UINT32_C( 957375358), UINT32_C(3003933707)),
      simde_x_mm_set_epu32(UINT32_C( 427537184), UINT32_C( 493530770), UINT32_C(3938875497), UINT32_C(  29647056)),
      simde_x_mm_set_epu32(UINT32_C( 114516008), UINT32_C(   6332779), UINT32_C( 957375358), UINT32_C(   9581051)),
      simde_x_mm_set_epu32(UINT32_C(         1), UINT32_C(         1), UINT32_C(         0), UINT32_C(       101)) },
    { simde_x_mm_set_epu32(UINT32_C(4101755863), UINT32_C(3436978124), UINT32_C(3846637996), UINT32_C(2693603084)),
      simde_x_mm_set_epu32(UINT32_C(4010243988), UINT32_C(4123176886), UINT32_C( 457043765), UINT32_C(4197612290)),
      simde_x_mm_set_epu32(UINT32_C(  91511875), UINT32_C(3436978124), UINT32_C( 190287876), UINT32_C(2693603084)),
      simde_x_mm_set_epu32(UINT32_C(         1), UINT32_C(         0), UINT32_C(         8), UINT32_C(         0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i rem;
    simde__m128i r = simde_mm_udivrem_epi32(&rem, test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u32(r, ==, test_vec[i].r);
    simde_assert_m128i_u32(rem, ==, test_vec[i].rem);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_tanh_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(    -0.19), SIMDE_FLOAT32_C(     0.04), SIMDE_FLOAT32_C(    -0.75), SIMDE_FLOAT32_C(     0.35)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    -0.19), SIMDE_FLOAT32_C(     0.04), SIMDE_FLOAT32_C(    -0.64), SIMDE_FLOAT32_C(     0.34)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(     0.50), SIMDE_FLOAT32_C(     0.67), SIMDE_FLOAT32_C(    -0.30), SIMDE_FLOAT32_C(     0.03)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.46), SIMDE_FLOAT32_C(     0.58), SIMDE_FLOAT32_C(    -0.29), SIMDE_FLOAT32_C(     0.03)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(     0.83), SIMDE_FLOAT32_C(     0.42), SIMDE_FLOAT32_C(    -0.27), SIMDE_FLOAT32_C(     0.47)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.68), SIMDE_FLOAT32_C(     0.40), SIMDE_FLOAT32_C(    -0.26), SIMDE_FLOAT32_C(     0.44)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(    -0.68), SIMDE_FLOAT32_C(    -0.69), SIMDE_FLOAT32_C(     0.08), SIMDE_FLOAT32_C(     0.57)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    -0.59), SIMDE_FLOAT32_C(    -0.60), SIMDE_FLOAT32_C(     0.08), SIMDE_FLOAT32_C(     0.52)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(    -0.31), SIMDE_FLOAT32_C(    -0.86), SIMDE_FLOAT32_C(    -0.42), SIMDE_FLOAT32_C(     0.70)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    -0.30), SIMDE_FLOAT32_C(    -0.70), SIMDE_FLOAT32_C(    -0.40), SIMDE_FLOAT32_C(     0.60)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(    -0.44), SIMDE_FLOAT32_C(     0.03), SIMDE_FLOAT32_C(    -0.38), SIMDE_FLOAT32_C(    -0.92)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    -0.41), SIMDE_FLOAT32_C(     0.03), SIMDE_FLOAT32_C(    -0.36), SIMDE_FLOAT32_C(    -0.73)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(     0.26), SIMDE_FLOAT32_C(    -0.21), SIMDE_FLOAT32_C(    -0.98), SIMDE_FLOAT32_C(    -0.66)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.25), SIMDE_FLOAT32_C(    -0.21), SIMDE_FLOAT32_C(    -0.75), SIMDE_FLOAT32_C(    -0.58)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(     0.18), SIMDE_FLOAT32_C(    -0.45), SIMDE_FLOAT32_C(     0.23), SIMDE_FLOAT32_C(     0.69)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.18), SIMDE_FLOAT32_C(    -0.42), SIMDE_FLOAT32_C(     0.23), SIMDE_FLOAT32_C(     0.60)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_tanh_ps(test_vec[i].a);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_tanh_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   -0.75), SIMDE_FLOAT64_C(    0.35)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -0.64), SIMDE_FLOAT64_C(    0.34)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   -0.19), SIMDE_FLOAT64_C(    0.04)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -0.19), SIMDE_FLOAT64_C(    0.04)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   -0.30), SIMDE_FLOAT64_C(    0.03)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -0.29), SIMDE_FLOAT64_C(    0.03)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    0.50), SIMDE_FLOAT64_C(    0.67)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.46), SIMDE_FLOAT64_C(    0.58)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   -0.27), SIMDE_FLOAT64_C(    0.47)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -0.26), SIMDE_FLOAT64_C(    0.44)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    0.83), SIMDE_FLOAT64_C(    0.42)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.68), SIMDE_FLOAT64_C(    0.40)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    0.08), SIMDE_FLOAT64_C(    0.57)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.08), SIMDE_FLOAT64_C(    0.52)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   -0.68), SIMDE_FLOAT64_C(   -0.69)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -0.59), SIMDE_FLOAT64_C(   -0.60)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_tanh_pd(test_vec[i].a);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_tanh_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(     0.50), SIMDE_FLOAT32_C(     0.67),
                         SIMDE_FLOAT32_C(    -0.30), SIMDE_FLOAT32_C(     0.03),
                         SIMDE_FLOAT32_C(    -0.19), SIMDE_FLOAT32_C(     0.04),
                         SIMDE_FLOAT32_C(    -0.75), SIMDE_FLOAT32_C(     0.35)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     0.46), SIMDE_FLOAT32_C(     0.58),
                         SIMDE_FLOAT32_C(    -0.29), SIMDE_FLOAT32_C(     0.03),
                         SIMDE_FLOAT32_C(    -0.19), SIMDE_FLOAT32_C(     0.04),
                         SIMDE_FLOAT32_C(    -0.64), SIMDE_FLOAT32_C(     0.34)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(    -0.68), SIMDE_FLOAT32_C(    -0.69),
                         SIMDE_FLOAT32_C(     0.08), SIMDE_FLOAT32_C(     0.57),
                         SIMDE_FLOAT32_C(     0.83), SIMDE_FLOAT32_C(     0.42),
                         SIMDE_FLOAT32_C(    -0.27), SIMDE_FLOAT32_C(     0.47)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    -0.59), SIMDE_FLOAT32_C(    -0.60),
                         SIMDE_FLOAT32_C(     0.08), SIMDE_FLOAT32_C(     0.52),
                         SIMDE_FLOAT32_C(     0.68), SIMDE_FLOAT32_C(     0.40),
                         SIMDE_FLOAT32_C(    -0.26), SIMDE_FLOAT32_C(     0.44)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(    -0.44), SIMDE_FLOAT32_C(     0.03),
                         SIMDE_FLOAT32_C(    -0.38), SIMDE_FLOAT32_C(    -0.92),
                         SIMDE_FLOAT32_C(    -0.31), SIMDE_FLOAT32_C(    -0.86),
                         SIMDE_FLOAT32_C(    -0.42), SIMDE_FLOAT32_C(     0.70)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    -0.41), SIMDE_FLOAT32_C(     0.03),
                         SIMDE_FLOAT32_C(    -0.36), SIMDE_FLOAT32_C(    -0.73),
                         SIMDE_FLOAT32_C(    -0.30), SIMDE_FLOAT32_C(    -0.70),
                         SIMDE_FLOAT32_C(    -0.40), SIMDE_FLOAT32_C(     0.60)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(     0.18), SIMDE_FLOAT32_C(    -0.45),
                         SIMDE_FLOAT32_C(     0.23), SIMDE_FLOAT32_C(     0.69),
                         SIMDE_FLOAT32_C(     0.26), SIMDE_FLOAT32_C(    -0.21),
                         SIMDE_FLOAT32_C(    -0.98), SIMDE_FLOAT32_C(    -0.66)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     0.18), SIMDE_FLOAT32_C(    -0.42),
                         SIMDE_FLOAT32_C(     0.23), SIMDE_FLOAT32_C(     0.60),
                         SIMDE_FLOAT32_C(     0.25), SIMDE_FLOAT32_C(    -0.21),
                         SIMDE_FLOAT32_C(    -0.75), SIMDE_FLOAT32_C(    -0.58)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(    -0.77), SIMDE_FLOAT32_C(     0.44),
                         SIMDE_FLOAT32_C(    -0.58), SIMDE_FLOAT32_C(     0.38),
                         SIMDE_FLOAT32_C(    -0.77), SIMDE_FLOAT32_C(     0.99),
                         SIMDE_FLOAT32_C(     0.03), SIMDE_FLOAT32_C(     0.84)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    -0.65), SIMDE_FLOAT32_C(     0.41),
                         SIMDE_FLOAT32_C(    -0.52), SIMDE_FLOAT32_C(     0.36),
                         SIMDE_FLOAT32_C(    -0.65), SIMDE_FLOAT32_C(     0.76),
                         SIMDE_FLOAT32_C(     0.03), SIMDE_FLOAT32_C(     0.69)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(    -0.39), SIMDE_FLOAT32_C(     0.40),
                         SIMDE_FLOAT32_C(     0.66), SIMDE_FLOAT32_C(     0.34),
                         SIMDE_FLOAT32_C(     0.53), SIMDE_FLOAT32_C(    -0.26),
                         SIMDE_FLOAT32_C(     0.78), SIMDE_FLOAT32_C(    -0.03)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    -0.37), SIMDE_FLOAT32_C(     0.38),
                         SIMDE_FLOAT32_C(     0.58), SIMDE_FLOAT32_C(     0.33),
                         SIMDE_FLOAT32_C(     0.49), SIMDE_FLOAT32_C(    -0.25),
                         SIMDE_FLOAT32_C(     0.65), SIMDE_FLOAT32_C(    -0.03)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(    -0.20), SIMDE_FLOAT32_C(    -0.08),
                         SIMDE_FLOAT32_C(     0.34), SIMDE_FLOAT32_C(    -0.94),
                         SIMDE_FLOAT32_C(    -0.75), SIMDE_FLOAT32_C(    -0.77),
                         SIMDE_FLOAT32_C(    -0.55), SIMDE_FLOAT32_C(     0.40)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    -0.20), SIMDE_FLOAT32_C(    -0.08),
                         SIMDE_FLOAT32_C(     0.33), SIMDE_FLOAT32_C(    -0.74),
                         SIMDE_FLOAT32_C(    -0.64), SIMDE_FLOAT32_C(    -0.65),
                         SIMDE_FLOAT32_C(    -0.50), SIMDE_FLOAT32_C(     0.38)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(     0.47), SIMDE_FLOAT32_C(     0.68),
                         SIMDE_FLOAT32_C(    -0.15), SIMDE_FLOAT32_C(     0.82),
                         SIMDE_FLOAT32_C(     0.91), SIMDE_FLOAT32_C(     0.60),
                         SIMDE_FLOAT32_C(     0.79), SIMDE_FLOAT32_C(     0.25)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     0.44), SIMDE_FLOAT32_C(     0.59),
                         SIMDE_FLOAT32_C(    -0.15), SIMDE_FLOAT32_C(     0.68),
                         SIMDE_FLOAT32_C(     0.72), SIMDE_FLOAT32_C(     0.54),
                         SIMDE_FLOAT32_C(     0.66), SIMDE_FLOAT32_C(     0.24)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_tanh_ps(test_vec[i].a);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_tanh_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   -0.19), SIMDE_FLOAT64_C(    0.04),
                         SIMDE_FLOAT64_C(   -0.75), SIMDE_FLOAT64_C(    0.35)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -0.19), SIMDE_FLOAT64_C(    0.04),
                         SIMDE_FLOAT64_C(   -0.64), SIMDE_FLOAT64_C(    0.34)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.50), SIMDE_FLOAT64_C(    0.67),
                         SIMDE_FLOAT64_C(   -0.30), SIMDE_FLOAT64_C(    0.03)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.46), SIMDE_FLOAT64_C(    0.58),
                         SIMDE_FLOAT64_C(   -0.29), SIMDE_FLOAT64_C(    0.03)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.83), SIMDE_FLOAT64_C(    0.42),
                         SIMDE_FLOAT64_C(   -0.27), SIMDE_FLOAT64_C(    0.47)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.68), SIMDE_FLOAT64_C(    0.40),
                         SIMDE_FLOAT64_C(   -0.26), SIMDE_FLOAT64_C(    0.44)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   -0.68), SIMDE_FLOAT64_C(   -0.69),
                         SIMDE_FLOAT64_C(    0.08), SIMDE_FLOAT64_C(    0.57)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -0.59), SIMDE_FLOAT64_C(   -0.60),
                         SIMDE_FLOAT64_C(    0.08), SIMDE_FLOAT64_C(    0.52)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   -0.31), SIMDE_FLOAT64_C(   -0.86),
                         SIMDE_FLOAT64_C(   -0.42), SIMDE_FLOAT64_C(    0.70)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -0.30), SIMDE_FLOAT64_C(   -0.70),
                         SIMDE_FLOAT64_C(   -0.40), SIMDE_FLOAT64_C(    0.60)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   -0.44), SIMDE_FLOAT64_C(    0.03),
                         SIMDE_FLOAT64_C(   -0.38), SIMDE_FLOAT64_C(   -0.92)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -0.41), SIMDE_FLOAT64_C(    0.03),
                         SIMDE_FLOAT64_C(   -0.36), SIMDE_FLOAT64_C(   -0.73)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.26), SIMDE_FLOAT64_C(   -0.21),
                         SIMDE_FLOAT64_C(   -0.98), SIMDE_FLOAT64_C(   -0.66)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.25), SIMDE_FLOAT64_C(   -0.21),
                         SIMDE_FLOAT64_C(   -0.75), SIMDE_FLOAT64_C(   -0.58)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.18), SIMDE_FLOAT64_C(   -0.45),
                         SIMDE_FLOAT64_C(    0.23), SIMDE_FLOAT64_C(    0.69)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.18), SIMDE_FLOAT64_C(   -0.42),
                         SIMDE_FLOAT64_C(    0.23), SIMDE_FLOAT64_C(    0.60)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_tanh_pd(test_vec[i].a);
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_tanh_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512 a;
    simde__m512 r;
  } test_vec[8] = {
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(    -0.68), SIMDE_FLOAT32_C(    -0.69), SIMDE_FLOAT32_C(     0.08), SIMDE_FLOAT32_C(     0.57),
                         SIMDE_FLOAT32_C(     0.83), SIMDE_FLOAT32_C(     0.42), SIMDE_FLOAT32_C(    -0.27), SIMDE_FLOAT32_C(     0.47),
                         SIMDE_FLOAT32_C(     0.50), SIMDE_FLOAT32_C(     0.67), SIMDE_FLOAT32_C(    -0.30), SIMDE_FLOAT32_C(     0.03),
                         SIMDE_FLOAT32_C(    -0.19), SIMDE_FLOAT32_C(     0.04), SIMDE_FLOAT32_C(    -0.75), SIMDE_FLOAT32_C(     0.35)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    -0.59), SIMDE_FLOAT32_C(    -0.60), SIMDE_FLOAT32_C(     0.08), SIMDE_FLOAT32_C(     0.52),
                         SIMDE_FLOAT32_C(     0.68), SIMDE_FLOAT32_C(     0.40), SIMDE_FLOAT32_C(    -0.26), SIMDE_FLOAT32_C(     0.44),
                         SIMDE_FLOAT32_C(     0.46), SIMDE_FLOAT32_C(     0.58), SIMDE_FLOAT32_C(    -0.29), SIMDE_FLOAT32_C(     0.03),
                         SIMDE_FLOAT32_C(    -0.19), SIMDE_FLOAT32_C(     0.04), SIMDE_FLOAT32_C(    -0.64), SIMDE_FLOAT32_C(     0.34)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.18), SIMDE_FLOAT32_C(    -0.45), SIMDE_FLOAT32_C(     0.23), SIMDE_FLOAT32_C(     0.69),
                         SIMDE_FLOAT32_C(     0.26), SIMDE_FLOAT32_C(    -0.21), SIMDE_FLOAT32_C(    -0.98), SIMDE_FLOAT32_C(    -0.66),
                         SIMDE_FLOAT32_C(    -0.44), SIMDE_FLOAT32_C(     0.03), SIMDE_FLOAT32_C(    -0.38), SIMDE_FLOAT32_C(    -0.92),
                         SIMDE_FLOAT32_C(    -0.31), SIMDE_FLOAT32_C(    -0.86), SIMDE_FLOAT32_C(    -0.42), SIMDE_FLOAT32_C(     0.70)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.18), SIMDE_FLOAT32_C(    -0.42), SIMDE_FLOAT32_C(     0.23), SIMDE_FLOAT32_C(     0.60),
                         SIMDE_FLOAT32_C(     0.25), SIMDE_FLOAT32_C(    -0.21), SIMDE_FLOAT32_C(    -0.75), SIMDE_FLOAT32_C(    -0.58),
                         SIMDE_FLOAT32_C(    -0.41), SIMDE_FLOAT32_C(     0.03), SIMDE_FLOAT32_C(    -0.36), SIMDE_FLOAT32_C(    -0.73),
                         SIMDE_FLOAT32_C(    -0.30), SIMDE_FLOAT32_C(    -0.70), SIMDE_FLOAT32_C(    -0.40), SIMDE_FLOAT32_C(     0.60)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(    -0.39), SIMDE_FLOAT32_C(     0.40), SIMDE_FLOAT32_C(     0.66), SIMDE_FLOAT32_C(     0.34),
                         SIMDE_FLOAT32_C(     0.53), SIMDE_FLOAT32_C(    -0.26), SIMDE_FLOAT32_C(     0.78), SIMDE_FLOAT32_C(    -0.03),
                         SIMDE_FLOAT32_C(    -0.77), SIMDE_FLOAT32_C(     0.44), SIMDE_FLOAT32_C(    -0.58), SIMDE_FLOAT32_C(     0.38),
                         SIMDE_FLOAT32_C(    -0.77), SIMDE_FLOAT32_C(     0.99), SIMDE_FLOAT32_C(     0.03), SIMDE_FLOAT32_C(     0.84)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    -0.37), SIMDE_FLOAT32_C(     0.38), SIMDE_FLOAT32_C(     0.58), SIMDE_FLOAT32_C(     0.33),
                         SIMDE_FLOAT32_C(     0.49), SIMDE_FLOAT32_C(    -0.25), SIMDE_FLOAT32_C(     0.65), SIMDE_FLOAT32_C(    -0.03),
                         SIMDE_FLOAT32_C(    -0.65), SIMDE_FLOAT32_C(     0.41), SIMDE_FLOAT32_C(    -0.52), SIMDE_FLOAT32_C(     0.36),
                         SIMDE_FLOAT32_C(    -0.65), SIMDE_FLOAT32_C(     0.76), SIMDE_FLOAT32_C(     0.03), SIMDE_FLOAT32_C(     0.69)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.47), SIMDE_FLOAT32_C(     0.68), SIMDE_FLOAT32_C(    -0.15), SIMDE_FLOAT32_C(     0.82),
                         SIMDE_FLOAT32_C(     0.91), SIMDE_FLOAT32_C(     0.60), SIMDE_FLOAT32_C(     0.79), SIMDE_FLOAT32_C(     0.25),
                         SIMDE_FLOAT32_C(    -0.20), SIMDE_FLOAT32_C(    -0.08), SIMDE_FLOAT32_C(     0.34), SIMDE_FLOAT32_C(    -0.94),
                         SIMDE_FLOAT32_C(    -0.75), SIMDE_FLOAT32_C(    -0.77), SIMDE_FLOAT32_C(    -0.55), SIMDE_FLOAT32_C(     0.40)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.44), SIMDE_FLOAT32_C(     0.59), SIMDE_FLOAT32_C(    -0.15), SIMDE_FLOAT32_C(     0.68),
                         SIMDE_FLOAT32_C(     0.72), SIMDE_FLOAT32_C(     0.54), SIMDE_FLOAT32_C(     0.66), SIMDE_FLOAT32_C(     0.24),
                         SIMDE_FLOAT32_C(    -0.20), SIMDE_FLOAT32_C(    -0.08), SIMDE_FLOAT32_C(     0.33), SIMDE_FLOAT32_C(    -0.74),
                         SIMDE_FLOAT32_C(    -0.64), SIMDE_FLOAT32_C(    -0.65), SIMDE_FLOAT32_C(    -0.50), SIMDE_FLOAT32_C(     0.38)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(    -0.18), SIMDE_FLOAT32_C(     0.76), SIMDE_FLOAT32_C(     0.32), SIMDE_FLOAT32_C(     0.34),
                         SIMDE_FLOAT32_C(    -0.87), SIMDE_FLOAT32_C(    -0.80), SIMDE_FLOAT32_C(    -0.33), SIMDE_FLOAT32_C(    -0.53),
                         SIMDE_FLOAT32_C(    -0.19), SIMDE_FLOAT32_C(    -0.82), SIMDE_FLOAT32_C(     0.56), SIMDE_FLOAT32_C(     0.66),
                         SIMDE_FLOAT32_C(    -0.07), SIMDE_FLOAT32_C(     0.54), SIMDE_FLOAT32_C(     0.12), SIMDE_FLOAT32_C(    -0.17)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    -0.18), SIMDE_FLOAT32_C(     0.64), SIMDE_FLOAT32_C(     0.31), SIMDE_FLOAT32_C(     0.33),
                         SIMDE_FLOAT32_C(    -0.70), SIMDE_FLOAT32_C(    -0.66), SIMDE_FLOAT32_C(    -0.32), SIMDE_FLOAT32_C(    -0.49),
                         SIMDE_FLOAT32_C(    -0.19), SIMDE_FLOAT32_C(    -0.68), SIMDE_FLOAT32_C(     0.51), SIMDE_FLOAT32_C(     0.58),
                         SIMDE_FLOAT32_C(    -0.07), SIMDE_FLOAT32_C(     0.49), SIMDE_FLOAT32_C(     0.12), SIMDE_FLOAT32_C(    -0.17)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.69), SIMDE_FLOAT32_C(     0.84), SIMDE_FLOAT32_C(    -0.02), SIMDE_FLOAT32_C(    -0.59),
                         SIMDE_FLOAT32_C(    -0.45), SIMDE_FLOAT32_C(     0.73), SIMDE_FLOAT32_C(     0.51), SIMDE_FLOAT32_C(     0.62),
                         SIMDE_FLOAT32_C(     0.83), SIMDE_FLOAT32_C(     0.14), SIMDE_FLOAT32_C(     0.98), SIMDE_FLOAT32_C(    -0.91),
                         SIMDE_FLOAT32_C(     0.33), SIMDE_FLOAT32_C(     0.10), SIMDE_FLOAT32_C(     0.46), SIMDE_FLOAT32_C(    -0.74)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.60), SIMDE_FLOAT32_C(     0.69), SIMDE_FLOAT32_C(    -0.02), SIMDE_FLOAT32_C(    -0.53),
                         SIMDE_FLOAT32_C(    -0.42), SIMDE_FLOAT32_C(     0.62), SIMDE_FLOAT32_C(     0.47), SIMDE_FLOAT32_C(     0.55),
                         SIMDE_FLOAT32_C(     0.68), SIMDE_FLOAT32_C(     0.14), SIMDE_FLOAT32_C(     0.75), SIMDE_FLOAT32_C(    -0.72),
                         SIMDE_FLOAT32_C(     0.32), SIMDE_FLOAT32_C(     0.10), SIMDE_FLOAT32_C(     0.43), SIMDE_FLOAT32_C(    -0.63)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(    -0.77), SIMDE_FLOAT32_C(     0.82), SIMDE_FLOAT32_C(    -0.57), SIMDE_FLOAT32_C(    -1.00),
                         SIMDE_FLOAT32_C(    -0.34), SIMDE_FLOAT32_C(     0.92), SIMDE_FLOAT32_C(     0.29), SIMDE_FLOAT32_C(    -0.77),
                         SIMDE_FLOAT32_C(    -0.58), SIMDE_FLOAT32_C(    -0.07), SIMDE_FLOAT32_C(     0.71), SIMDE_FLOAT32_C(     0.98),
                         SIMDE_FLOAT32_C(    -0.76), SIMDE_FLOAT32_C(     0.42), SIMDE_FLOAT32_C(     0.03), SIMDE_FLOAT32_C(    -0.10)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    -0.65), SIMDE_FLOAT32_C(     0.68), SIMDE_FLOAT32_C(    -0.52), SIMDE_FLOAT32_C(    -0.76),
                         SIMDE_FLOAT32_C(    -0.33), SIMDE_FLOAT32_C(     0.73), SIMDE_FLOAT32_C(     0.28), SIMDE_FLOAT32_C(    -0.65),
                         SIMDE_FLOAT32_C(    -0.52), SIMDE_FLOAT32_C(    -0.07), SIMDE_FLOAT32_C(     0.61), SIMDE_FLOAT32_C(     0.75),
                         SIMDE_FLOAT32_C(    -0.64), SIMDE_FLOAT32_C(     0.40), SIMDE_FLOAT32_C(     0.03), SIMDE_FLOAT32_C(    -0.10)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(    -0.44), SIMDE_FLOAT32_C(    -0.36), SIMDE_FLOAT32_C(    -0.75), SIMDE_FLOAT32_C(    -0.03),
                         SIMDE_FLOAT32_C(     0.93), SIMDE_FLOAT32_C(     0.01), SIMDE_FLOAT32_C(    -0.33), SIMDE_FLOAT32_C(    -0.13),
                         SIMDE_FLOAT32_C(    -0.18), SIMDE_FLOAT32_C(     0.04), SIMDE_FLOAT32_C(     0.51), SIMDE_FLOAT32_C(     0.39),
                         SIMDE_FLOAT32_C(     0.01), SIMDE_FLOAT32_C(    -0.30), SIMDE_FLOAT32_C(     0.92), SIMDE_FLOAT32_C(    -0.70)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    -0.41), SIMDE_FLOAT32_C(    -0.35), SIMDE_FLOAT32_C(    -0.64), SIMDE_FLOAT32_C(    -0.03),
                         SIMDE_FLOAT32_C(     0.73), SIMDE_FLOAT32_C(     0.01), SIMDE_FLOAT32_C(    -0.32), SIMDE_FLOAT32_C(    -0.13),
                         SIMDE_FLOAT32_C(    -0.18), SIMDE_FLOAT32_C(     0.04), SIMDE_FLOAT32_C(     0.47), SIMDE_FLOAT32_C(     0.37),
                         SIMDE_FLOAT32_C(     0.01), SIMDE_FLOAT32_C(    -0.29), SIMDE_FLOAT32_C(     0.73), SIMDE_FLOAT32_C(    -0.60)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512 r = simde_mm512_tanh_ps(test_vec[i].a);
    simde_assert_m512_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_mask_tanh_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512 src;
    simde__mmask16 k;
    simde__m512 a;
    simde__m512 r;
  } test_vec[8] = {
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(    -0.45), SIMDE_FLOAT32_C(     0.69), SIMDE_FLOAT32_C(    -0.21), SIMDE_FLOAT32_C(    -0.66),
                         SIMDE_FLOAT32_C(     0.03), SIMDE_FLOAT32_C(    -0.92), SIMDE_FLOAT32_C(    -0.86), SIMDE_FLOAT32_C(     0.70),
                         SIMDE_FLOAT32_C(    -0.69), SIMDE_FLOAT32_C(     0.57), SIMDE_FLOAT32_C(     0.42), SIMDE_FLOAT32_C(     0.47),
                         SIMDE_FLOAT32_C(     0.67), SIMDE_FLOAT32_C(     0.03), SIMDE_FLOAT32_C(     0.04), SIMDE_FLOAT32_C(     0.35)),
      UINT16_C(41466),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.18), SIMDE_FLOAT32_C(     0.23), SIMDE_FLOAT32_C(     0.26), SIMDE_FLOAT32_C(    -0.98),
                         SIMDE_FLOAT32_C(    -0.44), SIMDE_FLOAT32_C(    -0.38), SIMDE_FLOAT32_C(    -0.31), SIMDE_FLOAT32_C(    -0.42),
                         SIMDE_FLOAT32_C(    -0.68), SIMDE_FLOAT32_C(     0.08), SIMDE_FLOAT32_C(     0.83), SIMDE_FLOAT32_C(    -0.27),
                         SIMDE_FLOAT32_C(     0.50), SIMDE_FLOAT32_C(    -0.30), SIMDE_FLOAT32_C(    -0.19), SIMDE_FLOAT32_C(    -0.75)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.18), SIMDE_FLOAT32_C(     0.69), SIMDE_FLOAT32_C(     0.25), SIMDE_FLOAT32_C(    -0.66),
                         SIMDE_FLOAT32_C(     0.03), SIMDE_FLOAT32_C(    -0.92), SIMDE_FLOAT32_C(    -0.86), SIMDE_FLOAT32_C(    -0.40),
                         SIMDE_FLOAT32_C(    -0.59), SIMDE_FLOAT32_C(     0.08), SIMDE_FLOAT32_C(     0.68), SIMDE_FLOAT32_C(    -0.26),
                         SIMDE_FLOAT32_C(     0.46), SIMDE_FLOAT32_C(     0.03), SIMDE_FLOAT32_C(    -0.19), SIMDE_FLOAT32_C(     0.35)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.47), SIMDE_FLOAT32_C(    -0.15), SIMDE_FLOAT32_C(     0.91), SIMDE_FLOAT32_C(     0.79),
                         SIMDE_FLOAT32_C(    -0.20), SIMDE_FLOAT32_C(     0.34), SIMDE_FLOAT32_C(    -0.75), SIMDE_FLOAT32_C(    -0.55),
                         SIMDE_FLOAT32_C(    -0.39), SIMDE_FLOAT32_C(     0.66), SIMDE_FLOAT32_C(     0.53), SIMDE_FLOAT32_C(     0.78),
                         SIMDE_FLOAT32_C(    -0.77), SIMDE_FLOAT32_C(    -0.58), SIMDE_FLOAT32_C(    -0.77), SIMDE_FLOAT32_C(     0.03)),
      UINT16_C(36797),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    -0.17), SIMDE_FLOAT32_C(     0.68), SIMDE_FLOAT32_C(     0.82), SIMDE_FLOAT32_C(     0.60),
                         SIMDE_FLOAT32_C(     0.25), SIMDE_FLOAT32_C(    -0.08), SIMDE_FLOAT32_C(    -0.94), SIMDE_FLOAT32_C(    -0.77),
                         SIMDE_FLOAT32_C(     0.40), SIMDE_FLOAT32_C(     0.40), SIMDE_FLOAT32_C(     0.34), SIMDE_FLOAT32_C(    -0.26),
                         SIMDE_FLOAT32_C(    -0.03), SIMDE_FLOAT32_C(     0.44), SIMDE_FLOAT32_C(     0.38), SIMDE_FLOAT32_C(     0.99)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    -0.17), SIMDE_FLOAT32_C(    -0.15), SIMDE_FLOAT32_C(     0.91), SIMDE_FLOAT32_C(     0.79),
                         SIMDE_FLOAT32_C(     0.24), SIMDE_FLOAT32_C(    -0.08), SIMDE_FLOAT32_C(    -0.74), SIMDE_FLOAT32_C(    -0.65),
                         SIMDE_FLOAT32_C(     0.38), SIMDE_FLOAT32_C(     0.66), SIMDE_FLOAT32_C(     0.33), SIMDE_FLOAT32_C(    -0.25),
                         SIMDE_FLOAT32_C(    -0.03), SIMDE_FLOAT32_C(     0.41), SIMDE_FLOAT32_C(    -0.77), SIMDE_FLOAT32_C(     0.76)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(    -0.10), SIMDE_FLOAT32_C(     0.84), SIMDE_FLOAT32_C(    -0.59), SIMDE_FLOAT32_C(     0.73),
                         SIMDE_FLOAT32_C(     0.62), SIMDE_FLOAT32_C(     0.14), SIMDE_FLOAT32_C(    -0.91), SIMDE_FLOAT32_C(     0.10),
                         SIMDE_FLOAT32_C(    -0.74), SIMDE_FLOAT32_C(     0.76), SIMDE_FLOAT32_C(     0.34), SIMDE_FLOAT32_C(    -0.80),
                         SIMDE_FLOAT32_C(    -0.53), SIMDE_FLOAT32_C(    -0.82), SIMDE_FLOAT32_C(     0.66), SIMDE_FLOAT32_C(     0.54)),
      UINT16_C(16804),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.03), SIMDE_FLOAT32_C(     0.69), SIMDE_FLOAT32_C(    -0.02), SIMDE_FLOAT32_C(    -0.45),
                         SIMDE_FLOAT32_C(     0.51), SIMDE_FLOAT32_C(     0.83), SIMDE_FLOAT32_C(     0.98), SIMDE_FLOAT32_C(     0.33),
                         SIMDE_FLOAT32_C(     0.46), SIMDE_FLOAT32_C(    -0.18), SIMDE_FLOAT32_C(     0.32), SIMDE_FLOAT32_C(    -0.87),
                         SIMDE_FLOAT32_C(    -0.33), SIMDE_FLOAT32_C(    -0.19), SIMDE_FLOAT32_C(     0.56), SIMDE_FLOAT32_C(    -0.07)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    -0.10), SIMDE_FLOAT32_C(     0.60), SIMDE_FLOAT32_C(    -0.59), SIMDE_FLOAT32_C(     0.73),
                         SIMDE_FLOAT32_C(     0.62), SIMDE_FLOAT32_C(     0.14), SIMDE_FLOAT32_C(    -0.91), SIMDE_FLOAT32_C(     0.32),
                         SIMDE_FLOAT32_C(     0.43), SIMDE_FLOAT32_C(     0.76), SIMDE_FLOAT32_C(     0.31), SIMDE_FLOAT32_C(    -0.80),
                         SIMDE_FLOAT32_C(    -0.53), SIMDE_FLOAT32_C(    -0.19), SIMDE_FLOAT32_C(     0.66), SIMDE_FLOAT32_C(     0.54)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(    -0.35), SIMDE_FLOAT32_C(    -0.44), SIMDE_FLOAT32_C(    -0.75), SIMDE_FLOAT32_C(     0.93),
                         SIMDE_FLOAT32_C(    -0.33), SIMDE_FLOAT32_C(    -0.18), SIMDE_FLOAT32_C(     0.51), SIMDE_FLOAT32_C(     0.01),
                         SIMDE_FLOAT32_C(     0.92), SIMDE_FLOAT32_C(    -0.77), SIMDE_FLOAT32_C(    -0.57), SIMDE_FLOAT32_C(    -0.34),
                         SIMDE_FLOAT32_C(     0.29), SIMDE_FLOAT32_C(    -0.58), SIMDE_FLOAT32_C(     0.71), SIMDE_FLOAT32_C(    -0.76)),
      UINT16_C( 2107),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.90), SIMDE_FLOAT32_C(    -0.20), SIMDE_FLOAT32_C(    -0.36), SIMDE_FLOAT32_C(    -0.03),
                         SIMDE_FLOAT32_C(     0.01), SIMDE_FLOAT32_C(    -0.13), SIMDE_FLOAT32_C(     0.04), SIMDE_FLOAT32_C(     0.39),
                         SIMDE_FLOAT32_C(    -0.30), SIMDE_FLOAT32_C(    -0.70), SIMDE_FLOAT32_C(     0.82), SIMDE_FLOAT32_C(    -1.00),
                         SIMDE_FLOAT32_C(     0.92), SIMDE_FLOAT32_C(    -0.77), SIMDE_FLOAT32_C(    -0.07), SIMDE_FLOAT32_C(     0.98)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    -0.35), SIMDE_FLOAT32_C(    -0.44), SIMDE_FLOAT32_C(    -0.75), SIMDE_FLOAT32_C(     0.93),
                         SIMDE_FLOAT32_C(     0.01), SIMDE_FLOAT32_C(    -0.18), SIMDE_FLOAT32_C(     0.51), SIMDE_FLOAT32_C(     0.01),
                         SIMDE_FLOAT32_C(     0.92), SIMDE_FLOAT32_C(    -0.77), SIMDE_FLOAT32_C(     0.68), SIMDE_FLOAT32_C(    -0.76),
                         SIMDE_FLOAT32_C(     0.73), SIMDE_FLOAT32_C(    -0.58), SIMDE_FLOAT32_C(    -0.07), SIMDE_FLOAT32_C(     0.75)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(    -0.02), SIMDE_FLOAT32_C(    -0.74), SIMDE_FLOAT32_C(    -0.31), SIMDE_FLOAT32_C(     0.18),
                         SIMDE_FLOAT32_C(     0.35), SIMDE_FLOAT32_C(     0.89), SIMDE_FLOAT32_C(     0.92), SIMDE_FLOAT32_C(     0.13),
                         SIMDE_FLOAT32_C(     0.48), SIMDE_FLOAT32_C(    -0.60), SIMDE_FLOAT32_C(    -0.79), SIMDE_FLOAT32_C(    -0.77),
                         SIMDE_FLOAT32_C(     0.22), SIMDE_FLOAT32_C(    -0.79), SIMDE_FLOAT32_C(    -0.78), SIMDE_FLOAT32_C(     0.44)),
      UINT16_C(22274),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.50), SIMDE_FLOAT32_C(     0.92), SIMDE_FLOAT32_C(    -0.72), SIMDE_FLOAT32_C(     0.16),
                         SIMDE_FLOAT32_C(    -0.86), SIMDE_FLOAT32_C(     0.43), SIMDE_FLOAT32_C(     0.93), SIMDE_FLOAT32_C(     0.11),
                         SIMDE_FLOAT32_C(     0.83), SIMDE_FLOAT32_C(    -0.08), SIMDE_FLOAT32_C(     0.24), SIMDE_FLOAT32_C(    -0.38),
                         SIMDE_FLOAT32_C(    -0.60), SIMDE_FLOAT32_C(    -0.62), SIMDE_FLOAT32_C(    -0.94), SIMDE_FLOAT32_C(     0.48)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    -0.02), SIMDE_FLOAT32_C(     0.73), SIMDE_FLOAT32_C(    -0.31), SIMDE_FLOAT32_C(     0.16),
                         SIMDE_FLOAT32_C(     0.35), SIMDE_FLOAT32_C(     0.41), SIMDE_FLOAT32_C(     0.73), SIMDE_FLOAT32_C(     0.11),
                         SIMDE_FLOAT32_C(     0.48), SIMDE_FLOAT32_C(    -0.60), SIMDE_FLOAT32_C(    -0.79), SIMDE_FLOAT32_C(    -0.77),
                         SIMDE_FLOAT32_C(     0.22), SIMDE_FLOAT32_C(    -0.79), SIMDE_FLOAT32_C(    -0.74), SIMDE_FLOAT32_C(     0.44)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.88), SIMDE_FLOAT32_C(    -0.81), SIMDE_FLOAT32_C(    -0.07), SIMDE_FLOAT32_C(    -0.78),
                         SIMDE_FLOAT32_C(     0.09), SIMDE_FLOAT32_C(     0.21), SIMDE_FLOAT32_C(     0.83), SIMDE_FLOAT32_C(    -0.07),
                         SIMDE_FLOAT32_C(    -0.29), SIMDE_FLOAT32_C(    -0.21), SIMDE_FLOAT32_C(    -0.32), SIMDE_FLOAT32_C(     0.78),
                         SIMDE_FLOAT32_C(    -0.63), SIMDE_FLOAT32_C(     0.56), SIMDE_FLOAT32_C(     0.44), SIMDE_FLOAT32_C(     0.43)),
      UINT16_C(27396),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    -0.96), SIMDE_FLOAT32_C(    -0.41), SIMDE_FLOAT32_C(    -0.74), SIMDE_FLOAT32_C(    -0.76),
                         SIMDE_FLOAT32_C(     0.79), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.82), SIMDE_FLOAT32_C(     0.16),
                         SIMDE_FLOAT32_C(     0.58), SIMDE_FLOAT32_C(    -0.01), SIMDE_FLOAT32_C(    -0.31), SIMDE_FLOAT32_C(    -0.72),
                         SIMDE_FLOAT32_C(     0.33), SIMDE_FLOAT32_C(     0.27), SIMDE_FLOAT32_C(    -0.92), SIMDE_FLOAT32_C(    -0.49)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.88), SIMDE_FLOAT32_C(    -0.39), SIMDE_FLOAT32_C(    -0.63), SIMDE_FLOAT32_C(    -0.78),
                         SIMDE_FLOAT32_C(     0.66), SIMDE_FLOAT32_C(     0.21), SIMDE_FLOAT32_C(    -0.68), SIMDE_FLOAT32_C(     0.16),
                         SIMDE_FLOAT32_C(    -0.29), SIMDE_FLOAT32_C(    -0.21), SIMDE_FLOAT32_C(    -0.32), SIMDE_FLOAT32_C(     0.78),
                         SIMDE_FLOAT32_C(    -0.63), SIMDE_FLOAT32_C(     0.26), SIMDE_FLOAT32_C(     0.44), SIMDE_FLOAT32_C(     0.43)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.53), SIMDE_FLOAT32_C(    -0.02), SIMDE_FLOAT32_C(    -0.97), SIMDE_FLOAT32_C(     0.64),
                         SIMDE_FLOAT32_C(     0.45), SIMDE_FLOAT32_C(    -0.77), SIMDE_FLOAT32_C(     0.11), SIMDE_FLOAT32_C(     0.59),
                         SIMDE_FLOAT32_C(     0.03), SIMDE_FLOAT32_C(     0.64), SIMDE_FLOAT32_C(    -0.08), SIMDE_FLOAT32_C(     0.08),
                         SIMDE_FLOAT32_C(    -0.71), SIMDE_FLOAT32_C(     0.61), SIMDE_FLOAT32_C(     0.39), SIMDE_FLOAT32_C(    -0.89)),
      UINT16_C(  953),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.02), SIMDE_FLOAT32_C(     0.81), SIMDE_FLOAT32_C(     0.14), SIMDE_FLOAT32_C(    -0.43),
                         SIMDE_FLOAT32_C(     0.31), SIMDE_FLOAT32_C(    -0.18), SIMDE_FLOAT32_C(    -0.46), SIMDE_FLOAT32_C(     0.68),
                         SIMDE_FLOAT32_C(     0.07), SIMDE_FLOAT32_C(    -0.27), SIMDE_FLOAT32_C(     0.12), SIMDE_FLOAT32_C(    -0.58),
                         SIMDE_FLOAT32_C(    -0.04), SIMDE_FLOAT32_C(    -0.25), SIMDE_FLOAT32_C(    -0.05), SIMDE_FLOAT32_C(     0.09)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.53), SIMDE_FLOAT32_C(    -0.02), SIMDE_FLOAT32_C(    -0.97), SIMDE_FLOAT32_C(     0.64),
                         SIMDE_FLOAT32_C(     0.45), SIMDE_FLOAT32_C(    -0.77), SIMDE_FLOAT32_C(    -0.43), SIMDE_FLOAT32_C(     0.59),
                         SIMDE_FLOAT32_C(     0.07), SIMDE_FLOAT32_C(     0.64), SIMDE_FLOAT32_C(     0.12), SIMDE_FLOAT32_C(    -0.52),
                         SIMDE_FLOAT32_C(    -0.04), SIMDE_FLOAT32_C(     0.61), SIMDE_FLOAT32_C(     0.39), SIMDE_FLOAT32_C(     0.09)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(    -0.79), SIMDE_FLOAT32_C(     0.33), SIMDE_FLOAT32_C(    -0.49), SIMDE_FLOAT32_C(     0.82),
                         SIMDE_FLOAT32_C(     0.96), SIMDE_FLOAT32_C(     0.95), SIMDE_FLOAT32_C(     0.83), SIMDE_FLOAT32_C(    -0.82),
                         SIMDE_FLOAT32_C(    -0.21), SIMDE_FLOAT32_C(    -0.93), SIMDE_FLOAT32_C(    -0.73), SIMDE_FLOAT32_C(    -0.42),
                         SIMDE_FLOAT32_C(     0.10), SIMDE_FLOAT32_C(     0.10), SIMDE_FLOAT32_C(     0.44), SIMDE_FLOAT32_C(    -0.20)),
      UINT16_C(12713),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    -0.84), SIMDE_FLOAT32_C(    -0.01), SIMDE_FLOAT32_C(     0.82), SIMDE_FLOAT32_C(     0.79),
                         SIMDE_FLOAT32_C(    -0.74), SIMDE_FLOAT32_C(    -0.31), SIMDE_FLOAT32_C(     0.73), SIMDE_FLOAT32_C(    -0.35),
                         SIMDE_FLOAT32_C(     0.06), SIMDE_FLOAT32_C(     0.11), SIMDE_FLOAT32_C(     0.72), SIMDE_FLOAT32_C(    -0.25),
                         SIMDE_FLOAT32_C(     0.94), SIMDE_FLOAT32_C(     0.36), SIMDE_FLOAT32_C(    -0.01), SIMDE_FLOAT32_C(     0.85)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    -0.79), SIMDE_FLOAT32_C(     0.33), SIMDE_FLOAT32_C(     0.68), SIMDE_FLOAT32_C(     0.66),
                         SIMDE_FLOAT32_C(     0.96), SIMDE_FLOAT32_C(     0.95), SIMDE_FLOAT32_C(     0.83), SIMDE_FLOAT32_C(    -0.34),
                         SIMDE_FLOAT32_C(     0.06), SIMDE_FLOAT32_C(    -0.93), SIMDE_FLOAT32_C(     0.62), SIMDE_FLOAT32_C(    -0.42),
                         SIMDE_FLOAT32_C(     0.74), SIMDE_FLOAT32_C(     0.10), SIMDE_FLOAT32_C(     0.44), SIMDE_FLOAT32_C(     0.69)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512 r = simde_mm512_mask_tanh_ps(test_vec[i].src, test_vec[i].k, test_vec[i].a);
    simde_assert_m512_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_tanh_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512d a;
    simde__m512d r;
  } test_vec[8] = {
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.50), SIMDE_FLOAT64_C(    0.67),
                         SIMDE_FLOAT64_C(   -0.30), SIMDE_FLOAT64_C(    0.03),
                         SIMDE_FLOAT64_C(   -0.19), SIMDE_FLOAT64_C(    0.04),
                         SIMDE_FLOAT64_C(   -0.75), SIMDE_FLOAT64_C(    0.35)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.46), SIMDE_FLOAT64_C(    0.58),
                         SIMDE_FLOAT64_C(   -0.29), SIMDE_FLOAT64_C(    0.03),
                         SIMDE_FLOAT64_C(   -0.19), SIMDE_FLOAT64_C(    0.04),
                         SIMDE_FLOAT64_C(   -0.64), SIMDE_FLOAT64_C(    0.34)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(   -0.68), SIMDE_FLOAT64_C(   -0.69),
                         SIMDE_FLOAT64_C(    0.08), SIMDE_FLOAT64_C(    0.57),
                         SIMDE_FLOAT64_C(    0.83), SIMDE_FLOAT64_C(    0.42),
                         SIMDE_FLOAT64_C(   -0.27), SIMDE_FLOAT64_C(    0.47)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   -0.59), SIMDE_FLOAT64_C(   -0.60),
                         SIMDE_FLOAT64_C(    0.08), SIMDE_FLOAT64_C(    0.52),
                         SIMDE_FLOAT64_C(    0.68), SIMDE_FLOAT64_C(    0.40),
                         SIMDE_FLOAT64_C(   -0.26), SIMDE_FLOAT64_C(    0.44)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(   -0.44), SIMDE_FLOAT64_C(    0.03),
                         SIMDE_FLOAT64_C(   -0.38), SIMDE_FLOAT64_C(   -0.92),
                         SIMDE_FLOAT64_C(   -0.31), SIMDE_FLOAT64_C(   -0.86),
                         SIMDE_FLOAT64_C(   -0.42), SIMDE_FLOAT64_C(    0.70)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   -0.41), SIMDE_FLOAT64_C(    0.03),
                         SIMDE_FLOAT64_C(   -0.36), SIMDE_FLOAT64_C(   -0.73),
                         SIMDE_FLOAT64_C(   -0.30), SIMDE_FLOAT64_C(   -0.70),
                         SIMDE_FLOAT64_C(   -0.40), SIMDE_FLOAT64_C(    0.60)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.18), SIMDE_FLOAT64_C(   -0.45),
                         SIMDE_FLOAT64_C(    0.23), SIMDE_FLOAT64_C(    0.69),
                         SIMDE_FLOAT64_C(    0.26), SIMDE_FLOAT64_C(   -0.21),
                         SIMDE_FLOAT64_C(   -0.98), SIMDE_FLOAT64_C(   -0.66)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.18), SIMDE_FLOAT64_C(   -0.42),
                         SIMDE_FLOAT64_C(    0.23), SIMDE_FLOAT64_C(    0.60),
                         SIMDE_FLOAT64_C(    0.25), SIMDE_FLOAT64_C(   -0.21),
                         SIMDE_FLOAT64_C(   -0.75), SIMDE_FLOAT64_C(   -0.58)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(   -0.77), SIMDE_FLOAT64_C(    0.44),
                         SIMDE_FLOAT64_C(   -0.58), SIMDE_FLOAT64_C(    0.38),
                         SIMDE_FLOAT64_C(   -0.77), SIMDE_FLOAT64_C(    0.99),
                         SIMDE_FLOAT64_C(    0.03), SIMDE_FLOAT64_C(    0.84)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   -0.65), SIMDE_FLOAT64_C(    0.41),
                         SIMDE_FLOAT64_C(   -0.52), SIMDE_FLOAT64_C(    0.36),
                         SIMDE_FLOAT64_C(   -0.65), SIMDE_FLOAT64_C(    0.76),
                         SIMDE_FLOAT64_C(    0.03), SIMDE_FLOAT64_C(    0.69)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(   -0.39), SIMDE_FLOAT64_C(    0.40),
                         SIMDE_FLOAT64_C(    0.66), SIMDE_FLOAT64_C(    0.34),
                         SIMDE_FLOAT64_C(    0.53), SIMDE_FLOAT64_C(   -0.26),
                         SIMDE_FLOAT64_C(    0.78), SIMDE_FLOAT64_C(   -0.03)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   -0.37), SIMDE_FLOAT64_C(    0.38),
                         SIMDE_FLOAT64_C(    0.58), SIMDE_FLOAT64_C(    0.33),
                         SIMDE_FLOAT64_C(    0.49), SIMDE_FLOAT64_C(   -0.25),
                         SIMDE_FLOAT64_C(    0.65), SIMDE_FLOAT64_C(   -0.03)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(   -0.20), SIMDE_FLOAT64_C(   -0.08),
                         SIMDE_FLOAT64_C(    0.34), SIMDE_FLOAT64_C(   -0.94),
                         SIMDE_FLOAT64_C(   -0.75), SIMDE_FLOAT64_C(   -0.77),
                         SIMDE_FLOAT64_C(   -0.55), SIMDE_FLOAT64_C(    0.40)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   -0.20), SIMDE_FLOAT64_C(   -0.08),
                         SIMDE_FLOAT64_C(    0.33), SIMDE_FLOAT64_C(   -0.74),
                         SIMDE_FLOAT64_C(   -0.64), SIMDE_FLOAT64_C(   -0.65),
                         SIMDE_FLOAT64_C(   -0.50), SIMDE_FLOAT64_C(    0.38)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.47), SIMDE_FLOAT64_C(    0.68),
                         SIMDE_FLOAT64_C(   -0.15), SIMDE_FLOAT64_C(    0.82),
                         SIMDE_FLOAT64_C(    0.91), SIMDE_FLOAT64_C(    0.60),
                         SIMDE_FLOAT64_C(    0.79), SIMDE_FLOAT64_C(    0.25)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.44), SIMDE_FLOAT64_C(    0.59),
                         SIMDE_FLOAT64_C(   -0.15), SIMDE_FLOAT64_C(    0.68),
                         SIMDE_FLOAT64_C(    0.72), SIMDE_FLOAT64_C(    0.54),
                         SIMDE_FLOAT64_C(    0.66), SIMDE_FLOAT64_C(    0.24)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512d r = simde_mm512_tanh_pd(test_vec[i].a);
    simde_assert_m512d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_mask_tanh_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512d src;
    simde__mmask8 k;
    simde__m512d a;
    simde__m512d r;
  } test_vec[8] = {
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(   -0.69), SIMDE_FLOAT64_C(    0.57),
                         SIMDE_FLOAT64_C(    0.42), SIMDE_FLOAT64_C(    0.47),
                         SIMDE_FLOAT64_C(    0.67), SIMDE_FLOAT64_C(    0.03),
                         SIMDE_FLOAT64_C(    0.04), SIMDE_FLOAT64_C(    0.35)),
      UINT8_C(139),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   -0.68), SIMDE_FLOAT64_C(    0.08),
                         SIMDE_FLOAT64_C(    0.83), SIMDE_FLOAT64_C(   -0.27),
                         SIMDE_FLOAT64_C(    0.50), SIMDE_FLOAT64_C(   -0.30),
                         SIMDE_FLOAT64_C(   -0.19), SIMDE_FLOAT64_C(   -0.75)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   -0.59), SIMDE_FLOAT64_C(    0.57),
                         SIMDE_FLOAT64_C(    0.42), SIMDE_FLOAT64_C(    0.47),
                         SIMDE_FLOAT64_C(    0.46), SIMDE_FLOAT64_C(    0.03),
                         SIMDE_FLOAT64_C(   -0.19), SIMDE_FLOAT64_C(   -0.64)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.18), SIMDE_FLOAT64_C(    0.23),
                         SIMDE_FLOAT64_C(    0.26), SIMDE_FLOAT64_C(   -0.98),
                         SIMDE_FLOAT64_C(   -0.44), SIMDE_FLOAT64_C(   -0.38),
                         SIMDE_FLOAT64_C(   -0.31), SIMDE_FLOAT64_C(   -0.42)),
      UINT8_C(229),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.84), SIMDE_FLOAT64_C(   -0.45),
                         SIMDE_FLOAT64_C(    0.69), SIMDE_FLOAT64_C(   -0.21),
                         SIMDE_FLOAT64_C(   -0.66), SIMDE_FLOAT64_C(    0.03),
                         SIMDE_FLOAT64_C(   -0.92), SIMDE_FLOAT64_C(   -0.86)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.69), SIMDE_FLOAT64_C(   -0.42),
                         SIMDE_FLOAT64_C(    0.60), SIMDE_FLOAT64_C(   -0.98),
                         SIMDE_FLOAT64_C(   -0.44), SIMDE_FLOAT64_C(    0.03),
                         SIMDE_FLOAT64_C(   -0.31), SIMDE_FLOAT64_C(   -0.70)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.40), SIMDE_FLOAT64_C(    0.40),
                         SIMDE_FLOAT64_C(    0.34), SIMDE_FLOAT64_C(   -0.26),
                         SIMDE_FLOAT64_C(   -0.03), SIMDE_FLOAT64_C(    0.44),
                         SIMDE_FLOAT64_C(    0.38), SIMDE_FLOAT64_C(    0.99)),
      UINT8_C(253),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   -0.55), SIMDE_FLOAT64_C(   -0.39),
                         SIMDE_FLOAT64_C(    0.66), SIMDE_FLOAT64_C(    0.53),
                         SIMDE_FLOAT64_C(    0.78), SIMDE_FLOAT64_C(   -0.77),
                         SIMDE_FLOAT64_C(   -0.58), SIMDE_FLOAT64_C(   -0.77)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   -0.50), SIMDE_FLOAT64_C(   -0.37),
                         SIMDE_FLOAT64_C(    0.58), SIMDE_FLOAT64_C(    0.49),
                         SIMDE_FLOAT64_C(    0.65), SIMDE_FLOAT64_C(   -0.65),
                         SIMDE_FLOAT64_C(    0.38), SIMDE_FLOAT64_C(   -0.65)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.12), SIMDE_FLOAT64_C(    0.47),
                         SIMDE_FLOAT64_C(   -0.15), SIMDE_FLOAT64_C(    0.91),
                         SIMDE_FLOAT64_C(    0.79), SIMDE_FLOAT64_C(   -0.20),
                         SIMDE_FLOAT64_C(    0.34), SIMDE_FLOAT64_C(   -0.75)),
      UINT8_C( 93),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.54), SIMDE_FLOAT64_C(   -0.17),
                         SIMDE_FLOAT64_C(    0.68), SIMDE_FLOAT64_C(    0.82),
                         SIMDE_FLOAT64_C(    0.60), SIMDE_FLOAT64_C(    0.25),
                         SIMDE_FLOAT64_C(   -0.08), SIMDE_FLOAT64_C(   -0.94)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.12), SIMDE_FLOAT64_C(   -0.17),
                         SIMDE_FLOAT64_C(   -0.15), SIMDE_FLOAT64_C(    0.68),
                         SIMDE_FLOAT64_C(    0.54), SIMDE_FLOAT64_C(    0.24),
                         SIMDE_FLOAT64_C(    0.34), SIMDE_FLOAT64_C(   -0.74)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.10), SIMDE_FLOAT64_C(   -0.74),
                         SIMDE_FLOAT64_C(    0.76), SIMDE_FLOAT64_C(    0.34),
                         SIMDE_FLOAT64_C(   -0.80), SIMDE_FLOAT64_C(   -0.53),
                         SIMDE_FLOAT64_C(   -0.82), SIMDE_FLOAT64_C(    0.66)),
      UINT8_C(145),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.33), SIMDE_FLOAT64_C(    0.46),
                         SIMDE_FLOAT64_C(   -0.18), SIMDE_FLOAT64_C(    0.32),
                         SIMDE_FLOAT64_C(   -0.87), SIMDE_FLOAT64_C(   -0.33),
                         SIMDE_FLOAT64_C(   -0.19), SIMDE_FLOAT64_C(    0.56)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.32), SIMDE_FLOAT64_C(   -0.74),
                         SIMDE_FLOAT64_C(    0.76), SIMDE_FLOAT64_C(    0.31),
                         SIMDE_FLOAT64_C(   -0.80), SIMDE_FLOAT64_C(   -0.53),
                         SIMDE_FLOAT64_C(   -0.82), SIMDE_FLOAT64_C(    0.51)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(   -0.76), SIMDE_FLOAT64_C(    0.03),
                         SIMDE_FLOAT64_C(    0.69), SIMDE_FLOAT64_C(   -0.02),
                         SIMDE_FLOAT64_C(   -0.45), SIMDE_FLOAT64_C(    0.51),
                         SIMDE_FLOAT64_C(    0.83), SIMDE_FLOAT64_C(    0.98)),
      UINT8_C( 75),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.98), SIMDE_FLOAT64_C(    0.42),
                         SIMDE_FLOAT64_C(   -0.10), SIMDE_FLOAT64_C(    0.84),
                         SIMDE_FLOAT64_C(   -0.59), SIMDE_FLOAT64_C(    0.73),
                         SIMDE_FLOAT64_C(    0.62), SIMDE_FLOAT64_C(    0.14)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   -0.76), SIMDE_FLOAT64_C(    0.40),
                         SIMDE_FLOAT64_C(    0.69), SIMDE_FLOAT64_C(   -0.02),
                         SIMDE_FLOAT64_C(   -0.53), SIMDE_FLOAT64_C(    0.51),
                         SIMDE_FLOAT64_C(    0.55), SIMDE_FLOAT64_C(    0.14)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.39), SIMDE_FLOAT64_C(   -0.30),
                         SIMDE_FLOAT64_C(   -0.70), SIMDE_FLOAT64_C(    0.82),
                         SIMDE_FLOAT64_C(   -1.00), SIMDE_FLOAT64_C(    0.92),
                         SIMDE_FLOAT64_C(   -0.77), SIMDE_FLOAT64_C(   -0.07)),
      UINT8_C( 93),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.51), SIMDE_FLOAT64_C(    0.01),
                         SIMDE_FLOAT64_C(    0.92), SIMDE_FLOAT64_C(   -0.77),
                         SIMDE_FLOAT64_C(   -0.57), SIMDE_FLOAT64_C(   -0.34),
                         SIMDE_FLOAT64_C(    0.29), SIMDE_FLOAT64_C(   -0.58)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.39), SIMDE_FLOAT64_C(    0.01),
                         SIMDE_FLOAT64_C(   -0.70), SIMDE_FLOAT64_C(   -0.65),
                         SIMDE_FLOAT64_C(   -0.52), SIMDE_FLOAT64_C(   -0.33),
                         SIMDE_FLOAT64_C(   -0.77), SIMDE_FLOAT64_C(   -0.52)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.48), SIMDE_FLOAT64_C(    0.94),
                         SIMDE_FLOAT64_C(   -0.35), SIMDE_FLOAT64_C(   -0.44),
                         SIMDE_FLOAT64_C(   -0.75), SIMDE_FLOAT64_C(    0.93),
                         SIMDE_FLOAT64_C(   -0.33), SIMDE_FLOAT64_C(   -0.18)),
      UINT8_C(213),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   -0.78), SIMDE_FLOAT64_C(    0.44),
                         SIMDE_FLOAT64_C(    0.90), SIMDE_FLOAT64_C(   -0.20),
                         SIMDE_FLOAT64_C(   -0.36), SIMDE_FLOAT64_C(   -0.03),
                         SIMDE_FLOAT64_C(    0.01), SIMDE_FLOAT64_C(   -0.13)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   -0.65), SIMDE_FLOAT64_C(    0.41),
                         SIMDE_FLOAT64_C(   -0.35), SIMDE_FLOAT64_C(   -0.20),
                         SIMDE_FLOAT64_C(   -0.75), SIMDE_FLOAT64_C(   -0.03),
                         SIMDE_FLOAT64_C(   -0.33), SIMDE_FLOAT64_C(   -0.13)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512d r = simde_mm512_mask_tanh_pd(test_vec[i].src, test_vec[i].k, test_vec[i].a);
    simde_assert_m512d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_udivrem_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i rem;
    simde__m256i r;
  } test_vec[8] = {
    { simde_x_mm256_set_epu32(UINT32_C(3215450688), UINT32_C(3586813553), UINT32_C(1508722402), UINT32_C(2220621656),
                              UINT32_C(1747596798), UINT32_C(2231263307), UINT32_C( 527472553), UINT32_C(2891870298)),
      simde_x_mm256_set_epu32(UINT32_C( 172780273), UINT32_C( 168508556), UINT32_C(3803608574), UINT32_C(4064895559),
                              UINT32_C(4201299039), UINT32_C(3984766001), UINT32_C( 392212716), UINT32_C(4009222911)),
      simde_x_mm256_set_epu32(UINT32_C( 105405774), UINT32_C(  48133877), UINT32_C(1508722402), UINT32_C(2220621656),
                              UINT32_C(1747596798), UINT32_C(2231263307), UINT32_C( 135259837), UINT32_C(2891870298)),
      simde_mm256_set_epi32(INT32_C(         18), INT32_C(         21), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          1), INT32_C(          0)) },
    { simde_x_mm256_set_epu32(UINT32_C(1192263444), UINT32_C(2208623573), UINT32_C(1322777130), UINT32_C( 163989560),
                              UINT32_C(1492341726), UINT32_C( 298608154), UINT32_C(1250819173), UINT32_C(3643996043)),
      simde_x_mm256_set_epu32(UINT32_C(3853764578), UINT32_C( 294920921), UINT32_C(3883385645), UINT32_C(4126975473),
                              UINT32_C(3898385479), UINT32_C( 422762821), UINT32_C(  12586973), UINT32_C( 182106357)),
      simde_x_mm256_set_epu32(UINT32_C(1192263444), UINT32_C( 144177126), UINT32_C(1322777130), UINT32_C( 163989560),
                              UINT32_C(1492341726), UINT32_C( 298608154), UINT32_C(   4708846), UINT32_C(   1868903)),
      simde_mm256_set_epi32(INT32_C(          0), INT32_C(          7), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(         99), INT32_C(         20)) },
    { simde_x_mm256_set_epu32(UINT32_C( 493161721), UINT32_C(3099851477), UINT32_C( 894221337), UINT32_C(2964507124),
                              UINT32_C( 492373082), UINT32_C(4281870485), UINT32_C(2207786213), UINT32_C(3953959418)),
      simde_x_mm256_set_epu32(UINT32_C( 328620632), UINT32_C(3970654641), UINT32_C(4110215287), UINT32_C(3940207296),
                              UINT32_C(4043901133), UINT32_C( 395141437), UINT32_C(4177201181), UINT32_C( 520340456)),
      simde_x_mm256_set_epu32(UINT32_C( 164541089), UINT32_C(3099851477), UINT32_C( 894221337), UINT32_C(2964507124),
                              UINT32_C( 492373082), UINT32_C( 330456115), UINT32_C(2207786213), UINT32_C( 311576226)),
      simde_mm256_set_epi32(INT32_C(          1), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(         10), INT32_C(          0), INT32_C(          7)) },
    { simde_x_mm256_set_epu32(UINT32_C(1710148738), UINT32_C(1974123080), UINT32_C(2870600100), UINT32_C( 118588227),
                              UINT32_C( 542053192), UINT32_C( 499863549), UINT32_C( 957375358), UINT32_C(3003933707)),
      simde_x_mm256_set_epu32(UINT32_C(4010243988), UINT32_C(4123176886), UINT32_C( 457043765), UINT32_C(4197612290),
                              UINT32_C(4246664437), UINT32_C(4080470003), UINT32_C(4182884971), UINT32_C(3894626243)),
      simde_x_mm256_set_epu32(UINT32_C(1710148738), UINT32_C(1974123080), UINT32_C( 128337510), UINT32_C( 118588227),
                              UINT32_C( 542053192), UINT32_C( 499863549), UINT32_C( 957375358), UINT32_C(3003933707)),
      simde_mm256_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          6), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
    { simde_x_mm256_set_epu32(UINT32_C(1734496959), UINT32_C( 380846712), UINT32_C(3352999607), UINT32_C(3555523675),
                              UINT32_C(1995198557), UINT32_C(3314312199), UINT32_C(2406584253), UINT32_C(1779168063)),
      simde_x_mm256_set_epu32(UINT32_C( 440775120), UINT32_C(4165466156), UINT32_C(3932377571), UINT32_C(3942500746),
                              UINT32_C(  67477586), UINT32_C( 108492873), UINT32_C( 360489056), UINT32_C( 254567893)),
      simde_x_mm256_set_epu32(UINT32_C( 412171599), UINT32_C( 380846712), UINT32_C(3352999607), UINT32_C(3555523675),
                              UINT32_C(  38348563), UINT32_C(  59526009), UINT32_C( 243649917), UINT32_C( 251760705)),
      simde_mm256_set_epi32(INT32_C(          3), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(         29), INT32_C(         30), INT32_C(          6), INT32_C(          6)) },
    { simde_x_mm256_set_epu32(UINT32_C(3932090380), UINT32_C(2449576763), UINT32_C(4246346280), UINT32_C( 201516689),
                              UINT32_C(2859036576), UINT32_C(2362091228), UINT32_C(3141663427), UINT32_C( 562234020)),
      simde_x_mm256_set_epu32(UINT32_C(4128600985), UINT32_C(4209418337), UINT32_C( 525546139), UINT32_C( 219277873),
                              UINT32_C( 295872976), UINT32_C(4150814551), UINT32_C(4029638246), UINT32_C(4092942946)),
      simde_x_mm256_set_epu32(UINT32_C(3932090380), UINT32_C(2449576763), UINT32_C(  41977168), UINT32_C( 201516689),
                              UINT32_C( 196179792), UINT32_C(2362091228), UINT32_C(3141663427), UINT32_C( 562234020)),
      simde_mm256_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          8), INT32_C(          0),
                            INT32_C(          9), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
    { simde_x_mm256_set_epu32(UINT32_C( 910061584), UINT32_C(2002226944), UINT32_C(3673004107), UINT32_C(4246624078),
                              UINT32_C( 523093293), UINT32_C(3059761572), UINT32_C(2206005509), UINT32_C(1943141679)),
      simde_x_mm256_set_epu32(UINT32_C( 123967721), UINT32_C(4199435689), UINT32_C( 228811177), UINT32_C(   1270356),
                              UINT32_C( 355625346), UINT32_C(4253972365), UINT32_C(3915742229), UINT32_C( 124491394)),
      simde_x_mm256_set_epu32(UINT32_C(  42287537), UINT32_C(2002226944), UINT32_C(  12025275), UINT32_C(   1094326),
                              UINT32_C( 167467947), UINT32_C(3059761572), UINT32_C(2206005509), UINT32_C(  75770769)),
      simde_mm256_set_epi32(INT32_C(          7), INT32_C(          0), INT32_C(         16), INT32_C(       3342),
                            INT32_C(          1), INT32_C(          0), INT32_C(          0), INT32_C(         15)) },
    { simde_x_mm256_set_epu32(UINT32_C(1755684145), UINT32_C(2233240925), UINT32_C(3244523643), UINT32_C(2995026741),
                              UINT32_C(2178270751), UINT32_C(1493088054), UINT32_C(4115137419), UINT32_C( 651362699)),
      simde_x_mm256_set_epu32(UINT32_C( 301617823), UINT32_C( 343728879), UINT32_C( 132913279), UINT32_C( 518796827),
                              UINT32_C(4258812658), UINT32_C(3762000867), UINT32_C( 361195763), UINT32_C( 469656308)),
      simde_x_mm256_set_epu32(UINT32_C( 247595030), UINT32_C( 170867651), UINT32_C(  54604947), UINT32_C( 401042606),
                              UINT32_C(2178270751), UINT32_C(1493088054), UINT32_C( 141984026), UINT32_C( 181706391)),
      simde_mm256_set_epi32(INT32_C(          5), INT32_C(          6), INT32_C(         24), INT32_C(          5),
                            INT32_C(          0), INT32_C(          0), INT32_C(         11), INT32_C(          1)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i rem;
    simde__m256i r = simde_mm256_udivrem_epi32(&rem, test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_u32(r, ==, test_vec[i].r);
    simde_assert_m256i_u32(rem, ==, test_vec[i].rem);
  }

  return MUNIT_OK;
}

HEDLEY_DIAGNOSTIC_PUSH
HEDLEY_DIAGNOSTIC_DISABLE_CAST_QUAL

#if HEDLEY_HAS_WARNING("-Wold-style-cast")
  #pragma clang diagnostic ignored "-Wold-style-cast"
#endif
#if HEDLEY_HAS_WARNING("-Wzero-as-null-pointer-constant")
  #pragma clang diagnostic ignored "-Wzero-as-null-pointer-constant"
#endif

static MunitTest test_suite_tests[] = {
  SIMDE_TESTS_DEFINE_TEST(mm_cos_ps),
  SIMDE_TESTS_DEFINE_TEST(mm_cos_pd),
  SIMDE_TESTS_DEFINE_TEST(mm256_cos_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_cos_pd),
  SIMDE_TESTS_DEFINE_TEST(mm512_cos_ps),
  SIMDE_TESTS_DEFINE_TEST(mm512_cos_pd),
  SIMDE_TESTS_DEFINE_TEST(mm512_mask_cos_ps),
  SIMDE_TESTS_DEFINE_TEST(mm512_mask_cos_pd),

  SIMDE_TESTS_DEFINE_TEST(mm_cosh_ps),
  SIMDE_TESTS_DEFINE_TEST(mm_cosh_pd),
  SIMDE_TESTS_DEFINE_TEST(mm256_cosh_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_cosh_pd),
  SIMDE_TESTS_DEFINE_TEST(mm512_cosh_ps),
  SIMDE_TESTS_DEFINE_TEST(mm512_cosh_pd),
  SIMDE_TESTS_DEFINE_TEST(mm512_mask_cosh_ps),
  SIMDE_TESTS_DEFINE_TEST(mm512_mask_cosh_pd),

  SIMDE_TESTS_DEFINE_TEST(mm_div_epi8),
  SIMDE_TESTS_DEFINE_TEST(mm_div_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm_div_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm512_mask_div_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm_div_epi64),
  SIMDE_TESTS_DEFINE_TEST(mm_div_epu8),
  SIMDE_TESTS_DEFINE_TEST(mm_div_epu16),
  SIMDE_TESTS_DEFINE_TEST(mm_div_epu32),
  SIMDE_TESTS_DEFINE_TEST(mm_div_epu64),
  SIMDE_TESTS_DEFINE_TEST(mm256_div_epi8),
  SIMDE_TESTS_DEFINE_TEST(mm256_div_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm256_div_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm256_div_epi64),
  SIMDE_TESTS_DEFINE_TEST(mm256_div_epu8),
  SIMDE_TESTS_DEFINE_TEST(mm256_div_epu16),
  SIMDE_TESTS_DEFINE_TEST(mm256_div_epu32),
  SIMDE_TESTS_DEFINE_TEST(mm512_mask_div_epu32),
  SIMDE_TESTS_DEFINE_TEST(mm256_div_epu64),
  SIMDE_TESTS_DEFINE_TEST(mm512_div_epi8),
  SIMDE_TESTS_DEFINE_TEST(mm512_div_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm512_div_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm512_div_epi64),
  SIMDE_TESTS_DEFINE_TEST(mm512_div_epu8),
  SIMDE_TESTS_DEFINE_TEST(mm512_div_epu16),
  SIMDE_TESTS_DEFINE_TEST(mm512_div_epu32),
  SIMDE_TESTS_DEFINE_TEST(mm512_div_epu64),

  SIMDE_TESTS_DEFINE_TEST(mm_idivrem_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm256_idivrem_epi32),

  SIMDE_TESTS_DEFINE_TEST(mm_rem_epi8),
  SIMDE_TESTS_DEFINE_TEST(mm_rem_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm_rem_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm_rem_epi64),
  SIMDE_TESTS_DEFINE_TEST(mm_rem_epu8),
  SIMDE_TESTS_DEFINE_TEST(mm_rem_epu16),
  SIMDE_TESTS_DEFINE_TEST(mm_rem_epu32),
  SIMDE_TESTS_DEFINE_TEST(mm_rem_epu64),
  SIMDE_TESTS_DEFINE_TEST(mm256_rem_epi8),
  SIMDE_TESTS_DEFINE_TEST(mm256_rem_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm256_rem_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm512_mask_rem_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm256_rem_epi64),
  SIMDE_TESTS_DEFINE_TEST(mm256_rem_epu8),
  SIMDE_TESTS_DEFINE_TEST(mm256_rem_epu16),
  SIMDE_TESTS_DEFINE_TEST(mm256_rem_epu32),
  SIMDE_TESTS_DEFINE_TEST(mm512_mask_rem_epu32),
  SIMDE_TESTS_DEFINE_TEST(mm256_rem_epu64),
  SIMDE_TESTS_DEFINE_TEST(mm512_rem_epi8),
  SIMDE_TESTS_DEFINE_TEST(mm512_rem_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm512_rem_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm512_rem_epi64),
  SIMDE_TESTS_DEFINE_TEST(mm512_rem_epu8),
  SIMDE_TESTS_DEFINE_TEST(mm512_rem_epu16),
  SIMDE_TESTS_DEFINE_TEST(mm512_rem_epu32),
  SIMDE_TESTS_DEFINE_TEST(mm512_rem_epu64),

  SIMDE_TESTS_DEFINE_TEST(mm_sin_ps),
  SIMDE_TESTS_DEFINE_TEST(mm_sin_pd),
  SIMDE_TESTS_DEFINE_TEST(mm256_sin_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_sin_pd),
  SIMDE_TESTS_DEFINE_TEST(mm512_sin_ps),
  SIMDE_TESTS_DEFINE_TEST(mm512_sin_pd),
  SIMDE_TESTS_DEFINE_TEST(mm512_mask_sin_ps),
  SIMDE_TESTS_DEFINE_TEST(mm512_mask_sin_pd),

  SIMDE_TESTS_DEFINE_TEST(mm_sinh_ps),
  SIMDE_TESTS_DEFINE_TEST(mm_sinh_pd),
  SIMDE_TESTS_DEFINE_TEST(mm256_sinh_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_sinh_pd),
  SIMDE_TESTS_DEFINE_TEST(mm512_sinh_ps),
  SIMDE_TESTS_DEFINE_TEST(mm512_sinh_pd),
  SIMDE_TESTS_DEFINE_TEST(mm512_mask_sinh_ps),
  SIMDE_TESTS_DEFINE_TEST(mm512_mask_sinh_pd),

  SIMDE_TESTS_DEFINE_TEST(mm_tan_ps),
  SIMDE_TESTS_DEFINE_TEST(mm_tan_pd),
  SIMDE_TESTS_DEFINE_TEST(mm256_tan_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_tan_pd),
  SIMDE_TESTS_DEFINE_TEST(mm512_tan_ps),
  SIMDE_TESTS_DEFINE_TEST(mm512_tan_pd),
  SIMDE_TESTS_DEFINE_TEST(mm512_mask_tan_ps),
  SIMDE_TESTS_DEFINE_TEST(mm512_mask_tan_pd),

  SIMDE_TESTS_DEFINE_TEST(mm_tanh_ps),
  SIMDE_TESTS_DEFINE_TEST(mm_tanh_pd),
  SIMDE_TESTS_DEFINE_TEST(mm256_tanh_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_tanh_pd),
  SIMDE_TESTS_DEFINE_TEST(mm512_tanh_ps),
  SIMDE_TESTS_DEFINE_TEST(mm512_tanh_pd),
  SIMDE_TESTS_DEFINE_TEST(mm512_mask_tanh_ps),
  SIMDE_TESTS_DEFINE_TEST(mm512_mask_tanh_pd),

  SIMDE_TESTS_DEFINE_TEST(mm_udivrem_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm256_udivrem_epi32),

  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

HEDLEY_C_DECL MunitSuite* SIMDE_TESTS_GENERATE_SYMBOL(suite)(void) {
  static MunitSuite suite = { (char*) "/" HEDLEY_STRINGIFY(SIMDE_TESTS_CURRENT_ISAX), test_suite_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE };

  return &suite;
}

#if defined(SIMDE_TESTS_SINGLE_ISAX)
int main(int argc, char* argv[HEDLEY_ARRAY_PARAM(argc + 1)]) {
  static MunitSuite suite = { "", test_suite_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE };

  return munit_suite_main(&suite, NULL, argc, argv);
}
#endif /* defined(SIMDE_TESTS_SINGLE_ISAX) */

HEDLEY_DIAGNOSTIC_POP
