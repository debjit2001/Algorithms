#include <stdio.h>
#include <stdlib.h>

int TOP = -1;
int stack_size = 0, minElement = 0;
int *STACK = NULL;

void enqueue(int data)
{
    if (TOP == -1)
    {
        TOP = TOP + 1;
        STACK[TOP] = data;
    }
    else if (TOP == stack_size - 1)
    {
        printf("Stack Full %d cannot be inserted\n", data);
        return;
    }
    else
    {
        TOP = TOP + 1;
        STACK[TOP] = data;
    }
}

void pop()
{
    if (TOP == -1)
    {
        printf("\nNo elements to pop");
    }
    else
    {
        printf("\nElement popped: %d", STACK[TOP]);
        TOP -= 1;
    }
}

int isEmpty()
{
    if (TOP == -1)
    {
        return 1;
    }
    return 0;
}

void printStack()
{
    if (TOP == -1)
    {
        printf("Empty Stack");
        return;
    }
    else
    {
        printf("Stack elements are:\n");
        for (int i = 0; i <= TOP; i++)
        {
            printf("%d", STACK[i]);
        }
    }
}

int main()
{
    printf("Enter the number of elements you want to enter in the stack:");
    scanf("%d", &stack_size);

    STACK = calloc(stack_size, sizeof(int));

    enqueue(5);
    enqueue(4);
    enqueue(3);
    enqueue(2);
    enqueue(1);
    enqueue(0);
    printStack();

    pop();
    pop();
    pop();
    pop();
    // pop();
    // pop();
    // pop();
}