#include <stdio.h>
#include <stdlib.h>

long long log_trees(int *tree, int N, long long H)
{
    long long ret;

    ret = 0;
    for (int i = 0; i < N; i++)
    {
        if (tree[i] > H)
            ret += (long long)tree[i] - H;
    }
    return (ret);
}

int binary_search(int *tree, int N, int M, int max)
{
    long long case_max;
    long long case_min;
    long long mid;
    long long ret;
    long long long_M;

    long_M = (long long)M;
    case_max = (long long)max;
    case_min = 0;
    do
    {
        mid = (case_max + case_min) / 2;
        ret = log_trees(tree, N, mid);
        if (ret == long_M)
            return (mid);
        else if (ret > long_M)
            case_min = mid + 1;
        else
            case_max = mid - 1;
    } while (case_min <= case_max && mid);
    if (ret > long_M)
    {
        int i = 1;
        while (log_trees(tree, N, mid + i) > long_M)
            i++;
        i--;
        return (mid + i);
    }
    else
    {
        int i = 1;
        while (log_trees(tree, N, mid - i) < long_M)
            i++;
        return (mid - i);
    }
}

int main(void)
{
    int N;
    int M;
    int *tree;
    int max;
    int ret;

    max = 0;
    scanf("%d %d", &N, &M);
    tree = malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
    {    
        scanf("%d", &tree[i]);
        if (tree[i] > max)
            max = tree[i];
    }
    ret = binary_search(tree, N, M, max);
    printf("%d\n", ret);   
}