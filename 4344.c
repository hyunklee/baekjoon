#include <stdio.h>

int main(void)
{
    int T;
    int N[1000] = {0, };
    int num;
    int sum;
    int ave;
    int cnt;
    int i;
    int j;
    double ret;

    sum = 0;
    j = 0;
    i = 0;
    cnt = 0;
    scanf("%d", &T);
    while (i < T)
    {
        scanf("%d", &num);
        while (j < num)
        {
            scanf("%d", &N[j]);
            sum += N[j];
            j++;
        }
        ave = sum / num;
        j = 0;
        while (j < num)
        {
            if (N[j] > ave)
                cnt++;
            j++;
        }
        ret = (double) cnt / num;
        printf("%.3lf%%\n",ret * 100.0);
        j = 0;
        sum = 0;
        num = 0;
        cnt = 0;
        i++;
    }
    return (0);
}