#include <stdio.h>

int is2pow(int num, int two) {
  if (two > num && num != 1) {
    return 0;
  }
  if (two == num || num == 1) {
    return 1;
  }

  return is2pow(num, two * 2);
}

int main(void) {
  int number;
  int two = 2;
  scanf("%d", &number);
  printf("%s", is2pow(number, two) == 1 ? "YES" : "NO");
  return 0;
}