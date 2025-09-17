#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

int main(void) {
  FILE *in = fopen("input.txt", "rb");
  if (!in) {
    printf("errno: %d", errno);
    perror("input.txt");
    return 1;
  }

  uint8_t s[1001] = {0};
  size_t n = fread(s, sizeof(*s), sizeof(s) - 1, in);
  fclose(in);
  s[n] = '\0';

  while (n && (s[n - 1] == '\n' || s[n - 1] == '\r')) {
    s[--n] = '\0';
  }

  for (size_t i = 0; i < n; ++i) {
    if (s[i] == 'a') {
      s[i] = 'b';
    } else if (s[i] == 'A') {
      s[i] = 'B';
    } else if (s[i] == 'b') {
      s[i] = 'a';
    } else if (s[i] == 'B') {
      s[i] = 'A';
    }
  }

  FILE *out = fopen("output.txt", "wb");
  if (!out) {
    printf("errno: %d", errno);
    perror("output.txt");
    return 1;
  }

  fwrite(s, sizeof(*s), n, out);
  fclose(out);
  return 0;
}
