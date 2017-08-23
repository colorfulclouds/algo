#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[] = "SEARCHXMPL";
	int a;
	int M;

	int i;
	int length = strlen(str);

	int *hash;
	
	a=11;
	M=4;

	hash = (int *)malloc(sizeof(int) * M);
	

	for(i=0;i<length;i++)
	{
		hash[i] = (a*(int)str[i])%M;
	}

	for(i=0;i<length;i++)
	{
		printf("%c %d\n", str[i] , hash[i]);
	}
	free(hash);

	return 0;
}
