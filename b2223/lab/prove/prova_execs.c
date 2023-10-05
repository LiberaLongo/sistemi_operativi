#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <execs.h>

int main(int argc, char *argv[]) {
  while (1) {
    char *cmd = readline("% ");
    if (cmd == NULL)
      break;
    if (*cmd != 0) {
      add_history(cmd);
      system_nosh(cmd);
    }
    free(cmd);
  }
  printf("\n");
  return 0;
}
