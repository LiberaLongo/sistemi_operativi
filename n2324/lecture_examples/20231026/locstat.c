#include <stdio.h>

int counter(void) {
	static int value = 0;
	return value++;
}


int main() {
	printf("%d\n", counter());
	printf("%d\n", counter());
	printf("%d\n", counter());
	printf("%d\n", counter());
}
