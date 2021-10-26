#include <stdio.h>

long long factorial(long long n)
{
    if (n == 0 || n == 1)
        return (1);
    return (n * factorial(n - 1));
}
int main(void)
{
    long long n;
    scanf("%lld",&n);
    printf("%lld\n", factorial(n));
}