#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "Graph.h"

#define ASSERT_NULL(a) assert((a) == NULL)
#define ASSERT_INT_EQUALS(a, b) assert((a) == (b))
#define ASSERT_STRING_EQUALS(a, b) assert(strcmp(((const char*)(a)), ((const char*)(b))) == 0)
#define TEST_DONE printf_s("Test: \"%s\" - success\n", __func__);

void test_graph_create_node()
{
    TEST_DONE
}

int main()
{
    printf_s("Graph tests\n\n");

    test_graph_create_node();

    return 0;
}