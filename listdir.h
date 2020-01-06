int list_dir(void){
	DIR *d;
	struct dirent *dir;
	d = opendir(".");
	if(!d){
		return 0;
	}
	while((dir = readdir(d)) != NULL)
	{
		printf("%s\n", dir->d_name);
	}
	closedir(d);
	return(1);
}