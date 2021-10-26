#include <stdio.h>
#include <stdlib.h>

int dp[22][22][22];

void w(int a, int b, int c)
{
    if (!dp[a][b][c])
    {
        if (a == 0 || b == 0 || c == 0)
            dp[a][b][c] = 1;
        else if (a > 20 || b > 20 || c > 20)
        {
            if (!dp[20][20][20])
                w(20, 20, 20);
            dp[a][b][c] = dp[20][20][20];
        } 
        else if (a < b && b < c)
        {
            if (!dp[a][b][c - 1])
                w(a, b, c - 1);
            if (!dp[a][b - 1][c - 1])
                w(a, b - 1, c - 1);
            if (!dp[a][b - 1][c])
                w(a, b - 1, c);
            dp[a][b][c] = dp[a][b][c - 1] + dp[a][b - 1][c - 1] - dp[a][b - 1][c];
        }
        else
        {
            if (!dp[a - 1][b][c])
                w(a - 1, b, c);
            if (!dp[a - 1][b - 1][c])
                w(a - 1, b - 1, c);
            if (!dp[a - 1][b][c - 1])
                w(a - 1, b, c - 1);
            if (!dp[a - 1][b - 1][c - 1])
                w(a - 1, b - 1, c - 1);
            dp[a][b][c] = dp[a - 1][b][c] + dp[a - 1][b - 1][c] + dp[a - 1][b][c - 1] - dp[a - 1][b - 1][c - 1];
        }
    }
}

int main(void)
{
    int a;
    int b;
    int c;

    while (1)
    {
        scanf("%d%d%d", &a, &b, &c);
        if (a == -1 && b == -1 && c == -1)
            return (0);
        printf("w(%d, %d, %d) = ", a, b, c);
        if (a < 0)
            a = 0;
        if (b < 0)
            b = 0;
        if (c < 0)
            c = 0;
        if (a > 21)
            a = 21;
        if (b > 21)
            b = 21;
        if (c > 21)
            c = 21;
        w(a, b, c);
        printf("%d\n", dp[a][b][c]);
    }
}