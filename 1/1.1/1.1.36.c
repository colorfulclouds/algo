#include <stdlib.h>
#include <stdio.h>


void init(int *array , int length)
{
    int i;

    for(i=0;i<length;i++)
    {
        array[i] = i;
    }
}

void luan_xu(int *array , int length)
{
    array[0] ^= array[length - 1];
    array[length - 1] ^= array[0];
    array[0] ^= array[length - 1];
}

//ShuffleTest
int main(int argc , char *argv[])
{
    int m = atoi(argv[1]);
    int *a = (int *)malloc(m);
    int N = atoi(argv[2]);
    int i;
    int j;
    int k;

    int **result = (int **)malloc(sizeof(int *) * m);
    for(i=0;i<m;i++)
    {
        result[i] = (int *)malloc(sizeof(int) * m);
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            result[i][j] = 0;
        }
    }

    for(k=0;k<N;k++)
    {
        init(a , m);
        luan_xu(a , m);
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<m;j++)
            {
                if(a[j] == i)
                {
                    result[i][j] += 1;
                }
            }
        }

    }

    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d ", result[i][j]);
        }

        puts("");
    }

    for(i=0;i<m;i++)
        free(result[i]);
    free(result);

    free(a);
    return 0;
}
