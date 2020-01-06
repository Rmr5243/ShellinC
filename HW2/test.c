#include "bin/source.h"

void nullstring(char** comARR, char* in, char* out){
  int x = 0;
  int y = 0;
  while(comARR[x] != NULL){
    if(comparestr(comARR[x], out)){
      comARR[x] = NULL;
    }
    x++;
  }
  while(comARR[y] != NULL){
    if(comparestr(comARR[y], in)){
      comARR[y] = NULL;
    }
    y++;
  }
}

void NP(char** comARR, int* pipedex, int x)
{
  if(x != 0){
    while(x < sizeof(*pipedex))
    {
      comARR[pipedex[x]] = NULL;
    }
    x++;
  }
}

void getPipeIndex(char** comARR, int * pipearr){
  int x, index = 0;
  while(x < sizeof(comARR) && comARR[x] != NULL){
    if(strcmp(comARR[x], "|") == 0){
      pipearr[index] = x;
      index += 1;
    }
    x++;
  }
}

void cd(char** command){
  if (chdir(command[1]) == -1)
  {
    printf("Directory Not Found or Specified\n");
  }
  else if (strcmp(command[1], "..") == 0)
    return;
  else
    chdir(command[1]);
}

int P3(char **argv) {
    pid_t pid1, pid2, pid3;
    int fdp1[2]; 
    int fdp2[2]; 
    int status1, status2, status3;
    if (pipe(fdp1) != 0) 
    { 
      perror("pipe");
      exit(1);
    }
    if (pipe(fdp2) != 0) 
    { 
      perror("pipe");
      exit(1);
    }
    pid1 = fork(); 
    if (pid1 == 0) 
    { 
      close(fdp1[0]);
      close(fdp2[0]);
      close(fdp2[1]);
      if (dup2(fdp1[1], 1) == -1) {
	      perror("dup2");
	      exit(1);
      }
      run(argv);
      perror("execlp");
      exit(1);
    } 
    else if (pid1 < 0) 
    { 
      perror("fork"); 
      exit(1);
    }
    pid2 = fork(); 
    if (pid2 == 0) 
    { 
      close(fdp1[1]);
      if (dup2(fdp1[0], 0) == -1) 
      {
	      perror("dup2");
	      exit(1);
      }
      close(fdp2[0]);
      if (dup2(fdp2[1], 1) == -1) 
      {
	      perror("dup2");
	      exit(1);
      }
      run(argv);
      perror("execlp");
      exit(1);
    } 
    else if (pid2 < 0) 
    { 
      perror("fork"); 
      exit(1);
    }
    pid3 = fork(); 
    if (pid3 == 0) 
    { 
      close(fdp1[0]);
      close(fdp1[1]);
      close(fdp2[1]);
      if (dup2(fdp2[0], 0) == -1) {
	      perror("dup2");
      	exit(1);
      }
      run(argv);
      perror("execlp");
      exit(1);
    } else if (pid3 < 0) 
    { 
      perror("fork"); 
      exit(1);
    }
    close(fdp1[0]);
    close(fdp1[1]);
    close(fdp2[0]);
    close(fdp2[1]);
    waitpid(pid1, &status1, 0);
    waitpid(pid2, &status2, 0);
    waitpid(pid3, &status3, 0);
    return 0;
}

int P2(char **argv) {
    pid_t pid1, pid2;
    int pipefd[2]; 
    int status1, status2;
    if (pipe(pipefd) == 0) 
    { 
      pid1 = fork(); 
      if (pid1 == 0) {   
	      close(pipefd[0]);
        if (dup2(pipefd[1], 1) == -1) 
        {
           perror("dup2");
           exit(1);
        }
      run(argv);
      printf("If you see this statement then exec failed ;-(\n");
      perror("execlp");
      exit(1);
      } 
      else if (pid1 < 0) 
      { 
        perror("fork"); 
        exit(1);
      }
      pid2 = fork();
      if (pid2 == 0) { 
        close(pipefd[1]);
        if (dup2(pipefd[0], 0) == -1)
        {
          perror("dup2");
          exit(1);
        }
        run(argv);
        printf("If you see this statement then exec failed ;-(\n");
        perror("execlp");
        exit(1);
      } 
      else if (pid2 < 0) 
      { 
        perror("fork"); 
        exit(1);
      }
      close(pipefd[0]);
      close(pipefd[1]);
      waitpid(pid1, &status1, 0);
      waitpid(pid2, &status2, 0);
    } 
    else 
    {
      perror("pipe");
      exit(1);
    }
    return 0;
}

