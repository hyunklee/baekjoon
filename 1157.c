#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s;
    char ret;
    int cnt;
    int i;
    int flag;
    int alpha[26] = {0, };

    flag = 0;
    i = 0;
    cnt = 0;
    s = malloc(sizeof(char) * 1000001);
    scanf("%s",s);
    while (s[i] != 0)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] -= 32;
        alpha[s[i] - 'A']++;
        i++;
    }
    i = 0;
    while (i < 26)
    {
        if (alpha[i] > cnt)
        {    
            cnt = alpha[i];
            ret = i;
        }
        i++;
    }
    i = 0;
    while (i < 26)
    {
        if (i != ret && cnt == alpha[i])
            flag = 1;
        i++;
    }
    if (flag)
        printf("?");
    else
        printf("%c",ret + 'A');
}