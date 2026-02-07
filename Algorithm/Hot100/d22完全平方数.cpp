#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1);
        for(int i = 1; i <= n; i++)
        {
            int _min = 0x3f;
            for(int j = 1; j * j <= i; j++)
            {
                _min = min(_min, dp[i - j * j]);
            }
            dp[i] = _min + 1;
        }
        return dp[n];
    }
};