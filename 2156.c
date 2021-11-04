#include <stdio.h>
#include <stdlib.h>
#define MAX(x,y) ((x) > (y) ? (x) : (y))
int pre;
int main(void)
{
    int N;
    scanf("%d", &N);
    int wine;
    int *dp = calloc(N + 3, sizeof(int));;
    for (int i = 3; i < N + 3; i++)
    {
        scanf("%d", &wine);
        dp[i] = MAX(MAX(dp[i - 1], dp[i - 2] + wine), dp[i - 3] + pre + wine);
        pre = wine;
    }
    printf("%d\n", dp[N + 2]);
}