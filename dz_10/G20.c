#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { BUF_CAP = 1000 };

int is_palindrom(const char *s) {
  int freq[26] = {0};
  for (const unsigned char *p = (const unsigned char *)s; *p; ++p) {
    if (*p == ' ')
      continue;
    if (*p >= 'a' && *p <= 'z')
      freq[*p - 'a']++;
  }
  int odd = 0;
  for (int i = 0; i < 26; ++i) {
    if (freq[i] & 1) {
      if (++odd > 1)
        return 0;
    }
  }
  return 1;
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

  puts(is_palindrom(buf) ? "YES" : "NO");
  return EXIT_SUCCESS;
}
