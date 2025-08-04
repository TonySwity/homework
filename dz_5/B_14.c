#include <stdio.h>

int main(void)
{
	int num = 789;
	int count = 0;

	while (scanf("%d", &num) && num != 0)
	{
		count++;
	}
	printf("%d", count);

	return 0;
}