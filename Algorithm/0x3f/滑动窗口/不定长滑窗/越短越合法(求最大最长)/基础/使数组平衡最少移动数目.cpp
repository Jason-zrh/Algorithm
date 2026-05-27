#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, right = 0, n = nums.size();
        int ans = 0;
        for(right = 0; right < n; right++)
        {
            while(nums[right] > (long long)nums[left] * k)
                left++;
            
            ans = max(ans, right - left + 1);
        }
        return n - ans;
    }
};