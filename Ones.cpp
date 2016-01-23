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

int main(int argc, char** argv)
{
   int nlength, input, next = 0;
   
   while(scanf("%11d", &input) == 1)
   {
      nlength = 0;
      next = 0;
      do
      {
         next = ((next * 10) + 1) % input;
         nlength++;
      }
      while(next);
      cout << nlength << endl;
   }
   
   return 0;
}