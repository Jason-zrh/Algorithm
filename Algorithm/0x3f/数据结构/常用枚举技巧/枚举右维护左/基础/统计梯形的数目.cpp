#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long MOD = 1e9 + 7;

    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, long long> cntY;
        for (auto& p : points) {
            cntY[p[1]]++;
        }
        long long ans = 0;
        long long sum = 0; // 前面所有高度可形成的线段数量之和
        for (auto& [y, cnt] : cntY) {
            if (cnt < 2) {
                continue;
            }
            long long lines = cnt * (cnt - 1) / 2;
            lines %= MOD;
            ans = (ans + sum * lines) % MOD;
            sum = (sum + lines) % MOD;
        }
        return ans;
    }
};

