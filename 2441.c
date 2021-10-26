#include <stdio.h>

void    print_star(int n, int m)
{
    if (m == 0)
       return ;
    for (int i = 1; i <= n; i++)
    {   
        if (n - m < i) 
            printf("*");
        else
            printf(" ");
    }
    printf("\n");
    print_star(n, m - 1);
}

int    main(void)
{
    int n;
    scanf("%d",&n);
    print_star(n, n);
}