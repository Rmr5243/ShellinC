#include <string.h>

/*
Check if command is a command that is not affected by | < > &. 
If it is not return a value corresponding to each comamnd.
*/

int isQC(char** command){                       
    if (strcmp(command[0], "set") == 0){
        return 1;
    }else if(strcmp(command[0], "cd") == 0){
        return 2;
    }else if(strcmp(command[0], "quit") == 0){
        return 3;
    }else{return 0;}
}