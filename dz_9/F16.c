#include <stdio.h>

int main(void) {
    char col;
    int row;
    if (scanf("%c%d", &col, &row) != 2) {
        return 1;
    }

    int col_num = col - 'A' + 1;

    if ((col_num + row) % 2 == 0) {
        printf("BLACK\n");
    } else {
        printf("WHITE\n");
    }

    return 0;
}
