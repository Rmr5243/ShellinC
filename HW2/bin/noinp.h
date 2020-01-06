#include <string.h>

int noinp(char* line){
    if (strcmp(line, "\0") == 0)
    {
      return 1;
    }
    else
    {
      return 0;
    }
}