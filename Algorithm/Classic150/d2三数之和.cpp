#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // nums[j] + nums[k] = -nums[i]
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 2; i++)
        {
            // i与i - 1重复, 这里要确保i > 0
            if (i && nums[i] == nums[i - 1])
                continue;
            int j = i + 1, k = n - 1;
            while (j < k)
            {
                if (nums[j] + nums[k] > -nums[i])
                    k--;
                else if (nums[j] + nums[k] < -nums[i])
                    j++;
                else
                {
                    // 找到结果
                    ans.push_back({nums[i], nums[j], nums[k]});
                    // 把j，k重复的部分去掉
                    j++, k--;
                    while (nums[j] == nums[j - 1] && j < k)
                        j++;

                    while (nums[k] == nums[k + 1] && j < k)
                        k--;
                }
            }
        }
        return ans;
    }
};