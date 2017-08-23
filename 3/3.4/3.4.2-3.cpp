#include <iostream>
#include <cstdlib>

using namespace std;

class node
{
private:
	int key;
	int value;

	//add 3.4.3
	int k_v;

	node *next;

public:
	friend class link_list;
	friend class hash_link;

	node(int key , int value , node *next)
	{
		this->key = key;
		this->value = value;
		this->next = next;

		this->k_v = 0;
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
	friend class hash_link;

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
			{
				first->k_v --;
				return x->value;
			}

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
		first->k_v++;

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

class hash_link
{
private:
	int N;
	int M;

	link_list *st;

public:
	hash_link(int M = 997)
	{
		this->M = M;
		st = new link_list[M];
	}
	~hash_link()
	{
		delete [] st;
	}

	//member function
	int hash(int key)
	{
		return key % M;
	}

	int get(int key)
	{
		return st[hash(key)].get(key);
	}

	void put(int key , int value)
	{
		st[hash(key)].put(key , value);
	}

	void delete_key(int key)
	{
		st[hash(key)].delete_node(key);
	}

	void delete_key_greater(int k)
	{
		int i;

		node *x ;

		for(i=0;i<M;i++)
		{
			for(x = st[i].first ; x ; x=x->next)
				if(x->k_v > k)
					st[i].delete_node(x->key);
		}
	}

};

int main(void)
{
	link_list h;
	


	return 0;
}