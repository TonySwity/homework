#include <ctype.h>
#include <stdio.h>

#define MAXSTACK 100000

long long st[MAXSTACK];
int top = 0;

void push(long long x) { st[top++] = x; }

long long pop(void) { return st[--top]; }

int main(void) {
  char s[200005];

  if (!fgets(s, sizeof(s), stdin)) {
    return 0;
  }

  int i = 0;
  while (s[i]) {
    // пропуск пробелов
    while (isspace((unsigned char)s[i]))
      i++;

    if (isdigit((unsigned char)s[i])) {
      // читаем число
      long long v = 0;
      while (isdigit((unsigned char)s[i])) {
        v = v * 10 + (s[i] - '0');
        i++;
      }
      push(v);
      continue;
    }

    // оператор или конец
    char c = s[i];

    if (c == '.') {
      break;
    }

    if (c == '+' || c == '-' || c == '*' || c == '/') {
      long long b = pop();
      long long a = pop();
      long long r = 0;

      if (c == '+')
        r = a + b;
      else if (c == '-')
        r = a - b;
      else if (c == '*')
        r = a * b;
      else if (c == '/')
        r = a / b;

      push(r);
      i++;

      // вариант "+."
      if (s[i] == '.')
        break;
      continue;
    }

    // неизвестный символ — пропускаем
    i++;
  }

  if (top > 0) {
    printf("%lld\n", st[top - 1]);
  }

  return 0;
}
