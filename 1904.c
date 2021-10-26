#include <stdio.h>
#include <stdlib.h>

void binary_tile(int n, int *dp)
{
    if (n == 1)
    {
        dp[n] = 1;
        return ;
    }
    if (n == 2)
    {
        dp[n] = 2;
        return ;
    }
    if (!dp[n - 1])
        binary_tile(n - 1, dp);
    if (!dp[n - 2])
        binary_tile(n - 2, dp);
    dp[n] = (dp[n - 1] + dp[n - 2]) % 15746;
}

int main(void)
{
    int n;
    int *dp;

    scanf("%d", &n);
    dp = calloc(n + 1, sizeof(int));
    binary_tile(n, dp);
    printf("%d\n", dp[n]);
}