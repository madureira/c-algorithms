#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "Stack.h"

#define ASSERT_NULL(a) assert((a) == NULL)
#define ASSERT_INT_EQUALS(a, b) assert((a) == (b))
#define ASSERT_STRING_EQUALS(a, b) assert(strcmp((a), (b)) == 0)
#define TEST_DONE printf_s("Test: \"%s\" - success\n", __func__);

void test_create_new_stack()
{
    Stack* stack = create_new_stack();

    ASSERT_INT_EQUALS(stack->capacity, 128);

    free_stack(stack);

    TEST_DONE
}

void test_stack_push()
{
    Stack* stack = create_new_stack();

    stack_push(stack, 1);

    free_stack(stack);

    TEST_DONE
}

int main()
{
    test_create_new_stack();
    test_stack_push();

    return 0;
}