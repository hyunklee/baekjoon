#include <stdio.h>
#include <math.h>

int main(void)
{
    int T;
    int x;
    int y;
    int distance;
    int i;
    double sqrt_d;
    double sqrt_n;
    int ret;

    i = 0;
    scanf("%d", &T);
    while (i < T)
    {
        scanf("%d %d", &x, &y);
        distance = y - x;
        sqrt_n = sqrt(distance);
        sqrt_d = floor(sqrt_n);
        if (sqrt_n == sqrt_d)
            ret = 2 * (int)sqrt_n - 1;
        else if (sqrt_d + 0.5 > sqrt_n)
            ret = 2 * (int)sqrt_n;
        else
            ret = 2 * (int)sqrt_n + 1;
        printf("%d\n",ret);
        i++;
    }
    return (0);
}