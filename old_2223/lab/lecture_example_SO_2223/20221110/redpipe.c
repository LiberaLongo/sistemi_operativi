#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
int main(int argc, char *argv[]) {
	int fd[2];
	int status;
	pipe(fd);
	if (fork() == 0) {
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		execlp("ls", "ls", NULL);
		exit(0);
	}
	if (fork() == 0) {
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
		execlp("sort", "sort", "-r", NULL);
		exit(0);
	}
	close(fd[0]);
	close(fd[1]);
	wait(&status);
	wait(&status);
}
