#include <stdio.h>
#include <stdlib.h>

void sort_even_odd(int n, int a[]) {
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) continue; // пропускаем нечётные

        // нашли чётный a[i], нужно, чтобы он оказался раньше всех последующих нечётных
        int even = a[i];
        int j = i;
        while (j > 0 && (a[j-1] % 2 != 0)) {
            a[j] = a[j-1];
            j--;
        }
        a[j] = even;
    }
}

int main(void) {
    size_t count_num = 0, cap = 0;
    int *a = NULL;
    int temp_num;

    while (scanf("%d", &temp_num) == 1) {
        if (count_num == cap) {
            size_t new_cap = cap ? cap * 2 : 8;
            int *tmp = realloc(a, new_cap * sizeof *a);
            if (!tmp) {
                perror("realloc");
                free(a);
                return 1;
            }
            a = tmp;
            cap = new_cap;
        }
        a[count_num++] = temp_num;
    }

    if (!feof(stdin)) {
        fprintf(stderr, "Остановлено: встретился нечисловой токен.\n");
    }

	sort_even_odd(count_num, a);

    for (size_t i = 0; i < count_num; ++i) {
		printf("%d%c", *(a+i), i + 1 < count_num ? ' ' : '\n');
	}

    free(a);
    return 0;
}
