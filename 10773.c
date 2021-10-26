#include <stdlib.h>
#include <stdio.h>

typedef	struct	s_stack{
	int	max;
	int	ptr;
	int	*stk;
}				t_stack;

int		initialize(t_stack *s, int max)
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

int		push(t_stack *s, int x)
{
    if (s->ptr >= s->max)
        return (-1);
    s->stk[s->ptr] = x;
    s->ptr++;
    return (0);
}

int		pop(t_stack *s, int *x)
{
    if (s->ptr <= 0)
        return (-1);
    *x = s->stk[s->ptr - 1];
    s->ptr--;
    return (0);
}

void	terminate(t_stack *s)
{
    if (s->stk)
    {
        free(s->stk);
        s->stk = 0;
    }
    s->max = 0;
    s->ptr = 0;
}

int sum_stack(t_stack *s)
{
    int sum;

    sum = 0;
    for (int i = 0; i < s->ptr; i++)
        sum += s->stk[i];
    return (sum);
}

int main(void)
{
    int K;
    int x;
    t_stack s;

    scanf("%d", &K);
    initialize(&s, K);
    for (int i = 0; i < K; i++)
    {
        scanf("%d", &x);
        if (x)
            push(&s, x);
        else
            pop(&s, &x);
    }
    printf("%d\n", sum_stack(&s));
    terminate(&s);
}