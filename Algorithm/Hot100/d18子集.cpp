#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<vector<int>> ans;

    vector<int> path;

    void dfs(vector<int> &nums, int pos)
    {
        // 边界条件?
        if(pos == nums.size())
        {
            ans.emplace_back(path);
            return;
        }
        // 非边界条件

        // nums[pos]位置的数字选或者不选
        path.push_back(nums[pos]);
        dfs(nums, pos + 1);
        path.pop_back();

        dfs(nums, pos + 1);
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        if(nums.size() == 0)
            return {};
        
        dfs(nums, 0);
        return ans;
    }
};