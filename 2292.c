#include <stdio.h>

int main(void)
{
    int N;
    int room;

    room = 0;
    scanf("%d",&N);
    while (N > 0)
    {
        if (room == 0)
            N -= 1;
        else
            N -= room * 6;
        room++;
    }
    printf("%d",room);
}