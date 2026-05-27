#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int left = 0, right = 0, n = nums.size();
        int ans = 0, window = 0;

        for(right = 0; right < n; right++)
        {
            int num = nums[right];
            window += num;
            mp[num]++;

            while(mp[num] > 1){
                mp[nums[left]]--;
                window -= nums[left];
                left++;
            }

            ans = max(ans, window);
        }
        return ans;
    }
};