#include <stdio.h>
#include <stdlib.h>

int cut_line(int n, int K, int *line)
{
    int ret;
    ret = 0;
    for (int i = 0; i < K; i++)
        ret += line[i] / n;
    return (ret);
}

int binary_search(long long min, long long max, int *line, int K, int N)
{
    long long mid;
    int length;
    int ret;
    long long temp;

    ret = 0;
    do
    {
        mid = (min + max) / 2;
        length = cut_line(mid, K, line);
        if (N > length)
            max = mid - 1;
        else if (N < length)
            min = mid + 1;
        else
        {
            if (ret < mid)
                ret = mid;
            else
                min = mid + 1;
        }
    } while (min <= max);
    if (!ret)
        ret = (min + max) / 2;
    return (ret);
}

int main(void)
{
    int K;
    int N;
    int *line;
    long long sum;
    int max;
    int num_max;
    int ret;
    int min;

    ret = 0;
    sum = 0;
    num_max = 0;
    scanf("%d %d", &K, &N);
    line = malloc(sizeof(int) * K);
    for (int i = 0; i < K; i++)
    {
        scanf("%d", &line[i]);
        if (num_max < line[i])
            num_max = line[i];
        sum += (long long)line[i];
    }
    max = (int)(sum / N);
    if (!(num_max / N))
        min = 1;
    else
        min = num_max / N;
    ret = binary_search((long long)min, (long long)max, line, K, N);
    printf("%d\n", ret);
}