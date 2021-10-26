#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(int a, int b)
{
    int big;
    int small;
    int temp;

    big = a > b ? a : b;
    small = a < b ? a : b;

    while (small)
    {
        temp = big;
        big = small;
        small = temp % small;
    }
    return (big);
}

int main(void)
{
    int t;
    int *num;
    int *num_mod;
    int *overlap;
    int min;
    int mod;
    int flag;
    int empty;
    int idx;
    int temp;

    idx = 0;
    empty = 0;
    min = 1000000001;
    scanf("%d", &t);
    num = malloc(sizeof(int) * t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &num[i]);
        if (num[i] < min)
            min = num[i];
    }
    num_mod = malloc(sizeof(int) * t);
    overlap = malloc(sizeof(char) * (min + 1));
    for (int i = 0; i <= min; i++)
        overlap[i] = 1;
    for (int i = 0; i < t; i++)
    {
        if (overlap[num[i] % min])
        {
            num_mod[idx] = num[i] % min;
            overlap[num_mod[idx]] = 0;
            idx++;
        }
    }
    free(overlap);
    num_mod[idx] = -1;
    for (int i = 0; i < idx - 1; i++)
    {
        for (int j = 0; j < idx - 1 - i; j++)
        {
            if (num_mod[j] > num_mod[j + 1])
            {
                temp = num_mod[j];
                num_mod[j] = num_mod[j + 1];
                num_mod[j + 1]= temp;
            }
        }
    }
    for (int i = 0; i < idx; i++)
    {
        flag = 1;
        if (num_mod[i] == 0)
            continue;
        for (int j = 0; j < t; j++)
        {
            if (j == 0)
                mod = num[j] % num_mod[i];
            else
            {
                if (mod != num[j] % num_mod[i])
                {
                    flag = 0;
                    break;
                }
            }
        }
        if (flag == 1 && empty == 0)
        {
            printf("%d", num_mod[i]);
            empty = 1;
        }
        else if (flag == 1 && empty == 1)
            printf(" %d", num_mod[i]);
    }
}