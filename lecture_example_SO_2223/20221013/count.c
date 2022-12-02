#include <stdio.h>

int count(void) {
	static int count = 0;
	return count++;
}

int main() {
	printf("%d\n", count());
	printf("%d\n", count());
	printf("%d\n", count());
	printf("%d\n", count());
}
