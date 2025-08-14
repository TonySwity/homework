#include <stdio.h>

int rev_print(int n) {
  int num = n % 10;
  int temp = n / 10;

  if (temp == 0) {
    printf("%d ", num);
    return 0;
  }

  rev_print(temp);
  printf("%d ", num);

  return 0;
}

int main(void) {
  int num;
  scanf("%d", &num);
  rev_print(num);
  return 0;
}