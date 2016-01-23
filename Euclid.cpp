/* 
 * File:   main.cpp
 * Author: Grady
 *
 * Created on October 22, 2015, 2:16 PM
 */

#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

long long int X, Y, D;
void Euclid(long long int A, long long int B)
{
    if(B == 0)
    {
        X = 1;
        Y = 0;
        D = A;
        return;
    }
    Euclid(B, (A%B));
    long long int x1, y1;
    x1 = Y;
    y1 = X - (A / B) * Y;
    X = x1;
    Y = y1;
}


int main()
{
    long long int aIn, bIn;
    while(scanf("%lld %lld", &aIn, &bIn) == 2)
    {
        if(aIn == 0) 
           swap(aIn, bIn);
        Euclid(aIn, bIn);
        printf("%lld %lld %lld\n", X, Y, D);
    }
	return 0;
}