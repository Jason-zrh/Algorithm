#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> getAverages(vector<int> &nums, int k)
    {
        int n = nums.size(), left = 0, right = 0;
        long long window = 0;
        vector<int> ans(n, -1);

        for(right = 0; right < n; right++)
        {
            // 入窗口
            window += nums[right];
            // 窗口大小不行
            if(right - left + 1 < (2 * k + 1))
                continue;
            // 窗口大小合格
            ans[right - k] = window / (2 * k + 1);
            // 破坏窗口
            window -= nums[left];
            left++;
        }
        return ans;
    }
};