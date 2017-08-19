#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

#define max(a,b) (((a)>(b))?(a):(b));

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

			this->left = this->right = NULL; 
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
		root = NULL;
	}

	~bst()
	{
	}

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

	//member function

	int height()
	{
		int hi = 0;
		height(root , hi);

		return hi;
	}

	void height(node *x , int &hi)
	{
		if(x == NULL)
			hi = 0;
		else
		{
			int hi_left;
			height(x->get_left() , hi_left);
			int hi_right;
			height(x->get_right() , hi_right);

			hi = 1 + max(hi_left , hi_right);
		}
	}

	void put(int key , int value);
	
	node* put(node *x , int key , int value)
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
	
	void print()
	{
		print(root);
	}
	void print(node *x)
	{
		if(x == NULL)
			return ;
		print(x->get_left());
		printf("key:%d value:%d N:%d\n", x->get_key() , x->get_value() , x->get_N());
		print(x->get_right());
	}
};

void bst::put(int key , int value)
{
	root = put(root , key , value);
}


int main(void)
{
	bst root;
	root.put(1,5);
	root.put(2,7);

	root.print();

	cout<<"height:"<<root.height()<<endl;

	return 0;
}