#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
	int fd = open(argv[1], O_RDWR);
	write(fd, "prova\n", 6);
	lseek(fd, 8192, SEEK_SET);
	write(fd, "fine\n", 5);
}
