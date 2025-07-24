#include <stdio.h>


int main() {
	int num = 0;
    scanf("%d", &num);

    int a = num / 100;
    int b = (num - a*100) /10;
    int c = num - (a*100+b*10);
    
    printf("%d", a*b*c);

    return 0;
}

