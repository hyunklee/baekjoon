#include <stdio.h>
#include <stdlib.h>

int knapsack(int i, int j, int **dp, int *W, int *V)
{
    int pre_max;
    int new_max;
    int ret;

    if (j == 0)
    {
        if (i < W[j])
            ret = 0;
        else
            ret = V[j];
    }
    else
    {
        if (i >= W[j])
            new_max = dp[i - W[j]][j - 1] + V[j];
        else
            new_max = 0;
        pre_max = dp[i][j - 1];
        ret = (pre_max > new_max) ? pre_max : new_max;
    }
    return (ret);
}

int main(void)
{
    int N;
    int K;
    int *W;
    int *V;
    int **dp;

    scanf("%d%d", &N, &K);
    dp = malloc(sizeof(int *) * (K + 1));
    W = malloc(sizeof(int) * N);
    V = malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
        scanf("%d%d", &W[i], &V[i]);
    for (int i = 0; i <= K; i++)
    {    
        dp[i] = malloc(sizeof(int) * N);
        for (int j = 0; j < N; j++)
            dp[i][j] = knapsack(i, j, dp, W, V);
    }
    printf("%d", dp[K][N - 1]);
    free(W);
    free(V);
    for (int i = 0; i <= K; i++)
        free(dp[i]);
    free(dp);
}