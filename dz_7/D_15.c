#include <stdio.h>

int max_find(int max) {
  int num;
  scanf("%d", &num);

  if (num == 0) {
    return max;
  }

  if (num > max) {
    max = num;
  }

  return max_find(max);
}

int main(void) {
  int num;
  scanf("%d", &num);
  int res = max_find(num);
  printf("%d\n", res);

  return 0;
}