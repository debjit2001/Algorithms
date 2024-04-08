#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "Stack.h"

#define MAX_SIZE 100

void exprEval(char s[], int size)
{
    int result = 0;
    char str[2];
    for (int i = 0; i < size; i++)
    {
        if (isdigit(s[i]))
        {
            push(s[i] - '0');
            printStack();
        }
        else
        {
            if (s[i] == '+')
            {
                int val1 = pop();
                int val2 = pop();
                result = val1 + val2;
                push(result);
            }
            if (s[i] == '*')
            {
                int val1 = pop();
                int val2 = pop();
                result = val1 * val2;
                push(result);
            }
            if (s[i] == '-')
            {
                int val1 = pop();
                int val2 = pop();
                result = val1 - val2;
                push(result);
            }
            if (s[i] == '/')
            {
                int val1 = pop();
                int val2 = pop();
                result = val1 / val2;
                push(result);
            }
        }
    }
    printf("\nEvaluation of the expression: %d", result);
}

int main()
{
    char arr[MAX_SIZE];
    int n;

    printf("Enter the postfix expression: ");
    scanf("%s", arr);

    int size = 0;
    while (arr[size] != '\0')
    {
        size++;
    }

    stack_size = size;

    STACK = calloc(stack_size, sizeof(int));

    exprEval(arr, size);

    return 0;
}
