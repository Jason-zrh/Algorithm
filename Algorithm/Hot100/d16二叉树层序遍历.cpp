#include <iostream>
#include <vector>
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

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if(root == nullptr)
        return ans;

    queue<TreeNode* > q;
    q.push(root);
    while(!q.empty())
    {
        vector<int> level;
        int n = q.size(); // 记录循环次数
        for(int i = 0; i < n; i++)
        {
            TreeNode* head = q.front();
            q.pop();
            if(head->left)
                q.push(head->left);
            if(head->right)
                q.push(head->right);
            level.push_back(head->val);
        }
        ans.push_back(level);
    }
    return ans;
}