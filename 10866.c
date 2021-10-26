#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef	struct	s_deque{
	int	max;
	int	ptr;
	int	*stk;
}				t_deque;

int		initialize(t_deque *s, int max)
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

int		push_front(t_deque *s, int x)
{
    if (s->ptr >= s->max)
        return (-1);
    memmove(s->stk + 1, s->stk, s->ptr * sizeof(int));
    s->stk[0] = x;
    s->ptr++;
    return (0);
}

int		push_back(t_deque *s, int x)
{
    if (s->ptr >= s->max)
        return (-1);
    s->stk[s->ptr] = x;
    s->ptr++;
    return (0);
}

int		pop_front(t_deque *s, int *x)
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

int		pop_back(t_deque *s, int *x)
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

int		size(const t_deque *s)
{
    return s->ptr;
}

int		empty(const t_deque *s)
{
    if (s->ptr <= 0)
        return (1);
    else
        return (0);
}

int		front(const t_deque *s, int *x)
{
    if (s->ptr <= 0)
        *x = -1;
    else
        *x = s->stk[0];
    return (0);
}

int		back(const t_deque *s, int *x)
{
    if (s->ptr <= 0)
        *x = -1;
    else
        *x = s->stk[s->ptr - 1];
    return (0);
}

void	terminate(t_deque *s)
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
    t_deque s;

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
        if (!strcmp(order, "push_front"))
        {
            scanf("%d", &x);
            push_front(&s, x);
        }
        else if (!strcmp(order, "push_back"))
        {
            scanf("%d", &x);
            push_back(&s, x);
        }
        else if (!strcmp(order, "pop_front"))
        {
            pop_front(&s, &x);
            printf("%d\n",x);
        }
        else if (!strcmp(order, "pop_back"))
        {
            pop_back(&s, &x);
            printf("%d\n",x);
        }
        else if (!strcmp(order, "size"))
            printf("%d\n",size(&s));
        else if (!strcmp(order, "empty"))
            printf("%d\n",empty(&s));
        else if (!strcmp(order, "front"))
        {
            front(&s, &x);
            printf("%d\n", x);
        }
        else if (!strcmp(order, "back"))
        {
            back(&s, &x);
            printf("%d\n", x);
        }
        else
        {
            printf("wrong order\n");
            break;
        }
    }
    return (0);
}