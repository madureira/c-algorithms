#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#ifdef __cplusplus
extern "C" {
#endif

    typedef void* BinaryTreeNodeValue;

    typedef struct BinaryTreeNode
    {
        BinaryTreeNodeValue value;
        struct BinaryTreeNode* left;
        struct BinaryTreeNode* right;
    } BinaryTreeNode;

    /*
        Creates a new empty BinaryTree.
    */
    BinaryTreeNode* binarytree_create_node(BinaryTreeNodeValue value);

    /*
        Frees the entire BinaryTree nodes from the root through its children recursively.
    */
    void binarytree_free(BinaryTreeNode* rootNode);

    /*
        Inserts a value on the left side of the BinaryTreeNode.
    */
    BinaryTreeNode* binarytree_insert_left(BinaryTreeNode* rootNode, BinaryTreeNodeValue value);

    /*
        Inserts a value on the right side of the BinaryTreeNode.
    */
    BinaryTreeNode* binarytree_insert_right(BinaryTreeNode* rootNode, BinaryTreeNodeValue value);

#ifdef __cplusplus
}
#endif

#endif // BINARY_TREE_H