#include <string.h>

int comparestr(char* commands, char* input)
{ 
    if(strcmp(commands, input) == 0){
      return 1;
    }
  return 0;
}