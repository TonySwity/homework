#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { BUF_CAP = 1000 };

int main(void) {
  FILE *fi = fopen("input.txt", "rb");
  if (!fi) {
    fprintf(stderr, "input.txt %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  char buf[BUF_CAP + 1];
  size_t len = fread(buf, 1, BUF_CAP, fi);
  if (ferror(fi)) {
    fprintf(stderr, "input.txt read error\n");
    fclose(fi);
    return EXIT_FAILURE;
  }
  fclose(fi);
  buf[len] = '\0';

  while (len && (buf[len - 1] == '\n' || buf[len - 1] == '\r')) {
    buf[--len] = '\0';
  }

  char out_buf[BUF_CAP + 1];
  memcpy(out_buf, buf, len);
  out_buf[len] = '\0';

  size_t idx[BUF_CAP];
  size_t cnt = 0;
  for (size_t i = 0; i < len; ++i) {
    if (isalpha((unsigned char)buf[i])) {
      idx[cnt++] = i;
    }
  }

  for (size_t k = 0; k + 1 < cnt; k += 2) {
    size_t a = idx[k], b = idx[k + 1];
    out_buf[a] = buf[b];
    out_buf[b] = buf[a];
  }

  FILE *fo = fopen("output.txt", "wb");
  if (!fo) {
    fprintf(stderr, "output.txt: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }
  if (fwrite(out_buf, 1, len, fo) != len || ferror(fo)) {
    fprintf(stderr, "output.txt: write error\n");
    fclose(fo);
    return EXIT_FAILURE;
  }
  fclose(fo);
  return EXIT_SUCCESS;
}
