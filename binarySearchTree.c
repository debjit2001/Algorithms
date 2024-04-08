#include <stdio.h>
#include <stdlib.h>

struct treeNode
{
    int data;
    struct treeNode *left;
    struct treeNode *right;
};

struct treeNode *root = NULL;

struct treeNode *findMax(struct treeNode *node)
{
    if (node == NULL)
        return NULL;
    else if (node->right == NULL)
        return node;
    else
        return findMax(node->right);
}

struct treeNode *findMin(struct treeNode *node)
{
    if (node == NULL)
        return NULL;
    else if (node->left == NULL)
        return node;
    else
        return findMin(node->left);
}

struct treeNode *insert(struct treeNode *node, int data)
{
    if (node == NULL)
    {
        struct treeNode *temp = (struct treeNode *)malloc(sizeof(struct treeNode));
        if (temp == NULL)
        {
            printf("Memory error!");
            return NULL;
        }
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }

    if (data > node->data)
        node->right = insert(node->right, data);
    else if (data < node->data)
        node->left = insert(node->left, data);

    return node;
}

struct treeNode *findElement(struct treeNode *node, int target)
{
    if (node == NULL)
    {
        return NULL;
    }
    else
    {
        if (target == node->data)
            return node;
        else if (target > node->data)
            return findElement(node->right, target);
        else
            return findElement(node->left, target);
    }
}

void inorderTraversal(struct treeNode *node)
{
    if (node == NULL)
        return;
    inorderTraversal(node->left);
    printf("%d ", node->data);
    inorderTraversal(node->right);
}

void preorderTraversal(struct treeNode *node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

struct treeNode *deleteNode(struct treeNode *node, int data)
{
    if (node == NULL)
    {
        return NULL;
    }
    if (data < node->data)
    {
        node->left = deleteNode(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = deleteNode(node->right, data);
    }
    else
    {
        if (node->left == NULL)
        {
            struct treeNode *temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL)
        {
            struct treeNode *temp = node->left;
            free(node);
            return temp;
        }
        else
        {
            struct treeNode *temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
    }
    return node;
}

int main()
{
    int target;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder traversal of the BST: ");
    inorderTraversal(root);
    printf("\n");

    printf("\nEnter the value you want to find:");
    scanf("%d", &target);

    struct treeNode *n = findElement(root, target);

    if (n == NULL)
    {
        printf("Not found");
    }
    else
    {
        printf("Found");
    }

    struct treeNode *maxNode = findMax(root);
    struct treeNode *minNode = findMin(root);

    printf("\nMax node value: %d", maxNode->data);
    printf("\nMin node value: %d", minNode->data);

    struct treeNode *node = deleteNode(root, 30);

    inorderTraversal(node);

    return 0;
}
