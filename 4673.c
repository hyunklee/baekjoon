#include <stdio.h>

int self_number(int a)
{
    int ret;

    ret = a;
    while (a)
    {
        ret += a % 10;
        a /= 10;
    }
    return (ret);
}

int main(void)
{
    int num[10001] = {0, };
    int fix;
    int i;

    i = 1;
    while (i < 10001)
    {
        fix = self_number(i);
        if (fix < 10001)
            num[fix] = 1;
        i++;
    }
    i = 1;
    while (i < 10001)
    {
        if (!num[i])
            printf("%d\n",i);
        i++;
    }
    return (0);
}