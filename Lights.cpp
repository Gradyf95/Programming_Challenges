/* 
 * File:   main.cpp
 * Author: Grady
 *
 * Created on October 22, 2015, 2:16 PM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv)
{
   long long int x, y;
   while(cin >> x)
   {
      if (x == 0)
         break;
      y = sqrt(x);
      if (y*y == x)
         cout << "yes\n";
      else
         cout << "no\n";
   }
   return 0;
}

