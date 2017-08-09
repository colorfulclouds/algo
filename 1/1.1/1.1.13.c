#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 5
#define N 6


int main(void)
{
    int src_array[M][N];
    int i,j;

    srand((unsigned int)time(NULL));
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            src_array[i][j] = random()%100;
        }
    }

    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%-3d  ", src_array[i][j]);
        }

        printf("\n");
    }
puts("==");
    int des_array[N][M];

    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            des_array[i][j] = src_array[j][i];
        }
    }
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            printf("%-3d  ", des_array[i][j]);
        }

        printf("\n");
    }


    return 0;
}
