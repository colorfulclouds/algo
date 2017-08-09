#include <stdlib.h>
#include <stdio.h>

#define M 4

void histogram(int *a , int a_length , int m , int *new_array)
{
    int i;
    int j;
    int count;

    for(i=0;i<M;i++)
    {
        count = 0;

        for(j=0;j<a_length;j++)
        {
            if(i == a[j])
            {
                count ++;
            }
        }
        new_array[i] = count;
    }
}

int main(void)
{
    int a[5] = {4,5,2,12,45};
    
    int new_array[M];

    histogram(a , 5 , M , new_array);

    int i;
    for(i=0;i<M;i++)
    {
        printf("%d\n", new_array[i]);
    }
    return 0;
}
