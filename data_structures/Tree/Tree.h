#ifndef TREE_H
#define TREE_H

#ifdef __cplusplus
extern "C" {
#endif

#define TREE_SUCCESS 1
#define TREE_FAILURE 0
#define TREE_INITIAL_CAPACITY 128

    typedef void* TreeNode;

    typedef struct Tree
    {
        TreeNode* nodes;
    } Tree;

    /*
        Creates a new empty Tree.
    */
    Tree* create_new_tree();

#ifdef __cplusplus
}
#endif

#endif // TREE_H