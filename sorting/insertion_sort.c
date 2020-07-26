/*
Insertion sort

Worst complexity: O(n^2)
Average complexity: O(n^2)
Best complexity: O(n)
Space complexity: O(n)
*/
#include <stdio.h>

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
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
    printf_s("Insertion sort\n\n");

    int arr[] = { 6, 3, 2, 20, 7, 300, 11 };
    int size = (int)(sizeof(arr) / sizeof(arr[0]));

    printf_s("Original array: \n");
    printArray(arr, size);

    insertionSort(arr, size);

    printf_s("Sorted array: \n");
    printArray(arr, size);

    return 0;
}