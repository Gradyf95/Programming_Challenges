#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

int main() 
{
   int table[19][19][19] = {};
   table[1][1][1] = 1;
   for (int i = 2; i <= 13; i++)
      for (int j = 1; j <= 13; j++)
         for (int k = 1; k <= 13; k++)
            table[i][j][k] = table[i - 1][j - 1][k] + table[i - 1][j][k - 1] + table[i - 1][j][k] * (i - 2);
         
      
   
   int cases;
   cin >> cases;
   while (cases > 0) 
   {
    int i, j, k;
    scanf("%d%d%d", &i, &j, &k);
    cout << table[i][j][k] << endl;
    cases--;
   }
   return 0;
}