#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> res;
        // nums[i] + x = target -> x = target = nums[i]
        for(int i = 0; i < nums.size(); i++) {
            int x = target - nums[i];
            if(mp.find(x) != mp.end()) {
                res = {i, mp[x]};
                break;
            }
            mp[nums[i]] = i;
        }
        return res;
    }
};
