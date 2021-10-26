#include <stdio.h>
#include <stdlib.h>

int find_min(int *color, int use)
{
    int min;
    int temp;
    
    min = 2147483647;
    for (int i = 0; i < 3; i++)
    {
        if (i != use)
        {
            if (color[i] < min)
            {
                min = color[i];
                temp = i;
            }
        }
    }
    return (temp);
}

int main(void)
{
    int N;
    int **color;
    int *pre_color;
    int min;
    int **dp;

    scanf("%d", &N);
    color = malloc(sizeof(int *) * N);
    dp = malloc(sizeof(int *) * N);
    for (int i = 0; i < N; i++)
    {
        color[i] = malloc(sizeof(int) * 3);
        dp[i] = malloc(sizeof(int) * 3);
        for (int j = 0; j < 3; j++)
            scanf("%d", &color[i][j]);
    }
    for (int i = 0; i < 3; i++)
        dp[0][i] = color[0][i];
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            min = find_min(dp[i - 1], j);
            dp[i][j] = dp[i - 1][min] + color[i][j];
        }
    }
    min = find_min(dp[N - 1], 3);
    printf("%d\n", dp[N - 1][min]);
    for (int i = 0; i < N; i++)
    {
        free(color[i]);
        free(dp[i]);
    }
    free(color);
    free(dp);
}