#include <iostream>
#include <cstdlib>
#include <queue>

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

	public:
		node(int key , int value)
		{
			this->key = key;
			this->value = value;
			this->left = this->right = NULL; 
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
	};//end class node 

private:
	node *root;

public:
	bst()
	{
		root = NULL;
	}

	~bst()
	{
	}

	//member function

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
			return new node(key , value);
		
		if(x->get_key() > key)
			x->set_left( put(x->get_left() , key , value) );
		else if(x->get_key() < key)
			x->set_right( put(x->get_right() , key , value) );
		else
			x->set_value(value);

		return x;
	}

	int min()
	{
		return min(root)->get_key(); 
	}
	node * min(node *x)
	{
		if(x->get_left() == NULL)
			return x;
		else
			return min(x->get_left());
	}

	int max()
	{
		return max(root)->get_key();
	}
	node * max(node *x)
	{
		if(x->get_right() == NULL)
			return x;
		else
			return max(x->get_right());
	}

	int floor(int key)
	{
		node *x = floor(root , key);
		if(x == NULL)
			return -1;	//no exist

		return x->get_key();
	}
	node * floor(node *x , int key)
	{
		if(x == NULL)
			return NULL;

		if(key == x->get_key())
			return x;
		if(key<x->get_key())
			return floor(x->get_left() , key);

		node *t = floor(x->get_right() , key);
		if(t!=NULL)
			return t;
		else
			return x;
	}

	int ceiling(int key)
	{
		node *x = ceiling(root , key);
		if(x == NULL)
			return -1;

		return x->get_key();
	}
	node * ceiling(node *x , int key)
	{
		if(x == NULL)
			return NULL;

		if(key == x->get_key())
			return x;
		if(key>x->get_key())
			return ceiling(x->get_right() , key);

		node *t = ceiling(x->get_left() , key);
		if(t!=NULL)
			return t;
		else
			return x;
	}

	void delete_min()
	{
		root = delete_min(root);
	}

	node * delete_min(node *x)
	{
		if(x->get_left() == NULL)
			return x->get_right();

		x->set_left(delete_min(x->get_left()));
		return x;
	}

	void delete_max()
	{
		root = delete_max(root);
	}

	node * delete_max(node *x)
	{
		if(x->get_right() == NULL)
			return x->get_left();

		x->set_right(delete_max(x->get_right()));
		return x;
	}

	void delete_true(int key)
	{
		root = delete_true(root , key);
	}
	node * delete_true(node *x , int key)
	{
		if(x == NULL)
			return NULL;

		if(key<x->get_key())
			x->set_left(delete_true(x->get_left() , key));
		else if(key>x->get_key())
			x->set_right(delete_true(x->get_right() , key));
		else
		{
			if(x->get_right() == NULL)
				return x->get_left();
			if(x->get_left() == NULL)
				return x->get_right();
			node *t = x;
			x = min(t->get_right());
			x->set_right(delete_min(t->get_right()));
			x->set_left(t->get_left());
		}
		return x;
	}

	void keys(node *x , queue<int> q , int lo_key , int hi_key)
	{
		if(x == NULL)
			return ;
		if(lo_key < x->get_key())
			keys(x->get_left() , q , lo_key , hi_key);
		if(lo_key <= x->get_key() && hi_key >= x->get_key())
			q.push(x->get_key());
		if(hi_key > x->get_key())
			keys(x->get_right() , q ,lo_key , hi_key);
	}
	
};

int main(void)
{
	

	return 0;
}