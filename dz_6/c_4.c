#include <stdio.h>

int main (void) {
	int num, res = 0, temp = 0;

	while (scanf("%d", &num) == 1 && num != 0) {
		if(num>=-2 && num<2) {
			res = num * num;
		} else if( num >= 2){
			res = num*num + (4* num) + 5;
		} else {
			res = 4;
		}

		if(temp < res) {
			temp = res;
		}
	}

	printf("%d", temp);
	return 0;
}