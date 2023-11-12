#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	pid_t fork_retvalue;
	if (fork_retvalue = fork()) {
		int status;
		printf("genitore %d %d\n", getpid(), fork_retvalue);
		wait(&status);
		printf("fine wait %d\n", WEXITSTATUS(status));
	} else {
		sleep(1);
		printf("figlio %d %d\n", getpid(), getppid());
		_exit(42);
	}
}
