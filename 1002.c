#include <stdio.h>
#include <math.h>

int main(void)
{
    int T;
    int x1;
    int y1;
    int r1;
    int x2;
    int y2;
    int r2;
    int d;
    
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        d = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);

        if (d == 0)
        {
            if (r1 == r2)
                printf("-1\n");
            else
                printf("0\n");
        }
        else if ((r1 + r2) * (r1 + r2) < d || (r1 - r2) * (r1 - r2) > d)
            printf("0\n");
        else if ((r1 + r2) * (r1 + r2) == d || (r1 - r2) * (r1 - r2) == d)
            printf("1\n");
        else
            printf("2\n");
    }
}