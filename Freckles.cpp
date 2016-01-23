#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#define N 100

using namespace std;
 
struct node 
{
   int start;
   int end;
   double distance;
} a[N * N + 10];
 
struct vertex 
{
   double x;
   double y;
} v[N + 10];
 
bool cmp (node p, node q)
{
   if ( p.distance > q.distance )
      return false;
   return true;
}
 
int main ()
{
   int testCase;
   scanf ("%d", &testCase);
   bool blankLine = false;

   while (testCase--) 
   {
      int n;
      scanf ("%d", &n);
      int root[N + 5];
      double table[N + 5][N + 5];

      for (int i = 0; i < N + 5; i++) 
      {
         for (int j = 0; j < N + 5; j++) 
         {
           table[i][j] = -1;
         }
         root [i] = i;
      }

      for (int i = 1; i <= n; i++)
         scanf ("%lf %lf", &v[i].x, &v[i].y);

      for (int i = 1; i <= n; i++)
      {
         for (int j = 1; j <= n; j++)
         {
            if (table[i][j] == -1)
            {
               double d = sqrt ((v[i].x - v[j].x) * (v[i].x - v[j].x) + (v[i].y - v[j].y) * (v[i].y - v[j].y));
               table[i][j] = table[j][i] = d;
            }
         }
      }

      int length_a = 0;

      for (int i = 1; i <= n; i++)
      {
         for (int j = i + 1; j <= n; j++)
         {
            a[length_a].start = i;
            a[length_a].end = j;
            a[length_a].distance = table[i][j];
            length_a++;
         }
      }

      sort (a, a + length_a, cmp);

      double output = 0;
      int c = 1;
      for (int i = 0; i < length_a && c < n; i++)
      {
         if (root[a[i].start] != root[a[i].end])
         {
            c++;
            output += a[i].distance;
            for (int j = 1; j <= n; j++)
            {
               if (root [a[i].end] == root[j] && a[i].end != j)
                  root[j] = root[a[i].start];
            }
            root [a[i].end] = root[a[i].start];
         }
      } 
      if (blankLine)
         printf ("\n");
      blankLine = true;
      printf ("%.2lf\n", output);
   }

   return 0;
}