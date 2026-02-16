#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        int sum = 0;
        int left = 0, right = 0;
        for(right = 0; right < n; right++)
        {
            // 入窗口
            sum += nums[right];

            // 出窗口, 这里因为要找最短的，所以要一直缩小范围
            while(sum - nums[left] >= target)
            {
                sum -= nums[left];
                left++;
            }

            // 符合条件记录答案
            if(sum >= target)
                ans = min(ans, right - left + 1);
        }
        return ans == INT_MAX ? 0 : ans;
    }
};