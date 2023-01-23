#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char *argv[]) {
	int status;
	printf("%d\n", getpid());
	switch( fork() ) {
		case 0: //figlio
			execvp(argv[1], argv+1);
			perror("exec");
			return 0;
		default: //padre
			wait(&status);
			printf("done!\n");
			break;
		case -1:
			perror("fork");
			exit(-1);
	}
}

