#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX 100000

void get_h(int *h_array)
{
	int i=0;
	int h = 1;

	while (h<MAX/3)
	{
		h = 3*h + 1;
	}
	h_array[i ++] = h;

	while (h>=1)
	{
		h /= 3;
		h_array[i ++] = h;
	}

	h_array[i] = 0;
}

void shell_sort(int *array)
{
	int i;
	int j;
	int k=0;
	int h;
	int h_array[100];
	get_h(h_array);

	while(h_array[k])
	{
		h=h_array[k];

		for(i=h;i<MAX;i++)
		{
			for(j=i ; j>=h && array[j]<array[j-h] ; j-=h)
			{
				array[j] ^= array[j-h];
				array[j-h] ^= array[j];
				array[j] ^= array[j-h];
			}
		}

		k ++;
	}
	
}

int main(void)
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
	start_time = clock();
	shell_sort(array);
	end_time = clock();
	printf("shell time:%lf\n", (double)(end_time - start_time)/CLOCKS_PER_SEC);

	return 0;
}
