#include <stdio.h>
#include <stdbool.h>
#include <math.h>


bool is_prime(int n) {
    if (n < 2) return false;  
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    int limit = (int)sqrt(n) + 1;
    for (int i = 3; i < limit; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main(void) {
	int num;
	char *answer = "NO";
	scanf("%d", &num);

	if (is_prime(num)) {
			answer = "YES";
	}
	printf("%s",answer);
	return 0;
}