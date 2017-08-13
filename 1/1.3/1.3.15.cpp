#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <string>

using namespace std;

int main(int argc , char *argv[])
{
	int k;
	//k = atoi(argv[1]);
	scanf("%d", &k);

	queue<char> x;
	string str("adkjsfd") ;
	int i;
	int length = str.size();

	for(i=0;i<length;i++)
	{
		x.push(str[i]);
	}

	int pos = length - k;

	for(i=0;i<pos;i++)
	{
		x.pop();
	}

	printf("%c\n", x.front());

	return 0;
}