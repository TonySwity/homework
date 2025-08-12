#include <stdio.h>

int is_digit(char c) { return (c >= '0' && c <= '9'); }

int main(int argc, char **argv) {
  char c;
  int digit_count = 0;

  while ((c = getchar()) != '.' && c != '\n') {
    if (is_digit(c)) {
      digit_count++;
    }
  }

  printf("%d\n", digit_count);
  return 0;
}