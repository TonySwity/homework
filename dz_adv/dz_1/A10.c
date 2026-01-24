#include <stdint.h>
#include <stdio.h>

int extractExp(float x) {
  union {
    float f;
    uint32_t u;
  } v;

  v.f = x;

  return (int)((v.u >> 23) & 0xFF);
}

int main(void) {
  float num;

  scanf("%f", &num);

  int temp = extractExp(num);

  printf("%d", temp);

  return 0;
}
