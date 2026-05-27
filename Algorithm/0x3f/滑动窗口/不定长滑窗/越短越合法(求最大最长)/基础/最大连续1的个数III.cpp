#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0, n = nums.size();
        int ans = 0, cnt0 = 0;

        for(right = 0; right < n; right++)
        {
            if(nums[right] == 0)
                cnt0++;

            while(cnt0 > k)
            {
                if(nums[left] == 0)
                    cnt0--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};