#include <stdio.h>
#define ARRMAX 5

int main(void) {
  int temp = 0, count = 0, min = 0;
  int arr[ARRMAX];

  while (count < ARRMAX) {
    if (scanf("%d", &temp) == 1) {
      arr[count] = temp;
      if (count == 0) {
        min = arr[count];
      } else if (min > arr[count]) {
        min = arr[count];
      }
      count++;
    }
  }

  printf("%d", min);

  return 0;
}