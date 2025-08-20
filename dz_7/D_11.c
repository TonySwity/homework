#include <stdio.h>

int to_binary(int n) {
  if (n <= 1) {
    return n;
  }

  return to_binary(n / 2) + (n % 2);
}

int main(void) {
  int num;
  scanf("%d", &num);
  printf("%d\n", to_binary(num));
  return 0;
}