#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	pid_t fork_retvalue;
	switch (fork_retvalue = fork()) {
		case 0:
			sleep(1);
			printf("figlio %d %d\n", getpid(), getppid());
			_exit(42);
			break;
		default:
			int status;
			printf("genitore %d %d\n", getpid(), fork_retvalue);
			waitpid(fork_retvalue, &status, 0);
			printf("fine wait %d\n", WEXITSTATUS(status));
			break;
		case -1:
			perror("fork");
	}
}
