#include <stdio.h>

int main(void)
{
    char    alpha[16];
    int     num[16] = {0, };
    int     i;
    int     time;

    i = 0;
    time = 0;
    scanf("%s",alpha);
    while (alpha[i] != 0)
    {
        if (alpha[i] == 'S')
            num[i] = 7;
        else if (alpha[i] == 'V')
            num[i] = 8;
        else if (alpha[i] == 'Y' || alpha[i] == 'Z')
            num[i] = 9;
        else
            num[i] = (alpha[i] - 'A') / 3 + 2;
        time += num[i] + 1;
        i++;
    }
    printf("%d\n",time);
}