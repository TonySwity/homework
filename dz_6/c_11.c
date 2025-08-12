#include <stdio.h>

int nod(int a, int b) {
	if(a == b) {
		return a;
	}

	if(a > b) {
		return nod(a-b, b);
	} else {
		return nod(a, b-a);
	}
}

int main(int argc, char** argv) {
	int a, b;
	scanf("%d %d", &a, &b);

	printf("%d", nod(a,b));

	return 0;
}