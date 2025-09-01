#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE 10
#define MAX_RANGE 500

int main(void) {
    int numbers[ARR_SIZE];
    int positive[ARR_SIZE], negative[ARR_SIZE];
    size_t pos_count = 0, neg_count = 0;

    for (size_t i = 0; i < ARR_SIZE; ++i) {
        if (scanf("%d", &numbers[i]) != 1) {
            fprintf(stderr, "Ошибка чтения данных\n");
            return EXIT_FAILURE;
        }

        if (numbers[i] < -MAX_RANGE || numbers[i] > MAX_RANGE) {
            fprintf(stderr, "Число %d выходит за диапазон [-500, 500]\n", numbers[i]);
            return EXIT_FAILURE;
        }

        if (numbers[i] > 0) {
            positive[pos_count++] = numbers[i];
        } else if (numbers[i] < 0) {
            negative[neg_count++] = numbers[i];
        }
    }

    for (size_t i = 0; i < pos_count; ++i) {
        printf("%d", positive[i]);
        if (i < pos_count - 1) printf(" ");
    }

    if (pos_count > 0 && neg_count > 0) {
        printf(" ");
    }

    for (size_t i = 0; i < neg_count; ++i) {
        printf("%d", negative[i]);
        if (i < neg_count - 1) printf(" ");
    }

    putchar('\n');

    return EXIT_SUCCESS;
}
