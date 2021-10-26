#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    int N;
    char *prime;
    int k;

    k = 2;
    scanf("%d",&N);
    prime = malloc(sizeof(int) * N + 1);
    for (int i = 0; i <= N; i++)
        prime[i] = 1;
    for (int i = 2; i <= (int)sqrt(N); i++)
    {
        if (prime[i])
        {
            for (int j = 2; j <= N / i; j++)
                prime[i * j] = 0;
        }
    }
    while (N > 1)
    {
        if (prime[k] && N % k == 0)
        {
            printf("%d\n",k);
            N /= k;
        }
        else
            k++;
    }
}