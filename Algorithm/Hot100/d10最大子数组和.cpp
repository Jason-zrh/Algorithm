#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int maxSubArray(vector<int> &nums)
{
    // 前缀和 + 贪心
    int ans = -1e6;
    int pre_min = 0; // 前缀和中的最小值
    int pre = 0;
    for (int x : nums)
    {
        pre += x;                      // 更新前缀和
        ans = max(ans, pre - pre_min); // 用前缀和减掉最小前缀和更新答案
        pre_min = min(pre_min, pre);   // 更新最小前缀和
    }
    return ans;
}

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubArray(nums) << endl;
    return 0;
}