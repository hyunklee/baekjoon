#include <stdio.h>

int main(void)
{
    int A;
    int B;
    int C;
    int M;
    int time;
    int tired;
    int ret;

    ret = 0;
    time = 24;
    tired = 0;
    scanf("%d %d %d %d", &A, &B, &C, &M);
    while (time)
    {
        if (tired + A <= M)
        {
            ret += B;
            tired += A;
        }
        else
        {
            tired -= C;
            if (tired < 0)
                tired = 0;
        }
        time--;
    }
    printf("%d\n", ret);
}