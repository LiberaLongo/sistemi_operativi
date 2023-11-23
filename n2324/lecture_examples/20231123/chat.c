#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <poll.h>
#define BUFSIZE 1024

int main(int argc, char *argv[]) {
	int fdin = open(argv[1], O_RDONLY | O_NONBLOCK);
	int fdout = open(argv[2], O_WRONLY);
	char buf[BUFSIZE];

	struct pollfd pfd[2] = {
		{STDIN_FILENO, POLLIN, 0},
		{fdin, POLLIN, 0}};

	for (;;) {
		int prv = poll(pfd, 2, -1);
		if (prv < 0)
			return(1);
		if (pfd[0].revents & POLLIN) {
			ssize_t n = read(STDIN_FILENO, buf, BUFSIZE);
			if (n <= 0)
				return 0;
			write (fdout, buf, n);
		}
		if (pfd[1].revents & POLLIN) {
			ssize_t n = read(fdin, buf, BUFSIZE);
			if (n <= 0)
				return 0;
			write (STDOUT_FILENO, buf, n);
		}
	}
}
