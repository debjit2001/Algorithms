#include <stdio.h>

#define QUEUE_SIZE 100

struct treeNode
{
    int data;
    struct treeNode *left;
    struct treeNode *right;
};

int front = -1, rear = -1;
struct treeNode *QUEUE[QUEUE_SIZE];

void enqueue(struct treeNode *node)
{
    if (rear == QUEUE_SIZE - 1)
    {
        printf("Queue Full, cannot enqueue\n");
        return;
    }
    else
    {
        if (front == -1)
            front = 0;
        rear++;
        QUEUE[rear] = node;
    }
}

struct treeNode *dequeue()
{
    struct treeNode *dequeuedNode;
    if (front == -1 || front > rear)
    {
        printf("Queue Empty, cannot dequeue\n");
        return NULL;
    }
    else
    {
        dequeuedNode = QUEUE[front];
        front++;
        return dequeuedNode;
    }
}

int isEmpty()
{
    if (front == -1 || front > rear)
        return 1;
    else
        return 0;
}

void emptyQueue()
{
    while (!isEmpty())
    {
        struct treeNode *node = dequeue();
        free(node);
    }
}
