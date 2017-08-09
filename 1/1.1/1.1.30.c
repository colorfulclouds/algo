#include <stdlib.h>
#include <stdio.h>

#define N 10

int gcd(int p , int q)
{
    if(q == 0)
        return p;
    int r=p%q;
    return gcd(q , r);
}

void bool_array()
{
    int array[N][N];
    int i;
    int j;

    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            int result = gcd(i , j);
            if( (result == 0) || (result == 1))
            {
                array[i][j] = 1;
            }
            else
            {
                array[i][j] = 0;
            }
        }
    }

    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%d ", array[i][j]);
        }

        puts("");
    }
}

int main(void)
{
    bool_array();

    return 0;
}
