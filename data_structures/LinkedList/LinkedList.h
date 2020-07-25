#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#ifdef __cplusplus
extern "C" {
#endif

    typedef void* NodeValue;

    typedef struct Node
    {
        NodeValue value;
        struct Node* next;
    } Node;

    typedef void (*LinkedListCallback)(Node* node);
    typedef int (*LinkedListCompareFunction)(NodeValue* a, NodeValue* b);

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
        Reverse a LinkedList.
    */
    Node* linkedlist_reverse(Node* head);

    /*
        Traverse the LinkedList and perform the callback function for each Node.
    */
    void linkedlist_traverse(Node* head, LinkedListCallback callback);

    /*
        Remove the first Node from a LinkedList.
    */
    Node* linkedlist_remove_first(Node* head);

    /*
        Remove the last Node from a LinkedList.
    */
    Node* linkedlist_remove_last(Node* head);

    /*
        Search for a specific Node with value.
    */
    Node* linkedlist_search(Node* head, NodeValue value);

    /*
        Sort the Nodes from a LinkedList.
    */
    Node* linkedlist_sort(Node* head, LinkedListCompareFunction compareFunction);

    /*
        Delete an existent Node.
    */
    void linkedlist_free(Node* node);

#ifdef __cplusplus
}
#endif

#endif // #ifndef LINKED_LIST_H