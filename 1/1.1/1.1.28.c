#include <stdlib.h>
#include <stdio.h>


void erase(int *number , int *length)
{
    int i;
    int j;

    for(i=0;i<(*length);i++)
    {
        for(j=0;j<i;j++)
        {
            if(number[i] == number[j])
            {
                number[i] = number[--(*length)];
                i --;
                break ;
            }
        }
    }
}

int main(void)
{
    int number[10] = {1,4,23,12,4,65,12,1,23,4};
    int length = 10;
    erase(number , &length);

    int i;
    for(i=0;i<length;i++)
    {
        printf("%d ", number[i]);
    }

    puts("");


    return 0;
}
