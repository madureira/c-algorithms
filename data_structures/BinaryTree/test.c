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

void test_binarytree_insert()
{
    BinaryTreeNode* node = binarytree_create_node(5);

    binarytree_insert(node, 3, int_compare_function);
    binarytree_insert(node, 9, int_compare_function);

    ASSERT_INT_EQUALS(node->left->value, 3);
    ASSERT_INT_EQUALS(node->right->value, 9);

    binarytree_free(node);

    TEST_DONE
}

void test_binarytree_insert_string()
{
    BinaryTreeNode* node = binarytree_create_node("B");

    binarytree_insert(node, "C", c_string_compare_function);
    binarytree_insert(node, "A", c_string_compare_function);

    ASSERT_INT_EQUALS(node->left->value, "A");
    ASSERT_INT_EQUALS(node->right->value, "C");

    binarytree_free(node);

    TEST_DONE
}

void test_binarytree_insert_recursively()
{
    /*
                    10
           _________|_________
          |                   |
       ___5___             ___20___
      |       |           |        |
      3       7___        15    ___30
                  |            |
                  9            25
    */

    BinaryTreeNode* node = binarytree_create_node(10);

    binarytree_insert(node, 5, int_compare_function);
    binarytree_insert(node, 20, int_compare_function);
    binarytree_insert(node, 3, int_compare_function);
    binarytree_insert(node, 7, int_compare_function);
    binarytree_insert(node, 9, int_compare_function);
    binarytree_insert(node, 15, int_compare_function);
    binarytree_insert(node, 30, int_compare_function);
    binarytree_insert(node, 25, int_compare_function);

    ASSERT_INT_EQUALS(node->value, 10);

    ASSERT_INT_EQUALS(node->left->value, 5);
    ASSERT_INT_EQUALS(node->left->left->value, 3);
    ASSERT_INT_EQUALS(node->left->right->value, 7);
    ASSERT_INT_EQUALS(node->left->right->right->value, 9);

    ASSERT_INT_EQUALS(node->right->value, 20);
    ASSERT_INT_EQUALS(node->right->left->value, 15);
    ASSERT_INT_EQUALS(node->right->right->value, 30);
    ASSERT_INT_EQUALS(node->right->right->left->value, 25);

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

void test_binarytree_search()
{
    /*
                    10
           _________|_________
          |                   |
       ___5___             ___20___
      |       |           |        |
      3       7___        15    ___30
                  |            |
                  9            25
    */

    BinaryTreeNode* tree = binarytree_create_node(10);

    binarytree_insert(tree, 5, int_compare_function);
    binarytree_insert(tree, 20, int_compare_function);
    binarytree_insert(tree, 3, int_compare_function);
    binarytree_insert(tree, 7, int_compare_function);
    binarytree_insert(tree, 9, int_compare_function);
    binarytree_insert(tree, 15, int_compare_function);
    binarytree_insert(tree, 30, int_compare_function);
    binarytree_insert(tree, 25, int_compare_function);

    BinaryTreeNode* foundNode = binarytree_search(tree, 30, int_compare_function);

    ASSERT_INT_EQUALS(foundNode->left->value, 25);

    BinaryTreeNode* notFoundNode = binarytree_search(tree, 999, int_compare_function);

    ASSERT_NULL(notFoundNode);

    binarytree_free(tree);

    TEST_DONE
}

void test_binarytree_search_string()
{
    /*
                    E
           _________|_________
          |                   |
       ___B___             ___G___
      |       |           |        |
      A       C___        F     ___I
                  |            |
                  D            H
    */

    BinaryTreeNode* tree = binarytree_create_node("E");

    binarytree_insert(tree, "B", c_string_compare_function);
    binarytree_insert(tree, "G", c_string_compare_function);
    binarytree_insert(tree, "A", c_string_compare_function);
    binarytree_insert(tree, "C", c_string_compare_function);
    binarytree_insert(tree, "D", c_string_compare_function);
    binarytree_insert(tree, "F", c_string_compare_function);
    binarytree_insert(tree, "I", c_string_compare_function);
    binarytree_insert(tree, "H", c_string_compare_function);

    BinaryTreeNode* foundNode = binarytree_search(tree, "I", c_string_compare_function);

    ASSERT_INT_EQUALS(foundNode->left->value, "H");

    BinaryTreeNode* notFoundNode = binarytree_search(tree, "Z", c_string_compare_function);

    ASSERT_NULL(notFoundNode);

    binarytree_free(tree);

    TEST_DONE
}

int main()
{
    printf_s("BinaryTree tests\n\n");

    test_binarytree_create_node();
    test_binarytree_insert_left();
    test_binarytree_insert_right();
    test_binarytree_insert();
    test_binarytree_insert_string();
    test_binarytree_insert_recursively();
    test_binarytree_inorder_traversal();
    test_binarytree_preorder_traversal();
    test_binarytree_postorder_traversal();
    test_binarytree_search();
    test_binarytree_search_string();

    return 0;
}