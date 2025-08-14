#include <stdio.h>

int rec_sum(int n) {

  if (n < 10) {
    return n;
  }

  return n % 10 + rec_sum(n / 10);
}

int main(void) {
  int num;
  scanf("%d", &num);
  printf("%d", rec_sum(num));

  return 0;
}