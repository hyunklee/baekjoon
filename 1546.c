#include <stdio.h>

int main(void)
{
    int     t;
    int     score[1000] = {0, };
    float   fixed[1000] = {0.0, };
    int     i;
    int     max;
    float   ret;

    i = 0;
    max = 0;
    ret = 0;
    scanf("%d",&t);
    while (i < t)
    {
        scanf("%d",&score[i]);
        if (max < score[i])
            max = score[i];
        i++;
    }
    i = 0;
    while (i < t)
    {
        fixed[i] = ((float)score[i] / (float)max) * 100;
        ret += fixed[i];
        i++;
    }
    printf("%f",ret / (float)t);
}