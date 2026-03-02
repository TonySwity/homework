#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcs.h"
#include "methods.h"
#include "tests.h"

/*
 * Площадь фигуры, образованной:
 *   f1 = 0.6x + 3
 *   f2 = (x-2)^3 - 1
 *   f3 = 3/x
 *
 * Положительные точки пересечения:
 *   xA: f1=f3
 *   xB: f2=f3
 *   xC: f1=f2
 *
 * S = ∫[xA..xB] (f1-f3) dx + ∫[xB..xC] (f1-f2) dx
 */

static void print_help(const char *prog) {
  printf("Usage: %s [options]\n", prog);
  printf("Options:\n");
  printf("  --help              Show this help\n");
  printf("  --points            Print x-intersections in one line: xA xB xC\n");
  printf("  --iters             Print iterations for each root: itA itB itC\n");
  printf("  --eps1 <value>      Root precision (default 1e-7)\n");
  printf("  --eps2 <value>      Integral precision (default 1e-7)\n");
  printf("  --test-root         Run root() self-test\n");
  printf("  --test-integral     Run integral() self-test\n");
}

static int parse_double_arg(int argc, char **argv, int *i, double *out) {
  if (*i + 1 >= argc)
    return 0;
  char *end = NULL;
  double v = strtod(argv[*i + 1], &end);
  if (end == argv[*i + 1] || *end != '\0' || !(v > 0.0) || !isfinite(v))
    return 0;
  *out = v;
  (*i)++;
  return 1;
}

int main(int argc, char **argv) {
  int opt_points = 0, opt_iters = 0;
  int opt_test_root = 0, opt_test_integral = 0;

  double eps1 = 1e-7;
  double eps2 = 1e-7;

  for (int i = 1; i < argc; ++i) {
    if (strcmp(argv[i], "--help") == 0) {
      print_help(argv[0]);
      return 0;
    } else if (strcmp(argv[i], "--points") == 0) {
      opt_points = 1;
    } else if (strcmp(argv[i], "--iters") == 0) {
      opt_iters = 1;
    } else if (strcmp(argv[i], "--test-root") == 0) {
      opt_test_root = 1;
    } else if (strcmp(argv[i], "--test-integral") == 0) {
      opt_test_integral = 1;
    } else if (strcmp(argv[i], "--eps1") == 0) {
      if (!parse_double_arg(argc, argv, &i, &eps1)) {
        fprintf(stderr, "Bad --eps1 value\n");
        return 2;
      }
    } else if (strcmp(argv[i], "--eps2") == 0) {
      if (!parse_double_arg(argc, argv, &i, &eps2)) {
        fprintf(stderr, "Bad --eps2 value\n");
        return 2;
      }
    } else {
      fprintf(stderr, "Unknown option: %s\nUse --help\n", argv[i]);
      return 2;
    }
  }

  /* Предварительное тестирование */
  if (opt_test_root && !test_root())
    return 1;
  if (opt_test_integral && !test_integral())
    return 1;

  /* Отрезки с гарантированной сменой знака для h(x)=f-g */
  /* xA: f1=f3, ~0.854 -> (0.5, 1.0) */
  double xA = root(f1, f3, 0.5, 1.0, eps1);
  int itA = root_last_iterations();

  /* xB: f2=f3, ~3.244 -> (3.0, 3.5) */
  double xB = root(f2, f3, 3.0, 3.5, eps1);
  int itB = root_last_iterations();

  /* xC: f1=f2, ~3.848 -> (3.5, 4.2) */
  double xC = root(f1, f2, 3.5, 4.2, eps1);
  int itC = root_last_iterations();

  if (!isfinite(xA) || !isfinite(xB) || !isfinite(xC) ||
      !(xA < xB && xB < xC)) {
    fprintf(stderr, "Failed to find valid intersections.\n");
    return 1;
  }

  if (opt_points) {
    printf("%.10f %.10f %.10f\n", xA, xB, xC);
  }
  if (opt_iters) {
    printf("%d %d %d\n", itA, itB, itC);
  }

  /* Интегралы разностей — через ЯВНЫЕ функции (см. funcs.c) */
  double area1 = integral(f1_minus_f3, xA, xB, eps2);
  double area2 = integral(f1_minus_f2, xB, xC, eps2);
  double area = area1 + area2;

  printf("%.10f\n", area);
  return 0;
}
