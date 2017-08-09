#include <stdlib.h>
#include <stdio.h>

int binary(int *number , int key , int low , int high , int depth)
{
    int i;
    for(i=0;i<depth;i++)
    {
        printf(" ");
    }
    printf("low:%d high:%d\n", low , high);

    if(low > high)
        return -1;

    int middle = (low + high) / 2;
    if(key < number[middle])
        return binary(number , key , low , middle - 1 , depth + 1);
    else if(key > number[middle])
        return binary(number , key , middle + 1 , high , depth + 1);
    else
        return middle;
}

int main(void)
{
    int number[10] = {1,2,3,4,5,6,7,8,9,10};
    binary(number , 3 , 0 , 9 , 0);

    return 0;
}
