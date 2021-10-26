#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *num;
    int N;
    int x;

    num = calloc(20000002, sizeof(int));
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &x);
        if (x <= 0)
            num[x + 10000000]++;
        else
            num[x + 10000001]++;
    }
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &x);
        if (i == N - 1)
        {
            if (x <= 0)
                printf("%d", num[x + 10000000]);
            else
                printf("%d", num[x + 10000001]);
        }
        else
        {
            if (x <= 0)
                printf("%d ", num[x + 10000000]);
            else
                printf("%d ", num[x + 10000001]);
        }
    }
    putchar('\n');
    free(num);
}