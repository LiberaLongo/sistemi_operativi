#include <stdio.h>
#include <unistd.h>
#include <math.h>
 
#define DELAY 10000
#define DURATION 30
 
int main(int argc, char *argv[]) {
  double x;
  int i;
  for (i = 0; i < DURATION * 1000000 / DELAY; i++) {
    double y = sin(M_PI * i / 100);
    int pos = 40 + (40 * y);
    printf("\r%*s\b",pos,"*");
    fflush(stdout);
    usleep(DELAY);
    printf("\n");
  }
}
