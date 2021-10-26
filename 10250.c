#include <stdio.h>

int main(void)
{
    int T;
    int H;
    int W;
    int N;
    int floor;
    int room;

    scanf("%d",&T);
    while (T--)
    {
        scanf("%d %d %d",&H, &W, &N);
        
        if (!(N % H))
        {
            floor = H;
            room = N / H;
        }
        else
        {
            floor = N % H;
            room = (N / H) + 1;
        }
        
        if (room < 10)
            printf("%d0%d\n", floor, room);
        else
            printf("%d%d\n", floor, room);
    }
    return (0);
}