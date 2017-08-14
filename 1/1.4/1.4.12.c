#include <stdlib.h>
#include <stdio.h>

int comp(const void *a , const void *b)
{
	return *(int *)a - *(int *)b;
}

int main(void)
{
	int array_a[10] = {2,12,35,12,54,12,65,32,1,45};
	int array_b[15] = {12,54,12,32,12,12,1,3,54,2,12,54,1,32,1};

	int array_c[15];
	int pos = 0;

	int i;
	int j;

	qsort(array_a , 10 , sizeof(int) , comp);	
	qsort(array_b , 15 , sizeof(int) , comp);

	i=j=0;

	while(i<10 && j<15)
	{
		if(array_a[i] < array_b[j])
			i ++;
		else if(array_a[i] > array_b[j])
			j ++;
		else
		{
			array_c[pos ++] = array_a[i];
			i++;
			j++;
		}
	}

	//remove the same number
	for(i=1;i<pos;i++)
	{
		for(j=0;j<i;j++)
			if(array_c[i] == array_c[j])
			{
				array_c[j] = array_c[-- pos];
				break;
			}
	}

	for(i=0;i<pos;i++)
		printf("%d ", array_c[i]);

	printf("\n");

	return 0;
}