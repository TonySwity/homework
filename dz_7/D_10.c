#include <stdbool.h>
#include <stdio.h>

bool is_prime_rec(int n, int divisor) {
  if (n < 2)
    return false;
  if (n == 2)
    return true;
  if (n % 2 == 0)
    return false;

  if (divisor * divisor > n) {
    return true;
  }

  if (n % divisor == 0) {
    return false;
  }

  return is_prime_rec(n, divisor + 2);
}

int main(void) {
  int num;
  scanf("%d", &num);
  printf("%s\n", is_prime_rec(num, 3) ? "YES" : "NO");
  return 0;
}