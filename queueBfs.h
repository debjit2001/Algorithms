int front = -1, rear = -1;
int queue_size = 0;
int *QUEUE = NULL;

void enqueue(int data)
{
    if (front == -1 && rear == -1)
    {
        printf("\nElement inserted:%d", data);
        front += 1;
        rear += 1;
        QUEUE[rear] = data;
    }
    else if (rear == queue_size - 1)
    {
        printf("Queue Full %d cannot be inserted\n", data);
        return;
    }
    else
    {
        printf("\nElement inserted:%d", data);
        rear += 1;
        QUEUE[rear] = data;
    }
}

int dequeue()
{
    int dequeuedElement;
    if (front == -1 && rear == -1)
    {
        printf("\nNo elements to dequeue");
        return -1;
    }
    else if (front == rear)
    {
        dequeuedElement = QUEUE[front];
        front = -1;
        rear = -1;
        return dequeuedElement;
    }
    else
    {
        dequeuedElement = QUEUE[front];
        front += 1;
        printf("\nElement dequeued:%d", dequeuedElement);
        return dequeuedElement;
    }
}

int isEmpty()
{
    if (front == -1 && rear == -1)
    {
        return 1;
    }
    return 0;
}