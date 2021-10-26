#include <stdio.h>

void    print_star(int n)
{
    if (n == 0)
        return ;
    for (int i = 0; i < n; i++)
        printf("*");
    printf("\n");
    print_star(n - 1);
}

int    main(void)
{
    int n;
    scanf("%d",&n);
    print_star(n);
}