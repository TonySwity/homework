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

  size_t i = 0, j = 0;
  int sp = 0;

  char str_out[BUFF_CAP + 1];
  while (i < len) {
    unsigned char c = (unsigned char)str[i++];

    if (c == ' ') {
      sp = 1;
      continue;
    }

    if (isalpha(c)) {
      if (sp && j > 0) {
        str_out[j++] = '\n';
      }
      str_out[j++] = (char)c;
      sp = 0;
    }
  }
  if (j > 0) {
    str_out[j++] = '\n';
  }
  str_out[j] = '\0';

  FILE *out = fopen("output.txt", "wb");
  if (!out) {
    fprintf(stderr, "output.txt: %s\n", strerror(errno));
    return 0;
  }

  fwrite(str_out, sizeof(*str_out), j, out);

  fclose(out);

  return EXIT_SUCCESS;
}
