#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    for (int k = 2; k <= 9; k++) {
        int count = N / k;
        printf("%d %d\n", k, count);
    }

    return 0;
}
