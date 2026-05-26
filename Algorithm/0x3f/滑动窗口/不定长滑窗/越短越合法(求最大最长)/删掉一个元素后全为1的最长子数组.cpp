#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cnt = 0;
        int ans = 0, n = nums.size();
        int left = 0, right = 0;
        for(right = 0; right < n; right++)
        {
            if(nums[right] == 0)
                cnt++;
                
            while(cnt > 1)
            {
                if(nums[left] == 0)
                    cnt--;
                left++;
            }
            ans = max(ans, right - left);
        }
        return ans;
    }
};