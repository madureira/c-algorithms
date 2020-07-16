/*
Bubble sort

Worst complexity: O(n^2)
Average complexity: O(n^2)
Best complexity: O(n)
Space complexity: O(1)
*/
#include <stdio.h>

void bubbleSort(int arr[], int sizeArr)
{
    for (int step = 0; step < (sizeArr - 1); step++)
    {
        for (int element = 0; element < (sizeArr - step - 1); element++)
        {
            // Compare if the left element is greater than the right element
            if (arr[element] > arr[element + 1])
            {
                // Swap the elements
                int temp = arr[element];
                arr[element] = arr[element + 1];
                arr[element + 1] = temp;
            }
        }
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

    bubbleSort(arr, size);

    printf_s("Sorted array: \n");
    printArray(arr, size);

    return 0;
}
