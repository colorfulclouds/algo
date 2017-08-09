#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 5
#define N 6

//array trans
/*
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
*/

double dot(double *x , double *y , int length)
{
    double result = 0.0;
    int i;

    for(i=0;i<length;i++)
    {
        result = result + x[i] * y[i];
    }

    return result;
}

void mult(double *a[] , int a_row , int univ , double *b[] , int b_col , double *result[])
{
    int i;
    int j;
    int k;
    double temp;

    for(i=0;i<a_row;i++)
    {
        for(j=0;j<b_col;j++)
        {
            temp = 0.0;

            for(k=0;k<univ;k++)
            {
                temp = temp + a[i][k] * b[k][j];
            }
            result[i][j] = temp;
        }
    }
}
//
//array * matrix
//martix * array
//martix=array[n][1]
int main(void)
{
    double x[3]={1.2 , 2.3 , 3.1};
    double y[3]={2.1 , 2.3 , 2.1};
    printf("%lf\n", dot(x , y ,3));



    return 0;
}