int parentProcess(char** comARR, int* args, int need_to_wait, pid_t* cpids, char** ctitle, int* cindex, int pid)
{
  int status;
  if(need_to_wait)
  {
    wait(&status);
  }
  else
  {
      ctitle[*cindex] = malloc(strlen(comARR[0]) * sizeof(char));
      strcpy(ctitle[*cindex], comARR[0]);
      cpids[*cindex] = pid;
      *cindex += 1;
      return 0;
  }
  return 0;
}

int part1(char** comARR, pid_t* cpids, char** CT, int* CArrIn)
{
  int args[4] = {0, 0, 0, 0};
  int noargs = 1;
  int status1 = 0;
  setargs(comARR, args);
  for (int x = 0; x < 4; x++){
    if(args[x] == 1){
      noargs = 0;
    }
  }
  if(noargs){
    if(!iscmd(comARR, cpids, CT, CArrIn)){
      int pid = forking();
      if(pid == 0){
        cp(comARR);
      }else if(pid > 0){
        status1 = parentProcess(comARR, args, noargs, cpids, CT, CArrIn, pid);
      }else{
        perror("fork"); 
        exit(1);
      }
    }
  }
  else
  {
    status1 = part2(comARR, args, cpids, CT, CArrIn);
  }

  return status1;
}
int part2(char** comARR, int* args, pid_t* cpids, char** CT, int* CArrIn)
{
  int status2 = 0;
  int fdin, fdout;
  int amp = 1, pipe = 0;  
  int PC = 0;
  if(args[2] == 1)
  {
    fdin = readInOpen(comARR);
  }
  if(args[3] == 1)
  {
    fdout = readOutOpen(comARR);
  }
  if(args[1] == 1)
  {
    amp = 0;
  }
  if(args[0] == 1)
  {
    pipe = 1;
  }
  PC = pipecnt(comARR);
  int pipe_index[PC];
  if(PC)
  {
    getPipeIndex(comARR, pipe_index);
  }
  nullstring(comARR, "<", ">");
  NP(comARR, pipe_index, PC);
  if(PC == 2)
  {
    P3(comARR);
    return 0;
  }
  int pid;
  pid = forking();
  if(pid == 0)
  {
    if(fdin > 0)
    {
    dupe(fdin, 0);
    }
    if(fdout > 0)
    {
      dupe(fdout, 1);
    }
    if (!amp && !(fdout > 0))
    {
      int emp = open("/dev/null", O_RDONLY);
      dupe(emp, 1);
    }
    cp(comARR);
  }
  else if(pid > 0)
  {
    status2 = parentProcess(comARR, args, amp, cpids, CT, CArrIn, pid);
  }
  else
  {
    perror("fork");
    exit(1);
  }
    return status2;
}

int main(int argc, char** argv)
{
  int main_status = 0;
  char string_cmd[1024];
  char** comARR;
  pid_t cpids [1000];
  char **CT = malloc(1000 * sizeof(char*));
  int CArrIn = 0;

    while(!main_status){
        int emp;
        printDir();        
        inp(string_cmd);
        emp = noinp(string_cmd);
        if(!emp){
            comARR = parseLine(string_cmd);
            int if_quick = 0;
            if_quick = isQC(comARR);
            if (if_quick){
                runQC(comARR, if_quick);
                continue;
            }else{
              
              main_status = part1(comARR, cpids, CT, &CArrIn);
            }
        free(comARR);     
        }
    }
    return EXIT_SUCCESS;
}
