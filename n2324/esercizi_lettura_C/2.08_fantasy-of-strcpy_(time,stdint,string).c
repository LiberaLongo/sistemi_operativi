/* Cit Cirano pag 25 (http://copioni.corrierespettacolo.it/wp-content/uploads/2016/12/ROSTAND%20Edmond__Cirano%20di%20Bergerac__null__U(29)-D(13)__Commedia__5a.pdf)
Cit. orig. Cyrano page 67. (http://www.crdp-strasbourg.fr/je_lis_libre/livres/Rostand_CyranoDeBergerac.pdf) */
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

char *strcpy0(char *dest, const char *src) {
  int i;
  int len;
  for (len = 0; src[len] != 0; len++)
    ;
  for (i = 0; i <= len; i++)
    dest[i] = src[i];
  return dest;
}
 
char *strcpy1(char *dest, const char *src) {
  int i;
  for (i = 0; src[i] != 0; i++)
    ;
  for ( ; i >= 0; i--)
    dest[i] = src[i];
  return dest;
}
 
char *strcpy2(char *dest, const char *src) {
  char *rval = dest;
  while ((*dest++ = *src++) != 0)
    ;
  return rval;
}

char *strcpy3(char *dest, const char *src) {
  int i;
  for (i=0; (dest[i] = src[i]) != 0; i++)
    ;
  return dest;
}

char *strcpy4(char *dest, const char *src) {
  if ((*dest = *src) != 0)
    strcpy4(dest+1, src+1);
  return dest;
}


char *strcpy5(char *dest, const char *src) {
  char *rval = dest;
  while (*src != 0)
    *dest++ = *src++;
  *dest = 0;
  return rval;
}

char *strcpy6(char *dest, const char *src) {
  uint64_t *src64 = (uint64_t *) src;
  uint64_t *dest64 = (uint64_t *) dest;
  while (1) {
    register uint64_t tmp = *src64;
    register uint64_t scan;
    for (scan = 0xffULL; (tmp & scan) != 0; scan <<= 8)
      ;
      //printf("%llx %llx %p %p %s\n",scan, tmp, src64, dest64, (char *) src64);
    if (scan != 0) {
      strcpy2((char *) dest64, (char *) src64);
      break;
    }
    *dest64++ = tmp;
    src64++;
  }
  return dest;
}
 
#define NUMBER_OF_TEST 1000000
 
double time_strcpy(char * (*cpy)(char *, const char *), char *d, const char *s)
{
    clock_t starttime, time;
    int i;
    starttime = clock();
    for (i = 0; i< NUMBER_OF_TEST; i++)
    cpy(d, s);
    time = clock() - starttime;
    return (1.0) * time / CLOCKS_PER_SEC;
}

#define TESTSTRCPY(N,D,S) \
  printf("strcpy" #N " %s time %lf\n", strcpy ##N ((D),(S)), time_strcpy(strcpy ##N, (D),(S))) 
 
int main(int argc, char *argv[]) {
  if (argc != 2)
    return 1;
  else {
    size_t argv1len=strlen(argv[1]);
    char argcpy[argv1len+1];
    strncpy(argcpy, argv[1], argv1len);
    printf("strncpy %s\n", argcpy);
    TESTSTRCPY(, argcpy, argv[1]);
    TESTSTRCPY(0, argcpy, argv[1]);
    TESTSTRCPY(1, argcpy, argv[1]);
    TESTSTRCPY(2, argcpy, argv[1]);
    TESTSTRCPY(3, argcpy, argv[1]);
    TESTSTRCPY(4, argcpy, argv[1]);
    TESTSTRCPY(5, argcpy, argv[1]);
    TESTSTRCPY(6, argcpy, argv[1]);
  }
}
/*This program compares several homemade implementations of string copy functions with the library one. */

