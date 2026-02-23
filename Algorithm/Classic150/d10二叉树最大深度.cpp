#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

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
    int ans = 0;
    void dfs(TreeNode* root, int depth)
    {
        if(root == nullptr)
        {
            ans = max(ans, depth);
            return;
        }
        depth++;
        dfs(root->left, depth);
        dfs(root->right, depth);
    }

    int maxDepth(TreeNode *root)
    {
        dfs(root, 0);
        return ans;
    }
};