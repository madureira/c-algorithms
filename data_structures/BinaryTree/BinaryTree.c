#include "BinaryTree.h"
#include <stdlib.h>

BinaryTreeNode* binarytree_create_node(BinaryTreeNodeValue value)
{
    BinaryTreeNode* node = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));

    if (node == NULL)
    {
        return NULL;
    }

    node->value = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void binarytree_free(BinaryTreeNode* rootNode)
{
    if (rootNode == NULL)
    {
        return;
    }

    binarytree_free(rootNode->left);
    binarytree_free(rootNode->right);

    rootNode->value = NULL;
    free(rootNode);
    rootNode = NULL;
}

BinaryTreeNode* binarytree_insert_left(BinaryTreeNode* rootNode, BinaryTreeNodeValue value)
{
    if (rootNode == NULL)
    {
        return NULL;
    }
    rootNode->left = binarytree_create_node(value);
    
    return rootNode->left;
}

BinaryTreeNode* binarytree_insert_right(BinaryTreeNode* rootNode, BinaryTreeNodeValue value)
{
    if (rootNode == NULL)
    {
        return NULL;
    }
    rootNode->right = binarytree_create_node(value);
    
    return rootNode->right;
}

void binarytree_inorder_traversal(BinaryTreeNode* rootNode, BinaryTreeCallback callback)
{
    if (rootNode == NULL)
    {
        return;
    }

    binarytree_inorder_traversal(rootNode->left, callback);
    callback(rootNode);
    binarytree_inorder_traversal(rootNode->right, callback);
}

void binarytree_preorder_traversal(BinaryTreeNode* rootNode, BinaryTreeCallback callback)
{
    if (rootNode == NULL)
    {
        return;
    }

    callback(rootNode);
    binarytree_preorder_traversal(rootNode->left, callback);
    binarytree_preorder_traversal(rootNode->right, callback);
}

void binarytree_postorder_traversal(BinaryTreeNode* rootNode, BinaryTreeCallback callback)
{
    if (rootNode == NULL)
    {
        return;
    }

    binarytree_postorder_traversal(rootNode->left, callback);
    binarytree_postorder_traversal(rootNode->right, callback);
    callback(rootNode);
}