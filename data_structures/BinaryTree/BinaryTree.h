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

    typedef void (*BinaryTreeCallback)(BinaryTreeNode* node);
    typedef int (*BinaryTreeCompareFunction)(BinaryTreeNodeValue* a, BinaryTreeNodeValue* b);

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

    /*
        Inserts a value recursively into the BinaryTree.
    */
    BinaryTreeNode* binarytree_insert(BinaryTreeNode* rootNode, BinaryTreeNodeValue value, BinaryTreeCompareFunction compareFunction);

    /*
        Visit the left branch, then the current node, and finally, the right branch.
    */
    void binarytree_inorder_traversal(BinaryTreeNode* rootNode, BinaryTreeCallback callback);

    /*
        Visit the current node before its child nodes in ascending order.
    */
    void binarytree_preorder_traversal(BinaryTreeNode* rootNode, BinaryTreeCallback callback);

    /*
        Visit the current node after its child nodes.
    */
    void binarytree_postorder_traversal(BinaryTreeNode* rootNode, BinaryTreeCallback callback);

#ifdef __cplusplus
}
#endif

#endif // BINARY_TREE_H