#ifndef STACK_H
#define STACK_H

#ifdef __cplusplus
extern "C" {
#endif

#define STACK_INITIAL_CAPACITY 128

    typedef void* StackItem;

    typedef struct Stack
    {
        StackItem top;
        StackItem* items;
        unsigned int capacity;
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
        Adds a new item to the top of the Stack.
    */
    void stack_push(Stack* stack, StackItem item);

#ifdef __cplusplus
}
#endif

#endif // STACK_H