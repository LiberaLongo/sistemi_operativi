#include <stdio.h>
struct poi {
	int x; int y; int v[10];
};

struct poi a = {0,0,0};
struct poi b ;
#include <string.h>
int main(int argc, char *argv[]) {
	b = a;
}
