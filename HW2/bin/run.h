#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int run(char** cmds){
  if(execvp(cmds[0], cmds) == -1){
    fprintf(stderr, "Command failed or Not Found\n");
    exit(1);
  }
  return 0;
}