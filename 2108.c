#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void int_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void    quick(int a[], int left, int right)
{
    int pl = left;
    int pr = right;
    int x = a[(pl + pr) / 2];
    
    while (pl <= pr)
    {
        while (a[pl] < x)
            pl++;
        while (a[pr] > x)
            pr--;
        if (pl <= pr)
        {
            int_swap(&a[pl], &a[pr]);
            pl++;
            pr--;
        }
    }
    if (left < pr)
        quick(a, left, pr);
    if (pl < right)
        quick(a, pl, right);
}

void    quick_sort(int a[], int n)
{
    quick(a, 0, n - 1);
}

int main(void)
{
    int N;
    int *num;
    int sum;
    float ave;
    int mid;
    int range;
    int mode;
    int mode_num[8001] = {0, };
    int flag;
    int mode_cnt;

    flag = 2;
    mode_cnt = 0;
    sum = 0;
    scanf("%d", &N);
    num = malloc(sizeof(int) * N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &num[i]);
        sum += num[i];
        mode_num[num[i] + 4000]++;
        if (mode_cnt < mode_num[num[i] + 4000])
            mode_cnt = mode_num[num[i] + 4000];
    }
    for (int i = 0; i < 8001; i++)
    {
        if (mode_cnt == mode_num[i] && flag)
        {
            mode = i - 4000;
            flag--;
        }
    }
    quick_sort(num, N);
    ave = round((float)sum / (float)N);
    mid = num[(N - 1) / 2];
    range = num[N - 1] - num[0];
    printf("%d\n%d\n%d\n%d\n", (int)ave, mid, mode, range);
}