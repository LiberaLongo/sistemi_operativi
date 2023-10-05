#include <stdio.h>
#include <stdarg.h>

	void
foo(char *fmt, ...)   /* '...' is C syntax for a variadic function */
{
	va_list ap;
	va_start(ap, fmt);
	printf("mia stampa\n");
	vprintf(fmt, ap);
	va_end(ap);
}

int main() {
	foo("%s\n", "hello world");
	foo("%d %d\n", 42, 21);
}

