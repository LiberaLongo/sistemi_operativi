#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	struct stat st;
	int rv = stat(argv[1], &st);
	if (rv < 0) {
		perror ("stat");
		exit(1);
	}
}
