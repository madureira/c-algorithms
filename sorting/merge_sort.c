/*
Merge sort

Worst complexity: O(n log n)
Average complexity: O(n log n)
Best complexity: O(n log n)
Space complexity: O(n)
*/
#include <stdlib.h>
#include <stdio.h>

void merge(int arr[], int start, int middle, int end)
{
    int start1 = start;
    int start2 = middle + 1;
    int startAux = 0;
    int allocSize = end - start + 1;
    int* arrayAux = (int*)malloc(allocSize * sizeof(int));

    while (start1 <= middle && start2 <= end)
    {
        if (arr[start1] < arr[start2])
        {
            arrayAux[startAux] = arr[start1];
            start1++;
        }
        else
        {
            arrayAux[startAux] = arr[start2];
            start2++;
        }
        startAux++;
    }

    while (start1 <= middle)
    {
        arrayAux[startAux] = arr[start1];
        startAux++;
        start1++;
    }

    while (start2 <= end)
    {
        arrayAux[startAux] = arr[start2];
        startAux++;
        start2++;
    }

    for (startAux = start; startAux <= end; startAux++)
    {
        arr[startAux] = arrayAux[startAux - start];
    }

    free(arrayAux);
}

void mergeSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int middle = (end + start) / 2;
        mergeSort(arr, start, middle);
        mergeSort(arr, (middle + 1), end);
        merge(arr, start, middle, end);
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
    printf_s("Bubble sort\n\n");

    int arr[] = { 6, 3, 2, 20, 7, 300, 11 };
    int size = (int)(sizeof(arr) / sizeof(arr[0]));

    printf_s("Original array: \n");
    printArray(arr, size);

    mergeSort(arr, 0, size - 1);

    printf_s("Sorted array: \n");
    printArray(arr, size);

    return 0;
}