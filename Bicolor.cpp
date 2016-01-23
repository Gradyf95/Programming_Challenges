#include <iostream>

using namespace std;

int map[199][199];
int graph[199];
bool bicolor;
int flag[199];

void check(int n)
{
    for(int i = 0; i < graph[n] && bicolor; i++)
    {
        if(flag[map[n][i]] == -1)
        {
            flag[map[n][i]] = 1 - flag[n];
            check(map[n][i]);
        }
        else if(flag[n] == flag[map[n][i]]) 
           bicolor = false;
    }
}

int main()
{
    int nodes, edges, p1, p2;
    
    while(true)
    {
        cin >> nodes;
        if(nodes == 0) 
           break;
        cin >> edges;
        
        for(int i = 0; i < nodes; i++) 
           graph[i] = 0;
        
        for(int i = 0; i < edges; i++)
        {
            cin >> p1 >> p2;
            map[p1][graph[p1]] = p2;
            graph[p1]++;
            map[p2][graph[p2]] = p1;
            graph[p2]++;
        }
        
        bicolor = true;
        for(int i = 0; i < nodes; i++) 
           flag[i] = -1;        
        for(int i = 0; i < nodes && bicolor; i++)
        {
            if(flag[i] == -1)
            {
                flag[i] = 0;
                check(i);
            }
        }
        
        if(bicolor) 
           cout << "BICOLORABLE." << endl;
        else 
           cout << "NOT BICOLORABLE." << endl;
    }
    return 0;
}