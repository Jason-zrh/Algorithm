#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = 1e9, window = 0, n = nums.size();
        int left = 0, right = 0;
        for(right = 0; right < n; right++)
        {
            window += nums[right];
            while(window >= target)
            {
                res = min(res, right - left + 1);
                window -= nums[left];
                left++;
            }
        }

        return res == 1e9 ? 0 : res;
    }
};
