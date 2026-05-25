#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        unordered_map<int, int> mp;
        long long ans = 0, window = 0;
        int n = nums.size();
        int left = 0, right = 0, catagory = 0;

        for(right = 0; right < n; right++){
            // 先入窗口
            int num = nums[right];
            window += num;
            if(mp[num] == 0)
                catagory++;
            mp[num]++;

            // 窗口大小不足
            if(right - left + 1 < k)
                continue;

            // 窗口大小够了，但是需要判断catagory
            if(catagory >= m)
                ans = max(ans, window);

            // 出窗口
            num = nums[left];
            window -= num;
            mp[num]--;
            if(mp[num] == 0)
                catagory--;
            left++;
        }
        return ans;
    }
};