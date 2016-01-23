/* 
 * File:   main.cpp
 * Author: Grady
 *
 * Created on September 18, 2015, 10:50 AM
 */

#include <cstdlib>
#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

bool compare(pair<string,int> x, pair<string,int> y)
{
    return x.second > y.second;
}

void getSwaps(vector< pair<string, int> > &swaps, vector< pair<string, int> > &original_order, int n)
{
   for (int j = n-1, next = n-1; j >= 0; j--)
   {
       if (original_order[j].second != next) 
          swaps.push_back(original_order[j]);
       else next--;
   }
   sort(swaps.begin(), swaps.end(), compare);
}

int main(int argc, char** argv)
{
    int N = 0;
    scanf("%d",&N);
    char input[5000];
 
    gets(input);
    for (int i = 0; i < N; i++)
    {
        vector<string> original;
        map<string,int> desired;
 
        int n;
        scanf("%d",&n);
        gets(input);
 
        for (int j = 0; j < n; j++)
        {
            gets(input);
            original.push_back(input);
        }
 
        for (int j = 0; j < n; j++)
        {
            gets(input);
            desired[input] = j;
        }
 
        vector< pair<string, int> > original_order;
 
        for (int j = 0; j < n; j++)
        {
            original_order.push_back(make_pair(original[j], desired[original[j]]));
        }
 
        vector< pair<string, int> > swaps;
        getSwaps(swaps, original_order, n);
 
        for (int j = 0; j < swaps.size(); j++)
           cout << swaps[j].first << endl;
        cout << endl;
    }
    return 0;
}