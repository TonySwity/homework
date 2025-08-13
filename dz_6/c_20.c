#include <stdio.h>

typedef struct {
  int open_count;
  int has_error;
} BracketState;

BracketState is_bracket(char c, BracketState state) {
  if (c == '(') {
    state.open_count++;
  } else if (c == ')') {
    if (state.open_count > 0) {
      state.open_count--;
    } else {
      state.has_error = 1;
    }
  }
  return state;
}

int main(void) {
  char c;
  BracketState state = {0, 0};

  while ((c = getchar()) != '.' && c != '\n') {
    state = is_bracket(c, state);
  }

  printf("%s\n", (state.has_error || state.open_count != 0) ? "NO" : "YES");
  return 0;
}