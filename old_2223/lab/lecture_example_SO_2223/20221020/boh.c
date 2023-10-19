#include <stdio.h>
#include <unistd.h>

int main() {
	if (fork()) 
		printf("A %d\n", getpid());
	else
		printf("B %d\n", getpid());
}
