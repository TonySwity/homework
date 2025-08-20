#include <stdio.h>

void print_seq(int n, int cur_num, int count) {
  if (n <= 0) {
    return;
  }

  if (count >= cur_num) {
    print_seq(n, cur_num + 1, 0);
  } else {
    printf("%d ", cur_num);
    print_seq(n - 1, cur_num, count + 1);
  }
}

int main(void) {
  int n;
  scanf("%d", &n);
  print_seq(n, 1, 0);
  printf("\n");

  return 0;
}