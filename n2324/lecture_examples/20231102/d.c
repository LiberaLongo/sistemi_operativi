#include <stdio.h>
#include <dirent.h>

int main(int argc, char * argv[]) {
	DIR *f = opendir(argv[1]);
	struct dirent *d;
	while ((d = readdir(f)) != NULL) {
		printf("%s\n",d->d_name);
	}
	closedir(f);
}
