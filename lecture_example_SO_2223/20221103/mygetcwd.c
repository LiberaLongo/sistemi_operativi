#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	char *buf = getcwd(NULL, 0);
	printf("%s\n", buf);
}
