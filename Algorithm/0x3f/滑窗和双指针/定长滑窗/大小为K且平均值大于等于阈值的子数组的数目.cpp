#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    int numOfSubarrays(vector<int> &arr, int k, int threshold)
    {
        int n = arr.size();
        int left = 0, right = 0;
        int ans = 0, window = 0;
        for(right = 0; right < n; right++)
        {
            window += arr[right];
            if(right - left + 1 < k)
                continue;

            if((window / k) >= threshold)
                ans++;

            window -= arr[left];
            left++;
        }
        return ans;
    }
};