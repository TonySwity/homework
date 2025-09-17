#include <stdio.h>
#include <stdlib.h>

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

/**
 * Функция сравнения для сортировки по убыванию
 * @param a Указатель на первый элемент
 * @param b Указатель на второй элемент
 * @return Отрицательное значение если a > b, положительное если a < b, 0 если равны
 */
static int compare_digit_rev(const void *a, const void *b) {
    const int *num1 = (const int *)a;
    const int *num2 = (const int *)b;

    return *num2 - *num1;
}

int main(void) {
    int arr[10];

    for (size_t i = 0; i < 10; ++i) {
        if (scanf("%d", &arr[i]) != 1) {
            fprintf(stderr, "Ошибка чтения данных\n");
            return EXIT_FAILURE;
        }
    }


    qsort(arr, 5, sizeof(arr[0]), compare_digit);

    qsort(arr + 5, 5, sizeof(arr[0]), compare_digit_rev);

    for (size_t i = 0; i < 10; ++i) {
        printf("%d%s", arr[i], (i < 9) ? " " : "");
    }
    putchar('\n');

    return EXIT_SUCCESS;
}
