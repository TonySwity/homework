#include <stdio.h>

void reverse_string(void) {
  char ch = getchar();

  if (ch == '.' || ch == '\n') {
    return;
  }

  reverse_string();
  putchar(ch);
}

int main(void) {
  reverse_string();
  printf("\n");
  return 0;
}