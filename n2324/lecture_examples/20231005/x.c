#include <stdio.h>
char c = 1 << 7;
unsigned char d = 1 << 7;

int main() {
	printf("%d\n", c >> 1);
	printf("%d\n", d >> 1);
	printf("%08hhb\n", c);
	printf("%08hhb\n", d);
	printf("%08hhb\n", c >> 1);
	printf("%08hhb\n", d >> 1);
}
