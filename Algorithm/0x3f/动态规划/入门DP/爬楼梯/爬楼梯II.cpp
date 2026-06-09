#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        int n = costs.size();
        vector<int> dp(n + 1, 0);
        dp[0] = costs[0];
        for(int i = 1; i <= n; i++) {
            int res = INT_MAX;
            for(int j = max(i - 3, 0); j < i; j++) {
                res = min(res, dp[j] + (j - i) * (j - i));
            }
            dp[i] = res + costs[i - 1];
        }
        return dp[n];
    }
};

