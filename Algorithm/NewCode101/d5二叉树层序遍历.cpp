#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <queue>
#include <unordered_set>

using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @return int整型vector<vector<>>
     */

    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if(root == nullptr)
            return {};
        vector<vector<int>> ans;
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> level;
            int n = q.size();
            for(int i = 0; i < n; i++)
            {
                TreeNode* front = q.front();
                level.push_back(front->val);
                q.pop();
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            }
            ans.emplace_back(level);
        }

        return ans;
    }
};