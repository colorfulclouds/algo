#include <stdio.h>
#include <stdlib.h>

#define CMAX 11

int min_heap(int *array)
{
	int i;

	for(i=1;i<CMAX/2;i++)
	{
		if( (array[i] > array[2*i]) || (array[i] > array[2*i + 1]) )
		{
			return 0;
		}
	}

	return 1;
}

int main(void)
{
	int array[CMAX]={0 , 1,2,3,4,5,6,7,8,9,10};
//	int array[CMAX]={0 , 12,51,32,12,2,3,5,12,45,32};
	printf("status:%d\n", min_heap(array));


	return 0;
}