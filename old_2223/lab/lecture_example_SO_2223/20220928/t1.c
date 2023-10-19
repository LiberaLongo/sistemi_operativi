#include <stdio.h>
#include <pthread.h>

#define MAX 10
#define DELAY 10000

void *test (void * s) {
	for (int i = 0; i < MAX; i++) {
		printf("%s\n", s);
		for (int j = 0; j < DELAY; j++)
			;
	}
}

int main(int argc, char * argv[]) {
	pthread_t t1,t2;
	pthread_create(&t1, NULL, test, "uno");
	pthread_create(&t2, NULL, test, "due");
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
}
