#include <stdio.h>

#define MAX_COUNT 100
int main(void)
{
	int even_count = 0, odd_count = 0, num, count =0;
	int arr_num[MAX_COUNT]; 

	scanf("%d", &num);
	while(num>0) {
		arr_num[count] = num%10;	
		num/=10;
		count++;
	}

	for (int i=0; i<count; ++i) {
		if(*(arr_num + i)%2 == 0)
		{
			even_count++;
		}

		if(*(arr_num + i)%2 == 1)
		{
			odd_count++;
		}
	}

	printf("%d %d", even_count, odd_count);
}