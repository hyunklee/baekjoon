#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check_braket(char *s, int n)
{
    char *ret;
    int k;

    k = 0;
    ret = malloc(sizeof(char) * (n + 1));
    for (int i = 0; i < n + 1; i++)
        ret[i] = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(' && s[i + 1] == ')')
        {
            i++;
            continue;
        }
        else
        {    
            ret[k] = s[i];
            k++;
        }
    }
    if (ret[0] == 0)
    {
        printf("YES\n");
        free(s);
        free(ret);
        return ;
    }
    else if (strlen(ret) == strlen(s))
    {
        printf("NO\n");
        free(s);
        free(ret);
        return ;
    }
    else
    {
        free(s);
        check_braket(ret, strlen(ret));
    }
}

int main(void)
{
    int T;
    char *s;
    char board[50];

    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        s = malloc(sizeof(char) * 50);
        for (int k = 0; k < 50; k++)
            s[k] = 0;
        scanf("%s",s);
        check_braket(s, strlen(s));
    }
}