extern char **environ;

void env(void){
	int x;
	for (x=0; environ[x] !=NULL; x++){
		printf("\n%s\n",environ[x]);
	}
}