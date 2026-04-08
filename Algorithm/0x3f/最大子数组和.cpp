#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int prefix = 0;
        // 保存前缀和最小
        int ans = INT_MIN, minnum = 0;
        for(int i = 0; i < n; i++)
        {
            // 先更新当前位置前缀和
            prefix += nums[i];
            // 用当前位置前缀和减去前面最小的前缀和
            ans = max(ans, prefix - minnum);
            // 更新最小前缀和
            minnum = min(minnum, prefix);
        }
        return ans;
    }
};