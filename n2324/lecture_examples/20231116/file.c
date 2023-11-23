#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
	int fd = open(argv[1], O_RDONLY);
	char buf[10];

	printf("fd=%d\n", fd);

	ssize_t n = read(fd, buf, 10);

	write(1, buf, n);
	write(1, "\n", 1);
}
