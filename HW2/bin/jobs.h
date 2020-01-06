#include <unistd.h>
#include <stdio.h>

void jobs(pid_t *carray, char **ctitle, int cindex)
{
  int x;
  printf("\nPID\t\tTITLE\n");
  for(x = 0; x < sizeof(carray)/sizeof(int); x++)
  {
    printf("%d\t\t%s\n", carray[x], ctitle[x]);
  }
}