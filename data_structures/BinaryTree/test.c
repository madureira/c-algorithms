#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "BinaryTree.h"

#define ASSERT_NULL(a) assert((a) == NULL)
#define ASSERT_INT_EQUALS(a, b) assert((a) == (b))
#define ASSERT_STRING_EQUALS(a, b) assert(strcmp(((const char*)(a)), ((const char*)(b))) == 0)
#define TEST_DONE printf_s("Test: \"%s\" - success\n", __func__);

void test_binarytree_create_node()
{
    BinaryTreeNode* node = binarytree_create_node(1);

    ASSERT_INT_EQUALS(node->value, 1);
    ASSERT_NULL(node->left);
    ASSERT_NULL(node->right);

    binarytree_free(node);

    TEST_DONE
}

void test_binarytree_insert_left()
{
    BinaryTreeNode* node = binarytree_create_node(1);

    binarytree_insert_left(node, 2);

    ASSERT_INT_EQUALS(node->left->value, 2);
    ASSERT_NULL(node->right);

    binarytree_free(node);

    TEST_DONE
}

void test_binarytree_insert_right()
{
    BinaryTreeNode* node = binarytree_create_node(1);

    binarytree_insert_right(node, 2);

    ASSERT_INT_EQUALS(node->right->value, 2);
    ASSERT_NULL(node->left);

    binarytree_free(node);

    TEST_DONE
}

int main()
{
    printf_s("BinaryTree tests\n\n");

    test_binarytree_create_node();
    test_binarytree_insert_left();
    test_binarytree_insert_right();

    return 0;
}