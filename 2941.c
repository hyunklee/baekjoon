#include <stdio.h>

int main(void)
{
    char s[101];
    char i;
    char cnt;

    i = 0;
    cnt = 0;

    scanf("%s",s);
    while (s[i] != 0)
    {
        if (s[i] == '=' &&  i > 0)
        {
            if (s[i - 1] == 'c' || s[i - 1] == 's' || s[i - 1] == 'z')
                cnt--;
            if (i > 1 && s[i - 1] == 'z' && s[i - 2] == 'd')
                cnt--;
        }
        if (s[i] == '-' && i > 0)
        {
            if (s[i - 1] == 'c' || s[i - 1] == 'd')
                cnt--;
        }
        if (s[i] == 'j' && i > 0)
        {
            if (s[i - 1] == 'l' || s[i - 1] == 'n')
                cnt--;
        }
        cnt++;
        i++;
    }
    printf("%d",cnt);
    return (0);
}