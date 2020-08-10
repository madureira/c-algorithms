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
        unsigned int capacity;
        QueueItem* items;
    } Queue;

    /*
        Creates a new empty Queue.
    */
    Queue* create_new_queue();

#ifdef __cplusplus
}
#endif

#endif // QUEUE_H