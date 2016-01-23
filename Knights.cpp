#include<stdio.h>
#include<math.h>

int main()
{
   double a, b, c, d, r;
   while(scanf("%lf%lf%lf", &a, &b, &c) == 3)
   {
       if(a == 0 || b == 0 || c == 0)
       printf("The radius of the round table is: 0.000\n");
       else
       {
           d = (a + b + c) / 2;
           r = (d - a) * (d - b) * (d - c) / d;
           r = sqrt(r);
           printf("The radius of the round table is: %.3lf\n",r);
       }
   }
}