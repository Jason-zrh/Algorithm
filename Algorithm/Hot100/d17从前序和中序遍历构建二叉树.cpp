#include <iostream>
#include <vector>
#include <algorithm>

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
    TreeNode *build(vector<int> &preorder, int p_start, int p_end, vector<int> &inorder, int i_start, int i_end)
    {
        if (p_start == p_end)
            return nullptr;

        // preorder的第一个位置就是根节点
        TreeNode *root = new TreeNode(preorder[p_start]);

        // 计算左子树的大小从而划分子树
        int index = i_start;
        while (index < i_end)
        {
            if (inorder[index] != preorder[p_start])
                index++;
            else
                break;
        }
        int size = index - i_start;
        // 左子树继续递归建立
        root->left = build(preorder, p_start + 1, p_start + 1 + size,
                           inorder, i_start, index);
        // 右子树也继续递归建立
        root->right = build(preorder, p_start + 1 + size, p_end,
                            inorder, index + 1, i_end);
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        // 左闭右开
        return build(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};
