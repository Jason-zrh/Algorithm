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
     * @param o1 int整型
     * @param o2 int整型
     * @return int整型
     */
    TreeNode* dfs(TreeNode *root, int o1, int o2)
    {
        if(root == nullptr || root->val == o1 || root->val == o2)
            return root;
        TreeNode* left = dfs(root->left, o1, o2);
        TreeNode* right = dfs(root->right, o1, o2);
        
        if(left == nullptr)
            return right;
        if(right == nullptr)
            return left;
        return root;
    }
    int lowestCommonAncestor(TreeNode *root, int o1, int o2)
    {
        return dfs(root, o1, o2)->val;
    }
};