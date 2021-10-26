#include <stdio.h>
#include <math.h>

int main(void)
{
    int M;
    int N;
    int sum;
    int first;
    int min;
    int flag;

    first = 1;
    sum = 0;
    min = 0;
    scanf("%d", &M);
    scanf("%d", &N);
    for (int i = M; i <= N; i++)
    {
        if (i == 1)
            continue;
        flag = 1;
        for (int j = 2; j <= (int)sqrt(i); j++)
        {
            if (i % j == 0)
            {
                flag = 0;
                break;
            }
        }
        if (first && flag)
        {
            min = i;
            first = 0;
        }
        if (flag)
            sum += i;
    }
    if (sum)
        printf("%d\n%d\n", sum, min);
    else
        printf("-1\n");
}