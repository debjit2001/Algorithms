#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int size)
{
    int temp = 0;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int smallPos = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[smallPos])
            {
                smallPos = j;
            }
        }
        if (smallPos != i)
        {
            int temp = arr[i];
            arr[i] = arr[smallPos];
            arr[smallPos] = temp;
        }
    }
}

void insertionSort(int arr[], int size)
{
    int i, j, key;

    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int size)
{
    printf("\nArray elements are:");
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
    }
}

int main()
{

    int size, *arr;

    printf("Enter the size of the array:");
    scanf("%d", &size);

    arr = (int *)malloc(size * sizeof(int));

    printf("\nEnter the elements of the array:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", (arr + i));
    }

    printf("\nBefore Sorting:");
    printArray(arr, size);

    // printf("\nAfter bubble sort:");
    // bubbleSort(arr, size);
    // printArray(arr, size);

    // printf("\nAfter selection sort:");
    // selectionSort(arr, size);
    // printArray(arr, size);

    printf("\nAfter insertion sort:");
    insertionSort(arr, size);
    printArray(arr, size);

    return 0;
}