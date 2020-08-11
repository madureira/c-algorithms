#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "Queue.h"

#define ASSERT_NULL(a) assert((a) == NULL)
#define ASSERT_INT_EQUALS(a, b) assert((a) == (b))
#define ASSERT_STRING_EQUALS(a, b) assert(strcmp(((const char*)(a)), ((const char*)(b))) == 0)
#define TEST_DONE printf_s("Test: \"%s\" - success\n", __func__);

void test_create_new_queue()
{
    Queue* queue = create_new_queue();

    ASSERT_INT_EQUALS(queue->size, 0);
    ASSERT_INT_EQUALS(queue->rear, -1);
    ASSERT_INT_EQUALS(queue->front, 0);
    ASSERT_INT_EQUALS(queue->capacity, QUEUE_INITIAL_CAPACITY);

    free_queue(queue);

    TEST_DONE
}

void test_queue_is_empty()
{
    Queue* queue = create_new_queue();

    ASSERT_INT_EQUALS(queue_is_empty(queue), 1);

    queue_push(queue, 1);

    ASSERT_INT_EQUALS(queue_is_empty(queue), 0);

    free_queue(queue);

    TEST_DONE
}

void test_queue_push()
{
    Queue* queue = create_new_queue();

    queue_push(queue, 1);

    ASSERT_INT_EQUALS(queue->size, 1);

    free_queue(queue);

    TEST_DONE
}

void test_queue_is_full()
{
    Queue* queue = create_new_queue();

    ASSERT_INT_EQUALS(queue_is_full(queue), 0);

    for (int i = 1; i <= QUEUE_INITIAL_CAPACITY; i++)
    {
        queue_push(queue, i);
    }

    ASSERT_INT_EQUALS(queue_is_full(queue), 1);

    queue_push(queue, 1);

    ASSERT_INT_EQUALS(queue->capacity, QUEUE_INITIAL_CAPACITY * 2);
    ASSERT_INT_EQUALS(queue_is_full(queue), 0);

    free_queue(queue);

    TEST_DONE
}

void test_queue_peek()
{
    Queue* queue = create_new_queue();

    queue_push(queue, 1);
    queue_push(queue, 2);
    queue_push(queue, 3);

    int item = (int)queue_peek(queue);

    ASSERT_INT_EQUALS(item, 1);

    free_queue(queue);

    TEST_DONE
}

void test_queue_peek_string()
{
    Queue* queue = create_new_queue();

    queue_push(queue, "AAA");
    queue_push(queue, "BBB");
    queue_push(queue, "CCC");

    int item = (int)queue_peek(queue);

    ASSERT_INT_EQUALS(item, "AAA");

    free_queue(queue);

    TEST_DONE
}

void test_queue_pop()
{
    Queue* queue = create_new_queue();

    queue_push(queue, 1);
    queue_push(queue, 2);
    queue_push(queue, 3);

    ASSERT_INT_EQUALS(queue->size, 3);

    int item = (int)queue_pop(queue);

    ASSERT_INT_EQUALS(item, 1);
    ASSERT_INT_EQUALS(queue->size, 2);

    item = (int)queue_pop(queue);

    ASSERT_INT_EQUALS(item, 2);
    ASSERT_INT_EQUALS(queue->size, 1);

    item = (int)queue_pop(queue);

    ASSERT_INT_EQUALS(item, 3);
    ASSERT_INT_EQUALS(queue->size, 0);

    free_queue(queue);

    TEST_DONE
}

int main()
{
    printf_s("Queue tests\n\n");

    test_create_new_queue();
    test_queue_is_empty();
    test_queue_push();
    test_queue_is_full();
    test_queue_peek();
    test_queue_peek_string();
    test_queue_pop();

    return 0;
}