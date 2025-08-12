#include <stdio.h>
#include <math.h>

void print_simple(int n) {
    if (n < 2) {
        printf("Число должно быть больше 1\n");
        return;
    }
    
    if (n < 0) {
        printf("-1 ");
        n = -n;
    }
    
    while (n % 2 == 0) {
        printf("2 ");
        n /= 2;
    }

    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            printf("%d ", i);
            n /= i;
        }
    }
    
    if (n > 2) {
        printf("%d", n);
    }
}

int main() {
    int num;
		scanf("%d", &num);
    
    print_simple(num);
    
    return 0;
}