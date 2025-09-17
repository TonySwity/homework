#include <stdio.h>
#include <stdint.h>

int main(void) {
    FILE *fi = fopen("input.txt", "rb");
    if (!fi) return 0;

    char s[256] = {0};
    size_t n = fread(s, 1, sizeof s - 1, fi);
    fclose(fi);
    s[n] = '\0';

    // Удалим хвостовые \r\n
    while (n && (s[n-1] == '\n' || s[n-1] == '\r')) {
		s[--n] = '\0';
	}

    char w1[101] = {0}, w2[101] = {0};
    uint8_t i1 = 0, i2 = 0;
    int seen_space = 0;

    char *ch = s;
    while (*ch != '\0') {
        if (*ch != ' ') {
            if (!seen_space) {
                if (i1 < 100) w1[i1++] = *ch;
            } else {
                if (i2 < 100) w2[i2++] = *ch;
            }
        } else {
            seen_space = 1;
        }
        ch++;
    }
    w1[i1] = '\0';
    w2[i2] = '\0';

    int f1[26] = {0}, f2[26] = {0};
    ch = w1;
    while (*ch) {
        if (*ch >= 'a' && *ch <= 'z') f1[*ch - 'a']++;
        ch++;
    }
    ch = w2;
    while (*ch) {
        if (*ch >= 'a' && *ch <= 'z') f2[*ch - 'a']++;
        ch++;
    }

    FILE *fo = fopen("output.txt", "wb");
    if (!fo) return 0;

    int first = 1;
    for (int i = 0; i < 26; ++i) {
        if (f1[i] == 1 && f2[i] == 1) {
            if (!first) {
				fputc(' ', fo);
			}
            fputc('a' + i, fo);
            first = 0;
        }
    }
    fputc('\n', fo);
    fclose(fo);
    return 0;
}
