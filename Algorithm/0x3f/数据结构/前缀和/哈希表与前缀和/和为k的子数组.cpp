#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int prefix = 0, ans = 0;
        mp[0] = 1;
        // prefix - x = k -> x = prefix - k
        for(int i = 0; i < nums.size(); i++) {
            prefix += nums[i];
            ans += mp[prefix - k];
            mp[prefix]++;
        }
        return ans;
    }
};