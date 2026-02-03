#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<vector<int>> ans;
    int sum;
    vector<int> path;
    

    void dfs(vector<int> &candidates, int target, int pos)
    {
        // 边界约束条件
        if(sum == target)
        {
            ans.push_back(path);
            return;
        }

        // 剪枝
        if(sum > target)
            return;

        // 非边界约束条件
        for(int i = pos; i < candidates.size(); i++)
        {
            path.push_back(candidates[i]);
            sum += candidates[i];
            dfs(candidates, target, i);
            sum -= candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        dfs(candidates, target, 0);
        return ans;
    }
};