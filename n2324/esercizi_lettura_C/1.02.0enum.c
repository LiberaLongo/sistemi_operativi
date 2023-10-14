#include <stdio.h>

enum numbers { zero, uno, due, quarantadue = 42 };

int main() {
        enum numbers n;
        n = 44;
        printf("%d %d %d %d %d\n", zero, uno, due, quarantadue, n);
}

