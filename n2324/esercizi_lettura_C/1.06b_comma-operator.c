#include <stdio.h>

int slen(char *s) { /* in real programs use strlen instead */
  size_t rval;
  for (rval = 0; *s != 0; s++, rval++)
    ;
  return rval;
}

int ispal(char *s) {
  int i,j;
  for (i=0, j=slen(s)-1; i < j; i++, j--) {
    if (s[i] != s[j])
      return 0;
  }
  return 1;
}

void reverse(char *s) {
  int i,j;
  for (i=0, j=slen(s)-1; i < j; i++, j--)
    s[j] ^= s[i] ^= s[j] ^= s[i];
}

int main(int argc, char *argv[1]) {
  for ( ;argc > 1; argv++, argc--) {
    printf("\"%s\" is%s palindrome\n", argv[1],
        ispal(argv[1])?"":"n't");
    reverse(argv[1]);
    printf("\"%s\"\n", argv[1]);
  }
}

