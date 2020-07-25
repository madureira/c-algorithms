#include "LinkedList.h"
#include <stdlib.h>

static Node* __sortedInsert(Node* sorted, Node* newNode, LinkedListCompareFunction compareFunction);
static Node* __linkedlist_insertion_sort(Node* head, LinkedListCompareFunction compareFunction);

Node* linkedlist_create_node(NodeValue value)
{
    Node* node;
    node = (Node*)malloc(sizeof(Node));
    node->next = NULL;
    node->value = value;

    return node;
}

Node* linkedlist_prepend(Node* head, NodeValue value)
{
    Node* newNode = linkedlist_create_node(value);
    newNode->next = head;
    head = newNode;

    return head;
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

Node* linkedlist_reverse(Node* head)
{
    Node* previous = NULL;
    Node* current = head;
    Node* next;

    while (current != NULL)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    head = previous;

    return head;
}

void linkedlist_traverse(Node* head, LinkedListCallback callback)
{
    Node* current = head;

    while (current != NULL)
    {
        callback(current);
        current = current->next;
    }
}

Node* linkedlist_remove_first(Node* head)
{
    Node* first = head;
    head = head->next;
    first->next = NULL;

    if (first == head)
    {
        head = NULL;
    }
    free(first);

    return head;
}

Node* linkedlist_remove_last(Node* head)
{
    Node* current = head;
    Node* last = NULL;

    while (current->next != NULL)
    {
        last = current;
        current = current->next;
    }

    if (current == head)
    {
        head = NULL;
    }

    if (last != NULL)
    {
        last->next = NULL;
    }

    free(current);

    return head;
}

Node* linkedlist_search(Node* head, NodeValue value)
{
    Node* current = head;

    while (current != NULL)
    {
        if (current->value == value)
        {
            head = current;
            return head;
        }
        current = current->next;
    }

    return NULL;
}

Node* linkedlist_sort(Node* head, LinkedListCompareFunction compareFunction)
{
    return __linkedlist_insertion_sort(head, compareFunction);
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

    node = NULL;
    temp = NULL;
}

Node* __sortedInsert(Node* sorted, Node* newNode, LinkedListCompareFunction compareFunction)
{
    if (sorted == NULL || compareFunction(sorted->value, newNode->value) >= 0)
    {
        newNode->next = sorted;
        return newNode;
    }
    else
    {
        Node* current = sorted;
        while (current->next != NULL && compareFunction(current->next->value, newNode->value) <= 0)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    return sorted;
}

Node* __linkedlist_insertion_sort(Node* head, LinkedListCompareFunction compareFunction)
{
    Node* current = head;
    Node* sorted = NULL;

    while (current != NULL)
    {
        Node* next = current->next;
        sorted = __sortedInsert(sorted, current, compareFunction);
        current = next;
    }

    return sorted;
}