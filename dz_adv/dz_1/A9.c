#include <stdint.h>
#include <stdio.h>

struct pack_array {
  uint32_t array;
  uint32_t count0 : 8;
  uint32_t count1 : 8;
};

void array2struct(int a[], struct pack_array *p) {
  uint32_t packed = 0;
  uint32_t c0 = 0, c1 = 0;

  for (int i = 0; i < 32; i++) {
    uint32_t bit = (a[i] != 0) ? 1u : 0u;

    if (bit)
      c1++;
    else
      c0++;
    packed |= bit << (31 - i);
  }

  p->array = packed;
  p->count0 = c0;
  p->count1 = c1;
}

int main(void) {
  int a[32];
  for (int i = 0; i < 32; i++) {
    if (scanf("%d", &a[i]) != 1)
      return 0;
  }

  struct pack_array p;
  array2struct(a, &p);

  printf("%u %u %u\n", p.array, (unsigned)p.count0, (unsigned)p.count1);
  return 0;
}
