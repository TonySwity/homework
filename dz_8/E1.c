#include <stdio.h>

int main(void) {
  int temp = 0, count = 0, res = 0;
  int arr[5];

  while (count < 5) {
    if (scanf("%d", &temp) == 1) {
      arr[count] = temp;
      res += arr[count];
      count++;
    }
  }

  float midsum = res / 5.0;
  printf("%.3f", midsum);

  return 0;
}