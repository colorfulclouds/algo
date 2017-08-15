#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

static int times = 0;

void merge(int *array , int lo , int mid , int hi, int SIZE)
{
	int i = lo;
	int j = mid + 1;
	int k;
	int *aux = (int *)malloc(sizeof(int) * SIZE);	//aux to main

	for(k=lo ; k <= hi ; k ++)
	{
		times ++;
		aux[k] = array[k];
	}

	for(k=lo; k <= hi ; k ++)
	{
		times ++;
		
		if(i>mid)
			array[k] = aux[j++];
		else if(j>hi)
			array[k] = aux[i++];
		else if(aux[j] < aux[i])
			array[k] = aux[j++];
		else
			array[k] = aux[i++];
	}
	free(aux);

}

void merge_sort(int *array , int lo , int hi , int SIZE)
{
	int mid;

	if(hi<=lo)
		return ;

	mid = lo + (hi-lo)/2;
	merge_sort(array , lo , mid,SIZE);
	merge_sort(array , mid+1 , hi,SIZE);
	
	//2.2.8
//	if(array[mid] > array[mid+1])
		merge(array , lo , mid , hi , SIZE);
}

void up_merge_sort(int *array , int SIZE)
{
	int sz;
	int low;


	for(sz = 1; sz<SIZE;sz*=2)
	{
		for(low=0;low<SIZE-sz;low+= sz+sz)
			merge(array , low,low+sz-1,min(low+sz+sz+1,SIZE-1) ,SIZE);
	}
}

int main(int argc , char *argv[])
{
	int i;
	int j;

	int *array;
	int SIZE[512];

	double nln;

	for(i=0;i<512;i++)
		SIZE[i] = i+1;

	for(i=0;i<512;i++)
	{
		srand((unsigned int)time(NULL));
		nln = 6*SIZE[i]*log(SIZE[i]);

		array = (int *)malloc(sizeof(int) * SIZE[i]);
		for(j=0;j<SIZE[i];j++)
			array[j] = rand() % SIZE[i] + 1;

		if(argc == 1)
		{
			merge_sort(array , 0,SIZE[i]-1,SIZE[i]);
			printf("top to down ");
		}
		else
		{
			up_merge_sort(array , SIZE[i]);
			printf("down to top ");
		}
		
	printf("size:%d times:%d 6NlgN:%lf\n", SIZE[i] , times , nln);
	times = 0;	//reset

		free(array);
	}

//	for(i=0;i<CMAX;i++)
//		printf("%d ", array[i]);

	printf("\n");



	return 0;
}