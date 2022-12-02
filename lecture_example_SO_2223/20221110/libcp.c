#include <stdio.h>

int main(int argc, char *argv[]) {
	FILE *in = fopen(argv[1], "r");
	FILE *out = fopen(argv[2], "w");
	int c;
	while ((c = fgetc(in)) != EOF)
		fputc(c, out);
	fclose(in);
	fclose(out);
}
