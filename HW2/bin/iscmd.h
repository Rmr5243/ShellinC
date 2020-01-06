
int iscmd(char **command, pid_t* childpid, char** CT, int* CArrIn)
{
  if (strcmp(command[0], "environ") == 0)
  {
    env();
    return 1;
  }
  else if (strcmp(command[0], "list") == 0)
  {
    listdir();
    return 1;
  }
  else if (strcmp(command[0], "help") == 0)
  {
    help();
    return 1;
  }
  else if (strcmp(command[0], "cwd") == 0)
  {
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    printf("%s", cwd);
    return 1;
  }
  else if(strcmp(command[0], "jobs") == 0)
  {
    jobs(childpid, CT, *CArrIn);
    return 0;
  }
  else
  {
    return 0;
  }
  
}