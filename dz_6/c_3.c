#include <stdio.h>

int middle(int a, int b)
{
	return (a+b) / 2 ;
}

int main(void) {
	int num = 0, num_2 = 0;
	scanf("%d %d", &num, &num_2);

	printf("%d", middle(num, num_2));
	return 0;
}