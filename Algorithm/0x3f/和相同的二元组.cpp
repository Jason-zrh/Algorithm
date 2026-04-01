#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    // 计算和小于等于 goal 的连续子数组个数
    int countAtMost(vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        int ans = 0, n = nums.size();
        int left = 0;
        int sum = 0;
        
        for (int right = 0; right < n; right++) {
            sum += nums[right];
            
            // 当和大于目标时，收缩左边界
            while (sum > goal) {
                sum -= nums[left];
                left++;
            }
            
            // 以 right 为终点，左端点可以在 [left, right] 之间的任意位置
            // 共有 right - left + 1 个子数组
            ans += (right - left + 1);
        }
        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // 恰好等于 goal = (<= goal) - (<= goal - 1)
        return countAtMost(nums, goal) - countAtMost(nums, goal - 1);
    }
};