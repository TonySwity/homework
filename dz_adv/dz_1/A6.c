#include <stdint.h>
#include <stdio.h>

int main(void) {
  uint32_t N;
  scanf("%u", &N);

  uint32_t mask = 0xFF000000u;
  N ^= mask;

  printf("%u\n", N);
  return 0;
}
