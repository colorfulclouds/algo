#include <iostream>
#include <cstdio>

using namespace std;

#define CMAX 11

class max_pq
{
private:
	int *pq;
	int N;

	int comp_times;
	int exeh_times;

public:
	max_pq(int *array , int length);
	~max_pq()
	{
		free(pq);
	}

	void sink(int k);
	void print()
	{
		int i;

		for(i=1;i<N;i++)
			printf("%d ", pq[i]);

		printf("\n");
	}

	void times()
	{
		printf("comp:%d exch:%d\n", comp_times , exeh_times);
	}

	void sort()
	{
		int length = N;
		int temp;

		N--;

		while(N > 1)
		{
			temp = pq[N];
			pq[N] = pq[1];
			pq[1] = temp;

			N -- ;

			sink(1);
		}

		N = length;	//re
	}

};

max_pq::max_pq(int *array , int length)
{
	this->comp_times = this->exeh_times = 0;

	N = length;
	int k;

	pq = (int *)malloc(sizeof(int) * N);

	for(k=1;k<N;k++)
		pq[k] = array[k]; 

	for(k=N/2 ; k>=1 ; k --)
	{
		sink(k);
	}

}

void max_pq::sink(int k)
{
	int j;

	while(2*k <= N)
	{
		j = 2*k;
		if(j<N && (pq[j] < pq[j+1]) )
		{
			j ++;
			comp_times ++;
		}
		if(pq[k]>pq[j])
		{
			comp_times ++;
			break;
		}

		pq[k] ^= pq[j];
		pq[j] ^= pq[k];
		pq[k] ^= pq[j];
		exeh_times ++;

		k = j;
	}
}

int main(void)
{
	int array[CMAX] = {0 , 1,23,45,12,65,13,5,36,9,21};
	
	max_pq test(array , CMAX);
	test.times();

	test.print();
	test.sort();
	test.print();

	return 0;
}