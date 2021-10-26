#include <stdio.h>

int main(void)
{
    int A;
    int B;
    int C;
    int ben;
    int cnt;

    cnt = 0;
    scanf("%d %d %d",&A, &B, &C);
    if (B >= C)
    {
        printf("%d", -1);
        return (0);
    }
    ben = C - B;
    cnt = A / ben + 1;
    printf("%d",cnt);
    return (0);
}