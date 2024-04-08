#include <stdio.h>
#include <stdlib.h>

int partition(int arr[], int l, int h)
{
    int pivot = arr[l];
    int i = l, j = h;

    while (i < j)
    {
        while (arr[i] <= pivot)
            i++;
        while (arr[j] > pivot)
            j--;

        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[l];
    arr[l] = arr[j];
    arr[j] = temp;
    return j;
}

void quickSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int j = partition(arr, l, h);
        quickSort(arr, l, j);
        quickSort(arr, j + 1, h);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int n, *arr;

    printf("Enter the size of the array:");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", (arr + i));
    }
    printf("\nBefore sorting:");
    printArray(arr, n);
    printf("\nAfter using quick sort:");
    quickSort(arr, 0, n - 1);
    printArray(arr, n);
}