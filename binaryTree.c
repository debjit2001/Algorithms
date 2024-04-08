#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct treeNode *root = NULL;

void insertInBinaryTree(struct treeNode **root, int data)
{
    struct treeNode *newNode;
    struct treeNode *temp;
    newNode = (struct treeNode *)malloc(sizeof(struct treeNode));
    if (newNode == NULL)
    {
        printf("Memory error");
        return;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    if (*root == NULL)
    {
        *root = newNode;
        return;
    }
    enqueue(*root);
    while (isEmpty() == 0)
    {
        temp = dequeue();
        if (temp->left)
        {
            enqueue(temp->left);
        }
        else
        {
            temp->left = newNode;
            return;
        }
        if (temp->right)
        {
            enqueue(temp->right);
        }
        else
        {
            temp->right = newNode;
            return;
        }
    }
}

int searchBinaryTree(struct treeNode *root, int data)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == data)
    {
        return 1;
    }
    int leftSearch = searchBinaryTree(root->left, data);
    if (leftSearch == 1)
    {
        return 1;
    }
    int rightSearch = searchBinaryTree(root->right, data);
    if (rightSearch == 1)
    {
        return 1;
    }
    return -1;
}

void deleteBinaryTree(struct treeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    deleteBinaryTree(root->left);
    deleteBinaryTree(root->right);
    free(root);
}

void inorderTraversal(struct treeNode *node)
{
    if (node == NULL)
        return;
    inorderTraversal(node->left);
    printf("%d ", node->data);
    inorderTraversal(node->right);
}

int sizeOfBinaryTree(struct treeNode *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return 1 + sizeOfBinaryTree(node->left) + sizeOfBinaryTree(node->right);
}

int addBinaryTreeNodeValues(struct treeNode *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return node->data + addBinaryTreeNodeValues(node->left) + addBinaryTreeNodeValues(node->right);
}

int heightOfBinaryTree(struct treeNode *node)
{
    if (node == NULL)
    {
        return 0;
    }
    int leftHeight = heightOfBinaryTree(node->left);
    int rightHeight = heightOfBinaryTree(node->right);

    if (leftHeight > rightHeight)
    {
        return leftHeight + 1;
    }
    else
        return rightHeight + 1;
}

struct treeNode *findDeepestNode(struct treeNode *node)
{
    struct treeNode *temp;
    if (node == NULL)
    {
        return NULL;
    }
    if (node->left == NULL && node->right == NULL)
    {
        return node;
    }
    enqueue(node);
    while (isEmpty() == 0)
    {
        temp = dequeue();
        if (temp->left)
        {
            enqueue(temp->left);
        }
        if (temp->right)
        {
            enqueue(temp->right);
        }
    }
    return temp;
}

int main()
{
    insertInBinaryTree(&root, 30);
    insertInBinaryTree(&root, 20);
    insertInBinaryTree(&root, 40);
    insertInBinaryTree(&root, 10);
    insertInBinaryTree(&root, 25);
    insertInBinaryTree(&root, 35);
    insertInBinaryTree(&root, 50);
    inorderTraversal(root);

    int val = searchBinaryTree(root, 60);

    if (val == 1)
    {
        printf("\nFound\n");
    }
    else
    {
        printf("\nNot found\n");
    }

    printf("\nHeight of binary tree is: %d", heightOfBinaryTree(root));
    printf("\nSize of binary tree is: %d", sizeOfBinaryTree(root));
    printf("\nTotal node value: %d", addBinaryTreeNodeValues(root));

    struct treeNode *deepestNode = findDeepestNode(root);
    printf("\nDeepest node value: %d", deepestNode->data);
    deleteBinaryTree(root);
    printf("\nTree deleted successfully");
    return 0;
}