#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int num = 0, pow_n = 0;
	scanf("%d %d", &num, &pow_n);
	double res = pow(num, pow_n);
	if(abs((int)res) <= 1000){
		printf("%d", (int)res);
	}
	return 0;
}