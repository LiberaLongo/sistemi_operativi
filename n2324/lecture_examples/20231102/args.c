#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <libgen.h>

void usage_and_exit(char *progname) {
	fprintf(stderr,
			"Usage:\n"
			"  %s OPTIONS [value] ... [value]\n"
			"Options:\n"
			"  -v | --verbose:      verbose mode\n"
			"  -h | --help:         print a short usage helping message\n"
			"  -a val | --add val   add a value\n"
			"  -s val | --sub val   subtract a value\n"
			"  --double             double the final result\n"
			"This program computes an integer value\n", progname);
	exit(1);
}

int main(int argc, char *argv[]) {
	static struct option long_options[] = {
		{"verbose", no_argument, 0, 'v'},
		{"help",    no_argument, 0, 'h'},
		{"add",     required_argument, 0, 'a'},
		{"sub",     required_argument, 0, 's'},
		{"double",  no_argument, 0, 0x101},
		{0,         0,           0, 0}
	};
	static char *short_options = "vha:s:";

	int opt;

	int value = 0;
	int verbose = 0;
	int doubleval = 1;

	char *progname = basename(argv[0]);

	while((opt = getopt_long(argc, argv, short_options, long_options, NULL)) > 0) {
		switch (opt) {
			case 'v': verbose = 1;
								break;
			case 'a': value += atoi(optarg);
								break;
			case 's': value -= atoi(optarg);
								break;
			case 0x101: doubleval *= 2;
									break;
			case 'h':
			case '?': usage_and_exit(progname);
								break;
		}
	}

	for (; optind < argc; optind++)
		value += atoi(argv[optind]);

	value *= doubleval;

	if (verbose)
		printf("the result is %d\n", value);

	return value;
}
