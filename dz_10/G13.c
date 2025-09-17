#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

enum { BUF_CAP = 1000 };

int main(void) {
    FILE *in = fopen("input.txt", "rb");
    if (!in) {
        fprintf(stderr, "input.txt: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    char s[BUF_CAP + 1];
    size_t n = fread(s, 1, BUF_CAP, in);
    if (ferror(in)) {
        fprintf(stderr, "input: read error\n");
        fclose(in);
        return EXIT_FAILURE;
    }
    fclose(in);
    s[n] = '\0';

    while (n && (s[n-1] == '\n' || s[n-1] == '\r')) {
		s[--n] = '\0';
	}

    size_t last_slash = (size_t)-1;
    for (size_t i = 0; i < n; ++i) {
        if (s[i] == '/') {
			last_slash = i;
		}
    }

    size_t start = (last_slash == (size_t)-1) ? 0 : last_slash + 1;

    ssize_t dot_pos = -1;
    for (size_t i = start; i < n; ++i) {
        if (s[i] == '.') {
			dot_pos = (ssize_t)i;
		}
    }

    size_t keep_len = (dot_pos > (ssize_t)start) ? (size_t)dot_pos : n;

    FILE *out = fopen("output.txt", "wb");
    if (!out) {
        fprintf(stderr, "output.txt: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    if (keep_len > 0){
		fwrite(s, 1, keep_len, out);
	}
    fwrite(".html", 1, 5, out);

    fclose(out);
    return 0;
}
