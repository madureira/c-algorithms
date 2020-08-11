#include "Queue.h"
#include <stdlib.h>

static int __queue_increase_capacity(Queue* queue);

Queue* create_new_queue()
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));

    if (queue == NULL)
    {
        return NULL;
    }

    queue->items = (QueueItem)malloc(QUEUE_INITIAL_CAPACITY * sizeof(QueueItem));

    if (queue->items == NULL)
    {
        free(queue);
        return NULL;
    }

    queue->rear = -1;
    queue->front = 0;
    queue->size = 0;
    queue->capacity = QUEUE_INITIAL_CAPACITY;

    return queue;
}

void free_queue(Queue* queue)
{
    if (queue != NULL)
    {
        free(queue->items);
        free(queue);
        queue = NULL;
    }
}

unsigned int queue_is_empty(Queue* queue)
{
    if (queue == NULL || queue->size == 0)
    {
        return 1;
    }

    return 0;
}

unsigned int queue_is_full(Queue* queue)
{
    if (queue == NULL || queue->size < queue->capacity)
    {
        return 0;
    }

    return 1;
}

void queue_push(Queue* queue, QueueItem item)
{
    if (queue != NULL)
    {
        if (queue_is_full(queue) == 1)
        {
            if (__queue_increase_capacity(queue) == 0)
            {
                return;
            }
        }
        queue->items[++queue->rear] = item;
        queue->size++;
    }
}

QueueItem queue_peek(Queue* queue)
{
    if (queue == NULL)
    {
        return NULL;
    }

    return queue->items[queue->front];
}

QueueItem queue_pop(Queue* queue)
{
    if (queue_is_empty(queue) == 1)
    {
        return NULL;
    }

    int item = queue->items[queue->front++];

    if (queue->front == queue->capacity) {
        queue->front = 0;
    }

    queue->size--;

    return item;
}

static int __queue_increase_capacity(Queue* queue)
{
    unsigned int newSize = queue->capacity * 2;
    QueueItem* value = realloc(queue->items, sizeof(QueueItem) * newSize);

    if (value == NULL)
    {
        return QUEUE_FAILURE;
    }

    queue->items = value;
    queue->capacity = newSize;

    return QUEUE_SUCCESS;
}