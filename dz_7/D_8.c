#include <stdio.h>

void print_rec_rev(int n, int m) {
  if (n <= m) {
    printf("%d", m);
    return;
  }
  printf("%d ", n);
  print_rec_rev(--n, m);
}

void print_rec(int n, int m) {
  if (n >= m) {
    printf("%d", n);
    return;
  }

  printf("%d ", n);
  print_rec(++n, m);
}

int main(int argc, char **argv) {
  int a, b;

  scanf("%d %d", &a, &b);
  if (a > b) {
    print_rec_rev(a, b);
  } else {
    print_rec(a, b);
  }
}