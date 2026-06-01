#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> mp;
        // nums[i] == nums[j] 且 i < j
        for(int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            if(mp.find(x) != mp.end()) {
                res += mp[x];
            }
            mp[x]++;
        }
        return res;
    }
};