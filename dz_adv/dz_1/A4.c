#include <stdint.h>
#include <stdio.h>

int main(void) {
  uint32_t N;
  int K;

  scanf("%u %d", &N, &K);

  uint32_t mask = (1u << K) - 1;
  uint32_t max_val = 0;

  for (int i = 0; i <= 32 - K; i++) {
    uint32_t cur = (N >> i) & mask;
    if (cur > max_val) {
      max_val = cur;
    }
  }

  printf("%u\n", max_val);
  return 0;
}
