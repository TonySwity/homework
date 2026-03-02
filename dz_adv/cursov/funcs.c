#include "funcs.h"

/* f1 = 0.6x + 3 */
double f1(double x) { return 0.6 * x + 3.0; }

/* f2 = (x-2)^3 - 1 */
double f2(double x) {
  double t = x - 2.0;
  return t * t * t - 1.0;
}

/* f3 = 3/x */
double f3(double x) { return 3.0 / x; }

double f1_minus_f3(double x) { return f1(x) - f3(x); }

double f1_minus_f2(double x) { return f1(x) - f2(x); }
