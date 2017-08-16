#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>


int par(int *array , int lo , int hi)
{
	int i = lo;
	int j = hi + 1;

	int v = array[lo];
	int temp;

	while(1)
	{
		while(array[++i] < v)
		{
			if(i == hi)
				break;
		}

		while(v < array[--j])
		{
			if(j == lo)
				break;
		}
		if(i >= j)
			break;

		temp = array[i] ;
		array[i] = array[j];
		array[j] = temp;
	}
	
	array[lo] ^= array[j];
	array[j] ^= array[lo];
	array[lo] ^= array[j];
	
	return j;	
}

int times_0 = 0;
int times_1 = 0;
int times_2 = 0;

void quick_sort(int *array , int low , int high)
{
	int pos;

	if(low > high)
		times_0 ++;
	else if((high - low) == 0)
		times_1 ++;
	else if((high - low) == 1)
		times_2 ++;

	if(high <= low)
		return ;

	pos = par(array , low , high);
	quick_sort(array , low , pos - 1);
	quick_sort(array , pos + 1 , high);

}

int main(void)
{
	int i;
	int j;
	int N = 9;
	int *array;

	for(i=0;i<100;i++)
	{
		N ++;
		srand((unsigned int)time(NULL));
		array = (int *)malloc(sizeof(int) * N);
		for(j=0;j<N;j++)
			array[j] = rand() % N + 1;
		quick_sort(array , 0 , N - 1);

		printf("time_0:%-3d time_1:%-3d time_2:%-3d\n", times_0 , times_1 , times_2);
		//~2:2:1
		times_0 = times_1 = times_2 = 0;

		free(array);

	}

	return 0;
}