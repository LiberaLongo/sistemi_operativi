#include <stdio.h>
#include <unistd.h>

int main() {
	pid_t fork_retvalue;
	if (fork_retvalue = fork())
		printf("genitore %d %d\n", getpid(), fork_retvalue);
	else
		printf("figlio %d %d\n", getpid(), getppid());
}
