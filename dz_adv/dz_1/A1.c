#include <ctype.h>
#include <stdio.h>

int main(void) {
  int N;
  if (scanf("%d", &N) != 1)
    return 0;

  N %= 26;

  int c = getchar();
  while (c != EOF && isspace((unsigned char)c)) {
    c = getchar();
  }

  while (c != EOF) {
    if (c == '.') {
      putchar('.');
      break;
    }

    if (c >= 'a' && c <= 'z') {
      c = 'a' + (c - 'a' + N) % 26;
    } else if (c >= 'A' && c <= 'Z') {
      c = 'A' + (c - 'A' + N) % 26;
    }
    putchar(c);

    c = getchar();
  }

  return 0;
}
