#include <stdio.h>

int power(int a, int b)
{
    int ret;

    ret = 1;
    for (int i = 0; i < b; i++)
        ret = (ret * a) % 10;
    if (!ret)
        ret = 10;
    return (ret);
}

int main(void)
{
    int T;
    int a;
    int b;

    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n",power(a,b));
    }
}