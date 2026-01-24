#include <stdio.h>

int main(void) {
  int N;
  scanf("%d", &N);

  int x;
  scanf("%d", &x);

  int max = x;
  int count = 1;

  for (int i = 1; i < N; i++) {
    scanf("%d", &x);
    if (x > max) {
      max = x;
      count = 1;
    } else if (x == max) {
      count++;
    }
  }

  printf("%d\n", count);
  return 0;
}
