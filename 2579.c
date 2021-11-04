#include <stdio.h>
#include <stdlib.h>

#define MAX(x,y) ((x) > (y) ? (x) : (y))
int dp[301][3];

int main(void)
{
    int N;
    int stair;

    scanf("%d", &N);
    for (int i = 1; i < N + 1; i++)
    {
        scanf("%d", &stair);
        dp[i][0] = MAX(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = dp[i - 1][0] + stair;
        dp[i][2] = dp[i - 1][1] + stair;
    }
    printf("%d\n", MAX(dp[N][1], dp[N][2]));
}