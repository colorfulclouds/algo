#include <stdlib.h>
#include <stdio.h>

#define CMAX 10

void swim(int *array , int k)
{
	while(k > 1 && (array[k/2] < array[k]) )
	{
		array[k/2] ^= array[k];
		array[k] ^= array[k/2];
		array[k/2] ^= array[k];

		k /= 2;
	}
}

void sink(int *array , int k)
{
	int j;
	while(2*k <= CMAX)
	{
		j = 2*k;
		if(j<CMAX && (array[j] < array[j+1]))
			j ++;
		if(array[k] >= array[j])
			break;

		array[k] ^= array[j];
		array[j] ^= array[k];
		array[k] ^= array[j];

		k = j;
	}
}

int size = 0;
void insert(int *array , int item)
{
	array[++ size] = item;
	swim(array , size);
}

int delete(int *array)
{
	int temp = array[1];//0 no use

	array[1] ^= array[size];
	array[size] ^= array[1];
	array[1] ^= array[size];

	size --;	//delete
	sink(array , 1);
	return temp;
}

int main(void)
{
	int *array = (int *)malloc(sizeof(int) * CMAX);
	insert(array , 2);
	insert(array , 12);
	insert(array , 6);
	insert(array , 24);
	insert(array , 6);
	insert(array , 8);
	insert(array , 19);
	insert(array , 31);
	insert(array , 25);

	printf("%d\n", delete(array));

	free(array);


	return 0;
}