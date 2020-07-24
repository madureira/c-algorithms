#include "ArrayList.h"
#include <stdlib.h>

static int __arraylist_increase_capacity(ArrayList* arrayList);
static void __arraylist_quicksort(ArrayListValue* elements, int left, int right);

ArrayList* new_arraylist()
{
    ArrayList* arrayList = (ArrayList*)malloc(sizeof(ArrayList));

    if (arrayList == NULL)
    {
        return NULL;
    }

    arrayList->__capacity = ARRAY_LIST_INITIAL_CAPACITY;
    arrayList->__length = 0;
    arrayList->__elements = (ArrayListValue*)malloc(sizeof(ArrayListValue) * ARRAY_LIST_INITIAL_CAPACITY);

    if (arrayList->__elements == NULL)
    {
        free_arraylist(arrayList);
        return NULL;
    }

    return arrayList;
}

void free_arraylist(ArrayList* arrayList)
{
    if (arrayList != NULL)
    {
        arrayList->__length = 0;
        arrayList->__capacity = 0;
        free(arrayList->__elements);
        free(arrayList);
        arrayList = NULL;
    }
}

int arraylist_insert(ArrayList* arrayList, unsigned int index, ArrayListValue value)
{
    if (index > arrayList->__length)
    {
        return ARRAY_LIST_FAILURE;
    }

    if (arrayList->__length + 1 > arrayList->__capacity)
    {
        if (!__arraylist_increase_capacity(arrayList))
        {
            return ARRAY_LIST_FAILURE;
        }
    }

    memmove(&arrayList->__elements[index + 1],
        &arrayList->__elements[index],
        (arrayList->__length - index) * sizeof(ArrayListValue));

    arrayList->__elements[index] = value;
    ++arrayList->__length;

    return ARRAY_LIST_SUCCESS;
}

int arraylist_prepend(ArrayList* arrayList, ArrayListValue value)
{
    return arraylist_insert(arrayList, 0, value);
}

int arraylist_append(ArrayList* arrayList, ArrayListValue value)
{
    return arraylist_insert(arrayList, arrayList->__length, value);
}

unsigned int arraylist_size(ArrayList* arrayList)
{
    return arrayList->__length;
}

ArrayListValue arraylist_at(ArrayList* arrayList, unsigned int index)
{
    return arrayList->__elements[index];
}

int arraylist_indexof(ArrayList* arrayList, ArrayListValue value)
{
    for (unsigned int i = 0; i < arrayList->__length; ++i)
    {
        if (arrayList->__elements[i] == value)
        {
            return i;
        }
    }

    return -1;
}

void arraylist_remove_range(ArrayList* arrayList, unsigned int start, unsigned int end)
{
    end += 1;

    if (end <= start)
    {
        return;
    }

    unsigned int length = end - start;
    unsigned int interval = start + length;

    if (start > arrayList->__length || interval > arrayList->__length)
    {
        return;
    }

    memmove(&arrayList->__elements[start],
        &arrayList->__elements[interval],
        (arrayList->__length - interval) * sizeof(ArrayListValue));

    arrayList->__length -= length;
}

void arraylist_remove(ArrayList* arrayList, unsigned int index)
{
    arraylist_remove_range(arrayList, index, index);
}

void arraylist_sort(ArrayList* arrayList)
{
    __arraylist_quicksort(arrayList->__elements, 0, arrayList->__length);
}

void arraylist_reverse(ArrayList* arrayList)
{
    int start = 0;
    int end = arrayList->__length;
    ArrayList temp;

    while (start < end)
    {
        temp = arrayList[start];
        arrayList[start] = arrayList[end];
        arrayList[end] = temp;
        start++;
        end--;
    }
}

void arraylist_erase(ArrayList* arrayList)
{
    for (unsigned int i = 0; i < arrayList->__length; i++)
    {
        arrayList->__elements[i] = NULL;
    }
    arrayList->__length = 0;
}

unsigned int arraylist_capacity(ArrayList* arrayList)
{
    return arrayList->__capacity;
}

int __arraylist_increase_capacity(ArrayList* arrayList)
{
    ArrayListValue* value;
    unsigned int newSize;

    newSize = arrayList->__capacity * 2;

    value = realloc(arrayList->__elements, sizeof(ArrayListValue) * newSize);

    if (value == NULL)
    {
        return ARRAY_LIST_FAILURE;
    }
    else
    {
        arrayList->__elements = value;
        arrayList->__capacity = newSize;
        return ARRAY_LIST_SUCCESS;
    }
}

void __arraylist_quicksort(ArrayListValue* elements, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    ArrayListValue pivot = elements[right];

    unsigned int splitIndex = left;

    ArrayListValue temp;
    for (int i = left; i <= right; i++)
    {
        if (elements[i] <= pivot)
        {
            temp = elements[splitIndex];
            elements[splitIndex] = elements[i];
            elements[i] = temp;
            splitIndex++;
        }
    }

    __arraylist_quicksort(elements, left, splitIndex - 2);
    __arraylist_quicksort(elements, splitIndex, right);
}