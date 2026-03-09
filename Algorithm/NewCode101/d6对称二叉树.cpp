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
     * @param pRoot TreeNode类
     * @return bool布尔型
     */
    bool dfs(TreeNode *p, TreeNode *q)
    {
        if(p == nullptr && q == nullptr)
            return true;
        if(p == nullptr || q == nullptr)
            return false;
        if(p->val != q->val)
            return false;
        return dfs(p->left, q->right) && dfs(p->right, q->left);
    }
    bool isSymmetrical(TreeNode *pRoot)
    {
        if(pRoot == nullptr)
            return true;
        return dfs(pRoot->left, pRoot->right);
    }
};