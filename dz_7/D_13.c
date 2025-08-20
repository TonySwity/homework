#include <stdio.h>

void print_prime_div(int num, int div) {
  if (num == 1) {
    return;
  }
  if (num < 2) {
    return;
  }

  if (num % div == 0) {
    printf("%d ", div);
    print_prime_div(num / div, div);
  } else {
    if (div == 2) {
      print_prime_div(num, 3);
    } else {
      print_prime_div(num, div + 2);
    }
  }
}

int main(void) {
  int num;
  scanf("%d", &num);
  print_prime_div(num, 2);
  printf("\n");

  return 0;
}