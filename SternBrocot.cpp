/* 
 * File:   main.cpp
 * Author: Grady
 *
 * Created on September 28, 2015, 4:59 PM
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;
 
 
int factor(int power)
{
   return ((power > 1) ? (power*factor(power - 1)) : (1));
}
int main()
{
   int power, num;
   while(scanf("%d %d", &power, &num) == 2)
   {
       int A, output = 1;
       for (int i = 0; i < num; i++)
       {
           scanf("%lld", &A); 
           output *= factor(A);
       }

       output = factor(power) / output;
       cout << output << endl;
   }
   return 0;
}