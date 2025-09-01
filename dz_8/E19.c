#include <stdio.h>
#include <string.h>

int main() {
    char num[10001];
    scanf("%s", num);
    int len = strlen(num);

    for (int i = 0; i < len; i++) {
        printf("%c", num[i]);
        if (i < len - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
