#include <unordered_map>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param num int整型vector
     * @return int整型vector<vector<>>
     */
    vector<int> path;
    vector<vector<int>> ans;
    void dfs(vector<int> &num, vector<bool> &use)
    {
        if(path.size() == num.size())
        {
            ans.emplace_back(path);
            return;
        }

        for(int i = 0; i < num.size(); i++)
        {
            // 如果一个没用过
            if(use[i] == false)
            {
                use[i] = true;
                path.push_back(num[i]);
                dfs(num, use);
                // 回溯
                path.pop_back();
                use[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int> &num)
    {
        vector<bool> use(num.size(), false);
        dfs(num, use);
        return ans;
    }
};