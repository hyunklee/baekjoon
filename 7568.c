#include <stdio.h>
#include <stdlib.h>

typedef struct s_info{
    int height;
    int weight;
    int rank;
}              t_info;

int main(void)
{
    int N;
    t_info **info;
    
    scanf("%d", &N);
    info = malloc(sizeof(t_info *) * N);
    for (int i = 0; i < N; i++)
    {
        info[i] = malloc(sizeof(t_info));
        scanf("%d %d",&info[i]->weight, &info[i]->height);
        info[i]->rank = 1;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
                continue;
            if (info[i]->weight < info[j]->weight && info[i]->height < info[j]->height)
                info[i]->rank++;
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (i == 0)
            printf("%d",info[i]->rank);
        else
            printf(" %d",info[i]->rank);
    }
}