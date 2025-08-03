#include <stdio.h>

int main(void) {

	int count = 0;

	scanf("%d", &count);
	for (int i = 1; i <= count; i++) {
	
		printf("%d %d %d\n", i, i * i, i * i * i);
	}
	return 0;
}