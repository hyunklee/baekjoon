#include <stdio.h>

int main(void)
{
   int num[10];
   int i;
   int cnt[42] = {0, };
   int ret;

   i = 0;
   ret = 0;
   while (i < 10)
   {
       scanf("%d",&num[i]);
       num[i] %= 42;
       cnt[num[i]]++;
       i++;
   }
   i = 0;
   while (i < 42)
   {
        if (cnt[i])
            ret++;
        i++;
   }
   printf("%d",ret);
}