#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        if (amount == 0)
            return 0;

        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            int _min = INT_MAX;
            for (int c : coins)
            {
                if (i - c < 0)
                    continue;
                if (dp[i - c] == -1)
                    continue; // ⭐ 核心修复点
                _min = min(_min, dp[i - c]);
            }
            dp[i] = (_min == INT_MAX ? -1 : _min + 1);
        }

        return dp[amount];
    }
};