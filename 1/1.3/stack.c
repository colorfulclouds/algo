#include "stack.h"


void init(stack_t *stack)
{
    /*stack = (stack_t *)malloc(sizeof(stack_t));
    if(stack == NULL)
    {
        exit(EXIT_FAILURE);
    }*/
    stack->count = 0;
}

void push(stack_t *stack , int item)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->item = item;
    
    new_node->next = (stack->head);
    stack->head = new_node;

    stack->count ++;
}

int pop(stack_t *stack)
{
    int item;
    item = stack->head->item;
    stack->head = (stack->head->next);
    stack->count --;

    return item;
}


int size(stack_t *stack)
{
    return stack->count;
}

int is_empty(stack_t *stack)
{
    return stack->count == 0;
}

int is_full(stack_t *stack)
{
    ;//impossible
}

void print(stack_t *stack)
{
    struct node *p;

    for(p=stack->head;p;p=p->next)
    {
        printf("%d ", p->item);
    }
    printf("\n");
}

void destroy(stack_t *stack)
{
    free(stack);
}

int peek(stack_t *stack)
{
    return stack->head->item;
}
