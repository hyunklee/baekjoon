#include <stdio.h>

int find_people(int k, int n)
{
    int i;
    int ret;

    ret = 0;
    i = 1;
    if (k == 0)
        return (n);
    while (i <= n)
    {
        ret += find_people(k - 1, i);
        i++;
    }
    return (ret);
}

int main(void)
{
    int T;
    int k;
    int n;
    int i;
    int ret;
    
    i = 0;
    scanf("%d",&T);
    while (i < T)
    {
        scanf("%d",&k);
        scanf("%d",&n);
        ret = find_people(k, n);
        printf("%d\n",ret);
        i++;
    }
    return (0);
}