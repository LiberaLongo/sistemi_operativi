#include <stdio.h>

union intch {
	int i;
	struct {
		char c0;
		char c1;
		char c2;
		char c3;
	};
};

int main(int argc, char *argv[]) {
	union intch ic;
	ic.i = 0x01020304;
	printf("%d %d %d %d\n", ic.c0, ic.c1, ic.c2, ic.c3);
}
