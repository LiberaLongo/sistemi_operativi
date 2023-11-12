#include <stdio.h>
#include <mysrc.h>

char * val;

int main(int argc, char *argv[]) {
	val = argv[1];
	myfun();
}
