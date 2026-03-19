#include <unordered_map>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> path;
    vector<vector<int>> ans;

    void dfs(vector<int>& num, vector<bool>& use) {
        if (path.size() == num.size()) {
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < num.size(); i++) {
            // 剪枝关键点：
            // 1. 如果当前元素已经用过，跳过
            // 2. 如果当前元素和前一个相同，且前一个还没用过（说明刚从前一个的回溯里退出来），跳过
            if (use[i] || (i > 0 && num[i] == num[i - 1] && !use[i - 1])) {
                continue;
            }

            use[i] = true;
            path.push_back(num[i]);
            dfs(num, use);
            
            // 回溯
            path.pop_back();
            use[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& num) {
        // 第一步：排序，这是去重的前提
        sort(num.begin(), num.end());
        vector<bool> use(num.size(), false);
        dfs(num, use);
        return ans;
    }
};