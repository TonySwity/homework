#include <stdio.h>


int main() {
	int num = 0;
    scanf("%d", &num);

    int a = num / 100;
    int b = (num - a*100) /10;
    int c = num - (a*100+b*10);
    
    if(a > b && a > c) {
        printf("%d", a);
    } else if(b > a && b > c) {
        printf("%d", b);
    } else {
        printf("%d", c);
    }

    return 0;
}
