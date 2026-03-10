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
     * 求二叉树的右视图
     * @param preOrder int整型vector 先序遍历
     * @param inOrder int整型vector 中序遍历
     * @return int整型vector
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

    vector<int> solve(vector<int> &preOrder, vector<int> &inOrder)
    {
        // 构建出二叉树
        TreeNode* root = build(preOrder, 0, preOrder.size(), inOrder, 0, inOrder.size());

        vector<int> ans;
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            vector<int> level;
            // 层序遍历 
            for(int i = 0; i < n; i++)
            {
                TreeNode* tmp = q.front();
                level.emplace_back(tmp->val);
                q.pop();
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
            }
            // 将层序遍历的最后一个结果插入ans
            ans.emplace_back(level[level.size() - 1]);
        }

        return ans;
    }
};