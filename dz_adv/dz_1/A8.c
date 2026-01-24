#include <stdint.h>
#include <stdio.h>

int main(void) {
  uint32_t M;
  if (scanf("%u", &M) != 1)
    return 0;

  const uint32_t CAP = 1000000u;

  uint32_t w = 1u;
  uint32_t maxM = 0u;
  while (w <= CAP) {
    maxM += w;
    if (w > CAP / 3u)
      break;
    w *= 3u;
  }

  if (M > maxM) {
    printf("-1\n");
    return 0;
  }

  int count = 0;
  while (M > 0) {
    uint32_t r = M % 3u;
    if (r == 1u) {
      count++;
      M = (M - 1u) / 3u;
    } else if (r == 2u) {
      count++;
      M = (M + 1u) / 3u;
    } else {
      M /= 3u;
    }
  }

  printf("%d\n", count);
  return 0;
}
