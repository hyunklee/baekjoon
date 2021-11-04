#include <stdio.h>
#include <stdlib.h>
#define MIN(x,y) ((x) < (y) ? (x) : (y))

int dp[1000001];

int main(void)
{
    int N;

    scanf("%d", &N);
    for (int i = 2; i <= N; i++)
    {
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0)
            dp[i] = MIN(dp[i], dp[i / 2] + 1);
        if (i % 3 == 0)
            dp[i] = MIN(dp[i], dp[i / 3] + 1);
    }
    printf("%d\n", dp[N]);
}