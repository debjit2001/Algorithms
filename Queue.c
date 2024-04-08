#include <stdio.h>
#include <stdlib.h>

int front = -1, rear = -1;
int queue_size = 0;
int *QUEUE = NULL;

void enqueue(int data)
{
    if (front == -1 && rear == -1)
    {
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
        rear += 1;
        QUEUE[rear] = data;
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("\nNo elements to dequeue");
    }
    else if (front == rear)
    {
        printf("\nElement dequeued: %d", QUEUE[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("\nElement dequeued: %d", QUEUE[front]);
        front += 1;
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

void printQueue()
{
    if (isEmpty())
    {
        printf("Empty Queue");
        return;
    }
    else
    {
        printf("\nQueue elements are:\n");
        for (int i = front; i <= rear; i++)
        {
            printf("%d", QUEUE[i]);
        }
    }
}

int main()
{
    printf("Enter the number of elements you want to enter in the queue:");
    scanf("%d", &queue_size);

    QUEUE = calloc(queue_size, sizeof(int));

    enqueue(5);
    enqueue(4);
    enqueue(3);
    enqueue(2);
    enqueue(1);
    enqueue(0);
    printQueue();
    dequeue();
    dequeue();
    dequeue();
    printQueue();
}