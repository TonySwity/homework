#include <stdio.h>
#define ARRMAX 12

int main(void) {
  int temp = 0, count = 0, res = 0;
  int arr[ARRMAX];

  while (count < ARRMAX) {
    if (scanf("%d", &temp) == 1) {
      arr[count] = temp;
      count++;
    }
  }

  for (int i = 0; i < ARRMAX; ++i) {
    res += *(arr + i);
  }

  float res_mid_sum = res * 1.0 / ARRMAX;

  printf("%.2f", res_mid_sum);

  return 0;
}