#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>

int compression(int a[], int b[], int N) {
    int k = 0;
    if (N <= 0) return 0;

    if (a[0] == 1) {
        b[k++] = 0;
    }

    int cur = a[0];
    int run = 1;

    for (int i = 1; i < N; ++i) {
        if (a[i] == cur) {
			run++;
        } else {
			b[k++]=run;
			cur = a[i];
			run = 1;
        }
    }

	b[k++] = run;
    return k;
}


int main(void) {
    size_t count_num = 0, cap = 0;
    int *a = NULL;
    char line[256];

    while (fgets(line, sizeof line, stdin)) {

		char *p = line;
		if (*p == '\n') {
				break;
		}
		for (;;) {
    		while (isspace((unsigned char)*p)) p++;
    		if (*p == '\0' || *p == '\n') {
				break;
			}

    		char *end;
    		long v = strtol(p, &end, 10);
    		if (p == end) break;

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

			if (v < INT_MIN || v > INT_MAX) {
				p = end;
				continue;
			}

			a[count_num++] = (int)v;

		}
    }
	int b[count_num+1];
    int size_b = compression(a, b, count_num);
	printf("[");
	for (int i=0; i < size_b; ++i) {
		printf("%d%s", *(b+i), i < size_b-1 ? ", " : "");
	}
	printf("]\n");
    free(a);
    return EXIT_SUCCESS;
}
