#include <stdio.h>
#define ARRMAX 10

int main(void) {
  int temp, count = 0;
  int arr[ARRMAX], arr2[ARRMAX];

  while (count < ARRMAX) {
    if (scanf("%d", &temp) == 1) {
      arr[count] = temp;
      count++;
    }
  }
  int half = ARRMAX / 2;
  for (int i = 0; i < half; ++i) {
    *(arr2 + i) = *(arr + half - 1 - i);
    *(arr2 + i + half) = *(arr + ARRMAX - 1 - i);
  }

  for (int j = 0; j < ARRMAX; ++j) {
    if (j)
      printf(" ");
    printf("%d", *(arr2 + j));
  }

  return 0;
}