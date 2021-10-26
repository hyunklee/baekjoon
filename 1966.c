#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef	struct	s_queue{
	int	max;
	int	ptr;
	int	*stk;
}				t_queue;

int		initialize(t_queue *s, int max)
{
    s->ptr = 0;
    s->stk = calloc(max, sizeof(int));
    if (!s->stk)
    {
        s->max = 0;
        return (-1);
    }
    s->max = max;
    return (0);
}

int		push(t_queue *s, int x)
{
    if (s->ptr >= s->max)
        return (-1);
    s->stk[s->ptr] = x;
    s->ptr++;
    return (0);
}

int		pop(t_queue *s, int *x)
{
    if (s->ptr <= 0)
        *x = -1;
    else
    {
        *x = s->stk[0];
        s->ptr--;
        memmove(s->stk, s->stk + 1, s->ptr * sizeof(int));
    }
    return (0);
}

int		size(const t_queue *s)
{
    return s->ptr;
}

int		front(const t_queue *s)
{
    if (s->ptr <= 0)
        return (-1);
    else
        return (s->stk[0]);
}

void	terminate(t_queue *s)
{
    if (s->stk)
    {
        free(s->stk);
        s->stk = 0;
    }
    s->max = 0;
    s->ptr = 0;
}

int find_max(t_queue *s)
{
    int que_size;
    int max;

    max = s->stk[0];
    for (int i = 0; i <s->ptr; i++)
    {
        if (s->stk[i] > max)
            max = s->stk[i];
    }
    return (max);
}

int main(void)
{
    int T;
    int N;
    int M;
    int x;
    int max;
    int target;
    t_queue s;

    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d %d", &N, &M);
        initialize(&s, N);
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &x);
            push(&s, x);
        }
        target = M;
        for (int order = 1; order <= N; order++)
        {
            max = find_max(&s);
            while (front(&s) < max)
            {
                pop(&s, &x);
                push(&s, x);
                if (target == 0)
                    target += N - order;
                else
                    target--;
            }
            if (target == 0)
            {
                printf("%d\n", order);
                break;
            }
            pop(&s, &x);
            target--;
        }
        terminate(&s);
    }
    return (0);
}