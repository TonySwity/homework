#include <stdio.h>

#define MAX_COUNT 100
int main(void) {
	int a, count = 0;
	scanf("%d", &a);
	char *answer = "NO";
	int arr_num[MAX_COUNT];
	while(a>0) {
		arr_num[count] = a%10;
		a/=10;
		count++;
	}

	for(int i = 0; i < count-1; i++) {
		for(int j = i+1; j < count; j++) {
			if(*(arr_num+i) == *(arr_num+j)) {
				answer = "YES";
				goto end;
			}
		}
	}
end:
	printf("%s", answer);

	return 0;
}