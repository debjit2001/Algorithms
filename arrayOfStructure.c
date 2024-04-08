#include <stdio.h>
#include <stdlib.h>

struct Student
{
    char name[20];
    int roll;
};

int main()
{
    struct Student *class, *p;
    int n;

    scanf("%d", &n);

    class = (struct Student *)malloc(n * sizeof(struct Student));

    for (int i = 0; i < n; i++)
    {
        scanf("%s%d", class[i].name, &class[i].roll);
    }

    p = class;
    printf("class details:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s %d\n", (p + i)->name, (p + i)->roll);
    }
}
