#include <stdio.h>

#define MAX_COUNT 100
int main(void)
{
	int min_num = 10,max_num = 0, num, count =0;
	int arr_num[MAX_COUNT]; 

	scanf("%d", &num);
	while(num>0) {
		arr_num[count] = num%10;	
		num/=10;
		count++;
	}

	for (int i=0; i<count; ++i) {
		if( min_num > *(arr_num + i))
		{
			min_num = *(arr_num + i);
		}

		if( max_num < *(arr_num + i))
		{
			max_num = *(arr_num + i);
		}
	}

	printf("%d %d", min_num, max_num);
}