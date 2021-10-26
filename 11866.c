#include <stdlib.h>
#include <stdio.h>

typedef struct s_queue{
    int max;    
    int num;    
    int front;
    int rear;
    int *que;
}              t_queue;

int initialize(t_queue *q, int max)
{
    q->num = 0;
    q->front = 0;
    q->rear = 0;
    q->que = calloc(max, sizeof(int));
    if (!q->que)
    {   q->max = 0;
        return (-1);
    }
    q->max = max;
    return (0);
}

int enque(t_queue *q, int x)
{
    if (q->num >= q->max)
        return (-1);
    else
    {
        q->que[q->rear] = x;
        q->rear++;
        q->num++;
        if (q->rear == q->max)
            q->rear = 0;
    }
    return (0);    
}
int deque(t_queue *q, int *x)
{
    if (q->num <= 0)
        return (-1);
    else
    {
        q->num--;
        *x = q->que[q->front];
        q->front++;
        if (q->front == q->max)
            q->front = 0;
        return (0);
    }
}

int peek(const t_queue *q, int *x)
{
    if (q->num <= 0)
        return (-1);
    else
    {
        *x = q->que[q->front];
        return (0);
    }
}

void clear(t_queue *q)
{
    q->num = 0;
    q->front = 0;
    q->rear = 0;
}

int capacity(const t_queue *q)
{
    return q->max;
}

int size(t_queue *q)
{
    return q->num;
}
int is_empty(const t_queue *q)
{
    return (q->num <= 0);
}

int is_full(const t_queue *q)
{
    return (q->num >= q->max);
}

int search(const t_queue *q, int x)
{
    int idx;

    idx = q->front;
    for (int i = 0; i < q->num; i++)
    {
        if (q->que[idx] == x)
            return (idx);
        idx++;
        if (idx >= q->max)
            idx = 0;
    }
    return (-1);
}

int search2(const t_queue *q, int x)
{
    int idx;

    idx = q->front;
    for (int i = 0; i < q->num; i++)
    {
        if (q->que[idx] == x)
            return (i);
        idx++;
        if (idx >= q->max)
            idx = 0;
    }
    return (-1);
}

void print(const t_queue *q)
{
    int idx;

    idx = q->front;
    for (int i = 0; i < q->num; i++)
    {
        printf("%d ", q->que[idx]);
        idx++;
        if (idx >= q->max)
            idx = 0;
    }
    putchar('\n');
}

void terminate(t_queue *q)
{
    if (q->que)
    {
        free(q->que);
        q->que = 0;
    }
    q->front = 0;
    q->max = 0;
    q->num = 0;
    q->rear = 0;
}

int main(void)
{
    int N;
    int k;
    int x;
    int i;

    i = 1;
    t_queue q;

    scanf("%d",&N);
    initialize(&q, N);
    for (int i = 1; i <= N; i++)
        enque(&q, i);
    scanf("%d", &k);
    printf("<");
    while (1)
    {
        if (i % k == 0)
        {
            if (size(&q) == 1)
            {
                deque(&q, &x);
                printf("%d>\n", x);
                break;
            }
            else
            {
                deque(&q, &x);
                printf("%d, ", x);
            } 
        }
        else
        {
            deque(&q, &x);
            enque(&q, x);
        }
        i++;
    }
    terminate(&q);
}