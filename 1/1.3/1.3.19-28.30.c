#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int item;
	struct node *next;
}link_list;

void link_add_item(link_list *link , int item)
{
	link_list *node = (link_list *)malloc(sizeof(link_list));
	if(node == NULL)
	{
		exit(EXIT_FAILURE);
	}

	node->item = item;
	node->next = link->next;
	link->next = node;
}

//1.3.19
void link_delete_tail(link_list *link)
{
	link_list *p = link->next;
	link_list *q;
	
	while(p)
	{
		if(p->next)
		{
			q = p->next;
			if(!q->next)
			{
				p->next = NULL;
				free(q);
				break;
			}
			else
			{
				p = p->next;	//p = q;
			}
		}
		else
		{
			link->next = NULL;
			free(p);
			break;
		}
	}
}

//1.3.20
void link_delete(link_list *link , int k)
{
	int counter = 0;
	link_list *p;
	link_list *q = link;

	for(p=link->next ; p ; p = p->next , q = q->next)
	{
		counter ++;
		if(counter == k)
		{
			q->next = p->next;
			free(p);
			break;
		}
	}

}

//1.3.21
int link_find(link_list *link , int key)
{
	link_list *p;

	for(p=link->next ; p ; p = p->next)
	{
		if(key == p->item)
			return 1;
	}

	return 0;
}

//1.3.24
void link_remove_after(link_list *link , link_list *node)
{
	link_list *p = node->next;
	if(node == NULL || node->next == NULL)
		return ;

	//normal
	node->next = p->next;
	free(p);
}

//1.3.25
void link_insert_after(link_list *link , link_list *front , link_list *rear)
{
	if(rear == NULL)
		return ;

	//normal
	rear->next = front->next;
	front->next = rear;
}

//1.3.26
int link_remove_find(link_list *link , int key)
{
	link_list *p;
	int pos = 0;

	for(p=link->next ; p ; p = p->next)
	{
		if(key == p->item)
			return pos + 1;
		else
			pos ++;
	}

	return -1;	//no exist
}

void link_remove(link_list *link , int key)
{
	int delete_pos;

	while(1)
	{
		delete_pos = link_remove_find(link , key);	//find it
		if(delete_pos == -1)
			break;
		else
			link_delete(link , delete_pos);	//delet it
	}
}

//1.3.27
int link_max(link_list *link)
{
	link_list *p = link->next;
	int max;
	if(!p)
		return 0;

	//normal
	max = p->item;
	for( ; p ; p = p->next)
	{
		if(p->item > max)
			max = p->item;
	}

	return max;
}

//1.3.28
link_list *link_max_(link_list *link)
{
	if(link == NULL)
	{
		return NULL;
	}
	if(link->next == NULL)
	{
		return link;
	}
	if(link->item > link->next->item)
	{
		link_list *node = link->next->next;
		link->next = node;
		return link_max_(link);
	}
	else
	{
		return  link_max_(link->next);
	}
}

//1.3.30
link_list* link_reserve(link_list *link)
{
	link_list *r;
	link_list *p = link->next;
	link_list *q = (link_list *)malloc(sizeof(link_list));
	if(q == NULL)
	{
		exit(EXIT_FAILURE);
	}
	q->next = NULL;
	
	for( ; p ; )
	{
		r = p->next;
		p->next = q->next;
		q->next = p;
		p = r;
	}

	return q;
}

void link_print(link_list *link)
{
	link_list *p;

	for(p=link->next ; p ; p = p->next)
	{
		printf("%d ", p->item);
	}

	printf("\n");
}

int main(void)
{
	link_list *link = (link_list *)malloc(sizeof(link_list));
	if(link == NULL)
	{
		exit(EXIT_FAILURE);
	}
	link->next=NULL;

	link_add_item(link , 1);
	link_add_item(link , 2);
	link_add_item(link , 3);
	link_add_item(link , 4);
//	link_add_item(link , 1);

	//1.3.19 test
//	link_delete_tail(link);
//	link_delete_tail(link);
//	link_delete_tail(link);
//	link_delete_tail(link);

	//1.3.20 test
//	link_delete(link , 1);
//	link_delete(link , 2);
//	link_delete(link , 4);
//	link_delete(link , 5);

	//1.3.21 test
//	printf("%d\n", link_find(link , 3));
//	printf("%d\n", link_find(link , 5));

	//1.3.26 test
//	link_remove(link , 2);

	//1.3.27 test
//	printf("%d\n", link_max(link));

	//1.3.28 test
//	printf("%d\n", link_max_(link)->item);

	//1.3.30 test
//	link = link_reserve(link);

	link_print(link);
	
	free(link);

	return 0;
}