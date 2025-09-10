#include <stdio.h>
#include <stdlib.h>


int count_bigger_abs(int n, int a[]) {
	if (n <= 0) return 0;

	int cnt = 0;
    int big_num = a[0];
    for (int i = 1; i < n; ++i) {
        if (big_num < a[i]) {
			big_num = a[i];
        }
    }

	for (int i = 0; i < n; ++i) {
        if (big_num < abs(a[i])) {
			cnt++;
        }
    }

    return cnt;
}

int main(void) {
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

    printf("%d\n", count_bigger_abs((int)size, a));
    free(a);
    return 0;
}
