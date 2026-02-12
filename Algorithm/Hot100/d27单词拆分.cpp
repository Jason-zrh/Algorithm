#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        // 找到最长长度
        int max_len = 0;
        for (auto &s : wordDict)
        {
            max_len = max(max_len, (int)s.length());
        }
        unordered_set<string> mp(wordDict.begin(), wordDict.end());

        int n = s.size();
        vector<bool> dp(n + 1);
        dp[0] = true;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i - 1; j >= max(0, i - max_len); j--)
            {
                if (dp[j] && mp.contains(s.substr(j, i - j)))
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};