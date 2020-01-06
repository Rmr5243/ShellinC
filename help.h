char *command_lst[] = {"cd - Changes the current directory\n",
"help - Lists all available commands\n",
"quit - Exits the shell\n",
"set <name> <value> - Sets enviroment variable and adds to list of enviroment strings\n", 
"list - Lists all files in the current directory\n",
"environ - Lists all enviroment variables in name= value format\n",
"cd <directory> - changes directory to specified directory\n"
};
void help(void){
	int count;
	printf("\nEnter a command and press ENTER key\nBuilt-in Commands:\n");
	for (count = 0; count < sizeof(command_lst)/ sizeof(char *); count++){
		printf("%s\n", command_lst[count]);
	}
}