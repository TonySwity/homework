#include <stdio.h>

int main()
{
		int s = getchar();
    while (s != '.'){
			if (s >= 'a' && s <= 'z') {
      	s -= 'a' - 'A';
			}
			putchar(s);
			s = getchar();
    }

    
    return 0;
}