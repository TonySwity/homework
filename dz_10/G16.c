#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { BUF_CAP = 1000 };

int main(void) {
  FILE *file_in = fopen("input.txt", "rb");
  if (!file_in) {
    fprintf(stderr, "input.txt: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  char buf[BUF_CAP + 1];
  size_t len = fread(buf, sizeof(*buf), BUF_CAP, file_in);
  if (ferror(file_in)) {
    fprintf(stderr, "input.txt read error\n");
    fclose(file_in);
  }
  fclose(file_in);
  buf[len] = '\0';

  while (len && (buf[len - 1] == '\n' || buf[len - 1] == '\r')) {
    buf[--len] = '\n';
  }

  const char *to = "Cao";
  const char *from = "Ling";
  char out_buf[BUF_CAP * 2];
  size_t out_pos = 0;

  for (size_t i = 0; i < len;) {
    if (strncmp(&buf[i], from, strlen(from)) == 0) {
      memcpy(&out_buf[out_pos], to, strlen(to));
      out_pos += strlen(to);
      i += strlen(from);
    } else {
      out_buf[out_pos++] = buf[i++];
    }
  }
  out_buf[out_pos] = '\0';

  FILE *file_ou = fopen("output.txt", "wb");
  if (!file_ou) {
    fprintf(stderr, "output.txt: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }
  fwrite(out_buf, 1, out_pos, file_ou);
  fclose(file_ou);

  return EXIT_SUCCESS;
}
