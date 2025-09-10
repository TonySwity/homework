#include <limits.h>
#include <stdio.h>
#define ARRMAX 10

void change_max_min(int size, int a[]) {
	int min = INT_MAX, max = INT_MIN, minIndex = -1, maxIndex = -1;
	for (int i = 0; i < size; ++i) {

      if (max < a[i]) {
		max = a[i];
        maxIndex = i;
      }

      if (min > a[i]) {
		min = a[i];
        minIndex = i;
      }
	}

	int temp = a[maxIndex];
	a[maxIndex] = a[minIndex];
	a[minIndex] = temp;
}

int main(void) {
  int temp = 0, count = 0;
  int arr[ARRMAX];

  while (count < ARRMAX) {
    if (scanf("%d", &temp) == 1) {
      arr[count++] = temp;
    }
  }

  change_max_min(count, arr);

  for (int i = 0; i < count; ++i) {
	printf("%d%s", arr[i], i < count-1 ? " " : "\n");
  }


  return 0;
}
