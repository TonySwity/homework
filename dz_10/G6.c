#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(void) {
	FILE *in = fopen("input.txt", "rb");
	if(!in) {
        fprintf(stderr, "input.txt: %s\n", strerror(errno));
        return EXIT_FAILURE;
	}

	char s[1001];
    size_t n = fread(s, sizeof(*s), sizeof (s), in);
    if (ferror(in)) {
        fprintf(stderr, "read error: %s\n", strerror(errno));
        fclose(in);
        return EXIT_FAILURE;
    }
    fclose(in);

    s[n] = '\0';

    while (n && (s[n-1] == '\n' || s[n-1] == '\r')) {
        s[--n] = '\0';
    }

	char *ans = "YES";

	for (size_t i = 0, j = n ? n-1 : 0; i < j; ++i, --j) {
        if(s[i] != s[j])
			{
				ans = "NO";
				break;
			}
    }
	FILE *out = fopen("output.txt", "wb");
	if(!out) {
        fprintf(stderr, "output.txt: %s\n", strerror(errno));
        return EXIT_FAILURE;
	}
	fwrite(ans, sizeof(*ans), strlen(ans), out);
	if (ferror(out)) {
        fprintf(stderr, "write error: %s\n", strerror(errno));
        fclose(out);
        return EXIT_FAILURE;
    }
	fclose(out);
	return EXIT_SUCCESS;
}
