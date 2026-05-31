#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        int maxFactor = 0;
        int minPrice = INT_MAX;

        for (auto& item : items) {
            maxFactor = max(maxFactor, item[0]);
            minPrice = min(minPrice, item[1]);
        }

        vector<int> freq(maxFactor + 1, 0);

        for (auto& item : items) {
            freq[item[0]]++;
        }

        // multipleCnt[x] 表示数组中有多少个 factor 是 x 的倍数
        vector<int> multipleCnt(maxFactor + 1, 0);

        for (int x = 1; x <= maxFactor; x++) {
            if (freq[x] == 0) continue;

            for (int multiple = x; multiple <= maxFactor; multiple += x) {
                multipleCnt[x] += freq[multiple];
            }
        }

        vector<pair<int, int>> bonus;

        for (auto& item : items) {
            int factor = item[0];
            int price = item[1];

            // 排除自己
            int freeCnt = multipleCnt[factor] - 1;

            if (freeCnt > 0) {
                bonus.push_back({price, freeCnt});
            }
        }

        sort(bonus.begin(), bonus.end());

        long long money = budget;
        long long ans = 0;
        long long cheapest = minPrice;

        for (auto [price, freeCnt] : bonus) {
            // 买一份 price，最多获得 2 件。
            // 如果 price >= 2 * cheapest，不如买两个最便宜商品。
            if ((long long)price >= 2 * cheapest) {
                break;
            }

            long long canBuy = money / price;
            long long take = min<long long>(canBuy, freeCnt);

            ans += take * 2;
            money -= take * price;
        }

        // 剩余预算全部买最便宜商品
        ans += money / cheapest;

        return (int)ans;
    }
};