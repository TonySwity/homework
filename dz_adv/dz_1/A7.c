#include <stdint.h>
#include <stdio.h>

int main(void) {
  int N;
  if (scanf("%d", &N) != 1)
    return 0;

  uint32_t x;
  uint32_t ans = 0;

  for (int i = 0; i < N; i++) {
    scanf("%u", &x);
    ans ^= x;
  }

  printf("%u\n", ans);
  return 0;
}
