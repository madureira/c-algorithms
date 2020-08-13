#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "BinaryTree.h"

#define ASSERT_NULL(a) assert((a) == NULL)
#define ASSERT_INT_EQUALS(a, b) assert((a) == (b))
#define ASSERT_STRING_EQUALS(a, b) assert(strcmp(((const char*)(a)), ((const char*)(b))) == 0)
#define TEST_DONE printf_s("Test: \"%s\" - success\n", __func__);

static unsigned int GLOBAL_TRAVERSE_INDEX = 0;
static int GLOBAL_TRAVERSE_VISIT_ORDER[7] = { 0 };

static reset_traversal_data()
{
    GLOBAL_TRAVERSE_INDEX = 0;
    for (int i = 0; i < 7; i++)
    {
        GLOBAL_TRAVERSE_VISIT_ORDER[i] = 0;
    }
}

static void traverse_callback(BinaryTreeNode* node)
{
    GLOBAL_TRAVERSE_VISIT_ORDER[GLOBAL_TRAVERSE_INDEX] = (int)node->value;
    GLOBAL_TRAVERSE_INDEX++;
}

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

void test_binarytree_inorder_traversal()
{
    BinaryTreeNode* node = binarytree_create_node(1);
    
    BinaryTreeNode* node2 = binarytree_insert_left(node, 2);
    binarytree_insert_left(node2, 4);
    binarytree_insert_right(node2, 5);

    BinaryTreeNode* node3 = binarytree_insert_right(node, 3);
    binarytree_insert_left(node3, 6);
    binarytree_insert_right(node3, 7);

    binarytree_inorder_traversal(node, traverse_callback);

    ASSERT_INT_EQUALS(GLOBAL_TRAVERSE_VISIT_ORDER[0], 4);
    ASSERT_INT_EQUALS(GLOBAL_TRAVERSE_VISIT_ORDER[1], 2);
    ASSERT_INT_EQUALS(GLOBAL_TRAVERSE_VISIT_ORDER[2], 5);
    ASSERT_INT_EQUALS(GLOBAL_TRAVERSE_VISIT_ORDER[3], 1);
    ASSERT_INT_EQUALS(GLOBAL_TRAVERSE_VISIT_ORDER[4], 6);
    ASSERT_INT_EQUALS(GLOBAL_TRAVERSE_VISIT_ORDER[5], 3);
    ASSERT_INT_EQUALS(GLOBAL_TRAVERSE_VISIT_ORDER[6], 7);

    binarytree_free(node);

    reset_traversal_data();

    TEST_DONE
}

void test_binarytree_preorder_traversal()
{
    BinaryTreeNode* node = binarytree_create_node(1);

    BinaryTreeNode* node2 = binarytree_insert_left(node, 2);
    binarytree_insert_left(node2, 4);
    binarytree_insert_right(node2, 5);

    BinaryTreeNode* node3 = binarytree_insert_right(node, 3);
    binarytree_insert_left(node3, 6);
    binarytree_insert_right(node3, 7);

    binarytree_preorder_traversal(node, traverse_callback);

    ASSERT_INT_EQUALS(GLOBAL_TRAVERSE_VISIT_ORDER[0], 1);
    ASSERT_INT_EQUALS(GLOBAL_TRAVERSE_VISIT_ORDER[1], 2);
    ASSERT_INT_EQUALS(GLOBAL_TRAVERSE_VISIT_ORDER[2], 4);
    ASSERT_INT_EQUALS(GLOBAL_TRAVERSE_VISIT_ORDER[3], 5);
    ASSERT_INT_EQUALS(GLOBAL_TRAVERSE_VISIT_ORDER[4], 3);
    ASSERT_INT_EQUALS(GLOBAL_TRAVERSE_VISIT_ORDER[5], 6);
    ASSERT_INT_EQUALS(GLOBAL_TRAVERSE_VISIT_ORDER[6], 7);

    binarytree_free(node);

    reset_traversal_data();

    TEST_DONE
}

void test_binarytree_postorder_traversal()
{
    BinaryTreeNode* node = binarytree_create_node(1);

    BinaryTreeNode* node2 = binarytree_insert_left(node, 2);
    binarytree_insert_left(node2, 4);
    binarytree_insert_right(node2, 5);

    BinaryTreeNode* node3 = binarytree_insert_right(node, 3);
    binarytree_insert_left(node3, 6);
    binarytree_insert_right(node3, 7);

    binarytree_postorder_traversal(node, traverse_callback);

    ASSERT_INT_EQUALS(GLOBAL_TRAVERSE_VISIT_ORDER[0], 4);
    ASSERT_INT_EQUALS(GLOBAL_TRAVERSE_VISIT_ORDER[1], 5);
    ASSERT_INT_EQUALS(GLOBAL_TRAVERSE_VISIT_ORDER[2], 2);
    ASSERT_INT_EQUALS(GLOBAL_TRAVERSE_VISIT_ORDER[3], 6);
    ASSERT_INT_EQUALS(GLOBAL_TRAVERSE_VISIT_ORDER[4], 7);
    ASSERT_INT_EQUALS(GLOBAL_TRAVERSE_VISIT_ORDER[5], 3);
    ASSERT_INT_EQUALS(GLOBAL_TRAVERSE_VISIT_ORDER[6], 1);

    binarytree_free(node);

    reset_traversal_data();

    TEST_DONE
}

int main()
{
    printf_s("BinaryTree tests\n\n");

    test_binarytree_create_node();
    test_binarytree_insert_left();
    test_binarytree_insert_right();
    test_binarytree_inorder_traversal();
    test_binarytree_preorder_traversal();
    test_binarytree_postorder_traversal();

    return 0;
}