#include "qls.h"

int
main(int argc, char *argv[])
{
	if(argc <= 1)
		listfiles(".");
	else
	{
		for(int i=1 ; i < argc ; i++)
		{
			if(chdir(argv[i]) != 0)
				perror("main(): cannot access the dir");
			listfiles(".");
		}
	}
	
	return 0;
}
