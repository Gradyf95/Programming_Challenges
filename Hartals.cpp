/* 
 * File:   main.cpp
 * Author: Grady
 *
 * Created on August 31, 2015, 4:31 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv)
{
   //variable declarations
   int totalcases, days, parties, wasted = 0;
   
   //get totalcases and make array
   cin >> totalcases;
   int * dayslost = new int[totalcases];
   
   //individual cases
   for(int i = 0; i < totalcases; i++)
   {
      wasted = 0;
      cin >> days >> parties;
      int * hartal = new int[parties];
      //get hartals
      for(int a = 0; a < parties; a++)
         cin >> hartal[a];
      //find wasted days
      for(int a = 0, daypass = 1; daypass <= days; a++, a %= 7, daypass++)
            if ((a != 5) && (a != 6))
               for(int j = 0; j < parties; j++)
                  if (daypass % hartal[j] == 0)
                  {
                     wasted++;
                     break;
                  }
      dayslost[i] = wasted;
   }
   
   for(int i = 0; i < totalcases; i++)
      cout << dayslost[i] << endl;
   
   return 0;
}