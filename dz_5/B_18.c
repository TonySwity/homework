#include <stdio.h>

#define ONE 1

int main(void)
{
	int num = 0;
	int res = 0;
	int temp = 0;
	int vtemp = 0;
	int count = 0;
	if (scanf("%d", &num) != 1)
	{
		printf("Input error.");
		return 0;
	}

	while (count < num)
	{
		if (count < 1)
		{
			temp = ONE;
		}

		res = temp + vtemp;
		temp = vtemp;
		vtemp = res;

		count++;
		printf("%d ", res);
	}

	return 0;
}