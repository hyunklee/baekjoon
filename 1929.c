#include <stdio.h>

int main(void)
{
    char num[1000001] = {0, };
    int M;
    int N;
    int i;
    int j;

    i = 2;
    j = 2;
    scanf("%d %d", &M, &N);
    num[1] = 1;
    while (i <= 1000)
    {
        if (!num[i])
        {
            while (j <= N / i)
            {
                num[i * j] = 1;
                j++;
            }   
        }
        j = 2;
        i++;
    }
    while (M <= N)
    {
        if (!num[M])
            printf("%d\n",M);
        M++;
    }
    return (0);
}