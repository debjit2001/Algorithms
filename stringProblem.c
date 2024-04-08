#include <stdio.h>
#include <stdlib.h>

char *getName(int length)
{
    char *name = malloc(length + 1);
    name = "Debjit";
    return name;
}

int main()
{
    printf("%s", getName(5));

    return 0;
}
