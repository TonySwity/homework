#include <stdio.h>

void convert_to_base(int n, int p) {
	if (n == 0) {
			printf("0");
			return;
	}
	
	char digits[32];
	int count = 0;
	
	while (n > 0) {
			int temp_num = n % p;
			digits[count++] = '0' + temp_num;
			n = n / p;
	}
	
	for (int i = count - 1; i >= 0; i--) {
			printf("%c", digits[i]);
	}
}

int main() {
	int n, p;
	scanf("%d %d", &n, &p);
	convert_to_base(n, p);
	printf("\n");
	return 0;
}