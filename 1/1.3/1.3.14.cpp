#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

template<class T>
class queue
{
	private:
		T *item;
		int count;
		int N;

		int front;
		int rear;

	public:
		queue(int N);
		~queue();
		
		void enqueue(T item)
		{
			if(count * 2 > this->N)
			{
				this->N *= 2;
				resize(this->N);
			}
			this->item[front ++] = item;
			count ++;
		}
		T dequeue()
		{
			count --;
			return this->item[rear ++];
		}

		void resize(int N)
		{
			T *new_item = new T[N];

			int i;
			for(i=rear;i<front;i++)
			{
				new_item[i] = item[i];
			}

			delete(item);
			item = new_item;
		}

		void print()
		{
			int i;

			for(i=rear;i<front;i++)
			{
				printf("%d ", item[i]);
			}
			printf("\n");
		}

		int sizequeue()
		{
			return N;
		}
};

template<class T>
queue<T>::queue(int N)
{
	this->N = N;
	this->count = 0;
	
	this->item = new T[this->N];

	this->front = 0;
	this->rear = 0;
}

template<class T>
queue<T>::~queue()
{
	delete item;
}

int main(void)
{
	queue<int> inst(3);
	inst.enqueue(1);
	inst.enqueue(2);
	inst.enqueue(3);

	inst.dequeue();

	inst.print();

	printf("size:%d\n", inst.sizequeue());


	return 0;
}