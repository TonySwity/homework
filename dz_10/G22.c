#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { BUF_CAP = 32 };

static char code_of(char c) {

  switch (c) {
  case 'b':
  case 'f':
  case 'p':
  case 'v':
    return '1';
  case 'c':
  case 'g':
  case 'j':
  case 'k':
  case 'q':
  case 's':
  case 'x':
  case 'z':
    return '2';
  case 'd':
  case 't':
    return '3';
  case 'l':
    return '4';
  case 'm':
  case 'n':
    return '5';
  case 'r':
    return '6';

  case 'a':
  case 'e':
  case 'h':
  case 'i':
  case 'o':
  case 'u':
  case 'w':
  case 'y':
    return '0';
  default:
    return '0';
  }
}

int main(void) {
  FILE *fi = fopen("input.txt", "rb");
  if (!fi) {
    fprintf(stderr, "input.txt: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  char s[BUF_CAP];
  if (fscanf(fi, "%31s", s) != 1) {
    fclose(fi);
    return EXIT_FAILURE;
  }
  fclose(fi);

  char out[5];
  out[0] = s[0];
  int out_len = 1;

  char prev = '\0';
  for (size_t i = 1; s[i] != '\0'; ++i) {
    char c = s[i];
    char code = code_of(c);
    if (code == '0') {
      continue;
    }
    if (code != prev) {
      if (out_len < 4) {
        out[out_len++] = code;
      }
      prev = code;
    }
  }

  while (out_len < 4)
    out[out_len++] = '0';
  out[4] = '\0';

  FILE *fo = fopen("output.txt", "wb");
  if (!fo) {
    fprintf(stderr, "output.txt: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }
  fputs(out, fo);
  fclose(fo);
  return EXIT_SUCCESS;
}
