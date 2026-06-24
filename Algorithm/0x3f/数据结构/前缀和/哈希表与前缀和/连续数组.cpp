#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // 存的是最先出现的位置
        unordered_map<int, int> mp;
        int ans = 0;
        mp[0] = -1;
        int prefix = 0;
        // (prefix - x) * 2 = r - l
        // 2 * prefix - r = 2 * x - l
        for(int i = 0; i < nums.size(); i++) {
            prefix += nums[i];
            if(mp.find((2 * prefix) - (i + 1)) != mp.end()) {
                ans = max(ans, i - mp[(2 * prefix) - (i + 1)]);
            } else {
                mp[(2 * prefix) - (i + 1)] = i;
            }
        }
        return ans;
    }
};

