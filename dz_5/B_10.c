#include <stdio.h>

#define MAX_COUNT 100

int main(void) {
	int num, count =0;
	int arr_num[MAX_COUNT]; 
	char *answer = "YES";
	scanf("%d", &num);
	while(num>0) {
		arr_num[count] = num%10;	
		num/=10;
		count++;
	}

for (int i=0; i<count-1; i++) {
	if(*(arr_num+i) <= *(arr_num+i+1))
	{
		answer = "NO";
	}
}
	printf("%s", answer);
}