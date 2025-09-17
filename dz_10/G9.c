#include <ctype.h>
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { BUF_CAP = 1000 };

int main(void) {
    FILE *in = fopen("input.txt", "rb");
    if (!in) {
        fprintf(stderr, "input.txt: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    char buf[BUF_CAP + 1];
    size_t n = fread(buf, 1, BUF_CAP, in);
    if (ferror(in)) {
        fprintf(stderr, "input: read error\n");
        fclose(in);
        return EXIT_FAILURE;
    }
    fclose(in);
    buf[n] = '\0';

    while (n && (buf[n-1] == '\n' || buf[n-1] == '\r')) {
        buf[--n] = '\0';
    }

    bool seen[256] = {0};
    char out[BUF_CAP + 1];
    size_t m = 0;

    const unsigned char *p = (const unsigned char*)buf;
    while (*p) {
        unsigned char c = *p++;
        if (isalpha(c)) {
            if (!seen[c]) {
                seen[c] = true;
                out[m++] = (char)c;
                if (m == BUF_CAP) break;
            }
        }
    }
    out[m] = '\0';

    FILE *outf = fopen("output.txt", "wb");
    if (!outf) {
        fprintf(stderr, "output.txt: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }
    fputs(out, outf);
    fputc('\n', outf);
    if (fclose(outf) == EOF) {
        fprintf(stderr, "output: close error\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
