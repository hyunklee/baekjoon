#include <stdio.h>

void    print_star(int n, int m)
{
    if (n < m + 1)
       return ;
    for (int i = 1; i <= n + m; i++)
    {
        if (i >= n - m && i <= n + m)
            printf("*");
        else
            printf(" ");
    }
    printf("\n");
    print_star(n, m + 1);
}

void    print_star_r(int n, int m)
{
    if (n == m + 1)
       return ;
    print_star_r(n, m + 1);
    for (int i = 1; i <= n + m; i++)
    {
        if (i >= n - m && i <= n + m)
            printf("*");
        else
            printf(" ");
    }
    printf("\n");
}

int    main(void)
{
    int n;
    scanf("%d",&n);
    print_star(n, 0);
    print_star_r(n, 0);
}