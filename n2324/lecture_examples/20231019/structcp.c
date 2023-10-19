#include <stdio.h>
int main(int argc, char *argv[]) {
	struct point {
		int x;
		int y;
	};

	//struct point p0 = {3,4};
	struct point p0 = {.y = 4};
	struct point p1;

	p1 = p0;

	printf("%d %d\n", p1.x, p1.y);
}
