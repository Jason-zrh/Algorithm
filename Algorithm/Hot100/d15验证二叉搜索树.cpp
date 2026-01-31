#include <iostream>
#include <vector>

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

// 前序遍历解法
class Solution
{
public:
    bool Check(TreeNode *root, long long left, long long right)
    {
        if (root == nullptr)
            return true;

        if (root->val <= left || root->val >= right)
            return false;

        return Check(root->left, left, root->val) &&
               Check(root->right, root->val, right);
    }

    bool isValidBST(TreeNode *root)
    {
        return Check(root, LLONG_MIN, LLONG_MAX);
    }
};

// 中序遍历
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class Solution
{
    long long pre = LLONG_MIN;
public:
    bool isValidBST(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        if (!isValidBST(root->left))
        { // 左
            return false;
        }
        if (root->val <= pre)
        { // 中
            return false;
        }
        pre = root->val;
        return isValidBST(root->right); // 右
    }
};
