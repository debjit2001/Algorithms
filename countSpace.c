#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

int countSpace(char s[], int size)
{
    int i = 0, sc = 0;
    for (i = 0; i < size; i++)
    {
        if (s[i] == ' ')
        {
            sc++;
        }
    }
    return sc;
}
int main()
{
    char arr[MAX_SIZE];

    printf("Enter the string: ");
    gets(arr);
    int len = strlen(arr);

    int count = countSpace(arr, len);

    printf("Space count: %d", count);
}