#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFSIZE 65536

int main(int argc, char *argv[]){
	mode_t u = umask(007);
	int fdin = open(argv[1], O_RDONLY);
	int fdout = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	umask(u);
	char buf[BUFSIZE];
	ssize_t n;
	while ((n = read(fdin, buf, BUFSIZE)) > 0)
		write(fdout, buf, n);

	close(fdin);
	close(fdout);
}
