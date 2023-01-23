#include <stdio.h>
#include <unistd.h>

int main (int argc, char * argv[]){
	pid_t pid;
	printf("%d before\n", getpid());
	if (pid = fork()) {
		printf(" parent proc is %d, pid = %d\n", getpid(), pid);
	} else {
		printf(" child proc is %d, pid = %d\n", getpid(), pid);
	}
	printf("%d after\n", getpid());
	if (pid = fork()) {
		printf(" parent proc is %d, pid = %d\n", getpid(), pid);
	} else {
		printf(" child proc is %d, pid = %d\n", getpid(), pid);
	}
}
