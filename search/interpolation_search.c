/*
Interpolation search

Worst complexity: O(n)
Average complexity: O(log log n)
Best complexity: O(1)
Space complexity: O(1)
*/
#include <stdio.h>

int interpolationSearch(int arr[], int size, int x)
{
    int low = 0;
    int high = size - 1;
    int middle = -1;

    while (low <= high && x >= arr[low] && x <= arr[high])
    {
        middle = low + ((x - arr[low]) * (high - low) / (arr[high] - arr[low]));

        if (x > arr[middle])
        {
            low = middle + 1;
        }
        else if (x < arr[middle])
        {
            high = middle - 1;
        }
        else
        {
            return middle;
        }
    }

    return -1;
}

int main()
{
    printf_s("Interpolation search\n\n");

    int arr[] = { 1, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
    int size = (int)(sizeof(arr) / sizeof(arr[0]));
    int x = 23;

    int index = interpolationSearch(arr, size, x);

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