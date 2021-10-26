#include <stdio.h>
#include <math.h>

int main(void)
{
    int T;
    int num;
    int cnt;

    scanf("%d", &T);
    cnt = T;
    for (int i = 0; i < T; i++)
    {
        scanf("%d",&num);
        if (num == 1)
            cnt--;
        for (int j = 2; j <= (int)sqrt(num); j++)
        {
            if (num % j == 0)
            {   
                cnt--;
                break;
            }
        }
    }
    printf("%d\n",cnt);
}