#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct table
{
	char level[3];
	double score;
};

int comp(const void *a , const void *b)
{
	struct table a_t = *(struct table *)a;
	struct table b_t = *(struct table *)b;

	return a_t.score > b_t.score;
}

void insert(struct table *inst , int *count , struct table *one)
{
	strcpy(inst[*count].level , one->level);
	inst[*count].score = one->score;

	(*count) ++;

	qsort(inst , *count , sizeof(struct table) , comp);
}

void print(struct table *inst , int count)
{
	int i;

	for(i=0;i<count;i++)
	{
		printf("%s %.2lf\n", inst[i].level , inst[i].score);
	}
}

int main(void)
{
	int count = 0;
	struct table test;
	struct table inst[10];

	strcpy(test.level , "A");
	test.score = 4.0;

	insert(inst , &count , &test);
	
	print(inst , count);

	return 0;
}