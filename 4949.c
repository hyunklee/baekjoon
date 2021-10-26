#include <stdlib.h>
#include <stdio.h>
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

int		pop(t_stack *s)
{
    if (s->ptr <= 0)
        return (-1);
    s->ptr--;
    return (0);
}

int     size(t_stack *s)
{
    return s->ptr;
}


int    peek(t_stack *s)
{
    return s->stk[s->ptr - 1];
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
    char *s;
    char flag;
    t_stack bracket;

    while(1)
    {
        s = calloc(101, sizeof(char));
        gets(s);
        if (s[0] == '.')
            break;
        flag = 0;
        initialize(&bracket, 101);
        for (int i = 0; s[i] != 0; i++)
        {
            if (s[i] == '[' || s[i] == '(')
                push(&bracket, s[i]);
            else if (s[i] == ']')
            {
                if (peek(&bracket) == '[')
                    pop(&bracket);
                else
                {
                    flag = 1;
                    break;
                }
            }
            else if (s[i] == ')')
            {
                if (peek(&bracket) == '(')
                    pop(&bracket);
                else
                {
                    flag = 1;
                    break;
                }
            }
        }
        if (size(&bracket) || flag)
            printf("no\n");
        else
            printf("yes\n");
        terminate(&bracket);
        free(s);
    }
    free(s);
}