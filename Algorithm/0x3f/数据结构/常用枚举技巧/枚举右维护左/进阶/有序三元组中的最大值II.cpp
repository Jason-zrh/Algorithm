#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> suf_max(n + 1);
        for (int i = n - 1; i > 1; i--) {
            suf_max[i] = max(suf_max[i + 1], nums[i]);
        }

        long long ans = 0;
        int pre_max = nums[0];
        for (int j = 1; j < n - 1; j++) {
            ans = max(ans, 1LL * (pre_max - nums[j]) * suf_max[j + 1]);
            pre_max = max(pre_max, nums[j]);
        }
        return ans;
    }
};
