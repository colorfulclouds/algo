#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void d2b(int d_number , char *b_number , int b_bit)
{
    memset(b_number , (int)'0' , b_bit);
    b_number[0] = d_number > 0 ? '0' : (d_number *= (-1) , '1');
    b_number[b_bit - 1] = '\0';

    int pointer = b_bit - 2;
    char bit[2] = {'0' , '1'};

    while(d_number != 0)
    {
        b_number[pointer --] = bit[d_number % 2];
        d_number /= 2;
    }

    puts(b_number);
}


int main(void)
{
    int number;

    char number_str[sizeof(int) * 8 + 2];
    scanf("%d", &number);

    d2b(number , number_str , sizeof(int) * 8 + 2);


    return 0;
}
