#include <stdio.h>

int main(void) {
	int num, temp =0;

	scanf("%d", &num);
	char *answer = "YES";
	while(num > 0)
	{
		temp = num%10;
		if(temp%2 == 1)
		{
			answer = "NO";
			break;
		}
		num /= 10;
	}
	printf("%s", answer);
}