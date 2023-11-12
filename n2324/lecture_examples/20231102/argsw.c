#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <libgen.h>

#define AUTOPTS \
  OPSOP(h, help, 0, "Display this help message") \
  OPSOP(f, file, 1, "Set the file") \
  OPSOP(v, verbose, 0, "Verbose mode") \
  OPSOP(t, text, 1, "Text field") \
  OPSOP(a, addr, 1, "Set the address")

#define _OPS0(...)
#define _OPS1(...) ":"
#define OPSOP(s, l, a, h) #s _OPS ## a(a)
char short_options[] = AUTOPTS;
#undef _OPS0
#undef _OPS1
#undef OPSOP

#define OPSOP(s, l, a, h) { #l, a, NULL, #s [0] },
struct option long_options[] = {
  AUTOPTS
};
#undef OPSOP

#define OPSOP(s, l, a, h) #s
char optchars[] = AUTOPTS;
#undef OPSOP

#define OPSOP(s, l, a, h) char *l ;
union {
  char *args[sizeof(optchars)];
  struct {
    AUTOPTS
  };
} opts;
#undef OPSOP

void usage(char *progname) {
#define _OPS0(...) "     "
#define _OPS1(...) "<arg>"
#define OPSOP(s, l, a, h) \
  printf(" -%s, --%-8s %s         %s\n", #s, #l, _OPS ## a(a), h);
  printf("%s [OPTIONS] file\nOptions:\n", progname);
  AUTOPTS
#undef _OPS0
#undef _OPS1
#undef OPSOP
    printf("\n");
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
  char *progname = basename(argv[0]);
  while (c != -1) {
    c = getopt_long(argc, argv, short_options, long_options, NULL);
    switch (c) {
      case -1:
        break;
      case '?':
        usage(progname);
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
  if (opts.help)
    usage(progname);
}
