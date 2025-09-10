#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void swap_negmax_last(int size, int a[]) {
    if (size <= 1) return;

    int pos = -1;
    int neg_max = 0;

    for (int i = 0; i < size; ++i) {
        if (a[i] < 0 && (pos == -1 || a[i] > neg_max)) {
            neg_max = a[i];
            pos = i;
        }
    }

    if (pos == -1 || pos == size - 1)
	{
		return;
	}

    int tmp = a[size - 1];
    a[size - 1] = a[pos];
    a[pos] = tmp;
}

int main(void) {
	size_t count = 0, cap = 0;
    int *a = NULL, x;


    while (scanf("%d", &x) == 1 && x != 0)  {
        if (count == cap) {
            size_t new_cap = cap ? cap * 2 : 8;
            int *tmp = (int*)realloc(a, new_cap * sizeof *a);
            if (!tmp) { perror("realloc"); free(a); return EXIT_FAILURE; }
            a = tmp; cap = new_cap;
        }
        a[count++] = x;
    }

	swap_negmax_last(count, a);

	for (size_t i = 0; i < count; ++i) {
		printf("%d%s", a[i], i < count-1 ? " " : "");
	}
	free(a);
	return EXIT_SUCCESS;
}
