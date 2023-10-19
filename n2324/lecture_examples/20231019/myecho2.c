#include <stdio.h>
int main(int argc, char *argv[]) {
	for (argv++; *argv; argv++)
		printf("%s ", argv[0]);
	printf("\n");
}
