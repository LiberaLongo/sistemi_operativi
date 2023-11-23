#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
	pid_t pid;
	switch (pid = fork()) {
		case 0:
			int fd = open("ciao", O_WRONLY | O_CREAT | O_TRUNC, 0666);
			dup2(fd, STDOUT_FILENO);
			close(fd);
			execlp("ls", "ls", 0);
			_exit(1);
		default:
			int status;
			wait(&status);
			printf("finito\n");
			break;
		case -1:
			perror("errfork");
	}
}
