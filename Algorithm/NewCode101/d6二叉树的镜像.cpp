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
     * @return TreeNode类
     */
    void dfs(TreeNode *pRoot)
    {
        if(pRoot == nullptr)
            return;
        
        // 执行反转逻辑
        TreeNode* left = pRoot->left;
        TreeNode* right = pRoot->right;
        pRoot->left = right;
        pRoot->right = left;
        dfs(pRoot->left);
        dfs(pRoot->right);
    }
    TreeNode *Mirror(TreeNode *pRoot)
    {
        if(pRoot == nullptr)
            return nullptr;
        dfs(pRoot);
        return pRoot;
    }
};