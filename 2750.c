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
    int *num;

    scanf("%d",&N);
    num = malloc(sizeof(int) * N);
    for(int i = 0; i < N; i++)
        scanf("%d", &num[i]);
    shell(num, N);
    for(int i = 0; i < N; i++)
        printf("%d\n", num[i]);
}