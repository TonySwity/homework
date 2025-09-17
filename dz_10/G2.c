#include <stdio.h>

int main(void) {
    FILE *fi = fopen("input.txt", "rb");
    if (!fi) return 0;

    int N = 0;
    if (fscanf(fi, "%d", &N) != 1) { fclose(fi); return 0; }
    fclose(fi);

    if (N < 0 || N > 26 || (N % 2 != 0)) {
        FILE *fo = fopen("output.txt", "wb");
        if (fo) {
			fclose(fo);
		}
        return 0;
    }

    char out[26 + 1];
    const char evens[] = { '2', '4', '6', '8' };

    for (int i = 0; i < N; ++i) {
        if ((i % 2) == 0) {
            out[i] = 'A' + (i / 2);
        } else {
            out[i] = evens[(i / 2) % 4];
        }
    }
    out[N] = '\0';

    FILE *fo = fopen("output.txt", "wb");
    if (!fo) return 0;
    fputs(out, fo);
    fclose(fo);
    return 0;
}
