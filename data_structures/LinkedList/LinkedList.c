#include "LinkedList.h"
#include <stdlib.h>

Node* linkedlist_create_node(NodeValue value)
{
    Node* node;
    node = (Node*)malloc(sizeof(Node));
    node->next = NULL;
    node->value = value;
    return node;
}

Node* linkedlist_append(Node* head, NodeValue value)
{
    Node* previous;
    Node* temp = linkedlist_create_node(value);

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        previous = head;
        while (previous->next != NULL)
        {
            previous = previous->next;
        }
        previous->next = temp;
    }

    return head;
}

void linkedlist_free(Node* node)
{
    Node* temp;
    while (node != NULL)
    {
        temp = node;
        node = node->next;
        temp->value = NULL;
        free(temp);
    }
}