#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    char str[100] = {0};
    fgets(str, sizeof(str)-1, stdin);
    char* ptr_n = strrchr(str, '\n');
    if(ptr_n != NULL)
		{
			*ptr_n = '\0';
		}
		ptr_n = strrchr(str, '.');
		if(ptr_n != NULL)
		{
			char *temp_c  = str;
			while (*temp_c != '.' && *temp_c != '\0') {
					if (*temp_c >= 'A' && *temp_c <= 'Z') {
							*temp_c = tolower(*temp_c); 
					}
					putchar(*temp_c);
					temp_c++;
			}
		} else {

			printf("%s", str);
		}
      
    return 0;
}