#include <stdio.h>
#include <string.h>

#define MAXN 1000005

static int pos[10][MAXN];
static int cnt[10];

static int lower_bound_int(const int *a, int n, int x) {
  int l = 0, r = n;
  while (l < r) {
    int m = l + (r - l) / 2;
    if (a[m] < x)
      l = m + 1;
    else
      r = m;
  }
  return l;
}

int main(void) {
  static char s[MAXN];
  if (scanf("%1000000s", s) != 1)
    return 0;

  int n = (int)strlen(s);
  if (n < 3) {
    printf("0\n");
    return 0;
  }

  for (int d = 0; d < 10; ++d)
    cnt[d] = 0;

  for (int i = 0; i < n; ++i) {
    int d = s[i] - '0';
    pos[d][cnt[d]++] = i;
  }

  int ans = 0;

  for (int x = 100; x <= 999; ++x) {
    int a = x / 100;
    int b = (x / 10) % 10;
    int c = x % 10;

    int i1 = lower_bound_int(pos[a], cnt[a], 0);
    if (i1 >= cnt[a])
      continue;
    int p1 = pos[a][i1];

    int i2 = lower_bound_int(pos[b], cnt[b], p1 + 1);
    if (i2 >= cnt[b])
      continue;
    int p2 = pos[b][i2];

    int i3 = lower_bound_int(pos[c], cnt[c], p2 + 1);
    if (i3 >= cnt[c])
      continue;

    ans++;
  }

  printf("%d\n", ans);
  return 0;
}
