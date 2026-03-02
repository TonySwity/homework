#include "methods.h"
#include <math.h>

/* Документируем глобально-статическое состояние модуля:
 * g_last_root_iters хранит число итераций последнего root().
 */
static int g_last_root_iters = 0;

int root_last_iterations(void) { return g_last_root_iters; }

double root(func_t f, func_t g, double a, double b, double eps) {
  g_last_root_iters = 0;

  if (!(eps > 0.0) || !(a < b))
    return NAN;

  double fa = f(a) - g(a);
  double fb = f(b) - g(b);
  if (!isfinite(fa) || !isfinite(fb))
    return NAN;

  if (fa == 0.0)
    return a;
  if (fb == 0.0)
    return b;

  if (fa * fb > 0.0)
    return NAN; /* нет “зажатого” корня */

  while ((b - a) * 0.5 > eps) {
    double c = 0.5 * (a + b);
    double fc = f(c) - g(c);
    if (!isfinite(fc))
      return NAN;

    g_last_root_iters++;

    if (fabs(fc) <= eps)
      return c;

    if (fa * fc <= 0.0) { /* корень в [a,c] */
      b = c;
      fb = fc;
    } else { /* корень в [c,b] */
      a = c;
      fa = fc;
    }

    if (g_last_root_iters > 10000000)
      return NAN; /* страховка */
  }

  return 0.5 * (a + b);
}

/* --- Адаптивный Симпсон --- */

static double simpson(func_t f, double a, double b) {
  double c = 0.5 * (a + b);
  double fa = f(a);
  double fb = f(b);
  double fc = f(c);
  return (b - a) * (fa + 4.0 * fc + fb) / 6.0;
}

static double adaptive_simpson(func_t f, double a, double b, double eps,
                               double whole, int depth) {
  double c = 0.5 * (a + b);
  double left = simpson(f, a, c);
  double right = simpson(f, c, b);
  double delta = left + right - whole;

  if (depth <= 0) {
    return left + right + delta / 15.0;
  }

  if (fabs(delta) <= 15.0 * eps) {
    return left + right + delta / 15.0;
  }

  return adaptive_simpson(f, a, c, eps * 0.5, left, depth - 1) +
         adaptive_simpson(f, c, b, eps * 0.5, right, depth - 1);
}

double integral(func_t f, double a, double b, double eps) {
  if (!(eps > 0.0))
    return NAN;
  if (a == b)
    return 0.0;

  int sign = 1;
  if (a > b) {
    double t = a;
    a = b;
    b = t;
    sign = -1;
  }

  double whole = simpson(f, a, b);
  if (!isfinite(whole))
    return NAN;

  double res = adaptive_simpson(f, a, b, eps, whole, 25);
  return sign * res;
}
