#include <stdio.h>

int dp[2][12];
long long ret;
int mod = 1000000000;
int main(void)
{
    int N;
    scanf("%d", &N);
    for (int i = 2; i <= 10; i++)
        dp[0][i] = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= 10; j++)
            dp[i % 2][j] = (dp[(i - 1) % 2][j - 1] + dp[(i - 1) % 2][j + 1]) % mod;
    }
    for (int i = 1; i <= 10; i++)
        ret = (ret + dp[(N - 1) % 2][i]);
    printf("%lld\n", ret % mod);
}