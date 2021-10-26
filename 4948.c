#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int n;
    int *prime;
    int cnt;
    
    while (1)
    {
        cnt = 0;
        scanf("%d",&n);
        if (!n)
            return (0);
        prime = malloc(sizeof(int) * 2 * n + 1);
        prime[0] = 0;
        prime[1] = 0;
        for (int i = 2; i <= 2 * n; i++)
            prime[i] = 1;
        for (int i = 2; i <= 2 * n; i++)
        {
            if (prime[i])
            {
                for (int j = 2; i * j <= 2 * n; j++)
                    prime[i * j] = 0;
            }
        }
        for (int i = n + 1; i <= 2 * n; i++)
        {
            if (prime[i])
                cnt++;
        }
        printf("%d\n",cnt);
        free(prime);
    }
}