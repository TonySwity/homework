#include <ctype.h>
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { BUFF_CAP = 1000 };

int main(void) {
  FILE *in = fopen("input.txt", "rb");
  if (!in) {
    fprintf(stderr, "input.txt: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  char str[BUFF_CAP + 1];
  size_t len = fread(str, sizeof(*str), BUFF_CAP, in);
  if (ferror(in)) {
    fprintf(stderr, "input: read error\n");
    fclose(in);
    return EXIT_FAILURE;
  }
  fclose(in);
  str[len] = '\0';

  while (len && (str[len - 1] == '\n' || str[len - 1] == '\r')) {
    str[--len] = '\0';
  }

  size_t best_pos = 0, best_len = 0;
  size_t i = 0;

  while (i < len) {
    while (i < len && str[i] == ' ') {
      ++i;
    }
    size_t start = i;

    while (i < len && str[i] != ' ') {
      ++i;
    }

    size_t wlen = i - start;
    if (wlen > best_len) {
      best_len = wlen;
      best_pos = start;
    }
  }

  FILE *out = fopen("output.txt", "wb");
  if (!out) {
    fprintf(stderr, "output.txt: %s\n", strerror(errno));
    return 0;
  }

  if (best_len > 0) {
    fwrite(str + best_pos, 1, best_len, out);
  }
  fclose(out);

  return EXIT_SUCCESS;
}
