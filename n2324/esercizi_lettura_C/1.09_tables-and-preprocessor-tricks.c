#include <stdio.h>

#define rows_of(X) (sizeof(X) / sizeof((X)[0]))

#define printTable(X) do { \
    int i; \
    printf("TABLE " #X ": size of element %d\n" \
        "(printed by the line %d of source file %s)\n",  \
        sizeof(*(table ## X)), __LINE__, __FILE__); \
    for (i = 0; i < rows_of(table ## X); i++)  \
      printf(#X " %02d %s\n",i,table ## X [i]); \
    } while (0)

char tableA[][50] = {"Sempre caro mi fu quest'ermo colle,",
  "e questa siepe, che da tanta parte",
  "dell’ultimo orizzonte il guardo esclude."};
char *tableB[] = {"Sempre caro mi fu quest'ermo colle,",
  "e questa siepe, che da tanta parte",
  "dell’ultimo orizzonte il guardo esclude."};

int main(int argc, char *argv[1]) {
  int i;
  printTable(A);
  printf("\n");
  printTable(B);
}

