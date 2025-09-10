#include <stdio.h>
enum { N = 5 };

int matrix_trace(size_t n, const int a[n][n]) {
    int sum = 0;
    for (size_t i = 0; i < n; ++i) {
        sum += a[i][i];
    }
    return sum;
}

int main(void) {

    int arr[N][N];

    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < N; ++j) {
            if (scanf("%d", &arr[i][j]) != 1) {
                return 0;
            }
        }
    }

    printf("%d\n", matrix_trace(N, arr));
    return 0;
}
