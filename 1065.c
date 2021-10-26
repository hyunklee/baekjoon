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

int han_number(int n)
{
    int num[4] = {0, };
    int N;
    int i;
    int d;

    i = 0;
    N = count_number(n);
    while (i < N)
    {
        num[i] = n % 10;
        n /= 10;
        i++;
    }
    if (N == 3)
    {
        d = num[1] - num[2];
        if (num[0] - num[1] != d)
            return(0);
    }
    else if (N == 4)
        return (0);
    return (1);
}

int main(void)
{
    int i;
    int cnt;
    int N;

    cnt = 0;
    i = 1;
    scanf("%d",&N);
    while (i <= N)
    {
        if (han_number(i))
        {
            cnt++;
        }
        i++;
    }
    printf("%d",cnt);
    return (0);
}