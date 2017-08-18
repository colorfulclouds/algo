#include <iostream>
#include <cstdlib>

using namespace std;

#define CMAX 10

class array_st
{
private:
	int key[CMAX];
	int value[CMAX];
	int count;

public:
	array_st()
	{
		count = 0;
	}

	~array_st()
	{
	}

	int size()
	{
		return count;
	}

	int find(int key)
	{
		int i;

		for(i=0;i<count;i++)
		{
			if(this->key[i] == key)
				return i;
		}

		return -1;
	}

	void put(int key , int value)
	{
		int pos = find(key);
		
		if(pos == -1)
		{
			//new key
			this->key[count] = key;
			this->value[count] = value;

			count ++;
		}
		else
		{
			//update value
			this->value[pos] = value;
		}
	}

	int get(const int key)
	{
		int pos = find(key);
		if(pos == -1)
			return -1;
		else
			return this->value[pos];
	}

	void print()
	{
		int i;

		for(i=0;i<count;i++)
		{
			printf("key:%d value:%d\n", key[i] , value[i]);
		}
	}

	int contains(int key)
	{
		return find(key) ;
	}

	int is_empty()
	{
		return count == 0;
	}

	int max_key()
	{
		if(is_empty())
			return -1;

		int i;
		int max = 0;


		for(i=1;i<count;i++)
		{
			if(key[i] > key[max])
				max = i;
		}

		return key[max];
	}

	int min_key()
	{
		if(is_empty())
			return -1;
		
		int i;
		int min = 0;
		
		
		for(i=1;i<count;i++)
		{
			if(key[i] < key[min])
				min = i;
		}
		
		return key[min];
	}
};

int main(void)
{
	array_st inst;

	inst.put(5 , 1);
	inst.put(5 , 3);
	inst.put(2 , 5);
	inst.put(4 , 6);
	inst.put(2 , 1);
	inst.put(8 , 1);

	inst.print();

	return 0;
}