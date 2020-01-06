#include <unistd.h>
void dupe(int oldfd, int newfd)
{
  dup2(oldfd, newfd);
  close(oldfd);
}