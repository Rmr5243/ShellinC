#include <unistd.h>
#include <stdio.h>

void set(char** command){
  if (command[1] == NULL || command[2] == NULL)
  {
    printf("Formatted Incorrectly");
  }
  else
  {
    setenv(command[1], command[2], 0);
  }
}