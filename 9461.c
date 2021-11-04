#include <stdio.h>
#include <stdlib.h>

long long dp[101];

void padovan(int n)
{
    if (n < 4)
    {
        dp[n] = 1;
        return ;
    }
    if (!dp[n - 2])
        padovan(n - 2);
    if (!dp[n - 3])
        padovan(n - 3);
    dp[n] = dp[n - 2] + dp[n - 3];
}

int main(void)
{
    int T;
    int *N;

    scanf("%d", &T);
    N = malloc(sizeof(int) * T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d", &N[i]);
        padovan(N[i]);
        printf("%lld\n", dp[N[i]]); 
    }
}