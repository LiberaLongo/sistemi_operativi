#include <stdio.h>

#define NICE 42

#define MIN(X,Y) \
	((X) < (Y) ? (X) : (Y))

#define DEF(X,Y) \
	printf("sto definendo %s di tipo %s\n", #Y, #X); \
	X Y

int main(int argc, char *argv[]) {
	DEF(int, myi);
}
