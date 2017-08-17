#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc , char *argv[])
{
	int i;
	int j;

	for(i=1;i<argc;i++)
	{
		for(j=1;j<i;j++)
		{
			if(strstr(argv[i] , argv[j]))
			{
				puts(argv[i]);
				break;
			}
		}
	}


	return 0;
}