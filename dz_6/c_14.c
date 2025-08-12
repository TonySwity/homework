#include <stdio.h>
#include <stdlib.h>

void try_even(int n) {
	if(n%2 ==0) {
		printf("YES");
	} else {
		printf("NO");
	}
}



int main(void) {
	int num, sum=0, count =0;
	
	scanf("%d", &num);
	while(num>0) {
		sum += num%10;	
		num/=10;
		count++;
	} 
	try_even(sum);
	return 0;
}