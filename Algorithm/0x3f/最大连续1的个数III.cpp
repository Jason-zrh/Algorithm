#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), left = 0;
        int cnt = 0, ans = 0;
        for(int right = 0; right < n; right++)
        {
            if(nums[right] == 0)
                cnt++;
            
            while(cnt > k)
            {
                if(nums[left] == 0)
                    cnt--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};