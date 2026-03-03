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
    TreeNode *build(vector<int> &preorder, int pbegin, int pend, vector<int> &inorder, int ibegin, int iend)
    {
        if (pbegin == pend)
            return nullptr;

        // 第一个节点是root
        TreeNode *root = new TreeNode(preorder[pbegin]);

        int index = ibegin;
        while (index < iend)
        {
            if (inorder[index] != preorder[pbegin])
                index++;
            else
                break;
        }

        int leftlen = index - ibegin;
        // 递归建立左右子树
        root->left = build(preorder, pbegin + 1, pbegin + 1 + leftlen, inorder, ibegin, index);
        root->right = build(preorder, pbegin + 1 + leftlen, pend, inorder, index + 1, iend);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return build(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};