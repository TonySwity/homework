#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  FILE *fi = fopen("input.txt", "rb");
  if (!fi) {
    fprintf(stderr, "input.txt: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  size_t stars = 0;
  char buf[4096];
  for (;;) {
    size_t n = fread(buf, 1, sizeof buf, fi);
    for (size_t i = 0; i < n; ++i)
      if (buf[i] == '*')
        ++stars;
    if (n < sizeof buf) {
      if (ferror(fi)) {
        fprintf(stderr, "input.txt: read error\n");
        fclose(fi);
        return EXIT_FAILURE;
      }
      break;
    }
  }
  fclose(fi);

  size_t rows = 0, sum = 0;
  while (sum < stars) {
    ++rows;
    sum += rows;
  }

  FILE *fo = fopen("output.txt", "wb");
  if (!fo) {
    fprintf(stderr, "output.txt: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  if (sum != stars || rows == 0) {
    fputs("NO", fo);
    fclose(fo);
    return EXIT_SUCCESS;
  }

  for (size_t i = 1; i <= rows; ++i) {
    for (size_t s = 0; s < rows - i; ++s)
      fputc(' ', fo);
    for (size_t j = 1; j <= i; ++j) {
      fputc('*', fo);
      if (j < i)
        fputc(' ', fo);
    }
    if (i < rows)
      fputc('\n', fo);
  }

  fclose(fo);
  return EXIT_SUCCESS;
}
