#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { BUF_CAP = 1000 };

size_t make_palindrome(const char *in, char *out) {
  int cnt[26] = {0};

  for (const unsigned char *p = (const unsigned char *)in; *p; ++p) {
    if (*p >= 'a' && *p <= 'z')
      cnt[*p - 'a']++;
  }

  size_t left_len = 0;
  for (int i = 0; i < 26; ++i)
    left_len += (size_t)(cnt[i] / 2);

  int center = -1;
  for (int i = 0; i < 26; ++i) {
    if (cnt[i] % 2 == 1) {
      center = i;
      break;
    }
  }

  size_t pos = 0;
  for (int i = 0; i < 26; ++i) {
    int k = cnt[i] / 2;
    while (k--)
      out[pos++] = (char)('a' + i);
  }

  if (center != -1)
    out[pos++] = (char)('a' + center);

  for (int i = 25; i >= 0; --i) {
    int k = cnt[i] / 2;
    while (k--)
      out[pos++] = (char)('a' + i);
  }

  out[pos] = '\0';
  return pos;
}

int main(void) {
  FILE *fi = fopen("input.txt", "rb");
  if (!fi) {
    fprintf(stderr, "input.txt: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  char inbuf[BUF_CAP + 1];
  size_t len = fread(inbuf, 1, BUF_CAP, fi);
  if (ferror(fi)) {
    fprintf(stderr, "input.txt: read error\n");
    fclose(fi);
    return EXIT_FAILURE;
  }
  fclose(fi);
  inbuf[len] = '\0';

  while (len && (inbuf[len - 1] == '\n' || inbuf[len - 1] == '\r')) {
    inbuf[--len] = '\0';
  }

  char outbuf[BUF_CAP + 1];
  make_palindrome(inbuf, outbuf);

  FILE *fo = fopen("output.txt", "wb");
  if (!fo) {
    fprintf(stderr, "output.txt: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }
  fwrite(outbuf, 1, strlen(outbuf), fo);
  fclose(fo);

  return EXIT_SUCCESS;
}
