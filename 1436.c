#include <stdio.h>

int     count_six(int n)
{
    int cnt;

    cnt = 0;
    while (n > 0)
    {
        if (n % 10 == 6)
            cnt++;
        else
            cnt = 0;
        if (cnt == 3)
            break;
        n /= 10;
    }
    if (cnt >= 3)
        return (1);
    else
        return (0);
}

int main(void)
{
    int N;
    int ret;
    ret = 665;

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        ret++;
        while (!count_six(ret))
            ret++;
    }
    printf("%d\n", ret);
}