#include <stdio.h>

struct A {
	char a1;
	short a2;
	char a3;
};

struct B {
	char b1;
	char b2;
	short b3;
};

int main() {
	printf("%d %d\n", sizeof(struct A), sizeof(struct B));
}
