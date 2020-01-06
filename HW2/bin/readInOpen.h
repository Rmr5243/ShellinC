#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>


int readInOpen(char** comARR)
{
  int fdin = 0;
  int read_file;
  read_file = Iter(comARR, "<");
  if (read_file){
    if ((fdin = open(comARR[read_file + 1], O_RDONLY)) == -1)
    {
      printf("Error opening file stdin.txt for input\n");
      exit(1);
    }

    return fdin;
  }
  exit(1);
}