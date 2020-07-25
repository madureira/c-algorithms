#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "LinkedList.h"

#define ASSERT_NULL(a) assert((a) == NULL)
#define ASSERT_INT_EQUALS(a, b) assert((a) == (b))
#define ASSERT_STRING_EQUALS(a, b) strcmp((a), (b))
#define TEST_DONE printf_s("Test: \"%s\" - success\n", __func__)

static int GLOBAL_TRAVERSE_COUNTER = 0;

static void traverse_callback(Node* node)
{
    GLOBAL_TRAVERSE_COUNTER += (int)node->value;
}

static int int_compare_function(int a, int b)
{
    if (a > b) return 1;
    if (a < b) return -1;
    return 0;
}

static int c_string_compare_function(char* a, char* b)
{
    return strcmp(a, b);
}

void test_linkedlist_create_node()
{
    Node* node = linkedlist_create_node("Some Value");

    ASSERT_STRING_EQUALS(node->value, "Some Value");

    linkedlist_free(node);

    TEST_DONE;
}

void test_linkedlist_prepend()
{
    Node* node = linkedlist_create_node(3);

    node = linkedlist_prepend(node, 2);
    node = linkedlist_prepend(node, 1);

    Node* node2 = node->next;
    Node* node3 = node2->next;

    ASSERT_INT_EQUALS(node->value, 1);
    ASSERT_INT_EQUALS(node2->value, 2);
    ASSERT_INT_EQUALS(node3->value, 3);

    linkedlist_free(node);

    TEST_DONE;
}

void test_linkedlist_append()
{
    Node* node = linkedlist_create_node(1);

    linkedlist_append(node, 2);
    linkedlist_append(node, 3);

    Node* node2 = node->next;
    Node* node3 = node2->next;

    ASSERT_INT_EQUALS(node->value, 1);
    ASSERT_INT_EQUALS(node2->value, 2);
    ASSERT_INT_EQUALS(node3->value, 3);

    linkedlist_free(node);

    TEST_DONE;
}

void test_linkedlist_reverse()
{
    Node* node = linkedlist_create_node(1);

    linkedlist_append(node, 2);
    linkedlist_append(node, 3);

    node = linkedlist_reverse(node);

    Node* node2 = node->next;
    Node* node3 = node2->next;

    ASSERT_INT_EQUALS(node->value, 3);
    ASSERT_INT_EQUALS(node2->value, 2);
    ASSERT_INT_EQUALS(node3->value, 1);

    linkedlist_free(node);

    TEST_DONE;
}

void test_linkedlist_traverse()
{
    Node* node = linkedlist_create_node(1);

    linkedlist_append(node, 2);
    linkedlist_append(node, 3);
    linkedlist_append(node, 4);

    linkedlist_traverse(node, traverse_callback);

    ASSERT_INT_EQUALS(GLOBAL_TRAVERSE_COUNTER, 10);

    GLOBAL_TRAVERSE_COUNTER = 0;

    linkedlist_free(node);

    TEST_DONE;
}

Node* test_linkedlist_remove_first()
{
    Node* node = linkedlist_create_node(1);

    linkedlist_append(node, 2);
    linkedlist_append(node, 3);

    node = linkedlist_remove_first(node);

    Node* node2 = node->next;

    ASSERT_INT_EQUALS(node->value, 2);
    ASSERT_INT_EQUALS(node2->value, 3);
    ASSERT_NULL(node2->next);

    linkedlist_free(node);

    TEST_DONE;
}

void test_linkedlist_remove_last()
{
    Node* node = linkedlist_create_node(1);

    linkedlist_append(node, 2);
    linkedlist_append(node, 3);

    node = linkedlist_remove_last(node);

    Node* node2 = node->next;

    ASSERT_INT_EQUALS(node->value, 1);
    ASSERT_INT_EQUALS(node2->value, 2);
    ASSERT_NULL(node2->next);

    linkedlist_free(node);

    TEST_DONE;
}

void test_linkedlist_search()
{
    Node* node = linkedlist_create_node("A");

    linkedlist_append(node, "B");
    linkedlist_append(node, "C");

    Node* found = linkedlist_search(node, "B");
    ASSERT_STRING_EQUALS(found->value, "B");

    Node* notFound = linkedlist_search(node, "Z");
    ASSERT_NULL(notFound);

    linkedlist_free(node);

    TEST_DONE;
}

void test_linkedlist_sort()
{
    Node* node = linkedlist_create_node(3);

    linkedlist_append(node, 2);
    linkedlist_append(node, 1);
    linkedlist_append(node, 2);

    node = linkedlist_sort(node, int_compare_function);

    Node* node2 = node->next;
    Node* node3 = node2->next;
    Node* node4 = node3->next;

    ASSERT_INT_EQUALS(node->value, 1);
    ASSERT_INT_EQUALS(node2->value, 2);
    ASSERT_INT_EQUALS(node3->value, 2);
    ASSERT_INT_EQUALS(node4->value, 3);

    linkedlist_free(node);

    TEST_DONE;
}

void test_linkedlist_sort_strings()
{
    Node* node = linkedlist_create_node("A");

    linkedlist_append(node, "B");
    linkedlist_append(node, "A");
    linkedlist_append(node, "C");

    node = linkedlist_sort(node, c_string_compare_function);

    Node* node2 = node->next;
    Node* node3 = node2->next;
    Node* node4 = node3->next;

    ASSERT_STRING_EQUALS(node->value, "A");
    ASSERT_STRING_EQUALS(node2->value, "A");
    ASSERT_STRING_EQUALS(node3->value, "B");
    ASSERT_STRING_EQUALS(node4->value, "C");

    linkedlist_free(node);

    TEST_DONE;
}

int main()
{
    printf_s("LinkedList tests\n\n");

    test_linkedlist_create_node();
    test_linkedlist_prepend();
    test_linkedlist_append();
    test_linkedlist_reverse();
    test_linkedlist_traverse();
    test_linkedlist_remove_first();
    test_linkedlist_remove_last();
    test_linkedlist_search();
    test_linkedlist_sort();
    test_linkedlist_sort_strings();

    return 0;
}