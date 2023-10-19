#include <stdio.h>

struct A {
	char a1;
	long a2;
	char a3;
};
//}__attribute__((packed));

int main() {
	struct A sa;
	sa.a2 = 44;
}
