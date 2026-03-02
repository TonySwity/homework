#include "tests.h"
#include "methods.h"
#include <math.h>
#include <stdio.h>

/* Тестовые функции */
static double sqr(double x) { return x * x; }
static double c2(double x) {
  (void)x;
  return 2.0;
}
static double s(double x) { return sin(x); }

int test_root(void) {
  double r = root(sqr, c2, 1.0, 2.0, 1e-10);
  double ref = sqrt(2.0);
  double err = fabs(r - ref);

  printf("[test_root] r=%.12f ref=%.12f err=%.3e iters=%d\n", r, ref, err,
         root_last_iterations());

  return isfinite(r) && err < 1e-8;
}

int test_integral(void) {
  double pi = acos(-1.0);
  double val = integral(s, 0.0, pi, 1e-10);
  double err = fabs(val - 2.0);

  printf("[test_integral] val=%.12f ref=2.000000000000 err=%.3e\n", val, err);

  return isfinite(val) && err < 1e-8;
}
