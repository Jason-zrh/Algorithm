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

class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @return bool布尔型
     */
    bool isCompleteTree(TreeNode* root) {
        if (root == nullptr)
            return true;

        queue<TreeNode*> q;
        q.push(root);
        bool reachedEnd = false; // 标记是否遇到了第一个空节点

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr == nullptr)
                // 第一次遇到空节点，标记一下
                reachedEnd = true;

            else {
                // 如果之前已经遇到过空节点，现在又遇到了非空节点，说明不连续
                if (reachedEnd)
                    return false;

                // 关键点：不管是不是空，直接入队
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return true;
    }
};