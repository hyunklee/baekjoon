#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[100];
    char alpha[26];
    char flag[26];
    int i;
    
    i = 0;
    memset(alpha, -1, 26 * sizeof(char));
    memset(flag, 1, 26 * sizeof(char));
    scanf("%s",s);
    while (s[i] != 0)
    {
        if (flag[s[i] - 'a'])
        {
            alpha[s[i] - 'a'] = i;
            flag[s[i] - 'a'] = 0;
        }
        i++;
    }
    i = 0;
    while (i < 26)
        printf("%d ",alpha[i++]);
    return (0);
}