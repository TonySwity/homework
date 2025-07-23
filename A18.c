#include <stdio.h>

int main(void)
{
    int a, b;
	scanf("%d %d", &a, &b);
		
    if(a > b) {
        printf("Above");
    } else if(b > a) {
        printf("Less");
    } else {
        printf("Equal");
    }
    return 0;
}
