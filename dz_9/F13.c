#include <stdio.h>
#include <stdlib.h>

int count_between(int from, int to, int size, int a[]) {
    if (size <= 0) return 0;

    if (from > to) { int tmp = from; from = to; to = tmp; }

    int cnt = 0;
    for (int i = 0; i < size; ++i) {
        if (a[i] >= from && a[i] <= to) {
            ++cnt;
        }
    }
    return cnt;
}

int main(void) {
    int from, to;
    if (scanf("%d %d", &from, &to) != 2) {
        return 0;
    }

    int *a = NULL;
    size_t size = 0, cap = 0;
    int x;
    while (scanf("%d", &x) == 1) {
        if (size == cap) {
            size_t new_cap = cap ? cap * 2 : 16;
            int *tmp = realloc(a, new_cap * sizeof *a);
            if (!tmp) { free(a); return 0; }
            a = tmp;
			cap = new_cap;
        }
        a[size++] = x;
    }

    printf("%d\n", count_between(from, to, (int)size, a));
    free(a);
    return 0;
}
