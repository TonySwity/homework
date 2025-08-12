#include <stdio.h>
#include <stdlib.h>

#define MAX_COUNT 100

int grow_up(int n) {
	int count = 0;
	int arr_n [MAX_COUNT] = { 0 };
	while(n>0) {
		arr_n[count] = n%10;	
		n/=10;
		count++;
	} 
	for (int i = 0; i < count -1; ++i) {
		if( arr_n[i] <= arr_n[i+1] ) {
			return 0;
		}
	}
	return 1;
}

int main(void) {
	int num;
	scanf("%d", &num);
	printf("%s", grow_up(num) == 1 ? "YES" : "NO");
	return 0;
}