#include <stdio.h>

typedef void (*voidfun) (void *arg);

void printint(void *arg) {
  int *iarg = arg;
  printf("int %d\n", *iarg);
}

void printstring(void *arg) {
  char *sarg = arg;
  printf("int %s\n", sarg);
}

void printpointer(void *arg) {
  printf("pointer %p\n", arg);
}

void printfun(void *arg) {
  voidfun fun = arg;
  fun((void *) 0x42);
}

void launch(voidfun f, void *opaque) {
  f(opaque);
}

int main(int argc, char *argv[1]) {
  int v = 235;
  char *s = "Lasciate ogni speranza, o voi ch'entrate";
  launch(printint, &v);
  launch(printstring, s);
  launch(printfun, printpointer);
  return 0;
}
/*This technique is used to implement callbacks with opaque args. */

