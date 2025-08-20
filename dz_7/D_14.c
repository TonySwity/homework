#include <stdio.h>

void odd_find(int num) {
  scanf("%d", &num);
  if (num == 0) {
    return;
  }

  if (num % 2 != 0) {
    printf("%d ", num);
  }

  odd_find(num);
}

int main(void) {
  int number;
  scanf("%d", &number);
  odd_find(number);

  return 0;
}