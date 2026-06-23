#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> mp;
        int prefix = 0, ans = 0;
        mp[0] = 1;
        for(int i = 0; i < nums.size(); i++) {
            prefix += nums[i];
            ans += mp[prefix - goal];
            mp[prefix]++;
        }
        return ans;
    }
};
