#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE 10

int main(void) {
    int arr[ARR_SIZE];

    for (size_t i = 0; i < ARR_SIZE; ++i) {
        if (scanf("%d", &arr[i]) != 1) {
            fprintf(stderr, "Ошибка чтения данных\n");
            return EXIT_FAILURE;
        }
    }

    int most_frequent = arr[0];
    int max_count = 1;

    for (size_t i = 0; i < ARR_SIZE; ++i) {
        int current_count = 0;

        for (size_t j = 0; j < ARR_SIZE; ++j) {
            if (arr[i] == arr[j]) {
                current_count++;
            }
        }

        if (current_count > max_count) {
            max_count = current_count;
            most_frequent = arr[i];
        }
    }

    printf("%d\n", most_frequent);

    return EXIT_SUCCESS;
}
