#include <stdio.h>
#include <limits.h>
enum { N = 10 };

int max_in_line(size_t n, const int a[n][n]) {
    int sum = 0;
	int arr_max[N]={0};

    for (size_t i = 0; i < n; ++i) {
		for(size_t j = 0; j < n; ++j){
			if(arr_max[i] < a[i][j]){
				arr_max[i] = a[i][j];
			}
		}
    }

	for (size_t i = 0; i < n; ++i) {
		sum+= arr_max[i];
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

    printf("%d\n", max_in_line(N, arr));
    return 0;
}
