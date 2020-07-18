/*
Linear search

Worst complexity: O(n)
Average complexity: O(n)
Best complexity: O(1)
Space complexity: O(1)
*/
#include <stdio.h>

int linearSearch(int arr[], int size, int x)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    printf_s("Linear search\n\n");

    int arr[] = { 1, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
    int size = (int)(sizeof(arr) / sizeof(arr[0]));
    int x = 23;

    int index = linearSearch(arr, size, x);

    if (index == -1)
    {
        printf_s("Element %d is not present in the array!\n", x);
    }
    else
    {
        printf_s("Element %d is present at index: %d\n", x, index);
    }

    return 0;
}