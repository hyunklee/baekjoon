#include <stdio.h>

int main(void)
{
    int x;
    int y;
    int w;
    int h;
    int x_case;
    int y_case;

    scanf("%d %d %d %d", &x,&y,&w,&h);
    if (x < w - x)
        x_case = x;
    else
        x_case = w - x;
    if (y < h - y)
        y_case = y;
    else
        y_case = h - y;
    if (x_case < y_case)
        printf("%d",x_case);
    else
        printf("%d",y_case);
}