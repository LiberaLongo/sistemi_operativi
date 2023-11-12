#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main() {
	char *newargv[] = {"ls", "/", NULL};
	execve("/usr/bin/ls", newargv, NULL);
	//execlp("lllls", "ls", "/", NULL);
	//printf("errore %s\n", strerror(errno));
	//perror("exevlp");
}
