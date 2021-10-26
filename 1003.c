#include <stdio.h>
#include <stdlib.h>

void    fibonacci(int **dp, int n)
{
    if (n == 0)
    {
        dp[n][0] = 1;
        return ;
    }
    if (n == 1)
    {
        dp[n][1] = 1;
        return ;
    }
    if (!dp[n - 1][0] || !dp[n - 1][0])
        fibonacci(dp, n - 1);
    if (!dp[n - 2][0] || !dp[n - 2][1])
        fibonacci(dp, n - 2);
    dp[n][0] = dp[n - 1][0] + dp[n - 2][0];
    dp[n][1] = dp[n - 1][1] + dp[n - 2][1];
}

int find_max(int T, int *n)
{
    int max;

    max = n[0];
    for (int i = 1; i < T; i++)
    {
        if (max < n[i])
            max = n[i];
    }
    return (max);
}

int main(void)
{
    int T;
    int *N;
    int **dp;
    int max;

    scanf("%d", &T);
    N = malloc(sizeof(int) * T);
    for (int i = 0; i < T; i++)
        scanf("%d", &N[i]);
    max = find_max(T, N);
    dp = malloc(sizeof(int *) * (max + 1));
    for (int i = 0; i < max + 1; i++)
        dp[i] = calloc(2, sizeof(int));
    for (int i = 0; i < T; i++)
    {
        fibonacci(dp, N[i]);
        printf("%d %d\n", dp[N[i]][0], dp[N[i]][1]);
    }
    free(N);
    for (int i = 0; i < max + 1; i++)
        free(dp[i]);
    free(dp);
}