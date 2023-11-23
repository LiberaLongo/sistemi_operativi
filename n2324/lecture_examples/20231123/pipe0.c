#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#define BUFSIZE 1024

int main(int argc, char *argv[]) {
	int fd[2];
	char buf[BUFSIZE];
	pipe(fd);

	switch (fork()) {
		case 0:
			close(fd[1]);
			dup2(fd[0], STDIN_FILENO);
			close(fd[0]);
			execlp("sort", "sort", "-r", 0);
			exit(1);
		default:
			break;
		case -1:
			perror("fork");
			exit(1);
	}

	switch (fork()) {
		case 0:
			close(fd[0]);
			dup2(fd[1], STDOUT_FILENO);
			close(fd[1]);
			execlp("ls", "ls", "/", 0);
			break;
		default:
			break;
		case -1:
			perror("fork");
			exit(1);
	}
	close(fd[0]);
	close(fd[1]);
	int status;
	wait(&status);
	wait(&status);
}
