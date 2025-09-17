#include <stdio.h>
#include <string.h>

int main(void) {
    FILE *fi = fopen("input.txt", "rb");
    if (!fi) return 0;

    char buf[1024];
    size_t n = fread(buf, 1, sizeof buf - 1, fi);
    fclose(fi);
    buf[n] = '\0';

    while (n > 0 && (buf[n-1] == '\n' || buf[n-1] == '\r')) {
        buf[--n] = '\0';
    }

    size_t len = n;

    FILE *fo = fopen("output.txt", "wb");
    if (!fo) return 0;

    fprintf(fo, "%s, %s, %s %zu", buf, buf, buf, len);
    fclose(fo);
    return 0;
}
