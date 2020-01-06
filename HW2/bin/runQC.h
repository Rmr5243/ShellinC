void runQC(char** args,int command){
	if (command == 1)
  {
    set(args);
  }

  else if(command == 2)
  {
    cd(args);
  }

  else if(command == 3)
  {
    quit();
  }
}