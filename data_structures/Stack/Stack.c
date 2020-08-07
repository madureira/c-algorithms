#include "Stack.h"
#include <stdlib.h>

Stack* create_new_stack()
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));

    if (stack == NULL)
    {
        return NULL;
    }

    stack->capacity = STACK_INITIAL_CAPACITY;
    stack->top = NULL;
    stack->items = (StackItem*)malloc(stack->capacity * sizeof(StackItem));

    if (stack->items == NULL)
    {
        free(stack);
        return NULL;
    }

    return stack;
}

void free_stack(Stack* stack)
{
    if (stack != NULL)
    {
        free(stack->items);
        free(stack);
        stack = NULL;
    }
}

void stack_push(Stack* stack, StackItem item)
{

}
