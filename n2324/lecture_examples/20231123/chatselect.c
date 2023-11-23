#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/select.h>
#define BUFSIZE 1024

int main(int argc, char *argv[]) {
	int fdin = open(argv[1], O_RDONLY | O_NONBLOCK);
	int fdout = open(argv[2], O_WRONLY);
	char buf[BUFSIZE];

	for (;;) {
		fd_set rfds;
		FD_ZERO(&rfds);
		FD_SET(STDIN_FILENO, &rfds);
		FD_SET(fdin, &rfds);

		int srv = select(fdin+1, &rfds, NULL, NULL, NULL);
		if (FD_ISSET(STDIN_FILENO, &rfds)) {
			ssize_t n = read(STDIN_FILENO, buf, BUFSIZE);
			if (n <= 0)
				return 0;
			write (fdout, buf, n);
		}
		if (FD_ISSET(fdin, &rfds)) {
			ssize_t n = read(fdin, buf, BUFSIZE);
			if (n <= 0)
				return 0;
			write (STDOUT_FILENO, buf, n);
		}
	}
}
