#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// 参照两数之和II, 使用相向双指针, 但是在那之前需要先进行排序

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    // i < j < k
    for (int i = 0; i < nums.size() - 2; i++)
    {
        if (i && nums[i] == nums[i - 1])
            continue;
        if (nums[i] + nums[i + 1] + nums[i + 2] > 0)
            break;
        if (nums[i] + nums[nums.size() - 1] + nums[nums.size() - 2] < 0)
            continue;
        int j = i + 1, k = nums.size() - 1;
        while (j < k)
        {
            if (nums[i] + nums[j] + nums[k] < 0)
                j++;
            else if (nums[i] + nums[j] + nums[k] > 0)
                k--;
            else // 找到等于0的地方了
            {
                ans.push_back({nums[i], nums[j], nums[k]});
                j++;
                while (j < k && nums[j] == nums[j - 1]) j++;
                k--;
                while (j < k && nums[k] == nums[k + 1]) k--;
            }
        }
    }
    return ans;
}

int main()
{

    return 0;
}