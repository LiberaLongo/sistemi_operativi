#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	printf("getpid %d\n",getpid());
	int fdout = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	sleep(20); fprintf(stderr, "1\n");
	dup2(fdout, STDOUT_FILENO);
	sleep(10); fprintf(stderr, "2\n");
	close(fdout);
	sleep(10); fprintf(stderr, "3\n");
	printf("hello world\n");
	sleep(10); fprintf(stderr, "4\n");
}
