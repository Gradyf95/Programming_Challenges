#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void bishopCount(int n, int k, vector <vector <int> > &A, vector <int> color)
{
   for(int i = 0; i <= n; i++)
      A[i][0] = 1;
   for(int i = 1; i <= k; i++)
      A[0][i] = 0;
   for(int i = 1; i <= n; i++)
      for (int j = 1; j <= color[i] && j<=k; j++)
         A[i][j] = A[i - 1][j - 1] * (color[i] - j + 1) + A[i - 1][j];
}

void initialize(int n, vector<int> &white, vector<int> &black)
{
   for(int i = 1; i <= n; i++)
   {
      for(int j = 1; j <= n; j++)
      {
         if ((i + j) % 2)
            black[(i + j) / 2]++;
         else
            white[(i + j) / 2]++;
      }
   }
}

int main()
{
   int n, k;
   while (cin >> n >> k)
   {
      if (n == 0 && k == 0) 
         return 0;
      vector <vector <int> > A(n + 1, vector <int>(k + 1, 0));
      vector <vector <int> > B(n, vector <int>(k + 1, 0));
      vector <int> black(n, 0);
      vector <int> white(n + 1, 0);
      
      initialize(n, white, black);
      
      sort(white.begin() + 1, white.end());
      sort(black.begin() + 1, black.end());
      
      bishopCount(n, k, A, white);
      bishopCount(n - 1, k, B, black);
      
      int count = 0;
      for(int i = 0; i <= k; i++)
         count += A[n][i] * B[n-1][k - i];
      
      cout << count << endl;
   }
   return 0;
}