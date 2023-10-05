#include <stdio.h>
#include <stdlib.h>

void clean1(void) {
	printf("io sono clean 1\n");
}
void clean2(void) {
	printf("io sono clean 2\n");
}
int main() {
	atexit(clean1);
	atexit(clean2);
	_exit(42);
	//return 42;
}	
