#ifndef STACK_H
#define STACK_H

#ifdef __cplusplus
extern "C" {
#endif

#define STACK_SUCCESS 1
#define STACK_FAILURE 0
#define STACK_INITIAL_CAPACITY 128

    typedef void* StackItem;

    typedef struct Stack
    {
        unsigned int capacity;
        int topIndex;
        StackItem* items;
    } Stack;

    /*
        Creates a new empty Stack.
    */
    Stack* create_new_stack();

    /*
        Frees a given Stack pointer.
    */
    void free_stack(Stack* stack);

    /*
        Checks if Stack is completely empty.
    */
    unsigned int stack_is_empty(Stack* stack);

    /*
        Checks if Stack is completely full.
    */
    unsigned int stack_is_full(Stack* stack);

    /*
        Adds a new item to the top of the Stack.
    */
    void stack_push(Stack* stack, StackItem item);

    /*
        Gets the item on top of the Stack.
    */
    StackItem stack_peek(Stack* stack);

    /*
        Remove an item from Stack and return it.
    */
    StackItem stack_pop(Stack* stack);

#ifdef __cplusplus
}
#endif

#endif // STACK_H