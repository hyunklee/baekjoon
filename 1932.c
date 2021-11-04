#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main(void)
{
    int T;
    int **dp;
    int ret;

    scanf("%d", &T);
    dp = malloc(sizeof(int *) * T);
    for (int i = 0; i < T; i++)
    {
        dp[i] = malloc(sizeof(int) * (i + 1));
        for (int j = 0; j < i + 1; j++)
        {
            scanf("%d", &dp[i][j]);
            if (i != 0 || j != 0)
            {
                if (j == 0)
                    dp[i][j] += dp[i - 1][0];
                else if (j == i)
                    dp[i][j] += dp[i - 1][j - 1];
                else
                    dp[i][j] += MAX(dp[i - 1][j - 1], dp[i - 1][j]);
            }
        }
    }
    for (int i = 1; i < T; i++)
        dp[T - 1][0] = MAX(dp[T - 1][0], dp[T - 1][i]);
    printf("%d\n", dp[T - 1][0]);
    for (int i = 0; i < T; i++)
        free(dp[i]);
    free(dp);
}