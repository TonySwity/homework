#include <stdio.h>

void print_rec(int n) {
  if (n > 1) {
    print_rec(n - 1);
  }
  printf("%d ", n);
}

int main(int argc, char **argv) {
  int num = 0;
  scanf("%d", &num);
  print_rec(num);
}