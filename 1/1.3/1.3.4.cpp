#include <iostream>
#include <string>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;


int main(int argc , char *argv[])
{
    if(argc < 2)
    {
        printf("no para\n");
        exit(EXIT_FAILURE);
    }
    stack<char> bracket;
    int i;
    int length = strlen(argv[1]);

    for(i=0;i<length;i++)
    {
        if(argv[1][i] == '('\
        || argv[1][i] == '[' \
        || argv[1][i] == '{')
        {
            bracket.push(argv[1][i]);
        }
        else
        {
            if(bracket.size() == 0)
            {
                printf("false\n");
                return 1;
            }
            else
            {
                char c = bracket.top();
                bracket.pop();
                switch(argv[1][i])
                {
                    case ']':
                    if(c != '[')
                    {
                        printf("false\n");
                        return 1;          
                    }
                    break;

                    case ')':
                    if(c != '(')
                    {
                        printf("false\n");
                        return 1;
                    }
                    break;

                    case '}':
                    if(c != '{')
                    {
                        printf("false\n");
                        return 1;
                    }
                    break;
                }
            }
        }
    }

    if(bracket.size())
    {
        printf("false\n");
        return 1;
    }

    printf("true\n");
    return 0;
}
