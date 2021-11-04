#include <stdio.h>

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main(void)
{
    int N;
    int A;
    int B;
    int x;

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &A, &B);
        x = gcd(A, B);
        printf("%d\n", x * (A / x) * (B / x));
    }
}