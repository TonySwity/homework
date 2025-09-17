#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

enum { BUF_CAP = 10000 };

int main(void) {
    FILE *in = fopen("input.txt", "rb");
    if (!in) {
        fprintf(stderr, "input.txt: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    char str[BUF_CAP + 1];
    size_t len = fread(str, 1, BUF_CAP, in);
    if (ferror(in)) {
        fprintf(stderr, "input: read error\n");
        fclose(in);
        return EXIT_FAILURE;
    }
    fclose(in);
    str[len] = '\0';

    while (len && (str[len-1] == '\n' || str[len-1] == '\r')) {
        str[--len] = '\0';
    }

   int lit_let = 0, big_let = 0;
    for (size_t i = 0; i < len; ++i) {
        if (str[i] >= 'a' && str[i] <= 'z') {
			lit_let++;
		} else if (str[i] >= 'A' && str[i] <= 'Z') {
			big_let++;
		}
    }

    FILE *out = fopen("output.txt", "wb");
    if (!out) {
        fprintf(stderr, "output.txt: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

	fprintf(out, "%d %d\n", lit_let, big_let);


    if (fclose(out) == EOF) {
        fprintf(stderr, "output: close error\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
