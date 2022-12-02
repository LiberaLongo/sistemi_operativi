#include <stdio.h>
#include <pthread.h>

#define MAX 100000

int count = 0;

void *test (void * s) {
	for (int i = 0; i < MAX; i++) 
		count += 1;
}

int main(int argc, char * argv[]) {
	pthread_t t1,t2;
	pthread_create(&t1, NULL, test, "uno");
	pthread_create(&t2, NULL, test, "due");
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	printf("%d\n", count);
}
