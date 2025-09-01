#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRMAX 10

int main(void) {
    int arr[ARRMAX], result[ARRMAX];
    size_t result_count = 0;

    for (size_t i = 0; i < ARRMAX; ++i) {
        if (scanf("%d", &arr[i]) != 1) {
            fprintf(stderr, "Ошибка чтения данных\n");
            return EXIT_FAILURE;
        }
    }

    for (size_t i = 0; i < ARRMAX; ++i) {
        int count = 0;

        for (size_t j = 0; j < ARRMAX; ++j) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }

        if (count > 1) {
            bool already_added = false;
            for (size_t k = 0; k < result_count; ++k) {
                if (result[k] == arr[i]) {
                    already_added = true;
                    break;
                }
            }

            if (!already_added) {
                result[result_count++] = arr[i];
            }
        }
    }

    for (size_t i = 0; i < result_count; ++i) {
        printf("%d%s", result[i], (i < result_count - 1) ? " " : "");
    }
    putchar('\n');

    return EXIT_SUCCESS;
}
