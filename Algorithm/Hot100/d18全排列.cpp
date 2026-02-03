#include <iostream>
#include <vector>
#include <string>

using namespace std;


// 排列型回溯

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    
    // 用 visited 数组记录数字是否已被使用
    void dfs(vector<int>& nums, vector<bool>& used) {
        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            // 如果数字没用过，就选它
            if (!used[i]) {
                path.push_back(nums[i]);
                used[i] = true;   // 标记已使用
                dfs(nums, used);  // 进入下一层
                used[i] = false;  // 回溯：撤销标记
                path.pop_back();  // 回溯：移出路径
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        dfs(nums, used);
        return ans;
    }
};