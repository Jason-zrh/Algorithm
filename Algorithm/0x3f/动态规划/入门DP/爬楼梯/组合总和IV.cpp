#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        for(int i = 1; i <= target; i++) {
            long long tmp = 0;
            // 遍历当前位置 - nums的位置
            for(auto& n : nums) {
                if((i - n) == 0) {
                    tmp++;
                }else if((i - n) > 0) {
                    tmp += dp[i - n];
                }
            }
            dp[i] = tmp;
        }
        return dp[target];
    }
};