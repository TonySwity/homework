#ifndef METHODS_H
#define METHODS_H

typedef double (*func_t)(double);

/* Поиск корня f(x)=g(x) на [a,b] с точностью eps (бисекция). */
double root(func_t f, func_t g, double a, double b, double eps);

/* Итерации последнего root() */
int root_last_iterations(void);

/* Определённый интеграл ∫[a,b] f(x) dx с точностью eps (адаптивный Симпсон). */
double integral(func_t f, double a, double b, double eps);

#endif
