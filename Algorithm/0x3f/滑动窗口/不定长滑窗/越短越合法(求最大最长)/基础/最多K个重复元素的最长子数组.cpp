#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int left = 0, right = 0, n = nums.size();
        int ans = 0;

        for(right = 0; right < n; right++)
        {
            mp[nums[right]]++;

            while(mp[nums[right]] > k)
            {
                mp[nums[left]]--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
