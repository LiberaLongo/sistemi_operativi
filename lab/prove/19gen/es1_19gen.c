#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <execs.h>

int main(int argc, char** argv){
    int des_p[2];
    if(pipe(des_p) == -1) {
        perror("Pipe failed");
        exit(1);
    }
    int first = 1;
    while(1){
        char *cmd = readline(NULL);
        if (cmd == NULL)
            break;
        if (*cmd != 0) {
            if(first){
                first--;
                if(fork() == 0){
                    close(STDOUT_FILENO);
                    dup(des_p[1]);
                    close(des_p[0]);
                    close(des_p[1]);
                    system_nosh(cmd);
                    exit(1);
                }
            }else{
                if(fork() == 0){
                    close(STDIN_FILENO);   //closing stdin
                    dup(des_p[0]);         //replacing stdin with pipe read
                    close(des_p[1]);       //closing pipe write
                    close(des_p[0]);
                    system_nosh(cmd);
                    exit(1);
                }
            }
        }
        free(cmd);
    }

    close(des_p[0]);
    close(des_p[1]);
    wait(0);
    wait(0);
    return 0;
}
