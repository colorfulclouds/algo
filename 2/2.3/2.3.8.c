#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int times = 0;

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
			times ++;
			if(i == hi)
				break;
		}

		while(v < array[--j])
		{
			times ++;
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

void quick_sort(int *array , int low , int high)
{
	int pos;

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
	int N[3] = {100 , 1000 , 10000};
	int *array;

	for(i=0;i<3;i++)
	{
		array = (int *)malloc(sizeof(int) * N[i]);
		for(j=0;j<N[i];j++)
			array[j] = 1;	//same element
		quick_sort(array , 0 , N[i] - 1);

		printf("times:%d 2NlnN:%f\n", times , 2*N[i]*log(N[i]));

		times = 0;
		free(array);

	}

	return 0;
}