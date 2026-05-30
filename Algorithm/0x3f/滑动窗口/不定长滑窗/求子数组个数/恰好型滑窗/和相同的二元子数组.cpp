#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // 至少 - 越长越合法
    int solve(vector<int>& nums, int goal) {
        if(goal < 0)
            return 0;
        int res = 0, window = 0;
        int left = 0, right = 0, n = nums.size();
        for(right = 0; right < n; right++) {
            window += nums[right];
            while(window >= goal && left <= right) {
                res += (n - right);
                window -= nums[left];
                left++;
            }
        }
        return res;
    }

    // (>= k) - (>= k - 1)
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums, goal) - solve(nums, goal + 1);
    }   
};