#include <stdio.h>

int main(int argc, char * argv[]) {
	int a = 22;
	int b = 33;
	char s[100];
	snprintf(s, 100, "i valori sono %1000d %d", a, b);
	printf("%s\n",s);
}
