#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
int main(int argc, char *argv[]) {
	int fdout;
	int status;
	switch (fork()) {
		case 0:
			fdout = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
			dup2(fdout, STDOUT_FILENO);
			close(fdout);
			execlp("echo", "echo", "ciao", NULL);
			exit(0);
		default:
			wait(&status);
			break;
		case -1:
			exit(1);
	}
	sleep(10);
}
