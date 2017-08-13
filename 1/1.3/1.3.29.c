#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int item;
	struct node *next;
}node_t;

typedef struct queue
{
	node_t *first;
	node_t *last;
	int count ;
}queue_t;

void init(queue_t *queue)
{
	node_t *p = (node_t *)malloc(sizeof(node_t));
	if(p == NULL)
	{
		exit(EXIT_FAILURE);
	}
	p->next = NULL;

	queue->first = queue->last = p;
	queue->count = 0;
}

void queue_add(queue_t *queue , int item)
{
	node_t *p = (node_t *)malloc(sizeof(node_t));
	if(p == NULL)
	{
		exit(EXIT_FAILURE);
	}
	p->item = item;
	p->next = queue->first;

	queue->last->next = p;
	queue->last = p;
	queue->count ++;
}

int queue_delete(queue_t *queue)
{
	node_t *p = queue->first->next;
	int item = p->item;
	queue->first->next = p->next;
	free(p);
	queue->count --;
	
	return item;
}

void queue_print(queue_t *queue)
{
	node_t *p = queue->first->next;

	while(p != queue->first)
	{
		printf("%d ", p->item);
		p = p->next;
	}

	printf("\n");
}

int main(void)
{
	queue_t *queue = (queue_t *)malloc(sizeof(queue_t));
	init(queue);

	queue_add(queue , 8);
	queue_add(queue , 7);
	queue_add(queue , 2);

	queue_delete(queue);

	queue_print(queue);

	free(queue);
	
	return 0;
}