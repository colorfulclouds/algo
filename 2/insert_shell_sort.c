#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100000000	//shell sort:110.377s

void insert_sort(int *array)
{
	int i;
	int j;

	for(i=1;i<MAX;i++)
	{
		for(j=i ; j>0 && array[j]<array[j-1] ; j --)
		{
			array[j] ^= array[j-1];
			array[j-1] ^= array[j];
			array[j] ^= array[j-1];
		}
	}
}

void shell_sort(int *array)
{
	int i;
	int j;
	int h = 1;

	while(h<MAX/3)
		h = 3*h + 1;

	while(h>=1)
	{
		for(i=h;i<MAX;i++)
		{
			for(j=i ; j>=h && array[j]<array[j-h] ; j-=h)
			{
				array[j] ^= array[j-h];
				array[j-h] ^= array[j];
				array[j] ^= array[j-h];
			}
		}
		h=h/3;
	}
	
}

int main(int argc , char *argv[])
{
	int i;
	int *array = (int *)malloc(sizeof(int) * MAX);
	int start_time;
	int end_time;

	srand((unsigned int)time(NULL));
	for(i=0;i<MAX;i++)
	{
		array[i] = rand() % MAX + 1;
	}

	if(argc == 1)
	{
		start_time = clock();
		insert_sort(array);
		end_time = clock();
		printf("insert time:%lf\n", (double)(end_time - start_time)/CLOCKS_PER_SEC);
	}
	else
	{
		start_time = clock();
		shell_sort(array);
		end_time = clock();
		printf("shell time:%lf\n", (double)(end_time - start_time)/CLOCKS_PER_SEC);
	}
	
	free(array);

	return 0;
}
