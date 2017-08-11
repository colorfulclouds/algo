#include <iostream>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

bool is_op(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}

bool compare(char c_1 , char c_2)
{
	switch(c_1)
	{
	case '+':
		{
			switch(c_2)
			{
			case '+': return true;
			case '-': return true;
			case '*': return false;
			case '/': return false;
			case '#': return true;
			}
		}
		
	case '-':
		{
			switch(c_2)
			{
			case '+': return true;
			case '-': return true;
			case '*': return false;
			case '/': return false;
			case '#': return true;
			}
		}
		
	case '*':
		{
			switch(c_2)
			{
			case '+': return true;
			case '-': return true;
			case '*': return true;
			case '/': return true;
			case '#': return true;
			}
		}
		
	case '/':
		{
			switch(c_2)
			{
			case '+': return true;
			case '-': return true;
			case '*': return true;
			case '/': return true;
			case '#': return true;
			}
		}

	case '#':
		{
			switch(c_2)
			{
			case '+': return false;
			case '-': return false;
			case '*': return false;
			case '/': return false;
			case '#': return false;
			}
		}
	}
}

int main(void)
{
	stack<char> value;

	value.push('#');

	char answer[] = "(a-b)*(c-a)+b/(e+f)";

	int length = strlen(answer);
	int i;

	for(i=0 ; i<length ; i ++)
	{	
		if(islower(answer[i]))
		{
			printf("%c", answer[i]);
		}
		else if(answer[i] == '(')
		{
			value.push(answer[i]);
		}
		else if(answer[i] == ')')
		{
			while(value.top() != '(')
			{
				printf("%c", value.top());
				value.pop();
			}
			value.pop();
		}
		else if(is_op(answer[i]))
		{
			if(value.top() != '#')
			{
				while(value.top() != '(' && value.top() != '#')
				{
					if(compare(value.top() , answer[i]))
					{
						printf("%c", value.top());
						value.pop();
					}
					else
					{
						break;
					}
				}
			}
			
			value.push(answer[i]);
		}
	}
	
	while(value.top() != '#')
	{
		printf("%c", value.top());
		value.pop();
	}
	printf("\n%d\n", value.size());

	return 0;
}