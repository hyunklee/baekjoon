#include <stdio.h>
#include <math.h>

int main(void)
{
    double a;
    double b;
    double v;
    double speed;
    double time;
    int     i_time;

    scanf("%lf %lf %lf", &a, &b, &v);
    speed = a - b;
    time = (v - a) / speed;
    time = ceil(time);
    i_time = (int)time;
    i_time++;
    printf("%d",i_time);
}