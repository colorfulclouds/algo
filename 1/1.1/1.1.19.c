#include <stdlib.h>
#include <stdio.h>

#define LIMIT 20

void f()
{
    int array[LIMIT];
    array[0] = array[1] = 1;

    int i;
    for(i=2;i<LIMIT;i++)
    {
        array[i] = array[i-1] + array[i-2];
    }

    for(i=0;i<LIMIT;i++)
    {
        printf("%d ", array[i]);
    }

    //puts("\n");
}

int main(void)
{
    f();

    return 0;
}
