#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	int fd1 = open("provaopen", O_CREAT | O_WRONLY | O_TRUNC, 0777);
	close(fd1);
	mkdir("provamkdir", 0777);
}
