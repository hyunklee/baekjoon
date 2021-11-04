#include <stdio.h>

char num[2000001];

int main(void)
{
    int N;
    int temp;

    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &temp);
        num[temp + 1000000] = 1;
    }
    for (int i = 0; i < 2000001; i++)
    {
        if (num[i])
            printf("%d\n", i - 1000000);
    }
}