/*
Quicksort

Worst complexity: O(n^2)
Average complexity: O(n log n)
Best complexity: O(n log n)
Space complexity: O(log n)
*/
#include <stdio.h>

void quickSort(int arr[], int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int pivot = arr[high];
    int splitIndex = low; // Index of smaller element
    int temp;

    for (int i = low; i <= high; i++)
    {
        if (arr[i] <= pivot)
        {
            temp = arr[splitIndex];
            arr[splitIndex] = arr[i];
            arr[i] = temp;
            splitIndex++;
        }
    }

    quickSort(arr, low, splitIndex - 2);
    quickSort(arr, splitIndex, high);
}

// Not part of the algorithm
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf_s("%d ", arr[i]);
    }
    printf_s("\n\n");
}

int main()
{
    printf_s("Quicksort\n\n");

    int arr[] = { 6, 3, 2, 20, 7, 300, 11, 7 };
    int size = (int)(sizeof(arr) / sizeof(arr[0]));

    printf_s("Original array: \n");
    printArray(arr, size);

    quickSort(arr, 0, size - 1);

    printf_s("Sorted array: \n");
    printArray(arr, size);

    return 0;
}