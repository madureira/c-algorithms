/*
Binary search

Worst complexity: O(log n)
Average complexity: O(log n)
Best complexity: O(1)
Space complexity: O(1)
*/
#include <stdio.h>

int binarySearch(int arr[], int left, int right, int x)
{
    while (left <= right)
    {
        // Get the element at the middle of the array
        int middle = left + (right - left) / 2;

        // Check if x is present at middle
        if (arr[middle] == x)
        {
            return middle;
        }

        // If x greater, ignore left half
        if (x > arr[middle])
        {
            left = middle + 1;
        }
        else
        {
            // If x is smaller, ignore right half
            right = middle - 1;
        }
    }

    // If we reach here, then element was not present
    return -1;
}

int main()
{
    printf_s("Binary search\n\n");

    int arr[] = { 1, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
    int size = (int)(sizeof(arr) / sizeof(arr[0]));
    int x = 7;

    int index = binarySearch(arr, 0, size - 1, x);

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