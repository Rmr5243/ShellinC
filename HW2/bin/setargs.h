
#include <string.h>
void setargs(char** command, int* args)
{
  int i = 0;
  while(command[i] != NULL){
    if(strcmp(command[i], "|") == 0){
      args[0] = 1;
    }else if(strcmp(command[i], "&") == 0){
      args[1] = 1;
    }else if(strcmp(command[i], "<") == 0){
      args[2] = 1;
    }else if(strcmp(command[i], ">") == 0){
      args[3] = 1;
    }
    i++;
  }
}