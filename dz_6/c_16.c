#include <stdio.h>


int is_Prime(int n) {
	
	if (n > 1) {
			for (int i = 2; i < n; i++) {
					if (n % i == 0) {
							return 0;
					}
			}
			return 1;
	} else {
			return 0;
	}
}

int main(int argc, char** argv) {
	int num =0;
	scanf("%d", &num);

	printf("%s", is_Prime(num)? "YES" : "NO");
	return 0;
}