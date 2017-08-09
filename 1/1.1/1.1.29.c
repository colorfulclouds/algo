#include <stdlib.h>
#include <stdio.h>

int count(int *number , int length , int key)
{
    int count = 0;
    int i;

    for(i=0;i<length;i++)
    {
        if(number[i] == key)
            count ++;
    }

    return count;
}

int rank(int *number , int length , int key)
{
    int count = 0;
    int i;

    for(i=0;i<length;i++)
    {
        if(number[i] < key)
            count ++;
    }

    return count;
}

int main(void)
{
    int number[10]={1,23,45,23,12,45,232,12,12,3};

    printf("count:%d\n", count(number , 10 , 5));
    printf("rank:%d\n", rank(number , 10 , 5));

    return 0;
}
