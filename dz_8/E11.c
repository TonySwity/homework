#include <stdio.h>
#include <stdlib.h>

/**
 * Функция сравнения для сортировки по последней цифре
 * @param a Указатель на первый элемент
 * @param b Указатель на второй элемент
 * @return Отрицательное значение если a < b, положительное если a > b, 0 если равны
 */
static int compare_by_last_digit(const void *a, const void *b) {
    const int *num1 = (const int *)a;
    const int *num2 = (const int *)b;

    return (*num1 % 10) - (*num2 % 10);
}

int main(void) {
    int arr[10];

    for (size_t i = 0; i < 10; ++i) {
        if (scanf("%d", &arr[i]) != 1) {
            fprintf(stderr, "Ошибка чтения данных\n");
            return EXIT_FAILURE;
        }
    }

    qsort(arr, 10, sizeof(arr[0]), compare_by_last_digit);

    for (size_t i = 0; i < 10; ++i) {
        printf("%d%s", arr[i], (i < 9) ? " " : "");
    }
    putchar('\n');

    return EXIT_SUCCESS;
}
