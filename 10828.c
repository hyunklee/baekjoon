#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        *x = -1;
    else
    {
        *x = s->stk[s->ptr - 1];
        s->ptr--;
    }
    return (0);
}

int		top(const t_stack *s, int *x)
{
    if (s->ptr <= 0)
        *x = -1;
    else
        *x = s->stk[s->ptr - 1];
    return (0);
}

int		size(const t_stack *s)
{
    return s->ptr;
}

int		empty(const t_stack *s)
{
    if (s->ptr <= 0)
        return (1);
    else
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

int main(void)
{
    int T;
    int x;
    char *order;
    t_stack s;

    if (initialize(&s, 10000) == -1)
    {
        printf("initialization error\n");
        return (-1);
    }
    scanf("%d",&T);
    for (int i = 0; i < T; i++)
    {
        order = malloc(sizeof(char) * 6);
        scanf("%s", order);
        if (!strcmp(order, "push"))
        {
            scanf("%d", &x);
            push(&s, x);
        }
        else if (!strcmp(order, "pop"))
        {
            pop(&s, &x);
            printf("%d\n",x);
        }
        else if (!strcmp(order, "size"))
            printf("%d\n",size(&s));
        else if (!strcmp(order, "empty"))
            printf("%d\n",empty(&s));
        else if (!strcmp(order, "top"))
        {
            top(&s, &x);
            printf("%d\n",x);
        }
        else
        {
            printf("wrong order\n");
            break;
        }
    }
    return (0);
}