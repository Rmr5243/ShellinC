#include <stdio.h>
#include <string.h>

void inp(char* line)
{
  fgets(line, 1024, stdin); //readline
    size_t ln = strlen(line) - 1;
    if (*line && line[ln] == '\n')
    {
      line[ln] = '\0';
    }
}