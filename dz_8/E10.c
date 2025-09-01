#include <stdio.h>
#define ARRMAX 12

int main(void) {
  int temp, count = 0;
  int arr[ARRMAX], arr2[ARRMAX];

  while (count < ARRMAX) {
    if (scanf("%d", &temp) == 1) {
      arr[count] = temp;
      count++;
    }
  }
  int third = ARRMAX / 3;
  for (int i = 0; i < third; ++i) {
    *(arr2 + third + i) = *(arr + i);
    *(arr2 + i + third + third ) = *(arr + i + third );
    *(arr2 + i) = *(arr + i + third +third);
  }

  for (int j = 0; j < ARRMAX; ++j) {
    if (j)
      printf(" ");
    printf("%d", *(arr2 + j));
  }

  return 0;
}
