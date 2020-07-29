#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "ArrayList.h"

#define ASSERT_INT_EQUALS(a, b) assert((a) == (b))
#define ASSERT_STRING_EQUALS(a, b) strcmp((a), (b))
#define TEST_DONE printf_s("Test: \"%s\" - success\n", __func__);

static int int_compare_function(int a, int b)
{
    if (a > b) return 1;
    if (a < b) return -1;
    return 0;
}

static int c_string_compare_function(char* a, char* b)
{
    return strcmp(a, b);
}

void test_new_arraylist()
{
    ArrayList* arrayList = new_arraylist();

    ASSERT_INT_EQUALS(arraylist_size(arrayList), 0);
    ASSERT_INT_EQUALS(arraylist_capacity(arrayList), 128);

    free_arraylist(arrayList);

    TEST_DONE
}

void test_arraylist_insert()
{
    ArrayList* arrayList = new_arraylist();

    arraylist_append(arrayList, 10);
    arraylist_append(arrayList, 30);
    arraylist_insert(arrayList, 1, 20);

    ASSERT_INT_EQUALS(arraylist_at(arrayList, 0), 10);
    ASSERT_INT_EQUALS(arraylist_at(arrayList, 1), 20);
    ASSERT_INT_EQUALS(arraylist_at(arrayList, 2), 30);

    free_arraylist(arrayList);

    TEST_DONE
}

void test_arraylist_prepend()
{
    ArrayList* arrayList = new_arraylist();

    arraylist_append(arrayList, 20);
    arraylist_prepend(arrayList, 10);

    ASSERT_INT_EQUALS(arraylist_at(arrayList, 0), 10);
    ASSERT_INT_EQUALS(arraylist_at(arrayList, 1), 20);

    free_arraylist(arrayList);

    TEST_DONE
}

void test_arraylist_append()
{
    ArrayList* arrayList = new_arraylist();

    arraylist_append(arrayList, 10);
    arraylist_append(arrayList, 20);

    ASSERT_INT_EQUALS(arraylist_at(arrayList, 0), 10);
    ASSERT_INT_EQUALS(arraylist_at(arrayList, 1), 20);

    free_arraylist(arrayList);

    TEST_DONE
}

void test_arraylist_size()
{
    ArrayList* arrayList = new_arraylist();

    arraylist_append(arrayList, 10);
    arraylist_append(arrayList, 20);

    ASSERT_INT_EQUALS(arraylist_size(arrayList), 2);

    free_arraylist(arrayList);

    TEST_DONE
}

void test_arraylist_at()
{
    ArrayList* arrayList = new_arraylist();

    arraylist_append(arrayList, 10);
    arraylist_append(arrayList, 20);
    arraylist_append(arrayList, 30);

    ASSERT_INT_EQUALS(arraylist_at(arrayList, 1), 20);

    free_arraylist(arrayList);

    TEST_DONE
}

void test_arraylist_indexof()
{
    ArrayList* arrayList = new_arraylist();

    arraylist_append(arrayList, 10);
    arraylist_append(arrayList, 20);
    arraylist_append(arrayList, 30);

    int foundAt = arraylist_indexof(arrayList, 20);
    ASSERT_INT_EQUALS(foundAt, 1);

    int notFound = arraylist_indexof(arrayList, 90);
    ASSERT_INT_EQUALS(notFound, -1);

    free_arraylist(arrayList);

    TEST_DONE
}

void test_arraylist_remove_range()
{
    ArrayList* arrayList = new_arraylist();

    arraylist_append(arrayList, 10);
    arraylist_append(arrayList, 20);
    arraylist_append(arrayList, 30);
    arraylist_append(arrayList, 40);

    arraylist_remove_range(arrayList, 1, 2);

    ASSERT_INT_EQUALS(arraylist_size(arrayList), 2);
    ASSERT_INT_EQUALS(arraylist_at(arrayList, 0), 10);
    ASSERT_INT_EQUALS(arraylist_at(arrayList, 1), 40);

    free_arraylist(arrayList);

    TEST_DONE
}

void test_arraylist_remove()
{
    ArrayList* arrayList = new_arraylist();

    arraylist_append(arrayList, 10);
    arraylist_append(arrayList, 20);
    arraylist_append(arrayList, 30);

    arraylist_remove(arrayList, 1);

    ASSERT_INT_EQUALS(arraylist_size(arrayList), 2);
    ASSERT_INT_EQUALS(arraylist_at(arrayList, 0), 10);
    ASSERT_INT_EQUALS(arraylist_at(arrayList, 1), 30);

    free_arraylist(arrayList);

    TEST_DONE
}

