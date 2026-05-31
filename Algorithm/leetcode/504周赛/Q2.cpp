#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> factor(n), price(n);
        for (int i = 0; i < n; i++) {
            factor[i] = items[i][0];
            price[i] = items[i][1];
        }

        vector<int> freeCnt(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                // 注意：是 factor[i] 整除 factor[j]
                if (factor[j] % factor[i] == 0) {
                    freeCnt[i]++;
                }
            }
        }

        vector<int> dp(budget + 1, 0);

        for (int i = 0; i < n; i++) {
            vector<int> ndp = dp;

            int cost = price[i];
            int firstGain = 1 + freeCnt[i];

            // 第一次购买：0/1 背包
            for (int b = cost; b <= budget; b++) {
                ndp[b] = max(ndp[b], dp[b - cost] + firstGain);
            }

            // 后续重复购买：完全背包
            for (int b = cost; b <= budget; b++) {
                ndp[b] = max(ndp[b], ndp[b - cost] + 1);
            }

            dp = ndp;
        }

        return dp[budget];
    }
};