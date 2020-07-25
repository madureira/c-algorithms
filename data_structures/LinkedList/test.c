#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "LinkedList.h"

#define ASSERT_INT_EQUALS(a, b) assert((a) == (b))
#define ASSERT_STRING_EQUALS(a, b) strcmp((a), (b))
#define TEST_DONE printf_s("Test: \"%s\" - success\n", __func__)

void test_linkedlist_create_node()
{
    Node* node = linkedlist_create_node("Some Value");

    ASSERT_STRING_EQUALS(node->value, "Some Value");

    linkedlist_free(node);

    TEST_DONE;
}

void test_linkedlist_prepend()
{
    Node* node3 = linkedlist_create_node(3);

    Node* node2 = linkedlist_prepend(node3, 2);
    Node* node = linkedlist_prepend(node2, 1);

    int i = 1;
    while (node != NULL)
    {
        ASSERT_INT_EQUALS(node->value, i);
        node = node->next;
        i++;
    }

    linkedlist_free(node);

    TEST_DONE;
}

void test_linkedlist_append()
{
    Node* node = linkedlist_create_node(1);

    Node* node2 = linkedlist_append(node, 2);
    Node* node3 = linkedlist_append(node2, 3);

    int i = 1;
    while (node != NULL)
    {
        ASSERT_INT_EQUALS(node->value, i);
        node = node->next;
        i++;
    }

    linkedlist_free(node);

    TEST_DONE;
}

int main()
{
    printf_s("LinkedList tests\n\n");

    test_linkedlist_create_node();
    test_linkedlist_prepend();
    test_linkedlist_append();

    return 0;
}