#include <iostream>
#include <cstdlib>

using namespace std;

class hash_array
{
private:
	int N;
	int M;
	int *key;
	int *value;

public:
	hash_array(int M = 16)
	{
		N = 0;
		M = 16;

		key = new int[M];
		value = new int[M];

		int i;
		for(i=0;i<M;i++)
			key[i] = value[i] = -1;
	}
	~hash_array()
	{
		delete [] key;
		delete [] value;
	}

	//member function
	int hash(int key)
	{
		return key % M;
	}

	void resize(int size)
	{
		hash_array t(size);
		
		int i;
		for(i=0;i<M;i++)
		{
			if(key[i] != -1)
				t.put(key[i] , value[i]);
		}

		key = t.key;
		value = t.value;
		M = t.M;
	}

	void put(int key , int value)
	{
		if(N >= M/2)
			resize(2*M);

		int i;
		for(i=hash(key) ; this->key[i] != -1 ; i=(i+1)%M)
		{
			if(this->key[i] == key)
			{
				this->value[i] = value;
				return ;
			}
		}

		this->key[i] = key;
		this->value[i] = value;

		this->N ++;
	}

	int get(int key)
	{
		int i;

		for(i=hash(key) ; this->key[i]!=-1 ; i=(i+1)%M)
		{
			if(this->key[i] == key)
				return this->value[i];
		}

		return -1;
	}

	bool contains(int key)
	{
		return get(key) == -1;
	}

	void delete_node(int key)
	{
		if(contains(key))
			return ;

		int i = hash(key);

		for(;this->key[i] != key ; i=(i+1)%M)
			;

		this->key[i] = this->value[i] = -1;

		i=(i+1)%M;
		
		int key_t;
		int value_t;

		while(this->key[i] != -1)
		{
			key_t = this->key[i];
			value_t = this->value[i];

			this->key[i] = this->value[i] = -1;

			this->N --;

			put(key_t , value_t);

			i=(i+1)%M;
		}
		this->N --;

		if(N>0 && N==M/8)
			resize(M/2);
	}
};

int main(void)
{


	return 0;
}