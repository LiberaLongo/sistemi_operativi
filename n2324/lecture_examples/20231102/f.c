#include <stdio.h>

int main(int argc, char * argv[]) {
	FILE *f = fopen(argv[1], "r");
	int a,b;
	char s[100];
	int rv;
	while ((rv = fscanf(f, "%s %d %d\n", s, &a, &b)) == 3)
		printf("%-10.10s %5d %05d\n", s, a, b);
	fclose(f);
}
