#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { BUF_CAP = 1000 };

static size_t compress_spaces(const char *in, size_t n, char *out) {
  size_t w = 0;
  int seen_nonspace = 0;
  int prev_space = 0;

  for (size_t i = 0; i < n; ++i) {
    char c = in[i];

    if (c == ' ') {
      if (!seen_nonspace) {
        continue;
      }
      if (!prev_space) {
        out[w++] = ' ';
        prev_space = 1;
      }
    } else {
      out[w++] = c;
      prev_space = 0;
      seen_nonspace = 1;
    }
  }

  if (w > 0 && out[w - 1] == ' ')
    --w;

  out[w] = '\0';
  return w;
}

int main(void) {
  FILE *fi = fopen("input.txt", "rb");
  if (!fi) {
    fprintf(stderr, "input.txt: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  char buf[BUF_CAP + 1];
  size_t len = fread(buf, 1, BUF_CAP, fi);
  if (ferror(fi)) {
    fprintf(stderr, "input.txt: read error\n");
    fclose(fi);
    return EXIT_FAILURE;
  }
  fclose(fi);
  buf[len] = '\0';

  while (len && (buf[len - 1] == '\n' || buf[len - 1] == '\r')) {
    buf[--len] = '\0';
  }

  char out[BUF_CAP + 1];
  size_t out_len = compress_spaces(buf, len, out);

  FILE *fo = fopen("output.txt", "wb");
  if (!fo) {
    fprintf(stderr, "output.txt: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }
  if (out_len && fwrite(out, 1, out_len, fo) != out_len) {
    fprintf(stderr, "output.txt: write error\n");
    fclose(fo);
    return EXIT_FAILURE;
  }
  fclose(fo);
  return EXIT_SUCCESS;
}
