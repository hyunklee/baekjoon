#include <stdio.h>

int main(void)
{
    int num[8];
    int flag;
    int i;

    flag = 0;
    i = 0;
    while (i < 8)
        scanf("%d",&num[i++]);
    i = 0;
    while (i < 7)
    {
        if (num[i] < num[i + 1])
            flag++;
        else if (num[i] > num[i + 1])
            flag--;
        i++;
    }
    if (flag == 7)
        printf("ascending");
    else if (flag == -7)
        printf("descending");
    else
        printf("mixed");
    return (0);
}