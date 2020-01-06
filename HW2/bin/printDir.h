#include <unistd.h>
void printDir()
{
	char cdir[1024];
	getcwd(cdir, sizeof(cdir)); 
	printf("\n[%s]\nblazersh> ", cdir);
}