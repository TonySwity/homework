#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { BUF_CAP = 1000, ARR_CAP = 500 };

/**
 * Функция сравнения для сортировки по возрастанию
 * @param a Указатель на первый элемент
 * @param b Указатель на второй элемент
 * @return Отрицательное значение если a < b, положительное если a > b, 0 если равны
 */
static int compare_digit(const void *a, const void *b) {
    const int *num1 = (const int *)a;
    const int *num2 = (const int *)b;

    return *num1  - *num2;
}

int main(void) {
    FILE *in = fopen("input.txt", "rb");
    if (!in) {
        fprintf(stderr, "input.txt: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    char str[BUF_CAP + 1];
    size_t len = fread(str, 1, BUF_CAP, in);
    if (ferror(in)) {
        fprintf(stderr, "input: read error\n");
        fclose(in);
        return EXIT_FAILURE;
    }
    fclose(in);
    str[len] = '\0';

    while (len && (str[len-1] == '\n' || str[len-1] == '\r')) {
        str[--len] = '\0';
    }

    int nums[ARR_CAP];
    int count = 0;

    char *p = str;
    while (*p) {
        while (*p && isspace((unsigned char)*p)) {
			p++;
		}

        if (!*p) {
			break;
		}

        char *end;
        long v = strtol(p, &end, 10);

        if (p == end) {
            p++;
            continue;
        }

        if (count < ARR_CAP) {
            nums[count++] = (int)v;
        }
        p = end;
    }
	/*
    for (int i = 0; i < count; ++i) {
        printf("%s%d", i ? " " : "", nums[i]);
    }
    printf("\n");
    */

	qsort(nums, count, sizeof(*nums), compare_digit);

    FILE *out = fopen("output.txt", "wb");
    if (!out) {
        fprintf(stderr, "output.txt: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }
    for (int i = 0; i < count; ++i) {
        if (i) fputc(' ', out);
        fprintf(out, "%d", nums[i]);
    }
    fputc('\n', out);

    if (fclose(out) == EOF) {
        fprintf(stderr, "output: close error\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
