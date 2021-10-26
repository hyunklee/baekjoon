#include <stdio.h>
#include <math.h>

int main(void)
{
    int R;

    scanf ("%d",&R);
    printf("%lf\n%lf",(double)R * (double)R * M_PI, (double)R * (double)R * 2);
}