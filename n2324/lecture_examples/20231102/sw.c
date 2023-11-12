#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BUFLEN 4096

char *loadfile(char *path) {
	char *contents = NULL;
	size_t contents_len = 0;
	char buffer[BUFLEN];
	size_t len;
	FILE *fin = fopen(path, "r");
	FILE *fout = open_memstream(&contents, &contents_len);
	if (fin == NULL || fout == NULL)
		exit(1);
	while ((len = fread(buffer, sizeof(char), BUFLEN, fin)) > 0)
		fwrite(buffer, sizeof(char), len, fout);
	fclose(fin);
	fclose(fout);
	return(contents);
}

enum state {SPACE, CHAR};

int splitwords(char *s, char **words) {
	enum state state = SPACE;
	int count = 0;
	for (; *s != 0; s++) {
		if (isalnum(*s)) {
			if (state == SPACE && words != NULL)
				*words++ = s;
			state = CHAR;
		} else {
			if (state != SPACE)
				count++;
			if (words != NULL)
				*s = 0;
			state = SPACE;
		}
	};
	if (state != SPACE)
		count++;
	return count;
}

static int sortcmp(const void *p1, const void *p2) {
	const char *s1 = *(char * const *) p1;
	const char *s2 = *(char * const *) p2;
	int rval = strlen(s1) - strlen(s2);
	if (rval == 0)
		rval = strcmp(s1, s2);
	return rval;
}

int main(int argc, char *argv[1]) {
	if (argc == 2) {
		char *contents = loadfile(argv[1]);
		int count = splitwords(contents, NULL);
		char **words = malloc(count * sizeof(char *));
		if (words == NULL)
			return 1;
		else {
			int i;
			splitwords(contents, words);
			qsort(words, count, sizeof(char *), sortcmp);
			for (i = 0; i < count; i++)
				printf("%s\n", words[i]);
			return 0;
		}
	} else
		return 1;
}

