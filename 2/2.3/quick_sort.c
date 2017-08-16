#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CMAX 100000

int par(int *array , int lo , int hi)
{
	int i = lo;
	int j = hi + 1;

	int v = array[lo];
	int temp;

	while(1)
	{
		while(array[++i] < v)
			if(i == hi)
				break;

		while(v < array[--j])
			if(j == lo)
				break;

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

//http://blog.csdn.net/morewindows/article/details/6684558
int par_(int s[], int l, int r)
{
	int i = l, j = r;
	int x = s[l];	//keng
	while (i < j)
	{
		while(i < j && s[j] >= x) 
			j--;  
		if(i < j) 
		{
			s[i] = s[j];
			i++;
		}

		while(i < j && s[i] < x)
			i++;  
		if(i < j) 
		{
			s[j] = s[i];
			j--;
		}
	}
	s[i] = x;

	return i;
}


void quick_sort(int *array , int low , int high)
{
	int pos;

	if(high <= low)
		return ;

	pos = par_(array , low , high);
	quick_sort(array , low , pos - 1);
	quick_sort(array , pos + 1 , high);

}

int main(void)
{
	int start_time;
	int end_time;

	int i;
	int *array = (int *)malloc(sizeof(int) * CMAX);

	srand((unsigned int)time(NULL));
	for(i=0;i<CMAX;i++)
	{
		array[i] = rand() % CMAX + 1;
	}
	
	start_time = clock();
	quick_sort(array , 0 , CMAX - 1);
	end_time = clock();

	for(i=0;i<CMAX;i++)
		printf("%d ", array[i]);

	printf("\n");

	printf("time:%lf\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

	free(array);
	
	return 0;
}