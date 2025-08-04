#include <stdio.h>
#include <stdlib.h>

#define MAX_COUNT 100

int main(void) {
	int num, count =0;
	int arr_num[MAX_COUNT]; 

	scanf("%d", &num);
	while(num>0) {
		arr_num[count] = num%10;	
		num/=10;
		count++;
	} 

	if(count == 0){
		printf("%d\n", 0);
	} else {

		char *result = malloc(count+1);
		
		if (!result) {
			perror("Ошибка malloc");
		}

		int pos = 0;

		for (int i = 0; i < count; i++) {
			pos += sprintf(result + pos, "%d", arr_num[i]);
		}
		result[++count] ='\0';
		puts(result);
		free(result);
	}
	
	return 0;
}