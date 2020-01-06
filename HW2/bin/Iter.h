#include <string.h>
int Iter(char** comARR, char* input)
{
  int i = 0;
  while(comARR[i] != NULL){
    if(comparestr(comARR[i], input)){
      return i;
    }
    i++;
  }
  return -1;
}