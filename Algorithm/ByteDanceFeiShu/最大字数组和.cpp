#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        for(int i = 1; i <= n; i++)
        {
            dp[i] = max((dp[i - 1] + nums[i - 1]), nums[i - 1]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};