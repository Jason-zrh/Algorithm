#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        int n = nums.size();
        const long long NEG = -(1LL << 60);
        auto choices = [&](int i) {
            vector<int> res;
            if (s[i] == '0') {
                // 没有标记，用 0 占位
                res.push_back(0);
            } else {
                // 0 表示不移动，覆盖 i
                res.push_back(0);
                // 1 表示向左移动，覆盖 i - 1
                if (i > 0) {
                    res.push_back(1);
                }
            }
            return res;
        };

        auto gain = [&](int p, int move_p, int move_next) -> long long {
            bool covered = false;
            // 下标 p 自己有标记，并且不移动
            if (s[p] == '1' && move_p == 0) {
                covered = true;
            }
            // 下标 p + 1 有标记，并且向左移动到 p
            if (p + 1 < n && s[p + 1] == '1' && move_next == 1) {
                covered = true;
            }
            return covered ? nums[p] : 0;
        };
        // dp[move] 表示处理到当前位置 i，当前标记状态为 move 时，
        // 已经结算完 [0, i - 1] 的最大和
        vector<long long> dp(2, NEG);
        for (int c : choices(0)) {
            dp[c] = 0;
        }
        for (int i = 1; i < n; i++) {
            vector<long long> ndp(2, NEG);
            for (int prev : choices(i - 1)) {
                if (dp[prev] == NEG) continue;
                for (int cur : choices(i)) {
                    ndp[cur] = max(ndp[cur], dp[prev] + gain(i - 1, prev, cur));
                }
            }
            dp = ndp;
        }
        long long ans = NEG;
        for (int last : choices(n - 1)) {
            if (dp[last] == NEG) continue;
            // 最后结算位置 n - 1
            bool covered = (s[n - 1] == '1' && last == 0);
            long long add = covered ? nums[n - 1] : 0;
            ans = max(ans, dp[last] + add);
        }
        return ans;
    }
};
