#include <stdio.h>
#include <string.h>

#define MAX_LEN 100000

int main(void) {
    static char s[MAX_LEN + 2];
    int freq[10] = {0};

    if (!fgets(s, sizeof(s), stdin)) {
        return 1;
    }

    s[strcspn(s, "\n")] = '\0';

    for (char *p = s; *p; p++) {
        if (*p >= '0' && *p <= '9') {
            freq[*p - '0']++;
        } else {
            fprintf(stderr, "Ошибка: недопустимый символ '%c'\n", *p);
            return 1;
        }
    }

    for (int d = 0; d < 10; d++) {
        if (freq[d] > 0) {
            printf("%d %d\n", d, freq[d]);
        }
    }

    return 0;
}
