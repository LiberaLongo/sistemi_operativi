#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
	int i, m;
	i = atoi(argv[1]);
	m = atoi(argv[2]);

	printf("%d / %d = %d\n", i, m, i/m);
	printf("%d %% %d = %d\n", i, m, i%m);
}
