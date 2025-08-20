#include <stdio.h>

int recurs_power(int n, int p) {

  if (p == 0) {
    return 1;
  }

  if (p == 1) {
    return n;
  }

  return n * recurs_power(n, p - 1);
}

int main(void) {
  int n, p;
  scanf("%d %d", &n, &p);

  int result = recurs_power(n, p);
  printf("%d\n", result);

  return 0;
}