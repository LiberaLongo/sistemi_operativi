#include <stdio.h>
#include <string.h>

const char *sep=" \t\n";

void tokenize(const char *s) {
  const char *t;
  for ( ; *s != 0; s = t) {
    for ( ; strchr(sep, *s) ; s++)
      ;
    if (*s == 0)
      break;
    for (t = s; ! strchr(sep, *t); t++)
      ;
    size_t len = t - s;
    char token[len + 1];
    sprintf(token, "%.*s", len, s);
    printf("TOKEN='%s'\n", token);
  }
}

int main(int argc, char *argv[]) {
  for ( ; argc > 1 ; argc--, argv++) {
    tokenize(argv[1]);
  }
}

