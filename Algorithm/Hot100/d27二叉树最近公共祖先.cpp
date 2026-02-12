
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // 如果找到空节点或者p或q，就可以直接返回
        if(root == nullptr || root == p || root == q)
        {
            return root;
        }
        // 递归去左右子树找p，q
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left == nullptr) // 左子树没找到，说明两个都在右侧
            return right;
        if(right == nullptr) // 右子树没找到，说明两个都在左侧
            return left;
        // 左右都找到了直接返回根节点
        return root;
    }
};