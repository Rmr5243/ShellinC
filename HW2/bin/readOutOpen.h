#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int readOutOpen(char** comARR)
{
  int fdout = 0;
  int write_file;
  write_file = Iter(comARR, ">");
  if (write_file){
    if ((fdout = open(comARR[write_file + 1], O_WRONLY | O_TRUNC | O_CREAT| O_APPEND, S_IRWXU)) == -1)
    {
      printf("Error: opening file for output\n");
      exit(1);
    }

    return fdout;
  }
  exit(1);
}