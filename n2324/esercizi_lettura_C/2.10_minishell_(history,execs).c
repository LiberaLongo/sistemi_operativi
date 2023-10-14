/*this program needs some libraries: history/readline should be provided in yur distribution, execs is in Debian Buster (or it is available in GitHUB). */
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
/*You may need to define the environment variable LD_LIBRARY_PATH to load locally installed libraries. 

LD_LIBRARY_PATH=/usr/local/lib
export LD_LIBRARY_PATH

*/

