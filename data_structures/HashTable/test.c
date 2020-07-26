#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "HashTable.h"

#define ASSERT_NULL(a) assert((a) == NULL)
#define ASSERT_INT_EQUALS(a, b) assert((a) == (b))
#define ASSERT_STRING_EQUALS(a, b) strcmp((a), (b))
#define TEST_DONE printf_s("Test: \"%s\" - success\n", __func__);

void test_new_hashtable()
{
    unsigned long capacity = 10;
    HashTable* hashTable = new_hashtable(HASHTABLE_KEY_TYPE_C_STRING, capacity);

    free_hashtable(hashTable);

    TEST_DONE
}

void test_hashtable_put_integer()
{
    HashTable* hashTable = new_hashtable(HASHTABLE_KEY_TYPE_INTEGER, 10);

    hashtable_put(hashTable, 1, 111);
    hashtable_put(hashTable, 2, 222);

    ASSERT_INT_EQUALS(hashtable_get(hashTable, 1), 111);
    ASSERT_INT_EQUALS(hashtable_get(hashTable, 2), 222);
    ASSERT_NULL(hashtable_get(hashTable, 3));

    free_hashtable(hashTable);

    TEST_DONE
}

void test_hashtable_put_string()
{
    HashTable* hashTable = new_hashtable(HASHTABLE_KEY_TYPE_C_STRING, 10);

    hashtable_put(hashTable, "foo", "bar");
    hashtable_put(hashTable, "fizz", "buzz");

    ASSERT_STRING_EQUALS(hashtable_get(hashTable, "foo"), "bar");
    ASSERT_STRING_EQUALS(hashtable_get(hashTable, "fizz"), "buzz");
    ASSERT_NULL(hashtable_get(hashTable, "not_found"));

    free_hashtable(hashTable);

    TEST_DONE
}

void test_hashtable_contains()
{
    HashTable* hashTable = new_hashtable(HASHTABLE_KEY_TYPE_C_STRING, 10);

    hashtable_put(hashTable, "foo", "bar");

    ASSERT_INT_EQUALS(hashtable_contains(hashTable, "foo"), 1);
    ASSERT_INT_EQUALS(hashtable_contains(hashTable, "fizz"), 0);

    free_hashtable(hashTable);

    TEST_DONE
}

int main()
{
    test_new_hashtable();
    test_hashtable_put_integer();
    test_hashtable_put_string();
    test_hashtable_contains();

    return 0;
}