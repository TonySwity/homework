#include <stdio.h>

enum { N = 5 };

double diag_avg(const int a[N][N]) {
    long long sum = 0;
    for (int i = 0; i < N; ++i)
		sum += a[i][i];

    return (double)sum / N;
}

int main(void) {
    int arr[N][N];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (scanf("%d", &arr[i][j]) != 1) return 0;

    double avg = diag_avg(arr);

    int cnt = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (arr[i][j] > 0 && arr[i][j] > avg)
                ++cnt;

    printf("%d\n", cnt);
    return 0;
}
