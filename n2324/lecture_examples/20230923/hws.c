#include <unistd.h>

int main(int argc, char *argv[]) {
	write(1, "hello world\n", 12);
}
