#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
	char *buf = NULL;
	size_t len = 0;
	for (;;) {
		getline(&buf, &len, stdin);
		size_t cmdlen = strlen(buf) - 1;
		buf[cmdlen]=0;
		char *myargv[] = {buf, 0};
		int status;
		switch (fork()) {
			case 0:
				execve(buf, myargv, NULL);
				exit(0);
			default:
				wait(&status);
			case -1:
				exit(1);
		}
	}
}
