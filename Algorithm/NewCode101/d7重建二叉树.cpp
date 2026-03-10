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
     * @param preOrder int整型vector
     * @param vinOrder int整型vector
     * @return TreeNode类
     */
    TreeNode *build(vector<int> &preOrder, int pbegin, int pend, vector<int> &inOrder, int ibegin, int iend)
    {
        // 判断递归结束条件
        if (pbegin == pend)
            return nullptr;
        // 根节点
        int val = preOrder[pbegin];
        TreeNode* root = new TreeNode(val);
        // 在inorder找左右子树
        int index = ibegin;
        while(index < iend)
        {
            if(inOrder[index] != val)
                index++;
            // 找到了记得break掉
            else
                break;
        }
        int leftlen = index - ibegin;
        root->left = build(preOrder, pbegin + 1, pbegin + 1 + leftlen, inOrder, ibegin, index);
        root->right = build(preOrder, pbegin + 1 + leftlen, pend, inOrder, index + 1, iend);
        return root;
    }

    TreeNode *reConstructBinaryTree(vector<int> &preOrder, vector<int> &vinOrder)
    {
        return build(preOrder, 0, preOrder.size(), vinOrder, 0, vinOrder.size());
    }
};