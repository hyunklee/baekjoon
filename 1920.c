#include <stdio.h>
#include <stdlib.h>

void    shell(int a[], int n)
{
    int i, j, h;
    for (h = 1; h < n / 9; h = h * 3 + 1)
        ;
    for (; h > 0; h /= 3)
    {
        for (i = h; i < n; i++)
        {
            int tmp = a[i];
            for (j = i - h; j >= 0 && a[j] > tmp; j -= h)
                a[j + h] = a[j];
            a[j + h] = tmp;
        }
    }
}

int main(void)
{
    int N;
    int *N_num;
    int M;
    int *M_num;
    int temp;
    int high;
    int low;
    int mid;
    int flag;

    scanf("%d",&N);
    N_num = malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
        scanf("%d", &N_num[i]);
    scanf("%d", &M);
    M_num = malloc(sizeof(int) * M);
    for (int i = 0; i < M; i++)
        scanf("%d", &M_num[i]);
    shell(N_num, N);
    for (int i = 0; i < M; i++)
    {
        high = N - 1;
        low = 0;
        flag = 0;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (M_num[i] == N_num[mid])
            {
                printf("1\n");
                flag = 1;
                break;
            }
            else if (M_num[i] < N_num[mid])
                high = mid - 1;
            else if (M_num[i] > N_num[mid])
                low = mid + 1;
        }
        if (!flag)
            printf("0\n");
    }
}