#include <stdio.h>

char s[] = "ciao";

int main(int argc, char *argv[]) {
	//int v[10] = {1,2,3,4};
	int v[] = {[3 ... 9] = 33, [7] = 35, [12] = 12};

	for (int i = 0; i < sizeof(v)/sizeof(*v); i++)
		printf("%d ", v[i]);
	printf("\n");
}	
