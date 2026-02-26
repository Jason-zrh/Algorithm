#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (root == nullptr)
            return {};
        vector<vector<int>> ans;
        deque<TreeNode *> dq;
        int dirct = 0; // 标记从左往右
        dq.push_back(root);
        while (!dq.empty())
        {
            int n = dq.size();
            vector<int> level;
            if (dirct == 0)
            {
                for (int i = 0; i < n; i++)
                {
                    // 从左往右
                    TreeNode *node = dq.front();
                    dq.pop_front();
                    level.push_back(node->val);
                    if (node->left)
                        dq.push_back(node->left);
                    if (node->right)
                        dq.push_back(node->right);
                }
            }
            else
            {
                for (int i = 0; i < n; i++)
                {
                    // 从右往左
                    TreeNode *node = dq.back();
                    dq.pop_back();
                    level.push_back(node->val);
                    if (node->right)
                        dq.push_front(node->right);
                    if (node->left)
                        dq.push_front(node->left);
                }
            }
            dirct = (dirct + 1) % 2;
            ans.push_back(level);
        }
        return ans;
    }
};