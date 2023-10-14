#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct word {
  struct word *next;
  int count;
  char word[0];
};

static int lenalphacmp(const char *s1, const char *s2) {
  int rval = strlen(s1) - strlen(s2);
  if (rval == 0)
    rval = strcmp(s1, s2);
  return rval;
}

struct word *addword(char *word, struct word *wlist) {
  struct word **scan;
  int cmpvalue;
  for (scan = &wlist;
      *scan != NULL && ((cmpvalue = lenalphacmp(word, (*scan)->word)) > 0);
      scan = &((*scan)->next))
    ;
  if (scan != NULL && cmpvalue == 0)
    (*scan)->count ++;
  else {
    struct word *new = malloc(sizeof(struct word) + strlen(word) + 1);
    if (new) {
      new->next = *scan;
      new->count = 1;
      strcpy(new->word, word);
      *scan = new;
    }
  }
  return wlist;
}

struct word *addwordlen(char *word, size_t len,  struct word *wlist) {
  char word0[len+1];
  strncpy(word0,word,len);
  word0[len]=0;
  return addword(word0, wlist);
}

struct word *processline(char *line, struct word *wlist) {
  char *thisword = NULL;
  for ( ;*line != 0; line++) {
    if (isalnum(*line)) {
      if (thisword == NULL)
        thisword = line;
    } else {
      if (thisword != NULL) {
        wlist = addwordlen(thisword, line - thisword, wlist);
        thisword = NULL;
      }
    }
  }
  return wlist;
}

void printwlist(struct word *wlist) {
  for ( ; wlist != NULL; wlist = wlist->next)
    printf("%s : %d\n", wlist->word, wlist->count);
}

int main(int argc, char *argv[1]) {
  if (argc == 2) {
    FILE *fin = fopen(argv[1], "r");
    ssize_t len;
    char *linebuf = NULL;
    size_t linebuflen = 0;
    struct word *wlist = NULL;
    while ((len = getline(&linebuf, &linebuflen, fin)) > 0)
      wlist = processline(linebuf, wlist);
    fclose(fin);
    free(linebuf);
    printwlist(wlist);
    return 0;
  } else
    return 1;
}

