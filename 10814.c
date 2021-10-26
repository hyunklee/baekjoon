#include <stdio.h>
#include <stdlib.h>

void    shell(int a[], char **b, int n)
{
    int i, j, h;
    for (h = 1; h < n / 9; h = h * 3 + 1)
        ;
    for (; h > 0; h /= 3)
    {
        for (i = h; i < n; i++)
        {
            int tmp_a = a[i];
            char *tmp_n = b[i];
            for (j = i - h; j >= 0 && a[j] > tmp_a; j -= h)
            {    
                a[j + h] = a[j];
                b[j + h] = b[j];
            }
            a[j + h] = tmp_a;
            b[j + h] = tmp_n;
        }
    }
}

int main(void)
{
    int *age;
    char **name;
    int N;

    scanf("%d", &N);
    age = malloc(sizeof(int) * N);
    name = malloc(sizeof(char *) * N);
    for (int i = 0; i < N; i++)
    {
        name[i] = malloc(sizeof(char) * 101);
        scanf("%d %s", &age[i], name[i]);
    }
    printf("\n");
    shell(age, name, N);
    for (int i = 0; i < N; i++)
        printf("%d %s\n", age[i], name[i]);
    printf("\n");
}