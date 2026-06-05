#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;


class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }
        long long ans = 0;
        for (int j = 1; j + 1 < nums.size(); j++) {
            long long target = 1LL * nums[j] * 2;
            if (target < INT_MIN || target > INT_MAX) {
                continue;
            }
            auto it = mp.find((int)target);
            if (it == mp.end()) continue;

            vector<int>& pos = it->second;

            long long left = lower_bound(pos.begin(), pos.end(), j) - pos.begin();
            long long right = pos.end() - upper_bound(pos.begin(), pos.end(), j);

            ans = (ans + left * right) % MOD;
        }

        return ans;
    }
};
