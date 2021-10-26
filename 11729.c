#include <stdio.h>

void hanoi(int n,char from,char temp,char to)
{
   if(n==1)
      printf("%c %c\n",from, to);
   else
   {
      hanoi(n-1,from,to,temp);
      printf("%c %c\n",from,to);
      hanoi(n-1,temp,from,to);
   }
}

int main()
{
   int n;
   int ret;

   ret = 1;
   scanf("%d",&n);
   for (int i = 0; i < n; i++)
   {
    ret *= 2;
   }
   printf("%d\n",ret - 1);
   hanoi(n,'1','2','3');
} 