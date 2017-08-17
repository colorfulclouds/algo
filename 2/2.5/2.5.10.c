#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct version
{
	int alpha;
	int beta;
	int gama;
}version_t;

//comparable in java
int comp(const void *a , const void *b)
{
	version_t a_t = *(version_t *)a;
	version_t b_t = *(version_t *)b;

	if(a_t.alpha < b_t.alpha)
		return 1;
	else if(a_t.alpha > b_t.alpha)
		return -1;
	else
	{
		if(a_t.beta < b_t.beta)
			return 1;
		else if(a_t.beta > b_t.beta)
			return -1;
		else
		{
			if(a_t.gama < b_t.gama)
				return 1;
			else if(a_t.gama > b_t.gama)
				return -1;
			else
				return 1;
		}
	}
}

int main(void)
{
	int i;

	version_t inst[3];
	inst[0].alpha = 115;
	inst[0].beta = 1;
	inst[0].gama = 1;

	inst[1].alpha = 115;
	inst[1].beta = 10;
	inst[1].gama = 1;

	inst[2].alpha = 115;
	inst[2].beta = 10;
	inst[2].gama = 2;

	qsort(inst , 3 , sizeof(version_t) , comp);

	for(i=0;i<3;i++)
	{
		printf("%d version:%d.%d.%d\n", i+1 , inst[i].alpha , inst[i].beta , inst[i].gama);
	}

	return 0;
}