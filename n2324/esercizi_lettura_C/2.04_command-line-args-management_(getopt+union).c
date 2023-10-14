#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

char short_options[] = "hf:vt:a:";
struct option long_options[] = {
  {"help", no_argument, NULL, 'h'},
  {"file", required_argument, NULL, 'f'},
  {"verbose", no_argument, NULL, 'v'},
  {"test", required_argument, NULL, 't'},
  {"addr", required_argument, NULL, 'a'},
};

char optchars[] = "hfvta";
union {
  char *args[sizeof(optchars)];
  struct {
    char *help;
    char *file;
    char *verbose;
    char *text;
    char *addr;
  };
} opts;

void usage(void) {
  exit(1);
}

#ifndef _GNU_SOURCE
const char *strchrnul(const char *s, int c) {
  while (*s != 0 && *s != c)
    s++;
  return s;
}
#endif

void setarg(int c, char *optarg) {
  int index = strchrnul(optchars, c) - optchars;
  opts.args[index] = optarg ? optarg : "";
}

int main(int argc, char *argv[]) {
  int c = 0;
  while (c != -1) {
    c = getopt_long(argc, argv, short_options, long_options, NULL);
    switch (c) {
      case -1:
        break;
      case '?':
        usage();
      default:
        setarg(c, optarg);
        break;
    }
  }

  printf("%s \n", opts.help);
  printf("%s \n", opts.file);
  printf("%s \n", opts.verbose);
  printf("%s \n", opts.text);
  printf("%s \n", opts.addr);
}

