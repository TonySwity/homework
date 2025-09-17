#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

enum { BUFF_CAP = 100, FIO_CAP = 3, FIO_LEN = 40};

int main(void) {
	FILE *in_file = fopen("input.txt", "rb");
	if(!in_file) {
		fprintf(stderr, "input.txt: %s\n", strerror(errno));
		return EXIT_FAILURE;
	}

	int cap = 0;
	char fio[FIO_CAP][FIO_LEN];
	while(cap < FIO_CAP && fscanf(in_file, "%39s", fio[cap])==1){
		cap++;
	}
	fclose(in_file);

	FILE *out_file = fopen("output.txt", "wb");
    if (!out_file) {
        fprintf(stderr, "output.txt: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

	fprintf(out_file, "Hello, %s %s!\n", fio[1], fio[0]);
	fclose(out_file);

	return EXIT_SUCCESS;
}
