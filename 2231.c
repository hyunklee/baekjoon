#include <stdio.h>

int count_number(int n)
{
    int i;

    i = 0;  
    while (n)
    {
        n /= 10;
        i++;
    }
    return (i);
}

int make_init(int n)
{
    int init_n;

    init_n = n;
    while (n)
    {
        init_n += n % 10;
        n /= 10;
    }
    return (init_n);
}

int main(void)
{
    int N;
    int M;

    scanf("%d", &N);
    M = N - 9 * count_number(N);
    while (M < N)
    {
        if (make_init(M) == N)
        {
            printf("%d",M);
            return (0);
        }
        M++;
    }
    printf("%d",0);
}