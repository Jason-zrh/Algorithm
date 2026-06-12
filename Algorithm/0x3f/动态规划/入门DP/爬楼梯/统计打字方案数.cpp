#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int countTexts(string pressedKeys) {
        const int MOD = 1e9 + 7;
        int n = pressedKeys.size();
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            int limit = (pressedKeys[i - 1] == '7' || pressedKeys[i - 1] == '9') ? 4 : 3;
            for (int j = 1; j <= limit; j++) {
                if (i - j < 0) {
                    break;
                }
                if (pressedKeys[i - j] != pressedKeys[i - 1]) {
                    break;
                }
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
        return dp[n];
    }
};

