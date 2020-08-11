#include "Stack.h"
#include <stdlib.h>

static int __stack_increase_capacity(Stack* stack);

Stack* create_new_stack()
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));

    if (stack == NULL)
    {
        return NULL;
    }

    stack->capacity = STACK_INITIAL_CAPACITY;
    stack->topIndex = -1;
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

unsigned int stack_is_empty(Stack* stack)
{
    if (stack == NULL || stack->topIndex > -1)
    {
        return 0;
    }

    return 1;
}

unsigned int stack_is_full(Stack* stack)
{
    if (stack == NULL)
    {
        return 0;
    }

    if (stack->topIndex == (stack->capacity - 1))
    {
        return 1;
    }

    return 0;
}

void stack_push(Stack* stack, StackItem item)
{
    if (stack != NULL)
    {
        if (stack_is_full(stack) == 1)
        {
            if (__stack_increase_capacity(stack) == 0)
            {
                return;
            }
        }
        stack->items[++stack->topIndex] = item;
    }
}

StackItem stack_peek(Stack* stack)
{
    if (stack_is_empty(stack) == 1)
    {
        return NULL;
    }

    return stack->items[stack->topIndex];
}

StackItem stack_pop(Stack* stack)
{
    if (stack_is_empty(stack) == 1)
    {
        return NULL;
    }

    return stack->items[stack->topIndex--];
}

int __stack_increase_capacity(Stack* stack)
{
    unsigned int newSize = stack->capacity * 2;
    StackItem* value = realloc(stack->items, sizeof(StackItem) * newSize);

    if (value == NULL)
    {
        return STACK_FAILURE;
    }

    stack->items = value;
    stack->capacity = newSize;

    return STACK_SUCCESS;
}