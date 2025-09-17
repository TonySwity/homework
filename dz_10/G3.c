#include <stdio.h>

int main(void) {
    FILE *fi = fopen("input.txt", "rb");
    if (!fi) return 0;

    char s[1000 + 1];
    size_t n = fread(s, 1, sizeof s - 1, fi);
    fclose(fi);
    s[n] = '\0';

    while (n > 0 && (s[n - 1] == '\n' || s[n - 1] == '\r')) {
        s[--n] = '\0';
    }

    FILE *fo = fopen("output.txt", "wb");
    if (!fo) return 0;

    if (n > 0) {
        char last = s[n - 1];
        int first = 1;
        for (size_t i = 0; i + 1 < n; ++i) {
            if (s[i] == last) {
                if (!first) {
					fputc(' ', fo);
				}
                fprintf(fo, "%zu", i);
                first = 0;
            }
        }
        if (!first) {
			fputc('\n', fo);
		}
    }

    fclose(fo);
    return 0;
}
