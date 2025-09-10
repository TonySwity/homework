#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>

int is_two_same(int size, int a[]) {
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (a[i] == a[j]) {
                return 1;
            }
        }
    }
    return 0;
}

int main(void) {
    size_t count_num = 0, cap = 0;
    int *a = NULL;
    char line[256];

    while (fgets(line, sizeof line, stdin)) {

        char *p = line;
        while (isspace((unsigned char)*p)) {
			p++;
		}
        if (*p == '\0') {
			break;
		}

        char *end;
        long v = strtol(p, &end, 10);
        if (p == end) {
			continue;
		}

        if (v < INT_MIN || v > INT_MAX) {
			continue;
		}

        if (count_num == cap) {
            size_t new_cap = cap ? cap * 2 : 8;
            int *tmp = realloc(a, new_cap * sizeof *a);
            if (!tmp) {
				perror("realloc");
				free(a);
				return EXIT_FAILURE;
			}
            a = tmp;
			cap = new_cap;
        }
        a[count_num++] = (int)v;
    }

    printf("%s", is_two_same(count_num, a)? "YES":"NO");
    free(a);
    return EXIT_SUCCESS;
}
