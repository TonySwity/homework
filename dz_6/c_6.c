#include <stdio.h>

int main(void) {
	unsigned int num = 1;
	scanf("%u", &num);
	if( num >= 1 && num <= 64)
	{
		printf("%lu", 1UL << (num-1));
	}
	return 0;
}