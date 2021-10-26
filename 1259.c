#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *s;
    int flag;
    int last;
    int cnt;

    while (1)
    {
        s = malloc(sizeof(char) * 6);
        scanf("%s",s);
        cnt = strlen(s);
        last = cnt - 1;
        if (cnt % 2 == 0)
            cnt = cnt / 2;
        else
            cnt = cnt / 2 + 1;
        flag = 1;
        if (*s == '0')
            break;
        for (int i = 0; i < cnt; i++)
        {
            if (s[i] != s[last - i])
                flag = 0;
        }
        if (flag == 1)
            printf("yes\n");
        else
            printf("no\n");
    }
}