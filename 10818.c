#include <stdio.h>

int main(void)
{
    int t;
    int i;
    int min;
    int max;
    int num[1000000];

    i = 0;
    scanf("%d",&t);
    while (i < t)
        scanf("%d",&num[i++]);
    i = 0;
    min = 1000001;
    max = -1000001;
    while (i < t)
    {
        if (num[i] > max)
            max = num[i];
        if (num[i] < min)
            min = num[i];
        i++;
    }
    printf("%d %d",min,max);
}