#include <stdio.h>

int main(void) {

	int a, count = 0;
	scanf("%d", &a);
	while(a>0) {
		a/=10;
		count++;
	}
	if(count==3) {
		printf("YES");
	} else {
		printf("NO");
	}
	return 0;
}