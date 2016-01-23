/* 
 * File:   main.cpp
 * Author: Grady
 *
 * Created on September 18, 2015, 10:50 AM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
    int N = 0;
 
    cin >> N;
 
    for (int i = 0; i < N; i++)
    {
        vector<int> street_numbers;
 
        int relatives;
        cin >> relatives;
         
        for (int j = 0; j < relatives; j++)
        {
            int street;
            cin >> street;
            street_numbers.push_back(street);
        }
        sort(street_numbers.begin(), street_numbers.end());
        int optimal = 0;
 
        optimal = street_numbers[street_numbers.size()/2];
             
        long long int distance = 0;
        for (int j = 0; j < street_numbers.size(); j++)
           distance += abs(optimal - street_numbers[j]);
        cout << distance;
        cout << endl;
    }
    return 0;
}