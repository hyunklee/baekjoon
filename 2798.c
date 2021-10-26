#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N;
    int M;
    int *card;
    int sum;
    int temp;
    
    temp = -1;
    scanf("%d %d",&N, &M);
    sum = 0;
    card = malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
        scanf("%d",&card[i]);
    for (int i = 0; i < N - 2; i++)
    {
        for (int j = i + 1; j < N - 1; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                sum = card[i] + card[j] + card[k];
                if (sum > M)
                    sum = -1;
                if (temp < sum)
                    temp = sum;
            }
        }
    }
    printf("%d\n",temp);
}