#include <stdio.h>
#include <stdlib.h>

int comp_up(const void *a , const void *b)
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
	int min_pos;
	
	int array[10] = {1,1,2,3,4,5,6,8,8,8};
	
	int key = 8;

	min_pos = binary_find(array , key , 0 , 9);

	if(min_pos == -1)
	{
		puts("no");
		return 1;
	}

	//forward
	for(; min_pos ; min_pos --)
	{
		if(array[min_pos] == key)
			continue ;
		else
		{
			min_pos ++;
			break;
		}
	}

	printf("%d\n", min_pos);

	return 0;
}