#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

#define min(a,b) (((a)<(b))?(a):(b))

class arrange
{
private:
	int *aux;

public:
	void merge(int *array , int lo , int mid , int hi, int SIZE)
	{
		int i = lo;
		int j = mid + 1;
		int k;
		aux = (int *)malloc(sizeof(int) * SIZE);
		
		for(k=lo ; k <= hi ; k ++)
		{
			aux[k] = array[k];
		}
		
		for(k=lo; k <= hi ; k ++)
		{
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

};

int main(void)
{


	return 0;
}