void test_arraylist_sort()
{
    ArrayList* arrayList = new_arraylist();

    arraylist_append(arrayList, 30);
    arraylist_append(arrayList, 10);
    arraylist_append(arrayList, 40);
    arraylist_append(arrayList, 10);
    arraylist_append(arrayList, 20);

    arraylist_sort(arrayList, int_compare_function);

    ASSERT_INT_EQUALS(arraylist_at(arrayList, 0), 10);
    ASSERT_INT_EQUALS(arraylist_at(arrayList, 1), 10);
    ASSERT_INT_EQUALS(arraylist_at(arrayList, 2), 20);
    ASSERT_INT_EQUALS(arraylist_at(arrayList, 3), 30);
    ASSERT_INT_EQUALS(arraylist_at(arrayList, 4), 40);

    free_arraylist(arrayList);

    TEST_DONE
}

void test_arraylist_sort_strings()
{
    ArrayList* arrayList = new_arraylist();

    arraylist_append(arrayList, "C");
    arraylist_append(arrayList, "B");
    arraylist_append(arrayList, "A");

    arraylist_sort(arrayList, c_string_compare_function);

    ASSERT_STRING_EQUALS(arraylist_at(arrayList, 0), "A");
    ASSERT_STRING_EQUALS(arraylist_at(arrayList, 1), "B");
    ASSERT_STRING_EQUALS(arraylist_at(arrayList, 2), "C");

    free_arraylist(arrayList);

    TEST_DONE
}

void test_arraylist_reverse()
{
    ArrayList* arrayList = new_arraylist();

    arraylist_append(arrayList, 50);
    arraylist_append(arrayList, 40);
    arraylist_append(arrayList, 30);
    arraylist_append(arrayList, 20);
    arraylist_append(arrayList, 10);

    arraylist_sort(arrayList, int_compare_function);

    ASSERT_INT_EQUALS(arraylist_at(arrayList, 0), 10);
    ASSERT_INT_EQUALS(arraylist_at(arrayList, 1), 20);
    ASSERT_INT_EQUALS(arraylist_at(arrayList, 2), 30);
    ASSERT_INT_EQUALS(arraylist_at(arrayList, 3), 40);
    ASSERT_INT_EQUALS(arraylist_at(arrayList, 4), 50);

    free_arraylist(arrayList);

    TEST_DONE
}

void test_arraylist_reverse_c_strings()
{
    ArrayList* arrayList = new_arraylist();

    arraylist_append(arrayList, "A");
    arraylist_append(arrayList, "B");
    arraylist_append(arrayList, "C");

    arraylist_reverse(arrayList);

    ASSERT_INT_EQUALS(arraylist_at(arrayList, 0), "C");
    ASSERT_INT_EQUALS(arraylist_at(arrayList, 1), "B");
    ASSERT_INT_EQUALS(arraylist_at(arrayList, 2), "A");

    free_arraylist(arrayList);

    TEST_DONE
}

void test_arraylist_erase()
{
    ArrayList* arrayList = new_arraylist();

    arraylist_append(arrayList, 10);
    arraylist_append(arrayList, 20);
    arraylist_append(arrayList, 30);

    arraylist_erase(arrayList);

    ASSERT_INT_EQUALS(arraylist_size(arrayList), 0);
    ASSERT_INT_EQUALS(arraylist_at(arrayList, 0), 0);
    ASSERT_INT_EQUALS(arraylist_at(arrayList, 1), 0);
    ASSERT_INT_EQUALS(arraylist_at(arrayList, 2), 0);

    free_arraylist(arrayList);

    TEST_DONE
}

void test_arraylist_capacity()
{
    ArrayList* arrayList = new_arraylist();

    ASSERT_INT_EQUALS(arraylist_capacity(arrayList), ARRAY_LIST_INITIAL_CAPACITY);

    for (int i = 0; i <= ARRAY_LIST_INITIAL_CAPACITY; i++)
    {
        arraylist_append(arrayList, i);
    }

    ASSERT_INT_EQUALS(arraylist_capacity(arrayList), ARRAY_LIST_INITIAL_CAPACITY * 2);

    free_arraylist(arrayList);

    TEST_DONE
}

int main()
{
    printf_s("ArrayList tests\n\n");

    test_new_arraylist();
    test_arraylist_insert();
    test_arraylist_prepend();
    test_arraylist_append();
    test_arraylist_size();
    test_arraylist_at();
    test_arraylist_indexof();
    test_arraylist_remove_range();
    test_arraylist_remove();
    test_arraylist_sort();
    test_arraylist_sort_strings();
    test_arraylist_reverse();
    test_arraylist_reverse_c_strings();
    test_arraylist_erase();
    test_arraylist_capacity();

    return 0;
}