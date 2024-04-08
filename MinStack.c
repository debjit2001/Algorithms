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
        minElement = STACK[TOP];
    }
    else if (TOP == stack_size - 1)
    {
        printf("Stack Full %d cannot be inserted\n", data);
        return;
    }
    else
    {
        if (data > minElement)
        {
            TOP = TOP + 1;
            STACK[TOP] = data;
        }
        else
        {
            int prevMin = minElement;
            minElement = data;
            data = 2 * data - prevMin;
            TOP = TOP + 1;
            STACK[TOP] = data;
        }
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
        int t = STACK[TOP];
        if (t < minElement)
        {
            minElement = 2 * minElement - t;
        }
        TOP -= 1;
    }
}

void getMin()
{
    if (TOP == -1)
    {
        printf("Empty stack");
        return;
    }
    else
    {
        printf("\nThe minimum element is: %d", minElement);
    }
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

    getMin();
    // pop();
    // pop();
    // pop();
}