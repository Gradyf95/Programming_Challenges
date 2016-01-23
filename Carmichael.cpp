/* 
 * File:   main.cpp
 * Author: Grady
 *
 * Created on October 22, 2015, 2:16 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
   //source of Carmichael numbers is https://oeis.org/A002997
   int n;
   while(cin >> n)
   {
      if (n == 0)
         break;
      if(n==561 || n==1105 || n==1729 || n==2465 || n==2821 || n==6601 || n==8911 || n==10585 || n==15841 || n==29341 || n==41041 || n==46657 || n==52633 || n==62745 || n==63973)
         cout << "The number " << n << " is a Carmichael number.\n";
      else 
         cout << n << " is normal.\n";
    }
    return 0;
}