#include <iostream>
#include <cstdlib>

using namespace std;

class node
{
private:
	int key;
	int value;

	node *next;

public:
	friend class link_list;
	node(int key , int value , node *next)
	{
		this->key = key;
		this->value = value;
		this->next = next;
	}
	~node()
	{
	}
};

class link_list
{
private:
	node *first;

public:
	link_list()
	{
		first = NULL;
	}
	~link_list()
	{
		//delete
	}
	
	int get(int key)
	{
		node *x = first;

		for( ; x ; x=x->next)
			if(key == x->key)
				return x->value;

		return -1;
	}

	void put(int key , int value)
	{
		node *x = first;

		for(; x ; x=x->next)
			if(key == x->key)
			{
				x->value = value;
				return ;
			}

		first = new node(key , value , first);

	}

	void print();
	int size();

	void delete_node(int key);
};

void link_list::print()
{
	node *x;

	for(x=first ; x ; x = x->next)
	{
		printf("key:%-4d value:%-4d\n", x->key , x->value);
	}

	printf("\n");
}

int link_list::size()
{
	int length = 0;
	node *x;
	
	for(x=first ; x ; x = x->next)
	{
		length ++;
	}

	return length;
}

void link_list::delete_node(int key)
{
	node *p = first;
	node *q = p;

	for(; p ; p = p->next)
	{
		if(p->key == key)
		{
			if(first == p)
			{
				first = p->next;
			}
			else
			{
				q->next = p->next;
				delete(p);
				return ;
			}
		}
		
		q = p;
	}
}

int main(void)
{
	link_list h;
	h.put(1,2);
	h.put(3,5);
	h.put(6,15);
	h.put(7,52);
	h.put(31,125);

	h.print();
	
	h.delete_node(1);
	h.delete_node(31);
//	h.delete_node(7);

	h.print();

//	printf("length:%d\n", h.size());


	return 0;
}