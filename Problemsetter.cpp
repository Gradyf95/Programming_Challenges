#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <queue>
  
using namespace std;
const int maxn = 1500;
const int oo = 1000000;

vector<int> p;
queue<int> q;
int a[maxn][maxn];
int f, n, np, s, t, nn, sump;
bool readFile();
int findMaxFlow();

bool readFile() 
{
   cin >> n >> np;
   if (n == 0 && np == 0)
      return false;

   nn = n+np+1; sump = 0;
   for (int i = 0; i <= nn; i++)
      for (int j = 0; j <= nn; j++)
         a[i][j] = 0;

   int k;
   s = 0;
   t = n+np+1;
   for (int i = 1; i <= n; i++)
   {
      cin >> a[s][i];
      sump += a[s][i];
   }

   for (int i = 1; i <= np; i++)
   {
      cin >> k;
      for (int j = 1; j <= k; j++)
      {
         int value;
         cin >> value;
         a[value][i+n] = 1;
      }
      a[i+n][t] = 1;
   }
   return true;
}

void augment(int v, int minEdge)
{
   if (v == s)
   {
      f = minEdge;
      return;
   }
   else if (p[v] != -1)
   {
      augment(p[v], min(minEdge, a[p[v]][v]));
      a[p[v]][v] -= f;
      a[v][p[v]] += f;
   }
}

int findMaxFlow()
{
   int result = 0;
   while (true) 
   {
   p.assign(nn+1, -1);
   f = 0;
   while (!q.empty()) 
      q.pop();
   q.push(s);
   while (!q.empty()) 
   {
      int u = q.front();
      q.pop();
      if (u == t) break;
      for (int v = 0; v <= nn; v++) 
      {
         if (a[u][v] > 0 && p[v] == -1)
            q.push(v), p[v] = u;
      }
   }
   augment(t, +oo);
   if (f == 0)
      break;
   result += f;
   }
   return result;
}
   
int main()
{
   while (readFile())
   {
      int result = findMaxFlow();
      if (result == sump)
      {
         cout << 1 << endl;
         for (int i = 1; i <= n; i++)
         {
            int cnt = 0;
            for (int j = 1; j <= np; j++)
            {
               if (a[j+n][i] == 1) 
               {
                 cnt++;
                 if (cnt > 1) cout << " " << j;
                 else cout << j;
               }
            }
            cout << endl;
         }
      }
      else
         cout << 0 << endl;
   }
   return 0;
}