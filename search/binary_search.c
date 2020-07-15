/*
Binary search
Recurrence relation: T(n) = T(n/2) + 1
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
    printf_s("Binary search\n");

    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
    int n = (int)(sizeof(arr) / sizeof(arr[0]));
    int x = 4;
    int result = binarySearch(arr, 0, n - 1, x);

    if (result == -1)
    {
        printf_s("Element is not present in array!\n");
    }
    else
    {
        printf_s("Element is present at index: %i\n", result);
    }

    return 0;
}