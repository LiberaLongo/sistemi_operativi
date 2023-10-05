#include <stdio.h>
#include <stdint.h>
#include <dump.h>

int main(int argc, char *argv[]) {
	int i42 = 42;
	uint8_t bits = 0b10110001;
	char *s1 = "hello world";
	char s2[] = "hello world";
	hexdump(i42);
	bindump(i42);
	printf("\n");
	hexdump(bits);
	bindump(bits);
	printf("\n");
	hexdump(s1);
	bindump(s1);
	printf("\n");
	hexdump(s2);
	bindump(s2);
}
