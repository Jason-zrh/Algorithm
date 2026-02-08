#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 1)
            return 1;
        int _max = -0x3f;
        // dp[i]代表从0 - i中最长子序列是多少
        vector<int> dp(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        int ret = 1;
        for (int k = 0; k < nums.size(); k++) {
            ret = max(dp[k], ret);
        }
        return ret;
    }
};