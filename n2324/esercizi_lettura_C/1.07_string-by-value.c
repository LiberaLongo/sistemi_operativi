#include <stdio.h>

int slen(char *s) { /* in real programs use strlen instead */
  int rval;
  for (rval = 0; *s != 0; s++, rval++)
    ;
  return rval;
}

void printxvowel(char v, char *s) {
  int s_len = slen(s);
  char locals[s_len + 1];
  int i;
  for (i=0; i<s_len; i++) {
    switch (s[i]) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
        locals[i] = v;
        break;
      default:
        locals[i] = s[i];
        break;
    }
  }
  printf("-> %s\n<- %s\n",s,locals);
}

int main(int argc, char *argv[]) {
  for ( ; argc > 1; argc--, argv++) {
    printxvowel('a',argv[1]);
    printxvowel('e',argv[1]);
    printxvowel('i',argv[1]);
    printxvowel('o',argv[1]);
    printxvowel('u',argv[1]);
  }
  return 0;
}

/*test it using "Garibaldi fu ferito, fu ferito ad una gamba, Garibaldi che comanda, che comanda il battaglion" as argv[1]. */

