#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            int x = -1 * nums[i];
            if(mp.find(x) != mp.end()) {
                res = max(res, abs(x));
            }
            mp[nums[i]]++;
        }
        return res == 0 ? -1 : res;
    }
};