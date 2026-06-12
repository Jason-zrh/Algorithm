#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int MOD = 1e9 + 7;
        vector<uint64_t> dp(high + 1, 0);
        dp[0] = 1;
        uint64_t ans = 0;
        for(int i = 1; i <= high; i++) {
            if((i - zero) >= 0) {
                dp[i] += (dp[i - zero]) % MOD;
            }
            if((i - one) >= 0) {
                dp[i] += (dp[i - one]) % MOD;
            }
        }
        
        for(int i = low; i <= high; i++) {
            ans += dp[i] % MOD;
        }
        return ans % MOD;
    }
};
