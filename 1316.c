#include <stdio.h>
#include <stdlib.h>

int check_group_word(char *s)
{
    char a[26] = {0, };
    char c;

    c = *s;
    while (*s)
    {
        if (*s != c)
        {
            a[c - 'a'] = 1;
            c = *s;
            if (a[c - 'a'] == 1)
                return (0);
        }
        s++;
    }
    return (1);
}

int main(void)
{
    int N;
    int i;
    char **word;
    int cnt;

    i = 0;
    cnt = 0;
    scanf("%d", &N);
    word = malloc(sizeof(char **) * N);
    while (i < N)
    {
        word[i] = malloc(sizeof(char *) * 101);
        scanf("%s", word[i]);
        if(check_group_word(word[i]))
            cnt++;
        i++;
    }
    printf("%d\n",cnt);
}