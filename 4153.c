#include <stdio.h>

int main(void)
{
    int num[3];
    int temp;
    while (1)
    {

        scanf("%d %d %d", &num[0], &num[1], &num[2]);
        if (!num[0] || !num[1] || !num[2])
            return (0);
        if (num[0] > num[1])
        {
            temp = num[0];
            num[0] = num[1];
            num[1] = temp;
        }
        if (num[1] > num[2])
        {
            temp = num[1];
            num[1] = num[2];
            num[2] = temp;
        }
        
        if (num[2] * num[2] == num[0] * num[0] + num[1] * num[1])
            printf("right\n");
        else
            printf("wrong\n");
    }
}