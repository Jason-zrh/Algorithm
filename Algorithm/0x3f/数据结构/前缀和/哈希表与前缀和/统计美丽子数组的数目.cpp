#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long ans = 0, prefix = 0;
        unordered_map<int, int> cnt({0, 1});
        for(auto& e : nums) {
            prefix ^= e;
            ans += cnt[prefix];
            cnt[prefix]++;
        }
        return ans;
    }
};

