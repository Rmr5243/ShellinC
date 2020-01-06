#include <string.h>

int pipecnt(char** comARR)
{
  int x, pipes = 0;
  
  for(x = 0; x < sizeof(comARR) && comARR[x] != NULL; x++)
  {
    if(strcmp(comARR[x], "|") == 0)
    {
      pipes += 1;
    }
  }
  return pipes;
}