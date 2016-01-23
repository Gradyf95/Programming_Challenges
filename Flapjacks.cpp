/* 
 * File:   main.cpp
 * Author: Grady
 *
 * Created on September 18, 2015, 10:19 AM
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

bool isSorted(vector<int> flapjacks)
{
   for(int i = 0; i < flapjacks.size()-1; i++)
      if (flapjacks[i] > flapjacks[i+1])
         return false;
   return true;
}

bool swaps(vector<int> &flapjacks,int end, string &moves)
{
    int maxi = -1;
    for (int i = 0; i < end; i++)
    {
        if (i == 0 || flapjacks[i] > flapjacks[maxi]) 
           maxi = i;
    }
    if (maxi == 0) 
       return true;
    if (maxi == end-1) 
       return false;
 
    reverse(flapjacks.begin(), flapjacks.begin() + maxi + 1);
    ostringstream s;
    s << flapjacks.size() - maxi;
    moves += s.str() + " ";
 
    return true;
}
int main()
{
    char stack[5000];
    while(gets(stack))
    {
        string moves="";
        vector<int> flapjacks;
        stringstream stream1(stack);
 
        while(!stream1.eof()) 
        {
            int T;
            stream1 >> T;
            cout << T << " ";
            flapjacks.push_back(T);
        }
        cout.seekp((int)cout.tellp()-1);
        cout << endl;
        stream1.clear();
        for (int i = flapjacks.size(); !isSorted(flapjacks); i--)
        {
            if(swaps(flapjacks, i, moves))
                {
                    ostringstream stream2;
                    stream2 << flapjacks.size() - i  + 1;
                    reverse(flapjacks.begin(), flapjacks.begin() + i);
                    moves += stream2.str()  + " ";
                }
        }
        cout << moves << "0\n";
    }
    return 0;
}