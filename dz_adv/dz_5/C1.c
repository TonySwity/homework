#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void prefix_function(const char *s, int n, int *pi) {
  pi[0] = 0;
  for (int i = 1; i < n; ++i) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j])
      j = pi[j - 1];
    if (s[i] == s[j])
      ++j;
    pi[i] = j;
  }
}

static int pref_of_X_is_suf_of_Y(const char *X, const char *Y) {
  int nX = (int)strlen(X), nY = (int)strlen(Y);
  if (nX == 0 || nY == 0)
    return 0;

  int n = nX + 1 + nY;

  char *s = (char *)malloc((size_t)n + 1);
  int *pi = (int *)malloc((size_t)n * sizeof(int));
  if (!s || !pi)
    exit(1);

  memcpy(s, X, (size_t)nX);
  s[nX] = '#';
  memcpy(s + nX + 1, Y, (size_t)nY);
  s[n] = '\0';

  prefix_function(s, n, pi);
  int ans = pi[n - 1];

  free(pi);
  free(s);
  return ans;
}

int main(void) {
  char A[100005], B[100005];

  if (!fgets(A, sizeof(A), stdin)) {
    printf("0 0\n");
    return 0;
  }
  if (!fgets(B, sizeof(B), stdin)) {
    printf("0 0\n");
    return 0;
  }

  A[strcspn(A, "\r\n")] = '\0';
  B[strcspn(B, "\r\n")] = '\0';

  int first = pref_of_X_is_suf_of_Y(A, B);
  int second = pref_of_X_is_suf_of_Y(B, A);

  printf("%d %d\n", first, second);
  return 0;
}
