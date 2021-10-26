#include <stdio.h>
#include <stdlib.h>

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

int main(void)
{
    int n;
    int x;
    int *num;
    char *ret;
    char *temp;
    int s_ptr;
    t_stack s;

    s_ptr = 1;
    scanf("%d", &n);
    initialize(&s, n);
    ret = malloc(sizeof(char) * (n * 3));
    temp = ret;
    num = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        scanf("%d", &num[i]);
    for (int i = 0; i < n; i++)
    {
        while (s_ptr <= num[i])
        {
            push(&s, s_ptr);
            *temp = '+';
            temp++;
            s_ptr++;
        }
        pop(&s, &x);
        if (x != num[i])
        {
            printf("NO\n");
            free(ret);
            terminate(&s);
            return (0);
        }
        *temp = '-';
        temp++;
    }
    *temp = 0;
    for (int i = 0; ret[i] != 0; i++)
        printf("%c\n",ret[i]);
    free(ret);
    terminate(&s);
}