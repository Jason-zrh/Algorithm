#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        vector<vector<int>> res;
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            // x + nums[i] = target
            if(mp[target - nums[i]] != 0) {
                res.push_back({target - nums[i], nums[i]});
                mp[target - nums[i]]--;
            }else {
                mp[nums[i]]++;
            }
        }
        return res;
    }
};

