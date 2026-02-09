#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 爆内存了
int maxProduct(vector<int> &nums)
{
    int m = nums.size();
    int ans = -0x3f;
    vector<vector<int>> dp(m);
    for (int i = 0; i < m; i++)
    {
        for (int j = i; j < m; j++)
        {
            if (i == j)
                dp[i].push_back(nums[j]);
            else
                dp[i].push_back(dp[i][j - 1] * nums[j]);
            ans = max(ans, dp[i].back());
        }
    }
    return ans;
}

// 维护两个dp数组，一个fmax 一个 fmin 代表以下标为i为结尾的子数组的最大和最小乘积
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int ans = INT_MIN;
        int n = nums.size();
        vector<int> fmax(n + 1, 1);
        vector<int> fmin(n + 1, 1);
        for(int i = 1; i <= n; i++)
        {
            int x = nums[i - 1];
            fmax[i] = max(max(fmax[i - 1] * x, fmin[i - 1] * x), x);
            fmin[i] = min(min(fmax[i - 1] * x, fmin[i - 1] * x), x);
            ans = max(ans, fmax[i]);
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {2, 3, -2, 4};
    cout << maxProduct(nums) << endl;
    return 0;
}