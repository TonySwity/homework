#include <stdio.h>

static int put_uint_to_buf(unsigned v, char *buf) {
    char tmp[10];
    int n = 0;
    do {
        tmp[n++] = (char)('0' + (v % 10));
        v /= 10;
    } while (v);
    for (int i = n - 1; i >= 0; --i) *buf++ = tmp[i];
    return n;
}

int main(void) {
    char in[1000];
    int n = 0;

    for (;;) {
        int c = getchar();
        if (c == EOF || c == '.') break;
        if (c >= 'a' && c <= 'z') {
            if (n < (int)sizeof in) in[n++] = (char)c;
        }
    }

    if (n == 0) { puts(""); return 0; }

    char out[5000 + 1];
    int k = 0;

    char cur = in[0];
    unsigned run = 1;

    for (int i = 1; i < n; ++i) {
        if (in[i] == cur) {
            ++run;
        } else {
            out[k++] = cur;
            k += put_uint_to_buf(run, out + k);
            cur = in[i];
            run = 1;
        }
    }
    out[k++] = cur;
    k += put_uint_to_buf(run, out + k);

    out[k] = '\0';
    puts(out);
    return 0;
}
