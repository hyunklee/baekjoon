#include <stdio.h>
#include <string.h>

int main(void)
{
    char A[10001];
    char B[10001];
    char *big;
    char *small;
    int big_p;
    int small_p;
    char upper;
    char same;

    same = 0;
    upper = 0;
    scanf("%s %s",A,B);
    if (strlen(A) > strlen(B))
    {
        big_p = strlen(A) - 1;
        small_p = strlen(B) - 1;
        big = A;
        small = B;
    }
    else if (strlen(A) < strlen (B))
    {
        big_p = strlen(B) - 1;
        small_p = strlen(A) - 1;
        big = B;
        small = A;
    }
    else
    {
        same = 1;
        big_p = strlen(A) - 1;
        small_p = strlen(B) - 1;
        big = A;
        small = B;
    }
    while (big_p >= 0)
    {
        if (upper)
        {
            big[big_p]++;
            upper--;
            if (big[big_p] > '9')
            {
                upper++;
                big[big_p] = '0';
            }
        }
        if (small_p >= 0)
        {
            big[big_p] = (big[big_p] - '0') + (small[small_p] - '0');
            if (big[big_p] >= 10)
            {
                upper++;
                big[big_p] -= 10;
            }
            big[big_p] += '0';
        }
        if (big_p == 0 && upper)
            printf("%d",1);
        big_p--;
        small_p--;
    }
    printf("%s\n",big);
}