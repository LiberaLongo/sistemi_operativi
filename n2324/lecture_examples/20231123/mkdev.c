#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>

int main(int argc, char *argv[]) {
	int rv = mknod(argv[1], S_IFCHR | 0666, makedev(136, 1));
	if (rv < 0)
		perror("mknod");
}
