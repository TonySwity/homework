#include <stdio.h>

int num_sum(int n) {
	int res = 0;
	for(int i = 1; i <= n; ++i)
	{
		res += i;
	}
	return res;
}

int main(void) {
	int num = 0;
	scanf("%d", &num);
	printf("%d", num_sum(num));
	return 0;
}