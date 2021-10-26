#include <stdio.h>

int main(void)
{
    int t;
    int i;
    int sum;
    int num[100];

    i = 0;
    sum = 0;
    scanf("%d",&t);
    while (i < t)
        scanf("%1d",&num[i++]);
    i = 0;
    while (i < t)
        sum += num[i++];
    printf("%d",sum);
}