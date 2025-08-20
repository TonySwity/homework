#include <stdio.h>

int a_counter(void) {
  char ch = getchar();

  if (ch == '.' || ch == '\n') {
    return 0;
  }

  int current_count = 0;
  if (ch == 'a') {
    current_count = 1;
  }

  return current_count + a_counter();
}

int main(void) {
  int count = a_counter();
  printf("%d\n", count);
  return 0;
}