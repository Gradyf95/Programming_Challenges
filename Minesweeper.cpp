/* 
 * File:   newmain.cpp
 * Author: Grady
 *
 * Created on August 28, 2015, 10:51 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
   int h, w, num, count = 0;
   while(cin >> h >> w)
   {
      
      if ((h == 0) && (w == 0))
      {
         break;
      }
      if (count >= 1)
         cout << endl;
      count++;
      int board[102][102] = {0};
      for(int i = 1; i < (h+1); i++)
      {
         for(int j = 1; j < (w+1); j++)
         {
            char bomb;
            cin >> bomb;
            if (bomb == '*')
            {
               board[i][j] = -1;
               if (board[i-1][j-1] != -1)
                  board[i-1][j-1] += 1;
               
               if (board[i-1][j] != -1)
                  board[i-1][j] += 1;
               
               if (board[i-1][j+1] != -1)
                  board[i-1][j+1] += 1;
               
               if (board[i][j+1] != -1)
                  board[i][j+1] += 1;
               
               if (board[i+1][j+1] != -1)
                  board[i+1][j+1] += 1;
               
               if (board[i+1][j] != -1)
                  board[i+1][j] += 1;
               
               if (board[i+1][j-1] != -1)
                  board[i+1][j-1] += 1;
               
               if (board[i][j-1] != -1)
                  board[i][j-1] += 1;
            }
         }
      }
      
      cout << "Field #" << count << ":\n";
      for(int i = 1; i < (h+1); i++)
      {
         for(int j = 1; j < (w+1); j++)
         {
            if (board[i][j] == -1)
               cout << '*';
            else
               cout << board[i][j];
         }
         cout << endl;
      }
   }   
   return 0;
}