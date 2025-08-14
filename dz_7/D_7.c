#include <stdio.h>

void print_rec(int n) {
  if (n <= 0) {
    return;
  }
  printf("%d ", n);
  print_rec(--n);
}

int main(int argc, char **argv) {
  int num = 0;
  scanf("%d", &num);
  print_rec(num);
}