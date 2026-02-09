#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 0 - 1背包？

bool canPartition(vector<int> &nums)
{
    int s = 0;
    for(auto& e : nums)
        s += e;
    if (s % 2)
        return false;

    s /= 2; // 注意这里把 s 减半了
    int n = nums.size();
    vector f(n + 1, vector<int>(s + 1));
    f[0][0] = true;
    for (int i = 0; i < n; i++)
    {
        int x = nums[i];
        for (int j = 0; j <= s; j++)
        {
            f[i + 1][j] = (j >= x && f[i][j - x]) || f[i][j];
        }
    }
    return f[n][s];
}

int main()
{
    vector<int> nums = {1, 5, 11, 5};
    cout << canPartition(nums) << endl;
    return 0;
}