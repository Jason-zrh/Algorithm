#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution 
{
public:
    double findMaxAverage(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int left = 0, right = 0;
        double ans = -1e10, window = 0;
        for(right = 0; right < n; right++)
        {
            // 入窗口
            window += nums[right];
            // 窗口大小不够
            if(right - left + 1 < k)
                continue;
            // 窗口合法，更新结果
            ans = max(ans, window / k);
            // 左指针右移，破坏窗口
            window -= nums[left];
            left++;
        }
        return ans;
    }
};