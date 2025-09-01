#include <limits.h>
#include <stdio.h>
#define ARRMAX 10

int main(void) {
  int temp = 0, count = 0, max_one = 0, max_two = 0, max_One_Index = 0;
  int arr[ARRMAX];

  while (count < ARRMAX) {
    if (scanf("%d", &temp) == 1) {
      arr[count] = temp;
      count++;
    }
  }

  max_one = arr[0];
  max_One_Index = 0;
  for (int i = 1; i < ARRMAX; ++i) {
    if (arr[i] > max_one) {
      max_one = arr[i];
      max_One_Index = i;
    }
  }

  max_two = INT_MIN;
  for (int i = 0; i < ARRMAX; ++i) {
    if (i != max_One_Index && arr[i] > max_two) {
      max_two = arr[i];
    }
  }

  printf("%d", max_one + max_two);

  return 0;
}