#include <stdio.h>

#define NICE 42

#define MIN(X,Y) \
	((X) < (Y) ? (X) : (Y))


int main(int argc, char *argv[]) {
	int i = 2;
	int j = 20;

	printf("%d\n", MIN(i++, j));
	printf("%d\n", MIN(i++, j));
}
