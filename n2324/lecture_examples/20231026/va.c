#include <stdio.h>
#include <stdarg.h>


void pn (int nr, ...) {
	va_list va;
	va_start(va, nr);
	for (int i = 0; i < nr; i++)
		printf("%d\n", va_arg(va, int));
	va_end(va);
}

int main(int argc, char *argv[]) {
	pn(3, 1, 2, 3);
	pn(2, 21, 22);
	pn(0);
}
