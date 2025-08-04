#include <stdio.h>

int main(void) {
	int num; 

	scanf("%d", &num);

	for (int i = 10; i <= num; ++i) {
		int temp_num = i;
		int sum_num = 0, mult_num = 1;
		while(temp_num>0) {
			int temp = temp_num%10;
			sum_num += 	temp;
			mult_num *= temp;
			temp_num /= 10;
		}
		if(sum_num == mult_num)
		{
			printf("%d ", i);
		}
	}

	return 0;
}