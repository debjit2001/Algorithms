#include <stdio.h>
#include <stdlib.h>

struct LinkedList
{
    int data;
    struct LinkedList *next;
};

struct LinkedList *headA = NULL;
struct LinkedList *headB = NULL;
int lengthA = 0, lengthB = 0;

int getLenLinkedList(struct LinkedList *head)
{
    struct LinkedList *ptr = head;
    int count = 0;
    if (ptr == NULL)
    {
        return 0;
    }
    else
    {
        while (ptr != NULL)
        {
            count += 1;
            ptr = ptr->next;
        }
    }
    return count;
}

void insertAtFirst(struct LinkedList **head, int data)
{
    struct LinkedList *temp = (struct LinkedList *)malloc(sizeof(struct LinkedList));
    if (temp == NULL)
    {
        printf("Memory error");
        return;
    }
    temp->data = data;
    temp->next = *head;
    *head = temp;
}

void reverseList(struct LinkedList **head)
{
    struct LinkedList *nextptr = NULL;
    struct LinkedList *prevptr = NULL;
    struct LinkedList *currentptr = *head;
    if (currentptr == NULL)
    {
        printf("Empty List!!!");
        return;
    }
    else
    {
        while (currentptr != NULL)
        {
            nextptr = currentptr->next;
            currentptr->next = prevptr;
            prevptr = currentptr;
            currentptr = nextptr;
        }
        *head = prevptr;
    }
}

int detectCycle(struct LinkedList *head)
{
    struct LinkedList *fastptr = head, *slowptr = head;
    while (fastptr && fastptr->next)
    {
        fastptr = fastptr->next->next;
        slowptr = slowptr->next;
        if (fastptr == slowptr)
        {
            return 1;
        }
    }
    return 0;
}

void findMid(struct LinkedList *head)
{
    struct LinkedList *slow = head;
    struct LinkedList *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("\nMid element is: %d", slow->data);
}

void findMergePoint(struct LinkedList *headA, struct LinkedList *headB)
{
    struct LinkedList *ptrA = headA;
    struct LinkedList *ptrB = headB;

    while (lengthA > lengthB)
    {
        ptrA = ptrA->next;
        lengthA--;
    }
    while (lengthB > lengthA)
    {
        ptrB = ptrB->next;
        lengthB--;
    }
    while (ptrA != ptrB)
    {
        ptrA = ptrA->next;
        ptrB = ptrB->next;
    }
    printf("\nIntersection point: %d", ptrA->data);
}

void printList(struct LinkedList *head)
{
    struct LinkedList *ptr = head;
    if (ptr == NULL)
    {
        printf("Nothing to display!!!");
    }
    else
    {
        printf("Head->");
        while (ptr != NULL)
        {
            printf("%d->", ptr->data);
            ptr = ptr->next;
        }
        printf("NULL");
    }
}

int main()
{
    insertAtFirst(&headA, 5);
    insertAtFirst(&headA, 4);
    insertAtFirst(&headA, 3);
    insertAtFirst(&headA, 2);
    insertAtFirst(&headA, 1);

    insertAtFirst(&headB, 8);
    insertAtFirst(&headB, 7);
    insertAtFirst(&headB, 6);

    // printList(headA);

    // reverseList(&headA);
    // printf("\n");
    printList(headA);
    printf("\n");
    printList(headB);

    // int val = detectCycle(headA);
    // if (val)
    // {
    //     printf("\nCycle detected");
    // }
    // else
    // {
    //     printf("\nNo cycle");
    // }

    // findMid(headA);

    // Merging the two list
    headB->next->next->next = headA->next->next;

    lengthA = getLenLinkedList(headA);
    lengthB = getLenLinkedList(headB);

    printf("\nLengthA: %d,LengthB: %d", lengthA, lengthB);

    findMergePoint(headA, headB);
}
