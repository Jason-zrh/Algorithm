#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, right = 0, mid = 0, n = nums.size();
        int res = 0;
        for(right = 0; right < n; right++)
        {
            // mid = ((right + left) / 2);
            // while(nums[mid] + k < nums[right])
            // {
            //      left++;
            //      mid = ((right + left) / 2);
            // }

            while(nums[right] - nums[left] > 2 * k)
                left++;
            
            res = max(res, right - left + 1);
        }
        return res;
    }
};