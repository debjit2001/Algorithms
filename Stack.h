int TOP = -1;
int stack_size = 0;
int *STACK = NULL;

int isEmpty()
{
    if (TOP == -1)
    {
        return 1;
    }
    return 0;
}

int isFull()
{
    if (TOP == stack_size - 1)
    {
        return 1;
    }
    return 0;
}

void push(int data)
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
        printf("\nData to be inserted:%d", data);
        TOP = TOP + 1;
        STACK[TOP] = data;
    }
}

int pop()
{
    if (isEmpty())
    {
        printf("\nNo elements to pop");
        return -1;
    }
    else
    {
        int element = STACK[TOP];
        TOP -= 1;
        return element;
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
        printf("\nStack elements are:\n");
        for (int i = 0; i <= TOP; i++)
        {
            printf("%d", STACK[i]);
        }
    }
}
