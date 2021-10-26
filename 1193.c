#include <stdio.h>

int main(void)
{
    int X;
    int n;
    int max;
    int temp;
    int row;
    int col;

    scanf("%d",&X);
    temp = X;
    n = 1;
    while (X > 0)
    {
        X = temp;
        max = (n * n + n) / 2;
        X -= max;
        n++;
    }
    n--;
    X = temp;
    max = (n * n + n) / 2;
    row = n;
    col = 1;
    while (max != X)
    {
        max--;
        row--;
        col++;
    }
    if (n % 2 == 1)
        printf("%d/%d\n",col,row);
    else
        printf("%d/%d\n",row,col);
}