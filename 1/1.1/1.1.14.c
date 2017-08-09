#include <stdlib.h>
#include <stdio.h>

#define LIMIT 0xffffffff

int pow_new(int times)
{
    int i;
    int result = 1;

    for(i=0;i<times;i++)
    {
        result *= 2;
    }

    return result;
}

int main(void)
{
    int N;

    scanf("%d", &N);

    int i;
    for(i=0;i<LIMIT;i++)
    {
        if(pow_new(i) > N)
        {
            printf("%d\n", i - 1);
            break ;
        }
    }


    return 0;
}
