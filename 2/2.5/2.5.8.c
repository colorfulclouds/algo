#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct freq
{
	char item[20];
	int hz;
};

int comp(const void *a , const void *b)
{
	return ((struct freq *)b)->hz - ((struct freq *)a)->hz;
}

int main(int argc , char *argv[])
{
	int i;
	int j;
	int pos = 1;
	struct freq *inst = (struct freq *)malloc(sizeof(struct freq) * (argc));
	
	for(i=1;i<argc;i++)
	{
		inst[i].item[0] = '\0';
		inst[i].hz = 0;
	}

	strcpy(inst[pos].item , argv[1]);
	inst[pos ++].hz ++;

	for(i=2;i<argc;i++)
	{
		for(j=1;j<i;j++)
		{
			if(strcmp(argv[i] , inst[j].item) == 0)
				inst[j].hz ++;
			else
			{
				strcpy(inst[pos].item , argv[i]);
				inst[pos ++].hz ++;
				
				break;
			}
		}
	}

	qsort(inst+1 , pos -1 , sizeof(struct freq) , comp);

	for(i=1;i<pos;i++)
	{
		printf("%s %d\n", inst[i].item , inst[i].hz);
	}

	free(inst);

	return 0;
}