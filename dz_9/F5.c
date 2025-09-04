#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int find_max_array(int size, int a[]) {
	int temp_max = INT_MIN;
	for (int i = 0; i < size; ++i) {
		if(temp_max < *(a + i)) {
			temp_max = *(a + i);
		}
	}
	return temp_max;
}

int main(void) {
	size_t count_num = 0, cap = 0;
    int *a = NULL;
    int temp_num;

    while (scanf("%d", &temp_num) == 1) {
        if (count_num == cap) {
            size_t new_cap = cap ? cap * 2 : 8;
            int *tmp = realloc(a, new_cap * sizeof *a);
            if (!tmp) {
                perror("realloc");
                free(a);
                return 1;
            }
            a = tmp;
            cap = new_cap;
        }
        a[count_num++] = temp_num;
    }

	printf("%d", find_max_array(count_num, a));

	return 0;
}
