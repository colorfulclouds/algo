#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define CMAX 1000000

void shell_sort(double *array , double *comp)
{
	int i;
	int j;
	int h = 1;
	double temp;
	long *times = (long *)malloc(sizeof(long) * CMAX);
	for(i=0;i<CMAX;i++)
		times[i] = 0;

	while(h<CMAX/3)
		h = 3*h + 1;

	while(h>=1)
	{
		for(i=h;i<CMAX;i++)
		{
			for(j=i ; j>=h && array[j]<array[j-h] ; j-=h)
			{
				temp = array[j];
				array[j] = array[j-h];
				array[j-h] = temp;

				times[j] ++;
				times[j-h] ++;
			}
		}
		h=h/3;
	}
	
	for(i=0;i<CMAX;i++)
	{
		comp[i] = (double)times[i] / (double)CMAX;
//		printf("%lf ", comp[i]);
		printf("%d ", times[i]);
	}
	free(times);

}

int main(void)
{
	int i;
	int start_time;
	int end_time;
	double *array = (double *)malloc(sizeof(double) * CMAX);
	double *comp = (double *)malloc(sizeof(double) * CMAX);

	srand((unsigned int)time(NULL));
	for(i=0;i<CMAX;i++)
	{
		array[i] = (double)(rand() % CMAX) / 1.0 + 1;
	}
	start_time = clock();
	shell_sort(array , comp);
	end_time = clock();
	printf("shell time:%lf\n", (double)(end_time - start_time)/CLOCKS_PER_SEC);

//	for(i=0;i<CMAX;i++)
//	{
//		printf("%lf ", comp[i]);
//	}

	free(array);
	free(comp);

	return 0;
}
