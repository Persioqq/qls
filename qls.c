#include "qls.h"


static int 
isfile(const char *path)
{
	struct stat pathstat;
    	stat(path, &pathstat);
    	return S_ISREG(pathstat.st_mode);
}

static int 
isdirectory(const char *path)
{
   	struct stat pathstat;
   	stat(path, &pathstat);
	return S_ISDIR(pathstat.st_mode);
}

void
listfiles(const char *path)
{
	struct dirent *dp;
	DIR *dir = opendir(path);
	struct stat     statbuf;
	struct passwd  *pwd;
	struct tm      *tm;
	char            datestring[256];
	
	if(!dir)
		perror("listfiles(): cannot access the dir");
	
	printf("\n");
	while ((dp = readdir(dir)) != NULL)
	{
		if (stat(dp->d_name, &statbuf) == -1)
		        continue;
		
		// Print the owner's name
		if ((pwd = getpwuid(statbuf.st_uid)) != NULL)
			printf(" \033[33m%-8.8s\033[m", pwd->pw_name);
		else
			printf(" \033[33m%-8d\033[m", statbuf.st_uid);
		
		// Print the size of the file
		printf(" \033[36m%9jd\033[m", (intmax_t)statbuf.st_size);


		tm = localtime(&statbuf.st_mtime);

		// Get localized date string
		strftime(datestring, sizeof(datestring), nl_langinfo(D_T_FMT), tm);
		printf(" %s ", datestring);

		// Finally, print the filename
		if(isfile(dp->d_name) == 0)
			printf("\033[36m%s\033[m\n", dp->d_name);
		else if(isdirectory(dp->d_name) == 0)
			printf("\033[33m%s\033[m\n", dp->d_name);
		else
			printf("%s\n", dp->d_name);
	}
	
	printf("\n");
	closedir(dir);
}

