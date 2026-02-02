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
    TreeNode *build(vector<int> &preorder, int pre_start, int pre_end,
                    vector<int> &postorder, int pos_start, int pos_end)
    {
        if (pre_start == pre_end)
            return nullptr;

        // 根节点就是这个
        TreeNode *root = new TreeNode(preorder[pre_start]);
        // 左子树的根节点默认为pre[1]

        if (pre_end - pre_start == 1)
            return root;

        int val = preorder[pre_start + 1];

        // 在postorder中找左子树根节点
        int index = pos_start;
        while (index < pos_end)
        {
            if (postorder[index] != val)
                index++;
            else
                break;
        }

        int left_size = index - pos_start + 1;

        root->left = build(preorder, pre_start + 1, pre_start + 1 + left_size,
                           postorder, pos_start, pos_start + left_size);

        root->right = build(preorder, pre_start + 1 + left_size, pre_end,
                            postorder, pos_start + left_size, pos_end - 1);

        return root;
    }
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {
        return build(preorder, 0, preorder.size(), postorder, 0, postorder.size());
    }
};