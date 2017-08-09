#include <stdlib.h>
#include <stdio.h>

int binary(int *number , int key , int low , int high , int depth)
{
    int i;
/*
    for(i=0;i<depth;i++)
    {
        printf(" ");
    }
    */
//    printf("low:%d high:%d\n", low , high);

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
    int number_a[1000];
    int number_b[1000];
    int i;
    int j;

    srand((unsigned int)time(NULL));
    for(i=0;i<1000;i++)
    {
        number_a[i] = random() % ( 999999 - 100000 + 1 ) + 100000;
        number_b[i] = random() % 900000 + 100000;

//      printf("number_a:%d number_b:%d\n", number_a[i] , number_b[i]);
    }

    int count = 0;
    int pos;
    for(i=0;i<1000;i++)
    {
        for(j=0;j<1000;j++)
        {
            pos = binary(number_b , number_a[i] , 0 , 999 , 0);
            if( pos != -1)
            {
                printf("same!pos in a:%d pos in b:%d number:%d\n", i , pos , number_a[i] );
                count ++;
                break;
            }
        }
    }

    printf("count:%d\n", count);

    return 0;
}
