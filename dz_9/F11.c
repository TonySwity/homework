#include <limits.h>
#include <stdio.h>
#define ARRMAX 30

int main(void) {
  int temp = 0, count = 0, min_one = 0, min_two = 0, min_one_index = -1, min_two_index = -1;
  int arr[ARRMAX];

  while (count < ARRMAX) {
    if (scanf("%d", &temp) == 1) {
      arr[count] = temp;
      count++;
    }
  }

  min_one = arr[0];
  min_one_index = 0;
  for (int i = 1; i < ARRMAX; ++i) {
    if (arr[i] < min_one) {
      min_one = arr[i];
      min_one_index = i;
    }
  }

  min_two = INT_MAX;
  for (int i = 0; i < ARRMAX; ++i) {
    if (i != min_one_index && arr[i] < min_two) {
      min_two = arr[i];
	  min_two_index = i;
    }
  }

  if(min_one_index < min_two_index){
	printf("%d %d\n", min_one_index, min_two_index);
  } else {
	printf("%d %d\n", min_two_index, min_one_index);
  }


  return 0;
}
