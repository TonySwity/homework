#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[1000];
    fgets(input, sizeof(input), stdin);

    int found = 0;
    long max = 0;

    char *token = strtok(input, " \t\n");

    while (token != NULL) {
        int valid = 1;
        char *ptr = token;
        
        if (*ptr == '+' || *ptr == '-') ptr++;
        
        while (*ptr) {
            if (!isdigit((unsigned char)*ptr)) {
                valid = 0;
                break;
            }
            ptr++;
        }

        if (valid && ptr != token) {
            long num = strtol(token, NULL, 10);
            
            if (!found) {
                max = num;
                found = 1;
            } else if (num > max) {
                max = num;
            }
        }
        
        token = strtok(NULL, " \t\n");
    }

    if (!found) {
        printf("Числа не найдены\n");
    } else {
        printf("%ld\n", max);
    }

    return 0;
}
