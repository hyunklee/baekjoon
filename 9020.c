#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *prime;
    int T;
    int n;
    int left;
    int right;

    scanf("%d",&T);
    for (int k = 0; k < T; k++)
    {
        scanf("%d",&n);
        prime = malloc(sizeof(char) * n);
        prime[0] = 0;
        prime[1] = 0;
        for (int i = 2; i < n; i++)
            prime[i] = 1;
        for (int i = 2; i < n; i++)
        {
            if (prime[i])
            {
                for (int j = 2; i * j < n; j++)
                    prime[i * j] = 0;
            }
        }
        left = n / 2;
        right = n / 2;
        while (1)
        {
            while (!prime[left])
                left--;
            while (!prime[right])
                right++;
            if (left + right > n)
                left--;
            else if (left + right < n)
                right++;
            else
            {
                printf("%d %d\n",left ,right);
                break;
            }
        }
        free(prime);
    }
}