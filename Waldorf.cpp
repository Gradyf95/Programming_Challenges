/* 
 * File:   main.cpp
 * Author: Grady
 *
 * Created on September 9, 2015, 9:37 PM
 */

#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <string>


using namespace std;

int height, width = 0;

void check(int word, char array[][52], string *wordlist)
{
   string query = wordlist[word];
   for(int h = 1; h <= height; h++)
   {
      for(int w = 1; w <= width; w++)
      {
         if (query[0] == array[h][w])
         {
            string topleft, top, topright, right, bottomright, bottom, bottomleft, left = "";
            int i, j = 0;
            //topleft
            for(i = h,  j = w; (i > 0) && (j > 0); i--, j--)
            {
               topleft += array[i][j];
            }
            //top
            for(i = h, j = w; i > 0; i--)
            {
               top += array[i][j];
            }
            //topright
            for(i = h, j = w; (i > 0) && (j <= width); i--, j++)
            {
               topright += array[i][j];
            }
            //right
            for(i = h, j = w; j <= width; j++)
            {
               right += array[i][j];
            }
            //bottomright
            for(i = h, j = w; (i <= height) && (j <= width); i++, j++)
            {
               bottomright += array[i][j];
            }
            //bottom
            for(i = h, j = w; i <= height; i++)
            {
               bottom += array[i][j];
            }
            //bottomleft
            for(i = h, j = w; (i <= height) && (j > 0); i++, j--)
            {
               bottomleft += array[i][j];
            }
            //left
            for(i = h, j = w; j > 0; j--)
            {
               left += array[i][j];
            }
            //check substrings
            if (topleft.find(query) == 0)
            {
               printf("%d %d\n", h, w);
               return;
            }
            if (top.find(query) == 0)
            {
               printf("%d %d\n", h, w);
               return;
            }
            if (topright.find(query) == 0)
            {
               printf("%d %d\n", h, w);
               return;
            }
            if (right.find(query) == 0)
            {
               printf("%d %d\n", h, w);
               return;
            }
            if (bottomright.find(query) == 0)
            {
               printf("%d %d\n", h, w);
               return;
            }
            if (bottom.find(query) == 0)
            {
               printf("%d %d\n", h, w);
               return;
            }
            if (bottomleft.find(query) == 0)
            {
               printf("%d %d\n", h, w);
               return;
            }
            if (left.find(query) == 0)
            {
               printf("%d %d\n", h, w);
               return;
            }
            
         }
      }
   }
}

int main(int argc, char** argv)
{
   string trash;
   int cases, words, posh, posw, word = 0;
   
   cin >> cases;
   
   for(int c = 0; c < cases; c++)
   {
      char search[52][52] = {'-'};
      getline(cin, trash);
      scanf("%d %d", &height, &width);
      
      //get array
      for(int i = 1; i < height+1; i++)
      {
         for(int j = 1; j < width+1; j++)
         {
            cin >> search[i][j];
            search[i][j] = toupper(search[i][j]);
         }
      }
      //get words
      cin >> words;
      string wordlist[words];
      for(int i = 0; i < words; i++)
      {
         cin >> wordlist[i];
         string convert = wordlist[i];
         for(int j = 0; j < convert.length(); j++)
            convert[j] = toupper(convert[j]);
         wordlist[i] = convert;
      }
      
      //search array for words
      for(word = 0; word < words; word++)
      {
         check(word, search, wordlist);
      }
      if (c != (cases-1))
         cout << endl;
   }
   
   return 0;
}