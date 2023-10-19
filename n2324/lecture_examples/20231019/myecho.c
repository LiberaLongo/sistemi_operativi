#include <stdio.h>
int main(int argc, char *argv[]) {
	for (argc--, argv++; argc > 0; argc--, argv++)
		printf("%s ", argv[0]);
	printf("\n");
}
