#ifndef HEAD
#define HEAD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int item;
    struct node *next;
};

typedef struct stack
{
    struct node *head;
    int count;
}stack_t;

void init(stack_t *stack);
void push(stack_t *stack , int item);
int pop(stack_t *stack);
int size(stack_t *stack);
int is_empty(stack_t *stack);
int is_full(stack_t *stack);
void print(stack_t *stack);
void destory(stack_t *stack);
int peek(stack_t *stack);

#endif
