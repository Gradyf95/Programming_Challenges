/* 
 * File:   main.cpp
 * Author: Grady
 *
 * Created on November 9, 2015, 4:03 PM
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <cstdio>

using namespace std;

bool square(int a)
{
   int b = sqrt(a);
   if (b*b == a)
      return true;
   else 
      return false;           
}

int hanoi(int N)
{
   int pegs[50] = {0};
   int count, i = 0;
   int p = 1;
   while(i < N)
   {
      if (square(pegs[i] + p) || pegs[i] == 0)
      {   
         pegs[i] = p;
         count++;
         p++;
         i = 0;
         continue;
      }
      i++;
   }
   return count;
}

int main(int argc, char** argv)
{
   int C, N = 0;
   cin >> C;
   while(C--)
   {
      cin >> N;
      cout << hanoi(N) << endl;
   }
   return 0;
}