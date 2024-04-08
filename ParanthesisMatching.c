#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int match(char a, char b)
{
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '{' && b == '}')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
    return 0;
}

int paranthesisCheck(char *arr, int size)
{
    for (int j = 0; j < size; j++)
    {
        if (arr[j] == '(' || arr[j] == '{' || arr[j] == '[')
        {
            enqueue(arr[j]);
        }
        if (arr[j] == ')' || arr[j] == '}' || arr[j] == ']')
        {
            if (isEmpty())
            {
                return 0;
            }
            else
            {
                char poppedVal = pop();
                if (!match(poppedVal, arr[j]))
                {
                    return 0;
                }
            }
        }
    }
    if (isEmpty())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int size, i = 0, j = 0;

    char *arr;

    printf("Enter the number of character you want to store:");
    scanf("%d", &size);

    arr = (char *)malloc(size * sizeof(char));

    stack_size = size;

    STACK = calloc(stack_size, sizeof(char));

    printf("Enter the characters:");
    for (i = 0; i < size; i++)
    {
        scanf("%c", arr + i);
    }

    printf("\nEntered characters are:");
    for (j = 0; j < size; j++)
    {
        printf("%c", arr[j]);
    }

    int balancedParanthesisOrNot = paranthesisCheck(arr, size);
    if (balancedParanthesisOrNot)
    {
        printf("\nValid");
    }
    else
    {
        printf("\nInvalid");
    }
}