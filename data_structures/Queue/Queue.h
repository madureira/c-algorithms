#ifndef QUEUE_H
#define QUEUE_H

#ifdef __cplusplus
extern "C" {
#endif

#define QUEUE_SUCCESS 1
#define QUEUE_FAILURE 0
#define QUEUE_INITIAL_CAPACITY 128

    typedef void* QueueItem;

    typedef struct Queue
    {
        int rear;
        unsigned int front;
        unsigned int size;
        unsigned int capacity;
        QueueItem* items;
    } Queue;

    /*
        Creates a new empty Queue.
    */
    Queue* create_new_queue();

    /*
        Frees a given Queue pointer.
    */
    void free_queue(Queue* queue);

    /*
        Checks if Queue is completely empty.
    */
    unsigned int queue_is_empty(Queue* queue);

    /*
        Checks if Queue is completely full.
    */
    unsigned int queue_is_full(Queue* queue);

    /*
        Adds a new item to the top of the Queue.
    */
    void queue_push(Queue* queue, QueueItem item);

    /*
        Gets the item on the front of the Queue.
    */
    QueueItem queue_peek(Queue* queue);

    /*
        Remove an item from Queue and return it.
    */
    QueueItem queue_pop(Queue* queue);

#ifdef __cplusplus
}
#endif

#endif // QUEUE_H