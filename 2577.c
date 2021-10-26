#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int num[3];
    int cnt[10] = {0, };
    int mul;
    int i;

    i = 0;
    mul = 1;
    while (i < 3)
    {
        scanf("%d",&num[i]);
        mul *= num[i];
        i++;
    }
    while (mul)
    {
        cnt[mul % 10]++;
        mul /= 10;
    }
    i = 0;
    while (i < 10)
        printf("%d\n",cnt[i++]);
    return (0);
}