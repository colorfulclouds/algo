#include <iostream>
#include <stack>
#include <cstdlib>
#include <cstring>

using namespace std;

bool is_op(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/' ;
}

int main(void)
{
	char answer[] = "153*+241-*-";
	int i;
	int length = strlen(answer);
	stack<double> solution;
	
	for(i=0;i<length;i++)
	{
		if(is_op(answer[i]))
		{
			double n_2 = solution.top();
			solution.pop();
			double n_1 = solution.top();
			solution.pop();

			switch(answer[i])
			{
			case '+':
				solution.push(n_1 + n_2);
				break;
				
			case '-':
				solution.push(n_1 - n_2);
				break;
				
			case '*':
				solution.push(n_1 * n_2);
				break;
				
			case '/':
				solution.push(n_1 / n_2);
				break;
			}

		}
		else
		{
			
			solution.push(answer[i]-'0');

		}

		
	}
printf("%.3lf\n", solution.top());

	return 0;
}