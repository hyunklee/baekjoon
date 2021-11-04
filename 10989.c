#include <stdio.h>

int num[10001];

int main(void)
{
    int N;
    int temp;

    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &temp);
        num[temp]++;
    }
    for (int i = 1; i < 10001; i++)
    {
        while (num[i])
        {
            printf("%d\n", i);
            num[i]--;
        }
    }
}