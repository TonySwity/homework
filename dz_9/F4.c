#include <stdio.h>
#include <string.h>

#define MAX_LEN 100000

void print_digit(char s[]) {
	int freq[10] = {0};
	for (char *p = s; *p; p++) {
        if (*p >= '0' && *p <= '9') {
            freq[*p - '0']++;
        }
    }
	for (int d = 0; d < 10; d++) {
        if (freq[d] > 0) {
            printf("%d %d\n", d, freq[d]);
        }
    }
}

int main(void) {
    static char s[MAX_LEN + 2];

    if (!fgets(s, sizeof(s), stdin)) {
        return 1;
    }

    s[strcspn(s, "\n")] = '\0';

    print_digit(s);

    return 0;
}
