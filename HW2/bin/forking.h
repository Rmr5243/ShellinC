#include <unistd.h>
int forking()
{
  pid_t p;
  p = fork();
  return p;
}