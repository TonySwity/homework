#include <stdio.h>
#define ARRMAX 10

int main(void) {
  int temp = 0, count = 0, min = 0, res = 0;
  int arr[ARRMAX];

  while (count < ARRMAX) {
    if (scanf("%d", &temp) == 1) {
      arr[count] = temp;
      count++;
    }
  }

  for (int i = 0; i < ARRMAX; ++i) {
    if (*(arr + i) > min) {
      res += *(arr + i);
    }
  }

  printf("%d", res);

  return 0;
}