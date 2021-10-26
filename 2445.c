#include <stdio.h>

void print_star(int n, int m)
{
    for (int i = 1; i <= 2 * n; i++)
    {
        if (i <= m ||i > 2 * n - m)
            printf("*");
        else
            printf(" ");
    }
    printf("\n");
    if (m >= n)
        return ;
    print_star(n, m + 1);
    for (int i = 1; i <= 2 * n; i++)
    {
        if (i <= m ||i > 2 * n - m)
            printf("*");
        else
            printf(" ");
    }
    printf("\n");
}

int main(void)
{
    int n;

    scanf("%d",&n);
    print_star(n, 1);
}