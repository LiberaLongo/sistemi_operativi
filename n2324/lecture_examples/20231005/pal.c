#include <stdio.h>
#include <string.h>

int f(int x) {
	//(void) x;
	return 0;
}

int pal(char *s){
	int i,j;
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
		if (s[i] != s[j])
			return 0;
	return 1;
}

int main(int argc, char *argv[]) {
	//(void) argc;
	printf("%s %se' palindroma\n", argv[1], pal(argv[1]) ? "" : "non ");
}
