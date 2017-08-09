#include <stdlib.h>
#include <stdio.h>
#include <math.h>//gcc 1.1.20 -lm

//ln(n!)=ln(n*(n-1)*(n-2).....*1)=ln(n)+ln(n-1)+.....ln(1)

double cal(int n)
{
    if(n == 1 || n == 0)
    {
        return 1;
    }


    return n * cal(n-1);
}


int main(void)
{
    int n;
    scanf("%d", &n);

    printf("result:%lf\n", log(cal(n)));

    return 0;
}
