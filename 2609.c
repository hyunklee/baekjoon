#include <stdio.h>

int gcd(int a, int b)
{
    int big;
    int small;
    int temp;

    big = a > b ? a : b;
    small = a < b ? a : b;

    while (small)
    {
        temp = big;
        big = small;
        small = temp % small;
    }
    return (big);
}

int main(void)
{
    int a;
    int b;
    int c;

    scanf("%d %d",&a,&b);
    c = gcd(a,b);
    printf("%d\n%d\n",c, a * b / c);
}