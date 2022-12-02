#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/syscall.h>

int main(int argc, char *argv[]) {
	char buf[4096];
	int rv = syscall(__NR_getcwd, buf, sizeof(buf));
	printf("%d %d\n", rv, errno);
	printf("%s\n", buf);
}
