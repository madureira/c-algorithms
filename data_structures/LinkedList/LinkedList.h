#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#ifdef __cplusplus
extern "C" {
#endif

    typedef void* NodeValue;

    typedef struct _Node
    {
        NodeValue value;
        struct Node* next;
    } Node;

    /*
        Create a new Node.
    */
    Node* linkedlist_create_node(NodeValue value);

    /*
        Add a new Node at the beginning of the LinkedList.
    */
    Node* linkedlist_prepend(Node* head, NodeValue value);

    /*
        Add a new Node at the end of the LinkedList.
    */
    Node* linkedlist_append(Node* head, NodeValue value);

    /*
        Delete an existent Node.
    */
    void linkedlist_free(Node* node);

#ifdef __cplusplus
}
#endif

#endif // #ifndef LINKED_LIST_H