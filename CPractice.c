#include <stdio.h>
#include <stdlib.h>

int main()
{

    int *ptr, *arr;

    int val = 10;

    printf("Value of ptr: %p", ptr);

    printf("\nValue at ptr: %d", *ptr);

    ptr = &val;

    printf("\nValue of ptr after initialization: %p", ptr);

    printf("\nValue at ptr after initialization: %d", *ptr);

    arr = (int *)malloc(5 * sizeof(int));

    for (int i = 0; i < 5; i++)
    {
        scanf("%d", (arr + i));
    }

    printf("\nArray elements are:");
    for (int i = 0; i < 5; i++)
    {
        printf("%d", arr[i]);
    }

    return 0;
}
