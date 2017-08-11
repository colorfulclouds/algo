#include <iostream>
#include <string>
#include <cstdio>
#include <stack>
using namespace std;

int main(void)
{
    string ari("1+2)*3-4)*5-6)))");
    stack<string> num;
    stack<string> op;

    int i;
    int length = ari.size();

    for(i=0;i<length;i++)
    {
        if((ari[i] == '+') || (ari[i] == '-') || (ari[i] == '*') || (ari[i] == '/' ) )
        {
            string temp(1 , ari[i]);
            op.push(temp);
        }
        else if(isdigit(ari[i]))
        {
            string temp(1 , ari[i]);
            num.push(temp);
        }
        else
        {
            string a,b,c;
            b=num.top();
            num.pop();
            a=num.top();
            num.pop();
            c=op.top();
            op.pop();

            string temp("(");
            temp.append(a);
            temp.append(c);
            temp.append(b);

            string br(1 , ')');
            temp.append(br);

            num.push(temp);
        }
    }

    printf("%s\n", num.top().c_str());


    return 0;
}
