#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>

int main(int argc, char *argv[]) {
	syscall(__NR_write, 1, "hello world\n", 12);
}
