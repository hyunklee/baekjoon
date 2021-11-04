#include <stdio.h>
#include <stdlib.h>
#define MAX(x,y) ((x) > (y) ? (x) : (y))

int main(void)
{
    int N;
    int *dp;
    int temp;

    scanf("%d", &N);
    dp = calloc(N, sizeof(int));
    scanf("%d", &dp[0]);
    for (int i = 1; i < N; i++)
    {
        scanf("%d", &temp);
        if (temp >= 0 && dp[i - 1] < 0)
            dp[i] = temp;
        else if (temp < 0 && dp[i - 1] < 0)
            dp[i] = MAX(temp, dp[i - 1]);
        else
            dp[i] = dp[i - 1] + temp;
    }
    for (int i = 1; i < N; i++)
        dp[0] = MAX(dp[0], dp[i]);
    printf("%d\n", dp[0]);
    free(dp);
}