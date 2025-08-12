#include <stdio.h>

int num_fuct(int n) {
	int res = 1;
	for(int i = 1; i <= n; ++i)
	{
		res *= i;
	}
	return res;
}

int main(void) {
	int num = 0;
	scanf("%d", &num);
	printf("%d", num_fuct(num));
	return 0;
}