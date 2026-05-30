#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int left = 0, right = 0, n = nums.size();
        int res = 1e9, window = 0;

        for(right = 0; right < n; right++){
            // 只有第一次才算值
            if(mp[nums[right]] == 0)
                window += nums[right];
            mp[nums[right]]++;

            while(window >= k){
                res = min(res, right - left + 1);
                // 只有扣到0才减值
                mp[nums[left]]--;
                if(mp[nums[left]] == 0)
                    window -= nums[left];
                left++;
            }
        }
        
        return res == 1e9 ? -1 : res;
    }
};

