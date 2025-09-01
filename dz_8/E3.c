#include <stdio.h>
#define ARRMAX 10

int main(void) {
  int temp = 0, count = 0, min = 0, max = 0, minIndex = 0, maxIndex = 0;
  int arr[ARRMAX];

  while (count < ARRMAX) {
    if (scanf("%d", &temp) == 1) {
      arr[count] = temp;
      if (count == 0) {
        min = arr[count];
        max = arr[count];
      }
      if (max < arr[count]) {
        max = arr[count];
        maxIndex = count;
      }

      if (min > arr[count]) {
        min = arr[count];
        minIndex = count;
      }

      count++;
    }
  }

  printf("%d %d %d %d", maxIndex + 1, max, minIndex + 1, min);

  return 0;
}