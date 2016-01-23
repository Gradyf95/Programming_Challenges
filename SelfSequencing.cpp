#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#define nummax    2000000001
using namespace std;

int main(int argc, char* argv[])
{
   int nums[700000];
   int size = 0;
   int n;
   int i;
   nums[0] = 1;
   nums[1] = 2;
   nums[2] = 4;
   for (i = 1; nums[nums[i] - 1] < nummax; ++i)
   {
       for (int j = nums[i]; j < nums[i + 1]; ++j)
           nums[j] = nums[j - 1] + i + 1;
   }
   size = nums[i] - 1;
   while (cin >> n && n)
   {
       cout << upper_bound(nums, nums + size, n) - nums << endl;
   }
   return 0;
}