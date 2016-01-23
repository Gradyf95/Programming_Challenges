
#include <iostream>
#include <vector>

using namespace std;

struct coord
{
  int x;
  int y;
  coord(int xx, int yy)
  {
    x = xx;
    y = yy;
  }
};

int main()
{
  int N;
  cin >> N;
  while(N > 0)
  {
    vector<coord*> cherries;
    for(int j = 0; j < 2*N; ++j)
    {
      int x, y;
      cin >> x >> y;
      cherries.push_back(new coord(x, y));
    }
    bool f = false;
    for(int i = -500; i <= 500 && !f; ++i)
    {
      for(int j = -500; j <= 500 && !f; ++j)
      {
        int a = 0, b = 0, c = 0;
        for(vector<coord*>::iterator it = cherries.begin(); it != cherries.end(); ++it)
        {
          int r = i * (*it)->x + j * (*it)->y;
          if(r < 0) 
             a++;
          else if(r > 0) 
             b++;
          else 
             c++;
          if(a > N || b > N) 
             break;
          if(c > 0) 
             break;
        }
        if(a == N && b == N && c == 0)
        {
          f = true;
          cout << i << " " << j << endl;
        }
      }
    }
    cin >> N;
  }
}