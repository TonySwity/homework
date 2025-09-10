#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

static void sort_array(int size, int a[]) {
    for (int i = 0; i < size; i++) {
        int pos = i;
        for (int j = i + 1; j < size; j++) {
            if (a[j] < a[pos]) pos = j;
        }
        if (pos != i) {
            int t = a[i];
			a[i] = a[pos];
			a[pos] = t;
        }
    }
}

int main(void) {
    size_t count = 0, cap = 0;
    int *a = NULL, x;


    while (scanf("%d", &x) == 1 && x != 0) {
        if (count == cap) {
            size_t new_cap = cap ? cap * 2 : 64;
            int *tmp = (int*)realloc(a, new_cap * sizeof *a);
            if (!tmp) { perror("realloc"); free(a); return EXIT_FAILURE; }
            a = tmp; cap = new_cap;
        }
        a[count++] = x;
    }

    if (count == 0) { printf("%d\n", INT_MIN); free(a); return 0; }

    sort_array((int)count, a);

    int ans = INT_MIN;
    for (size_t i = 0; i + 1 < count; ++i) {
        if (a[i+1] == a[i]) continue;
        if (a[i+1] > a[i] + 1) {
            ans = a[i] + 1;
            break;
        }
    }

    printf("%d\n", ans);
    free(a);
    return 0;
}
