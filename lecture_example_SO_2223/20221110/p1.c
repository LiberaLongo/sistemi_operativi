#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int fd[2];
	char buf[5];
	pipe(fd);
	write(fd[1], "ciao", 5);
	read(fd[0], buf, 5);
	printf("%s\n", buf);
}

