#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define ARRMAX 10

int main(void) {
    int arr[ARRMAX], arr_2[ARRMAX];
	size_t counter = 0;

    for (size_t i = 0; i < ARRMAX; ++i) {
        if (scanf("%d", &arr[i]) != 1) {
            fprintf(stderr, "Ошибка чтения данных\n");
            return EXIT_FAILURE;
        }

		if((arr[i] / 10) % 10  == 0) {
			arr_2[counter++] = arr[i];
		}

    }

    for (size_t i = 0; i < counter; ++i) {
        printf("%d%s", arr_2[i], (i < counter-1) ? " " : "");
    }
    putchar('\n');

    return EXIT_SUCCESS;
}
