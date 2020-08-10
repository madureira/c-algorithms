#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "Stack.h"

#define ASSERT_NULL(a) assert((a) == NULL)
#define ASSERT_INT_EQUALS(a, b) assert((a) == (b))
#define ASSERT_STRING_EQUALS(a, b) assert(strcmp(((const char*)(a)), ((const char*)(b))) == 0)
#define TEST_DONE printf_s("Test: \"%s\" - success\n", __func__);

void test_create_new_stack()
{
    Stack* stack = create_new_stack();

    ASSERT_INT_EQUALS(stack->capacity, 128);

    free_stack(stack);

    TEST_DONE
}

void test_stack_is_empty()
{
    Stack* stack = create_new_stack();

    ASSERT_INT_EQUALS(stack_is_empty(stack), 1);

    stack_push(stack, 1);

    ASSERT_INT_EQUALS(stack_is_empty(stack), 0);

    free_stack(stack);

    TEST_DONE
}

void test_stack_push()
{
    Stack* stack = create_new_stack();

    stack_push(stack, 1);

    ASSERT_INT_EQUALS(stack->topIndex, 0);

    free_stack(stack);

    TEST_DONE
}

void test_stack_is_full()
{
    Stack* stack = create_new_stack();

    ASSERT_INT_EQUALS(stack_is_full(stack), 0);

    for (int i = 1; i <= STACK_INITIAL_CAPACITY; i++)
    {
        stack_push(stack, i);
    }

    ASSERT_INT_EQUALS(stack_is_full(stack), 1);

    stack_push(stack, 1);

    ASSERT_INT_EQUALS(stack->capacity, STACK_INITIAL_CAPACITY * 2);
    ASSERT_INT_EQUALS(stack_is_full(stack), 0);

    free_stack(stack);

    TEST_DONE
}

void test_stack_peek()
{
    Stack* stack = create_new_stack();

    int item = (int)stack_peek(stack);

    ASSERT_INT_EQUALS(item, 0);

    stack_push(stack, 3);
    stack_push(stack, 2);
    stack_push(stack, 1);

    item = (int)stack_peek(stack);

    ASSERT_INT_EQUALS(item, 1);

    free_stack(stack);

    TEST_DONE
}

void test_stack_peek_string()
{
    Stack* stack = create_new_stack();

    stack_push(stack, "AAA");
    stack_push(stack, "BBB");

    char* item = (char*)stack_peek(stack);

    ASSERT_STRING_EQUALS(item, "BBB");

    free_stack(stack);

    TEST_DONE
}

void test_stack_pop()
{
    Stack* stack = create_new_stack();

    stack_push(stack, 1);
    stack_push(stack, 2);
    stack_push(stack, 3);

    ASSERT_INT_EQUALS(stack->topIndex, 2);

    int item = (int)stack_pop(stack);

    ASSERT_INT_EQUALS(item, 3);
    ASSERT_INT_EQUALS(stack->topIndex, 1);

    item = (int)stack_pop(stack);

    ASSERT_INT_EQUALS(item, 2);
    ASSERT_INT_EQUALS(stack->topIndex, 0);

    free_stack(stack);

    TEST_DONE
}

int main()
{
    printf_s("Stack tests\n\n");

    test_create_new_stack();
    test_stack_is_empty();
    test_stack_push();
    test_stack_is_full();
    test_stack_peek();
    test_stack_peek_string();
    test_stack_pop();

    return 0;
}