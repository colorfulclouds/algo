#include <stdio.h>

int mystery(int a , int b)
{
    if(b == 0)
    {
        return 1;
    }
    if(b % 2 == 0)
    {
        return mystery(a * a , b/2);
    }
    return mystery(a*a,b/2) * a;
}

int main(void)
{
    printf("%d\n", mystery(2,25));
    printf("%d\n", mystery(3,11));
    printf("%d\n", mystery(8,3));


    return 0;
}
