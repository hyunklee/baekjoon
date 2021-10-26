#include <stdio.h>

long long   sum(int *a, int n)
{
    int i;
    long long sum;

    sum = 0;
    i = 0;
    while (i < n)
    {
        sum += a[i];
        i++;
    }
    return (sum);
}