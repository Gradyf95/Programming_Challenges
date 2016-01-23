/* 
 * File:   main.cpp
 * Author: Grady
 *
 * Created on November 9, 2015, 5:22 PM
 */

#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

map<string, int> ladder; 

int main()
{
    int maxL = 0;
    string w2;
    while (cin >> w2)
    {
        int length = 1;
        for (int i = 0; i <= w2.size(); ++i)
            for (char c = 'a'; c <= 'z'; ++c)       
            {
                string w1(w2);
                w1.insert(i, 1, c);
                if (w1 > w2)
                    break;
                if (ladder.count(w1))
                    length = max(length, ladder[w1] + 1);
            }
        for (int i = 0; i < w2.size(); ++i)
        {
            string w1(w2);
            w1.erase(i, 1);
            if (ladder.count(w1))
                length = max(length, ladder[w1] + 1);
        }
        for (int i = 0; i < w2.size(); ++i)
            for (char c = 'a'; c <= 'z' && c != w2[i]; ++c)
            {
                string w1(w2);
                w1[i] = c;
                if (w1 > w2)
                    break;
                if (ladder.count(w1))
                    length = max(length, ladder[w1] + 1);
            }
        ladder[w2] = length;
        maxL = max(maxL, length);
    }
    cout << maxL << endl;
}