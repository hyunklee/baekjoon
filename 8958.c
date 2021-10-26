#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int t;
    int i;
    int j;
    int sum;
    int score;
    char **s;

    i = 0;
    j = 0;
    sum = 0;
    score = 0;
    scanf("%d",&t);
    s = malloc(sizeof(char *) * t + 1);
    s[t] = 0;
    while (i < t)
    {
        s[i] = malloc(sizeof(char) * 80);
        scanf("%s",s[i]);
        i++;
    }
    i = 0;
    while (i < t)
    {
        while (s[i][j] != 0)
        {
            if (s[i][j] == 'O')
                score++;
            else
                score = 0;
            sum += score;
            j++;
        }
        printf("%d\n",sum);
        j = 0;
        sum = 0;
        score = 0;
        i++;
    }
    return (0);
}