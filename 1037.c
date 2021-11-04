#include <stdio.h>

int main(void)
{
    int N;
    int min;
    int max;
    int temp;

    min = 1000000;
    max = 2;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &temp);
        if (temp > max)
            max = temp;
        if (temp < min)
            min = temp;
    }
    printf("%d\n", min * max);
}