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
    TreeNode* build(vector<int> &inorder, int ibegin, int iend, vector<int> &postorder, int pbegin, int pend)
    {
        if(pbegin == pend)
            return nullptr;
        // 左闭右开，post的最后一个值就是根节点
        TreeNode* root = new TreeNode(postorder[pend - 1]);

        // 计算左子树的大小
        int index = ibegin;
        while(index < iend)
        {
            if(inorder[index] != postorder[pend - 1])
                index++;
            else
                break;
        }

        int leftlen = index - ibegin;
        // 递归构建左右子树
        root->left = build(inorder, ibegin, index, postorder, pbegin, pbegin + leftlen);
        root->right = build(inorder, index + 1, iend, postorder, pbegin + leftlen, pend - 1);
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        return build(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
};