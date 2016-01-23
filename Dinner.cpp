#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef vector <int> v1;
typedef vector <v1> v2;

struct seat { int val, id; };
struct team { int val, id; };

bool cmp (seat a,seat b) 
{ 
   return a.val > b.val; 
};
bool cmp1 (team a,team b) 
{ 
   return a.val > b.val; 
};

int main(){
 int m, n, tmp;
 seat s[75];
 team t[75];
 bool flag;
 v2 out;
 while(scanf("%d %d", &m, &n),(m | n))
 {
    out.assign(m, v1());
    flag = true;
    for(int i = 0; i < m; i++) 
       scanf("%d", &t[i].val), t[i].id = i+1;
    for(int i = 0; i < n; i++) 
       scanf("%d", &s[i].val), s[i].id = i+1;
    sort(t, t+m, cmp1);
    sort(s, s+n, cmp);
    for(int i = 0; i < m; i++)
    {
        tmp = t[i].val;
        for(int j = 0; j < n; j++)
        {
            if(!tmp) 
               break;
            if(s[j].val)
            {
                out[t[i].id-1].push_back(s[j].id);
                tmp--;
                s[j].val--;
            }
            else continue;
        }
        if(tmp)
        {
            flag = false;
            break;
        }
    }
    if(!flag) 
       printf("0\n");
    else
    {
      printf("1\n");
      for(int i = 0; i < m; i++)
      {
          sort(out[i].begin(), out[i].end());
          for(int j = 0; j < out[i].size(); j++)
              printf("%d ", out[i][j]);
          printf("\n");
      }
    }
 }
 return 0;
}