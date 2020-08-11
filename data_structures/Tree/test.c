#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "Tree.h"

#define ASSERT_NULL(a) assert((a) == NULL)
#define ASSERT_INT_EQUALS(a, b) assert((a) == (b))
#define ASSERT_STRING_EQUALS(a, b) assert(strcmp(((const char*)(a)), ((const char*)(b))) == 0)
#define TEST_DONE printf_s("Test: \"%s\" - success\n", __func__);

void test_create_new_tree()
{
    TEST_DONE
}

int main()
{
    printf_s("Tree tests\n\n");

    test_create_new_tree();

    return 0;
}