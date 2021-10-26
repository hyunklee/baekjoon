#include <stdio.h>

int main(void)
{
    int p[3][2];
    int x;
    int y;
    
    for (int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 2; j++)
            scanf("%d", &p[i][j]);
    }
    if (p[0][0] == p[1][0])
        x = p[2][0];
    else if (p[0][0] == p[2][0])
        x = p[1][0];
    else
        x = p[0][0];
    if (p[0][1] == p[1][1])
        y = p[2][1];
    else if (p[0][1] == p[2][1])
        y = p[1][1];
    else
        y = p[0][1];
    printf("%d %d",x,y);
}