#include <stdint.h>
#include <stdio.h>

int main(void) {
  uint32_t N;
  scanf("%u", &N);

  int count = 0;
  while (N) {
    N &= (N - 1);
    count++;
  }

  printf("%d\n", count);
  return 0;
}
