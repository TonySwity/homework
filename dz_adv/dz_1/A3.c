#include <stdint.h>
#include <stdio.h>

int main(void) {
  uint32_t N;
  int K;

  scanf("%u %d", &N, &K);

  uint32_t mask = (1u << K) - 1;
  uint32_t result = N & mask;

  printf("%u\n", result);
  return 0;
}
