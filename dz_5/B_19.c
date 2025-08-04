#include <stdio.h>

#define TEN 10

int main(void) {
	char *answer = "NO";
	int num, num_sum =0;

	scanf("%d", &num);
	while(num>0) {
		num_sum += num%10;	
		num/=10;
	}

	if(num_sum == TEN)
	{
		answer = "YES";
	}

	printf("%s", answer);

	return 0;
}