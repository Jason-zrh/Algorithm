#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            // x + nums[i] = k
            if(mp[k - nums[i]] != 0) {
                mp[k - nums[i]]--;
                res++;
            } else {
                mp[nums[i]]++;
            }
        }
        return res;
    }
};
