#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int fdin = open(argv[1], O_RDONLY);
	int fdout = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	int buflen = strtol(argv[3], NULL, 0);
	char buf[buflen];
	int len;
	while ((len = read(fdin, buf, buflen)) > 0)
		write(fdout, buf, len);
	close(fdin);
	close(fdout);
}
