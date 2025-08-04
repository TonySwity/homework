#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a, b;

	if (scanf("%d %d", &a, &b) != 2)
	{
		printf("Input error.");
		return 0;
	}

	int temp;
	
	while (b)
	{
		temp = a % b;
		a = b;
		b = temp;
	}

	printf("%d", abs(a));
	
	return 0;
}