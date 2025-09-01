#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE 10

int main(void) {
    int arr[ARR_SIZE];
	int arr_2[ARR_SIZE];
	size_t count = 0;

    for (size_t i = 0; i < ARR_SIZE; ++i) {
        if (scanf("%d", &arr[i]) != 1) {
            fprintf(stderr, "Ошибка чтения данных\n");
            return EXIT_FAILURE;
        }
    }

    for (size_t i = 0; i < ARR_SIZE; ++i) {
        int current_count = 0;

        for (size_t j = 0; j < ARR_SIZE; ++j) {
            if (arr[i] == arr[j]) {
                current_count++;
            }
        }

        if (current_count == 1) {
            arr_2[count++] = arr[i];
        }
    }

    for (size_t i = 0; i < count; ++i) {
        printf("%d%s", arr_2[i], (i < count - 1) ? " " : "");
    }
    putchar('\n');

    return EXIT_SUCCESS;
}
