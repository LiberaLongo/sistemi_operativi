#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[]){
	char* newargv[] = {"ls", "-l", NULL};
	printf("%d\n", getpid());
	execve("/usr/bin/ls", newargv, NULL);
	return 0;
}
