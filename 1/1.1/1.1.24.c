#include <stdlib.h>
#include <stdio.h>

int get_max(int p , int q)
{
    printf("p:%d q:%d\n", p , q);
    if(q == 0)
        return p;
    int r = p % q;
    return get_max(q , r);
}

int main(int argc , char *argv[])
{
    printf("result:%d\n", get_max(atoi(argv[1]), atoi(argv[2])) );

    return 0;
}
