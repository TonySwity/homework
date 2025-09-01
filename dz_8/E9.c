#include <stdio.h>
#define ARRMAX 10

int main(void) {
  int temp, count = 0;
  int arr[ARRMAX];

  while (count < ARRMAX) {
    if (scanf("%d", &temp) == 1) {
      *(arr + count) = temp;
      count++;
    }
  }

  for(int i = ARRMAX-1; i > 0; --i) {
	if (i == ARRMAX - 1) {
		temp = *(arr + i);
	}
	*(arr + i) = *(arr+i - 1);
  }
  *arr = temp;

  for (int j = 0; j < ARRMAX; ++j) {
    if (j)
      printf(" ");
    printf("%d", *(arr + j));
  }

  return 0;
}
