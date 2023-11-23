#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#define BUFSIZE 1024

void print(int fd) {
	char buf[BUFSIZE];
	ssize_t n;
	while ((n = read(fd, buf, BUFSIZE)) > 0)
		write (STDOUT_FILENO, buf, n);
	close(fd);
}

int main(int argc, char *argv[]) {
	int etcfd = open("/etc", O_PATH);
	int homefd = open("/home", O_PATH);
	int fd = openat(etcfd, "hostname", O_RDONLY);
	if (fd < 0) {
		perror("open1");
		exit(1);
	}
	print(fd);
	fd = openat(homefd, "../etc/hostname", O_RDONLY);
	if (fd < 0) {
		perror("open2");
		exit(1);
	}
	print(fd);
	fd = openat(AT_FDCWD,  "../etc/hostname", O_RDONLY);
  if (fd < 0) {
    perror("open3");
    exit(1);
  }
	print(fd);
}
