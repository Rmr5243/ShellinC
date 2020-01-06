#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <fcntl.h>
#include "help.h"
#include "printDir.h"
#include "env.h"
#include "listdir.h"
#include <unistd.h>


#define delimiter " \t\r\n"

int main(int argc, char** argv) {
	int bs = 1024;
	char *command;
	char input[bs];
	pid_t cp;
	int x=1;
	pid_t tpid;
	int childStatus;
	int in, out;

	while (1){
		printDir();
		
		if (!fgets(input, bs, stdin)){
			
			return 0;
		}
		if ((command = strtok(input, delimiter))){
			errno = 0;

			if (strcmp(command, "help") == 0){
				help();
			}
			else if (strcmp(command, "list") == 0){
				list_dir();
			}
			else if (strcmp(command, "environ") == 0){
				env();
			}
			else if (strcmp(command, "cd") == 0){
				char *arg = strtok(0, delimiter);
				if (!arg){
					fprintf(stderr, "No directory specified\n");
				}
				else{
					char old[1024];
					getcwd(old, sizeof(old));
					setenv("OLDPWD", old, 1);
					chdir(arg);
				}
					char full[1024];
					getcwd(full, sizeof(full));
					setenv("PWD", full, 1);
			}
			else if (strcmp(command, "quit") == 0){
				return 0;
			}
			else if (strcmp(command, "set") == 0){
				char *name = strtok(NULL, delimiter);
				char *value = strtok(NULL, delimiter);
				setenv(name, value, 0);
			}			
				
			else{
				cp = fork();
				if (cp == 0) {
					argv[0] = malloc(strlen(input));
					argv[0] = command;

					command=strtok(NULL, delimiter);
					while(command!=NULL) {
						argv[x]=malloc(strlen(input));
						argv[x]=command;
						command=strtok(NULL, delimiter);
						x++;
					}
					int j = 0;
					while(argv[j] != NULL){
						if (strcmp(argv[j], "<") == 0){
							in = open(argv[j+1], O_RDONLY);
							dup2(in, 0);
							close(in);
						}
						if (strcmp(argv[j], ">") == 0){
							out = open(argv[j+1], O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
							dup2(out, 1);
							close(out);
						}
						j++;
					}
					argv[x] = NULL;
					if(execvp(argv[0],argv) == -1)
					{
						printf("Command Failed or Not Found");
						x = 0;
						exit(0);
					}
				}
				else {
					do {
							tpid = wait(&childStatus);
					} while(tpid != cp);
				}
				
			}
			if (errno){
				perror("Command failed");
			}
		}
	}
  return 0;
}