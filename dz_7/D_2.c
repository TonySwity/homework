#include <stdio.h>

int sum_rec(int n) {
  if (n <= 0) {
    return 0;
  }
  return n + sum_rec(n - 1);
}

int main(void) {
  int num;
  scanf("%d", &num);
  printf("%d\n", sum_rec(num));
  return 0;
}