#include <stdio.h>
#include <mysrc.h>

extern char * val;

void myfun(void) {
	printf("%s\n", val);
}
