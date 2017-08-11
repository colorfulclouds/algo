#include "stack.h"

int main(void)
{
    stack_t *stack = (stack_t *)malloc(sizeof(stack_t));
    init(stack);

    int number_1;
    number_1=1;
    push(stack , number_1);
    
    int number_2;
    number_2 = 2;
    push(stack , number_2);

    print(stack);

    destroy(stack);

    return 0;
}
