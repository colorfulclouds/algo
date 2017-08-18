#include <iostream>
#include <cstdlib>

using namespace std;

class bst
{
private:
	class node
	{
	private:
		int key;
		int value;
		node *left , *right;
		int N;

	public:
		node(int key , int value , int N)
		{
			this->key = key;
			this->value = value;
			this->N = N;
		}

		int get_N()
		{
			return N;
		}

		int get_key()
		{
			return key;
		}

		int get_value()
		{
			return value;
		}

		node * get_left()
		{
			return left;
		}

		node * get_right()
		{
			return right;
		}

		void set_left(node *left)
		{
			this->left = left;
		}

		void set_right(node *right)
		{
			this->right = right;
		}

		void set_value(int value)
		{
			this->value = value;
		}

		void set_N(int N)
		{
			this->N = N;
		}
	};//end class node 

private:
	node *root;

public:
	bst()
	{
	}

	~bst()
	{
	}

	//member function

	int size()
	{
		return size(root);
	}

	int size(node *x)
	{
		if(x == NULL)
			return 0;
		else
			return x->get_N();
	}

	int get_value(int key)
	{
		return get_value(root , key);
	}

	int get_value(node *x , int key)
	{
		if(x == NULL)	//no exist
			return -1;
		if(x->get_key() > key)
			return get_value(x->get_left() , key);
		else if(x->get_key() < key)
			return get_value(x->get_right() , key);
		else
			return x->get_value();
	}

	void put(int key , int value)
	{
		root = put(root , key , value);
	}

	node * put(node *x , int key , int value)
	{
		if(x == NULL)
			return new node(key , value , 1);
		
		if(x->get_key() > key)
			x->set_left( put(x->get_left() , key , value) );
		else if(x->get_key() < key)
			x->set_right( put(x->get_right() , key , value) );
		else
			x->set_value(value);

		x->set_N(size(x->get_left()) + size(x->get_right()) + 1);

		return x;
	}
	
};

int main(void)
{
	

	return 0;
}