#include <stdio.h>

int is_happy_number(int n) {
  int temp_num = n;
  int sum_num = 0, mult_num = 1;

  while (temp_num > 0) {
    int temp = temp_num % 10;
    sum_num += temp;
    mult_num *= temp;
    temp_num /= 10;
  }

  return (sum_num == mult_num);
}

int main(void) {
  int num;
  scanf("%d", &num);

  printf("%s", is_happy_number(num) ? "YES" : "NO");
  return 0;
}