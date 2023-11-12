#include <stdio.h>

int main(int argc, char * argv[]) {
	FILE *f = fopen(argv[1], "r");
	int a,b;
	char s[100];
	int rv;
	int len = 6;
	while ((rv = fscanf(f, "%s %d %d\n", s, &a, &b)) == 3)
		printf("%-10.10s %*d %05d\n", s, len++, a, b);
	fclose(f);
}
