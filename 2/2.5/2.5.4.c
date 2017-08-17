#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void dedup(char *array , int length)
{
	int i;
	char *str = (char *)malloc(sizeof(char) * length);
	int pos = 0;

	str[pos ++] = array[0];

	for(i=1;i<length;i++)
	{
		if(array[i] == str[pos-1])
			continue ;
		else
			str[pos ++] = array[i];
	}

	str[pos] = '\0';

	strcpy(array , str);
	
	free(str);
}

int comp(const void *a , const void *b)
{
	return *(char *)a - *(char *)b;
}

int main(void)
{
	char array[] = "sdfavsdsgasfaf";
	int length = strlen(array);
	
	qsort(array , length , sizeof(char) , comp);
	puts(array);

	dedup(array , length);
	puts(array);

	return 0;
}