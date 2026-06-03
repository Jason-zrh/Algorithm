#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int digitalMax(int num) {
        int res = -1;
        while(num / 10 != 0) {
            res = max(res, num % 10);
            num /= 10;
        }
        res = max(res, num);
        return res;
    }

    int maxSum(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            int n = digitalMax(nums[i]);
            if(mp.find(n) != mp.end()) {
                res = max(res, mp[n] + nums[i]);
            }
            mp[n] = max(mp[n], nums[i]);
        }
        return res == 0 ? -1 : res;
    }
};

