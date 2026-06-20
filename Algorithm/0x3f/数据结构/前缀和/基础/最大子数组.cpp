#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int premin = 0;
        int prefix = 0, ans = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            prefix += nums[i];
            ans = max(ans, prefix - premin);
            premin = min(premin, prefix);
        }
        return ans;
    }
};