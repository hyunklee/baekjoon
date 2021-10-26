#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap_string(char **s1, char **s2)
{
    char *temp;

    temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

int main(void)
{
    int n;
    int i;
    int j;
    char **word;

    i = 0;
    j = 0;
    scanf("%d",&n);
    word = malloc(sizeof(char *) * n);
    while (i < n)
    {
        word[i] = malloc(sizeof(char) * 51);
        scanf("%s",word[i]);
        i++;
    }
    i = 0;
    i = -1;
    while (++i < n)
    {
        if (i != n - 1 && !strcmp(word[i], word[i + 1]))
             continue;
        printf("%s\n", word[i]);
    }
    return (0);
}