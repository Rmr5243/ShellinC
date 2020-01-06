#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>

char **parseLine(char *line)
{
  int bs = 1024, position = 0;
  char **TokeBS = malloc(bs * sizeof(char*));
  char *toke;
  const char s[1] = " ";
  toke = strtok(line, s);
  while (toke != NULL)
  {
    TokeBS[position] = toke;
    position++;

    if (bs <= position)
    {
      bs += 180;
      TokeBS = realloc(TokeBS, bs * sizeof(char *));
    }
    toke = strtok(NULL, s);
  }
  TokeBS[position] = NULL;
  return TokeBS;
}