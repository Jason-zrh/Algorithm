#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k == 0){
            return 0;
        }
        
        int res = 0, window = 1;
        int left = 0, right = 0, n = nums.size();
        for(right = 0; right < n; right++){
            // 入窗口
            window *= nums[right];
            // 窗口非法
            while(window >= k){
                window /= nums[left];
                left++;
            }
            res += (right - left + 1);
        }
        return res;
    }
};