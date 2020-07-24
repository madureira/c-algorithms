/*
Jump search

Worst complexity: O(√n)
Average complexity: O(√n)
Best complexity: O(1)
Space complexity: O(1)
*/
#include <stdio.h>
#include <math.h>

#define min(x, y) ((x < y) ? x : y)

int jumpSearch(int arr[], int size, int x)
{
    int step = (int)floor(sqrt(size));

    int previousStep = 0;
    while (arr[min(step, size) - 1] < x)
    {
        previousStep = step;
        step += (int)floor(sqrt(step));
        if (previousStep >= size)
        {
            return -1;
        }
    }

    while (arr[previousStep] < x)
    {
        previousStep++;
        if (previousStep == min(step, size))
        {
            return -1;
        }
    }

    if (arr[previousStep] == x)
    {
        return previousStep;
    }

    return -1;
}

int main()
{
    printf_s("Jump search\n\n");

    int arr[] = { 1, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
    int size = (int)(sizeof(arr) / sizeof(arr[0]));
    int x = 23;

    int index = jumpSearch(arr, size, x);

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