#include <stdio.h>

int main(void)
{
    int N;
    int five;
    int temp;

    scanf("%d",&N);
    five = N / 5;
    temp = (N / 5) * 5;
    N -= temp;
    while (N % 3)
    {
        five--;
        N += 5;
        if (five == -1)
        {
            printf("-1\n");
            return (0);
        }
    }
    printf("%d",five + (N / 3));
}