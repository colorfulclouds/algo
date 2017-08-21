#include <iostream>
#include <cstdlib>

using namespace std;

#define RED true
#define BLACK false

class node
{
private:
	int key;
	int value;
	node *left;
	node *right;
	int N;
	bool color;

public:
	node(int key , int value , int N , bool color)
	{
		this->key = key;
		this->value = value;
		this->N = N;
		this->color = color;
	}
	~node()
	{
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

	bool get_color()
	{
		return color;
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

	void set_color(bool color)
	{
		this->color = color;
	}

};

class tree
{
private:
	node *root;

public:
	tree()
	{
		root = NULL;
	}
	~tree()
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

	///////////////
	node * rotate_left(node *h)
	{
		node *x = h->get_right();
		h->set_right(x->get_left());
		x->set_left(h);
		x->set_color(h->get_color());
		h->set_color(RED);
		x->set_N(h->get_N());
		h->set_N(1 + size(h->get_left()) + size(h->get_right()));

		return x;
	}

	node * rotate_right(node *h)
	{
		node *x = h->get_left();
		h->set_left(x->get_right());
		x->set_right(h);
		x->set_color(h->get_color());
		h->set_color(RED);
		x->set_N(h->get_N());
		h->set_N(1 + size(h->get_left()) + size(h->get_right()));

		return x;
	}

	bool is_red(node *x)
	{
		if(x == NULL)
			return BLACK;
		
		return x->get_color() == RED;
	}

	void flip_colors(node *x)
	{
		x->set_color(RED);
		x->get_left()->set_color(BLACK);
		x->get_right()->set_color(BLACK);
	}
	/////////////////

	void put(int key , int value)
	{
		root = put(root , key , value);
		root->set_color(BLACK);
	}
	node * put(node *h , int key , int value)
	{
		if(h == NULL)
			return new node(key , value , 1 , RED);

		if(key < h->get_key())
			h->set_left(put(h->get_left() , key , value));
		else if(key > h->get_key())
			h->set_right(put(h->get_right() , key , value));
		else
			h->set_value(value);

		if(is_red(h->get_right()) && !is_red(h->get_left()))
			h = rotate_left(h);
		if(is_red(h->get_left()) && is_red(h->get_left()->get_left()))
			h = rotate_right(h);
		if(is_red(h->get_left()) && is_red(h->get_right()))
			flip_colors(h);

		h->set_N( size(h->get_left()) + size(h->get_right()) + 1);

		return h;
			
	}
};

int main(void)
{

	return 0;
}