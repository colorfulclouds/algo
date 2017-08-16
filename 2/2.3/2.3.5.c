#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int i;
	int key_1;
	int count_key_1 = 0;
	int key_2;
	int count_key_2 = 0;
	int array[10]={1,2,1,2,1,1,1,2,1,2};

	key_1 = array[0];
	for(i=1;i<10;i++)
		if(array[i] != key_1)
		{
			key_2 = array[i];
			break;
		}

	for(i=0;i<10;i++)
	{
		if(array[i] == key_1)
			count_key_1 ++;
		else if(array[i] == key_2)
			count_key_2 ++;
	}
	
	if(key_1 < key_2)
	{
		for(i=0;i<count_key_1;i++)
			array[i] = key_1;

		for(;i<10;i++)
			array[i] = key_2;
	}
	else
	{
		for(i=0;i<count_key_2;i++)
			array[i] = key_2;

		for(;i<10;i++)
			array[i] = key_1;
	}

	for(i=0;i<10;i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");

	return 0;
}