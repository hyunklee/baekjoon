#include <stdio.h>
#include <stdlib.h>

void swap(char *a, char *b)
{
    char temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int main(void)
{
    char a[4];
    char b[4];

    scanf("%s %s",a,b);
    swap(&a[0],&a[2]);
    swap(&b[0],&b[2]);
    if (atoi(a) > atoi(b))
        printf("%s",a);
    else
        printf("%s",b);
    return (0);
}
