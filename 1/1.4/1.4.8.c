#include <stdlib.h>
#include <stdio.h>

int comp(const void *a , const void *b)
{
	return *(int *)a - *(int *)b;
}

int binary_find(int *array , int key , int low , int high)
{

	int middle;

	while(low <= high)
	{
		middle = (low + high) / 2;

		if(array[middle]>key)
		{
			high = middle - 1;
		}
		else if(array[middle] < key)
		{
			low = middle + 1;
		}
		else
			return middle;
	}

	return -1;
}

int main(void)
{
	int array[10] = {11,23,11,55,12,2,23,2,5,55};
	int i;
	int count = 0;
	qsort(array , 10 , sizeof(int) , comp);

for(i=0;i<10;i++)
{
	printf("%d\n", array[i]);
}

	for(i=0;i<10;i++)
	{
		printf("pos:%d\n", binary_find(array , array[i] , i+1 , 9));
		if(binary_find(array , array[i] , i+1 , 9) != -1)
			count ++;
	}

	printf("%d\n", count);

	return 0;
}